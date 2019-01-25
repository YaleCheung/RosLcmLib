#ifndef COMM_NODE_HHH
#define COMM_NODE_HHH

#include "Publisher.h"
#include "Subscriber.h"

template<typename Data_t>
class CommNode {
public:   
    virtual void publish(const std::string& channel, const Data_t& data) = 0;
    virtual void subscribe(const std::string& channel, const Callback_t& callback) = 0;
    virtual ~CommNode() = 0;
};

template<typename Data_t>
class LcmNode : public CommNode<Data_t>{
public:
  typedef std::function<void(const lcm::ReceiveBuffer*, const std::string&, const Data_t*, void*)> LcmCallback_t;
  LcmNode() :
      _comm_entity(std::make_shared<lcm::LCM>()) {
      _publisher = std::make_shared<LcmPublisher>(_comm_entity);
      _subscriber = std::make_shared<LcmSubscriber>(_comm_entity);
  }

  void publish(const std::string& channel, const Data_t& data) {
      _publisher->publish(channel, data);
  }

  void subscribe<LcmCallback_t>(const std::string& channel, LcmCallback_t callback) {
      _subscriber->subscribe(channel, callback);
  }

  ~LcmNode() {};
private:
    std::shared_ptr<Data_t> _comm_entity;
    std::shared_ptr<Publisher<Data_t>> _publisher;
    std::shared_ptr<Subscriber> _subscriber;
};

#endif // COMM_NODE_HHH
