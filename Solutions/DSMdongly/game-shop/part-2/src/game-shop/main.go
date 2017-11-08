package main

import (
	"game-shop/item"
)

func main() {
	wep := item.NewWeapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24)
	wep.Describe()

	arm := item.NewArmor("Steel Armor", "Protective covering made by steel", 15, 805, 18)
	arm.Describe()
}
