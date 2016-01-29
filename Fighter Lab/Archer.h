#pragma once
#include "Fighter.h"
// PLEASE CHANGE THIS FILE
// The class must be called Archer
// By completing this file, you should learn about inheritance. 
// You should add a file called Archer.cpp that will hold the implementations.
// You will override functions in the Fighter class, but you will make the following changes
// Archer - Relies on speed to deal damage.  Also can increase its speed for the remainder of the battle (no max bonus speed).


		/*
			getDamage()

			Returns the amount of damage a fighter will deal.
			
			Archer:
			This value is equal to the Archer's speed.
		*/
		
		
		/*
			reset()

			Restores a fighter's current hit points to its maximum hit points.

			Archer:
			Also resets an Archer's current speed to its original value.

		*/
		
		
		/*
			useAbility()
			
			Attempts to perform a special ability based on the type of fighter.  The 
			fighter will attempt to use this special ability just prior to attacking 
			every turn.

			Archer: Quickstep
			Increases the Archer's speed by one point each time the ability is used.
			This bonus lasts until the reset() method is used.
			This ability always works; there is no maximum bonus speed.

			Return true if the ability was used; false otherwise.
		*/
class Archer : public Fighter
{
public:
	Archer(string name, int max_hp, int strength, int speed, int magic);
	int getDamage();
	void reset();
	bool useAbility();
private:
	int base_speed;
};