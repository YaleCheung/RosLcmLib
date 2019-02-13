#ifndef SUBSCRIBER_HHH
#define SUBSCRIBER_HHH

#include <string>
#include <memory>

template<typename Callback>
class Subscriber {
public:
    virtual void subscribe(const std::string& channel, const Callback& callback, void* context, const uint32_t queue_size) const = 0;
    virtual ~Subscriber() {};
};


#endif // SUBSCRIBER_HHH
