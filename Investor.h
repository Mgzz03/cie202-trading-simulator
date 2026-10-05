#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Portfolio.h"

class Investor
{
private:
    string name;
    Portfolio portfolio;
    double balance;
    vector<Stock> stocks;

public:
    Investor(string name);
    void viewPortfolio();
    string getName();
    double getBalance() const;
    void addBalance(double amount);
    void subtractBalance(double amount);
    Portfolio& getPortfolio();
    bool hasStock(const string& symbol) const;
    void addStock(const std::string& symbol, int numShares, double price);
    void subtractStock(const string& symbol, int numShares, double price);
    void BuyStock(const std::string& stockSymbol, int quantity,int price);
    void SellStock(const std::string& stockSymbol, int quantity,int price);
};





