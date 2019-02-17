#ifndef FUNCTIONPROTOTYPE_HHH
#define FUNCTIONPROTOTYPE_HHH

#include <functional>
#include <string>

template<typename Message>
struct FunctionPrototype {
#ifdef _LCM
   typedef void (*Callback)(const lcm::ReceiveBuffer* rbuf, const std::string& channel, const Message* msg, void* context);
#elif defined _ROS
   typedef void (*Callback)(const Message& msg);
#endif
};

#endif  //FUNCTIONPROTOTYPE_HHH
