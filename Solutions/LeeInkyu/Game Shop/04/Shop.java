/**
 * Created by Inkyu Lee on 2017-05-30.
 */
import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

public class Shop {
	String name;
	Item[] items;
	ArrayList<Item> itemsList;
	FileReader itemsInput;
	int ARR_MAX = 5;


	public Shop(String namePm, Item[] itemsPm)
	{
		this.name = namePm;
		this.items = itemsPm;
		this.ARR_MAX = itemsPm.length;
	}

	public Shop(String namePm, Item[] itemsPm, int arrMaxPm)
	{
		this.name = namePm;
		this.items = itemsPm;
		this.ARR_MAX = arrMaxPm;
	}

	public Shop(String namePm, ArrayList<Item> itemsListPm)
	{
		this.name = namePm;
		this.itemsList = itemsListPm;
		this.ARR_MAX = itemsListPm.size();
	}

	public Shop(String namePm, ArrayList<Item> itemsListPm, String fileNamePm) throws IOException
	{
		this.name = namePm;
		this.itemsList = itemsListPm;
		this.ARR_MAX = itemsListPm.size();
		this.itemsInput = new FileReader(fileNamePm);
	}

	public void finalize() throws IOException
	{
		this.itemsInput.close(); //소멸자로 파일 스트림 닫음
	}

	public void showItemArr()
	{
		System.out.println("Welcome to " + this.name + "!");
		for(int i=0; i<ARR_MAX; i++)
		{
			this.items[i].describe();
		}
	}

	public void showItemList()
	{
		Scanner sc = new Scanner(System.in);
		char cTmp;

		System.out.println("Welcome to " + this.name + "!");
		System.out.println("1. Show Item List");
		System.out.println("2. Exit");
		System.out.println("Select: ");
		cTmp = sc.next().charAt(0);

		if(cTmp == '1')
		{
			for(int i=0; i<itemsList.size(); i++)
			{
				this.itemsList.get(i).describe(); //item 객체 describe 이용해서 출력
			}
		}

		else return;
	}

	public void readDataFromFile() throws IOException, NotValidItemType
	{
		String file_input_tmp;
		String[] file_split_tmp;
		BufferedReader reader = new BufferedReader(itemsInput);

		READ_FILE:
		for(;;)
		{
			int index = 0;
			file_input_tmp = reader.readLine(); // 한 줄 입력
			if(file_input_tmp == null)
			{
				reader.close();
				return;
			} //입력이 끝날 경우

			file_split_tmp = file_input_tmp.split(","); //쉼표 기준으로 분리

			for(int j=0; j<file_split_tmp.length; j++)
			{
				if(file_split_tmp[j] == null) break READ_FILE;
				file_split_tmp[j] = file_split_tmp[j].replace('"',' ');
				file_split_tmp[j] = file_split_tmp[j].trim(); //공백, " 제거
			}


			if(file_split_tmp[0].equals("Weapon"))
			{
				itemsList.add(index, new Weapon(file_split_tmp[1], file_split_tmp[2],
						Integer.parseInt(file_split_tmp[3]), Integer.parseInt(file_split_tmp[4]),
						Integer.parseInt(file_split_tmp[5])));
			}
			else if(file_split_tmp[0].equals("Armor"))
			{
				itemsList.add(index, new Armor(file_split_tmp[1], file_split_tmp[2],
						Integer.parseInt(file_split_tmp[3]), Integer.parseInt(file_split_tmp[4]),
						Integer.parseInt(file_split_tmp[5])));
			}
			else if(file_split_tmp[0].equals("Potion"))
			{
				itemsList.add(index, new Potion(file_split_tmp[1], file_split_tmp[2],
						Integer.parseInt(file_split_tmp[3]), Integer.parseInt(file_split_tmp[4]),
						file_split_tmp[5], Integer.parseInt(file_split_tmp[6])));
			}
			else
			{
				throw new NotValidItemType(); //아이템 타입이 일치하지 않을 경우 예외 던짐
			}
			index++;
		}

		reader.close();
	}
}
