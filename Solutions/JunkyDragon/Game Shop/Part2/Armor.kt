package org.junkydragon.item

/**
 * Created by Administrator on 2017-05-24.
 */

class Armor(name: String, description: String, weight: Double, value: Int, val defence: Int) : Item(name, description, weight, value){

    override fun About() {
        println("Name\t\t\t= $name")
        println("Description\t\t= $description")
        println("Weight\t\t\t= $weight")
        println("Value\t\t\t= $value")
        println("Defence\t\t\t= $defence")
    }
}