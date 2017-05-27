#include "Item.h"

#include <iostream>
#include <iomanip>

Item::Item(string name, string description, int weight, int value)
	:name(name), description(description), weight(weight), value(value) {}

void Item::Describe()
{
	cout.setf(ios::left);
	cout << setw(13) << "Name" << "= " << name << endl;
	cout << setw(13) << "Description" << "= " << description << endl;
	cout << setw(13) << "Weight" << "= " << weight << endl;
	cout << setw(13) << "Value" << "= " << value << endl;
	cout << "\n";
}

Weapon::Weapon(string name, string description, int weight, int value, int damage)
	: damage(damage), Item(name, description, weight, value) {}

void Weapon::Describe()
{
	cout.setf(ios::left);
	cout << setw(13) << "Name" << "= " << name << endl;
	cout << setw(13) << "Description" << "= " << description << endl;
	cout << setw(13) << "Weight" << "= " << weight << endl;
	cout << setw(13) << "Value" << "= " << value << endl;
	cout << setw(13) << "Damage" << "= " << damage << endl;
	cout << "\n";
}


Armor::Armor(string name, string description, int weight, int value, int defense)
	: defense(defense), Item(name, description, weight, value) {}

void Armor::Describe()
{
	cout.setf(ios::left);
	cout << setw(13) << "Name" << "= " << name << endl;
	cout << setw(13) << "Description" << "= " << description << endl;
	cout << setw(13) << "Weight" << "= " << weight << endl;
	cout << setw(13) << "Value" << "= " << value << endl;
	cout << setw(13) << "Defense" << "= " << defense << endl;
	cout << "\n";
}