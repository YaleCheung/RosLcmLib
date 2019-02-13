#ifndef LCMSUBSCRIBER_HHH 
#define LCMSUBSCRIBER_HHH 

#include "basic_subscriber.h"
#include <cstddef>

template<typename Callback>
class LCMSubscriber : public Subscriber<Callback> {
public:
    LCMSubscriber(std::shared_ptr<lcm::LCM> entity) :
        _subscribe_method(entity) {}

    void subscribe(const std::string& channel, const Callback& callback, void* context, const uint32_t queue_size) {
        assert( (! channel.empty()) &&
                _subscribe_method -> good()
              );
        _subscribe_method -> subscribeFunction(channel, callback, context);
    }

    ~LCMSubscriber() {}



private:
    std::shared_ptr<lcm::LCM> _subscribe_method;
};

#endif //LCMSUBSCRIBER_HHH 
