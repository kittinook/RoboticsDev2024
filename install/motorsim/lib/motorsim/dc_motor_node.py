#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import SetParametersResult
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist
from motorsim.dc_motor_model import DCMotorModel


class DcMotorNode(Node):
    def __init__(self):
        super().__init__('dc_motor_node')
        self.declare_parameter('Ke', 0.5265)
        self.declare_parameter('Kt', 0.5265 / 2.0)
        self.declare_parameter('L', 183.67e-6)
        self.declare_parameter('R', 0.6367)
        self.declare_parameter('J', 0.013369679361673)
        self.declare_parameter('B', 0.019688440522932)
        self.declare_parameter('V_max', 18.0)

        self.freq = 100.0

        self.create_subscription(Float64, "control_signal", self.voltage_callback, 10)
        self.speed_publisher = self.create_publisher(Twist, "motor_speed", 10)
        self.create_timer(1.0 / self.freq, self.timer_callback)

        Ke = self.get_parameter('Ke').value
        Kt = self.get_parameter('Kt').value
        L = self.get_parameter('L').value
        R = self.get_parameter('R').value
        J = self.get_parameter('J').value
        B = self.get_parameter('B').value
        V_max = self.get_parameter('V_max').value

        self.motor = DCMotorModel(Ke, Kt, L, R, J, B, V_max)
        self.motor.FM_init(self.freq)
        self.Vin = 0.0

        self.add_on_set_parameters_callback(self.set_param_callback)

    def set_param_callback(self, params):
        for param in params:
            if param.name == 'Ke':
                self.get_logger().info(f'Updated Ke: {param.value}')
                self.motor.Ke = param.value
            elif param.name == 'Kt':
                self.get_logger().info(f'Updated Kt: {param.value}')
                self.motor.Kt = param.value
            elif param.name == 'L':
                self.get_logger().info(f'Updated L: {param.value}')
                self.motor.L = param.value
            elif param.name == 'R':
                self.get_logger().info(f'Updated R: {param.value}')
                self.motor.R = param.value
            elif param.name == 'J':
                self.get_logger().info(f'Updated J: {param.value}')
                self.motor.J = param.value
            elif param.name == 'B':
                self.get_logger().info(f'Updated B: {param.value}')
                self.motor.B = param.value
            elif param.name == 'V_max':
                self.get_logger().info(f'Updated V_max: {param.value}')
                self.motor.V_max = param.value
            else:
                self.get_logger().warn(f'Unknown parameter: {param.name}')
                # Return failure result for unknown parameters
                return SetParametersResult(successful=False, reason=f'Unknown parameter: {param.name}')
            self.motor.FM_init(self.freq)
        # If all parameters are known, return success
        return SetParametersResult(successful=True)

    def voltage_callback(self, msg : Float64):
        self.Vin = msg.data

    def timer_callback(self):
        qd = self.motor.FM_compute(self.Vin, 0.0)
        msg = Twist()
        msg.angular.z = qd
        self.speed_publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = DcMotorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
