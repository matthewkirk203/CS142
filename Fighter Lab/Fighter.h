// You shouldnt have to modify this file, but you need to fill the Fighter.cpp file we provided with the implementations.
// Implement all common behaviours, and let the subclasses override their specific behaviors.

#pragma once
#include "FighterInterface.h"

class Fighter : public FighterInterface
{
public:
	//------------------------------------------------------
	Fighter();

	//------------------------------------------------------
	Fighter(string name, int max_hp, int strength, int speed, int magic);


	/*
			Returns the name of this fighter.
	*/
	string getName();

	//------------------------------------------------------
	/*
			Returns the maximum hit points of this fighter.
	*/
	int getMaximumHP();


	//------------------------------------------------------
	/*
			Returns the current hit points of this fighter.
	*/
	int getCurrentHP();


	//------------------------------------------------------
	/*

			Returns the strength stat of this fighter.
	*/
	int getStrength();

	//------------------------------------------------------
	/*
			Returns the speed stat of this fighter.
	*/
	int getSpeed();


	//------------------------------------------------------
	/*
			Returns the magic stat of this fighter.
	*/
	int getMagic();


	//------------------------------------------------------
	/*
			Returns the amount of damage a fighter will deal.
			In the Fighter class this method just returns a default value like 0, as it will never be used in the fighter class. 
			It will be overwritten when you create the Robot, Archer or Cleric class.
	*/
	virtual int getDamage();


	//------------------------------------------------------
	/*
			Reduces the fighter's current hit points by an amount equal to the given 
			damage minus one fourth of the fighter's speed.  This method must reduce 
			the fighter's current hit points by at least one.  It is acceptable for 
			this method to give the fighter negative current hit points.

			Examples:
				damage=10, speed=7		=> damage_taken=9
				damage=10, speed=9		=> damage_taken=8
				damage=10, speed=50		=> damage_taken=1
	*/
	void takeDamage(int damage);


	//------------------------------------------------------
	/*
			Restores a fighter's current hit points to its maximum hit points.
	*/
	virtual void reset();


	//------------------------------------------------------
	/*		Increases the fighter's current hit points by an amount equal to one sixth of
			the fighter's strength.  This method must increase the fighter's current hit 
			points by at least one.  Do not allow the current hit points to exceed the 
			maximum hit points.
	*/
	virtual void regenerate();


	//------------------------------------------------------
	/*
			Attempts to perform a special ability based on the type of fighter.  The 
			fighter will attempt to use this special ability just prior to attacking 
			every turn.

			In fighter, there are no special abilities because this is just a generic fighter.
	*/
	virtual bool useAbility();


	//------------------------------------------------------
	/*
			Returns true if you have not completed the useAbility() and/or the regenerate()
			methods for this type of fighter.  This allows the game to award points 
			for Part 2 even if Part 3 is incomplete.
			
			Return true if the testing is to be simplified; false otherwise.
	*/
	bool isSimplified();


protected:
	string name; // this string holds the name of a Fighter
	int max_hp;	//this int will hold the maximum hit points of a fighter
	int current_hp; // this int will hold the current hit points of a fighter
	int strength; // this int will hold the strength of a warrior
	int speed; // this int will hold the speed of a warrior
	int magic; // this int will hold the magic of a warrior
};