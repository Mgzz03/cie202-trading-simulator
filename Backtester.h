#pragma once
#ifndef BACKTESTER_H
#define BACKTESTER_H

#include <vector>

class Backtester {
public:
    Backtester(const std::vector<double>& prices, const std::vector<int>& signals, double initialCapital);

    void simulateTrades();

private:
    std::vector<double> prices_;
    std::vector<int> signals_;
    double initialCapital_;
    double riskFreeRate_;
    double variance_;
};

#endif
