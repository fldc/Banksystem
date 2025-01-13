#include "bankAccount.h"
#include <iostream>

bankAccount::bankAccount(int balance, int accountNumber)
{
    this->balance = balance;
    this->accountNumber = accountNumber;
}

bankAccount::bankAccount(int accountNumber)
{
    this->balance = 0;
    this->accountNumber = accountNumber;
}

void bankAccount::deposit(int amount)
{
    if(amount == 0)
    {
        throw "Invalid amount";
    }
    balance += amount;

}

void bankAccount::withdraw(int amount)
{
    if (amount > balance)
    {
        throw "Insufficient funds";
    }
    else if(amount == 0)
    {
        throw "Invalid amount";
    }
    balance -= amount;

}

int bankAccount::getBalance()
{
    return balance;
}
