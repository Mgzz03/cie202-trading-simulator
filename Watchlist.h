#pragma once
#include <vector>
#include "Investor.h"
#include "Stock.h"

using namespace std;

class Watchlist {
private:
    Investor Investor_;
    vector<Stock> stocks_;

public:
    explicit Watchlist(const Investor& Investor);

    void addStock(const Stock& stock);
    void removeStock(const Stock& stock);
    vector<Stock> getStocks() const; 
};
