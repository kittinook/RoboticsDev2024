# Exercise 1: Command Line Interface with Motorsim

## Objective
The objective of this exercise is to practice using ROS2 commands through the command line via the terminal.

## Additional documentation
https://docs.ros.org/en/melodic/api/std_msgs/html/msg/Float64.html

https://docs.ros.org/en/noetic/api/geometry_msgs/html/msg/Twist.html

https://index.ros.org/p/teleop_twist_keyboard/

## Motorsim package system overview

![Untitled Diagram drawio](https://github.com/user-attachments/assets/e27a7c90-8e51-4b18-9142-d0b155910647)

## Setup workspace (1.4 marks):
1. Create folder name TA_fra501 (0.2 marks):
  ```sh
  mkdir TA_fra501
  ```
2. Clone the workspace and the motorsim package from the fun1 branch using the following link: https://github.com/B-Paweekorn/TA_fra501.git (0.2 marks):
  ```sh
  git clone -b fun1 https://github.com/B-Paweekorn/TA_fra501.git
  ```
3. Open the .bashrc file in VS Code and add the command **source ~/TA_fra501/install/setup.bash** to the last line (0.2 marks):
  ```sh
  code .bashrc
  ```
4. Source the ./bashrc file (0.2 marks):
  ```sh
  source .bashrc
  ```
5. Navigate to the TA_fra501 folder using the command line (0.2 marks):
  ```sh
  cd /TA_fra501
  ```
6. List all the file in folder (0.2 marks):
  ```sh
  ls
  ```
7. Remove unuse_file.txt (0.2 marks):
  ```sh
  rm unuse_file.txt
  ```

## Interface motorsim_node (2.0 marks):
1. Execute the motorsim_node.py file within the motorsim package (0.2 marks):
  ```sh
  ros2 run motorsim motorsim_node.py
  ```
2. List all nodes (0.2 marks):
  ```sh
  ros2 node list
  ```
3. Retrieve information about the motorsim_node (0.2 marks):
  ```sh
  ros2 node info /motorsim_node
  ```
4. Identify the request and response arguments for the /spawn_motor service (0.2 marks):
  ```sh
  ros2 interface show motorsim_interfaces/srv/MotorSpawn
  ```
5. Call the /spawn_motor service to spawn a motor with the name **motor_XXYY**, where **XX** represents the first two digits of your student ID and **YY** represents the last two digits (0.2 marks):
  ```sh
  ros2 service call /spawn_motor motorsim_interfaces/srv/MotorSpawn "{name: '/motor_6462'}"
  ```
6. List all topics (0.2 marks):
  ```sh
  ros2 topic list
  ```
7. Find the types of the /control_signal topic (0.2 marks):
  ```sh
  ros2 topic type /motor_6462/control_signal
  ```
8. Find the types of the /motor_speed topic (0.2 marks):
  ```sh
  ros2 topic type /motor_6462/motor_speed
  ```
9. Publish the value 12.0 to the /control_signal topic (0.2 marks):
  ```sh
  ros2 topic pub /motor_6462/control_signal std_msgs/msg/Float64 "data: 12.0"
  ```
10. Echo the values from the /motor_speed topic (0.2 marks):
  ```sh
  ros2 topic echo /motor_6462/motor_speed
  ```

## Interface controller_node (1.6 marks):
1. Execute the controller_node.py file within the motorsim package and remap /control_signal to /**motor_XXYY**/control_signal and /motor_speed to /**motor_XXYY**/motor_speed, where **XX** represents the first two digits of your student ID and **YY** represents the last two digits  (0.2 marks):
  ```sh
  ros2 run motorsim controller_node.py --ros-args -r /control_signal:=/motor_6462/control_signal -r /motor_speed:=/motor_6462/motor_speed
  ```
2. List all parameters (0.2 marks):
  ```sh
  ros2 param list
  ```
3. Set the controller parameter Kp to 0.1 (0.2 marks):
  ```sh
  ros2 param set /controller_node Kp 0.1
  ```
4. Set the controller parameter Ki to 0.01 (0.2 marks):
  ```sh
  ros2 param set /controller_node Ki 0.01
  ```
5. Set the controller parameter Kd to 0.0 (0.2 marks):
  ```sh
  ros2 param set /controller_node Kd 0.0
  ```
6. Set the controller parameter U_max to 18.0 (0.2 marks):
  ```sh
  ros2 param set /controller_node U_max 18.0
  ```
7. Publish the value 20.0 to the angular velocity around the z-axis of the /cmd_vel topic (0.2 marks):
  ```sh
  ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "linear:
    x: 0.0
    y: 0.0
    z: 0.0
  angular:
    x: 0.0
    y: 0.0
    z: 20.0"
  ```
8. Execute teleop_twist_keyboard package to control the motor (0.2 marks):
  ```sh
  ros2 run teleop_twist_keyboard teleop_twist_keyboard
  ```
