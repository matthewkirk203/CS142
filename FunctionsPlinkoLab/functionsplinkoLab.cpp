/*
Matthew Kirk
Section 4
10/9/12
Lab #5: Plinko with functions.
Description: This program plays the game plinko, but this time with some functions!
Design: The user is brought to the menu where they choose one of four options.
		Depending on their option they choose slot number, chips to drop, etc.
		The program then drops chips through the pins by randomly adding or subtracting .5 to the position.
		The winnings are outputted and depending on the choice, the total and average are also outputted.
Test Cases:
1) The menu function should only ever return a value 1-4. If any other value is chosen it should loop back to the choices again. 
	1 should be 1 chip, 
	2 should be many chips one slot, 
	3 should be many chips all slots, 
and 4 should be quit.
2)chip_drop should accuratly drop a chip from the chosen slot and report its position as it falls.
3)winnings should take the value for position given and determine how much prize money should be printed.
4)many_chips should go through dropping the specified number of chips in a single slot. It returns the total prize.
*/

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int menu (int choice)
{
	do
	{
		cout << "Please choose an option by entering its number:\n1. One chip, one slot\n2. Many chips, one slot\n3. Many chips, all slots\n4. Quit program." << endl;
		cin >> choice;
		if (choice==1)
		{
			return 1; //run choice one function
		}
		else if (choice == 2)
		{
			return 2; //run choice 2 function
		}
		else if (choice == 3)
		{
			return 3; // Run choice 3
		}
		else if (choice == 4)
		{
			return 4; //quit
		}
		else
		{
			cout << "That option is invalid. Please enter a number 1-4 to choose." << endl << endl;
		}
	}
	while (1);
}

double chip_drop (int slot)
{
	double position;
	int count = 0;
	for (position=slot; count <= 11; count++)
	{
		int chance = 0;
		chance = rand() % 2;
		if (chance == 0)
		{
			if (position == 0)
			{
				position = position + 0.5;
			}
			else
			{
				position = position - 0.5; 
			}
		}
		else if (position == 8)
		{
			position = position - 0.5;
		}
		else
		{
			position = position + 0.5;
		}
		cout << position << endl;
	}
	return position;
}

double many_chips (int slot2, int num_chips)
{
	if (slot2 >= 0 && slot2 <= 8)
	{ // Continue
		double position;
		int new_prize = 0;
		int total_prize = 0;
		while (num_chips > 0)
		{
			int count = 0;
			for (position=slot2; count <= 11; count++)
			{
				int chance = 0;
				chance = rand() % 2;
				if (chance == 0)
				{
					if (position == 0)
					{
						position = position + 0.5;
					}
					else
					{
						position = position - 0.5; 
					}
				}
				else if (position == 8)
				{
					position = position - 0.5;
				}
				else
				{
					position = position + 0.5;
				}
			}
			if (position == 0 || position == 8)
			{
				//cout << "Prize Money: $100" << endl;
				new_prize = 100;
			}
			else if (position == 1 || position == 7)
			{
				//cout << "Prize Money: $500" << endl;
				new_prize = 500;
			}
			else if (position == 2 || position == 6)
			{
				//cout << "Prize Money: $1000" << endl;
				new_prize = 1000;
			}
			else if (position == 3 || position == 5)
			{
				//cout << "Prize Money: $0" << endl;
				new_prize = 0;
			}
			else 
			{
				//cout << "Prize Money: $10000" << endl;
				new_prize = 10000;
			}
			num_chips--;
			total_prize = total_prize + new_prize;
		}
		return total_prize;
	}
}

double winnings (int position)
{
	if (position == 0 || position == 8)
	{
		//cout << "Prize Money: $100" << endl;
		return 100;
	}
	else if (position == 1 || position == 7)
	{
		//cout << "Prize Money: $500" << endl;
		return 500;
	}
	else if (position == 2 || position == 6)
	{
		//cout << "Prize Money: $1000" << endl;
		return 1000;
	}
	else if (position == 3 || position == 5)
	{
		//cout << "Prize Money: $0" << endl;
		return 0;
	}
	else 
	{
		//cout << "Prize Money: $10000" << endl;
		return 10000;
	}
}

int main ()
{
	int choice = 0;
	srand ( time(NULL));
	do
	{	
		choice = menu(0); //Goes to menu.
		if (choice==1)
		{
			//cout << "One Chip" << endl;
			cout << "Choice one.\nPlease select a slot (0-8):" << endl;
			int slot;
			cin >> slot;
			cout << endl;
			if (slot >= 0 && slot <= 8)
			{
				double position = chip_drop (slot);
				double prize = winnings (position);
				cout << "Prize Money: $" << prize << endl << endl;
			}
			else
			{
				cout << "ERROR! Please only enter a slot between 0-8.\n\n";
			}
		}
		else if (choice == 2)
		{
			//cout << "Multiple" << endl;
			double total_prize = 0;
			int slot2 = 0;
			int num_chips;
			cout << "Choice two.\nPlease select number of chips to drop:" << endl;
			cin >> num_chips;
			if (num_chips <=0)
			{
				//Go to menu
				cout << "Please only enter a postive number of chips.\n\n";
			}
			else
			{
				cout << "Select a slot between 0-8:" << endl;
				cin >> slot2;
				cout << endl;
				if (slot2 >= 0 && slot2 <= 8)
				{
					total_prize = many_chips(slot2, num_chips);
					double avg_prize;
					avg_prize = total_prize/num_chips;
					cout << "Total prize money: $" << total_prize << endl;
					cout << "Average prize money per chip: $" << avg_prize << endl << endl;
				}
				else
				{
					cout << "ERROR! Please only enter a slot between 0-8.\n\n";
				}
			}
		}
		else if (choice == 3)
		{
			cout << "Choice 3: This will drop a specified number of chips into each slot.\nPlease choose the number of chips you would like to drop in all slots: \n";
			int num_chips = 0;
			cin >> num_chips;
			cout << endl;
			double total_prize = 0;
			double avg_prize = 0;
			cout << "Slot:\tTotal:\tAverage:" << endl;
			for (int i = 0; i < 9; i++)
			{
				total_prize = many_chips (i, num_chips);
				avg_prize = total_prize/num_chips;
				cout << i << "\t" << total_prize << "\t" << avg_prize << endl;
			}
			cout << endl;
		}
		else if (choice == 4)
		{
			return 0;
		}
		else
		{
			cout << "invalid" << endl;
			return 0;
		}
	}
	while (1);

}
