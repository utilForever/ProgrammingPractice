#pragma once
#include <iostream>
#include <string>

class Item
{
public:
	Item();
	virtual ~Item();
	Item(std::string name, std::string description, int weight, int value);
	virtual void Describe();
protected:
	std::string name;
	std::string description;
	int weight;
	int value;
};

class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();
	Weapon(std::string name, std::string description, int weight, int value, int damage);
	void Describe() override;
private:
	int damage;
};

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();
	Armor(std::string name, std::string description, int weight, int value, int defense);
	void Describe() override;
private:
	int defense;
};

class Potion : public Item
{
public:
	Potion();
	virtual ~Potion();
	Potion(std::string name, std::string description, int weight, int value, std::string type, int capacity);
	void Describe() override;
private:
	std::string type;
	int capacity;
};