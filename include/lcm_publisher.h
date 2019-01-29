#ifndef LCMPUBLISHER_HHH
#define LCMPUBLISHER_HHH

#include "publisher.h"
template<typename Data_t> 
class LCMPublisher : public Publisher<Data_t> {
public:
    LCMPublisher(std::unique_ptr<lcm::LCM> entity) :
        _publish_method(entity) { }

    void publish(const std::string& channel, const Data_t& data) {
        assert(channel != "" && _publish_method->good());
        _publish_method->publish(channel, &data);
        _publish_method->handle();
    }

    ~LCMPublisher() {}
private:
    std::shared_ptr<lcm::LCM> _publish_method;
};

#endif //LCMPUBLISHER_HHH
