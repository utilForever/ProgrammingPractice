package JunkyDragon.GameShop.Part2;

/**
 * Created by JunkyDragon on 2017-05-25.
 */
public class Item {
    private String name;
    private String description;
    private int weight;
    private int value;

    public Item(){}

    public Item(String name, String description, int weight, int value) {
        this.name = name;
        this.description = description;
        this.weight = weight;
        this.value = value;
    }
    public void Describe() {
        System.out.println("Name\t\t\t = " +this.name);
        System.out.println("Description\t\t = " +this.description);
        System.out.println("Weight\t\t\t = " +this.weight + " lbs");
        System.out.println("Value\t\t\t = " +this.value + " gold coins");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    public String toString() {
        return "Name\t\t\t = " + this.name + "\nDescription\t\t = " + this.description + "\nWeight\t\t\t = " + this.weight + " lbs\nValue\t\t\t = " + this.value + "gold coins";
    }
}
