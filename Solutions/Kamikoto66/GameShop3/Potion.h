#pragma once
#include "Item.h"
class Potion :
	public Item
{
private:
	string _type;
	int _capacity;

public:
	Potion();
	Potion(string name, string description, int weight, int value, string type, int capacity);
	virtual ~Potion();

	virtual void Describe() override;
};

