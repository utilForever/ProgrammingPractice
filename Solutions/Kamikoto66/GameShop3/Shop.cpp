#include <iostream>
#include "Shop.h"
#include "Item.h"


Shop::Shop()
{
}

Shop::Shop(std::string name, std::list<Item*> items)
	:_name(name), _items(items)
{
}


Shop::~Shop()
{
}

void Shop::ShowItemList()
{
	std::cout << _name .c_str()<< std::endl;
	std::cout << "- Item List -" << std::endl;

	for each (auto var in _items)
	{
		var->Describe();
	}
}
