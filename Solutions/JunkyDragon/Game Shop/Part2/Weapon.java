package JunkyDragon.GameShop.Part2;

/**
 * Created by Administrator on 2017-05-25.
 */
public class Weapon extends Item{
    private int damage;
    public Weapon(){super();}
    public Weapon(String name, String description, int weight, int value, int damage) {
        super(name, description, weight, value);
        this.damage = damage;
    }
    public void Describe() {
        System.out.println("Name\t\t\t = " +super.getName());
        System.out.println("Description\t\t = " +super.getDescription());
        System.out.println("Weight\t\t\t = " + super.getWeight() + " lbs");
        System.out.println("Value\t\t\t = " + super.getValue() + " gold coins");
        System.out.println("Damage\t\t\t = " + this.damage);
    }
    public String toString() {
        return "Name\t\t\t = " + super.getName() + "\nDescription\t\t = " + super.getDescription() +
                "\nWeight\t\t\t = " + super.getWeight() + " lbs\nValue\t\t\t = " + super.getValue() + "gold coins" +
                "\nDamage\t\t\t = " + this.damage;
    }
}
