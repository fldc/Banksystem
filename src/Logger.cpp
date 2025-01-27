#include "Logger.hpp"

Logger::Logger() : mtx(mtx), cv(cv);

static void logInfo(time_t timestamp, double accountBalance, double difference) {
    std::ofstream file("transaction_log.txt", std::ios::app);

    file << timestamp << "\nTransaction: " << difference << "\n" << "Account balance: " << accountBalance << "\n" << std::endl;
}

static Logger *const getInstance() {
    static Logger *instance;
    return instance;
}