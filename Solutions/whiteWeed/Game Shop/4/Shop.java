/**
 * 
 */
package whiteWeed.gameShop;

import java.io.*;
import java.util.*;

/**
 * <pre>
 * whiteWeed.gameShop
 *   |_Shop
 * 
 * 1. 개요 : 
 * 2. 작성일 : 2017. 6. 5.
 * </pre>
 * 
 * @author				:  Weed
 * @version				:  1.0
 */
public class Shop {
	String name;
	Item[] itemsArray;
	List<String> strList = new ArrayList<String>();
	List<String[]> itemList = new ArrayList<String[]>();
	List<Item> itemsList = new ArrayList<Item>();
	
	public Shop(String name, Item[] items){
		this.name = name;
		this.itemsArray = items;
	}
	
	public Shop(String name, String fileName){
		this.name = name;
		String path = Shop.class.getResource("").getPath();
		try{
			BufferedReader br = new BufferedReader(new FileReader(path + fileName));
			while(true){
				String line = br.readLine();
				if(line != null){ 
					strList.add(line);
				}else{
					break;
				}
			}
			br.close();
		} catch(IOException e){
			System.out.println("can't find file");
		}
	}
	
	public void splitData(){
		for(String str : strList){
			str = str.replaceAll("\"", "");
			itemList.add(str.split(", "));
			
		}
		for(String[] str : itemList){
			if(str[0].equals("Potion") == true){
				itemsList.add(new Potion(str[1], str[2], Integer.parseInt(str[3]), Integer.parseInt(str[4]), str[5], Integer.parseInt(str[6])));
			}
			else if(str[0].equals("Weapon") == true){
				itemsList.add(new Weapon(str[1], str[2], Integer.parseInt(str[3]), Integer.parseInt(str[4]), Integer.parseInt(str[5])));
			}
			else if(str[0].equals("Armor") == true){
				itemsList.add(new Armor(str[1], str[2], Integer.parseInt(str[3]), Integer.parseInt(str[4]), Integer.parseInt(str[5])));
			}
			else{
				System.out.println("Invalid item type! Try check .txt file again.");
			}
		}
	}
	
	public void showItemList(){
		System.out.println("Welcome to " + this.name + " Shop!");
		System.out.println("- Item List -");
		for(Item item : itemsArray){
			item.describe();
			System.out.println();
		}
	}
	
	public void showItemArrayList(){
		splitData();
		System.out.println("Welcome to " + this.name + " Shop!");
		System.out.println("- Item List -");
		for(Item item : itemsList){
			item.describe();
			System.out.println();
		}
	}
}
