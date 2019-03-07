#ifndef IPCCOMMNODE_HHH
#define IPCCOMMNODE_HHH

#include "basic_node.h"
#include "common.h"

#ifdef _LCM
#include "lcm_publisher.h"
#include "lcm_subscriber.h"
#define ENTITY lcm::LCM
#define PUBLISHER LCMPublisher
#define SUBSCRIBER LCMSubscriber
#elif defined(_ROS)
#include "ros_publisher.h"
#include "ros_subscriber.h"
#define ENTITY ros::NodeHandle
#define PUBLISHER ROSPublisher
#define SUBSCRIBER ROSSubscriber
# endif // include nothing, compiling will be failed

template<typename Message, typename Callback>
class IPCCommNode : public CommNode<Message, Callback> {
public:
  IPCCommNode(const std::string& node_name) {
#ifdef _ROS
      int argc = 0;
      //int& argc_ingored = argc;
      char* argv[1] = {"ingored"};
      // ros::init(argc, &argv, node_name);
      ros::init(argc, argv, node_name);
#endif
      _comm_entity = std::make_shared<ENTITY>();
      _publisher = std::make_unique<PUBLISHER<Message>>(_comm_entity);
      _subscriber = std::make_unique<SUBSCRIBER<Callback>>(_comm_entity);
  }

  void publish(const std::string& channel, const Message& msg, uint32_t queue_size) {
      _publisher->publish(channel, msg, queue_size);
  }

  void subscribe(const std::string& channel, const Callback& callback, void* context, uint32_t queue_size = 0) {
      _subscriber->subscribe(channel, callback, context, queue_size);
  }

  void handle() const {
#ifdef _LCM
      _comm_entity -> handle();
#elif defined(_ROS)
      ros::spinOnce();
#endif
  }

  ~IPCCommNode() {};
private:
  std::shared_ptr<ENTITY> _comm_entity;
  std::unique_ptr<Publisher<Message>> _publisher;
  std::unique_ptr<Subscriber<Callback>> _subscriber;
};

#endif //IPCCOMMNODE_HHH
