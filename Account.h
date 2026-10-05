#pragma once
#include <iostream>
#include <string>
using namespace std;


class Account
{
private:
	string name;
public:

	Account(string name);
	void createAccount();

	void login();

};

