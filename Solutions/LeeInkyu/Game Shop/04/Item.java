/**
 * Created by Inkyu Lee on 2017-05-28.
 */
public class Item {
    String name, description;
    int weight, value;

    public Item() {}

    public Item(String namePm, String descriptionPm, int weightPm, int valuePm)
    {
        this.name = namePm;
        this.description = descriptionPm;
        this.weight = weightPm;
        this.value = valuePm;
    }

    public void describe()
    {
        System.out.println("Name        = " + this.name);
        System.out.println("Description = " + this.description);
        System.out.println("Weight      = " + this.weight + " lbs");
        System.out.println("Value       = " + this.value + " gold coins");
    }
}

