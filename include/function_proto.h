#ifndef FUNCTIONPROTOTYPE_HHH
#define FUNCTIONPROTOTYPE_HHH

#include <functional>
template<typename Data_t>
struct FunctionPrototype {
   typedef std::function<void(const lcm::ReceiveBuffer* rbuf, const std::string& channel, const Data_t* msg, void* ptr)> LCMCallback;
}

#endif  //FUNCTIONPROTOTYPE_HHH
