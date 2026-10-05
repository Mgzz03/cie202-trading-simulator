#pragma once
#include <iostream>
#include <vector>
#include "Stock.h"
using namespace std;

class Portfolio
{
private:
    vector<Stock> stocks;
    double cash_balance;
    string name;

public:

    Portfolio(string n);

    void addStock(const string& symbol, int numShares, double price);
    void subtractStock(const string& symbol, int numShares, double price);

    double calculatePortfolioValue();

    bool hasStock(const string& symbol) const;


    void printPortfolio();
    void addBalance(double amount);
    double getBalance() const;
    void subtractBalance(double amount);
};


