#include "Shop.h"
#include "Item.h"

void ShopMenu();

int main()
{
	std::list<Item*> equipments;

	equipments.push_back(new Weapon("Sword", "Medium DMG", 3, 10, 10));
	equipments.push_back(new Armor("Cap", "Light Armor", 1, 5, 5));
	equipments.push_back(new Armor("Gloves", "Light Armor", 1, 5, 5));
	equipments.push_back(new Weapon("Axe", "High DMG", 5, 15, 15));
	equipments.push_back(new Armor("Boots", "Light Armor", 1, 5, 5));

	Shop* equipmentShop = new Shop("Weapon/Armor Shop!", equipments);

	std::list<Item*> potions;

	potions.push_back(new Potion("Small Health Potion", "Recovery 100 HP", 2, 5, "Health", 100));
	potions.push_back(new Potion("Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50));
	potions.push_back(new Potion("Medium Health Potion", "Recovery 200 HP", 4, 120, "Health", 200));
	potions.push_back(new Potion("Medium Mana Potion", "Recovery 100 MP", 2, 75, "Mana", 100));
	potions.push_back(new Potion("Large Health Potion", "Recovery 300 HP", 6, 200, "Health", 300));
	
	Shop* potionShop = new Shop("Potion Shop!", potions);

	int shopType;

	while (true)
	{
		ShopMenu();
		std::cin >> shopType;
		std::cout << std::endl;

		if (shopType == 1)
		{
			equipmentShop->ShowItemList();
		}
		else if (shopType == 2)
		{
			potionShop->ShowItemList();
		}
		else if (shopType == 3)
		{
			break;
		}
		else
		{
			std::cout << "Invalid number! Try again." << std::endl << std::endl;
		}
	}

	delete equipmentShop;
	delete potionShop;

	return 0;
}

void ShopMenu()
{
	std::cout << "- Shop Select -" << std::endl;
	std::cout << "\t1. Weapon/Armor Shop" << std::endl;
	std::cout << "\t2. Potion Shop" << std::endl;
	std::cout << "\t3. Exit" << std::endl << std::endl;
	std::cout << "Select : ";
}