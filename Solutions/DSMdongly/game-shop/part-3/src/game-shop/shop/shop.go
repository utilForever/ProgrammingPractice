package shop

type Item interface {
	Describe()
}

type Shop struct {
	Name  string
	Items []Item
}

func NewShop(nme string, ites []Item) *Shop {
	return &Shop{
		Name:  nme,
		Items: ites,
	}
}

func (shp Shop) ShowItemList() {
	for _, ite := range shp.Items {
		ite.Describe()
	}
}
