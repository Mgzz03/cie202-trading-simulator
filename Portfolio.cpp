#include "Portfolio.h"
#include<iostream>
using namespace std;
#include <string>



Portfolio::Portfolio(string n)
{
    name = n;
}



bool Portfolio::hasStock(const string& symbol) const {
    for (const Stock& stock : stocks) {
        if (stock.getSymbol() == symbol) {
            return true;
        }
    }
    return false;
}

void Portfolio::addStock(const std::string& symbol, int numShares, double price) {
    Stock stock(symbol, numShares, price);
    stocks.push_back(stock);
}

void Portfolio::subtractStock(const std::string& symbol, int numShares, double price) {
    for (auto it = stocks.begin(); it != stocks.end(); ++it) {
        if (it->getSymbol() == symbol) {
            if (it->getNumShares() >= numShares) {
                it->subtractShares(numShares);
                double value = numShares * price;
                cash_balance += value;
                std::cout << "Successfully subtracted " << numShares << " shares of " << symbol << " from the portfolio."
                    << " Balance increased by $" << value << std::endl;
                return;
            }
            else {
                std::cout << "Error: Insufficient shares of " << symbol << " in the portfolio." << std::endl;
                return;
            }
        }
    }
    std::cout << "Error: Stock with symbol " << symbol << " not found in the portfolio." << std::endl;
}


void Portfolio::addBalance(double amount) {
    cash_balance += amount;
}

double Portfolio::getBalance() const {
    return cash_balance;
}

void Portfolio::subtractBalance(double amount) {
    if (amount > cash_balance) {
        std::cout << "Insufficient balance." << std::endl;
    }
    else {
        cash_balance -= amount;
    }
}

double Portfolio::calculatePortfolioValue()
{
    double portfolio_value = cash_balance;
    for (Stock s : stocks)
    {
        portfolio_value += s.calculateValue();
    }
    return portfolio_value;
}

void Portfolio::printPortfolio()
{
    cout << "Portfolio:\n";
    for (Stock s : stocks) {
        cout << s.getSymbol() << " - " << s.getNumShares() << " shares\n";
    }
    cout << "Cash balance: $" << cash_balance << endl;
    cout << "Total portfolio value: $" << calculatePortfolioValue() << endl;
}



//
//
//#include <iostream>
//#include "Portfolio.h"
//
//int main() {
//    // Create a portfolio
//    Portfolio portfolio("My Portfolio");
//
//    // Add stocks to the portfolio
//    portfolio.addStock("AAPL", 10, 150.0);
//    portfolio.addStock("GOOG", 5, 2500.0);
//
//    // Subtract stocks from the portfolio
//    portfolio.subtractStock("AAPL", 3, 150.0);
//
//    // Update the cash balance
//    portfolio.addBalance(1000.0);
//    portfolio.subtractBalance(500.0);
//
//    // Print the portfolio details
//    portfolio.printPortfolio();
//
//    // Calculate the portfolio value
//    double portfolioValue = portfolio.calculatePortfolioValue();
//    std::cout << "Portfolio Value: $" << portfolioValue << std::endl;
//
//    return 0;
//}
