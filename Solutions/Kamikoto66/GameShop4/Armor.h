#pragma once

#include "Item.h"
class Item;

enum class ArmorIndex
{
	eDefense = 5
};

class Armor : public Item
{
private:
	int _defense;

public:

	Armor();
	Armor(string name, string description, int weight, int value, int defense);
	
	virtual ~Armor();

	virtual void Describe() override;

	void SetDefense(int defense) { _defense = defense; }
};

