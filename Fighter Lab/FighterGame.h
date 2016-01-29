#pragma once
#include "FighterInterface.h"
#include <vector>

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/

class FighterGame
{
private:
	FighterInterface *fightersA[5];
	FighterInterface *fightersB[5];
	int locations[10];
	int *grid, *tempgrid;
	int WIDTH, HEIGHT, TEAMSIZE;
	ArenaInterface* arena;
	int turn, steps;
	string message;

	void initialize();
	void loadCustomTeam();
	string getFighterName(string fighter);

	void clearGrid();
	void drawGrid();
	void drawFighterTeamA(int step, int value);
	void drawFighterTeamB(int step, int value);

	void loop(bool testing);
	void move(char input, bool testing);
	int checkMovement(int newSquare);
	bool combatTeamA(int current, int next, bool testing);
	bool combatTeamB(int current, int next, bool testing);

	bool checkWin();
	void redraw(int location);
public:
	FighterGame();
	void startGame(bool testing);
};