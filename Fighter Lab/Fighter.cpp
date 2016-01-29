#pragma once
#include "Fighter.h"
// PLEASE CHANGE THIS FILE
// By completing this file, you should learn about inheritance. 
// The fighter class should hold all common behaviors for the
//   subclasses Robot, Cleric and Archer

Fighter::Fighter()
{

}
Fighter::Fighter(string n, int hp, int str, int sp, int mag)
{
	name = n;
	max_hp = hp;
	current_hp = hp;
	strength = str;
	speed = sp;
	magic = mag;
}

string Fighter::getName()
{
	return name;
}

int Fighter::getMaximumHP()
{
	return max_hp;
}

int Fighter::getCurrentHP()
{
	return current_hp;
}

int Fighter::getStrength()
{
	return strength;
}

int Fighter::getSpeed()
{
	return speed;
}

int Fighter::getMagic()
{
	return magic;
}

int Fighter::getDamage()
{
	return 0;
}

void Fighter::takeDamage(int damage) 
{
	int net_damage = damage - (speed/4);
	if (net_damage > 0)
	{
	current_hp -= net_damage;
	}
	else
	{
		current_hp--;
	}
}

void Fighter::reset()
{
	current_hp = max_hp;
}

void Fighter::regenerate()
{
	int hpregen_value = strength/6;
	if (hpregen_value > 0 && current_hp < max_hp)
	{
		current_hp += hpregen_value;
	}
	else if (current_hp < max_hp)
	{
		current_hp++;
	}
}

bool Fighter::useAbility()
{
	return true;
}

bool Fighter::isSimplified()
{
	return false;
}