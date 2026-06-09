#include <iostream>
#include <fstream>
using namespace std;

class Bank {
private:
    string name;
    int accNo;
    float balance;

public:
    // Load data
    void load() {
        ifstream file("account.txt");

        if (file.is_open()) {
            file >> name >> accNo >> balance;
            file.close();
        } else {
            name = "";
            accNo = 0;
            balance = 0;
        }
    }

    // Save data
    void save() {
        ofstream file("account.txt");
        file << name << " " << accNo << " " << balance;
        file.close();
    }

    void createAccount() {
        cout << "\nEnter name: ";
        cin >> name;

        cout << "Enter account number: ";
        cin >> accNo;

        cout << "Enter initial balance: ";
        cin >> balance;

        save();

        cout << "Account created successfully!\n";
    }

    void displayBalance() {
        load();

        cout << "\n--- ACCOUNT DETAILS ---\n";
        cout << "Name: " << name << endl;
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit() {
        load();

        float amount;
        cout << "\nEnter deposit amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }

        balance += amount;
        save();

        cout << "Deposit successful!\n";
        cout << "Updated Balance: " << balance << endl;
    }

    void withdraw() {
        load();

        float amount;
        cout << "\nEnter withdrawal amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }

        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return;
        }

        balance -= amount;
        save();

        cout << "Withdrawal successful!\n";
        cout << "Updated Balance: " << balance << endl;
    }
};

int main() {
    Bank b;
    int choice;

    do {
        cout << "\n======================";
        cout << "\n BANK MANAGEMENT SYSTEM";
        cout << "\n======================";
        cout << "\n1. Create Account";
        cout << "\n2. Balance Check";
        cout << "\n3. Deposit";
        cout << "\n4. Withdraw";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                b.createAccount();
                break;

            case 2:
                b.displayBalance();
                break;

            case 3:
                b.deposit();
                break;

            case 4:
                b.withdraw();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}