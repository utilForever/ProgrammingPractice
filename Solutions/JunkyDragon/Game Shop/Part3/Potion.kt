package org.junkydragon.item

/**
 * Created by Administrator on 2017-05-30.
 */

class Potion(name: String, description: String, weight: Double, value: Int, val type :String, val capacity:Int) : Item(name, description, weight, value){

    override fun About() {
        super.About()
        println("Type\t\t\t= $type")
        println("Capacity\t\t= $capacity")
    }
}