/*
Matthew kirk
Section: 4
11/30/2012
Lab #10 RPG Fighter Lab
Description: This program creates a vector of fighters with different stats. They can be either an Archer, Robot, or Cleric.
			Each has unique abilities and stats.
			They are put into teams and the player can move them and fight. Yeah!
Design:
	User can input fighters or choose a default team.
	The user can attack other fighters and they will fight...to the death!
	Winning team wins. Yeah!
Test cases:
I stepped through my code with breakpoints to test these:
	Archer damage returns speed, cleric returns magic, and robot strength.
	Archer speed increases after every round.
	Robot bonus damage is equal to str on the first round.
	Everyone regenerates at least one HP, even if their stregth/6 < 1
*/
#pragma once
#include <string>
#include <sstream>
#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"
#include "BattleArena.h"

bool BattleArena::addFighter(string info)
{
	string name, type;
	int max_hp, strength, speed, magic;
	stringstream strm;
	strm << info;
	strm >> name >> type >> max_hp >> strength >> speed >> magic;
	if (type == "A")
	{
		FighterInterface* player = new Archer(name, max_hp, strength, speed, magic);
		players.push_back(player);
		return true;
	}
	
	else if (type == "R")
	{
		FighterInterface* player = new Robot(name, max_hp, strength, speed, magic);
		players.push_back(player);
		return true;
	}
	else if (type == "C")
	{
		FighterInterface* player = new Cleric(name, max_hp, strength, speed, magic);
		players.push_back(player);
		return true;
	}
	else
	{
		return false;
	}
}

bool BattleArena::removeFighter(string name)
{
	for (int i = 0; i < players.size(); i++)
	{
		if ((*players[i]).getName() == name)
		{
			players.erase (players.begin()+i);
			return true;
		}
	}
	return false;
	
}

FighterInterface* BattleArena::getFighter(string name)
{
	for (int i = 0; i < players.size(); i++)
	{
		if ((*players[i]).getName() == name)
		{
			return (players[i]);
		}
	}
}

int BattleArena::getSize()
{
	return players.size();
}