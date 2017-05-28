#include "Item.h"

#include <iostream>
#include <iomanip>

Item::Item(string name, string description, int weight, int value)
	:name(name), description(description), weight(weight), value(value)
{
}

void Item::Describe()
{
	cout.setf(ios::left);
	cout << setw(13) << "Name" << "= " << name << endl;
	cout << setw(13) << "Description" << "= " << description << endl;
	cout << setw(13) << "Weight" << "= " << weight << endl;
	cout << setw(13) << "Value" << "= " << value << endl;
}