#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>

class Bank
{
private:
    std::map <int, bankAccount> account;
public:
    int addAccount(int id, bankAccount info);
    bankAccount& getAccount(int id);
};

#endif