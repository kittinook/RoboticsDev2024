// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motorsim_interfaces:srv/MotorSpawn.idl
// generated code does not contain a copyright notice

#ifndef MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__TRAITS_HPP_
#define MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motorsim_interfaces/srv/detail/motor_spawn__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace motorsim_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MotorSpawn_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorSpawn_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorSpawn_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace motorsim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use motorsim_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const motorsim_interfaces::srv::MotorSpawn_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  motorsim_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motorsim_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const motorsim_interfaces::srv::MotorSpawn_Request & msg)
{
  return motorsim_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<motorsim_interfaces::srv::MotorSpawn_Request>()
{
  return "motorsim_interfaces::srv::MotorSpawn_Request";
}

template<>
inline const char * name<motorsim_interfaces::srv::MotorSpawn_Request>()
{
  return "motorsim_interfaces/srv/MotorSpawn_Request";
}

template<>
struct has_fixed_size<motorsim_interfaces::srv::MotorSpawn_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<motorsim_interfaces::srv::MotorSpawn_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<motorsim_interfaces::srv::MotorSpawn_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace motorsim_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MotorSpawn_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorSpawn_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorSpawn_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace motorsim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use motorsim_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const motorsim_interfaces::srv::MotorSpawn_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  motorsim_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motorsim_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const motorsim_interfaces::srv::MotorSpawn_Response & msg)
{
  return motorsim_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<motorsim_interfaces::srv::MotorSpawn_Response>()
{
  return "motorsim_interfaces::srv::MotorSpawn_Response";
}

template<>
inline const char * name<motorsim_interfaces::srv::MotorSpawn_Response>()
{
  return "motorsim_interfaces/srv/MotorSpawn_Response";
}

template<>
struct has_fixed_size<motorsim_interfaces::srv::MotorSpawn_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<motorsim_interfaces::srv::MotorSpawn_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<motorsim_interfaces::srv::MotorSpawn_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<motorsim_interfaces::srv::MotorSpawn>()
{
  return "motorsim_interfaces::srv::MotorSpawn";
}

template<>
inline const char * name<motorsim_interfaces::srv::MotorSpawn>()
{
  return "motorsim_interfaces/srv/MotorSpawn";
}

template<>
struct has_fixed_size<motorsim_interfaces::srv::MotorSpawn>
  : std::integral_constant<
    bool,
    has_fixed_size<motorsim_interfaces::srv::MotorSpawn_Request>::value &&
    has_fixed_size<motorsim_interfaces::srv::MotorSpawn_Response>::value
  >
{
};

template<>
struct has_bounded_size<motorsim_interfaces::srv::MotorSpawn>
  : std::integral_constant<
    bool,
    has_bounded_size<motorsim_interfaces::srv::MotorSpawn_Request>::value &&
    has_bounded_size<motorsim_interfaces::srv::MotorSpawn_Response>::value
  >
{
};

template<>
struct is_service<motorsim_interfaces::srv::MotorSpawn>
  : std::true_type
{
};

template<>
struct is_service_request<motorsim_interfaces::srv::MotorSpawn_Request>
  : std::true_type
{
};

template<>
struct is_service_response<motorsim_interfaces::srv::MotorSpawn_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__TRAITS_HPP_
