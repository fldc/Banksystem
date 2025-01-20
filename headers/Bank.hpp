#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>
#include "bankAccount.h"

class Bank
{
private:
    // Ändrade från bankAccount till bankAccount* eftersom annars bygger inte programmet.
    std::map <int, bankAccount*> account;
public:
    void addAccount(int id, bankAccount* info);
    bankAccount* getAccount(int id);
    ~Bank();
};

#endif