#pragma once
#include "Archer.h"

Archer::Archer(string n, int hp, int str, int sp, int mag)
{
	name = n;
	max_hp = hp;
	current_hp = hp;
	strength = str;
	speed = sp;
	base_speed = sp;
	magic = mag;
}

int Archer::getDamage()
{
	return speed;
}

void Archer::reset()
{
	current_hp = max_hp;
	speed = base_speed;
}

bool Archer::useAbility()
{
	speed++;
	return true;
}