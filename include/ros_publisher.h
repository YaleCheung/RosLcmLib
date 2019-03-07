#ifndef ROSPUBLISER_HHH 
#define ROSPUBLISER_HHH 

#include "ros/ros.h"
#include "basic_publisher.h"

#include <string>
#include <array>


template<typename Message>
class ROSPublisher : public Publisher<Message> {
public:
    ROSPublisher(std::shared_ptr<ros::NodeHandle> entity) :
        _publish_method(entity), _channels_in_use(0) {}

    void publish(const std::string& channel, const Message& msg, uint32_t queue_size) {
        auto idx = _index_publisher(channel);
        // add a new publisher
        if (idx < 0) {
            assert(_channels_in_use < max_publishers);
            idx = _channels_in_use;
            _publishers[idx] = _publish_method -> advertise<Message>(channel, queue_size);
            _channels[idx] = channel;
            ++ _channels_in_use;
        }
        _publishers[idx].publish(msg);
    }

    ~ROSPublisher() {}

private:
    int _index_publisher(const std::string& channel) {
        for(auto i = uint32_t(0); i < _channels_in_use; ++ i) {
            if(channel == _channels[i]) 
                return i;
        }
        return -1;
    }

    static constexpr uint32_t max_publishers = 10;

    std::shared_ptr<ros::NodeHandle> _publish_method;
    std::array<ros::Publisher, max_publishers> _publishers;
    std::array<std::string, max_publishers> _channels;
    
    uint32_t _channels_in_use;
};

#endif //ROSPUBLISER_HHH
