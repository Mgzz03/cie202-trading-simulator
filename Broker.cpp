#include <iostream>
#include <vector>
#include "Broker.h"
#include "Market.h"
#include "Investor.h"
using namespace std;

void Broker::AddInvestor(const Investor& Investor) {
    Investors.push_back(Investor);
}

void Broker::RemoveInvestor(string name) {
    for (auto it = Investors.begin(); it != Investors.end(); ++it) {
        if (it->getName() == name) {
            Investors.erase(it);
            std::cout << "Investor with ID " << name << " removed successfully." << endl;
            return;
        }
    }
    std::cout << "Investor with Name: " << name << " not found." << endl;
}

void Broker::UpdateMarket() {
    std::cout << "Market updated successfully." << endl;
}

void Broker::BuyStock(string name, const std::string& stockSymbol, int quantity,int price) {
    for (Investor& Investor : Investors) {
        if (Investor.getName() == name) {
            Investor.BuyStock(stockSymbol, quantity,price);
            return;
        }
    }
    std::cout << "Investor with Name " << name << " not found." << std::endl;
}

void Broker::SellStock(string name, const std::string& stockSymbol, int quantity,int price) {
    for (auto& Investor : Investors) {
        if (Investor.getName() == name) {
            Investor.SellStock(stockSymbol, quantity, price);
            return;
        }
    }
    std::cout << "Investor with ID " << name << " not found." << std::endl;
}

void Broker::DisplayInvestors() {
    std::cout << "Investors:" << endl;
    for (auto& Investor : Investors) {
        std::cout << "ID: " << Investor.getName() << ", Name: " << Investor.getName() << endl;
    }
}

#include <iostream>
#include "Broker.h"
#include "Investor.h"
#include "Market.h"
//
//int main() {
//    // Create a broker
//    Broker broker;
//
//    // Create investors
//    Investor investor1("John Doe");
//    investor1.addBalance(10000.0);
//    Investor investor2("Jane Smith");
//    investor2.addBalance( 5000.0);
//
//    // Add investors to the broker
//    broker.AddInvestor(investor1);
//    broker.AddInvestor(investor2);
//
//    // Remove an investor from the broker
//    broker.RemoveInvestor("John Doe");
//
//    // Create a market
//    Market market;
//
//    // Update the market
//    broker.UpdateMarket();
//
//    // Buy stocks for an investor
//    broker.BuyStock("Jane Smith", "AAPL", 3, 150);
//    broker.BuyStock("Jane Smith", "GOOGL", 2, 2500);
//
//    // Sell stocks for an investor
//    broker.SellStock("Jane Smith", "AAPL", 2, 160);
//    broker.SellStock("Jane Smith", "GOOGL", 1, 2600);
//
//    // Display all investors
//    broker.DisplayInvestors();
//
//    return 0;
//}
