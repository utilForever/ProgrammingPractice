#pragma once
#include <iostream>

class Item
{
public:
	Item(std::string, std::string, int, int);
	~Item();

	virtual void Describe();

private:
	std::string name;
	std::string descripition;
	int wight;
	int value;
};