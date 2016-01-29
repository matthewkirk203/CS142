#pragma once
#include <string>
using namespace std;

double const SAVINGS_INTEREST = 1.01;

double const CD_INTEREST = 0.0185; //This is different because it has to be to implement it the right way.

int const CD_DURATION = 120; // There was no duration given, so the bank defaults the required duration at 10 years (or 120 months);

double const PENALTY = 5;

double const UNDER_MINIMUM = 6;

class BankAccount // it doesn't make sense to me to have open and closing as member functions.
{
public:
	BankAccount(int, double, string);
	string getOwner();
	int getNumber();
	string getType();
	double getBalance();
	virtual void advanceMonth();
	virtual void withdraw(double);
	virtual void deposit(double);
	virtual string tostr();
protected:
	int account_number;
	double current_balance;
	string owner;
	int months; //in existence
	string accountType;
};

