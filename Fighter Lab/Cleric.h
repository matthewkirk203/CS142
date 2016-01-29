#pragma once
#include "Fighter.h"
// PLEASE CHANGE THIS FILE
// The class must be called Cleric
// By completing this file, you should learn about inheritance. 
// You should add a file called Cleric.cpp that will hold the implementations.
// You will override functions in the Fighter class, but you will make the following changes
// Cleric - Relies on magic to deal damage.  Also can heal itself using mana, restoring hit points (max mana equal to 5*magic).

		/*
			getDamage()

			Returns the amount of damage a fighter will deal.

			Cleric:
			This value is equal to the Cleric's magic.
		*/
		
		
		/*
			reset()

			Restores a fighter's current hit points to its maximum hit points.

			Cleric:
			Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
		*/

		
		/*
			regenerate()

			Increases the fighter's current hit points by an amount equal to one sixth of
			the fighter's strength.  This method must increase the fighter's current hit 
			points by at least one.  Do not allow the current hit points to exceed the 
			maximum hit points.

			Cleric:
			Also increases a Cleric's current mana by an amount equal to one fifth of the 
			Cleric's magic.  This method must increase the Cleric's current mana by at 
			least one.  Do not allow the current mana to exceed the maximum mana.
		*/
		
		
		/*
			useAbility()
			
			Attempts to perform a special ability based on the type of fighter.  The 
			fighter will attempt to use this special ability just prior to attacking 
			every turn.

			Cleric: Healing Light
			Increases the Cleric's current hit points by an amount equal to one third of its magic.
			Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
			Will be used even if the Cleric's current HP is equal to their maximum HP
			Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
			Cleric Note:
			This ability, when successful, must increase the Cleric's current hit points 
			by at least one.  Do not allow the current hit points to exceed the maximum 
			hit points.

			Return true if the ability was used; false otherwise.
		*/

class Cleric : public Fighter
{
public:
	Cleric(string name, int max_hp, int strength, int speed, int magic);
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
protected:
	int current_mana;
	int max_mana;
};