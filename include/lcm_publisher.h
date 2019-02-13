#ifndef LCMPUBLISHER_HHH
#define LCMPUBLISHER_HHH

#include "basic_publisher.h"
template<typename Message> 
class LCMPublisher : public Publisher<Message> {
public:
    LCMPublisher(std::shared_ptr<lcm::LCM> entity) :
        _publish_method(entity) { }

    void publish(const std::string& channel, const Message& msg) const {
        assert(channel != "" && _publish_method->good());
        _publish_method->publish(channel, &msg);
    }

    ~LCMPublisher() {}
private:
    std::shared_ptr<lcm::LCM> _publish_method;
};

#endif //LCMPUBLISHER_HHH
