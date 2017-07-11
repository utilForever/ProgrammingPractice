#pragma once
#include <string>

using namespace std;

enum class ItemIndex
{
	eName = 1,
	eDescription,
	eWeight,
	eValue
};

class Item
{
protected:
	string _name;
	string _description;
	int _weight;
	int _value;

public:
	Item();
	Item(string name, string description, int weight, int value);
	virtual ~Item();

	virtual void Describe();

	void SetName(string name) { _name = name; }
	void SetDes(string des) { _description = des; }
	void SetWeight(int weight) { _weight = weight; }
	void SetValue(int value) { _value = value; }
};

