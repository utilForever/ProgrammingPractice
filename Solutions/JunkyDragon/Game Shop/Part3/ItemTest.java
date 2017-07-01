package com.github.junkydragon;

import java.util.Scanner;

/**
 * Created by Administrator on 2017-05-18.
 */
public class ItemTest {
    public static void main(String args[]) {
        Item i[] = {
                new Weapon("Sword", "Medium DMG", 3,10,10),
                new Armor("Cap","Lightl Armor",1,5,5),
                new Armor("Gloves","Light Armor", 1,5,5),
                new Weapon("Axe","High DMG",5,15,15),
                new Armor("Boots","Light Armor",1,5,5),
                new Potion("Small Health Potion","Recovery 100HP", 2,5,"Health",100),
                new Potion("Small Mana Potion","Recovery 50MP", 1,30,"Mana",50),
                new Potion("Medium Health Potion","Recovery 200HP", 4,120,"Health",200),
                new Potion("Medium Mana Potion","Recovery 100MP", 2,75,"Mana",100),
                new Potion("Large Health Potion","Recovery 300HP", 6,200,"Health",300)
        };
        Shop s = new Shop("ssshop",i);
        s.ShowItemList();
    }
}
