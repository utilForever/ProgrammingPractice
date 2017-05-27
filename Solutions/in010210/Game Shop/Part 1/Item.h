#pragma once

#include <string>
using namespace std;

class Item
{
private:
	string name;
	string description;
	int weight;
	int value;
public:
	Item(string name, string description, int weight, int value);
	void Describe();
};