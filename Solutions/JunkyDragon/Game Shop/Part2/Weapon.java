package com.github.junkydragon;

/**
 * Created by Administrator on 2017-05-23.
 */
public class Weapon extends Item{
    private int damage;
    public Weapon(){super();}
    public Weapon(String name, String description, float weight, int value, int damage) {
        super(name, description, weight, value);
        this.damage = damage;
    }
    public void Describe() {
        super.Describe();
        System.out.println("Damage\t\t\t = " +this.damage);
    }
}
