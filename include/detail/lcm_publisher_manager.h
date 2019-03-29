#ifndef LCMPUBLISHERMANAGER_HHH
#define LCMPUBLISHERMANAGER_HHH

#include <lcm/lcm-cpp.hpp>
#include "noncopyable.h"

class LCMPublisherManager : Noncopyable {
public:
    LCMPublisherManager(std::shared_ptr<lcm::LCM> entity) :
        _publish_method(entity) { }

    template<typename Message>
    void publish(const std::string& channel, const Message& msg, uint32_t buffer_size) {
        assert(channel != "" && _publish_method->good());
        _publish_method->publish(channel, &msg);
    }

    ~LCMPublisherManager() {}
private:
    std::shared_ptr<lcm::LCM> _publish_method;
};

#endif //LCMPUBLISHERMANAGER_HHH
