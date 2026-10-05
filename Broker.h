#pragma once
#include <iostream>
#include <vector>
#include "investor.h"


class Broker {
private:
    vector<Stock> stocks;
    vector<Investor> Investors;

public:
    void AddInvestor(const Investor& Investor);
    void RemoveInvestor(string name);
    void UpdateMarket();
    void BuyStock(string name, const std::string& stockSymbol, int quantity, int price);
    void SellStock(string name, const std::string& stockSymbol, int quantity, int price);
    void DisplayInvestors();
};

