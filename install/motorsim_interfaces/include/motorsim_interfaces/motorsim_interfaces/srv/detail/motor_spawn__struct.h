// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motorsim_interfaces:srv/MotorSpawn.idl
// generated code does not contain a copyright notice

#ifndef MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__STRUCT_H_
#define MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MotorSpawn in the package motorsim_interfaces.
typedef struct motorsim_interfaces__srv__MotorSpawn_Request
{
  rosidl_runtime_c__String name;
} motorsim_interfaces__srv__MotorSpawn_Request;

// Struct for a sequence of motorsim_interfaces__srv__MotorSpawn_Request.
typedef struct motorsim_interfaces__srv__MotorSpawn_Request__Sequence
{
  motorsim_interfaces__srv__MotorSpawn_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motorsim_interfaces__srv__MotorSpawn_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MotorSpawn in the package motorsim_interfaces.
typedef struct motorsim_interfaces__srv__MotorSpawn_Response
{
  bool success;
  rosidl_runtime_c__String message;
} motorsim_interfaces__srv__MotorSpawn_Response;

// Struct for a sequence of motorsim_interfaces__srv__MotorSpawn_Response.
typedef struct motorsim_interfaces__srv__MotorSpawn_Response__Sequence
{
  motorsim_interfaces__srv__MotorSpawn_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motorsim_interfaces__srv__MotorSpawn_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTORSIM_INTERFACES__SRV__DETAIL__MOTOR_SPAWN__STRUCT_H_
