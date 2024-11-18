#include <iostream>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept { return "Insufficient funds!"; }
};

class BankAccount {
    double balance;
public:
    BankAccount(double initialBalance = 0) : balance(initialBalance) {}
    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) {
        if (amount > balance) throw InsufficientFundsException();
        balance -= amount;
    }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount account(1000);
    try {
        account.deposit(500);
        account.withdraw(2000);
    } catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    }
    cout << "Remaining Balance: " << account.getBalance() << endl;
    return 0;
}
