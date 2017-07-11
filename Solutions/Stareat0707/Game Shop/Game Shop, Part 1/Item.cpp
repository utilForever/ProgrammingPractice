#include "Item.h"

Item::Item(std::string name, std::string description, int weight, int value) : name(name), description(description), weight(weight), value(value)
{
}

void Item::Describe()
{
	std::cout << "Name          = " << name << std::endl;
	std::cout << "Description   = " << description << std::endl;
	std::cout << "Weight        = " << weight << " lbs" << std::endl;
	std::cout << "Value         = " << value << " coins" << std::endl;
}