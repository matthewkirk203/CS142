#pragma once
#include <string>
#include "ArenaInterface.h"
// PLEASE CHANGE THIS FILE
// By completing this file, you should learn about polymorphism. This is your class that represents the arena and it must be named BattleArena
// You must also create your own attribute to hold the fighters, such as a vector. Even though you will have different subclasses
//  in the arena vector, they all are returned in a FighterInterface pointer.  Their behavior is different
//  depending on their subclass.

// You should also create a BattleArena.cpp file with your implementations

// In this file you should extend the ArenaInterface class to implement the arena functions:


//------------------------------------------------------
// Given the info string, create a new fighter with the specified characteristics and add him to your arena vector.
//  bool addFighter(string info); 



//------------------------------------------------------
// Remove a fighter from the arena (when he dies)
//  bool removeFighter(string name);


//------------------------------------------------------
// Return a pointer to the fighter with the given name so that he can fight
//  FighterInterface* getFighter(string name);


//------------------------------------------------------
// Return the size of your vector of fighters in the arena
//  int getSize();

class BattleArena : public ArenaInterface
{
public:
	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();
private:
	vector<FighterInterface*> players;
};
