#ifndef LCMSUBSCRIBERMANAGER_HHH 
#define LCMSUBSCRIBERMANAGER_HHH 

#include <cstddef>
#include <lcm/lcm-cpp.hpp>

class LCMSubscriberManager : NonCopyable {
public:
    LCMSubscriberManager(std::shared_ptr<lcm::LCM> entity) :
        _subscribe_method(entity) {}

    template <typename Callback>
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
