#include "Transaction.h"

Transaction::Transaction(const std::string& symbol, int quantity, double price)
    : symbol_(symbol), quantity_(quantity), price_(price) {}

std::string Transaction::getSymbol() const {
    return symbol_;
}

int Transaction::getQuantity() const {
    return quantity_;
}

double Transaction::getPrice() const {
    return price_;
}

double Transaction::calculateTotalCost() const {
    return quantity_ * price_;
}


//#include <iostream>
//#include "Transaction.h"
//
//int main() {
//    Transaction buyTransaction("AAPL", 10, 150.0);
//
//    // Get symbol, quantity, and price
//    std::string symbol = buyTransaction.getSymbol();
//    int quantity = buyTransaction.getQuantity();
//    double price = buyTransaction.getPrice();
//
//    std::cout << "Symbol: " << symbol << std::endl;
//    std::cout << "Quantity: " << quantity << std::endl;
//    std::cout << "Price: $" << price << std::endl;
//
//    // Calculate total cost
//    double totalCost = buyTransaction.calculateTotalCost();
//    std::cout << "Total Cost: $" << totalCost << std::endl;
//
//    return 0;
//}
