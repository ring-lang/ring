# Form/Window Controller - Source Code File

load "objectsorderView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:objectsorderController)
		exec()
	}
}

class objectsorderController from windowsControllerParent

	oView = new objectsorderView {
		win.setwindowmodality(2)
		# Translation
			win.setWindowTitle(T_FORMDESIGNER_OBJSORD_TITLE)
			win.setLayoutDirection(T_LAYOUTDIRECTION)
			labelobjects.setText(T_FORMDESIGNER_OBJSORD_OBJECTS)
			btnUp.setText(T_FORMDESIGNER_OBJSORD_MOVEUP)
			btnDown.setText(T_FORMDESIGNER_OBJSORD_MOVEDOWN)
			btnClose.setText(T_FORMDESIGNER_OBJSORD_CLOSE)
	}

	func LoadObjects
		aList = formdesigner().oModel.getObjectsNames()
		for t = 2 to len(aList) {
			item = aList[t]
			oView.listObjects.additem(item)
		}

	func MoveUp
		nIndex = oView.listObjects.currentrow()
		if nIndex <= 1 { return }
		formdesigner().oModel.MoveObjectUp(nIndex)
		oView.listObjects.clear()
		LoadObjects()
		formdesigner().addobjectsToCombo()
		oView.listObjects.setcurrentrow(nIndex-1,0)

	func MoveDown
		nIndex = oView.listObjects.currentrow()
		if nIndex = 0 or nIndex = oView.listObjects.count() { return }
		formdesigner().oModel.MoveObjectDown(nIndex)
		oView.listObjects.clear()
		LoadObjects()
		formdesigner().addobjectsToCombo()
		oView.listObjects.setcurrentrow(nIndex+1,0)

	func Close 
		oView.win.close()

