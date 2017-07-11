#include <iomanip>
#include "Weapon.h"

Weapon::Weapon(std::string name, std::string descripition, int wight, int value, int damage):Item(name,descripition,wight,value)
{
	Weapon::damage = damage;
}


Weapon::~Weapon()
{
}

void Weapon::Describe() {
	Item::Describe();
	std::cout << std::left << std::setw(13) << "Damage" << " = " << damage << std::endl;
}