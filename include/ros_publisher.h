#ifndef ROSPUBLISER_HHH 
#define ROSPUBLISER_HHH 

#include "ros/ros.h"
#include <string>

#include <array>

constexpr uint32_t max_channels = 10;

template<typename Message>
class ROSPublisher : public Publisher<Message> {
public:
    ROSPublisher(std::shared_ptr<ros::Publisher> entity) :
        _publish_method(entity), _channels_in_use(0) {}

    void publish(const std::string& channel, const Message& msg, const uint32_t queue_size) {
        auto idx = _index_publisher(channel);
        // add a new publisher
        if (idx < 0) {
            assert(_channels_in_use < max_channels);
            idx = _channels_in_use;
            _publishers[idx] = _publish_method.advertise<Message>(channel, queue_size);
            _channels[idx] = channel;
            ++ _channels_in_use;
        }
        _publishers[idx].publish(msg);
    }

    ~ROSPublisher() {}

private:
    int _index_publisher(const std::string& channel) {
        for(auto i = 0; i < _channels_in_use; ++ i) {
            if(channel == _channels[i]) 
                return i;
        }
        return -1;
    }

    std::shared_ptr<ros::NodeHandle> _publish_method;
    std::array<ros::Publisher, max_channels> _publishers;
    std::array<std::string, max_channels> _channels;
    
    uint32_t _channels_in_use;
};

#endif //ROSPUBLISER_HHH
