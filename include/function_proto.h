#ifndef FUNCTIONPROTOTYPE_HHH
#define FUNCTIONPROTOTYPE_HHH

#include <string>
#include "common.h"

template<typename Message>
struct FunctionPrototype {
#ifdef _LCM
   typedef void (*Callback)(const lcm::ReceiveBuffer* rbuf, const std::string& channel, const Message* msg, void* context);
#elif defined _ROS
   typedef void (*Callback)(const boost::shared_ptr<Message const>& msg);
   // typedef boost::function<void(boost::shared_ptr<Message const>&)> Callback;
#endif
};

#endif  //FUNCTIONPROTOTYPE_HHH
