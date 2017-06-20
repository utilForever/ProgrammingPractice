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

using ItemPtr = shared_ptr<Item>;
using WeaponPtr = shared_ptr<Weapon>;
using ArmorPtr = shared_ptr<Armor>;
using PotionPtr = shared_ptr<Potion>;
using ShopPtr = shared_ptr<Shop>;
using ShopManagerPtr = shared_ptr<ShopManager>;

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

	static const unordered_map<string, Type> string_to_type;

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

// C++ 기본 라이브러리에는 bimap이 없어서 안타깝네요~
const unordered_map<Potion::Type, string> Potion::type_to_string{
	make_pair(Potion::Type::HP, "Health"),
	make_pair(Potion::Type::MP, "Mana")
};

const unordered_map<string, Potion::Type> Potion::string_to_type{
	make_pair("Health", Potion::Type::HP),
	make_pair("Mana", Potion::Type::MP)
};

class Shop : public enable_shared_from_this<Shop>
{
public:
	static ShopPtr MakeInstance(const string& name = "", vector<ItemPtr> items = vector<ItemPtr>())
	{
		return make_shared<Shop>(name, items);
	}

	static ShopPtr MakeInstance(const string& name, const string& file_name)
	{
		return make_shared<Shop>(name, file_name);
	}

	Shop(const string& name = "", vector<ItemPtr> items = vector<ItemPtr>())
		: name(name), items(items)
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
				istrm >> item;
				items.push_back(item);
			}
		}
	}

	// Shop 인스턴스 생성 시 아이템 정보를 파일에서 가져오는 것이 낫다고 판단하였습니다.
	// Shop 클래스가 파일스트림 어트리뷰트를 가지고 있을 필요가 없다고 생각하여, 이 클래스 또한 작성하지 않았습니다.
	// 대신 operation>>()를 재정의하여 파일로부터 아이템 정보를 입력받았습니다.
	//ReadDataFromFile(void);

	// 소멸자에 파일 스트림을 닫는 요구사항이 있었는데, 스트림 클래스의 소멸자에서 자동으로 닫는 것으로 알고 있어서 작성하지 않았습니다.
	// 그리고, 생성자에서 예외를 발생시키면 소멸자 호출이 안되는 것으로 알고 있기 때문에 여기에 스트림을 닫아봤자 효과가 없을 것 같다는 생각을 했습니다.
	virtual ~Shop() = default;

	ShopPtr PushBack(ItemPtr item)
	{
		items.push_back(item);

		return shared_from_this();
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
			shop_manager->PushBack(Shop::MakeInstance(shop_information.first, shop_information.second));
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

	MyGame(ShopManagerPtr shop_manager)
		: shop_manager(shop_manager)
	{

	}

	~MyGame() = default;

	void SetShopManager(ShopManagerPtr shop_manager)
	{
		this->shop_manager = shop_manager;
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