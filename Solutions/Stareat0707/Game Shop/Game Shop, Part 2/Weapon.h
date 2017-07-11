#pragma once
#include "Item.h"

class Weapon :
	public Item
{
public:
	Weapon(std::string, std::string, int, int, int);
	void Describe();

private:
	int damage;
};