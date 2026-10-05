#include "wallet.h"
#include <iostream>
using namespace std;

Wallet::Wallet(double initialBalance) {
    balance = initialBalance;
}

double Wallet::getBalance() const {
    return balance;
}

void Wallet::addCash(double amount) {
    balance += amount;
}

void Wallet::removeCash(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else {
        std::cout << "Error: Insufficient funds" << std::endl;
    }
}



//int main() {
//    double initialBalance;
//    cout << "Enter initial balance: $";
//    cin >> initialBalance;
//
//    Wallet myWallet(initialBalance);
//
//    double cashToAdd;
//    cout << "Enter cash to add: $";
//    cin >> cashToAdd;
//    myWallet.addCash(cashToAdd);
//
//    double cashToRemove;
//    cout << "Enter cash to remove: $";
//    cin >> cashToRemove;
//    myWallet.removeCash(cashToRemove);
//
//    cout << "Current balance: $" << myWallet.getBalance() << endl;
//
//    return 0;
