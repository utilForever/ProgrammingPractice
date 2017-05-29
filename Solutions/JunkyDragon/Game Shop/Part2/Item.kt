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