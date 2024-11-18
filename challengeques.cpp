#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    static int totalAccounts;
    static const int MIN_HIGH_VALUE = 1000;
    int accountNumber;
    float balance;

public:
    BankAccount(float initialBalance) : balance(initialBalance) {
        totalAccounts++;
        accountNumber = totalAccounts;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    void deposit(float amount) {
        balance += amount;
    }

    bool withdraw(float amount) {
        if (amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    bool isHighValueAccount() const {
        return balance >= MIN_HIGH_VALUE;
    }
};

int BankAccount::totalAccounts = 0;

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void addAccount(float initialBalance) {
        accounts.emplace_back(initialBalance);
    }

    void displayAllAccounts() const {
        for (const auto& account : accounts) {
            account.display();
        }
    }

    void displayHighValueAccounts() const {
        cout << "High-value accounts:" << endl;
        for (const auto& account : accounts) {
            if (account.isHighValueAccount()) {
                account.display();
            }
        }
    }
};

int main() {
    Bank myBank;

    myBank.addAccount(500);
    myBank.addAccount(1200);
    myBank.addAccount(750);
    myBank.addAccount(2500);
    myBank.addAccount(800);

    myBank.displayAllAccounts();
    myBank.displayHighValueAccounts();
    cout << "Total accounts created: " << BankAccount::getTotalAccounts() << endl;

    return 0;
}