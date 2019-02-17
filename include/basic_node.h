#ifndef COMM_NODE_HHH
#define COMM_NODE_HHH

#include <string>

template<typename Message, typename Callback>
class CommNode {
public:   
    virtual void publish(const std::string& channel, const Message& msg, uint32_t queue_size) = 0;
    virtual void subscribe(const std::string& channel, const Callback& callback, void* context, uint32_t queue_size) = 0;
    virtual void handle() const = 0;

    virtual ~CommNode() {};
};

#endif // COMM_NODE_HHH
