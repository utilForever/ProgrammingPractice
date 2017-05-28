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

    public void Describe()
    {
        System.out.println("Name        = " + this.name);
        System.out.println("Description = " + this.description);
        System.out.println("Weight      = " + this.weight + " lbs");
        System.out.println("Value       = " + this.value + " gold coins");
        System.out.println("Damage      = " + this.damage);
        System.out.println();
    }
}
