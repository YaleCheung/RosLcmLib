#ifndef PUBLISHER_HHH
#define PUBLISHER_HHH

#include <string>
#include <lcm/lcm-cpp.hpp>
#include <memory>
#include <cassert>

template<typename Message>
class Publisher {
public:
    virtual void publish(const std::string& name, const Message& msg) const = 0;
    virtual ~Publisher() {};
};

#endif //  PUBLISHER_HHH
