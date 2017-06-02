/**
 * Created by Inkyu Lee on 2017-05-30.
 */
public class Shop {
	String name;
	Item[] items;
	int ARR_MAX = 5;


	public Shop(String namePm, Item[] itemsPm)
	{
		this.name = namePm;
		this.items = itemsPm;
	}

	public Shop(String namePm, Item[] itemsPm, int arrMaxPm)
	{
		this.name = namePm;
		this.items = itemsPm;
		this.ARR_MAX = arrMaxPm;
	}

	public void showItemList()
	{
		System.out.println("Welcome to " + this.name + "!");
		for(int i=0; i<ARR_MAX; i++)
		{
			this.items[i].describe();
		}
	}
}
