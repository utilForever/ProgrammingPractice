#include "Shop.h"

int main()
{
	Item* Exalibur = new Item("Excalibur", "The legendary sword of King Arthur", 12, 1024);
	Exalibur->Describe();

	Item STeel_Armor("Steel Armor", "Protective covering made by steel", 15, 805);
	STeel_Armor.Describe();
}