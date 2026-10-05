#pragma once


#include <iostream>

class Wallet {
private:
    double balance;

public:
    Wallet(double initialBalance = 0.0);
    double getBalance() const;
    void addCash(double amount);
    void removeCash(double amount);
};


