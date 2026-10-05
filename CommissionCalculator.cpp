#include "CommissionCalculator.h"
// #include "Transaction.h"

double CommissionCalculator::calculateCommission(const Transaction& transaction) const {
    const double LOW_COMMISSION_RATE = 0.01;      // 1%
    const double HIGH_COMMISSION_RATE = 0.005;    // 0.5%

    // thresholds
    const double LOW_COMMISSION_THRESHOLD = 1000.0;   // $1000
    const double HIGH_COMMISSION_THRESHOLD = 10000.0; // $10000

    double totalCost = transaction.calculateTotalCost();

    double commission = 0.0;

    if (totalCost < LOW_COMMISSION_THRESHOLD) {
        commission = totalCost * LOW_COMMISSION_RATE;
    }
    else if (totalCost >= LOW_COMMISSION_THRESHOLD && totalCost < HIGH_COMMISSION_THRESHOLD) {
        commission = totalCost * HIGH_COMMISSION_RATE;
    }
    else {
        commission = totalCost * 0.0005;
    }

    return commission;
}
//
//#include <iostream>
//#include "CommissionCalculator.h"
//#include "Transaction.h"
//
//int main() {
//    // Create a transaction
//    Transaction transaction("AAPL", 5, 155.0);
//
//    // Create a commission calculator
//    CommissionCalculator commissionCalculator;
//
//    // Calculate the commission for the transaction
//    double commission = commissionCalculator.calculateCommission(transaction);
//
//    // Display the commission
//    std::cout << "Commission: $" << commission << std::endl;
//
//    return 0;
//}
