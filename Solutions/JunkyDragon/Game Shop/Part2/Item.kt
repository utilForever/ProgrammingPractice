package org.junkydragon.item

/**
 * Created by Administrator on 2017-05-24.
 */

open class Item(val name: String, val description: String, val weight: Double, val value: Int){

    open fun About() {
        println("Name\t\t\t= $name")
        println("Description\t\t= $description")
        println("Weight\t\t\t= $weight")
        println("Value\t\t\t= $value")
    }


}

//fun main(args: Array<String>) {
//    val item = Item("Excalibur", "The legendary sword of King Arthur", 12.0, 1024)
//    item.About()
//}