#ifndef LOGGING_HHH
#define LOGGING_HHH

#include <thread>

class Logging {
public:
    enum LogLevel { DEBUG, INFO, WARN, ERROR, FATAL, LEVEL_NUM };

private:
    class Impl {
    public:
        typedef Logging::LogLevel LogLevel;
        Impl(LogLevel level, const FilePath& path, int line);
        ~Impl() {
          
        }
    private:
        std::chrono::time_point _tp;
        std::thread::id
        LogLevel _level;
        int _line
        FilePath _path;

    }
    Impl _imp;
};

#endif //LOGGING_HHH
