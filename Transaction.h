#pragma once
#include <string>
#include <vector>
using namespace std;

class Transaction {
private:
    string symbol_;
    int quantity_;
    double price_;

public:
    Transaction(const string& symbol, int quantity, double price);

    string getSymbol() const;
    int getQuantity() const;
    double getPrice() const;
    double calculateTotalCost() const;
};

