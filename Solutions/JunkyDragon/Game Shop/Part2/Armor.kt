package org.junkydragon.item

/**
 * Created by Administrator on 2017-05-24.
 */

class Armor(name: String, description: String, weight: Double, value: Int, val defence: Int) : Item(name, description, weight, value){

    override fun About() {
        super.About()
        println("Defence\t\t\t= $defence")
    }
}