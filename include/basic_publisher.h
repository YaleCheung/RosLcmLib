#ifndef PUBLISHER_HHH
#define PUBLISHER_HHH

#include <string>
#include <lcm/lcm-cpp.hpp>
#include <memory>
#include <cassert>

template<typename Data_t>
class Publisher {
public:
    virtual void publish(const std::string& name, const Data_t& data) = 0;
    virtual ~Publisher() {};
};

#endif //  PUBLISHER_HHH
