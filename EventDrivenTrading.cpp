#include "EventDrivenTrading.h"
#include <vector>
using namespace std;

void EventDrivenTrading::monitorNewsFeed(const std::string& feedName, const std::vector<std::string>& newsAnnouncements) {
    std::cout << "Monitoring " << feedName << " news feed..." << std::endl;
    for (size_t i = 0; i < newsAnnouncements.size(); i++) {
        std::cout << "News announcement: " << newsAnnouncements[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
//int main() {
//    EventDrivenTrading tradingSystem;
//
//    string newsFeed = "Bloomberg";
//    vector<string> news = {
//        "S&P 500 hits all-time high on strong earnings reports",
//        "Dow Jones Industrial Average rises on positive economic data",
//        "Nasdaq Composite index falls on tech sell-off",
//        "Tesla announces record quarterly profits",
//        "Apple launches new line of MacBooks with M1 chip",
//        "Amazon acquires MGM Studios for $8.45 billion",
//        "Bitcoin price drops on China's renewed crackdown on cryptocurrency",
//        "Oil prices surge on global economic recovery",
//        "Gold prices rise on inflation fears",
//        "European stocks rally on strong corporate earnings",
//        "Fed signals possible interest rate hike by end of year",
//        "US and China trade talks resume in effort to resolve ongoing trade dispute",
//        "NYSE announces plans to delist Chinese telecom firms",
//        "Warren Buffett's Berkshire Hathaway invests $8.6 billion in Verizon",
//        "UK and EU reach post-Brexit trade deal"
//    };
//
//    tradingSystem.monitorNewsFeed(newsFeed, news);
//
//    return 0;