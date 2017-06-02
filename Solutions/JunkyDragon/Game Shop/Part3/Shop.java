package com.github.junkydragon;

import java.util.Scanner;

/**
 * Created by Administrator on 2017-05-30.
 */
public class Shop {
    private String name;
    private Item[] items;
    public Shop(String name, Item[] items) {
        this.name = name;
        this.items = items;
    }
    public void ShowItemList() {
        for (;;) {
            Scanner sc = new Scanner(System.in);
            System.out.println("- Shop Select - ");
            System.out.println("\t1. Weapon/Armor Shop");
            System.out.println("\t2. Potion Shop");
            System.out.println("\t3. Exit");
            switch (sc.nextInt()) {
                case 1 :
                    System.out.println("Welcome to Weapon/Armor Shop!");
                    for (Item i : items) {
                        if (i instanceof Potion) continue;
                        i.Describe();
                        System.out.println();
                    }
                    break;
                case 2 :
                    System.out.println("Welcome to Potion Shop!");
                    for (Item i : items) {
                        if (i instanceof Weapon || i instanceof Armor) continue;
                        i.Describe();
                        System.out.println();
                    }
                    break;
                case 3 :
                    System.out.println("Good Bye!");
                    return;

                default:
                    System.out.println("올바른 숫자를 입력해주세요.");
            }
        }
    }
}
