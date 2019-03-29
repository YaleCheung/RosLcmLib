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

    }
    class LogPreamble : NonCopyable {
    public: 
        LogPreamble() {}

        void addDate()       {_buf.append("%04d-%02d-%02d ", 15);}
        void addTime()       {_buf.append("%02d:%02d:%02d.%03lld ", 23);}
        void addUpTime()     {_buf.append("(%6.3f) ", 8);}
        void addTid()        {_buf.append("%-*s ", 5);}
        void addFileInfo()   {_buf.append("%*s:%-5u ", 9);}
        void addLogLevel()   {_buf.append("%4s ", 4);}
        void addSplitter()   {_buf.append("%1s ", 1);}
    private:
        Buffer _buf;
    }
    
    Impl _imp;
};

#endif //LOGGING_HHH
