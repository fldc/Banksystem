#include "../src/BankAccount.cpp"

int addAccount(int id, BankAccount info) {
    account[id] = info;
}

BankAccount& getAccount(int id) {
    return account.at(id);
}