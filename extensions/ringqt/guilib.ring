Load "qt.rh"
Load "ring_qt.ring"
Load "objectslib/objects.ring"
Load "objectslib/subwindows.ring"

if iswindows()
	LoadLib("ringqt.dll")
but ismacosx()
	LoadLib("libringqt.dylib")
else
	LoadLib("libringqt.so")
ok

GUILib = new GUILib

func setwinicon pWindow,cImage		
	pWindow.setWindowIcon(new qicon(new qpixmap(cImage)))
		
func setbtnimage pBtn,cImage
	pBtn.setIcon(new qicon(new qpixmap(cImage)))

Class GUILib

	func objcmp o1,o2
		return ptrcmp(o1.pObject,o2.pObject)

	func findobj aList,o1,nColumn
		return find(aList,o1.pObject,nColumn)	