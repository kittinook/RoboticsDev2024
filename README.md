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
1. Create folder name RoboticsDev2024 (0.2 marks):
  ```sh
  
  ```
2. Clone the workspace and the motorsim package from the fun1 branch using the following link: https://github.com/kittinook/RoboticsDev2024.git (0.2 marks):
  ```sh
  
  ```
3. Open the .bashrc file in VS Code and add the command **source ~/RoboticsDev2024/install/setup.bash** to the last line (0.2 marks):
  ```sh
  
  ```
4. Source the ./bashrc file (0.2 marks):
  ```sh
  
  ```
5. Navigate to the RoboticsDev2024 folder using the command line (0.2 marks):
  ```sh
  
  ```
6. List all the file in folder (0.2 marks):
  ```sh
  
  ```
7. Remove unuse_file.txt (0.2 marks):
  ```sh
  
  ```

## Interface motorsim_node (2.0 marks):
1. Execute the motorsim_node.py file within the motorsim package (0.2 marks):
  ```sh
  
  ```
2. List all nodes (0.2 marks):
  ```sh
  
  ```
3. Retrieve information about the motorsim_node (0.2 marks):
  ```sh
  
  ```
4. Identify the request and response arguments for the /spawn_motor service (0.2 marks):
  ```sh
  
  ```
5. Call the /spawn_motor service to spawn a motor with the name **motor_XXYY**, where **XX** represents the first two digits of your student ID and **YY** represents the last two digits (0.2 marks):
  ```sh
  
  ```
6. List all topics (0.2 marks):
  ```sh
  
  ```
7. Find the types of the /control_signal topic (0.2 marks):
  ```sh
  
  ```
8. Find the types of the /motor_speed topic (0.2 marks):
  ```sh
  
  ```
9. Publish the value 12.0 to the /control_signal topic (0.2 marks):
  ```sh
  
  ```
10. Echo the values from the /motor_speed topic (0.2 marks):
  ```sh
  
  ```

## Interface controller_node (1.6 marks):
1. Execute the controller_node.py file within the motorsim package and remap /control_signal to /**motor_XXYY**/control_signal and /motor_speed to /**motor_XXYY**/motor_speed, where **XX** represents the first two digits of your student ID and **YY** represents the last two digits  (0.2 marks):
  ```sh
  
  ```
2. List all parameters (0.2 marks):
  ```sh
  
  ```
3. Set the controller parameter Kp to 0.1 (0.2 marks):
  ```sh
  
  ```
4. Set the controller parameter Ki to 0.01 (0.2 marks):
  ```sh
  
  ```
5. Set the controller parameter Kd to 0.0 (0.2 marks):
  ```sh
  
  ```
6. Set the controller parameter U_max to 18.0 (0.2 marks):
  ```sh
  
  ```
7. Publish the value 20.0 to the angular velocity around the z-axis of the /cmd_vel topic (0.2 marks):
  ```sh
  
  ```
8. Execute teleop_twist_keyboard package to control the motor (0.2 marks):
  ```sh
  
  ```
