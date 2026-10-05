#pragma once
using namespace std;
class Order
{
private:
    double price_;
    int quantity_;
    bool buyOrder_;
public:
    Order(double price, int quantity, bool buyOrder);

    double getPrice() const;
    int getQuantity() const;
    bool isBuyOrder() const;
    void setQuantity(int quantity);
};