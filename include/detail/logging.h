#ifndef LOGGING_HHH
#define LOGGING_HHH


class Logging {
public:
    enum LogLevel {
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        LEVEL_NUM
    };

private:
    class Impl {
         
    }
    Impl* _imp;
};




#endif //LOGGING_HHH
