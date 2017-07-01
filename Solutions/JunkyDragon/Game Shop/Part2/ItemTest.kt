package org.junkydragon.item

/**
 * Created by Administrator on 2017-05-24.
 */

fun main(args: Array<String>) {
    val i : Item = Item("Armor", "armor", 100.0, 20)
    i.About()
    val a : Item = Armor("Steel Armor", "Armor that made by Steel", 100.0, 20, 50)
    a.About()
    val w : Weapon = Weapon("Steel Sword", "Sword that made by Steel", 100.0, 20, 50)
    w.About()
    val ia : Array<Item> = arrayOf(Armor("Steel Armor", "Armor that made by Steel", 100.0, 20, 50), Weapon("Steel Sword", "Sword that made by Steel", 100.0, 20, 50))
}