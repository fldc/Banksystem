#ifndef BANK_HPP
#define BANK_HPP

#include <map>
#include <mutex>
#include "bankaccount.h"

class Bank
{
    std::map<int, BankAccount*> account;
    std::mutex mapMtx;

public:
    const std::map<int, BankAccount*>& getAccounts() const noexcept;

    void addAccount(int id, BankAccount* info);
    BankAccount* getAccount(int id);
    ~Bank();
};

#endif
