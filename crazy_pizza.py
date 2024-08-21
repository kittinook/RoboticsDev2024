#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
import random

class CrazyPizzaPublisher(Node):
    def __init__(self):
        super().__init__('crazy_pizza_publisher')
        self.publisher_ = self.create_publisher(Pose, '/crazy_pizza', 10)
        self.timer = self.create_timer(1.0, self.publish_random_pose)

    def publish_random_pose(self):
        pose = Pose()
        pose.x = random.uniform(0, 10.8)
        pose.y = random.uniform(0, 10.8)

        self.publisher_.publish(pose)
        self.get_logger().info(f'Published Pose: x={pose.x}, y={pose.y}')

def main(args=None):
    rclpy.init(args=args)
    node = CrazyPizzaPublisher()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
