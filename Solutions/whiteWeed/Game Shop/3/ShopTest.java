/**
 * 
 */
package whiteWeed.gameShop;

import java.util.*;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_ShopTest
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 6. 5.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class ShopTest {
	private static Item[][] items = {
			{
				new Weapon("Sword", "Medium DMG", 3, 10, 10),
				new Armor("Cap", "Light Armor", 1, 5, 5),
				new Armor("Gloves", "Light Armor", 1, 5, 5),
				new Weapon("Axe", "High DMG", 5, 15, 15),
				new Armor("Boots", "Light Armor", 1, 5, 5)
			},
			{
				new Potion("Small Health Potion", "Recovery 100 HP", 2, 5, "Health", 100),
				new Potion("Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50),
				new Potion("Medium Health Potion", "Recovery 200 HP", 4, 120, "Health", 200),
				new Potion("Medium Mana Potion", "Recovery 100 MP", 2, 75, "Mana", 100),
				new Potion("Large Health Potion", "Recovery 300 HP", 6, 200, "Health", 300)
			}
	};
	private static Shop[] shops = {
			new Shop("Weapon/Armor", items[0]),
			new Shop("Potion", items[1])
	};
	
	private static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		select();
		sc.close();
	}
	
	public static void select(){
		System.out.println("- Shop Select -");
		System.out.println("   1. Weapon/Armor Shop");
		System.out.println("   2. Potion Shop");
		System.out.println("   3. Exit");
		System.out.println();
		System.out.println("Select : ");
		int selection = sc.nextInt();
		
		switch(selection){
		case 1:
			shops[0].showItemList();
			select();
			break;
		case 2:
			shops[1].showItemList();
			select();
			break;
		case 3:
			break;
		default:
			System.out.println("Invalid number! Try again.");
			select();
			break;
		}
	}
}
