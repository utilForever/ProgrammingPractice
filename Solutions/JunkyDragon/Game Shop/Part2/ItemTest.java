package com.github.junkydragon;

import java.util.Scanner;

/**
 * Created by Administrator on 2017-05-18.
 */
public class ItemTest {
    public static void main(String args[]) {
//        Item a[] = new Item[10];
//        Scanner sc = new Scanner(System.in);
//        for (Item i : a) {
//            System.out.print("아이템의 이름을 입력하시오! : ");
//            String n = sc.next();
//            sc.nextLine();
//            System.out.print("아이템에 대해 설명해주시오! : ");
//            String d = sc.nextLine();
//            System.out.print("아이템의 무게를 입력하시오! : ");
//            float w = sc.nextFloat();
//            System.out.print("아이템의 가격을 입력하시오! : ");
//            int v = sc.nextInt();
//            i = new Item(n, d, w, v);
//        }
//        for (Item i : a) {
//            i.Describe();
//        }

        Item i[] = {
                new Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24),
                new Armor("Steel Armor", "Protective covering made by steel",15,805,18)
        };
        for (Item item:i) {
            item.Describe();
        }
    }
}
