# Form/Window Controller - Source Code File

load "windowflagsView.ring"

if IsMainSourceFile() { 
	new qApp {
		StyleFusion()
		open_window(:windowflagsController)
		exec()
	}
}

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
			oPropertiesTable.item(6,1).settext(cFlags)
			oPropertiesTable.Blocksignals(False)
		parent().oModel.FormObject().setWindowFlagsValue(cFlags)
		oView.Close()

	func CancelAction
		oView.Close()
