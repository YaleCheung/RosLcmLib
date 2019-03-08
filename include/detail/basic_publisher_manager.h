#ifndef PUBLISHERMANAGER_HHH
#define PUBLISHERMANAGER_HHH

#include "common.h"

template<typename Message>
class PublisherManager : NonCopyable {
public:
    virtual void publish(const std::string& name, const Message& msg, uint32_t queue_size) = 0;
    virtual ~PublisherManager() {};
};

#endif //  PUBLISHERMANAGER_HHH
