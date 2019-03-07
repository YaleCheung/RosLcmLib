#ifndef PUBLISHER_HHH
#define PUBLISHER_HHH

#include "common.h"

template<typename Message>
class Publisher : NonCopyable {
public:
    virtual void publish(const std::string& name, const Message& msg, uint32_t queue_size) = 0;
    virtual ~Publisher() {};
};

#endif //  PUBLISHER_HHH
