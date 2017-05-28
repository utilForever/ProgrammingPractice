package org.junkydragon.item

/**
 * Created by Administrator on 2017-05-24.
 */

fun main(args: Array<String>) {
    val item : Item = Item("Armor", "armor", 100.0, 20)
    item.About()
    val armor : Armor = Armor("Steel Armor", "Armor that made by Steel", 100.0, 20, 50)
    armor.About()
    val weapon : Weapon = Weapon("Steel Sword", "Sword that made by Steel", 100.0, 20, 50)
    weapon.About()
}