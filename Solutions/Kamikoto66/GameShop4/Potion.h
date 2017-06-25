#pragma once
#include "Item.h"

enum class PotionIndex
{
	eType = 5,
	eCapacity
};

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

	void SetType(string type) { _type = type; }
	void SetCapacity(int capacity) { _capacity = capacity; }
};

