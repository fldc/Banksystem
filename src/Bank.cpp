#include "Bank.hpp"

int Bank::addAccount(int id, bankAccount info) {
    account[id] = info;
}

bankAccount& Bank::getAccount(int id) {
    return account.at(id);
}
