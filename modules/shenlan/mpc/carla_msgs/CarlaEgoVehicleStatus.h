// Generated by gencpp from file carla_msgs/CarlaEgoVehicleStatus.msg
// DO NOT EDIT!


#ifndef CARLA_MSGS_MESSAGE_CARLAEGOVEHICLESTATUS_H
#define CARLA_MSGS_MESSAGE_CARLAEGOVEHICLESTATUS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Pose.h>
#include <carla_msgs/CarlaEgoVehicleControl.h>

namespace carla_msgs
{
template <class ContainerAllocator>
struct CarlaEgoVehicleStatus_
{
  typedef CarlaEgoVehicleStatus_<ContainerAllocator> Type;

  CarlaEgoVehicleStatus_()
    : header()
    , pose()
    , velocity(0.0)
    , acceleration(0.0)
    , curvature(0.0)
    , control()  {
    }
  CarlaEgoVehicleStatus_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , pose(_alloc)
    , velocity(0.0)
    , acceleration(0.0)
    , curvature(0.0)
    , control(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef float _velocity_type;
  _velocity_type velocity;

   typedef float _acceleration_type;
  _acceleration_type acceleration;

   typedef float _curvature_type;
  _curvature_type curvature;

   typedef  ::carla_msgs::CarlaEgoVehicleControl_<ContainerAllocator>  _control_type;
  _control_type control;





  typedef boost::shared_ptr< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> const> ConstPtr;

}; // struct CarlaEgoVehicleStatus_

typedef ::carla_msgs::CarlaEgoVehicleStatus_<std::allocator<void> > CarlaEgoVehicleStatus;

typedef boost::shared_ptr< ::carla_msgs::CarlaEgoVehicleStatus > CarlaEgoVehicleStatusPtr;
typedef boost::shared_ptr< ::carla_msgs::CarlaEgoVehicleStatus const> CarlaEgoVehicleStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator1> & lhs, const ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.pose == rhs.pose &&
    lhs.velocity == rhs.velocity &&
    lhs.acceleration == rhs.acceleration &&
    lhs.curvature == rhs.curvature &&
    lhs.control == rhs.control;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator1> & lhs, const ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace carla_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e491670692786ee33b90a26a965a7d96";
  }

  static const char* value(const ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe491670692786ee3ULL;
  static const uint64_t static_value2 = 0x3b90a26a965a7d96ULL;
};

template<class ContainerAllocator>
struct DataType< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "carla_msgs/CarlaEgoVehicleStatus";
  }

  static const char* value(const ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#\n"
"# Copyright (c) 2019 Intel Corporation.\n"
"#\n"
"# This work is licensed under the terms of the MIT license.\n"
"# For a copy, see <https://opensource.org/licenses/MIT>.\n"
"#\n"
"\n"
"std_msgs/Header header\n"
"\n"
"geometry_msgs/Pose pose\n"
"float32 velocity\n"
"float32 acceleration\n"
"float32 curvature\n"
"\n"
"# the current control values, as reported by Carla\n"
"CarlaEgoVehicleControl control\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: carla_msgs/CarlaEgoVehicleControl\n"
"#\n"
"# Copyright (c) 2018-2019 Intel Corporation.\n"
"#\n"
"# This work is licensed under the terms of the MIT license.\n"
"# For a copy, see <https://opensource.org/licenses/MIT>.\n"
"#\n"
"# This represents a vehicle control message sent to CARLA simulator\n"
"\n"
"std_msgs/Header header\n"
"\n"
"# The CARLA vehicle control data\n"
"\n"
"# 0. <= throttle <= 1.\n"
"float32 throttle\n"
"\n"
"# -1. <= steer <= 1.\n"
"float32 steer\n"
"\n"
"# 0. <= brake <= 1.\n"
"float32 brake\n"
"\n"
"# hand_brake 0 or 1\n"
"bool hand_brake\n"
"\n"
"# reverse 0 or 1\n"
"bool reverse\n"
"\n"
"# gear\n"
"int32 gear\n"
"\n"
"# manual gear shift\n"
"bool manual_gear_shift\n"
;
  }

  static const char* value(const ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.pose);
      stream.next(m.velocity);
      stream.next(m.acceleration);
      stream.next(m.curvature);
      stream.next(m.control);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CarlaEgoVehicleStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::carla_msgs::CarlaEgoVehicleStatus_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "velocity: ";
    Printer<float>::stream(s, indent + "  ", v.velocity);
    s << indent << "acceleration: ";
    Printer<float>::stream(s, indent + "  ", v.acceleration);
    s << indent << "curvature: ";
    Printer<float>::stream(s, indent + "  ", v.curvature);
    s << indent << "control: ";
    s << std::endl;
    Printer< ::carla_msgs::CarlaEgoVehicleControl_<ContainerAllocator> >::stream(s, indent + "  ", v.control);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CARLA_MSGS_MESSAGE_CARLAEGOVEHICLESTATUS_H
