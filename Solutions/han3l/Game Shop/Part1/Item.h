#pragma once
#include <iostream>
#include <string>

class Item
{
public:
	Item();
	~Item();
	Item(std::string name, std::string description, int weight, int value);
	void Describe();
protected:
	std::string name;
	std::string description;
	int weight;
	int value;
};