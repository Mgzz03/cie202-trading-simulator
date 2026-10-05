#pragma
#include "Investor.h"
#include <iostream>
#include "Market.h"
#include "Broker.h"
#include "Portfolio.h"

Investor::Investor(string name) : name(name), portfolio(Portfolio("My Portfolio")) {}

string Investor::getName() 
{
    return name;
}

void Investor::viewPortfolio()
{
    cout << "Portfolio value: $" << portfolio.calculatePortfolioValue() << endl;
}

double Investor::getBalance() const {
    return balance;
}

void Investor::addBalance(double amount) {
    balance += amount;
    cout << "Balance updated, Current balance: $" << balance << endl;
}

void Investor::subtractBalance(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Balance updated, Current balance: $" << balance << endl;
    }
    else {
        cout << "Insufficient balance." << endl;
    }
}

bool Investor::hasStock(const string& symbol) const {
    return portfolio.hasStock(symbol);
}

void Investor::addStock(const std::string& symbol, int numShares, double price) {
    portfolio.addStock(symbol, numShares, price);
    cout << "Stock added to the portfolio." << std::endl;
}

void Investor::subtractStock(const string& symbol, int numShares, double price) {
    if (portfolio.hasStock(symbol)) {
        portfolio.subtractStock(symbol, numShares, price);
        cout << "Stock subtracted from the portfolio." << endl;
    }
    else {
        cout << "Stock not found in the portfolio." << endl;
    }
}

Portfolio& Investor::getPortfolio() {
    return portfolio;
}
void Investor::BuyStock(const std::string& stockSymbol, int quantity,int price) {
    // Check if the Investor already owns the stock
    for (auto stock : stocks) {
        if (stock.getSymbol() == stockSymbol) {
            stock.IncrementSharesOwned(quantity);
            std::cout << "Bought " << quantity << " shares of " << stockSymbol << " for Investor " << getName() << std::endl;
            return;
        }
    }

    // If the Investor doesn't own the stock, create a new stock object and add it to the Investor's portfolio
    Stock newStock(stockSymbol, quantity,price);
    stocks.push_back(newStock);
    std::cout << "Bought " << quantity << " shares of " << stockSymbol << " for Investor " << getName() << std::endl;
}
void Investor::SellStock(const std::string& stockSymbol, int quantity,int price) {
    // Check if the Investor owns the stock
    for (auto& stock : stocks) {
        if (stock.getSymbol() == stockSymbol) {
            if (stock.getNumShares() >= quantity) {
                stock.subtractShares(quantity);
                std::cout << "Sold " << quantity << " shares of " << stockSymbol << " for Investor " << getName() << std::endl;
                return;
            }
            else {
                std::cout << "Investor " << getName() << " doesn't have enough shares of " << stockSymbol << std::endl;
                return;
            }
        }
    }

    // If the Investor doesn't own the stock, display an error message
    std::cout << "Investor " << getName() << " doesn't own any shares of " << stockSymbol << std::endl;
}

//#include <iostream>
//#include "Investor.h"
//
//int main() {
//    // Create an investor
//    Investor investor("John Doe");
//
//    // Add balance to the investor's account
//    investor.addBalance(5000.0);
//
//    // Buy stocks
//    investor.BuyStock("AAPL", 5, 155.0);
//    investor.BuyStock("GOOGL", 3, 2500.0);
//
//    // Subtract shares from the investor's portfolio
//    investor.SellStock("AAPL", 2, 160.0);
//
//    // View portfolio value
//    investor.viewPortfolio();
//
//    return 0;
//}
