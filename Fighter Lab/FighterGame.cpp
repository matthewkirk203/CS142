#pragma once
#include <conio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <Windows.h>

#include "Archer.h"
#include "ArenaInterface.h"
#include "Battle.h"
#include "Cleric.h"
#include "Factory.h"
#include "FighterGame.h"
#include "FighterInterface.h"
#include "Robot.h"

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::pair;

// Functions to enable quick redrawing
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y) // for the record this isn't the same as goto in code. 
//this refers to moving the cursor on the screen so that everything gets printed in the correct place
{ 
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

int main()
{
	srand(time(NULL));
	
	int option;

	do
	{
		cout << "================================================================================";
		cout << "======                                                                    ======";
		cout << "==                                Fighter Game                                ==";
		cout << "======                                                                    ======";
		cout << "================================================================================";
		cout << "\n";
		cout << "\n";
	
		cout << "      =============\n";
		cout << "      =  OPTIONS  =\n";
		cout << "      =============\n";
		cout << "      \n";
		cout << "      1. How to Play\n";
		cout << "      2. Test and Debug\n";
		cout << "      3. Start Battle!\n";
		cout << "      4. Credits\n";
		cout << "      5. Exit\n";

		do
		{
			if (cin.fail())
			{
				cin.clear();
				cin.get();
			}
			cin >> option;
		} while (cin.fail() || option > 6 || option < 1);

		if (option == 1)
		{ // "How to Play"
			system("cls");
			cout << "Take control of your team of fighters and defeat your opponents!\n\n"
				<< "Fighters have 5 stats: Type, Hitpoints, Strength, Speed, and Magic.  A typical\n"
				<< "fighter's summary might look something like this:\n\n\t0. Bob\n\tC 24 8 20 14\n\n"
				<< "This means that Bob, fighter #0, is a Cleric with 24 hitpoints, 8 strength, 20\n"
				<< "speed, and 14 magic.\n\n"
				<< "Each team consists of Archers, Clerics or Robots:\n"
				<< "- Archers are skilled fighters who depend on speed to do damage.  Their special\n"
				<< "ability boosts their speed and, thus, their damage.\n"
				<< "- Clerics are holy fighters who depend on magic to do damage.  Their special\n"
				<< "ability heals them a small amount.\n"
				<< "- Robots are mighty fighters who depend on brute strength to deal damage.  Their"
				<< "special ability gives them a temporary attack boost.\n\n"
				<< "Controls: Up, Down, Left, or Right to move\n"
				<< "          Enter to end your turn early\n"
				<< "          Escape to forfeit the game at any time\n\n";
			system("pause");
			system("cls");
		 //cout << "                                                                                ";
			cout << "The fighters from team A and team B take turns moving across the battlefield and"
				<< "attacking one another.  Strategy is key in this game; be sure to pay close\n"
				<< "attention so you know who to fight and who to avoid!\n\n"
				<< "On your turn, you can move up to three spaces, depending on the terrain you walk"
				<< "over.  There are four different kinds of terrain:\n\n"
				<< "+----+\n"
				<< "|    | - Empty\n"
				<< "|    |   This terrain only takes one step to traverse.\n"
				<< "|    |\n"
				<< "+----+\n";
				cout << "|";
				SetConsoleTextAttribute(console, 2);
				cout << "YYYY";
				SetConsoleTextAttribute(console, 7);
				cout << "| - Forest (Green)\n";
				cout<< "|";
				SetConsoleTextAttribute(console, 2);
				cout << "YYYY";
				SetConsoleTextAttribute(console, 7);
				cout << "|   Dense forest is a little difficult to walk on.  It takes 2 steps to\n";
				cout << "|";
				SetConsoleTextAttribute(console, 2);
				cout << "YYYY";
				SetConsoleTextAttribute(console, 7);
				cout << "|   pass through.\n"
				<< "+----+\n"
				<< "|";
				SetConsoleTextAttribute(console, 6);
				cout << "^^^^";
				SetConsoleTextAttribute(console, 7);
				cout << "| - Mountains (Brown)\n"
				<< "|";
				SetConsoleTextAttribute(console, 6);
				cout << "^^^^";
				SetConsoleTextAttribute(console, 7);
				cout << "|   Barren mountains that are very difficult to cross.  It takes all 3 of\n"
				<< "|";
				SetConsoleTextAttribute(console, 6);
				cout << "^^^^";
				SetConsoleTextAttribute(console, 7);
				cout << "|   your steps to enter a mountain range.\n"
				<< "+----+\n"
				<< "|";
				SetConsoleTextAttribute(console, 9);
				cout << "~~~~";
				SetConsoleTextAttribute(console, 7);
				cout << "| - Water (Blue)\n"
				<< "|";
				SetConsoleTextAttribute(console, 9);
				cout << "~~~~";
				SetConsoleTextAttribute(console, 7);
				cout << "|   You can't walk on water, silly!\n"
				<< "|";
				SetConsoleTextAttribute(console, 9);
				cout << "~~~~";
				SetConsoleTextAttribute(console, 7);
				cout << "|\n"
				<< "+----+\n";
			system("pause");
			system("cls");
		}
		else if (option == 2)
			// "Test and Debug"
		{
			FighterGame game;
			game.startGame(true);
			system("cls");
			SetConsoleTextAttribute(console, 7);
		}
		else if (option == 3)
		{ // "Start Battle!"
			FighterGame game;
			game.startGame(false);
			system("cls");
			SetConsoleTextAttribute(console, 7);
		}
		else if (option == 4)
		{
			// Credits
			system("cls");
			cout << "Concept: Dr. Clement\n"
			<< "Lead Programmer: Stephen Rollins\n"
			<< "Fighter Creation: Nathan Watterson\n"
			<< "Pre-Made Team Designs: Stephen Rollins\n"
			<< "Graphical Interface: Stephen Rollins\n"
			<< "Combat System: Matthew Kirk\n"
			<< "Testing: Chris Belyeu, Samuel Giraud-Carrier, Amanda Kynaston, Alexander Lemmon, Krista Purser, Stephen Rollins, Nathan Watterson\n";
			system("pause");
			system("cls");
		}
		else if (option == 6)
		{
			bool done = false;
			while(!done)
			{
				ArenaInterface *arena = Factory::createArena();
			
				system("cls");
				cout << "--------------------------------\n";
				cout << "         Battle Arena           \n";
				cout << "--------------------------------\n";
				cout << "\n\n";
				cout << "How many fighters do you wish to enlist? ";
				int count;
				cin >> count;

				while (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX);

					cout << "Please enter an integer number. ";
				}

				if (count == 0)
					done = true;
				else
				{
					vector<FighterInterface*> fighters;
					for (int i = 0; i < count; i++)
					{
						cout << "\n";
						cout << "Stats for fighter #" << i << ":\n";
						cout << "Format: <name> <type> <hp> <str> <speed> <magic>\n";
						string attempt;
						getline(cin, attempt);

						while (!arena->addFighter(attempt))
						{
							cout << "Please use the correct format\n";
							getline(cin, attempt);
						}

						fighters.push_back(arena->getFighter(attempt.substr(0, attempt.find(' '))));
					}

					while (!done)
					{
						system("cls");
						cout << "TIME TO FIGHT!\n";
						cout << "Select two fighters by name:\n";
						for (size_t i = 0; i < fighters.size(); i++)
							cout << i << ". " << fighters.at(i)->getName() << "\n";

						cout << "\n\n";
						string choice1, choice2;
						cin >> choice1;
						cin >> choice2;

						FighterInterface *first = arena->getFighter(choice1);
						FighterInterface *second = arena->getFighter(choice2);

						if (first == NULL || second == NULL)
							cout << "I don't know who they are!";
						else
							fight(first, second, true);

						system("pause");

						cout << "Do you wish to continue? y/n ";
						cin >> choice1;

						done = (choice1 == "n");
					}

					cout << "Do you wish to enlist a new set of fighters? y/n ";
					string choice;
					cin >> choice;
			
					done = (choice == "n");
				}
			}
		}
	} while (option != 5); // Repeat until they quit

	return 0;
}

