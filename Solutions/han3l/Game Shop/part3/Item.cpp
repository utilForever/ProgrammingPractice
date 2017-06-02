#include "Item.h"

// constructor
Item::Item()
{
}

Item::~Item()
{
}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

Armor::Armor()
{
}

Armor::~Armor()
{
}

Potion::Potion()
{
}

Potion::~Potion()
{
}

Item::Item(std::string name, std::string description, int weight, int value) 
	: name(name), description(description), weight(weight), value(value)
{
}

Weapon::Weapon(std::string name, std::string description, int weight, int value, int damage)
	: Item(name, description, weight, value), damage(damage)
{
}

Armor::Armor(std::string name, std::string description, int weight, int value, int defense)
	: Item(name, description, weight, value), defense(defense)
{
}

Potion::Potion(std::string name, std::string description, int weight, int value, std::string type, int capacity)
	: Item(name, description, weight, value), type(type), capacity(capacity)
{
}

void Item::Describe()
{
	std::cout << "Name\t\t= " << this->name << std::endl;
	std::cout << "Description\t= " << this->description << std::endl;
	std::cout << "Weight\t\t= " << this->weight << " lbs" << std::endl;
	std::cout << "Value\t\t= " << this->value << " gold coins" << std::endl;
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

void Potion::Describe()
{
	Item::Describe();
	std::cout << "Type\t\t= " << this->type << std::endl;
	std::cout << "Capacity\t= " << this->capacity << std::endl << std::endl;
}