#pragma once
#include "Factory.h"
#include "BattleArena.h"
using namespace std;

/*
	WARNING: It is expressly forbidden to modify any part of this document, including its name
*/
//=======================================================================================
/*
	createArena()

	Creates and returns an object whose class extends ArenaInterface.
	This should be an object of a class you have created, which will be called BattleArena
*/
ArenaInterface* Factory::createArena()
{
	return new BattleArena();
}
//=======================================================================================