FighterGame::FighterGame()
{
	initialize();
}

void FighterGame::initialize()
{
	// Initialize arena object
	arena = Factory::createArena();
	message = "";

	TEAMSIZE = 5;
	turn = 0;
	steps = 3;

	for (int i = 0; i < TEAMSIZE; i++)
	{
		fightersA[i] = NULL;
		fightersB[i] = NULL;
		locations[i] = -1;
		locations[i + TEAMSIZE] = -1;
	}

	// Initialize grid variables
	WIDTH = 12;
	HEIGHT = 5;

	// The game grid is a one-dimensional array numbered by columns.	 e.g.  1  2  3  ... 8  9
	// Each index in the array represents a square in the grid.				   10 11 12 ... 17 18
	// The value of an index represents the type of object found			   19 20 21 ... 26 27
	// in that square.
	grid = new int[WIDTH * HEIGHT];
	tempgrid = new int[WIDTH * HEIGHT];

	// Initializes the grid, placing random mountains (-2) and trees (-2), leaving
	// every other square empty (-1)
	clearGrid();
}

void FighterGame::loop(bool testing)
{
	int turnA = 0;
	int turnB = TEAMSIZE;
	bool teamAsTurn = (bool) (rand() % 2);
	bool done = false;
	char input = 0;

	if (testing)
		for (int i = 0; i < 3; i++)
			if (fightersA[i] == NULL || fightersB[i] == NULL)
			{
				gotoXY(0, 22);
				cout << "ERROR: A fighter failed to load!\n";
				done = true;
			}

	while (!done)
	{
		// Clear the keyboard buffer
		while (_kbhit())
			_getch();
		
		// Display the current status message
		gotoXY(0, 23);
		printf("                                                                    ");
		gotoXY(0,23);
		cout << message;
		message = "";

		if (checkWin())
			done = true;
		else
		{
			// End turn if all steps are used
			if (steps == 0)
			{
				gotoXY(0, 24);
				cout << "Your turn is over...";
				
				if (teamAsTurn)
					turnA++;
				else
					turnB++;
				
				teamAsTurn = !teamAsTurn;
				steps = 3;

				_getch();
				gotoXY(62, turn * 2 + 1);
				cout << " ";
				continue;
			}

			// Clear the turn info and message
			gotoXY(0, 22);
			printf("                                                                    ");
			gotoXY(0,24);
			printf("                                                                    ");

			// Make sure it is a valid fighter's turn
			int prevturn = turn;
			if (teamAsTurn)
				{
					while (fightersA[turnA] == NULL)
						if (++turnA == TEAMSIZE)
							turnA = 0;
					turn = turnA;
					gotoXY(0,22);
					cout << "Team A's Turn: (" << turn << ") " << fightersA[turn]->getName();
				}
				else
				{
					while (fightersB[turnB - TEAMSIZE] == NULL)
						if (++turnB == TEAMSIZE * 2)
							turnB = TEAMSIZE;
					turn = turnB;
					gotoXY(0,22);
					cout << "Team B's Turn: (" << turn << ") " << fightersB[turn - TEAMSIZE]->getName();
				}
			if (prevturn != turn)
			{
				redraw(locations[prevturn]);
				redraw(locations[turn]);
			}

			gotoXY(62, turn * 2 + 1);
			cout << ">";

			int location = locations[turn];
			gotoXY((location % WIDTH) * 5 + 1, (location / WIDTH) * 4 + 2);

			// Determine input
			while ((input = _getch()) != -32 && input != 27 && input != 13);
			if (input == 13)
				steps = 0;
			else if (input != 27)
				move(input, testing);
			else
				done = true;
		}
	}
	gotoXY(0, 23);
	if (message == "")
	{
		message += "Team ";
		message += (turn < TEAMSIZE ? "A" : "B");
		message += " has forfeit!";
	}
	cout << message;
	//_getch();
	while (!_kbhit())
	{
		int color = rand() % 16;
		color |= 8;
		if ((rand() % 4))
			color = 0;
		int x = rand() % (WIDTH * 5 + 1);
		int y = rand() % (HEIGHT * 4 + 1);

		gotoXY(x, y);
		SetConsoleTextAttribute(console, color);
		cout << "*";
	}
	_getch();
}

