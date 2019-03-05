#ifndef ROSSUBSCRIBER_HHH 
#define ROSSUBSCRIBER_HHH 

#include "ros/ros.h"
#include "basic_subscriber.h"

template<typename Callback>
class ROSSubscriber : public Subscriber<Callback> {
public:
    ROSSubscriber(std::shared_ptr<ros::NodeHandle> entity) :
        _subscribe_method(entity) { }

    void subscribe(const std::string& channel, const Callback& callback, void* context = nullptr, uint32_t queue_size = 2) {       
        _subscribe_method -> subscribe(channel, queue_size, callback);
    }

    ~ROSSubscriber() {}

private:
    std::shared_ptr<ros::NodeHandle> _subscribe_method;
};

#endif //ROSSUBSCRIBER_HHH 
