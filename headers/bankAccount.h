class bankAccount {
private: 
    int balance;
    int accountNumber;

public: 
    bankAccount(int balance, int accountNumber);
    bankAccount(int accountNumber);
    void deposit(int amount);
    void withdraw(int amount);
    int getBalance();
};