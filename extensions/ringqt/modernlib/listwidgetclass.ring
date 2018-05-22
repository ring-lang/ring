package System.GUI

	class ListWidget from qListWidget

		func CurrentRow
			return Super.CurrentRow()+1

		func SetCurrentRow nIndex,nOptions
			return Super.SetCurrentRow(nIndex-1,nOptions)

		func item nIndex 
			return super.item(nIndex-1)

		func itemat nX,nY
			return super.itemAt(nX-1,nY-1)
	
		func row oItem
			return super.row(oItem)+1

		func TakeItem nIndex 
			return super.TakeItem(nIndex-1)		

