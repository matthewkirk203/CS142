/*
Matthew Kirk
Section 4
10/22/2012
Lab 7 Restaurants
Description: This program runs through a tournament where the user can choose their favorite.
Design: Allows the user to add and remove restaurants and then runs a tournament.
Test Cases:
1) If user tries to add restaurant to a full array it will display an error.
2) If user tries to remove restaurant to an empty array it will display an error.
3) If a menu choice is chosen other than 1-5, and error is shown.
4) There should never be duplicates when shuffling positions.
5) Removing any restaurant should cause all restaurants after it to shift down 1.
6) In the tournament, if the user tries to choose a restaurant that isn't listed, it shows an error and lets them retry.
*/

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int menu (int choice)
{
	do
	{
		cout << "Please choose an option by entering its number:\n1. Display all restaurants\n2. Add a restaurant\n3. Remove a restaurant\n4. Shuffle order\n5. Begin the tournament" << endl;
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
			return 4; // Run choice 4
		}
		else if (choice == 5)
		{
			return 5;
		}
		else
		{
			cout << "That option is invalid. Please enter a number 1-5 to choose." << endl << endl;
		}
	}
	while (1);
}

void printarr (string arr[], int size)
{
	for (int i = 0; i < size; i++)
	{

		if (i == size-1)
		{
			cout << arr[i];
		}
		else
		{
			cout << arr[i] << ", ";
		}

	}
	cout << endl;
}

bool find (string arr[], int size, string name)
{
	for (int i = 0; i < size; i++)
	{
		if (name == arr[i])
		{
			return true;
		}
	}
	return false;
}

int index (string arr[], int size, string name)
{
	for (int i = 0; i < size; i++)
	{
		if (name == arr[i])
		{
			return i;
		}
	}
}

int main()
{
	int const CAPACITY = 16;
	int size = CAPACITY;
	string rest[CAPACITY] = {"Zupas", "Applebees", "Chipotle", "Olive Garden", "Pizza Hut", "Subway", "Taco Bell", "Panda Express", "In-N-Out", "The Yellow Deli", "Outback", "Legends Grille", "Skyroom", "Arby's", "The Blue Line", "Denny's"};
	do 
	{
		int choice = menu(0);
		if (choice == 1) //Display all restaurants
		{
			printarr(rest, size);
		}
		else if (choice == 2) //Add a restaurant
		{
			if (size < CAPACITY)
			{
				cout << "What restaurant would you like to add?\n\n";
				string new_rest;
				cin.sync();
				getline (cin, new_rest);
				bool found = find(rest, size, new_rest);
				if (found)
				{
					cout << "That restaurant already exists. Try adding a different one.\n\n";
				}
				else
				{
					rest[size] = new_rest;
					size++;
				}
			}
			else 
			{
				cout << "The list is full. Please remove a restaurant before adding another.\n\n";
			}

		}
		else if (choice == 3) //Remove a restaurant
		{
			if (size > 0)
			{
				cout << "Select restaurant to remove (case sensitive)\n";
				string new_rest;
				cin.sync();
				getline (cin, new_rest);
				bool found = find(rest, size, new_rest);
				if (!found)
				{
					cout << "That restaurant does not exist in the list.\n\n";
				}
				else
				{
					int location = 0;
					for (int i = 0; i < size; i++)
					{
						if (new_rest == rest[i])
						{
							location = i;
						}
					}
					for (int i = location; i < size-1; i++)
					{
						rest[i] = rest[i+1];
					}
					size--;
					cout << "Removed: " << new_rest << endl << endl;
				}
			}
			else
			{
				cout << "There are no restaurants currently stored.\n\n";
			}
		}
		else if (choice == 4) //Shuffle restaurants
		{
			for (int i = 0; i < size; i++)
			{
				string temp = rest[i];
				int r = rand() % size;
				rest[i] = rest[r];
				rest[r] = temp;
			}
		}
		else if (choice == 5) //Begin tournament
		{

			if (size != CAPACITY)
			{
				cout << "You may only begin the tournament with 16 restaurants\n\n";

			}
			else
			{
				while (size > 1)
				{
					int location = 0;
					for (int i = 0; i < size; i = i + 2)
					{
						bool found = true;
						do
						{
							string fav;
							cout << "Choose your favorite of the two listed.\n" << rest[i] << " or " << rest[i+1] << endl << endl;
							cin.sync();
							getline (cin, fav);
							if (fav == rest[i] || fav == rest[i+1])
							{
								rest[location] = fav;
								location++;
								found = true;
							}
							else
							{
								cout << "Please choose one of the two listed.\n\n";
								found = false;
							}
						}
						while (!found);
						//location = index (rest, size, fav);
					}
					size = size/2;
				}
				cout << "The winner is: " << rest[0] << "!\n";
				system("pause");
				return 0;
			}

		}
	}
	while (1);

	system("pause");
}