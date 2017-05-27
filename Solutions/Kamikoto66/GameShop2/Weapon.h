#pragma once

class Item;

class Weapon : public Item
{
private:
	int _damage;
	
public:
	Weapon();
	Weapon(string name, string description, int weight, int value, int damage);
	virtual ~Weapon();

	virtual void Describe() override;
};

