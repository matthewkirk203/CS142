/*
Matthew Kirk
Section 4
12 September 2012
Lab # 3
Description: This program calculates and compares the costs of owning a hybrid and a traditional car based on gas consumption and total cost.
Design:
Test Cases: 
	#1 Negative miles per year -- It should say only positive numbers are allowed and close.
	#2 Enter a value other than "gas" or "total" -- It should require only the inputs "gas" or "total" and close if it gets any other input.
	#3 Entering 15000, 2.50, 45000, 40, 30000, 30000, 25, 15000, gas,
		I should get for hybrid: 375 gallons per year and a total cost of $15937.5. For traditional: 600 gallons per year and a total cost of $16500.

*/
#include <iostream>
#include <string>

using namespace std;

int main ()
{

// Part 1:
// Asking user to declare variables for hybrid.

	cout << "How many miles, approximately, do you drive a year?" << endl;
		int miles_year;
			cin >> miles_year;
	if (miles_year < 0)
	{
		cout << "Stop playing around, only positive numbers are allowed. Please try again." << endl;
		system("pause");
		return 1;	
	}
	cout << "Enter estimated cost of gas per gallon:" << endl;
		double cost_gallon_gas;
		cout << "$";
			cin >> cost_gallon_gas;
	if (cost_gallon_gas < 0)
	{
		cout << "Stop playing around, only positive numbers are allowed. Please try again." << endl;
		system("pause");
		return 1;	
	}
	cout << "Enter cost of Hybrid Car:" << endl;
		double hybrid_cost;
		cout << "$";
			cin >> hybrid_cost;
	if (hybrid_cost < 0)
	{
		cout << "Stop playing around, only positive numbers are allowed. Please try again." << endl;
		system("pause");
		return 1;	
	}
	cout << "Enter Hybrid mpg:" << endl;
		int hybrid_mpg;
			cin >> hybrid_mpg;
	if (hybrid_mpg < 0)
	{
		cout << "Stop playing around, only positive numbers are allowed. Please try again." << endl;
		system("pause");
		return 1;	
	}
	cout << "Enter estimated resale value of Hybrid after 5 years:" << endl;
		double hybrid_resale;
		cout << "$";
			cin >> hybrid_resale;
	if (hybrid_resale < 0)
	{
		cout << "Stop playing around, only positive numbers are allowed. Please try again." << endl;
		system("pause");
		return 1;	
	}
	cout << endl;


// Asking user to declare variables for traditional.

	cout << "Enter cost of traditional car:" << endl;
		double trad_cost;
		cout << "$";
			cin >> trad_cost;
	if (trad_cost < 0)
	{
		cout << "Stop playing around, only positive numbers are allowed. Please try again." << endl;
		system("pause");
		return 1;	
	}

	cout << "Enter mpg of traditional car:" << endl;
		int trad_mpg;
			cin >> trad_mpg;
	if (trad_mpg < 0)
	{
		cout << "Stop playing around, only positive numbers are allowed. Please try again." << endl;
		system("pause");
		return 1;	
	}

	cout << "Enter estimated resale value of traditional car after 5 years:" << endl;
		double trad_resale;
		cout << "$";
			cin >> trad_resale;
	if (trad_resale < 0)
	{
		cout << "Stop playing around, only positive numbers are allowed. Please try again." << endl;
		system("pause");
		return 1;	
	}


// Buying Criteria
	cout << "Please enter your buying criteria (either \"gas\" or \"total\") :" << endl;
	string buying_criteria;
	cin >> buying_criteria;
	if (buying_criteria == "gas" || buying_criteria == "total")
	{
		//Continue with program.
	}
	else 
	{
		cout << "Please enter either \"gas\" or \"total\"." << endl;
		system("pause");
		return 1;
	}
	cout << endl;

// Part 2:
// For Hybrid:

// Calculate gallons of gas consumed per year.
	double hybrid_gas_consumption_year = miles_year / hybrid_mpg;
// Total cost of gas.
	double hybrid_gas_cost_year = hybrid_gas_consumption_year * cost_gallon_gas;
	double hybrid_total_cost = hybrid_gas_cost_year + (hybrid_cost - hybrid_resale); // Car depreciation + fuel cost

// For Traditional:

// Calculate gallons of gas consumed per year.
	double trad_gas_consumption_year = miles_year / trad_mpg;
// Total cost of gas.
	double trad_gas_cost_year = trad_gas_consumption_year * cost_gallon_gas;
	double trad_total_cost = trad_gas_cost_year + (trad_cost - trad_resale); // Car depreciation + fuel cost
	
//Final output.
	if (buying_criteria == "gas")
	{
		if (hybrid_gas_consumption_year < trad_gas_consumption_year)
		{
			cout << "For Hybrid: " << endl;
			cout << "You will use " << hybrid_gas_consumption_year << " gallons of gas per year." << endl;
			cout << "It will cost a total of $" << hybrid_total_cost << "." << endl;
			cout << endl;
			cout << "For Traditional: " << endl;
			cout << "You will use " << trad_gas_consumption_year << " gallons of gas per year." << endl;
			cout << "It will cost a total of $" << trad_total_cost << "." << endl;
		}
		else
		{
			cout << "For Traditional: " << endl;
			cout << "You will use " << trad_gas_consumption_year << " gallons of gas per year." << endl;
			cout << "It will cost a total of $" << trad_total_cost << "." << endl;
			cout << endl;
			cout << "For Hybrid: " << endl;
			cout << "You will use " << hybrid_gas_consumption_year << " gallons of gas per year." << endl;
			cout << "It will cost a total of $" << hybrid_total_cost << "." << endl;
		}
	}
	else
	{
		if (hybrid_total_cost < trad_total_cost)
		{
			cout << "For Hybrid: " << endl;
			cout << "It will cost a total of $" << hybrid_total_cost << "." << endl;
			cout << "You will use " << hybrid_gas_consumption_year << " gallons of gas per year." << endl;
			cout << endl;
			cout << "For Traditional: " << endl;
			cout << "It will cost a total of $" << trad_total_cost << "." << endl;
			cout << "You will use " << trad_gas_consumption_year << " gallons of gas per year." << endl;
		}
		else
		{
			cout << "For Traditional: " << endl;
			cout << "It will cost a total of $" << trad_total_cost << "." << endl;
			cout << "You will use " << trad_gas_consumption_year << " gallons of gas per year." << endl;
			cout << endl;
			cout << "For Hybrid: " << endl;
			cout << "It will cost a total of $" << hybrid_total_cost << "." << endl;
			cout << "You will use " << hybrid_gas_consumption_year << " gallons of gas per year." << endl;
		}
	}

	system("pause");
}

