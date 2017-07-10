#include <iomanip>
#include "Potion.h"

Potion::Potion(std::string name, std::string descripition, int wight, int value, std::string type, int capacity) :Item(name, descripition, wight, value)
{

	Potion::type = type;
	Potion::capacity = capacity;
}


Potion::~Potion()
{
}

void Potion::Describe() {
	Item::Describe();
	
	std::cout << std::left << std::setw(13) << "Type" << " = " << type.data() << std::endl;
	std::cout << std::left << std::setw(13) << "Capacity" << " = " << capacity << std::endl;
}
