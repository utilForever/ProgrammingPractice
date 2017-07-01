/**
 * Created by Inkyu Lee on 2017-05-30.
 */


public class Armor extends Item{
	int defense;

	public Armor(String namePm, String descriptionPm, int weightPm, int valuePm, int defensePm)
	{
		super(namePm, descriptionPm, weightPm, valuePm);
		this.defense = defensePm;
	}

	public void describe()
	{
		super.describe();
		System.out.println("Defense     = " + this.defense);
		System.out.println();
	}
}
