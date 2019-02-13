#ifndef ROSPUBLISER_HHH 
#define ROSPUBLISER_HHH 

#include <array>
#include "ros/ros.h"

constexpr uint32_t default_queue_size = 10;

template<typename Message>
class ROSPublisher : public Publisher<Message> {
public:
    // ROSPublisher(std::shared_ptr<lcm::LCM> entity) :
        // _publish_method(entity), _queue_size(default_queue_size) { }

    ROSPublisher(std::shared_ptr<ros::Publisher> entity, const uint32_t queue_size = default_queue_size) :
        _publish_method(entity) , _queue_size(queue_size) {}

     
    void publish(const std::string& channel, const Message& msg) {
        assert((! channel.empty()) && 
               ros::ok()); 
        _publish_method -> publish(channel, _queue_size, msg);
    }

    void setQueueSize(const uint32_t& queue_size) {
        assert(queue_size);
        _queue_size = queue_size;
    }

    ~ROSPublisher() {}

private:
    std::shared_ptr<ros::NodeHandle> _publish_method;
    uint32_t _queue_size{0};
};

#endif //ROSPUBLISER_HHH 
