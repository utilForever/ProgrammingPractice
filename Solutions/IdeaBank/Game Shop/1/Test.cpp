int main()
{
	Item *a[2];
	a[0] = new Item("Excalibur", "The legendary sword of King Arthur", 12, 1024);
	a[1] = new Item("Steel Armor", "Protective covering made by steel", 15, 805);
	a[0]->Describe();
	a[1]->Describe();
}
