/*
**	Project : Form Designer 
**	File Purpose :  Window Objects - Controller Class
**	Date : 2017.04.27
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "windowobjectsView.ring"

package formdesigner

class windowObjectscontroller from windowsControllerParent

	oView = new windowObjectsView {
		win.setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint )
		ListObjects.setselectionmode(QAbstractItemView_MultiSelection)
		win.setwindowmodality(2)
	}

	aObjectsList = []

	nPropertyIndex = C_AFTERCOMMON+1
	cMethodName = "setLayoutObjectsValue"

	func SetPropertyIndex nValue
		nPropertyIndex = nValue

	func SetMethodName cName
		cMethodName = cName

	func LoadObjectsData aList
		aObjectsList = aList
		for item in aObjectsList {
			oView.ListObjects.AddItem(item)
		}

	func OkAction
		cObjects = ""
		for x = 1 to len(aObjectsList) {
			if oView.ListObjects.item(x-1).isSelected() {
				if not cObjects = NULL {
					cObjects += "," + aObjectsList[x]
				else
					cObjects += aObjectsList[x]
				}
			}
		}
		oPropertiesTable = parent().oView.oPropertiesTable
		# Set the Window Flags
			oPropertiesTable.Blocksignals(True)
			oPropertiesTable.item(nPropertyIndex,1).settext(cObjects)
			oPropertiesTable.Blocksignals(False)
		cCode = "parent().oModel.ActiveObject()."+cMethodName+"(cObjects)"
		eval(cCode)
		oView.Close()

	func CancelAction
		oView.Close()
