#ifndef COMM_NODE_HHH
#define COMM_NODE_HHH

#include "Publisher.h"
#include "Subscriber.h"

template<typename Data_t, typename Callback_t>
class CommNode {
public:   
    virtual void publish(const std::string& channel, const Data_t& data) = 0;
    virtual void subscribe(const std::string& channel, const Callback_t& callback) = 0;
    virtual ~CommNode() {};
};

#endif // COMM_NODE_HHH
