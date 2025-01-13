#include <catch2/catch_test_macros.hpp>
#include "bankAccount.h" // Not yet implemented

TEST_CASE("BankAccount class", "[bankaccount],[class]")
{
    BankAccount bankAccount(600, 1);

    REQUIRE_THROWS(bankAccount.withdraw(-1));
    REQUIRE_THROWS(bankAccount.deposit(-1));

    REQUIRE_THROWS(bankAccount.withdraw(-1500));
    REQUIRE_THROWS(bankAccount.deposit(-1500));

    REQUIRE_THROWS(bankAccount.withdraw(0));
    REQUIRE_THROWS(bankAccount.deposit(0));

    REQUIRE(bankAccount.getBalance() == 600);

    bankAccount.withdraw(300);
    REQUIRE(bankAccount.getBalance() == 300);

    bankAccount.deposit(150);
    REQUIRE(bankAccount.getBalance() == 450);
}

TEST_CASE("Bank class", "[bank],[class]")
{
    Bank bank;
    BankAccount bankAccount(600, 1);

    REQUIRE_NOTHROW(bank.addAccount(1, bankAccount));
    
    BankAccount &account;
    REQUIRE_NOTHROW(account = bank.getAccount(1));
}