#ifndef ROSSUBSCRIBER_HHH 
#define ROSSUBSCRIBER_HHH 

#include "ros/ros.h"

template<typename Callback_t>
class ROSSubscriber : public Subscriber<Callback_t> {
public:
    ROSSubscriber(std::shared_ptr<lcm::LCM> entity) :
        _subscribe_method(entity), _queue_size(default_queue_size) { }

    ROSSubscriber(std::shared_ptr<lcm::LCM> entity, uint32_t queue_size) :
        _subscribe_method(entity) { 
        setQueueSize(queue_size);
    }

     
    void subscribe(const std::string& channel, const Callback_t& callback, void* ) {
        assert((! channel.empty()) && 
                ros::ok());
        _subscribe_method -> subscribe(channel, _queue_size, callback);
    }

    void setQueueSize(uint32_t size) {
        assert(size > 0);
        _queue_size = size;
    }

    ~ROSSubscriber() {}

private:
    std::shared_ptr<ros::NodeHandle> _subscribe_method;
    std::uint32_t _queue_size;
};

#endif //ROSSUBSCRIBER_HHH 
