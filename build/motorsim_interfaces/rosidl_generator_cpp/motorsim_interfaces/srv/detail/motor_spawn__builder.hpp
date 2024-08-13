// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motorsim_interfaces:srv/MotorSpawn.idl
// generated code does not contain a copyright notice

#ifndef MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__BUILDER_HPP_
#define MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motorsim_interfaces/srv/detail/motor_spawn__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motorsim_interfaces
{

namespace srv
{

namespace builder
{

class Init_MotorSpawn_Request_name
{
public:
  Init_MotorSpawn_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::motorsim_interfaces::srv::MotorSpawn_Request name(::motorsim_interfaces::srv::MotorSpawn_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motorsim_interfaces::srv::MotorSpawn_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::motorsim_interfaces::srv::MotorSpawn_Request>()
{
  return motorsim_interfaces::srv::builder::Init_MotorSpawn_Request_name();
}

}  // namespace motorsim_interfaces


namespace motorsim_interfaces
{

namespace srv
{

namespace builder
{

class Init_MotorSpawn_Response_message
{
public:
  explicit Init_MotorSpawn_Response_message(::motorsim_interfaces::srv::MotorSpawn_Response & msg)
  : msg_(msg)
  {}
  ::motorsim_interfaces::srv::MotorSpawn_Response message(::motorsim_interfaces::srv::MotorSpawn_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motorsim_interfaces::srv::MotorSpawn_Response msg_;
};

class Init_MotorSpawn_Response_success
{
public:
  Init_MotorSpawn_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorSpawn_Response_message success(::motorsim_interfaces::srv::MotorSpawn_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MotorSpawn_Response_message(msg_);
  }

private:
  ::motorsim_interfaces::srv::MotorSpawn_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::motorsim_interfaces::srv::MotorSpawn_Response>()
{
  return motorsim_interfaces::srv::builder::Init_MotorSpawn_Response_success();
}

}  // namespace motorsim_interfaces

#endif  // MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__BUILDER_HPP_
