#include "Game Shop.h"

#include <iostream>
#include <iomanip>

Item::Item(string name, string description, int weight, int value)
	:name(name), description(description), weight(weight), value(value) {}

void Item::Describe() const
{
	cout.setf(ios::left);
	cout << setw(13) << "Name" << "= " << name << endl;
	cout << setw(13) << "Description" << "= " << description << endl;
	cout << setw(13) << "Weight" << "= " << weight << endl;
	cout << setw(13) << "Value" << "= " << value << endl;
}

Weapon::Weapon(string name, string description, int weight, int value, int damage)
	: damage(damage), Item(name, description, weight, value) {}

void Weapon::Describe() const 
{
	Item::Describe();
	cout << setw(13) << "Damage" << "= " << damage << endl;
}


Armor::Armor(string name, string description, int weight, int value, int defense)
	: defense(defense), Item(name, description, weight, value) {}

void Armor::Describe() const
{
	Item::Describe();
	cout << setw(13) << "Defense" << "= " << defense << endl;
}

Potion::Potion(string name, string description, int weight, int value, string type, int capacity)
	:Item(name, description, weight, value), type(type), capacity(capacity) {}

void Potion::Describe() const
{
	Item::Describe();
	cout << setw(13) << "type" << "= " << type << endl;
	cout << setw(13) << "capacity" << "= " << capacity << endl;
}

Shop::Shop(string name, vector<Item*> items)
	:name(name), items(items) {}

void Shop::ShowItemList()
{
	cout << "\n" << name;
	cout << "\n- Item List -\n";
	

	for_each(begin(items), end(items), [](const Item* itemptr) {
		itemptr->Describe();
		cout << "\n";
	});
}