#pragma once
#include <iostream>
#include <Set>
#include "Item.h"

class Shop
{
public:
	Shop(std::string, std::string);
	~Shop();

	void ReadDataFromFile();
	void LoadShop();

	void PrintShop();
	int Selection_Shop();

private:
	std::string name;
	std::string filename;
	std::set<Item*> items;
};