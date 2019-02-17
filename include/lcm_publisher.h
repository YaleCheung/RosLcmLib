#ifndef LCMPUBLISHER_HHH
#define LCMPUBLISHER_HHH

#include "basic_publisher.h"
#include <lcm/lcm-cpp.hpp>

template<typename Message> 
class LCMPublisher : public Publisher<Message> {
public:
    LCMPublisher(std::shared_ptr<lcm::LCM> entity) :
        _publish_method(entity) { }

    void publish(const std::string& channel, const Message& msg, uint32_t buffer_size) {
        assert(channel != "" && _publish_method->good());
        _publish_method->publish(channel, &msg);
    }

    ~LCMPublisher() {}
private:
    std::shared_ptr<lcm::LCM> _publish_method;
};

#endif //LCMPUBLISHER_HHH
