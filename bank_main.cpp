// main.cpp
#include <iostream>
#include "bank_header.h"

using namespace std;

int main() {
    BankAccount account("Akash Masih", 123456, 1000.0);

    int choice;
    double amount;

    do {
        cout << "\n==== Bank Menu ====" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Display Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
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
                account.display();
                break;
            case 4:
                cout << "Thank you for using the bank system!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
