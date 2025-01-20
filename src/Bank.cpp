#include "Bank.hpp"

void Bank::addAccount(int id, bankAccount* info) {
    // Något sätt att kolla om info är allokerad på heap kanske?
    account[id] = info;
}

bankAccount* Bank::getAccount(int id) {
    return account.at(id);
}

Bank::~Bank()
{
    for (auto [key, value] : this->account)
    {
        delete value;
        value = nullptr;
    }
}