void FighterGame::startGame(bool testing)
{
	int choice = 0;	//user's choice 1 or 2
	if (testing)
		choice = 1;

	//Print menu
		cout << "Choose your team from\n";
		cout << "1. Default Team\n";
		cout << "2. Custom Team\n";

	while(choice != 1 && choice !=2) //repeat while choice is not 1 or 2
	{
		if (cin.fail())
			{
				cin.clear();
				cin.get();
			}
		cin >> choice;
		if(choice != 1 && choice !=2)
		{
			//system("cls");
			cout << "Please enter as your choice 1 or 2\n";
		}
	}

	if(choice == 2)
		loadCustomTeam();			//load custom team
	else
	{
		/*
		arena->addFighter("Gimli R 50 25 10 10");
		arena->addFighter("Legolas A 70 10 20 0");
		
		fightersA[0] = arena->getFighter("Gimli");
		fightersB[0] = arena->getFighter("Legolas");
		*/

		// DEFAULT TEAM SELECTION
		arena->addFighter("Bob C 24 10 20 14");
		arena->addFighter("Alexander R 10 20 3 6");
		arena->addFighter("Craig A 25 20 14 20");
		arena->addFighter("Joe A 30 15 12 20");
		arena->addFighter("Moses C 50 2 10 10");
		arena->addFighter("Susan R 33 12 8 10");
		
		fightersA[0] = arena->getFighter("Bob");
		fightersA[1] = arena->getFighter("Alexander");
		fightersA[2] = arena->getFighter("Craig");
		fightersB[0] = arena->getFighter("Joe");
		fightersB[1] = arena->getFighter("Moses");
		fightersB[2] = arena->getFighter("Susan");
	}

	// Randomly places the fighters onto the board, making sure to place them only in
	// empty squares.
	for (int i = 0; i < TEAMSIZE; i++)
	{ // Place Team A fighters
		if (fightersA[i] != NULL)
		{
			int random;
			while ((grid[random = (rand() % (HEIGHT * WIDTH))]) != -1);
			grid[random] = i;
			locations[i] = random;
		}
	}
	for (int i = 0; i < TEAMSIZE; i++)
	{ // Place Team B fighters
		if (fightersB[i] != NULL)
		{
			int random;
			while ((grid[random = (rand() % (HEIGHT * WIDTH))]) != -1);
			grid[random] = i + TEAMSIZE;
			locations[i + TEAMSIZE] = random;
		}
	}

	drawGrid();
	loop(testing);
}

