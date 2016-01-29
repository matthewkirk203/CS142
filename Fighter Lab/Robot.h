#pragma once
#include "Fighter.h"
// PLEASE CHANGE THIS FILE
// The class must be called Robot
// By completing this file, you should learn about inheritance.
// You should add a file called Robot.cpp that will hold the implementations.
// You will override functions in the Fighter class, but you will make the following changes
// Robot - Relies on strength to deal damage.  Also can use stored electricity to temporarily increase damage (max electricity equal to 2*magic).

		/*
			getDamage()

			Returns the amount of damage a fighter will deal.

			Robot:
			This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.

		*/
		
		
		/*
			reset()

			Restores a fighter's current hit points to its maximum hit points.

			Robot:
			Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
			Also resets a Robot's bonus damage to 0.

		*/

		
		/*
			useAbility()
			
			Attempts to perform a special ability based on the type of fighter.  The 
			fighter will attempt to use this special ability just prior to attacking 
			every turn.

			Robot: Shockwave Punch
			Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength * ((current_energy/maximum_energy)^4)).
			Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
			Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
				Examples:
				strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
				strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
				strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
				strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
			Robot Note:
			The bonus damage formula should be computed using double arithmetic, and only 
			the final result should be cast into an integer.

			Return true if the ability was used; false otherwise.
		*/
class Robot : public Fighter
{
public:
	Robot(string n, int hp, int str, int sp, int mag);
	int getDamage();
	void reset();
	bool useAbility();
private:
	int current_energy;
	int max_energy;
	int bonus_damage;
};
	
