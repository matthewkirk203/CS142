#pragma once
#include "CheckingAccount.h"


CheckingAccount::CheckingAccount(int number, double balance, string name)
	: BankAccount(number, balance, name)
{
	accountType = "Checking";
}


double CheckingAccount::writeCheck()
{
	return 1;
}

void CheckingAccount::advanceMonth()
{
	if (current_balance < 300)
	{
		current_balance -= UNDER_MINIMUM;
	}
	months++;
}