void FighterGame::loadCustomTeam()
{
	cin.get();
	for( int i = 0; i < 2; i++)
	{
		system("cls");
		char letter = 'A'+i;
		cout << "For Team " << letter << ", create a custom team of up to 5 fighters." <<endl;
		cout << "Remember, the format is <name> <type> <hitpoints> <strength> <speed> <magic>\n";
		cout << "\"type\" can be A (Archer), C (Cleric), or R (Robot).\n";
		cout << "Enter \"done\" when you are done with your team." <<endl;

		string fighter = "";	//hold fighter data
		int numFighters = 0;	//count number of fighters

		while(fighter != "done" && numFighters < TEAMSIZE)	//for some reason grab an empty line
		{
			getline(cin,fighter);			//fighter from user
			if(fighter != "done")			//Make sure its a legit fighter
			{
				if(arena->addFighter(fighter))
				{
					string name = getFighterName(fighter);	//get first name of fighter
					if(name != "")							//if valid name
					{
						if(i == 0)
							fightersA[numFighters] = arena->getFighter(name);	//add to ATeam
						else
							fightersB[numFighters] = arena->getFighter(name);	//add to BTeam

						cout << "Fighter #" << numFighters << " added to team " << letter << "!\n";
					}
					numFighters++;	//increment number of fighters
				}
				else
					cout << "Error: Invalid format.  Please try again.\n";
			}
		}
	}
}

string FighterGame::getFighterName(string fighter)
{
	string name = "";
	for(size_t i=0; i< fighter.size(); i++)
	{
		if(fighter.at(i) == ' ')
			break;
		else
			name.push_back(fighter.at(i));
	}
	return name;
}

void FighterGame::clearGrid()
{
	// Make every squre empty
	for (int i = 0; i < HEIGHT * WIDTH; i++)
		grid[i] = -1;

	// Randomly place 10 mountain squares
	for (int i = 0; i < 10; i++)
		grid[rand() % (HEIGHT * WIDTH)] = -2;

	// Randomly place 15 forest squares
	for (int i = 0; i < 15; i++)
		grid[rand() % (HEIGHT * WIDTH)] = -3;

	// Randomly place 5 water (impassible) squares
	for (int i = 0; i < 5; i++)
		grid[rand() % (HEIGHT * WIDTH)] = -4;

	for (int i = 0 ; i < HEIGHT * WIDTH; i++)
		tempgrid[i] = grid[i];
}

