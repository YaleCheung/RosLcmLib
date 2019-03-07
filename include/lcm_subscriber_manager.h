#ifndef LCMSUBSCRIBERMANAGER_HHH 
#define LCMSUBSCRIBERMANAGER_HHH 

#include "basic_subscriber_manager.h"
#include <cstddef>
#include <lcm/lcm-cpp.hpp>

template<typename Callback>
class LCMSubscriberManager : public SubscriberManager<Callback> {
public:
    LCMSubscriberManager(std::shared_ptr<lcm::LCM> entity) :
        _subscribe_method(entity) {}

    void subscribe(const std::string& channel, const Callback& callback, 
                   void* context, uint32_t queue_size) {
        assert( (! channel.empty()) &&
                _subscribe_method -> ok()
              );
        _subscribe_method -> subscribeFunction(channel, callback, context);
    }

    ~LCMSubscriberManager() {}



private:
    std::shared_ptr<lcm::LCM> _subscribe_method;
};

#endif //LCMSUBSCRIBERMANAGER_HHH 
