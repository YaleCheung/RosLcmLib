#ifndef PUBLISHER_HHH
#define PUBLISHER_HHH

#include <string>
#include <lcm/lcm-cpp.hpp>
#include <memory>
#include <cassert>

template<typename Data_t>
class Publisher {
public:
    virtual void publish(std::string name, const Data_t& data) = 0;
    virtual ~Publisher() = 0;
};

template<typename Data_t> 
class LcmPublisher : public Publisher<Data_t> {
public:
    LcmPublisher(std::shared_ptr<lcm::LCM> entity) {
        publish_method = entity;
    }

    void publish(const std::string& name, const Data_t& dt) {
        assert(name != "" && publish_method->good());
        publish_method->publish(name, &dt);
    }
private:
    std::shared_ptr<lcm::LCM> publish_method;
};
#endif //  PUBLISHER_HHH
