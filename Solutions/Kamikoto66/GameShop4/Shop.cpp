#include <iostream>
#include <sstream>
#include "Shop.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);


Shop::Shop()
{
}

Shop::Shop(std::string name, std::list<Item*> items)
	:_name(name), _items(items)
{
}

Shop::Shop(std::string name, std::string fileName)
	: _name(name), _fileName(fileName)
{
		_inputStream.open(fileName.c_str());
		if (_inputStream.is_open())
			ReadDataFromFile();
		else if (!_inputStream.is_open())
			cout << "File Read Error!!" << endl;
}


Shop::~Shop()
{
	_inputStream.close();

	for (auto itr = _items.begin(); itr != _items.end();)
	{
		delete (*itr);
		itr = _items.erase(itr);
	}
}

void Shop::ShowItemList()
{
	int Select = 0;

	std::cout << "\n";
	std::cout << "Welcome To " <<_name .c_str() << std::endl;
	std::cout << "-------------------------------" << endl;

	cout << "1. Show Item List" << endl;
	cout << "2. Exit" << endl;
	cout << "Select: ";
	cin >> Select;

	if (Select == 1)
	{
		std::cout << "\n";
		std::cout << "- Item List -" << std::endl;

		for each (auto var in _items)
		{
			var->Describe();
		}
	}
}

void Shop::ReadDataFromFile()
{
	vector<string> fileData;

	if (_inputStream.is_open())
	{
		string line;

		while (getline(_inputStream, line)) 
		{
			fileData.push_back(line);
		}
	}

	for each(string var in fileData)
	{
		vector<string> splitData = split(var, ',');

		if (splitData[0] == "Weapon")
		{
			Weapon* w = new Weapon();
			w->SetName(splitData[static_cast<int>(ItemIndex::eName)]);
			w->SetDes(splitData[static_cast<int>(ItemIndex::eDescription)]);
			w->SetWeight(std::atoi(splitData[static_cast<int>(ItemIndex::eWeight)].c_str()));
			w->SetValue(std::stoi(splitData[static_cast<int>(ItemIndex::eValue)].c_str()));
			w->SetDamage(std::stoi(splitData[static_cast<int>(WeaponIndex::eDamage)].c_str()));
			_items.push_back(w);
		}
		else if (splitData[0] == "Armor")
		{
			Armor* a = new Armor();
			a->SetName(splitData[static_cast<int>(ItemIndex::eName)]);
			a->SetDes(splitData[static_cast<int>(ItemIndex::eDescription)]);
			a->SetWeight(std::atoi(splitData[static_cast<int>(ItemIndex::eWeight)].c_str()));
			a->SetValue(std::stoi(splitData[static_cast<int>(ItemIndex::eValue)].c_str()));
			a->SetDefense(std::stoi(splitData[static_cast<int>(ArmorIndex::eDefense)].c_str()));
			_items.push_back(a);
		}
		else if (splitData[0] == "Potion")
		{
			Potion* p = new Potion();
			p->SetName(splitData[static_cast<int>(ItemIndex::eName)]);
			p->SetDes(splitData[static_cast<int>(ItemIndex::eDescription)]);
			p->SetWeight(std::atoi(splitData[static_cast<int>(ItemIndex::eWeight)].c_str()));
			p->SetValue(std::stoi(splitData[static_cast<int>(ItemIndex::eValue)].c_str()));
			p->SetType(splitData[static_cast<int>(PotionIndex::eType)]);
			p->SetCapacity(std::atoi(splitData[static_cast<int>(PotionIndex::eCapacity)].c_str()));
			_items.push_back(p);
		}
		//예외
		else
		{
			cout << "Item Type Unknown" << endl;
		}
	}
}

//출처 https://github.com/ekg/split
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	return split(s, delim, elems);
}