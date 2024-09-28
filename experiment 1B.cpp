#include <iostream>
using namespace std;

class BankAccount {
    private:
        string accountHolder;
        double balance;

    public:
        BankAccount(string name, double initialBalance) : accountHolder(name), balance(initialBalance) {}

        void deposit(double amount) {
            balance += amount;
            cout << "Amount Deposited: " << amount << endl;
        }

        void withdraw(double amount) {
            if (amount > balance) {
                cout << "Insufficient balance!" << endl;
            } else {
                balance -= amount;
                cout << "Amount Withdrawn: " << amount << endl;
            }
        }

        void checkBalance() {
            cout << "Current Balance: " << balance << endl;
        }
};

int main() {
    BankAccount account("John Doe", 1000.0);
    int choice;
    double amount;

    do {
        cout << "\nBank Menu: " << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.checkBalance();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}