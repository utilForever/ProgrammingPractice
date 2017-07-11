#include "Armor.h"

Armor::Armor(std::string name, std::string description, int weight, int value, int defense) : Item(name, description, weight, value), defense(defense)
{
}

void Armor::Describe()
{
	Item::Describe();
	std::cout << "Defense       = " << defense << std::endl;
}