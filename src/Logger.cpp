#include "Logger.hpp"
#include <iostream>

Logger::Logger() {
}

void Logger::logInfo(time_t timestamp, double accountBalance, double difference) {
    std::ofstream file("transaction_log.txt", std::ios::app);

    if (file.is_open()) {
        file << timestamp << "\nTransaction: " << difference << "\n" << "Account balance: " << accountBalance << "\n" << std::endl;
        file.close();
    }
}

void Logger::logResults(std::map<int, bankAccount*> accounts) {
    std::cout << "\n--- Transaction report ---\n";
    for (auto [key, value] : accounts) {
        std::cout << "\nAccount " << key << 
            "\n\tBalance: " << value->getBalance() <<
            "\n\tWithdraws: " << value->getWithdraws() << 
            "\n\tDeposits: " << value->getDeposits() << std::endl; 
    }
}

Logger &Logger::getInstance() {
    static Logger instance;
    return instance;
}