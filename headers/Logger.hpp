#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <string>
#include <mutex>
#include <condition_variable>

/**
 * @brief Singleton to handle logging
 */
class Logger {
public:
    Logger();

    static void info(std::string msg);
    
    static const Logger *getInstance();
private:
    static Logger *instance;

    std::mutex mtx;
    std::condition_variable cv;
};

#endif