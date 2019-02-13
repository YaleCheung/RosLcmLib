#ifndef FUNCTIONPROTOTYPE_HHH
#define FUNCTIONPROTOTYPE_HHH

#include <functional>
template<typename Message>
struct FunctionPrototype {
   typedef void (*LCMCallback)(const lcm::ReceiveBuffer* rbuf, const std::string& channel, const Message* msg, void* context);
};

#endif  //FUNCTIONPROTOTYPE_HHH
