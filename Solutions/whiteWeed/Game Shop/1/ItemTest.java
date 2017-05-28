/**
 * 
 */
package whiteWeed.gameShop;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_ItemTest
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 5. 18.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class ItemTest {
	public static void main(String[] args) {
		Item[] items = {
				new Item("Excalibur", "The legendary sword of King Arthur", 12, 1024),
				new Item("Steel Armor", "Protective covering made by steel", 15, 805)
		};
		
		for(Item item : items){
			item.Describe();
		}
	}
}
