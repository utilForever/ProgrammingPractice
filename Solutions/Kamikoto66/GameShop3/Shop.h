#pragma once
#include <string>
#include <list>

class Item;

class Shop
{
private:
	std::string _name;
	std::list<Item*> _items;

public:
	Shop();	
	Shop(std::string name, std::list<Item*> items);
	~Shop();

	void ShowItemList();
};

