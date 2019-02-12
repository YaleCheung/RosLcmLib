#ifndef LCMNODE_HHH
#define LCMNODE_HHH

#include "basic_node.h"
#include "lcm_publisher.h"
#include "lcm_subscriber.h"

constexpr const char* default_ns = "memq://";

template<typename Data_t, typename Callback_t>
class LCMNode : public CommNode<Data_t, Callback_t>{
public:
  LCMNode() :
    _comm_entity(std::make_unique<lcm::LCM>()),
    _publisher(std::make_unique<LCMPublisher<Data_t>>(_comm_entity)),
    _subscriber(std::make_unique<LCMSubscriber<Callback_t>>(_comm_entity)) {}

  void publish(const std::string& channel, const Data_t& data) {
    _publisher->publish(channel, data);
  }

  void subscribe(const std::string& channel, const Callback_t& callback, void* ptr) {
    _subscriber->subscribe(channel, callback, ptr);
  }

  void start() {
     while(true)  
         _comm_entity -> handle();
  }

  ~LCMNode() {};
private:
  std::shared_ptr<lcm::LCM> _comm_entity;
  std::unique_ptr<Publisher<Data_t>> _publisher;
  std::unique_ptr<Subscriber<Callback_t>> _subscriber;
};

#endif // LCMNODE_HHH 
