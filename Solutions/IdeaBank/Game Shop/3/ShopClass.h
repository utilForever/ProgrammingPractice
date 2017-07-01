#include<iostream>
#include<string>
#include<vector>

class Item {
public:
	Item() = default;
	Item(std::string, std::string, int, int);
	virtual void Describe();
	virtual ~Item() = default;
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
	void Describe() override;
	~Weapon() = default;
private:
	int damage;
};
class  Armor :public Item {
public:
	Armor() = default;
	Armor(std::string, std::string, int, int, int);
	void Describe() override;
	~Armor() = default;
private:
	int defense;
};
class Potion :public Item {
public:
	Potion() = default;
	Potion(std::string, std::string, int, int, std::string, int);
	void Describe() override;
	~Potion() = default;
private:
	std::string type;
	int capacity;
};
class Shop {
public:
	Shop() = default;
	Shop(std::string, std::vector<Item*>&);
	void ShowItemList();
	~Shop() = default;
private:
	std::string name;
	std::vector<Item*> items;
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
	std::cout << "Value\t\t= " << this->value << " gold coins" << std::endl;
}
Weapon::Weapon(std::string name, std::string description, int weight, int value, int damage) : Item(name, description, weight, value)
{
	this->damage = damage;
}
void Weapon::Describe()
{
	Item::Describe();
	std::cout << "Damage\t\t= " << this->damage << std::endl << std::endl << std::endl;
}
Armor::Armor(std::string name, std::string description, int weight, int value, int defense) : Item(name, description, weight, value)
{
	this->defense = defense;
}
void Armor::Describe()
{
	Item::Describe();
	std::cout << "Defense\t\t= " << this->defense << std::endl << std::endl << std::endl;
}
Potion::Potion(std::string name, std::string description, int weight, int value, std::string type, int capacity) : Item(name, description, weight, value)
{
	this->capacity = capacity;
}
void Potion::Describe()
{
	Item::Describe();
	std::cout << "Type\t\t= " << this->type << std::endl;
	std::cout << "Capacity\t= " << this->capacity << std::endl << std::endl;
}
Shop::Shop(std::string name, std::vector<Item*> &items)
{
	this->name = name;
	this->items = items;
}
void Shop::ShowItemList()
{
	std::cout << "Welcome to " << this->name << "!" << std::endl;
	std::cout << "- Item List - " << std::endl;
	for (auto &i : this->items)
	{
		i->Describe();
	}
}
