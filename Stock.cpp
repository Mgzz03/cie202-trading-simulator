#include "Stock.h"
#include<iostream>
using namespace std;
#include <string>
#include <chrono>
#include <xlocmon>

Stock::Stock(const std::string& symbol, int numShares, double price)
    : symbol(symbol), num_shares(numShares), dividend_yield(price) {}

void Stock::setSymbol(string sym)
{
    symbol = sym;

}
string Stock::getSymbol() const
{
    return symbol;
}
int Stock::getNumShares() const
{
    return num_shares;
}
void Stock::setNumShares(int num_sh)
{
    num_shares = num_sh;
}
double Stock::getDividendYield()
{
    return dividend_yield;
}
void Stock::setDividendYield(double div_yield)
{
    dividend_yield = div_yield;
}
vector<double> Stock::getHistoricalPrices()
{
    return historical_prices;
}
void Stock::setHistoricalPrices(vector<double> hist_prices)
{
    historical_prices = hist_prices;
};
double Stock::calculateValue()
{
    double total_value = 0;
    for (int i = 0; i < historical_prices.size(); i++) {
        total_value += historical_prices[i];
    }
    return total_value * num_shares;
}
double Stock::calculateTrend()
{
    double sum = accumulate(historical_prices.begin(), historical_prices.end(), 0.0);
    double avg = sum / historical_prices.size();
    return ((historical_prices[0] - avg) / avg) * 100;
}

void Stock::subtractShares(int numShares) {
    this->num_shares -= numShares;
    if (this->num_shares < 0) {
        this->num_shares = 0;
    }
}
void Stock::IncrementSharesOwned(int quantity) {
    num_shares += quantity;
}
//bool operator==(const Stock& other) {
//    // Compare the necessary attributes for equality
//    return (symbol == other.getSymbol());
//}

//
//#include <iostream>
//#include "Stock.h"
//
//int main() {
//    vector<double> hist_prices = { 135.3, 137.4, 142.5, 135.9, 129.5, 131.1 };
//    Stock s("AAPLE", 100, 0.015);
//
//    vector<double> histPrices = s.getHistoricalPrices();
//    double sum = 0;
//    for (double price : histPrices) {
//        sum += price;
//    }
//    double average = sum / histPrices.size();
//
//    double trend = s.calculateTrend();
//    double yield = s.getDividendYield();
//
//    cout << "Stock Symbol: " << s.getSymbol() << endl;
//    cout << "Average Historical Price: $" << average << endl;
//    cout << "Trend: " << trend << "%" << endl;
//    cout << "Dividend Yield: " << yield << "%" << endl;
//
//    return 0;
//}
