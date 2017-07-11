#pragma once

class Item;

enum class WeaponIndex
{
	eDamage = 5
};

class Weapon : public Item
{
private:
	int _damage;
	
public:
	Weapon();
	Weapon(string name, string description, int weight, int value, int damage);
	virtual ~Weapon();

	virtual void Describe() override;

	void SetDamage(int damage) { _damage = damage; }
};

