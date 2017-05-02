/*
**	Project : Form Designer 
**	File Purpose :  Window Flags Window
**	Date : 2017.04.27
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "windowflagsView.ring"

import formdesigner

if IsMainSourceFile() { 
	new qApp {
		StyleFusion()
		open_window(:windowflagsController)
		exec()
	}
}

package formdesigner

class windowflagscontroller from windowsControllerParent

	oView = new windowflagsView {
		win.setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint )
		ListHints.setselectionmode(QAbstractItemView_MultiSelection)
		win.setwindowmodality(2)
	}

	aTypeList = [ "Qt_Window"  , "Qt_dialog"  , "Qt_sheet"  ,
			"Qt_Drawer"  , "Qt_popup"  , "Qt_Tool"  , "Qt_ToolTip"  ,
			"Qt_SplashScreen"  ]

	aHintsList = ["Qt_WindowTitleHint"  ,
			"Qt_WindowSystemMenuHint"  ,
			"Qt_WindowMinimizeButtonHint"  ,
			"Qt_WindowMaximizeButtonHint"  ,
			"Qt_WindowCloseButtonHint" ,
			"Qt_WindowContextHelpButtonHint"  ,
			"Qt_WindowShadeButtonHint" ,
			"Qt_WindowStaysOnTopHint"  ,
			"Qt_WindowStaysOnBottomHint"  ,
			"Qt_CustomizeWindowHint" ]

	cFlags = ""	# The window output

	nPropertyIndex = 6

	func LoadSelectedItems
		oPropertiesTable = parent().oView.oPropertiesTable
		cItems = oPropertiesTable.item(nPropertyIndex,1).Text()
		aItems = split(cItems,"|")
		for item in aItems {
			item = trim(item)	
			nPos = find(aTypeList,item)
			if nPos {
				oView.ListType.item(nPos-1).setSelected(True)
				loop 
			}	
			nPos = find(aHintsList,item)
			if nPos {
				oView.ListHints.item(nPos-1).setSelected(True)
				loop 
			}					
		}

	func OkAction
		cFlags = ""
		nType = oView.ListType.currentrow() + 1
		cFlags += aTypeList[nType]
		for x = 1 to len(aHintsList) {
			if oView.ListHints.item(x-1).isSelected() {
				cFlags += " | " + aHintsList[x]
			}
		}
		oPropertiesTable = parent().oView.oPropertiesTable
		# Set the Window Flags
			oPropertiesTable.Blocksignals(True)
			oPropertiesTable.item(nPropertyIndex,1).settext(cFlags)
			oPropertiesTable.Blocksignals(False)
		parent().oModel.FormObject().setWindowFlagsValue(cFlags)
		oView.Close()

	func CancelAction
		oView.Close()
