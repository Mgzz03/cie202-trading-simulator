#include "Watchlist.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


Watchlist::Watchlist(const Investor& Investor) : Investor_(Investor) {
    // Constructor with Investor parameter implementation
}

void Watchlist::addStock(const Stock& stock) {
    stocks_.push_back(stock);
}

void Watchlist::removeStock(const Stock& stock) {
    auto it = find(stocks_.begin(), stocks_.end(), stock);
    if (it != stocks_.end()) {
        stocks_.erase(it);
    }
}

std::vector<Stock> Watchlist::getStocks() const {
    return stocks_;
}



// int main() {
//     Watchlist watchlist(investor);

//     Stock aapl("AAPL");
//     Stock msft("MSFT");
//     Stock gaat("GAAT");
//     Stock hat("HAT");
//     Stock mat("MAT");
//     Stock fac("FAC");

//     watchlist.addStock(aapl);
//     watchlist.addStock(msft);
//     watchlist.addStock(gaat);
//     watchlist.addStock(hat);
//     watchlist.addStock(mat);
//     watchlist.addStock(fac);

//     watchlist.removeStock(fac);
//     watchlist.removeStock(mat);



//     std::vector<Stock> stocks = watchlist.getStocks();
//     for (Stock stock : stocks) {
//         std::cout << stock.getSymbol() << std::endl;
//     }

//     return 0;
// };