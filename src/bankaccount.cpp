#include "bankAccount.h"
#include <iostream>

BankAccount::BankAccount(const int balance, const int accountNumber)
{
    std::lock_guard lock(this->balanceMtx);
    this->balance = balance;
    this->accountNumber = accountNumber;
}

BankAccount::BankAccount(const int accountNumber)
{
    std::lock_guard lock(this->balanceMtx);
    this->balance = 0;
    this->accountNumber = accountNumber;
}

/**
 * @throws When amount is negative or zero
 */
void BankAccount::deposit(int amount)
{
    std::lock_guard lock(this->balanceMtx);
    if (amount <= 0)
    {
        throw "Invalid amount";
    }
    deposits += amount;
    balance += amount;
}

/**
 * @throws When amount is negative or zero
 */
void BankAccount::withdraw(int amount)
{
    std::lock_guard lock(this->balanceMtx);
    if (amount > balance)
    {
        throw "Insufficient funds";
    }
    else if (amount <= 0)
    {
        throw "Invalid amount";
    }

    withdraws += amount;
    balance -= amount;
}

int BankAccount::getBalance() const
{
    std::lock_guard lock(this->balanceMtx);
    return balance;
}

int BankAccount::getWithdraws() const
{
    std::lock_guard lock(this->balanceMtx);
    return withdraws;
}

int BankAccount::getDeposits() const
{
    std::lock_guard lock(this->balanceMtx);
    return deposits;
}

int BankAccount::getId() const
{
    return this->accountNumber;
}
