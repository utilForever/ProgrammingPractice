package JunkyDragon.GameShop.Part2;

/**
 * Created by Administrator on 2017-05-25.
 */
public class Armor extends Item{
    private int defence;
    public Armor(){super();}
    public Armor(String name, String description, int weight, int value, int defence) {
        super(name, description, weight, value);
        this.defence = defence;
    }
    public void Describe() {
        System.out.println("Name\t\t\t = " +super.getName());
        System.out.println("Description\t\t = " +super.getDescription());
        System.out.println("Weight\t\t\t = " + super.getWeight() + " lbs");
        System.out.println("Value\t\t\t = " + super.getValue() + " gold coins");
        System.out.println("Defence\t\t\t = " + this.defence);
    }
    public String toString() {
        return "Name\t\t\t = " + super.getName() + "\nDescription\t\t = " + super.getDescription() +
                "\nWeight\t\t\t = " + super.getWeight() + " lbs\nValue\t\t\t = " + super.getValue() + "gold coins" +
                "\nDefence\t\t\t = " + this.defence;
    }
}
