/*
Matthew Kirk
Section 4
Date: 10/2/2012
Midterm #1: Hydrology
Description: This program estimates the time it will take to fill a resevoir based on 10 simulations.
Design: Asks user for inputs. Estimates time to fill resevoir. Does that 10 times. Displays shortest time, longest time, and average time
based on all 10 simulations.
Test Cases:
1) If min_in = 5 and max_in = 25 and req_out = 20, it should say that req_out can't be that high and return to menu.
2) Each run should print the accurate smallest and largest number from the set of those 10 simulations.
3) The average reported should be equal to the average when done by hand of the 10 simulations reported.
4) At the end of the program, entering 'y' should go to the menu, entering 'n' should close the program, 
and entering anything else should bring forth an error berating the user of lack of attention.
*/

#include <iostream>
#include <time.h>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));
	string choice;
	do 
	{	
		cout << "This program will determine how long it will take to fill a reservoir of a certain capacity.\nName of reservoir:\n";

		string resevoir;

		getline (cin, resevoir);

		//Asking user for variables.

		cout << "Maximum capacity of resevoir in MAF (Million Acre Feet):" << endl;
		double max_capacity;
		cin >> max_capacity;
		cout << "Minimum inflow of resevoir:" << endl;
		double min_in;
		cin >> min_in;
		cout << "Maximum inflow of resevoir:" << endl;
		double max_in;
		cin >> max_in;
		double req_out;

		cout << "Required outflow of resevoir:" << endl;
		cin >> req_out;
		double check = .9*((min_in + max_in)/2.0); //Checks to see if req_out is greater than 90% of average inflow.

		if(req_out >= check)
		{
			cout << "The required outflow cannot be greater than 90% of the average inflow." << endl; //go to menu without using a goto
		}
		else
		{
			int largest = -999; //To aid in tracking.
			int smallest = 999;
			int current_total_years = 0;
			for (int simulation = 1; simulation <= 10; simulation++)
			{	
				double current_capacity = 0;
				int year = 0;
				double inflow = 0;
				while(current_capacity < max_capacity)
				{
					double r = rand() * 1.0 /RAND_MAX;
					inflow = r * (max_in - min_in) + min_in;
					if (inflow < min_in || inflow > max_in) // Test to make sure inflow does not go negative.
					{
						cout << "Inflow was negative" << endl;
						system("pause");
					}
					current_capacity = current_capacity + inflow - req_out; //Filling resevoir.
					if (current_capacity < 0) // To ensure that current capacity does not go negative.
					{
						current_capacity = 0;
					}
					year++;
				}
				cout << "Simulation " << simulation << ": " << "Filled after " << year << " years." << endl;
				current_total_years = current_total_years + year;
				if (year > largest) // Tracks largest number
				{
					largest = year;
				}
				if (year < smallest) // Tracks smallest number
				{
					smallest = year;
				}
			}
			double average = current_total_years/10.0; // 10.0 is the number of simulations. It is constant, so using a number is fine. 10.0 ensures floating point math.
			cout << "\nAfter 10 simulations of filling " << resevoir << ":\n\n";
			cout << "\tShortest time: " << smallest << "years." << endl << "\tLongest time: " << largest << "years." << endl << "\tAverage time: " << average << "years." << endl << endl;

		}
		cout << "Would you to try another resevoir? (y/n):" << endl;
		bool valid2 = false;
		while (valid2 == false)
		{
			cin >> choice;
			if (choice == "y")
			{
				valid2 = true;
			}
			else if (choice == "n")
			{
				return 0;
			}
			else if (choice != "y" || choice != "n")
			{
				cout << "Please enter either 'y' or 'n'." << endl;
			}
		}
		cin.ignore();

	}
	while ( choice == "y");

	system("pause");
}