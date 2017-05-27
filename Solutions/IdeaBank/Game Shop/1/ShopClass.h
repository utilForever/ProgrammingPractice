#include<iostream>
#include<string>

class Item {
public:
	Item() = default;
	Item(std::string, std::string, int, int);
	void Describe();
protected:
	std::string name;
	std::string description;
	int weight;
	int value;
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
