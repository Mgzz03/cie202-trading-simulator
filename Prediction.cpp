#include "Prediction.h"
using namespace std;
#include <iostream>


Prediction::Prediction(vector<double> data) {
    historical_data = data;
}

double Prediction::get_average() {
    double sum = 0.0;
    for (int i = 0; i < historical_data.size(); i++) {
        sum += historical_data[i];
    }
    return sum / historical_data.size();
}

string Prediction::get_prediction(double current_price) {
    double average = Prediction::get_average();
    if (current_price < average) {
        return "buy";
    }
    else {
        return "sell";
    }
}



//
//#include <iostream>
//#include <vector>
//#include "Prediction.h"
//
//int main() {
//    // Create a vector of historical data
//    std::vector<double> historicalData = { 100.0, 120.0, 110.0, 130.0, 140.0 };
//
//    // Create a Prediction object with the historical data
//    Prediction prediction(historicalData);
//
//    // Get the average of the historical data
//    double average = prediction.get_average();
//    std::cout << "Average: " << average << std::endl;
//
//    // Make a prediction based on the current price
//    double currentPrice = 120.0;
//    std::string predictionResult = prediction.get_prediction(currentPrice);
//    std::cout << "Prediction: " << predictionResult << std::endl;
//
//    return 0;
//}
