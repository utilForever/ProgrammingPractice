/**
 * 
 */
package whiteWeed.gameShop;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_Item
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 5. 18.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class Item {
	protected String name, description;
	protected int weight, value;
	
	public Item(String name, String description, int weight, int value){
		this.name = name;
		this.description = description;
		this.weight = weight;
		this.value = value;
	}
	
	public void describe(){
		System.out.println("Name          = " + this.name);
		System.out.println("Description = " + this.description);
		System.out.println("Weight        = " + this.weight + " lbs");
		System.out.println("Value           = " + this.value + " gold coins");
		System.out.println();
	}
}
