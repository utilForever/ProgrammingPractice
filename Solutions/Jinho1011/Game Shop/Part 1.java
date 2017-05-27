package test;

class Item {
    private String name;
    private String description;
    private int weight;
    private int value;

    public Item(String name, String description, int weight, int value) {
        this.name = name;
        this.description = description;
        this.weight = weight;
        this.value = value;
    }

    public void Describe() {
        System.out.println("Name        = "+name+"");
        System.out.println("Description = "+description+"");
        System.out.println("Weight      = "+weight+" lbs");
        System.out.println("Value       = "+value+" gold coins\n");
    }
}

class ItemTest {
    public  static void main (String args []) {
        Item weapon, armor;
        weapon = new Item ("Excalibur", "The legendary sword of King Arthur",12,1024);
        weapon.Describe();


        armor = new Item ("Steel Armor","Protective covering made by steel",15,805);
        armor.Describe();
    }
}
