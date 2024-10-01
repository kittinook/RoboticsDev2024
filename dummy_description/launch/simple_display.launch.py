#!/usr/bin/env python3


from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import os
import xacro    
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    
    pkg = get_package_share_directory('dummy_description')
    rviz_path = os.path.join(pkg,'config','display.rviz')
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz',
        arguments=['-d', rviz_path],
        output='screen')
    
    dummy_robot = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [
                os.path.join(
                    get_package_share_directory("dummy_description"),
                    "launch",
                    "dummy_robot.launch.py"
                )
            ]
        )
    )

    joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui'
    )

    launch_description = LaunchDescription()
    launch_description.add_action(rviz)
    launch_description.add_action(joint_state_publisher_gui)
    launch_description.add_action(dummy_robot)
    
    return launch_description