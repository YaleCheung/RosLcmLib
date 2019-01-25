#ifndef SUBSCRIBER_HHH
#define SUBSCRIBER_HHH

#include <string>
#include <memory>

using std::string;

class Subscriber {
public:
    virtual void subscribe(const std::string& name) = 0;
    virtual ~Subscriber() = 0;
};


template<typename Data_t>
class LcmSubscriber : public Subscriber {
public:
    typedef std::function<void(const lcm::ReceiveBuffer&, const std::string&, const Data_t*, void*)> Callback_t;

    LcmSubscriber(std::shared_ptr<lcm::LCM> entity) :
        _subscribe_method(entity) {}

    // void setChannel(const std::string& name) {
        // _channel = name;
    // }

    void subscribe(const std::string channel) {
        assert(channel != "");
        _subscribe_method -> subscribe(channel, _callback, nullptr);
        while(0 == _subscribe_method->handle()) {};
    }

private:
    std::shared_ptr<lcm::LCM> _subscribe_method;
};

#endif // SUBSCRIBER_HHH
