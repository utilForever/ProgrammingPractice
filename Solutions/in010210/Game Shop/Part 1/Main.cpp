#include "Item.h"

int main()
{
	Item* item = new Item("Excalibur", "The legendary sword of King Arthur", 12, 1024);
	item->Describe();

	Item a("Steel Armor", "Protective covering made by steel", 15, 805);
	a.Describe();
}