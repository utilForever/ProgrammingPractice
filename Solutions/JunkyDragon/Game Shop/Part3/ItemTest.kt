package org.junkydragon.item

/**
 * Created by Administrator on 2017-05-24.
 */

fun main(args: Array<String>) {
    val items : Array<Item> = arrayOf(
            Weapon("Sword", "Medium DMG", 3.0, 10, 10),
            Armor("Cap", "Light Armor", 1.0, 5, 5),
            Armor("Gloves", "Light Armor", 1.0, 5, 5),
            Weapon("Axe", "High DMG", 5.0, 15, 15),
            Armor("Boots", "Light Armor", 1.0, 5, 5),
            Potion("Small Health Potion", "Recovery 100HP", 2.0, 5, "Health", 100),
            Potion("Small Mana Potion", "Recovery 50MP", 1.0, 30, "Mana", 50),
            Potion("Medium Health Potion", "Recovery 200HP", 4.0, 120, "Health", 200),
            Potion("Medium Mana Potion", "Recovery 100MP", 2.0, 75, "Mana", 100),
            Potion("Large Health Potion", "Recovery 200HP", 6.0, 200, "Health", 300)
    );
    val shop : Shop = Shop("Aperture",items)
    shop.ShowItemList()
}