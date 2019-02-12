#ifndef SUBSCRIBER_HHH
#define SUBSCRIBER_HHH

#include <string>
#include <memory>

using std::string;

template<typename Callback_t>
class Subscriber {
public:
    virtual void subscribe(const std::string& channel, const Callback_t& callback, void* context) = 0;
    virtual ~Subscriber() {};
};


#endif // SUBSCRIBER_HHH
