#pragma once
#include <vector>

class Profit {
private:
    std::vector<double> trades;
    int accountNumber;

public:
    void addTrade(double trade);
    double calculateProfitOrLoss();
    void setAccountNumber(int newValue);
    int getAccountNumber();
};

