#pragma once
#include "BankAccount.h"
#include <iostream>
#include <sstream>



BankAccount::BankAccount(int number, double balance, string name)
{
	account_number = number;
	current_balance = balance;
	owner = name;
	accountType = "Bank";
	months = 0;
}

void BankAccount::advanceMonth()
{
	months++;
}

double BankAccount::getBalance()
{
	return current_balance;
}

string BankAccount::getOwner()
{
	return owner;
}

string BankAccount::getType()
{
	return accountType;
}

int BankAccount::getNumber()
{
	return account_number;
}

void BankAccount::deposit(double amount)
{
	current_balance += amount;
	cout << "New Balance: $" << current_balance << "\n\n";
}

void BankAccount::withdraw(double amount)
{
	if (current_balance >= amount)
	{
		current_balance -= amount;
		cout << "Delivering funds...\n";
		cout << "New Balance: $" << current_balance << "\n\n";
	}
	else
	{
		cout << "You don't have that much money! We are taking $5 from you...now.\n";
		current_balance -= PENALTY; //I am assuming the balance can go negative (i.e. they are now in debt) from penalties.
		cout << "New Balance: $" << current_balance << "\n\n";
	}
}

string BankAccount::tostr()
{
	ostringstream strm;
	strm << "Account#: " << account_number << ", Account Type: " << accountType << ", Owner: " << owner << ", Balance: $" << current_balance << ", Age (in months): " << months << "\n\n";
	return strm.str();
}
