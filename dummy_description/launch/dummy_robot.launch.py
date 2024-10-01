#!/usr/bin/env python3


from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import os
import xacro    
    
def generate_launch_description():
    
    pkg = get_package_share_directory('dummy_description')
    rviz_path = os.path.join(pkg,'config','display.rviz')
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz',
        arguments=['-d', rviz_path],
        output='screen')
    
    path_description = os.path.join(pkg,'urdf','my-robot.xacro')
    robot_desc_xml = xacro.process_file(path_description).toxml()
    #robot_desc_xml = xacro.process_file(path_description,mappings={'robot_name': namespace}).toxml()
    
    parameters = [{'robot_description':robot_desc_xml}]
    #parameters.append({'frame_prefix':namespace+'/'})
    robot_state_publisher = Node(package='robot_state_publisher',
                                  executable='robot_state_publisher',
                                  output='screen',
                                  parameters=parameters
    )

    # joint_state_publisher_gui = Node(
    #     package='joint_state_publisher_gui',
    #     executable='joint_state_publisher_gui'
    # )

    launch_description = LaunchDescription()
    
    # launch_description.add_action(rviz)
    launch_description.add_action(robot_state_publisher)
    # launch_description.add_action(joint_state_publisher_gui)
    
    return launch_description