#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <regex>
#include <iterator>

using namespace std;

class Item;
class Weapon;
class Armor;
class Potion;
class Shop;
class ShopManager;

using ItemPtr = unique_ptr<Item>;
using WeaponPtr = unique_ptr<Weapon>;
using ArmorPtr = unique_ptr<Armor>;
using PotionPtr = unique_ptr<Potion>;
using ShopPtr = unique_ptr<Shop>;
using ShopManagerPtr = unique_ptr<ShopManager>;

class Item
{
	friend istream& operator>>(istream& is, ItemPtr& item);
public:
	Item() = default;

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
	static const regex reg;

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
		cout << left << setw(space) << "Value" << "= " << value << (value > 1 ? " gold coins" : " gold coin") << endl;
	}
};

const regex Item::reg(R"~([[:s:]"]*([^",]+)[[:s:]]*)~");

class Weapon : public Item
{
public:
	static ItemPtr MakeInstance(const string& name, const string& description, const int weight, const int value, const int damage)
	{
		return make_unique<Weapon>(name, description, weight, value, damage);
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
		return make_unique<Armor>(name, description, weight, value, defense);
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

	static const unordered_map<string, Type> string_to_type;

	static ItemPtr MakeInstance(const string& name, const string& description, const int weight, const int value, const Type type, const int capacity)
	{
		return make_unique<Potion>(name, description, weight, value, type, capacity);
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

// C++ 기본 라이브러리에는 bimap이 없어서 안타깝네요~
const unordered_map<Potion::Type, string> Potion::type_to_string{
	make_pair(Potion::Type::HP, "Health"),
	make_pair(Potion::Type::MP, "Mana")
};

const unordered_map<string, Potion::Type> Potion::string_to_type{
	make_pair("Health", Potion::Type::HP),
	make_pair("Mana", Potion::Type::MP)
};

class Shop
{
public:
	static ShopPtr MakeInstance(const string& name, vector<ItemPtr>&& items)
	{
		return make_unique<Shop>(name, move(items));
	}

	static ShopPtr MakeInstance(const string& name, const string& file_name)
	{
		return make_unique<Shop>(name, file_name);
	}

	Shop(const string& name, vector<ItemPtr>&& items)
		: name(name), items(move(items))
	{

	}

	Shop(const string& name, const string& file_name)
		: name(name)
	{
		ifstream istrm(file_name);
		if (!istrm.is_open())
			throw std::invalid_argument("Failed to open "s + file_name);
		else
		{
			while (!istrm.eof())
			{
				ItemPtr item;
				istrm >> item;	// operator>>를 오버로딩하여 입력처리 부분을 모듈화 함
				items.emplace_back(move(item));
			}
		}
	}

	virtual ~Shop() = default;

	void EmplaceBack(ItemPtr&& item)
	{
		items.emplace_back(move(item));
	}

	void ShowItemList(void) const
	{
		cout << "\n- Item List -\n";

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

class ShopManager
{
public:
	static ShopManagerPtr MakeInstance(void)
	{
		return make_unique<ShopManager>();
	}

	void EmplaceBack(ShopPtr&& shop)
	{
		shop_list.emplace_back(move(shop));
	}

	template<typename F>
	void PrintShopName(F Func) const
	{
		for (const auto& name : shop_list)
			Func(name->GetName());
	}

	const string& GetShopName(const size_t index) const
	{
		return shop_list[index]->GetName();
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
	vector<pair<string, string>> shops_information;

	shops_information.emplace_back(make_pair("Weapon/Armor", R"~(C:\Users\NaDDu\Documents\GitHub\ProgrammingPractice\Solutions\MoNaDDu\Game Shop\4\equip_item.txt)~"));
	shops_information.emplace_back(make_pair("Potion", R"~(C:\Users\NaDDu\Documents\GitHub\ProgrammingPractice\Solutions\MoNaDDu\Game Shop\4\potion_item.txt)~"));

	auto shop_manager = ShopManager::MakeInstance();

	try
	{
		for (const auto& shop_information : shops_information)
			shop_manager->EmplaceBack(Shop::MakeInstance(shop_information.first, shop_information.second));
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}

	return shop_manager;
}

istream& operator>>(istream& is, ItemPtr& item)
{
	string input;

	getline(is, input);

	smatch m;
	vector<string> parsing_result;

	while (regex_search(input, m, Item::reg))
	{
		parsing_result.push_back(m[1]);
		input = m.suffix().str();
	}

	if (parsing_result.front() == "Weapon"s)
	{
		if (parsing_result.size() < 6)
			throw std::runtime_error("Not enough data.");

		item.reset(new Weapon(parsing_result[1], parsing_result[2], stoi(parsing_result[3]), stoi(parsing_result[4]), stoi(parsing_result[5])));
	}
	else if (parsing_result.front() == "Armor"s)
	{
		if (parsing_result.size() < 6)
			throw std::runtime_error("Not enough data.");

		item.reset(new Armor(parsing_result[1], parsing_result[2], stoi(parsing_result[3]), stoi(parsing_result[4]), stoi(parsing_result[5])));
	}
	else if (parsing_result.front() == "Potion"s)
	{
		if (parsing_result.size() < 7)
			throw std::runtime_error("Not enough data.");

		item.reset(new Potion(parsing_result[1], parsing_result[2], stoi(parsing_result[3]), stoi(parsing_result[4]), Potion::string_to_type.at(parsing_result[5]), stoi(parsing_result[6])));
	}
	else
		throw std::runtime_error("Unknown Item.");

	return is;
}

class MyGame
{
public:
	MyGame() = default;

	MyGame(ShopManagerPtr&& shop_manager)
		: shop_manager(move(shop_manager))
	{

	}

	~MyGame() = default;

	void SetShopManager(ShopManagerPtr&& shop_manager)
	{
		this->shop_manager = move(shop_manager);
	}

	int Play(void) const
	{
		PrintMenu();

		const auto selected_number = Input();
		auto end = false;

		if (selected_number < 0 || selected_number > shop_manager->GetNumberOfShop())
			cout << "\nInvalid number! Try again.\n" << endl;
		else if (selected_number != shop_manager->GetNumberOfShop())
			Shopping(selected_number);
		else
			end = true;

		return end ? 0 : Play();
	}

private:
	ShopManagerPtr shop_manager;

	size_t Input(void) const
	{
		size_t selected_number;

		cin >> selected_number;

		return selected_number - 1;
	}

	void Shopping(const size_t shop_number) const
	{
		auto shopping = true;

		while (shopping)
		{
			PrintShopMenu(shop_manager->GetShopName(shop_number));

			auto selected_shop_number = Input();

			switch (selected_shop_number)
			{
			case 0:
				shop_manager->ShowItemListOfShop(shop_number);
				break;
			case 1:
				shopping = false;
				break;
			default:
				cout << "\nInvalid number! Try again.\n" << endl;
				break;
			}
		}
	}

	void PrintMenu(void) const
	{
		auto index = 0u;

		cout << " - Shop Select -\n";
		shop_manager->PrintShopName([&index](const auto& name) {
			cout << "    " << ++index << ". " << name << " Shop\n";
		});
		cout << "    " << ++index << ". Exit\n\n";
		cout << "Select : ";
	}

	void PrintShopMenu(const string& shop_name) const
	{
		string welcome_message = "Welcome to " + shop_name + " Shop!";

		cout << '\n' << welcome_message << endl;
		fill_n(ostream_iterator<char>(cout), welcome_message.size(), '-');
		cout << "\n1. Show Item List\n";
		cout << "2. Exit\n\n";
		cout << "Select : ";
	}
};

int main()
{
	return MyGame(InitShopManager()).Play();
}