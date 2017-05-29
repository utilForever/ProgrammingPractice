#include "Item.h"

int main()
{
	Item* item = new Item("Excalibur", "The legendart sword of King Arthur", 12, 1204);
	item->Describe();
	
	item = new Item("Steel Armor", "Protective covering made by steel", 15, 805);
	item->Describe();
	
	delete item;

    return 0;
}



