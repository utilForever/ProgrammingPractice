#pragma once
#include <iostream>
#include "Item.h"

class Armor : public Item
{
public:
	Armor(std::string, std::string, int, int, int);
	~Armor();

	void Describe();

private:
	int defence;
};

