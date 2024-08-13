#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import SetParametersResult
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist
from motorsim.pid_controller import PIDController


class ControllerNode(Node):
    def __init__(self):
        super().__init__('controller_node')
        # Declare parameters with default values
        self.declare_parameter('Kp', 0.0)
        self.declare_parameter('Ki', 0.0)
        self.declare_parameter('Kd', 0.0)
        self.declare_parameter('U_max', 12.0)

        self.freq = 100.0

        self.create_subscription(Twist, "cmd_vel", self.cmd_callback, 10)
        self.create_subscription(Twist, "motor_speed", self.fb_callback, 10)
        self.signal_publisher = self.create_publisher(Float64, "control_signal", 10)
        self.create_timer(1.0 / self.freq, self.timer_callback)

        self.Kp = self.get_parameter('Kp').value
        self.Ki = self.get_parameter('Ki').value
        self.Kd = self.get_parameter('Kd').value
        self.U_max = self.get_parameter('U_max').value

        self.pid = PIDController(self.Kp, self.Ki, self.Kd, self.U_max)
        self.target = 0.0
        self.feedback = 0.0

        # Add callback for parameter changes
        self.add_on_set_parameters_callback(self.set_param_callback)

    def set_param_callback(self, params):
        for param in params:
            if param.name == 'Kp':
                self.get_logger().info(f'Updated Kp: {param.value}')
                self.Kp = param.value
            elif param.name == 'Ki':
                self.get_logger().info(f'Updated Ki: {param.value}')
                self.Ki = param.value
            elif param.name == 'Kd':
                self.get_logger().info(f'Updated Kd: {param.value}')
                self.Kd = param.value
            elif param.name == 'U_max':
                self.get_logger().info(f'Updated U_max: {param.value}')
                self.U_max = param.value
            else:
                self.get_logger().warn(f'Unknown parameter: {param.name}')
                # Return failure result for unknown parameters
                return SetParametersResult(successful=False, reason=f'Unknown parameter: {param.name}')
        self.pid.set_param(self.Kp, self.Ki, self.Kd, self.U_max)
        # If all parameters are known, return success
        return SetParametersResult(successful=True)

    def cmd_callback(self, msg: Twist):
        self.target = msg.angular.z

    def fb_callback(self, msg: Twist):
        self.feedback = msg.angular.z

    def timer_callback(self):
        error = self.target - self.feedback
        msg = Float64()
        msg.data = self.pid.compute(error)
        self.signal_publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = ControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
