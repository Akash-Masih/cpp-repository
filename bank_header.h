// bank_header.h
#ifndef BANK_H
#define BANK_H

#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string holder, int number, double initialBalance);
    
    void deposit(double amount);
    void withdraw(double amount);
    void display() const;
};

#endif
