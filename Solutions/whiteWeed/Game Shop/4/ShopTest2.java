/**
 * 
 */
package whiteWeed.gameShop;

import java.util.Scanner;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_ShopTest2
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 7. 3.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class ShopTest2 {
	private static Shop[] shops = {
			new Shop("Weapon/Armor", "equip_item.txt"),
			new Shop("Potion", "potion_item.txt")
	};
	
	private static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		boolean end = true;
		while(end) {
			end = select();
		}
		sc.close();
	}
	
	public static boolean select(){
		System.out.println("- Shop Select -");
		System.out.println("   1. Weapon/Armor Shop");
		System.out.println("   2. Potion Shop");
		System.out.println("   3. Exit");
		System.out.println();
		System.out.print("Select : ");
		int selection = sc.nextInt();
		sc.reset();
		
		if(selection > 3 || selection <= 0){
			System.out.println("Invalid number! Try again.");
			return true;
		}
		else if(selection <= 2){
			shops[selection - 1].showItemArrayList();
			return true;
		}
		return false;
	}
}
