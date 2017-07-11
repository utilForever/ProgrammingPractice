#include <iomanip>
#include "Item.h"

Item::Item(std::string name, std::string descripition, int wight, int value)
{
	Item::name = name;
	Item::descripition = descripition;
	Item::wight = wight;
	Item::value = value;
}


Item::~Item()
{

}

void Item::Describe() {
	std::cout << std::left << std::setw(13) << "Name" << " = " << name.data() << std::endl;
	std::cout << std::left << std::setw(13) << "Description" << " = " << descripition.data() << std::endl;
	std::cout << std::left << std::setw(13) << "Weight" << " = " << wight << " lbs" << std::endl;
	std::cout << std::left << std::setw(13) << "Value" << " = " << value << " gold coins" << std::endl;
}