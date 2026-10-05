#include "profit.h"
#include <numeric>
using namespace std;
#include<iostream>
void Profit::addTrade(double trade) {
    trades.push_back(trade);
}

double Profit::calculateProfitOrLoss() {
    double totalTrades = std::accumulate(trades.begin(), trades.end(), 0.0);
    return totalTrades;
}

void Profit::setAccountNumber(int newValue) {
    accountNumber = newValue;
}

int Profit::getAccountNumber() {
    return accountNumber;
}


//
//int main()
//{
//    Profit account;
//
//    int numTrades;
//    cout << "Enter the number of trades: ";
//    cin >> numTrades;
//
//    for (int i = 0; i < numTrades; i++) {
//        double trade;
//        cout << "Enter the trade value #" << i + 1 << ": ";
//        cin >> trade;
//        account.addTrade(trade);
//    }
//
//
//    double profitOrLoss = account.calculateProfitOrLoss();
//    cout << "Profit/Loss: $" << profitOrLoss << endl;
//
//
//    int accountNumber;
//    cout << "Enter the account number: ";
//    cin >> accountNumber;
//    account.setAccountNumber(accountNumber);
//
//    cout << "Account number: " << account.getAccountNumber() << endl;
//
//    return 0;