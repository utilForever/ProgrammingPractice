#include <iomanip>
#include "Armor.h"

Armor::Armor(std::string name, std::string descripition, int wight, int value, int defence) :Item(name, descripition, wight, value)
{
	Armor::defence = defence;
}


Armor::~Armor()
{
}

void Armor::Describe() {
	Item::Describe();
	std::cout << std::left << std::setw(13) << "Defence" << " = " << defence << std::endl;
}
