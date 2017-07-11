#include "Armor.h"
#include "Weapon.h"

int main()
{
	Item* item = new Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24);
	item->Describe();
	delete item;

	std::cout << std::endl;

	item = new Armor("Steel Armor", "Protective covering made by steel", 15, 805, 18);
	item->Describe();
	delete item;
}