#include "Account.h"

Account::Account(string name) : name(name) {}

void Account::createAccount()
{
    cout << "Welcome " << name << "! Your account has been created successfully." << endl;
}

void Account::login()
{
    cout << "Welcome back " << name << "!" << endl;
}