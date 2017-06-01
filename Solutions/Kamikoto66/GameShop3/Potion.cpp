#include "Item.h"
#include "Potion.h"
#include <iostream>


Potion::Potion()
{
}

Potion::Potion(string name, string description, int weight, int value, string type, int capacity)
	:Item(name, description, weight, value), _type(type), _capacity(capacity)
{
}


Potion::~Potion()
{
}

void Potion::Describe()
{
	Item::Describe();
	cout << "Type = " << _type.c_str() << endl;
	cout << "Capacity = " << _capacity << endl;
	cout << endl;
}
