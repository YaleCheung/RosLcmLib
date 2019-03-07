#ifndef SUBSCRIBERMANAGER_HHH
#define SUBSCRIBERMANAGER_HHH

#include "common.h"

template<typename Callback>
class SubscriberManager : NonCopyable {
public:
    virtual void SubscriberManager(const std::string& channel, const Callback& callback, void* context, uint32_t queue_size) = 0;
    virtual ~SubscriberManager() {};
};


#endif // SUBSCRIBERMANAGER_HHH
