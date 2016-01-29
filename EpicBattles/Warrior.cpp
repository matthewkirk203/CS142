#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior (int h, int d, int r, int b)
{
	max_hp = h;
	hp = h;
	damage = d;
	regen = r;
	defense = b;
}
int Warrior::get_damage() const
{
	return damage;
}

void Warrior::take_damage(int damage) // Damage of enemy warrior should be passed in.
{
	if (defense < damage)
	{
		hp -= (damage - defense);
	}
	if (hp <= 0)
	{
		cout << "Perished in battle!" << endl;
	}
}

int Warrior::get_hp() const
{
	return hp;
}

void Warrior::regenerate()
{
	if (hp < (max_hp/2))
	{
		hp += regen;
		cout << "Regenerate!\n";
	}
}

int Warrior::get_regen() const
{
	return regen;
}

int Warrior::get_defense() const
{
	return defense;
}

void Warrior::tostr() const
{
	cout << "HP: " << hp << endl;
	cout << "Damage: " << damage << endl;
	cout << "Regeneration: " << regen << endl;
	cout << "Defense: " << defense << endl;

}