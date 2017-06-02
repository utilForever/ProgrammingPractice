/**
 * Created by Inkyu Lee on 2017-05-30.
 */
public class Potion extends Item {
	String type;
	int capacity;

	public Potion(String namePm, String descriptionPm, int weightPm, int valuePm, String typePm, int capacityPm)
	{
		super(namePm, descriptionPm, weightPm, valuePm);
		this.type = typePm;
		this.capacity = capacityPm;
	}

	public void describe()
	{
		super.describe();
		System.out.println("Type        = " + this.type);
		System.out.println("Capacity    = " + this.capacity);
		System.out.println();
	}
}
