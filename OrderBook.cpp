#include "OrderBook.h"
#include <algorithm>
#include <iostream>

OrderBook::OrderBook() {}

OrderBook::OrderBook(std::string stockSymbol) : stockSymbol_(stockSymbol) {}

void OrderBook::addOrder(Order order) {
    if (order.isBuyOrder()) {
        buyOrders_.push_back(order);
    }
    else {
        sellOrders_.push_back(order);
    }
}

void OrderBook::matchOrders() {
    std::sort(buyOrders_.begin(), buyOrders_.end(), [](Order a, Order b) { return a.getPrice() > b.getPrice(); });
    std::sort(sellOrders_.begin(), sellOrders_.end(), [](Order a, Order b) { return a.getPrice() < b.getPrice(); });

    auto buyIt = buyOrders_.begin();
    auto sellIt = sellOrders_.begin();
    while (buyIt != buyOrders_.end() && sellIt != sellOrders_.end()) {
        if (buyIt->getPrice() >= sellIt->getPrice()) {
            int quantity = std::min(buyIt->getQuantity(), sellIt->getQuantity());
            std::cout << "Matched " << quantity << " shares at " << sellIt->getPrice() << std::endl;
            buyIt->setQuantity(buyIt->getQuantity() - quantity);
            sellIt->setQuantity(sellIt->getQuantity() - quantity);
            if (buyIt->getQuantity() == 0)
                buyIt++;
            if (sellIt->getQuantity() == 0)
                sellIt++;
        }
        else {
            break;
        }
    };

    buyOrders_.erase(std::remove_if(buyOrders_.begin(), buyOrders_.end(), [](Order order) { return order.getQuantity() == 0; }), buyOrders_.end());
    sellOrders_.erase(std::remove_if(sellOrders_.begin(), sellOrders_.end(), [](Order order) { return order.getQuantity() == 0; }), sellOrders_.end());
}


// int main() {
//     OrderBook orderBook("AAPL");

//     // Add buy orders
//     orderBook.addOrder(Order(100.0, 10, false));
//     orderBook.addOrder(Order(95.0, 20, true));
//     orderBook.addOrder(Order(105.0, 15, true));

//     // Add sell orders
//     orderBook.addOrder(Order(80.0, 10, false));
//     orderBook.addOrder(Order(115.0, 20, false));
//     orderBook.addOrder(Order(80., 25, true));

//     // Match orders
//     orderBook.matchOrders();

//     return 0;
// }
