#include <iostream>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Shop.h"

using namespace std;
	
int main()
{
	int ShopType = 0;
	list<Item*> WeaponArmorShopList;
	Shop* WeaponArmorShop;

	WeaponArmorShopList.push_back(new Weapon("Sword", "Medium DMG", 3, 10, 10));
	WeaponArmorShopList.push_back(new Armor("Cap", "Light Armor", 1, 5, 5));
	WeaponArmorShopList.push_back(new Armor("Gloves", "Light Armor", 1, 5, 5));
	WeaponArmorShopList.push_back(new Weapon("Axe", "HIgh DMG", 5, 15, 15));
	WeaponArmorShopList.push_back(new Armor("Boots", "Light Armor", 1, 5, 5));
	WeaponArmorShop = new Shop("Weapon/Armor Shop!", WeaponArmorShopList);


	list<Item*> PotionShopList;
	Shop* PotionShop;

	PotionShopList.push_back(new Potion("Small Health Potion", "Recovery 100 HP", 2, 5, "Health", 100));
	PotionShopList.push_back(new Potion("Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50));
	PotionShopList.push_back(new Potion("Medium Health Potion", "Recovery 200 HP", 4, 120, "Health", 200));
	PotionShopList.push_back(new Potion("Medium Mana Potion", "Recovery 100 MP", 2, 75, "Mana", 100));
	PotionShopList.push_back(new Potion("Large Health Potion", "Recovery 300 HP", 6, 200, "Health", 300));
	PotionShop = new Shop("Potion Shop!", PotionShopList);


	
	while (ShopType != 3)
	{
		cout << "-Shop Select -" << endl;
		cout << "1. Weapon / Armor Shop" << endl;
		cout << "2. Potion Shop" << endl;
		cout << "3. Exit" << endl;
		cin >> ShopType;

		switch (ShopType)
		{
		case 1:	WeaponArmorShop->ShowItemList();	break;
		case 2:	PotionShop->ShowItemList();			break;
		case 3:	cout << "Close Shop" << endl;		break;
		default:	cout << "Invalid number! Try again." << endl; break;
		}
	}

	delete PotionShop;
	delete WeaponArmorShop;

	for (auto itr = WeaponArmorShopList.begin(); itr != WeaponArmorShopList.end();)
	{
		delete (*itr);
		itr = WeaponArmorShopList.erase(itr);
	}

	for (auto itr = PotionShopList.begin(); itr != PotionShopList.end();)
	{
		delete (*itr);
		itr = PotionShopList.erase(itr);
	}

	system("pause");
	return 0;
}
