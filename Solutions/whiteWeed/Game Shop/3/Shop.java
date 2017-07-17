/**
 * 
 */
package whiteWeed.gameShop;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_Shop
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 6. 5.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class Shop {
	String name;
	Item[] items;
	
	public Shop(String name, Item[] items){
		this.name = name;
		this.items = items;
	}
	
	public void showItemList(){
		System.out.println("Welcome to " + this.name + " Shop!");
		System.out.println("- Item List -");
		for(Item item : items){
			item.describe();
			System.out.println();
		}
	}
}
