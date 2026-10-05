#include <iostream>
#include "Investor.h"
#include "Market.h"
#include "Order.h"
#include "OrderBook.h"
#include "Portfolio.h"
#include "Prediction.h"
#include "Transaction.h"
#include "Stock.h"
#include "Profit.h"
#include "Wallet.h"
#include "Watchlist.h"
#include "backtester.h"

int main() {
    // Create a Investor
    Investor Investor("John Doe");

    // Create a market
    Market market;

    // Create stocks and add them to the market
    Stock stock1("AAPL", 10, 150.0);
    Stock stock2("GOOGL", 5, 2500.0);
    market.AddStock(stock1);
    market.AddStock(stock2);

    // Create an order book
    OrderBook orderBook("AAPL");

    // Create buy and sell orders
    Order buyOrder(155.0, 5, true);
    Order sellOrder(160.0, 3, false);

    // Add orders to the order book
    orderBook.addOrder(buyOrder);
    orderBook.addOrder(sellOrder);

    // Match orders in the order book
    orderBook.matchOrders();

    // Create a portfolio for the Investor
    Portfolio portfolio("My Portfolio");

    // Add stocks to the portfolio
    portfolio.addStock("AAPL", 10, 150.0);
    portfolio.addStock("GOOGL", 5, 2500.0);

    // Subtract shares from the portfolio
    portfolio.subtractStock("AAPL", 3, 155.0);

    // Get the portfolio balance
    double balance = portfolio.getBalance();

    // Create a prediction
    std::vector<double> historicalData = { 150.0, 160.0, 155.0, 165.0 };
    Prediction prediction(historicalData);

    // Get the prediction for the current price
    std::string predictionResult = prediction.get_prediction(160.0);

    // Create a transaction
    Transaction transaction("AAPL", 5, 155.0);

    // Calculate the total cost of the transaction
    double totalCost = transaction.calculateTotalCost();

    // Create a profit
    Profit profit;
    profit.addTrade(100.0);
    profit.addTrade(-50.0);

    // Calculate the total profit or loss
    double totalProfitOrLoss = profit.calculateProfitOrLoss();

    // Create a wallet for the Investor
    Wallet wallet(5000.0);

    // Get the wallet balance
    double walletBalance = wallet.getBalance();

    // Add cash to the wallet
    wallet.addCash(1000.0);

    // Remove cash from the wallet
    wallet.removeCash(500.0);

    // Create a watchlist for the Investor
    Watchlist watchlist(Investor);

    // Add stocks to the watchlist
    watchlist.addStock(stock1);
    watchlist.addStock(stock2);

    // Get the stocks in the watchlist
    std::vector<Stock> stocks = watchlist.getStocks();

    // Display the stocks in the watchlist
    std::cout << "Stocks in the Watchlist:" << std::endl;
    for (Stock& stock : stocks) {
        std::cout << "Symbol: " << stock.getSymbol() << ", Num Shares: " << stock.getNumShares() << ", Price: $" << stock.getDividendYield() << std::endl;
    }

    // Create a backtester
    Backtester backtester(historicalData, { 1, 1, -1, 1 }, 10000.0);

    // Perform backtest and calculate results
    backtester.simulateTrades();

    return 0;
}
