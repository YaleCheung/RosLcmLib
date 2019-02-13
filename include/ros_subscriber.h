#ifndef ROSSUBSCRIBER_HHH 
#define ROSSUBSCRIBER_HHH 

#include "ros/ros.h"

template<typename Callback>
class ROSSubscriber : public Subscriber<Callback> {
public:
    ROSSubscriber(std::shared_ptr<lcm::LCM> entity) :
        _subscribe_method(entity), _queue_size(0) { }

    void subscribe(const std::string& channel, const Callback& callback, void* contex, uint32_t queue_size) {
        assert((! channel.empty()) && 
                ros::ok());
        _queue_size = queue_size;
        _channel = channel;
        _subscribe_method -> subscribe(channel, _queue_size, callback);
    }

    ~ROSSubscriber() {}

private:
    std::shared_ptr<ros::Subscriber> _subscribe_method;
    std::uint32_t _queue_size;
    std::string _channel;
};

#endif //ROSSUBSCRIBER_HHH 
