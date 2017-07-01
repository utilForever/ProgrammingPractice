/**
 * Created by Inkyu Lee on 2017-05-28.
 */
public class main {
    public static void main(String args[])
    {
        Item Excalibur = new Item("Excalibur", "The legendary sword of King Arthur", 12, 1024);
        Item SteelArmor = new Item("Steel Armor", "Protective covering made by steel", 15 , 805);
        Excalibur.Describe();
        SteelArmor.Describe();
    }
}
