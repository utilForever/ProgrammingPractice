package com.github.junkydragon;

/**
 * Created by Administrator on 2017-05-18.
 */
public class Item {
    private String name;
    private String description;
    private float weight;
    private int value;

    public Item(){}

    public Item(String name, String description, float weight, int value) {
        this.name = name;
        this.description = description;
        this.weight = weight;
        this.value = value;
    }
    public void Describe() {
        System.out.println("Name\t\t\t = " +this.name);
        System.out.println("Description\t\t = " +this.description);
        System.out.println("Weight\t\t\t = " +this.weight + " lbs");
        System.out.println("Value\t\t\t = " +this.value + " gold coins");
    }
}
