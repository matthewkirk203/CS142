#include <string>
using namespace std;

class Warrior
{
public:
	Warrior(int, int, int, int);
	void take_damage(int damage);
	void regenerate();
	int get_defense() const;
	int get_regen() const;
	int get_hp() const;
	int get_damage() const;
	void tostr() const;

private:
	int defense;
	int hp;
	int regen;
	int damage;
	int max_hp;
};