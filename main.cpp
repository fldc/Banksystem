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
        int account = accountDist(gen);
        int amount  = amountDist(gen);
        int action  = actionDist(gen);

        Bankaccount* account = bank.getAccount(account);
        if (account)
        {
            switch (action)
            {
                case 1:
                    std::cout << "Customer" << clientid << " Account" << account
                              << " Deposit: " << amount << std::endl;
                    account->deposit(amount);
                    break;
                case 2:
                    std::cout << "Customer" << clientid << " Account" << account
                              << " Withdraw: " << amount << std::endl;
                    account->withdraw(amount);
                    break;
                case 3:
                    std::cout << "Customer" << clientid << " Account" << account
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