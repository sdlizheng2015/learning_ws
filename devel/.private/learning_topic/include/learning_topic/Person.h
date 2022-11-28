// Generated by gencpp from file learning_topic/Person.msg
// DO NOT EDIT!


#ifndef LEARNING_TOPIC_MESSAGE_PERSON_H
#define LEARNING_TOPIC_MESSAGE_PERSON_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace learning_topic
{
template <class ContainerAllocator>
struct Person_
{
  typedef Person_<ContainerAllocator> Type;

  Person_()
    : name()
    , sex(0)
    , age(0)  {
    }
  Person_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , sex(0)
    , age(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;

   typedef uint8_t _sex_type;
  _sex_type sex;

   typedef uint8_t _age_type;
  _age_type age;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(unknown)
  #undef unknown
#endif
#if defined(_WIN32) && defined(male)
  #undef male
#endif
#if defined(_WIN32) && defined(female)
  #undef female
#endif

  enum {
    unknown = 0u,
    male = 1u,
    female = 2u,
  };


  typedef boost::shared_ptr< ::learning_topic::Person_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::learning_topic::Person_<ContainerAllocator> const> ConstPtr;

}; // struct Person_

typedef ::learning_topic::Person_<std::allocator<void> > Person;

typedef boost::shared_ptr< ::learning_topic::Person > PersonPtr;
typedef boost::shared_ptr< ::learning_topic::Person const> PersonConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::learning_topic::Person_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::learning_topic::Person_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::learning_topic::Person_<ContainerAllocator1> & lhs, const ::learning_topic::Person_<ContainerAllocator2> & rhs)
{
  return lhs.name == rhs.name &&
    lhs.sex == rhs.sex &&
    lhs.age == rhs.age;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::learning_topic::Person_<ContainerAllocator1> & lhs, const ::learning_topic::Person_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace learning_topic

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::learning_topic::Person_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::learning_topic::Person_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_topic::Person_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_topic::Person_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_topic::Person_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_topic::Person_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::learning_topic::Person_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8361f88618d6779bd872f0ba928ced56";
  }

  static const char* value(const ::learning_topic::Person_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8361f88618d6779bULL;
  static const uint64_t static_value2 = 0xd872f0ba928ced56ULL;
};

template<class ContainerAllocator>
struct DataType< ::learning_topic::Person_<ContainerAllocator> >
{
  static const char* value()
  {
    return "learning_topic/Person";
  }

  static const char* value(const ::learning_topic::Person_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::learning_topic::Person_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n"
"uint8 sex\n"
"uint8 age\n"
"\n"
"uint8 unknown = 0\n"
"uint8 male = 1\n"
"uint8 female =2\n"
;
  }

  static const char* value(const ::learning_topic::Person_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::learning_topic::Person_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.sex);
      stream.next(m.age);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Person_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::learning_topic::Person_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::learning_topic::Person_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
    s << indent << "sex: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sex);
    s << indent << "age: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.age);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LEARNING_TOPIC_MESSAGE_PERSON_H
