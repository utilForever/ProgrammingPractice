#pragma once
#include "Item.h"

class Armor :
	public Item
{
public:
	Armor(std::string, std::string, int, int, int);
	void Describe();

private:
	int defense;
};