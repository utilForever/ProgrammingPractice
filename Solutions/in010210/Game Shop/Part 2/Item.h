#pragma once

#include <string>

using namespace std;

class Item
{
protected:
	string name;
	string description;
	int weight;
	int value;
public:
	Item(string name, string description, int weight, int value);
	virtual void Describe();
};


class Weapon :public Item
{
private:
	int damage;
public:
	Weapon(string name, string description, int weight, int value, int damage);
	virtual void Describe();
};

class Armor :public Item
{
private:
	int defense;
public:
	Armor(string name, string description, int weight, int value, int defense);
	virtual void Describe();
};