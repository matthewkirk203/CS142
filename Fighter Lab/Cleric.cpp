#pragma once
#include "Cleric.h"

Cleric::Cleric(string n, int hp, int str, int sp, int mag)
{
	name = n;
	max_hp = hp;
	current_hp = hp;
	strength = str;
	speed = sp;
	magic = mag;
	current_mana = 5*mag;
	max_mana = 5*mag;
}

int Cleric::getDamage()
{
	return magic;
}

void Cleric::reset()
{
	current_hp = max_hp;
	current_mana = max_mana;
}

void Cleric::regenerate()
{
	// Health Regen
	int hpregen_value = strength/6;
	if (hpregen_value > 0 && current_hp < max_hp)
	{
		current_hp += hpregen_value;
	}
	else if (current_hp < max_hp)
	{
		current_hp++;
	}
	// Mana Regen
	int manaregen_value = magic/5;
	if (manaregen_value > 0 && current_mana < max_mana)
	{
		current_mana += manaregen_value;
	}
	else if (current_mana < max_mana)
	{
		current_mana++;
	}
}

bool Cleric::useAbility()
{
	if (current_mana > CLERIC_ABILITY_COST)
	{
		int hpregen_value = magic/3;
		if (hpregen_value > 0 && current_hp < max_hp)
		{
			current_hp += hpregen_value;
		}
		else if (current_hp < max_hp)
		{
			current_hp++;
		}
		current_mana -= CLERIC_ABILITY_COST;
		return true;
	}

	return false;
}