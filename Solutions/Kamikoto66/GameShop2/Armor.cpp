#include <iostream>
#include "Armor.h"
#include "Item.h"

Armor::Armor()
{
}

Armor::Armor(string name, string description, int weight, int value, int defense) 
	:Item(name, description, weight, value)
{
	_defense = defense;
}


Armor::~Armor()
{
}

void Armor::Describe()
{
	Item::Describe();
	cout << "Defense = " << _defense << endl;
	puts("");
}
