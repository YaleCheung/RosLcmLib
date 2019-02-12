#ifndef COMM_NODE_HHH
#define COMM_NODE_HHH

#include "basic_publisher.h"
#include "basic_subscriber.h"

template<typename Data_t, typename Callback_t>
class CommNode {
public:   
    virtual void publish(const std::string& channel, const Data_t& data) = 0;
    // virtual void subscribe(const std::string& channel, const Callback_t& callback) = 0;
    virtual void subscribe(const std::string& channel, const Callback_t& callback, void* context) = 0;
    virtual void start() = 0;

    virtual ~CommNode() {};
};

#endif // COMM_NODE_HHH
