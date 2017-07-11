#pragma once
#include <iostream>
#include <string>

class Item
{
public:
	Item(std::string, std::string, int, int);
	void Describe();

protected:
	std::string name;
	std::string description;
	int weight;
	int value;
};