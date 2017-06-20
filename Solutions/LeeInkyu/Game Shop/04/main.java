/**
 * Created by Inkyu Lee on 2017-05-28.
 */

import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;

public class main {

	public static void main(String args[]) throws IOException{
		Scanner sc = new Scanner(System.in);
		int input_tmp;
		ArrayList<Item> WeaponsAndArmors = new ArrayList<Item>();
		ArrayList<Item> Potions = new ArrayList<Item>();

		Shop WeaponsAndArmorsShop = new Shop("Weapon / Armor Shop", WeaponsAndArmors, "equip_item.txt");
		Shop PotionsShop = new Shop("Potion Shop", Potions, "potion_item.txt");

		try //파일 데이터 읽어옴
		{
			WeaponsAndArmorsShop.readDataFromFile();
			PotionsShop.readDataFromFile();
		}
		catch(NotValidItemType e) //유효한 아이템 타입이 아닐 경우
		{
			System.out.println("유효한 아이템 타입이 아닙니다.");
		}

		MAIN_MENU: //메인메뉴 처리 레이블
		for(;;)
		{
			System.out.println("- Shop Select -");
			System.out.println("1. Weapon/Armor Shop");
			System.out.println("2. Potion Shop");
			System.out.println("3. Exit");
			System.out.println("Select : ");
			input_tmp = sc.nextInt();

			switch(input_tmp)
			{
				case 1: //무기 방어구 상점
					WeaponsAndArmorsShop.showItemList();
					break;
				case 2: //포션 상점
					PotionsShop.showItemList();
					break;
				case 3:
					break MAIN_MENU;
				default:
					System.out.println("유효한 숫자가 아닙니다.");
			}
		}
	}
}
