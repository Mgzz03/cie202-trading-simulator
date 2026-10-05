#pragma once


#include <iostream>
#include <vector>
#include "Stock.h"
#include "Investor.h"
using namespace std;

class Market {
private:
    std::vector<Stock> stocks;

public:
    void AddStock(const Stock& stock);
    void UpdateStockPrices();
    void BuyStock(const string& stockSymbol, int quantity, Investor& Investor);
    void SellStock(const string& stockSymbol, int quantity, Investor& Investor);
};



