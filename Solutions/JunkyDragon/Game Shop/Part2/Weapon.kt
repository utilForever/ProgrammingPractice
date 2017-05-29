package org.junkydragon.item

/**
 * Created by Administrator on 2017-05-24.
 */

class Weapon(name: String, description: String, weight: Double, value: Int, val damage:Int):Item(name, description, weight, value){
    override fun About() {
        super.About()
        println("Damage\t\t\t= $damage")
    }
}