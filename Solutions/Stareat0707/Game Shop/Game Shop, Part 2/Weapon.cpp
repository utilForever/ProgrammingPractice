#include "Weapon.h"

Weapon::Weapon(std::string name, std::string description, int weight, int value, int damage) : Item(name, description, weight, value), damage(damage)
{
}

void Weapon::Describe()
{
	Item::Describe();
	std::cout << "Damage        = " << damage << std::endl;
}