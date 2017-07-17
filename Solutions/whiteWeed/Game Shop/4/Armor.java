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
public class Armor extends Item { //ㅁㄴㅇㄹ
	private int defence;
	
	public Armor(String name, String description, int weight, int value, int defence){
		super(name, description, weight, value);
		this.defence = defence;
	}
	
	public void describe(){
		super.describe();
		System.out.println("Defence       = " + this.defence);
	}
}
