package org.junkydragon.item

import java.util.*

/**
 * Created by Administrator on 2017-05-30.
 */

class Shop(val name : String, val item : Array<Item>) {
    fun ShowItemList() {
        val input = Scanner(System.`in`)
        while(true) {
            println()
            println("- Shop Select -")
            println("\t1. Weapon/Armor Shop")
            println("\t2. Potion Shop")
            println("\t3. Exit")
            print("Select : ")
            when (input.nextInt()) {
                1 -> {
                    println("Welcome to Weapon/Armor Shop!")
                    println("- Item List -")
                    for (x in item) {
                        if(x is Potion) continue
                        x.About()
                        println()
                    }
                }
                2 -> {
                    println("Welcome to Potion Shop!")
                    println("- Item List -")
                    for (x in item) {
                        if(x is Weapon || x is Armor) continue
                        x.About()
                        println()
                    }
                }
                3 -> {
                    println("Bye Bye")
                    return
                }
                else -> {
                    println("제대로된 숫자를 입력해주세요")
                }
            }

        }
    }
}