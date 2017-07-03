/**
 * 
 */
package whiteWeed.gameShop;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_Potion
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 6. 5.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class Potion extends Item {
	String type;
	int capacity;
	
	public Potion(String name, String description, int weight, int value, String type, int capacity){
		super(name, description, weight, value);
		this.type = type;
		this.capacity = capacity;
	}
	
	public void describe(){
		super.describe();
		System.out.println("Type          = " + this.type);
		System.out.println("Capacity      = " + this.capacity);
	}
}
