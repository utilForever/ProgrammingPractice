/**
 * 
 */
package whiteWeed.gameShop;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_ItemTest2
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 5. 29.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class ItemTest2 {
	public static void main(String[] args) {
		Item[] items = {
				new Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24),
				new Armor("Steel Armor", "Protective covering made by steel", 15, 805, 18)
		};
		
		for(Item item : items){
			item.describe();
			System.out.println();
		}
	}
}