void FighterGame::drawGrid()
{
	system("cls");

	// Draw the board, line by line
	for (int i = 0; i < HEIGHT * 4 + 1; i++)
	{
		if (i % 4 == 0)
		{
			for (int j = 0; j < WIDTH; j++)
				cout << "+----";
			cout << "+";
		}
		else
		{
			for (int j = 0; j < WIDTH; j++)
				cout << "|    ";
			cout << "|";
		}

		if (i == 0)
			printf("      A TEAM:");
		else if (i > 0 && i < 10)
		{
			if (fightersA[(i - 1) / 2] != NULL)
			{
				if (i % 2)
				{
					// Name Length Max : 12 characters
					string name = fightersA[(i - 1) / 2]->getName();
					name += "            ";
					printf("   %i. %s",(i - 1) / 2, name.substr(0, 12).c_str());
				}
				else
				{
					FighterInterface* temp = fightersA[(i - 1) / 2];
					if (dynamic_cast<Archer*> (temp))
						printf("  A");
					else if (dynamic_cast<Cleric*> (temp))
						printf("  C");
					else if (dynamic_cast<Robot*> (temp))
						printf("  R");

					printf(" %i %i %i %i", temp->getMaximumHP(), temp->getStrength(),
						temp->getSpeed(), temp->getMagic());
				}
			}
		}
		else if (i == 10)
			printf("      B TEAM:");
		else
		if (fightersB[(i - 11) / 2] != NULL)
		{
			if (i % 2)
			{
				// Name Length Max : 12 characters
				string name = fightersB[(i - 11) / 2]->getName();
				name += "            ";
				printf("   %i. %s",(i - 1) / 2, name.substr(0, 12).c_str());
				
			}
			else
			{
				FighterInterface* temp = fightersB[(i - 11) / 2];
				if (dynamic_cast<Archer*> (temp))
					printf("  A");
				else if (dynamic_cast<Cleric*> (temp))
					printf("  C");
				else if (dynamic_cast<Robot*> (temp))
					printf("  R");

				printf(" %i %i %i %i", temp->getMaximumHP(), temp->getStrength(),
					temp->getSpeed(), temp->getMagic());
			}
		}

		cout << "\n";
	}

	for (int i = 0; i < WIDTH * HEIGHT; i++)
		if (grid[i] != -1)
			redraw(i);
}

void FighterGame::redraw(int location)
{
	int x = location % WIDTH;
	int y = location / WIDTH;

	x = x * 5 + 1;
	y = y * 4 + 1;

	int value = grid[location];

	for (int i = 0; i < 3; i++)
	{
		gotoXY(x, y + i);
		switch (value)
		{
		case -1:
			cout << "    ";
			break;
		case -2:
			SetConsoleTextAttribute(console, 6);
			cout << "^^^^";
			SetConsoleTextAttribute(console, 7);
			break;
		case -3:
			SetConsoleTextAttribute(console, 2);
			cout << "YYYY";
			SetConsoleTextAttribute(console, 7);
			break;
		case -4:
			SetConsoleTextAttribute(console, 9);
			cout << "~~~~";
			SetConsoleTextAttribute(console, 7);
			break;
		default:
			if (value > -1)
			{
				if (value < TEAMSIZE)
					drawFighterTeamA(i + 1, value);
				else if (value < TEAMSIZE * 2)
					drawFighterTeamB(i + 1, value);
				else
					cout << "ERRR";
			}
			else
				cout << "ERRR";
		}
	}
}

void FighterGame::drawFighterTeamA(int step, int value)
{
	if (fightersA[value] == NULL)
	{
		cout << "ERRR";
		return;
	}
	int color = 4;
	if (value == turn)
		color += 8;

	SetConsoleTextAttribute(console, color);
	string name;
	switch (step)
	{
	case 1:
		cout << "A  ";
		if (tempgrid[locations[value]] == -2)
		{
			SetConsoleTextAttribute(console, 6);
			cout << "^";
		}
		else if (tempgrid[locations[value]] == -3)
		{
			SetConsoleTextAttribute(console, 2);
			cout << "Y";
		}
		else
		{
			cout << " ";
		}
		SetConsoleTextAttribute(console, color);
		break;
	case 2:
		name = fightersA[value]->getName();
		name += "    ";
		cout << name.substr(0, 4);
		break;
	case 3:
		FighterInterface* temp = fightersA[value];
		if (dynamic_cast<Archer*> (temp))
			cout << "ARCH";
		else if (dynamic_cast<Cleric*> (temp))
			cout << "CLER";
		else if (dynamic_cast<Robot*> (temp))
			cout << "RBOT"; // ROBO ROBT
		break;
	}
	
	SetConsoleTextAttribute(console, 7);
}

