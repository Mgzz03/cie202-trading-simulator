#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <numeric>

class Stock
{
private:
    string symbol;
    int num_shares;
    double dividend_yield;
    vector<double> historical_prices;
public:

    Stock(const std::string& symbol, int numShares, double price);

    string getSymbol() const;
    void setSymbol(string sym);
    int getNumShares() const;
    void setNumShares(int num_sh);
    double getDividendYield();
    void setDividendYield(double div_yield);
    vector<double> getHistoricalPrices();
    void setHistoricalPrices(vector<double> hist_prices);
    double calculateValue();
    double calculateTrend();
    void subtractShares(int numShares);
    void IncrementSharesOwned(int quantity);
    //bool operator==(const Stock& other);
};
