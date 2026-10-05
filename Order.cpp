#include "Order.h"
using namespace std;
#include <iostream>



Order::Order(double price, int quantity, bool buyOrder)
    : price_(price), quantity_(quantity), buyOrder_(buyOrder) {}

double Order::getPrice() const { return price_; }
int Order::getQuantity() const { return quantity_; }
bool Order::isBuyOrder() const { return buyOrder_; }
void Order::setQuantity(int quantity) { quantity_ = quantity; }

//
//#include <iostream>
//#include "Order.h"
//
//int main() {
//    // Create a buy order
//    Order buyOrder(155.0, 5, true);
//
//    // Get the order details
//    double price = buyOrder.getPrice();
//    int quantity = buyOrder.getQuantity();
//    bool isBuyOrder = buyOrder.isBuyOrder();
//
//    // Output the order details
//    std::cout << "Price: " << price << std::endl;
//    std::cout << "Quantity: " << quantity << std::endl;
//    std::cout << "Is Buy Order: " << std::boolalpha << isBuyOrder << std::endl;
//
//    // Update the quantity
//    buyOrder.setQuantity(10);
//
//    // Get the updated quantity
//    quantity = buyOrder.getQuantity();
//
//    // Output the updated quantity
//    std::cout << "Updated Quantity: " << quantity << std::endl;
//
//    return 0;
//}
