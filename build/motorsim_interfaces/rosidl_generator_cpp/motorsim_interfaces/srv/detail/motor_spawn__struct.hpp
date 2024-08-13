// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motorsim_interfaces:srv/MotorSpawn.idl
// generated code does not contain a copyright notice

#ifndef MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__STRUCT_HPP_
#define MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__motorsim_interfaces__srv__MotorSpawn_Request __attribute__((deprecated))
#else
# define DEPRECATED__motorsim_interfaces__srv__MotorSpawn_Request __declspec(deprecated)
#endif

namespace motorsim_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MotorSpawn_Request_
{
  using Type = MotorSpawn_Request_<ContainerAllocator>;

  explicit MotorSpawn_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit MotorSpawn_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motorsim_interfaces__srv__MotorSpawn_Request
    std::shared_ptr<motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motorsim_interfaces__srv__MotorSpawn_Request
    std::shared_ptr<motorsim_interfaces::srv::MotorSpawn_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorSpawn_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorSpawn_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorSpawn_Request_

// alias to use template instance with default allocator
using MotorSpawn_Request =
  motorsim_interfaces::srv::MotorSpawn_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace motorsim_interfaces


#ifndef _WIN32
# define DEPRECATED__motorsim_interfaces__srv__MotorSpawn_Response __attribute__((deprecated))
#else
# define DEPRECATED__motorsim_interfaces__srv__MotorSpawn_Response __declspec(deprecated)
#endif

namespace motorsim_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MotorSpawn_Response_
{
  using Type = MotorSpawn_Response_<ContainerAllocator>;

  explicit MotorSpawn_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit MotorSpawn_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motorsim_interfaces__srv__MotorSpawn_Response
    std::shared_ptr<motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motorsim_interfaces__srv__MotorSpawn_Response
    std::shared_ptr<motorsim_interfaces::srv::MotorSpawn_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorSpawn_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorSpawn_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorSpawn_Response_

// alias to use template instance with default allocator
using MotorSpawn_Response =
  motorsim_interfaces::srv::MotorSpawn_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace motorsim_interfaces

namespace motorsim_interfaces
{

namespace srv
{

struct MotorSpawn
{
  using Request = motorsim_interfaces::srv::MotorSpawn_Request;
  using Response = motorsim_interfaces::srv::MotorSpawn_Response;
};

}  // namespace srv

}  // namespace motorsim_interfaces

#endif  // MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__STRUCT_HPP_
