#ifndef ROSNODE_HHH
#define ROSNODE_HHH

#include <array>

#include "basic_node.h"
#include "ros_publisher.h"
#include "ros_subscriber.h"

constexpr uint32_t max_channels = 10;

template<typename Message, typename Callback>
class RosNode {
public:
    void publish(const std::string& channel, const Message& msg, const uint32_t queue_size) {
        
    }
private:
    std::array<
};


#endif  //ROSNODE_HHH 
