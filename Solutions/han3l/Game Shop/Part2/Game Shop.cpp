#include "Item.h"

int main()
{
	Item* item = new Weapon("Excalibur", "The legendart sword of King Arthur", 12, 1204, 24);
	item->Describe();
	
	item = new Amor("Steel Armor", "Protective covering made by steel", 15, 805, 18);
	item->Describe();
	
	delete item;

	return 0;
}


