#include "Bank.hpp"

void Bank::addAccount(int id, bankAccount* info) {
    // Något sätt att kolla om info är allokerad på heap kanske?
    std::lock_guard<std::mutex> lock(this->mapMtx);
    account[id] = info;
}

bankAccount* Bank::getAccount(int id) {
    std::lock_guard<std::mutex> lock(this->mapMtx);
    return account.at(id);
}

Bank::~Bank()
{
    std::lock_guard<std::mutex> lock(this->mapMtx);
    for (auto [key, value] : this->account)
    {
        delete value;
        value = nullptr;
    }
}
