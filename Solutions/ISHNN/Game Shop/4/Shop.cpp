#include <fstream>
#include "Shop.h"

#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

Shop::Shop(std::string name, std::string filename){
	Shop::name = name;
	Shop::filename = filename;

	Shop::ReadDataFromFile();
}

Shop::~Shop()
{
}

void Shop::ReadDataFromFile() {
	char input_buf[100];

	std::ifstream inFile(Shop::filename);

	int item_count = 0;

	while (!inFile.eof()) {
		inFile.getline(input_buf, 100);

		std::string tokens[7];
		int tokenNum = 0;
		bool isString = false;

		for (char r : input_buf) {

			if (r == ',') {
				tokenNum++;				continue;
			}//분기(,)일 경우 다음 토큰으로 이동
			else if (r == '\"') {
				isString = !isString;	continue;
			}//문장("")의 시작에서 true, 끝에서 false

			else if (r != ' ' || isString) {
				tokens[tokenNum] += r;
			}//공백을 뺀 값인 경우 또는 문장일 경우 대입
		}

		if (!tokens[0].compare("Weapon")) {
			Shop::items.insert(new Weapon(tokens[1], tokens[2], atoi(tokens[3].c_str()), atoi(tokens[4].c_str()), atoi(tokens[5].c_str())));
		}
		else if (!tokens[0].compare("Armor")) {
			Shop::items.insert(new Armor(tokens[1], tokens[2], atoi(tokens[3].c_str()), atoi(tokens[4].c_str()), atoi(tokens[5].c_str())));
		}
		else if (!tokens[0].compare("Potion")) {
			Shop::items.insert(new Potion (tokens[1], tokens[2], atoi(tokens[3].c_str()), atoi(tokens[4].c_str()),tokens[5], atoi(tokens[6].c_str()) ));
		}
	}

	inFile.close();
}

void Shop::LoadShop() {
	while (true) {
		std::cout << "Welcome to " << Shop::name.data() << "!" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		switch (Selection_Shop())
		{
		case 1: {
			PrintShop(); break;
		}
		case 2: {
			return;
		}
		default:
			std::cout << "Invaild number! Try again" << std::endl;
		}
	}
}

int Shop::Selection_Shop() {
	int select;
	std::cout << "- Shop Select -" << std::endl;
	std::cout << "1. Show Item List" << std::endl;
	std::cout << "2. Exit" << std::endl;
	std::cout << std::endl;

	std::cout << "Select : ";
	std::cin >> select;
	std::cout << std::endl;

	return select;
}

void Shop::PrintShop() {
	for (Item* item : Shop::items) {
		item->Describe();
		std::cout << std::endl;
	}
}
