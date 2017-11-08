package item

import "fmt"

type Armor struct {
	Item
	Defense int
}

func NewArmor(nme string, dsc string, wgt int, val int, def int) *Armor {
	return &Armor{
		Item:    *NewItem(nme, dsc, wgt, val),
		Defense: def,
	}
}

func (arm Armor) Describe() {
	arm.Item.Describe()
	fmt.Printf("Defense     = %d\n", arm.Defense)
}
