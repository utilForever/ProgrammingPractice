#pragma once
#include <string>

using namespace std;

class Item
{
private:
	string _name;
	string _description;
	int _weight;
	int _value;

public:
	Item();
	Item(string name, string description, int weight, int value);
	~Item();

	virtual void Describe();
};

