#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from std_srvs.srv import Trigger
from motorsim_interfaces.srv import MotorSpawn
import subprocess

class MotorSimNode(Node):
    def __init__(self):
        super().__init__('motorsim_node')
        self.spawner_srv = self.create_service(MotorSpawn, 'spawn_motor', self.spawn_motor_callback)

    def spawn_motor_callback(self, request, response):

        try:
            namespace = request.name
            subprocess.Popen(['ros2', 'run', 'motorsim', 'dc_motor_node.py', '--ros-args', '-r', '__ns:=' + namespace ])

            response.success = True
            response.message = 'Nodes spawned successfully'
        except Exception as e:
            self.get_logger().error(f'Failed to spawn nodes: {str(e)}')
            response.success = False
            response.message = str(e)
        return response

def main(args=None):
    rclpy.init(args=args)
    node = MotorSimNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
