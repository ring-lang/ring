GUILib = new GUILib

Class GUILib

	func objcmp o1,o2
		return ptrcmp(o1.pObject,o2.pObject)

	func findobj aList,o1,nColumn
		return find(aList,o1.pObject,nColumn)

