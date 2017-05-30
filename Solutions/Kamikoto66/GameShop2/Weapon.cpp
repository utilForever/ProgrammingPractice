#include <iostream>
#include "Item.h"
#include "Weapon.h"


Weapon::Weapon()
{
	_damage = 0;
}


Weapon::~Weapon()
{
}

Weapon::Weapon(string name, string description, int weight, int value, int damage) 
	:Item(name, description, weight, value)
{
	_damage = damage;
}

void Weapon::Describe()
{
	Item::Describe();
	cout << "Damage: " << _damage << endl;
	puts("");
}