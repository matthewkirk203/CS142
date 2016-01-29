#pragma once
#include "bankaccount.h"
class SavingsAccount :
	public BankAccount
{
public:
	SavingsAccount(int, double, string);
	virtual void advanceMonth();
	string postInterest();
protected:
	double interestRate;
};

