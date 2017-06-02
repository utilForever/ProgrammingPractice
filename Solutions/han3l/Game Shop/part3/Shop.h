#pragma once
#include "Item.h"
#include <vector>

class Item;

class Shop
{
public:
	Shop();
	virtual ~Shop();
	Shop(std::string name, std::vector<Item*> items);
	void ShowItemList();
private:
	std::string name;
	std::vector<Item*> items;
};

