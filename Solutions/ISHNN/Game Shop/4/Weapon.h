#pragma once
#include <iostream>
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string, std::string, int, int, int);
	~Weapon();

	void Describe();

private:
	int damage;
};

