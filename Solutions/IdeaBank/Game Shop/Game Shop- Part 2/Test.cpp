#include"ShopClass.h"

int main()
{
	Item* item = new Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24);
	item->Describe();

	item = new Armor("Steel Armor", "Protective covering made by steel", 15, 805, 18);
	item->Describe();
}
