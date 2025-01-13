#include <catch2/catch_test_macros.hpp>
#include "bankAccount.h"
#include "BankAccount.hpp" // Will be renamed

TEST_CASE("BankAccount class", "[bankaccount],[class]")
{
    bankAccount bankAccount(600, 1);

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
    bankAccount account1(600, 1);

    REQUIRE_NOTHROW(bank.addAccount(1, account1));
    
    REQUIRE_NOTHROW(bank.getAccount(1));
}