void FighterGame::drawFighterTeamB(int step, int value)
{
	if (fightersB[value - TEAMSIZE] == NULL)
	{
		cout << "ERRR";
		return;
	}

	int color = 3;
	if (value == turn)
		color += 8;

	SetConsoleTextAttribute(console, color);
	string name;
	switch (step)
	{
	case 1:
		cout << "B  ";
		if (tempgrid[locations[value]] == -2)
		{
			SetConsoleTextAttribute(console, 6);
			cout << "^";
		}
		else if (tempgrid[locations[value]] == -3)
		{
			SetConsoleTextAttribute(console, 2);
			cout << "Y";
		}
		else
		{
			cout << " ";
		}
		SetConsoleTextAttribute(console, color);
		break;
	case 2:
		name = fightersB[value - TEAMSIZE]->getName();
		name += "    ";
		cout << name.substr(0, 4);
		break;
	case 3:
		FighterInterface* temp = fightersB[value - TEAMSIZE];
		if (dynamic_cast<Archer*> (temp))
			cout << "ARCH";
		else if (dynamic_cast<Cleric*> (temp))
			cout << "CLER";
		else if (dynamic_cast<Robot*> (temp))
			cout << "RBOT"; // ROBO ROBT
		break;
	}
	SetConsoleTextAttribute(console, 7);
}

void FighterGame::move(char input, bool testing)
{
	input = _getch();
	int current = locations[turn];
	int next;
	if (input == 72)
		if (current >= WIDTH)
			next = -WIDTH;
		else
		{
			message = "You cannot go that way.";
			return;
		}
	else if (input == 75)
		if (current % WIDTH > 0)
			next = -1;
		else
		{
			message = "You cannot go that way.";
			return;
		}
	else if (input == 77)
		if (current % WIDTH < WIDTH - 1)
			next = 1;
		else
		{
			message = "You cannot go that way.";
			return;
		}
	else
		if ((current / WIDTH) < HEIGHT - 1)
			next = WIDTH;
		else
		{
			message = "You cannot go that way.";
			return;
		}
	
	// Check whether combat will happen
	if (grid[current + next] >= 0)
		if (checkMovement(tempgrid[current + next]))
			// Check teams
			if (turn < TEAMSIZE)
			{
				if (combatTeamA(current, next, testing))
				{
					if (!testing)
						redraw(current);
					else
						drawGrid();
					return;
				}
				else if (testing)
					drawGrid();
			}
			else
			{
				if (combatTeamB(current, next, testing))
				{
					if (!testing)
						redraw(current);
					else
						drawGrid();
					return;
				}
				else if (testing)
					drawGrid();
			}
		else
		{
			message = "You don't have enough movements left to go there.";
			return;
		}

	// Ensure player has enough movements left
	int change = checkMovement(tempgrid[current + next]);
	if (change)
		steps += change;
	else
	{
		message = "You don't have enough movements left to go there.";
		return;
	}

	grid[current] = tempgrid[current];
	locations[turn] += next;
	grid[locations[turn]] = turn;
	redraw(current);
	redraw(current + next);
}

bool FighterGame::combatTeamA(int current, int next, bool testing)
{ // Returns true if the fighter doesn't move (i.e. they lose or don't fight), and false if they do

	int enemy = grid[current + next];
	if (enemy < TEAMSIZE)
	{
		message = "You cannot fight one of your teammates!";
		return true;
	}

	gotoXY(0,23);
	FighterInterface* attacker = fightersA[turn];
	FighterInterface* defender = fightersB[grid[current + next] - TEAMSIZE];
	FighterInterface* winner = fight(attacker, defender, testing);
	//_getch();
	if (winner == attacker)
	{
		message += attacker->getName();
		message += " defeats ";
		message += defender->getName();
		message += "!";

		if (testing && !attacker->isSimplified() && !defender->isSimplified())
		{
			string name1 = attacker->getName();
			string name2 = defender->getName();

			if (name1 == "Bob" || name1 == "Craig")
			{
				if (name2 == "Susan")
					cout << " ERROR: Susan should have won!";
			}
			else if (name1 == "Alex")
				if (name2 == "Moses")
					cout << " ERROR: Moses should have won!";
		}

		delete defender;

		if (testing)
			_getch();
		else
		{
			gotoXY(62, grid[current + next] * 2 + 1);
			cout << "                 ";
			gotoXY(62, grid[current + next] * 2 + 2);
			cout << "                 ";
		}
		fightersB[grid[current + next] - TEAMSIZE] = NULL;
		grid[current + next] = tempgrid[current + next];
	}
	else
	{
		message += attacker->getName();
		message += " was defeated by ";
		message += defender->getName();
		message += "!";
		
		if (testing && !attacker->isSimplified() && !defender->isSimplified())
		{
			string name1 = attacker->getName();
			string name2 = defender->getName();

			if (name1 == "Bob" || name1 == "Craig")
			{
				if (name2 == "Joe" || name2 == "Moses")
					cout << " ERROR: " << name1 << " should have won!";
			}
			else if (name1 == "Alex")
				if (name2 == "Joe" || name2 == "Susan")
					cout << " ERROR: Alex should have won!";
		}

		steps = 0;
		delete attacker;

		if (testing)
			_getch();
		else
		{
			gotoXY(62, turn * 2 + 1);
			cout << "                 ";
			gotoXY(62, turn * 2 + 2);
			cout << "                 ";
		}
		fightersA[turn] = NULL;
		grid[locations[turn]] = tempgrid[locations[turn]];
		return true;
	}

	return false;
}

