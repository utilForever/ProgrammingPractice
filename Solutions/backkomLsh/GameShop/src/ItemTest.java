/**
 * Created by Administrator on 2017-05-22.
 */
public class ItemTest
{
    public static void main(String args[])
    {
        Item i1 = new Item("Excalibur", "The legendary sword of King Arthur", 12, 1024);
        Item i2 = new Item("Steel Armor", "Protective covering made by steel", 15, 805);

        i1.describe();
        i2.describe();
    }
}
