#ifndef LCMNODE_HHH
#define LCMNODE_HHH

#include "CommNode"

constexpr std::string default_ns = "memq://" ;

template<typename Data_t, typename Callback_t>
class LCMNode : public CommNode<Data_t, Callback_t>{
public:
  LCMNode() :
      _comm_entity(std::make_unique<lcm::LCM>(default_ns)),
      _publisher(std::make_unique<LcmPublisher<Data_t>>(_comm_entity)),
      _subscriber(std::make_shared<LcmSubscriber<Callback_t>>(_comm_entity)) {}

  void publish(const std::string& channel, const Data_t& data) {
      _publisher->publish(channel, data);
  }

  void subscribe(const std::string& channel, const Callback_t& callback) {
      _subscriber->subscribe(channel, callback);
  }

  ~LCMNode() {};
private:
    std::unique_ptr<lcm::LCM> _comm_entity;
    std::unique_ptr<Publisher<Data_t>> _publisher;
    std::unique_ptr<Subscriber<Callback_t>> _subscriber;
};

#endif // LCMNODE_HHH 
