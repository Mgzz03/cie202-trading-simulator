#pragma once
#include "Transaction.h"

class CommissionCalculator {
public:
    double calculateCommission(const Transaction& transaction) const;
};
