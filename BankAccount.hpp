#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <iostream>
#include <map>

class Bank
{
private:
    std::map <int, BankAccount> account;
public:
    Bank(/* args */);
    ~Bank();

    int addAccount(int id, BankAccount info);
    BankAccount& getAccount(int id);
};

#endif