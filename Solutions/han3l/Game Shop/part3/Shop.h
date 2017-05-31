#pragma once
#include "Item.h"
#include <list>

class Item;

class Shop
{
public:
	Shop();
	virtual ~Shop();
	Shop(std::string name, std::list<Item*> items);
	void ShowItemList();
private:
	std::string name;
	std::list<Item*> items;
};

