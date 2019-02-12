#ifndef FUNCTIONPROTOTYPE_HHH
#define FUNCTIONPROTOTYPE_HHH

#include <functional>
template<typename Data_t>
struct FunctionPrototype {
   typedef void (*LCMCallback)(const lcm::ReceiveBuffer* rbuf, const std::string& channel, const Data_t* msg, void* contex);
};

#endif  //FUNCTIONPROTOTYPE_HHH
