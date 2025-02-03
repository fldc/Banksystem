#include "bank.h"

/**
 * @param Id takes in id of the bankAccount
 * @param info a pointer to the bankAccount which is allocated to the heap.
 */
void Bank::addAccount(int Id, BankAccount* info) {
    std::lock_guard lock(this->mapMtx);
    account[Id] = info;
}

/**
 * @param id takes in id of the bankAccount
 * @returns A pointer to the account
 */
BankAccount* Bank::getAccount(int id) {
    std::lock_guard lock(this->mapMtx);
    return account.at(id);
}

Bank::~Bank()
{
    std::lock_guard lock(this->mapMtx);
    for (auto [key, value] : this->account)
    {
        delete value;
        value = nullptr;
    }
}

const std::map<int, BankAccount*>& Bank::getAccounts() const noexcept {
    return this->account;
}

