#ifndef ROSSUBSCRIBER_HHH 
#define ROSSUBSCRIBER_HHH 

#include "ros/ros.h"


class ROSSubscriberManager : NonCopyable {
public:
    ROSSubscriberManager(std::shared_ptr<ros::NodeHandle> entity) :
        _subscribe_method(entity), _channels_in_use(0) { }

    template<typename Callback>
    void subscribe(const std::string& channel, const Callback& callback, void* context = nullptr, uint32_t queue_size = 2) {       
        assert(_channels_in_use < max_subscribers);
        _subscribers[_channels_in_use] = _subscribe_method -> subscribe(channel, queue_size, callback);
        ++ _channels_in_use;
    }

    ~ROSSubscriberManager() {}

private:
    static constexpr uint32_t max_subscribers = 10;

    std::shared_ptr<ros::NodeHandle> _subscribe_method;
    std::array<ros::Subscriber, max_subscribers> _subscribers;

    uint32_t _channels_in_use;
};

#endif //ROSSUBSCRIBER_HHH 
