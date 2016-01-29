#pragma once
#include "Robot.h"
#include <math.h>

Robot::Robot(string n, int hp, int str, int sp, int mag)
{
	name = n;
	max_hp = hp;
	current_hp = hp;
	strength = str;
	speed = sp;
	magic = mag;
	current_energy = 2*mag;
	max_energy = 2*mag;
	bonus_damage = 0;
}

int Robot::getDamage() // need to return strength + bonus damage
{
	int total_damage = strength + bonus_damage;
	bonus_damage = 0;
	return total_damage;
}

void Robot::reset()
{
	current_hp = max_hp;
	current_energy = max_energy;
	bonus_damage = 0;
}

bool Robot::useAbility()
{
	if (current_energy > ROBOT_ABILITY_COST)
	{
		bonus_damage = (1.0)*strength * pow(((1.0*current_energy)/(1.0*max_energy)),4);
		current_energy -= ROBOT_ABILITY_COST;
		return true;
	}

	return false; // not used
}