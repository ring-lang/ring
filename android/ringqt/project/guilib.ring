Load "qt.rh"
Load "ring_qt.ring"
Load "objects.ring"
Load "subwindows.ring"

GUILib = new GUILib

func setwinicon pWindow,cImage
	if cImage = NULL return ok		
	pWindow.setWindowIcon(new qicon(new qpixmap(cImage)))
		
func setbtnimage pBtn,cImage
	if cImage = NULL return ok		
	pBtn.setIcon(new qicon(new qpixmap(cImage)))

Class GUILib

	func objcmp o1,o2
		return ptrcmp(o1.pObject,o2.pObject)

	func findobj aList,o1,nColumn
		return find(aList,o1.pObject,nColumn)	