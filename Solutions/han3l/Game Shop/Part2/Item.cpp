#include "Item.h"

Item::Item() {}

Item::~Item() {}

Item::Item(std::string name, std::string description, int weight, int value)
{
	this->name = name;
	this->description = description;
	this->weight = weight;
	this->value = value;
}

Weapon::Weapon() {}

Weapon::~Weapon() {}

Weapon::Weapon(std::string name, std::string description, int weight, int value, int damage)
	: Item(name, description, weight, value)
{
	this->damage = damage;
}

Armor::Armor() {}

Armor::~Armor() {}

Armor::Armor(std::string name, std::string description, int weight, int value, int defense)
	: Item(name, description, weight, value)
{
	this->defense = defense;
}

void Item::Describe()
{
	std::cout << "Name\t\t= " << this->name << std::endl;
	std::cout << "Description\t= " << this->description << std::endl;
	std::cout << "Weight\t\t= " << this->weight << " lbs" << std::endl;
	std::cout << "Value\t\t= " << this->value << " gold coins" << std::endl << std::endl;
}

void Weapon::Describe()
{	
	Item::Describe();
	std::cout << "Damage\t\t= " << this->damage << std::endl << std::endl;
}

void Armor::Describe()
{
	Item::Describe();
	std::cout << "Defense\t\t= " << this->defense << std::endl << std::endl;
}
