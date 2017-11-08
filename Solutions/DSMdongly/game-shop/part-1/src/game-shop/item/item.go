package item

import (
	"fmt"
)

type Item struct {
	Name        string
	Description string
	Weight      int
	Value       int
}

func NewItem(nme string, dsc string, wgt int, val int) *Item {
	return &Item{
		Name:        nme,
		Description: dsc,
		Weight:      wgt,
		Value:       val,
	}
}

func (ite Item) Describe() {
	fmt.Println()
	fmt.Printf("Name        = %s\n", ite.Name)
	fmt.Printf("Description = %s\n", ite.Description)
	fmt.Printf("Weight      = %d lbs\n", ite.Weight)
	fmt.Printf("Value       = %d gold coins\n", ite.Value)
}
