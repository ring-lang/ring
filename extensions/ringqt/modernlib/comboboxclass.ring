package System.GUI

	class ComboBox from qComboBox

		func CurrentIndex
			return Super.CurrentIndex() + 1

		func SetCurrentIndex nIndex
			return Super.SetCurrentIndex(nIndex - 1)

		func FindData p1,p2,p3
			return Super.FindData(p1,p2,p3)+1

		func FindText p1,p2
			return Super.FindText(p1,p2)+1

		func InsertItem nIndex,p2,p3
			return Super.InsertItem(nIndex-1,p2,p3)	

		func ItemData nIndex,p2
			return Super.ItemData(nIndex-1,p2)

		func ItemIcon nIndex 
			return Super.ItemIcon(nIndex-1)

		func ItemText nIndex 
			return Super.ItemText(nIndex-1)

		func RemoveItem nIndex 
			return Super.RemoveItem(nIndex-1)

		func SetItemIcon nIndex,p2
			return Super.SetItemIcon(nIndex-1,p2)

		func SetItemText nIndex,p2
			return Super.SetItemText(nIndex-1,p2)

		func ModelColumn 
			return Super.ModelColumn()+1

		func SetModelColumn nIndex
			return Super.SetModelColumn(nIndex-1)		

