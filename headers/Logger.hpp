#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <string>
#include <mutex>
#include <condition_variable>
#include <fstream>

/**
 * @brief Singleton to handle logging
 */
class Logger {
private:
    std::mutex mtx;
    std::condition_variable cv;
    Logger();
public:
    Logger() = delete;

    static void logInfo(time_t timestamp, double accountBalance, double difference);
    
    Logger &getInstance();
};

#endif