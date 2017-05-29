/**
 * 
 */
package whiteWeed.gameShop;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_Armor
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 5. 29.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class Armor extends Item {
	private int defence;
	
	public Armor(String name, String description, int weight, int value, int defence){
		super(name, description, weight, value);
		this.defence = defence;
	}
	
	public void describe(){
		System.out.println("Name          = " + super.name);
		System.out.println("Description = " + super.description);
		System.out.println("Weight        = " + super.weight + " lbs");
		System.out.println("Value           = " + super.value + " gold coins");
		System.out.println("Defence       = " + this.defence);
		System.out.println();
	}
}
