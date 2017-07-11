#pragma once
#include <iostream>
#include "Item.h"

class Potion : public Item
{
public:
	Potion(std::string, std::string, int, int, std::string, int);
	~Potion();

	void Describe();

private:
	std::string type;
	int capacity;
};

