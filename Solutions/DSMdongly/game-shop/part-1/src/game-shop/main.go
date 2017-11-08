package main

import (
	"game-shop/item"
)

func main() {
	swd := item.NewItem("Excalibur", "The legendary sword of King Arthur", 12, 1024)
	swd.Describe()

	arm := item.NewItem("Steel Armor", "Protective covering made by steel", 15, 805)
	arm.Describe()
}
