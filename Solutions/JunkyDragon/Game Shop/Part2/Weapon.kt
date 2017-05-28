package org.junkydragon.item

/**
 * Created by Administrator on 2017-05-24.
 */

class Weapon(name: String, description: String, weight: Double, value: Int, val damage:Int):Item(name, description, weight, value){
    override fun About() {
        println("Name\t\t\t= $name")
        println("Description\t\t= $description")
        println("Weight\t\t\t= $weight")
        println("Value\t\t\t= $value")
        println("Damage\t\t\t= $damage")
    }
}