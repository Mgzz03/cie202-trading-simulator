#include <iostream>
#include <vector>
#include "Market.h"
#include "Investor.h"
using namespace std;

void Market::AddStock(const Stock& stock) {
    stocks.push_back(stock);
}

void Market::UpdateStockPrices() {
    for (auto& stock : stocks) {
        double oldPrice = stock.getDividendYield();
        double newPrice = oldPrice + (rand() % 21 - 10) / 10.0; 
        stock.setDividendYield(newPrice);
    }
}

void Market::BuyStock(const std::string& stockSymbol, int quantity, Investor& Investor) {
    for (auto& stock : stocks) {
        if (stock.getSymbol() == stockSymbol) {
            double totalPrice = stock.getDividendYield() * quantity;
            if (Investor.getBalance() < totalPrice) {
                cout << "Investor does not have enough balance to buy " << quantity << " shares of " << stockSymbol << endl;
                return;
            }
            Investor.subtractBalance(totalPrice);
            Investor.addStock(stockSymbol, quantity,totalPrice);
            stock.IncrementSharesOwned(quantity);
            cout << "Investor bought " << quantity << " shares of " << stockSymbol << " for $" << totalPrice << endl;
            return;
        }
    }
    cout << "Stock with symbol " << stockSymbol << " does not exist." << endl;
}

void Market::SellStock(const string& stockSymbol, int quantity, Investor& Investor) {
    for (auto& stock : stocks) {
        if (stock.getSymbol() == stockSymbol) {
            if (!Investor.hasStock(stockSymbol)) {
                cout << "Investor does not have " << quantity << " shares of " << stockSymbol << endl;
                return;
            }
            double totalPrice = stock.getDividendYield() * quantity;
            Investor.addBalance(totalPrice);
            Investor.subtractStock(stockSymbol, quantity,totalPrice);
            stock.subtractShares(quantity);
            cout << "Investor sold " << quantity << " shares of " << stockSymbol << " for $" << totalPrice << endl;
            return;
        }
    }
    cout << "Stock with symbol " << stockSymbol << " does not exist." << endl;
}


#include <iostream>
#include "Investor.h"
#include "Market.h"
#include "Stock.h"

int main() {
    // Create an investor
    Investor investor("John Doe");
    investor.addBalance(10000.0);

    // Create a market
    Market market;

    // Add stocks to the market
    Stock stock1("AAPL", 10, 150.0);
    Stock stock2("GOOGL", 5, 2500.0);
    market.AddStock(stock1);
    market.AddStock(stock2);

    // Update stock prices in the market
    market.UpdateStockPrices();

    // Buy stocks
    market.BuyStock("AAPL", 3, investor);
    market.BuyStock("GOOGL", 2, investor);

    // Sell stocks
    market.SellStock("AAPL", 2, investor);
    market.SellStock("GOOGL", 1, investor);

    return 0;
}
