#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>

using namespace std;

class Item
{
public:
	Item(const string& name, const string& description, const int weight, const int value)
		: name(name), description(description), weight(weight), value(value)
	{

	}

	virtual ~Item() = default;

	virtual void Describe(void) const
	{
		DescribeName();
		DescribeDescription();
		DescribeWeight();
		DescribeValue();
	}

protected:
	static int GetSpaceInfo(void)
	{
		return space;
	}

private:
	string name;
	string description;
	int weight;
	int value;
	static const int space = 12;

	inline void DescribeName(void) const
	{
		cout << left << setw(space) << "Name" << "= " << name << endl;
	}

	inline void DescribeDescription(void) const
	{
		cout << left << setw(space) << "Description" << "= " << description << endl;
	}

	inline void DescribeWeight(void) const
	{
		cout << left << setw(space) << "Weight" << "= " << weight << (weight > 1 ? " lbs" : " lb") << endl;
	}

	inline void DescribeValue(void) const
	{
		cout << left << setw(space) << "Value" << "= " << value << (value > 1 ? " gold coin" : " gold coins") << endl;
	}
};

class Weapon : public Item
{
public:
	Weapon(const string& name, const string& description, const int weight, const int value, const int damage)
		: Item(name, description, weight, value), damage(damage)
	{

	}

	virtual ~Weapon() = default;

	virtual void Describe(void) const override
	{
		Item::Describe();
		DescribeDamage();
	}

private:
	int damage;

	inline void DescribeDamage(void) const
	{
		cout << setw(GetSpaceInfo()) << "Damage" << "= " << damage << endl;
	}
};

class Armor : public Item
{
public:
	Armor(const string& name, const string& description, const int weight, const int value, const int defense)
		: Item(name, description, weight, value), defense(defense)
	{

	}

	virtual ~Armor() = default;

	virtual void Describe(void) const override
	{
		Item::Describe();
		DescribeDefense();
	}

private:
	int defense;

	inline void DescribeDefense(void) const
	{
		cout << setw(GetSpaceInfo()) << "Defense" << "= " << defense << endl;
	}
};

int main()
{
	using ItemPtr = shared_ptr<Item>;

	vector<ItemPtr> item_list{
		make_shared<Weapon>("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24),
		make_shared<Armor>("Steel Armor", "Protective covering made by steel", 15, 805, 18)
	};

	for (const auto& item : item_list)
	{
		item->Describe();
		cout << endl;
	}

    return 0;
}