# Form/Window Controller - Source Code File

load "selobjectsView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:objectsorderController)
		exec()
	}
}

class selobjectsController from windowsControllerParent

	oView = new selobjectsView  {
		ListObjects.setselectionmode(QAbstractItemView_MultiSelection)
		win.setwindowmodality(2)
		# Translation
			win.setWindowTitle(T_FORMDESIGNER_SELOBJECTS_TITLE)
			win.setLayoutDirection(T_LAYOUTDIRECTION)
			labelobjects.setText(T_FORMDESIGNER_SELOBJECTS_OBJECTS)
			btnSelect.setText(T_FORMDESIGNER_SELOBJECTS_SELECT)
			btnClose.setText(T_FORMDESIGNER_SELOBJECTS_CLOSE)
	}

	func LoadObjects
		aList = formdesigner().oModel.getObjectsNames()
		for t = 2 to len(aList) {
			item = aList[t]
			oView.listObjects.additem(item)
		}

	func Select
		formdesigner().CancelSelectedObjects()
		aObjects = formdesigner().oModel.GetObjects()
		for x = 1 to oView.ListObjects.count() {
			if oView.ListObjects.item(x).isSelected() {
				nPos = x + 1
				item = aObjects[nPos]
				oObject = item[2]
				oObject.oCorners.Show()
				formdesigner().oModel.AddSelectedObject(nPos)
			}
		}
		close()

 	func Close 
		oView.win.close()

