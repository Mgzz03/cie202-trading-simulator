#include "Backtester.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;
Backtester::Backtester(const std::vector<double>& prices, const std::vector<int>& signals, double initialCapital) :
    prices_(prices), signals_(signals), initialCapital_(initialCapital), riskFreeRate_(0.0), variance_(0.0) {}

void Backtester::simulateTrades() {
    int numShares = 0;
    double cash = initialCapital_;
    double totalValue = 0.0;
    double maxDrawdown = 0.0;
    double peakValue = 0.0;
    double returns = 0.0;

    for (const double price : prices_) {
        int signal = signals_[&price - &prices_[0]];

        if (signal == 1 && cash > 0) {
            numShares = std::floor(cash / price);
            cash -= numShares * price;
        }
        else if (signal == -1 && numShares > 0) {
            cash += numShares * price;
            numShares = 0;
        }

        double currentValue = cash + numShares * price;
        totalValue = currentValue;

        if (totalValue > peakValue) {
            peakValue = totalValue;
        }
        double drawdown = (peakValue - totalValue) / peakValue;
        if (drawdown > maxDrawdown) {
            maxDrawdown = drawdown;
        }

        if (&price != &prices_[0]) {
            returns += std::log(price / *(std::prev(&price)));
        }
    }

    double averageReturns = std::exp(returns / static_cast<double>(prices_.size())) - 1.0;
    double finalValue = totalValue;
    double totalReturns = finalValue / initialCapital_ - 1.0;
    double sharpeRatio = (averageReturns - riskFreeRate_) / std::sqrt(variance_);

    std::cout << "Backtest Results" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Initial Capital: $" << initialCapital_ << std::endl;
    std::cout << "Final Value: $" << finalValue << std::endl;
    std::cout << "Total Returns: " << std::fixed << std::setprecision(2) << totalReturns * 100.0 << "%" << std::endl;
    std::cout << "Average Returns: " << std::fixed << std::setprecision(2) << averageReturns * 100.0 << "%" << std::endl;
    std::cout << "Maximum Drawdown: " << std::fixed << std::setprecision(2) << maxDrawdown * 100.0 << "%" << std::endl;
    std::cout << "Sharpe Ratio: " << std::fixed << std::setprecision(2) << sharpeRatio << std::endl;
}
//
//int main() {
//    vector<double> prices;
//    vector<int> signals;
//    double initialCapital;
//
//
//    cout << "Enter prices (press any non-numeric key to stop):" << endl;
//    double price;
//    while (cin >> price) {
//        prices.push_back(price);
//    }
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    cout << "Enter signals (1 for buy, -1 for sell, 0 for hold):" << endl;
//    int signal;
//    while (cin >> signal) {
//        signals.push_back(signal);
//    }
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    cout << "Enter initial capital:" << endl;
//    cin >> initialCapital;
//
//    Backtester bt(prices, signals, initialCapital);
//    bt.simulateTrades();
//
//    return 0;
//}