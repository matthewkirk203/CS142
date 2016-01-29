#pragma once
#include "savingsaccount.h"
class CDAccount :
	public SavingsAccount
{
public:
	CDAccount(int, double, string);
	void withdraw(double amount);
	void advanceMonth();
	string tostr();
protected:
	int duration;
	double interestBonus;
};

