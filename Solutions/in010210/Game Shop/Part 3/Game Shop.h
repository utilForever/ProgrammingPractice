#pragma once

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Item;

class Shop
{
private:
	string name;
	vector<Item*> items;
	
public:
	explicit Shop(string name, vector<Item*> items);
	void ShowItemList();
};

class Item
{
protected:
	string name;
	string description;
	int weight;
	int value;
public:
	Item(string name, string description, int weight, int value);
	virtual void Describe() const;
};


class Weapon :public Item
{
private:
	int damage;
public:
	Weapon(string name, string description, int weight, int value, int damage);
	virtual void Describe() const override;
};

class Armor :public Item
{
private:
	int defense;
public:
	Armor(string name, string description, int weight, int value, int defense);
	virtual void Describe() const override;
};

class Potion :public Item
{
private:
	string type;
	int capacity;
public:
	Potion(string name, string description, int weight, int value, string type, int capacity);
	virtual void Describe() const override;
};