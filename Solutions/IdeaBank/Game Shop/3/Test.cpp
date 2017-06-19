#include"ShopClass.h"

int main()
{
	//Init
	std::vector<Item*> waShopItems;
	std::vector<Item*> potionShopItems;

	waShopItems.push_back(new Weapon("Sword", "Medium DMG", 3, 10, 10));
	waShopItems.push_back(new Armor("Cap", "Light Armor", 1, 5, 5));
	waShopItems.push_back(new Weapon("Gloves", "Light Armor", 1, 5, 5));
	waShopItems.push_back(new Weapon("Axe", "High DMG", 5, 15, 15));

	potionShopItems.push_back(new Potion("Small Health Potion", "Recovery 100 HP", 2, 5, "Health", 100));
	potionShopItems.push_back(new Potion("Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50));
	potionShopItems.push_back(new Potion("Medium Health Potion", "Recovery 100 HP", 4, 120, "Health", 200));
	potionShopItems.push_back(new Potion("Medium Mana Potion", "Recovery 100 MP", 2, 75, "Mana", 100));
	potionShopItems.push_back(new Potion("Large Mana Potion", "Recovery 300 HP", 6, 200, "Health", 300));

	Shop waShop = Shop("Weapon/Armor Shop", waShopItems);
	Shop potionShop = Shop("Potion Shop", potionShopItems);

	int select;

	//Get Select From User
	do {
		std::cout << std::endl << "- Shop Select - " << std::endl;
		std::cout << "\t1. Weapon/Armor Shop" << std::endl;
		std::cout << "\t2. Potion Shop" << std::endl;
		std::cout << "\t3. Exit" << std::endl << std::endl;
		std::cout << "Select : ";
		std::cin >> select;
		std::cout << std::endl;
		switch (select)
		{
		case 1:
			waShop.ShowItemList();
			break;
		case 2:
			potionShop.ShowItemList();
			break;
		case 3:
			break;
		default:
			std::cout << "Invalid Number! Try again." << std::endl;
		}
	} while (select != 3);

	//deallocate memory
	std::vector<Item*>::iterator i;
	for (i = waShopItems.begin(); i != waShopItems.end(); ++i)
	{
		delete (*i);
		*i = 0;
	}
	waShopItems.clear();
	for (i = potionShopItems.begin(); i != potionShopItems.end(); ++i)
	{
		delete (*i);
		*i = 0;
	}
	potionShopItems.clear();
}
