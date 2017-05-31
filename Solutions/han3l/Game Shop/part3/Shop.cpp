#include "Shop.h"

Shop::Shop()
{
}

Shop::~Shop()
{
}

Shop::Shop(std::string name, std::list<Item*> items)
	: name(name), items(items)
{
}

void Shop::ShowItemList()
{
	std::cout << "Welcome to " << this->name << std::endl;
	std::cout << "- Item List -" << std::endl;
	
	for each (auto var in items)
	{
		var->Describe();
	}
}