#include<iostream>
#include<string>

class Item{
public:
	Item() = default;
	Item(std::string, std::string, int, int);
	virtual void Describe();
protected:
	std::string name;
	std::string description;
	int weight;
	int value;
};
class Weapon :public Item {
public:
	Weapon() = default;
	Weapon(std::string, std::string, int, int, int);
	void Describe();
private:
	int damage;
};
class  Armor:public Item {
public:
	Armor() = default;
	Armor(std::string, std::string, int, int, int);
	void Describe();
private:
	int defense;
};

Item::Item(std::string name, std::string description, int weight, int value)
{
	this->name = name;
	this->description = description;
	this->weight = weight;
	this->value = value;
}
void Item::Describe()
{
	std::cout << "Name\t\t= " << this->name << std::endl;
	std::cout << "Description\t= " << this->description << std::endl;
	std::cout << "Weight\t\t= " << this->weight << " lbs" << std::endl;
	std::cout << "Value\t\t= " << this->value << " gold coins" << std::endl << std::endl;
}
Weapon::Weapon(std::string name, std::string description, int weight, int value, int damage)
{
	this->name = name;
	this->description = description;
	this->weight = weight;
	this->value = value;
	this->damage = damage;
}
void Weapon::Describe()
{
	std::cout << "Name\t\t= " << this->name << std::endl;
	std::cout << "Description\t= " << this->description << std::endl;
	std::cout << "Weight\t\t= " << this->weight << " lbs" << std::endl;
	std::cout << "Value\t\t= " << this->value << " gold coins" << std::endl;
	std::cout << "Damage\t\t= " << this->damage << std::endl << std::endl;
}
Armor::Armor(std::string name, std::string description, int weight, int value, int defense)
{
	this->name = name;
	this->description = description;
	this->weight = weight;
	this->value = value;
	this->defense = defense;
}
void Armor::Describe()
{
	std::cout << "Name\t\t= " << this->name << std::endl;
	std::cout << "Description\t= " << this->description << std::endl;
	std::cout << "Weight\t\t= " << this->weight << " lbs" << std::endl;
	std::cout << "Value\t\t= " << this->value << " gold coins" << std::endl;
	std::cout << "Defense\t\t= " << this->defense << std::endl << std::endl;
}
