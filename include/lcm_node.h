#ifndef LCMNODE_HHH
#define LCMNODE_HHH

#include "basic_node.h"
#include "lcm_publisher.h"
#include "lcm_subscriber.h"

constexpr const char* default_ns = "memq://";

template<typename Message, typename Callback>
class LCMNode : public CommNode<Message, Callback>{
public:
  LCMNode() :
    _comm_entity(std::make_unique<lcm::LCM>()),
    _publisher(std::make_unique<LCMPublisher<Message>>(_comm_entity)),
    _subscriber(std::make_unique<LCMSubscriber<Callback>>(_comm_entity)) {}

  void publish(const std::string& channel, const Message& msg) const {
    _publisher->publish(channel, msg);
  }

  void subscribe(const std::string& channel, const Callback& callback, void* context) const{
    _subscriber->subscribe(channel, callback, context);
  }

  void run() const {
     while(true)  
         _comm_entity -> handle();
  }

  ~LCMNode() {};
private:
  std::shared_ptr<lcm::LCM> _comm_entity;
  std::unique_ptr<Publisher<Message>> _publisher;
  std::unique_ptr<Subscriber<Callback>> _subscriber;
};

#endif // LCMNODE_HHH 
