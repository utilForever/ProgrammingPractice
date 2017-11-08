package item

import "fmt"

type Weapon struct {
	Item
	Damage int
}

func NewWeapon(nme string, dsc string, wgt int, val int, dmg int) *Weapon {
	return &Weapon{
		Item:   *NewItem(nme, dsc, wgt, val),
		Damage: dmg,
	}
}

func (wep Weapon) Describe() {
	wep.Item.Describe()
	fmt.Printf("Damage      = %d\n", wep.Damage)
}
