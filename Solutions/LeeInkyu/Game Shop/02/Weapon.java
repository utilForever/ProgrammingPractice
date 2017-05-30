/**
 * Created by Inkyu Lee on 2017-05-28.
 */
public class Weapon extends Item
{
    int damage;

    public Weapon(String namePm, String descriptionPm, int weightPm, int valuePm, int damagePm)
    {
        this.name = namePm;
        this.description = descriptionPm;
        this.weight = weightPm;
        this.value = valuePm;
        this.damage = damagePm;
    }

    public void describe()
    {
        super.describe();
        System.out.println("Damage      = " + this.damage);
        System.out.println();
    }
}
