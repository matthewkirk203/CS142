/*
Matthew kirk
Section: 4
12/6/2012
CS142 Final
Description: This program simulates the operations of a bank. It allows users to to various banking things.
Tests are included, TE fills the vector with 5 premade accounts for testings.
AN allows for advancing through several months at a time.
Interest is computed on the new balance each month (compound interest as opposed to simple)

Design:
The different accounts in the bank are defined by a class hierarchy.
The program uses a myriad of functions as well as utilizing class member functions and the convieniences of inheritence.

Test cases:
If the balance in a checking account is < 300, it will subtract $6 a month, even into making it negative.
Every month, interest will be computed and it will be different between CD and savings because the rates are different

Susan has an initial balance of $1000 in her savings account.
After one month she should have 1010 assuming no withdrawls.
after two months: 1020.1
3 months: 1030.3
4: 1040.6

Sally has an inital balance of $100 in her CD account.
After one month she should have 101.85 assuming no withdrawls.
2 months: 103.734
3: 105.65
4: 107.61

Deleteing any account will remove it from the vector without changing the account numbers for any other accounts.
Users are not allowed to deposit negative money values.
A user may only withdraw from savings accounts and write checks against checking accounts.
Entering a menu option that doesn't exist will reprompt the user.
All accounts seperately keep track of their age.
Attempting to withdraw from a CD account before maturity will erase the bonus interest.
Attempting to withdraw more than is in the account will subtract $5, even into negative numbers, and cancel the transaction.
Does not allow withdrawing negative numbers.
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CDAccount.h"

using namespace std;

int accountCounter = 1;

//For the most part, I assume valid input (numbers when asks for numbers and strings when it asks for strings), although I will put in some different checks.

int menu() //This is the menu the user will see when the start the program or finish an action.
{
	do
	{
		cout << "Welcome to Redneck Bank! Yeeeehaw! What would you like to do today, pardner?\n(O) Open an account\n(D) Deposit some of that money\n(W) Withdraw from savings: Take back what's yours!\n(CH) Write a check from your checking account\n(CL) Close an account\n(A) Advance the month: Time ain't stoppin'!\n(T) Terminate (fancy talk meanin' close) the program\n(TE) Test\n(AN) Advance a specified number of months\n";
		string choice = "";
		cin >> choice;
		if (choice == "O") // Open an account.
		{
			return 1;
		}
		else if (choice == "D") //Deposit
		{
			return 2;
		}
		else if (choice == "W") //Withdraw
		{
			return 3;
		}
		else if (choice == "CH") //Write a check
		{
			return 4;
		}
		else if (choice == "CL")//Close account
		{
			return 5;
		}
		else if (choice == "A")//Advance month
		{
			return 6;
		}
		else if (choice == "T")//Close program
		{
			return 7;
		}
		else if (choice == "P")//Print
		{
			return 8;
		}
		else if (choice == "TE")//Test
		{
			return 9;
		}
		else if (choice == "AN")//Advance specified months
		{
			return 10;
		}
		else
		{
			cout << "That is not one of the options, bud! Remember, case matters!\n\n";
		}
	}
	while (true); //repeats until valid input is achieved.
}

int accountType()
{
	do
	{
		cout << "Account type ((C) Checking, (S) Savings, CD):\n";
		string type = "";
		cin >> type;
		if (type == "Checking" || type == "C")
		{
			return 1;
		}
		else if (type == "Savings" || type == "S")
		{
			return 2;
		}
		else if (type == "CD")
		{
			return 3;
		}
		else
		{
			cout << "Come on now, pardner, that's about as silly of an answer as a goat in pajamas!\n\n";
		}
	}
	while (true);
}

int accountFinder(vector<BankAccount*> vector, int userAccount)
{
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		if (vector[i]->getNumber() == userAccount)
		{
			return i;
		}
	}
	cout << "That account doesn't exist!\n\n";
	return -1;
}

//Ignore this, although I wanted to leave it in.
void test(vector<BankAccount*> vector) //Creates a series of bank accounts for testing.
{
	BankAccount* test = new CheckingAccount(accountCounter, 50, "Phil");
	accountCounter++;
	vector.push_back(test);

	test = new SavingsAccount(accountCounter, 75, "Bob");
	accountCounter++;
	vector.push_back(test);

	test = new CheckingAccount(accountCounter, 50, "John");
	accountCounter++;
	vector.push_back(test);

	test = new CDAccount(accountCounter, 0, "Sally");
	accountCounter++;
	vector.push_back(test);

	test = new SavingsAccount(accountCounter, 1000, "Susan");
	accountCounter++;
	vector.push_back(test);
} //This didn't work out...

int main()
{
	vector<BankAccount*> accounts;
	do
	{
		int index = 0;
		int userAccount = 0;
		int choice = menu();
		if (choice == 1) //Open
		{
			int type = accountType();//determines account type
			cout << "What name did your mom and pop give you?\n"; //Gathering account info. It makes more sense to me to do this in main with a constructor as opposed to a member function.
			string name = "";
			cin >> name; //I assume they user will only enter either a first name.
			bool validCheck = false;
			string initialDeposit;
			do //checks if valid choice y or n
			{

				cout << "Would you like to start with an initial deposit? (y/n)\n";
				initialDeposit = "";
				cin >> initialDeposit;
				if (initialDeposit == "y" || initialDeposit == "n")
				{
					validCheck = true;
				}
				else
				{
					cout << "That isn't one of the choices. Come on now.\n\n";
				}
			}
			while (validCheck == false);
			double initialDepositAmount = 0;
			if (initialDeposit == "y")
			{

				bool posCheck = false;
				do//Ensures only positive desposits.
				{

					cout << "How much you wanna deposit?\n";
					cin >> initialDepositAmount;

					if (initialDepositAmount < 0)
					{
						cout << "You may only deposit postive money...\n";
					}
					else
					{
						posCheck = true;
					}
				}
				while (!posCheck);
			}

			if (type == 1) //Checking
			{
				BankAccount* temp = new CheckingAccount(accountCounter, initialDepositAmount, name);
				cout << temp->tostr();
				accountCounter++;
				accounts.push_back(temp);
			}
			else if (type == 2)//Savings
			{
				BankAccount* temp = new SavingsAccount(accountCounter, initialDepositAmount, name);
				cout << temp->tostr();
				accountCounter++;
				accounts.push_back(temp);
				//Savings.open()
			}
			else if (type == 3)//CD
			{
				BankAccount* temp = new CDAccount(accountCounter, initialDepositAmount, name);
				cout << temp->tostr();
				accountCounter++;
				accounts.push_back(temp);
				//CD.open()
			}
		}
		else if (choice == 2) //Deposit
		{
			cout << "What be your account number?\n";
			cin >> userAccount;
			index = accountFinder(accounts, userAccount);
			if (index >= 0)
			{
				double depositAmount = 0;
				bool posCheck = false;
				do
				{

					cout << "How much you wanna deposit?\n";
					cin >> depositAmount;

					if (depositAmount < 0)
					{
						cout << "You may only deposit postive money...\n";
					}
					else
					{
						posCheck = true;
					}
				}
				while (!posCheck);
				accounts[index]->deposit(depositAmount);
			}
		}
		else if (choice == 3)//Withdraw from savings
		{
			cout << "What be your account number?\n";
			cin >> userAccount;
			index = accountFinder(accounts, userAccount);
			if (index >= 0 && accounts[index]->getType() == "Savings")
			{
				double withdrawAmount = 0;

				bool posCheck = false;
				do
				{

					cout << "How much you wanna withdraw?\n";
					cin >> withdrawAmount;

					if (withdrawAmount < 0)
					{
						cout << "You may only withdraw postive money...\n";
					}
					else
					{
						posCheck = true;
					}
				}
				while (!posCheck);
				accounts[index]->withdraw(withdrawAmount);
			}
			else if (index >= 0 && accounts[index]->getType() == "CD") //Maybe it's redundant, but I like the thought seperation.
			{
				double withdrawAmount = 0;
				bool posCheck = false;
				do
				{
					cout << "How much you wanna withdraw?\n";
					cin >> withdrawAmount;

					if (withdrawAmount < 0)
					{
						cout << "You may only withdraw postive money...\n";
					}
					else
					{
						posCheck = true;
					}
				}
				while (!posCheck);
				accounts[index]->withdraw(withdrawAmount);
			}
			else if (index < 0)
			{
				cout << "No such account exists!\n"; //This gets printed twice to really drive the point home.
			}
			else
			{
				cout << "Invalid account type. You may only withdraw from a savings account.\n";
			}

		}
		else if (choice == 4)//Write a check against checking. I am also assuming that this cannnot go negative except through penalties.
		{
			cout << "What be your account number?\n";
			cin >> userAccount;
			index = accountFinder(accounts, userAccount);
			if (index >= 0 && accounts[index]->getType() == "Checking")
			{
				double withdrawAmount = 0;

				bool posCheck = false;
				do
				{
					cout << "What is your check amount?\n";
					cin >> withdrawAmount;

					if (withdrawAmount < 0)
					{
						cout << "You may only write a check for postive money...\n";
					}
					else
					{
						posCheck = true;
					}
				}
				while (!posCheck);
				accounts[index]->withdraw(withdrawAmount);
			}
			else if (index < 0)
			{
				cout << "No such account exists!\n";
			}
			else
			{
				cout << "Invalid account type. You may only write a check from a checking account.\n";
			}
		}
		else if (choice == 5)//Close account. I assume the user will put at least one account in before they try and delete one.
		{
			cout << "What be your account number?\n";
			cin >> userAccount;
			index = accountFinder(accounts, userAccount);
			if (index < 0)
			{
				cout << "\n\nNo such account exists!\n\n";
			}
			else if (accounts[index]->getBalance() >= 0)
			{
				accounts.erase(accounts.begin() + index);
				cout << "Account deleted\n\n";
			}
			else 
			{
				cout << "\n\nYou may not close an account with a negative balance! WE WANT OUR MONEY.\n\n";
			}
		}
		else if (choice == 6)//Advance month
			//I don't undestand the interest sample provided, so I'm just assuming that interested is compounded monthly instead of yearly,
			//otherwise the advance month option would only actually update something every 12 months.
		{
			for (unsigned int i = 0; i < accounts.size(); i++)
			{
				accounts[i]->advanceMonth();
				cout << accounts[i]->tostr();
			}
		}
		else if (choice == 7)//Terminate program
		{
			return 0;
		}
		else if (choice == 8) //A hidden test that prints out all the accounts and their current data.
		{
			for (unsigned int i = 0; i < accounts.size(); i++)
			{
				cout << accounts[i]->tostr() << endl;
			}
		}
		else if (choice == 9) // Fill the vector with some stuff.
		{
			//Test function-----------------------------------------------------------------------------------------------------------------------------------------
			//It's crude, but it works. I have the test() function above, but it was skipping it, so this will suffice. I ASSUME THAT'S OKAY.
			//This test just creates accounts to work with so a tester does not have to keep entering them.
			BankAccount* test = new CheckingAccount(accountCounter, 50, "Phil");
			accountCounter++;
			accounts.push_back(test);

			test = new SavingsAccount(accountCounter, 75, "Bob");
			accountCounter++;
			accounts.push_back(test);

			test = new CheckingAccount(accountCounter, 50, "John");
			accountCounter++;
			accounts.push_back(test);

			test = new CDAccount(accountCounter, 100, "Sally");
			accountCounter++;
			accounts.push_back(test);

			test = new SavingsAccount(accountCounter, 1000, "Susan");
			accountCounter++;
			accounts.push_back(test);
			//Test function--------------------------------------------------------------------------------------------------------------------------------------

		}
		else if (choice == 10) //This is to advance a certain number of months, mainly for testing purposes to make it easier for you! I lost motivation on the Redneck thing, sorry.
		{
			cout << "Through how many months would you like to progress?\n";
			int monthNumber = 1;
			cin >> monthNumber;
			for (int j = 0; j < monthNumber; j++)
			{
				for (unsigned int i = 0; i < accounts.size(); i++)
				{
					accounts[i]->advanceMonth();
				}
			}
			for (unsigned int i = 0; i < accounts.size(); i++)
			{
				cout << accounts[i]->tostr();
			}
		}
	}
	while (true);
	system("pause");
	return 0;
}