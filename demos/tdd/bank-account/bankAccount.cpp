#include "bankAccount.h"

BankAccount::BankAccount() {
    balance = 0;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::deposit(double amount) {
    if (amount >= 0){
        balance += amount;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount < 0 || amount > balance) { return;}
    balance -= amount;
}
