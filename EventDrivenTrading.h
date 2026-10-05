#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

class EventDrivenTrading {
public:
    void monitorNewsFeed(const std::string& feedName, const std::vector<std::string>& newsAnnouncements);
};

