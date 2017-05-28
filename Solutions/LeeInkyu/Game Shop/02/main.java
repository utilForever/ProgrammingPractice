/**
 * Created by Inkyu Lee on 2017-05-28.
 */
public class main {
    public static void main(String args[])
    {
        Weapon Excalibur = new Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24);
        Armor SteelArmor = new Armor("Steel Armor", "Protective covering made by steel", 15, 805, 18);

        Excalibur.Describe();
        SteelArmor.Describe();
    }
}
