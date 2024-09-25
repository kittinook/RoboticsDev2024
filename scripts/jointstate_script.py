#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from math import pi
from spatialmath import *
import numpy as np

class DummyNode(Node):
    def __init__(self):
        super().__init__('dummy_node')
        self.joint_pub = self.create_publisher(JointState, "/joint_states", 10)
        self.dt = 0.01
        self.create_timer(self.dt, self.sim_loop)
        self.q = [0.0, 0.5, 1.4]
        self.cmd_vel = [0.0, 0.0, 0.0]
        self.name = ["joint_1", "joint_2", "joint_3"]

    def sim_loop(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        q_d = [0.1, 0.1, 0.1]
        self.q[0] = self.q[0] + (q_d[0] * self.dt)
        self.q[1] = self.q[1] + (q_d[1] * self.dt)
        self.q[2] = self.q[2] + (q_d[2] * self.dt)
        for i in range(len(self.q)):
            msg.position.append(self.q[i])
            msg.name.append(self.name[i])
        self.joint_pub.publish(msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = DummyNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
