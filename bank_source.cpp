// bank_source.cpp
#include <iostream>
#include "bank_header.h"

using namespace std;

BankAccount::BankAccount(string holder, int number, double initialBalance) {
    accountHolder = holder;
    accountNumber = number;
    balance = initialBalance;
}

void BankAccount::deposit(double amount) {
    balance += amount;
    cout << "Deposited $" << amount << " successfully!" << endl;
}

void BankAccount::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient balance!" << endl;
    } else {
        balance -= amount;
        cout << "Withdrew $" << amount << " successfully!" << endl;
    }
}

void BankAccount::display() const {
    cout << "\nAccount Holder: " << accountHolder << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: $" << balance << endl;
}
