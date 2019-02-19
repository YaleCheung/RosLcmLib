#ifndef ROSNODE_HHH
#define ROSNODE_HHH

#include <array>

#include "basic_node.h"
#include "ros_publisher.h"
#include "ros_subscriber.h"

constexpr uint32_t max_channels = 10;

template<typename Message, typename Callback>
class ROSNode {
public:
    ROSNode():
      _comm_entity(std::make_unique<ros::NodeHandle>()),
      _publisher(std::make_unique<ROSPublisher<Message>>(_comm_entity)),
      _subscriber(std::make_unique<ROSSubscriber<Callback>>(_comm_entity)) {}

    void publish(const std::string& channel, const Message& msg, uint32_t queue_size) {
        _publisher->publish(channel, msg, queue_size);
    }

    void subscribe(const std::string& channel, const Callback& callback, void* context, uint32_t queue_size) {
        _subscriber -> subscribe(channel, callback, context, queue_size);
    }

    void handle() const {
        ros::spinOnce();
    }

    ~ROSNode() {}
  
private:
    std::shared_ptr<ros::NodeHandle> _comm_entity;
    std::unique_ptr<Publisher<Message>> _publisher;
    std::unique_ptr<Subscriber<Callback>> _subscriber;
};


#endif  //ROSNODE_HHH 
