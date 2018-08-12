package System.GUI

	class TreeWidget from qTreeWidget

		func currentColumn 
			return Super.currentColumn() + 1

		func editItem p1,p2
			return Super.editItem(p1,p2-1)

		func indexOfTopLevelItem p1
			return Super.indexOfTopLevelItem(p1)+1

		func insertTopLevelItem p1,p2
			return Super.insertTopLevelItem(p1-1,p2)

		func itemAt p1,p2
			return Super.itemAt(p1-1,p2-1)

		func itemWidget p1,p2
			return Super.itemWidget(p1,p2-1)

		func openPersistentEditor p1,p2
			return Super.openPersistentEditor(p1,p2-1)
	
		func removeItemWidget p1,p2
			return Super.removeItemWidget(p1,p2-1)

		func setItemWidget p1,p2,p3
			return Super.setItemWidget(p1,p2-1,p3)

		func takeTopLevelItem p1
			return Super.takeTopLevelItem(p1-1)

		func topLevelItem p1
			return Super.topLevelItem(p1-1)		

