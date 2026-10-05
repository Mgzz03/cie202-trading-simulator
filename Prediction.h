#pragma once
using namespace std;
#include <string>
#include <vector>

class Prediction
{
private:
	vector<double> historical_data;
public:
	Prediction(vector<double> data);
	double get_average();
	string get_prediction(double current_price);

};