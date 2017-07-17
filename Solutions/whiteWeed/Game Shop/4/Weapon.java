/**
 * 
 */
package whiteWeed.gameShop;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_Weapon
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 5. 29.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class Weapon extends Item {
	private int damage; //ㅁㄴㅇㄹ
	
	public Weapon(String name, String description, int weight, int value, int damage){
		super(name, description, weight, value);
		this.damage = damage;
	}
	
	public void describe(){
		super.describe();
		System.out.println("Damage        = " + this.damage);
	}
}
