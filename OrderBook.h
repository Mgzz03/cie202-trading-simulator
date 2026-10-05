#pragma once
#include <vector>
#include <string>
#include "Order.h"

class OrderBook {
public:
    OrderBook();
    OrderBook(std::string stockSymbol);

    void addOrder(Order order);
    void matchOrders();

private:
    std::vector<Order> buyOrders_;
    std::vector<Order> sellOrders_;
    std::string stockSymbol_;
};
