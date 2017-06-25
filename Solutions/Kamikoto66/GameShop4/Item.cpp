#include <iostream>
#include "Item.h"

Item::Item()
{
	_name = "";
	_description = "";
	_weight = 0;
	_value = 0;
}

Item::~Item()
{
}

Item::Item(string name, string description, int weight, int value)
	:_name(name), _description(description), _weight(weight), _value(value)
{
}

void Item::Describe()
{
	cout << "Name:" << _name << endl;
	cout << "Description: " << _description << endl;
	cout << "Weight: " << _weight << "lbs" <<endl;
	cout << "Value: " << _value << "gold coins" <<endl;
}
