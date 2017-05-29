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
	~Weapon();
	Weapon(std::string name, std::string description, int weight, int value, int damage);
	void Describe();
private:
	int damage;
};

class Amor : public Item
{
public:
	Amor();
	~Amor();
	Amor(std::string name, std::string description, int weight, int value, int defense);
	void Describe();
private:
	int defense;
};
