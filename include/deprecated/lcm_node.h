#ifndef LCMNODE_HHH
#define LCMNODE_HHH

#include "basic_node.h"
#include "lcm_publisher.h"
#include "lcm_subscriber.h"

template<typename Message, typename Callback>
class LCMNode : public CommNode<Message, Callback>{
public:
  LCMNode() :
    _comm_entity(std::make_unique<lcm::LCM>()),
    _publisher(std::make_unique<LCMPublisher<Message>>(_comm_entity)),
    _subscriber(std::make_unique<LCMSubscriber<Callback>>(_comm_entity)) {}

  // lcm doesn't support message queue, so drop it;
  void publish(const std::string& channel, const Message& msg, uint32_t queue_size) {
    _publisher->publish(channel, msg, 0);
  }

  // lcm doesn't support message queue, so drop it;
  void subscribe(const std::string& channel, const Callback& callback, void* context, uint32_t queue_size = 0) {
    _subscriber->subscribe(channel, callback, context, 0);
  }

  void handle() const {
      _comm_entity -> handle();
  }

  ~LCMNode() {};
private:
  std::shared_ptr<lcm::LCM> _comm_entity;
  std::unique_ptr<Publisher<Message>> _publisher;
  std::unique_ptr<Subscriber<Callback>> _subscriber;
};

#endif // LCMNODE_HHH 
