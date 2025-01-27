#include "Logger.hpp"

Logger::Logger() {
}

void Logger::logInfo(time_t timestamp, double accountBalance, double difference) {
    std::ofstream file("transaction_log.txt", std::ios::app);

    file << timestamp << "\nTransaction: " << difference << "\n" << "Account balance: " << accountBalance << "\n" << std::endl;
}

Logger &Logger::getInstance() {
    static Logger instance;
    return instance;
}