#pragma once
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <string>

class Item;

class Shop
{
private:
	std::string _name;
	std::list<Item*> _items;
	std::string _fileName;
	std::ifstream _inputStream;

private:
	void ReadDataFromFile();

public:
	Shop();	
	Shop(std::string name, std::list<Item*> items);
	Shop(std::string name, std::string fileName);
	~Shop();

	void ShowItemList();
};

