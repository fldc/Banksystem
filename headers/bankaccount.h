#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <mutex>

class BankAccount
{
    int balance = 0;
    int deposits = 0;
    int withdraws = 0;
    int accountNumber = 0;

    std::mutex balanceMtx;

public:
    BankAccount(int balance, int accountNumber);
    explicit BankAccount(int accountNumber);
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance() const;
    int getWithdraws() const;
    int getDeposits() const;
    int getId() const;
};

#endif
