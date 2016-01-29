#pragma once
#include "BankAccount.h"
class CheckingAccount :
	public BankAccount
{
public:
	CheckingAccount(int, double, string);
	double writeCheck();
	void advanceMonth();
};

