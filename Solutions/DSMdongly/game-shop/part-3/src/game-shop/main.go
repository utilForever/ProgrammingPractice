package main

import (
	"fmt"
	"game-shop/item"
	"game-shop/shop"
	"log"
	"strconv"
	"time"
)

func main() {
	esh := InitEquipmentShop()
	psh := InitPotionShop()

SHOP_SELECTION:
	for {
		fmt.Println()
		fmt.Println("Shop Select")
		fmt.Println()
		fmt.Println("1. Weapon/Armor Shop")
		fmt.Println("2. Potion Shop")
		fmt.Println("3. Exit")
		fmt.Println()

		buf := ""
		fmt.Scanln(&buf)

		flg, err := strconv.Atoi(buf)

		if err != nil {
			log.Fatal(err)
		}

		switch flg {
		case 1:
			fmt.Println()
			fmt.Println("Welcome to Weapon/Armor Shop!")
			fmt.Println()

			time.Sleep(time.Millisecond * 500)
			esh.ShowItemList()

			break
		case 2:
			fmt.Println()
			fmt.Println("Welcome to Potion Shop!")
			fmt.Println()

			time.Sleep(time.Millisecond * 500)
			psh.ShowItemList()

			break
		case 3:
			break SHOP_SELECTION
		default:
			fmt.Println()
			fmt.Println("Invalid number! Try again.")

			continue SHOP_SELECTION
		}
	}
}

func InitEquipmentShop() *shop.Shop {
	eqps := make([]shop.Item, 0)
	eqps = append(eqps, item.NewWeapon("Sword", "Medium DMG", 3, 10, 10))
	eqps = append(eqps, item.NewWeapon("Cap", "Light Armor", 1, 5, 5))
	eqps = append(eqps, item.NewWeapon("Gloves", "Light Armor", 1, 5, 5))
	eqps = append(eqps, item.NewWeapon("Axe", "High DMG", 5, 15, 15))
	eqps = append(eqps, item.NewWeapon("Boots", "Light Armor", 1, 5, 5))

	esh := shop.NewShop("Weapon/Armor Shop", eqps)
	return esh
}

func InitPotionShop() *shop.Shop {
	pots := make([]shop.Item, 0)
	pots = append(pots, item.NewPotion("Small Health Potion", "Recovery 100 HP", 2, 5, "Health", 100))
	pots = append(pots, item.NewPotion("Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50))
	pots = append(pots, item.NewPotion("Medium Health Potion", "Recovery 200 HP", 4, 120, "Health", 200))
	pots = append(pots, item.NewPotion("Small Health Potion", "Recovery 100 MP", 2, 75, "Mana", 100))
	pots = append(pots, item.NewPotion("Large Health Potion", "Recovery 300 HP", 6, 200, "Health", 300))

	psh := shop.NewShop("Potion Shop", pots)
	return psh
}
