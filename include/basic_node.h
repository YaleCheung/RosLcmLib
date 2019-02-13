#ifndef COMM_NODE_HHH
#define COMM_NODE_HHH

#include "basic_publisher.h"
#include "basic_subscriber.h"

template<typename Message, typename Callback>
class CommNode {
public:   
    virtual void publish(const std::string& channel, const Message& msg, const uint32_t queue_size) const = 0;
    virtual void subscribe(const std::string& channel, const Callback& callback, void* context, const uint32_t queue_size) const = 0;
    virtual void run() const = 0;

    virtual ~CommNode() {};
};

#endif // COMM_NODE_HHH
