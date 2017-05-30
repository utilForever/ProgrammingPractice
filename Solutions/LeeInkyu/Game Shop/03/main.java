/**
 * Created by Inkyu Lee on 2017-05-28.
 */

import java.util.*;

public class main {

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		final int ITEM_ARR_MAX = 5;
		int input_tmp;

		Item[] WeaponsAndArmors = new Item[ITEM_ARR_MAX];
		Item[] Potions = new Potion[ITEM_ARR_MAX];

		WeaponsAndArmors[0] = new Weapon("Sword", "Medium DMG", 3, 10, 10);
		WeaponsAndArmors[1] = new Armor("Cap", "Light Armor", 1, 5, 5);
		WeaponsAndArmors[2] = new Armor("Gloves", "Light Armor", 1, 5, 5);
		WeaponsAndArmors[3] = new Weapon("Axe", "High DMG", 5, 15, 15);
		WeaponsAndArmors[4] = new Armor("Boots", "Light Armor", 1, 5, 5);
    
		Potions[0] = new Potion("Small Health Potion", "Recovery 100 HP", 2, 5, "Health", 100);
		Potions[1] = new Potion("Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50);
		Potions[2] = new Potion("Medium Health Potion", "Recovery 200 HP", 4, 120, "Health", 200);
		Potions[3] = new Potion("Medium Mana Potion", "Recovery 100 MP", 2, 75, "Mana", 100);
		Potions[4] = new Potion("Large Health Potion", "Recovery 300 HP", 6, 200, "Health", 300);

		Shop WeaponsAndArmorsShop = new Shop("Weapon / Armor Shop", WeaponsAndArmors, WeaponsAndArmors.length);
		Shop PotionsShop = new Shop("Potions Shop", Potions, Potions.length);

		MAIN_MENU: //메인메뉴 처리 레이블
		for(;;)
		{
			System.out.println("- Shop Select -");
			System.out.println("1. Weapon/Armor Shop");
			System.out.println("2. Potion Shop");
			System.out.println("3. Exit");
			System.out.println("Select : ");
			input_tmp = sc.nextInt();

			switch(input_tmp)
			{
				case 1: //무기 방어구 상점
					WeaponsAndArmorsShop.showItemList();
					break;
				case 2: //포션 상점
					PotionsShop.showItemList();
					break;
				case 3:
					break MAIN_MENU;
				default:
					System.out.println("Invalid number! Try again.");

			}
		}
	}
}
