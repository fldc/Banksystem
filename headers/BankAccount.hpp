#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <iostream>
#include <map>

class Bank
{
private:
    std::map <int, BankAccount> account;
public:
    int addAccount(int id, BankAccount info);
    BankAccount& getAccount(int id);
};

#endif