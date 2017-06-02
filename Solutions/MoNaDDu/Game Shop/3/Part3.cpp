#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Item;
class Weapon;
class Armor;
class Potion;
class Shop;
class ShopManager;

using ItemPtr = shared_ptr<Item>;
using WeaponPtr = shared_ptr<Weapon>;
using ArmorPtr = shared_ptr<Armor>;
using PotionPtr = shared_ptr<Potion>;
using ShopPtr = shared_ptr<Shop>;
using ShopManagerPtr = shared_ptr<ShopManager>;

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
	static ItemPtr MakeInstance(const string& name, const string& description, const int weight, const int value, const int damage)
	{
		return make_shared<Weapon>(name, description, weight, value, damage);
	}

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
	static ItemPtr MakeInstance(const string& name, const string& description, const int weight, const int value, const int defense)
	{
		return make_shared<Armor>(name, description, weight, value, defense);
	}

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

class Potion : public Item
{
public:
	enum class Type
	{
		HP,
		MP
	};

	static ItemPtr MakeInstance(const string& name, const string& description, const int weight, const int value, const Type type, const int capacity)
	{
		return make_shared<Potion>(name, description, weight, value, type, capacity);
	}

	Potion(const string& name, const string& description, const int weight, const int value, const Type type, const int capacity)
		: Item(name, description, weight, value), type(type), capacity(capacity)
	{

	}

	virtual void Describe(void) const override
	{
		Item::Describe();
		DescribeType();
		DescribeCapacity();
	}

private:
	const int capacity;
	const Type type;
	static const unordered_map<Type, string> type_to_string;

	inline void DescribeType(void) const
	{
		cout << setw(GetSpaceInfo()) << "Type" << "= " << type_to_string.at(type) << endl;
	}

	inline void DescribeCapacity(void) const
	{
		cout << setw(GetSpaceInfo()) << "Capacity" << "= " << capacity << endl;
	}
};

const unordered_map<Potion::Type, string> Potion::type_to_string{
	make_pair(Potion::Type::HP, "Health"),
	make_pair(Potion::Type::MP, "Mana")
};

class Shop : public enable_shared_from_this<Shop>
{
public:
	static ShopPtr MakeInstance(const string& name = "", vector<ItemPtr> items = vector<ItemPtr>())
	{
		return make_shared<Shop>(name, items);
	}

	Shop() = default;

	Shop(const string& name = "", vector<ItemPtr> items = vector<ItemPtr>())
		: name(name), items(items)
	{

	}

	virtual ~Shop() = default;

	ShopPtr PushBack(ItemPtr item)
	{
		items.push_back(item);

		return shared_from_this();
	}

	void ShowItemList(void) const
	{
		cout << "Welcome to " << name << "!\n";
		cout << "- Item List -\n";
		for (const auto& item : items)
		{
			item->Describe();
			cout << endl;
		}
	}

	const string& GetName(void) const
	{
		return name;
	}

private:
	const string name;
	vector<ItemPtr> items;
};

class ShopManager : public enable_shared_from_this<ShopManager>
{
public:
	static ShopManagerPtr MakeInstance(void)
	{
		return make_shared<ShopManager>();
	}

	ShopManagerPtr PushBack(ShopPtr shop)
	{
		shop_list.push_back(shop);

		return shared_from_this();
	}

	template<typename F>
	void PrintShopName(F Func) const
	{
		for (const auto& name : shop_list)
			Func(name->GetName());
	}

	void ShowItemListOfShop(const size_t index)
	{
		shop_list[index]->ShowItemList();
	}

	size_t GetNumberOfShop(void) const
	{
		return shop_list.size();
	}

private:
	vector<ShopPtr> shop_list;
};

ShopManagerPtr InitShopManager(void)
{
	return ShopManager::MakeInstance()
		->PushBack(
			Shop::MakeInstance("Weapon/Armor", {
				Weapon::MakeInstance("Sword", "Medium DMG", 3, 10, 10),
				Armor::MakeInstance("Cap", "Light Armor", 1, 5, 5),
				Armor::MakeInstance("Gloves", "Light Armor", 1, 5, 5),
				Weapon::MakeInstance("Axe", "High DMG", 5, 15, 15),
				Armor::MakeInstance("Boots", "Light Armor", 1, 5, 5)
			})
		)
		->PushBack(
			Shop::MakeInstance("Potion", {
				Potion::MakeInstance("Small Health Potion", "Recovery 100 HP", 2, 5, Potion::Type::HP, 100),
				Potion::MakeInstance("Small Mana Potion", "Recovery 50 MP", 1, 30, Potion::Type::MP, 50),
				Potion::MakeInstance("Medium Health Potion", "Recovery 200 HP", 4, 120, Potion::Type::HP, 200),
				Potion::MakeInstance("Medium Mana Potion", "Recovery 100 MP", 2, 75, Potion::Type::MP, 100),
				Potion::MakeInstance("Large Health Potion", "Recovery 300 HP", 6, 200, Potion::Type::HP, 300)
			})
		);
}

int Play(const ShopManagerPtr& shop_manager);

void PrintMenu(const ShopManagerPtr& shop_manager)
{
	auto index = 0u;
	cout << " - Shop Select -\n";
	shop_manager->PrintShopName([&index](const auto& name) {
		cout << "    " << ++index << ". " << name << " Shop\n";
	});
	cout << "    " << ++index << ". Exit\n\n";
	cout << "Select : ";
}

size_t Input(void)
{
	size_t selected_number;

	cin >> selected_number;

	return selected_number - 1;
}

int Play(const ShopManagerPtr& shop_manager)
{
	PrintMenu(shop_manager);

	auto selected_number = Input();
	auto end = false;

	if (selected_number < 0 || selected_number > shop_manager->GetNumberOfShop())
		cout << "\nInvalid number! Try again.\n" << endl;
	else if (selected_number != shop_manager->GetNumberOfShop())
		shop_manager->ShowItemListOfShop(selected_number);
	else
		end = true;

	return end ? 0 : Play(shop_manager);
}

int main()
{
	auto shop_manager = InitShopManager();

    return Play(shop_manager);
}