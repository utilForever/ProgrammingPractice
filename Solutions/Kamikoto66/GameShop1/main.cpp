#include <iostream>
#include "Item.h"


int main()
{
	Item* item_1 = new Item("Excalibur", "The legendary sword of King Arthur", 12, 1024);
	Item* item_2 = new Item("Steel Armor", "Protective covering made by steel", 15, 805);

	item_1->Describe();
	item_2->Describe();

	delete item_2;
	delete item_1;
}
