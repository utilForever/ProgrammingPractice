#include <iostream>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"

int main()
{
	Item* item_1 = new Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24);
	Item* item_2 = new Armor("Steel Armor", "Protective covering made by steel", 15, 805, 18);

	item_1->Describe();
	item_2->Describe();

	delete item_2;
	delete item_1;
}
