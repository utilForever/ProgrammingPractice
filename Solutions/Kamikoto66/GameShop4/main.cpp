#include <iostream>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Shop.h"

using namespace std;

int main()
{
	bool Loop = true;
	int ShopType = 0;

	Shop* WeaponArmorShop = new Shop("Weapon / Armor Shop", "Data//equip_item.txt");
	Shop* PotionShop = new Shop("Potion Shop", "Data//potion_item.txt");

	while (Loop)
	{
		cout << "-Shop Select -" << endl;
		cout << "1. Weapon / Armor Shop" << endl;
		cout << "2. Potion Shop" << endl;
		cout << "3. Exit" << endl;
		cout << "Select : ";
		cin >> ShopType;

		switch (ShopType)
		{
		case 1:	WeaponArmorShop->ShowItemList();	break;
		case 2:	PotionShop->ShowItemList();			break;
		case 3:	Loop = false;  break;
		default:	cout << "Invalid number! Try again." << endl; break;
		}
	}

	delete PotionShop;
	delete WeaponArmorShop;

	system("pause");
	return 0;
}
