#include "Bank.hpp"

int addAccount(int id, bankAccount info) {
    account[id] = info;
}

bankAccount& getAccount(int id) {
    return account.at(id);
}
