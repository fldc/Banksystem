#include <chrono>
#include <iostream>
#include <random>
#include <thread>

#include "Bank.hpp"
#include "bankAccount.h"

void client(Bank& bank, int clientid, int iterations)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> accountDist(1000, 1004);
    std::uniform_int_distribution<int> amountDist(10, 100);
    std::uniform_int_distribution<int> actionDist(1, 3);

    // random transactions
    for (int i = 0; i < iterations; i++)
    {
        int accountNumber = accountDist(gen);
        int amount  = amountDist(gen);
        int action  = actionDist(gen);

        bankAccount account = bank.getAccount(accountNumber);
        if (account)
        {
            switch (action)
            {
                case 1:
                    std::cout << "Customer" << clientid << " Account" << accountNumber
                              << " Deposit: " << amount << std::endl;
                    account->deposit(amount);
                    break;
                case 2:
                    std::cout << "Customer" << clientid << " Account" << accountNumber
                              << " Withdraw: " << amount << std::endl;
                    account->withdraw(amount);
                    break;
                case 3:
                    std::cout << "Customer" << clientid << " Account" << accountNumber
                              << " Balance: " << account->getBalance() << std::endl;
                    break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    Bank bank;

    // Create 5 accounts
    for (int i = 1000; i < 1005; ++i)
    {
        bank.addAccount(i, 1000);
    }

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i)
    {
        // Create 10 clients and make 5 transactions each
        threads.emplace_back(std::thread(client, std::ref(bank), i + 1, 5));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    return 0;
}