bool FighterGame::combatTeamB(int current, int next, bool testing)
{ // Returns true if the fighter doesn't move (i.e. they lose or don't fight), and false if they do

	int enemy = grid[current + next];
	if (enemy >= TEAMSIZE)
	{
		message = "You cannot fight one of your teammates!";
		return true;
	}

	gotoXY(0,23);
	FighterInterface* attacker = fightersB[turn - TEAMSIZE];
	FighterInterface* defender = fightersA[grid[current + next]];
	FighterInterface* winner = fight(attacker, defender, testing);
	//_getch();
	if (winner == attacker)
	{
		message += attacker->getName();
		message += " defeats ";
		message += defender->getName();
		message += "!";
		
		if (testing && !attacker->isSimplified() && !defender->isSimplified())
		{
			string name1 = attacker->getName();
			string name2 = defender->getName();

			if (name1 == "Moses")
			{
				if (name2 == "Bob" || name2 == "Craig")
					cout << " ERROR: " << name2 << " should have won!";
			}
		}

		
		delete defender;

		if (testing)
			_getch();
		else
		{
			gotoXY(62, grid[current + next] * 2 + 1);
			cout << "                 ";
			gotoXY(62, grid[current + next] * 2 + 2);
			cout << "                 ";
		}

		fightersA[grid[current + next]] = NULL;
		grid[current + next] = tempgrid[current + next];
	}
	else
	{
		message += attacker->getName();
		message += " was defeated by ";
		message += defender->getName();
		message += "!";

		if (testing && !attacker->isSimplified() && !defender->isSimplified())
		{
			string name1 = attacker->getName();
			string name2 = defender->getName();

			if (name1 == "Joe")
				cout << " ERROR: Joe should have won!";
			else if (name1 == "Moses")
			{
				if (name2 == "Alex")
					cout << " ERROR: Moses should have won!";
			}
			else if (name1 == "Susan")
				cout << "ERROR: Susan should have won!";
		}

		steps = 0;
		delete attacker;

		if (testing)
			_getch();
		else
		{
			gotoXY(62, turn * 2 + 1);
			cout << "                 ";
			gotoXY(62, turn * 2 + 2);
			cout << "                 ";
		}

		fightersB[turn - TEAMSIZE] = NULL;
		grid[locations[turn]] = tempgrid[locations[turn]];
		return true;
	}
	return false;
}

int FighterGame::checkMovement(int newSquare)
{
	switch (newSquare)
	{
	case -1:
		if (steps > 0)
			return -1;
		break;
	case -2:
		if (steps > 2)
			return -3;
		break;
	case -3:
		if (steps > 1)
			return -2;
		break;
	}
	return 0;
}

bool FighterGame::checkWin()
{
	int i;

	for (i = 0; i < TEAMSIZE; i++)
		if (fightersA[i] != NULL)
			break;
	if (i < TEAMSIZE)
	{
		for (i = TEAMSIZE; i < 2 * TEAMSIZE; i++)
			if (fightersB[i - TEAMSIZE] != NULL)
				break;
		if (i == TEAMSIZE * 2)
		{
			message += "\nTeam A wins!  Game Over!";
			return true;
		}
	}
	else
	{
		message += "\nTeam B wins!  Game Over!";
		return true;
	}
	
	return false;
}