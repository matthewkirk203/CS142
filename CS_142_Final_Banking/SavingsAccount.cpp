#pragma once
#include <iostream>
#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(int number, double balance, string name)
	: BankAccount(number, balance, name)
{
	accountType = "Savings";
	interestRate = SAVINGS_INTEREST;
}

void SavingsAccount::advanceMonth()
{
	current_balance *= SAVINGS_INTEREST;
	months++;
}

