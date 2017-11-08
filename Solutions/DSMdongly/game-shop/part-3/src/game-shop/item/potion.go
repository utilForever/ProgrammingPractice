package item

import "fmt"

type Potion struct {
	Item
	Type     string
	Capacity int
}

func NewPotion(nme string, dsc string, wgt int, val int, typ string, cap int) *Potion {
	return &Potion{
		Item:     *NewItem(nme, dsc, wgt, val),
		Type:     typ,
		Capacity: cap,
	}
}

func (pot Potion) Describe() {
	pot.Item.Describe()
	fmt.Printf("Type        = %s\n", pot.Type)
	fmt.Printf("Capacity    = %d\n", pot.Capacity)
}
