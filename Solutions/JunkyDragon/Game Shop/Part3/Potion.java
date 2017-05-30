package com.github.junkydragon;

/**
 * Created by Administrator on 2017-05-30.
 */
public class Potion extends Item {
    private String type;
    private int capacity;
    public Potion(String name, String description, int weight, int value, String type, int capacity) {
        super(name, description, weight, value);
        this.type = type;
        this.capacity = capacity;
    }
    public void Describe() {
        super.Describe();
        System.out.println("Type\t\t\t = " +this.type);
        System.out.println("Capacity\t\t\t = " + this.capacity);
    }
}
