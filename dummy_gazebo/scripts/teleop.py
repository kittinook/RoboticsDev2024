#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from geometry_msgs.msg import PoseStamped, Twist
from std_msgs.msg import Float64MultiArray
from roboticstoolbox import DHRobot, RevoluteMDH
from roboticstoolbox.robot.ET import ET
from roboticstoolbox.robot.ERobot import ERobot
from roboticstoolbox.robot.Link import Link
from math import pi
from spatialmath import *
import numpy as np

class SimpleRobot(DHRobot):

    def __init__(self):
        deg = pi / 180

        L1 = RevoluteMDH(
            a=0.0, d=0.2, alpha=0.0, qlim=[-180 * deg, 180 * deg]  # alpha=pi / 2,
        )
        L2 = RevoluteMDH(
            a=0.0, d=-0.06, alpha=-pi / 2, qlim=[-180 * deg, 65 * deg],
            offset=-pi/2  # d=0.135,  # alpha=pi,
        )
        L3 = RevoluteMDH(
            a=0.25,
            d=0.04,  # d=0.135,
            alpha=0.0,  # alpha=-pi / 2,
            qlim=[-180 * deg, 180 * deg],
        )

        L = [L1, L2, L3]#, L4]

        # Create SerialLink object
        super().__init__(
            L,
            name="SimpleRobot",
            manufacturer="FIBO"
        )

class DummyNode(Node):
    def __init__(self):
        super().__init__('dummy_node')
        self.joint_pub = self.create_publisher(JointState, "/joint_states", 10)
        self.eff_pub = self.create_publisher(PoseStamped, "eff", 10)
        self.velo_pub = self.create_publisher(Float64MultiArray, "velocity_controllers/commands", 10)
        self.create_subscription(Twist, "cmd_vel", self.cmd_callback, 10)
        self.create_subscription(JointState, "joint_states", self.joint_state_callback, 10)
        self.dt = 0.01
        self.create_timer(self.dt, self.sim_loop)
        self.q = [0.0, 0.5, 1.4]
        self.cmd_vel = [0.0, 0.0, 0.0]
        self.name = ["joint_1", "joint_2", "joint_3"]
        self.my_robot = SimpleRobot()
        tool = SE3(0.28, 0.0, 0.0) * SE3.Rx(pi/2) * SE3.Ry(pi/2)
        self.my_robot.tool = tool

    def joint_state_callback(self, msg:JointState):
        joint_positions = {name: None for name in self.name}
        
        # Loop ผ่านทุกค่าใน msg.name เพื่อเช็คว่าตรงกับ joint ที่เราต้องการหรือไม่
        for i, joint_name in enumerate(msg.name):
            if joint_name in self.name:
                joint_positions[joint_name] = msg.position[i]
        
        # ตรวจสอบว่าค่าครบทั้ง 3 joint แล้วหรือไม่ ก่อนจะอัพเดต self.q
        if all(joint_positions[joint_name] is not None for joint_name in self.name):
            self.q = [
                joint_positions['joint_1'],
                joint_positions['joint_2'],
                joint_positions['joint_3']
            ]
            self.get_logger().info(f'Updated q: {self.q}')
        else:
            self.get_logger().warn('Some joints are missing or have no data.')


    def cmd_callback(self, msg:Twist):
        self.cmd_vel[0] = msg.linear.x
        self.cmd_vel[1] = msg.linear.y
        self.cmd_vel[2] = msg.linear.z

    def send_vel(self, qd):
        msg = Float64MultiArray()
        msg.data.append(qd[0])
        msg.data.append(qd[1])
        msg.data.append(qd[2])
        self.velo_pub.publish(msg)

    def sim_loop(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        J = self.my_robot.jacob0(self.q)
        j_reduce = J[:3, :3]
        qd = np.linalg.inv(j_reduce) @ np.array( self.cmd_vel )
        # self.q[0] = self.q[0] + (q_d[0] * self.dt)
        # self.q[1] = self.q[1] + (q_d[1] * self.dt)
        # self.q[2] = self.q[2] + (q_d[2] * self.dt)
        self.send_vel([qd[0], qd[1], qd[2]])
        # for i in range(len(self.q)):
        #     msg.position.append(self.q[i])
        #     msg.name.append(self.name[i])
        # self.joint_pub.publish(msg)
        self.T0e = self.my_robot.fkine(self.q)
        eff_msg = PoseStamped()
        eff_msg.header.frame_id = "link_0"
        eff_msg.header.stamp = self.get_clock().now().to_msg()
        eff_msg.pose.position.x = self.T0e.t[0]
        eff_msg.pose.position.y = self.T0e.t[1]
        eff_msg.pose.position.z = self.T0e.t[2]
        self.eff_pub.publish(eff_msg)
        # print(self.T0e)

def main(args=None):
    rclpy.init(args=args)
    node = DummyNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()