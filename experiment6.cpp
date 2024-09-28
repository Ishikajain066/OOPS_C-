#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int number, double bal) {
        accountHolder = name;
        accountNumber = number;
        balance = bal;
    }

    string getAccountHolder() {
        return accountHolder;
    }

    double getBalance() {
        return balance;
    }

    void setBalance(double bal) {
        balance = bal;
    }

    friend class FriendFunction;
};

class FriendFunction {
public:
    static void transferFunds(BankAccount &fromAccount, BankAccount &toAccount, double amount) {
        if (fromAccount.getBalance() >= amount) {
            fromAccount.balance -= amount;
            toAccount.balance += amount;
        } else {
            cout << "Insufficient Funds" << endl;
        }
    }
};

int main() {
    BankAccount account1("Alice", 123456789, 1000);
    BankAccount account2("Bob", 987654321, 500);

   
    FriendFunction::transferFunds(account1, account2, 200);

    cout << account1.getAccountHolder() << "'s balance: " << account1.getBalance() << endl;
    cout << account2.getAccountHolder() << "'s balance: " << account2.getBalance() << endl;

    return 0;
}
