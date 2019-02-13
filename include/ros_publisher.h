#ifndef ROSPUBLISER_HHH 
#define ROSPUBLISER_HHH 

#include "ros/ros.h"
#include <string>

template<typename Message>
class ROSPublisher : public Publisher<Message> {
public:
    ROSPublisher(std::shared_ptr<ros::Publisher> entity, const uint32_t queue_size = default_queue_size) :
        _publish_method(entity), _queue_size(queue_size), _channel("") {}

    void publish(const std::string& channel, const Message& msg, const uint32_t queue_size) {
        assert(ros::ok());
        _channel = channel;
        _publish_method -> publish(msg);
    }

    ~ROSPublisher() {}

private:
    std::shared_ptr<ros::Publisher> _publish_method;
    uint32_t _queue_size{0};
    std::string _channel;
};

#endif //ROSPUBLISER_HHH
