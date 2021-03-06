#ifndef IPCCOMMNODE_HHH
#define IPCCOMMNODE_HHH

#include "detail/common.h"

#ifdef _LCM
#include "lcm_publisher_manager.h"
#include "lcm_subscriber_manager.h"
#define ENTITY lcm::LCM
#define PUBLISHER LCMPublisherManager
#define SUBSCRIBER LCMSubscriberManager

#elif defined(_ROS)

#include "ros_publisher_manager.h"
#include "ros_subscriber_manager.h"
#define ENTITY ros::NodeHandle
#define PUBLISHER ROSPublisherManager
#define SUBSCRIBER ROSSubscriberManager

#endif // include nothing, compiling process will be failed

// an abstract fractory pattern impletation of communication;

class IPCCommNode : NonCopyable {
public:
  IPCCommNode(const std::string& node_name) {
#ifdef _ROS
      int argc = 0;
      char* argv[1] = {"ingored"};
      ros::init(argc, argv, node_name);
#endif
      _comm_entity = std::make_shared<ENTITY>();
      _publisher_manager = std::make_unique<PUBLISHER>(_comm_entity);
      _subscriber_manager = std::make_unique<SUBSCRIBER>(_comm_entity);
  }

  template<typename Message>
  void publish(const std::string& channel, const Message& msg, uint32_t queue_size) {
      _publisher_manager->publish(channel, msg, queue_size);
  }

  template<typename Callback>
  void subscribe(const std::string& channel, const Callback& callback, void* context, uint32_t queue_size = 0) {
      _subscriber_manager->subscribe(channel, callback, context, queue_size);
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
  std::unique_ptr<PUBLISHER> _publisher_manager;
  std::unique_ptr<SUBSCRIBER> _subscriber_manager;
};

#endif //IPCCOMMNODE_HHH
