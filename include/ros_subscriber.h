#ifndef ROSSUBSCRIBER_HHH 
#define ROSSUBSCRIBER_HHH 

#include "ros/ros.h"

template<typename Callback>
class ROSSubscriber : public Subscriber<Callback> {
public:
    ROSSubscriber(std::shared_ptr<lcm::LCM> entity) :
        _subscribe_method(entity) { }

    void subscribe(const std::string& channel, const Callback& callback, void* context, uint32_t queue_size) {       
        _subscriber_method -> subscribe(channel, queue_size, callback, context);
    }

    ~ROSSubscriber() {}

private:
    std::shared_ptr<ros::NodeHandle> _subscribe_method;
};

#endif //ROSSUBSCRIBER_HHH 