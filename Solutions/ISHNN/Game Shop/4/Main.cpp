#include <iostream>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Shop.h"

int Selection_Main();	//메뉴 선택창을 출력하는 함수

int main() {
	Shop WAshop("Weapon/Armor Shop", "equip_item.txt");
	Shop Pshop("Potion Shop", "potion_item.txt");
	while (true) {
		bool exit = false;

		switch (Selection_Main())
		{
		case 1: {
			WAshop.LoadShop();	break;
		}
		case 2: {
			Pshop.LoadShop();	break;
		}
		case 3: {
			exit = true;		break;
		}
		default:
			std::cout << "Invaild number! Try again" << std::endl;
		}

		if (exit) break;
	}
}

int Selection_Main() {
	int select;
	std::cout << "- Shop Select -" << std::endl;
	std::cout << "     1. Weapon/Armor Shop" << std::endl;
	std::cout << "     2. Potion Shop" << std::endl;
	std::cout << "     3. Exit" << std::endl;
	std::cout << std::endl;

	std::cout << "Select : ";
	std::cin >> select;
	std::cout << std::endl;

	return select;
}