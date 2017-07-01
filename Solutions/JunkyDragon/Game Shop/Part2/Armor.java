package com.github.junkydragon;

/**
 * Created by Administrator on 2017-05-23.
 */
public class Armor extends Item{
    private int defence;
    public Armor(){super();}
    public Armor(String name, String description, float weight, int value, int defence) {
        super(name, description, weight, value);
        this.defence = defence;
    }
    public void Describe() {
        super.Describe();
        System.out.println("Defence\t\t\t = " +this.defence);
    }
}
