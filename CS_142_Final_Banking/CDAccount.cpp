#pragma once
#include <sstream>
#include "CDAccount.h"
#include <iostream>


CDAccount::CDAccount(int number, double balance, string name)
	: SavingsAccount(number, balance, name)
{
	accountType = "CD";
	interestRate = CD_INTEREST;
	duration = CD_DURATION;
	interestBonus = 0;
}

void CDAccount::withdraw(double amount)
{
	if (months < CD_DURATION)
	{
		cout << "Warning! If you withdraw now, you will forefeit all interest gained until this point. You currently have " << CD_DURATION-months << " months until the account reaches maturity.\nContinue? (y/n)\n";
		string choice = "";
		cin >> choice;
		if (choice == "y")
		{
			if (current_balance >= amount)
			{
				current_balance -= amount;
				interestBonus = 0;
				months = 0;
				cout << "Delivering funds...\n";
				cout << "New Balance: $" << current_balance << ", Interest reset. Months until maturity: " << CD_DURATION - months << endl;
			}
			else
			{
				cout << "You don't have that much money! We are taking $5 from you...now. We are so mean, we know.\n";
				current_balance -= PENALTY; //I am assuming the balance can go negative (i.e. they are now in debt) from penalties.
				cout << "New Balance: $" << current_balance << "\n\n";
			}

		}
		else
		{
			cout << "Transaction cancelled\n\n";
		}
	}
	else
	{
		if (current_balance >= amount)//I assume past the 120 month mark CD accounts can be freely withdrawn from.
		{
			current_balance -= amount;
			cout << "Delivering funds...\n";
			cout << "New Balance: $" << current_balance << endl;
		}
		else
		{
			cout << "You don't have that much money! We are taking $5 from you...now. We are so mean, we know.\n";
			current_balance -= PENALTY; //I am assuming the balance can go negative (i.e. they are now in debt) from penalties.
			cout << "New Balance: $" << current_balance << "\n\n";
		}
	}
}

void CDAccount::advanceMonth()
{
	interestBonus = interestBonus + (current_balance + interestBonus)*CD_INTEREST;
	months++;
}

string CDAccount::tostr()
{
	ostringstream strm;
	strm << "Account#: " << account_number << ", Account Type: " << accountType << ", Owner: " << owner << ", Balance(including interest): $" << (current_balance + interestBonus) << ", Age (in months): " << months << "\n\n";
	return strm.str();
}

