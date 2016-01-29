/*
Matthew kirk
Section: 4
11/14/2012
Lab #9 Armies of Helaman
Description: This program reads in stats for Nephites and Lamanites from a file.
				They proceed to fight and one claims victory.
Design:
	User inputs stat containing text files for the nephites and lamanites.
	Prints out the current armies.
	Goes through the battle where a random warrior for each army is chosen and they fight...to the death!
Test case is my test function.
*/
#include "Warrior.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

int test()
{
	Warrior nephite(100,5,2,2);
	Warrior lamanite(100,8,1,0);
	while (nephite.get_hp() > 0 && lamanite.get_hp() > 0)
	{
		cout << "Fight!\n";
		nephite.take_damage(lamanite.get_damage());
		if (nephite.get_hp() > 0)
		{
			lamanite.take_damage(nephite.get_damage());
			nephite.regenerate();
		}
		else
		{
			cout << "The Lamanite has won a battle for the motherland!\n\n";
			system("pause");
			return 0;
		}
		if (lamanite.get_hp() > 0)
		{
			lamanite.regenerate();
		}
		else
		{
			cout << "This victory goes to the Nephites!\n\n";
			system("pause");
			return 0;
		}
		cout << "Current Nephite stats:\n";
		nephite.tostr();
		cout << "\nCurrent Lamanite stats:\n";
		lamanite.tostr();
		cout << "\n\n";
	}
}

int rW (vector<Warrior> vector)
{
	int r = rand()%vector.size();
	return r;
}

void printvec (vector<Warrior> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		Warrior temp = vector[i];
		cout << "Warrior " << i+1 << endl;
		temp.tostr();
		cout << endl;
	}
}

int main()
{
	test();
	srand(time(NULL));
	int hp = 0;
	int damage = 0;
	int regen = 0;
	int defense = 0;
	vector<Warrior> nephites;
	vector<Warrior> lamanites;
	string location = "";
	cout << "Please provide Nephite stat file.\n";
	ifstream nephite_data;
	ifstream lamanite_data;
	cin >> location;
	nephite_data.open(location);
	if (nephite_data.is_open()) // Read in Nephite data.
	{
		while (nephite_data >> hp >> damage >> regen >> defense)
		{
			nephites.push_back(Warrior(hp, damage, regen, defense));
		}
		cout << "Nephite Army:\n\n";
		printvec(nephites);
		cout << "\n\n";
	}
	else
	{
		cout << "Unable to open file!\n\n";
		return 0;
	}

	cout << "Please provide Lamanite stat file.\n"; // Read in Lamanite data.
	cin >> location;
	lamanite_data.open(location);
	if (lamanite_data.is_open())
	{
		while (lamanite_data >> hp >> damage >> regen >> defense)
		{
			lamanites.push_back(Warrior(hp, damage, regen, defense));
		}
		cout << "Lamanite Army:\n\n";
		printvec(lamanites);
		cout << "\n\n";

	}
	else 
	{
		cout << "Unable to open file!\n\n";
		return 0;
	}

	// Battle
	while (nephites.size() > 0 && lamanites.size() > 0)
	{
		int rN = rW(nephites);
		int rL = rW(lamanites);

		nephites[rN].take_damage(lamanites[rL].get_damage());
		if (nephites[rN].get_hp() > 0)
		{
			lamanites[rL].take_damage(nephites[rN].get_damage());
			nephites[rN].regenerate();
		}
		else
		{
			nephites.erase(nephites.begin() + rN);
		}
		if (lamanites[rL].get_hp() > 0)
		{
			lamanites[rL].regenerate();
		}
		else 
		{
			lamanites.erase(lamanites.begin() + rL);
		}

	}

	// Winner

	if (nephites.size() > 0)
	{
		cout << "Nephites win!\n\n";
	}
	else
	{
		cout << "Lamanites win!\n\n";
	}

	system("pause");
	return 0;
}