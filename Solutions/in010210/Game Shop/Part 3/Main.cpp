#pragma once
#include "Game Shop.h"
#include <iostream>

int main()
{
	vector<Item*> WeaponArmorShopList = {
		new Weapon("Sword", "Medium DMG", 3, 10, 10),
		new Armor("Cap", "Light Armor", 1, 5, 5),
		new Armor("Gloves", "Light Armor", 1, 5, 5),
		new Weapon("Axe", "HIgh DMG", 5, 15, 15),
		new Armor("Boots", "Light Armor", 1, 5, 5)
	};
	Shop* WeaponArmorShop = new Shop("\nWelcome to Weapon/Armor Shop!", WeaponArmorShopList);

	vector<Item*> PotionShopList{
		new Potion("Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50),
		new Potion("Medium Health Potion", "Recovery 200 HP", 4, 120, "Health", 200),
		new Potion("Medium Mana Potion", "Recovery 100 MP", 2, 75, "Mana", 100),
		new Potion("Large Health Potion", "Recovery 300 HP", 6, 200, "Health", 300)
	};
	Shop* PotionShop = new Shop("\nWelcome to Potion Shop!", PotionShopList);
	
	int n=0;
	while (n != 3) {
		std::cout << "- Shop Select -\n  1. Weapon/Armor Shop\n  2. Potion Shop\n  3. Exit\n\n Select : ";
		std::cin >> n;
		if(n==1)WeaponArmorShop->ShowItemList();
		else if (n == 2)PotionShop->ShowItemList();
		else if (n != 3)std::cout << "\nInvalid number! Try again\n\n";
	}

	delete WeaponArmorShop;
	delete PotionShop;
}