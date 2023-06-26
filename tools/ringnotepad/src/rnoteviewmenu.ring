# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteViewMenu

	func ActivateProjectWindow
		oDockProjectFiles { show() raise() }
		Tree1.setFocus(0)
		oCheckAction1.setChecked(True)

	func ActivateSourceCodeWindow
		oDockSourceCode { show() raise() }
		TextEdit1.setFocus(0)
		oCheckAction2.setChecked(True)

	func ActivateWebBrowserWindow
		oDockWebBrowser { show() raise() }
		oWBText.setFocus(0)
		oCheckAction3.setChecked(True)

	func ActivateFunctionsListWindow
		oDockFunctionsList { show() raise() }
		this.DisplayFunctionsList()
		oFunctionsList.setFocus(0)
		oCheckAction4.setChecked(True)

	func ActivateClassesListWindow
		oDockClassesList { show() raise() }
		this.DisplayClassesList()
		oClassesList.setFocus(0)
		oCheckAction5.setChecked(True)

	func ActivateOutputWindow
		oDockOutputWindow { show() raise() }
		oProcessText.setFocus(0)
		oCheckAction6.setChecked(True)

	func ActivateFormDesignerWindow
		oDockFormDesigner { show() raise() }
		oCheckAction7.setChecked(True)

	func ProjectWindowStatus
		oDockProjectFiles { if isvisible() hide() else Show() ok }

	func SourceCodeWindowStatus
		oDockSourceCode   { if isvisible() hide() else Show() ok }

	func WebBrowserWindowStatus
		oDockWebBrowser	  { if isvisible() hide() else Show() ok }

	func FunctionsListWindowStatus
		oDockFunctionsList {
			if isvisible()
				hide()
			else
				Show()
				this.DisplayFunctionsList()
			ok
		}

	func ClassesListWindowStatus
		oDockClassesList {
			if isvisible()
				hide()
			else
				Show()
				this.DisplayClassesList()
			ok
		}

	func OutputWindowStatus
		oDockOutputWindow {
			if isvisible()
				hide()
			else
				Show()
			ok	
		}

	func FormDesignerWindowStatus
		oDockFormDesigner {
			if isvisible()
				hide()
			else
				Show()
			ok
		}

	func RefreshAppearanceMenu
		oCheckAction1.setChecked(oDockProjectFiles.isVisible())
		oCheckAction2.setChecked(oDockSourceCode.isVisible())
		oCheckAction3.setChecked(oDockWebBrowser.isVisible())
		oCheckAction4.setChecked(oDockFunctionsList.isVisible())
		oCheckAction5.setChecked(oDockClassesList.isVisible())
		oCheckAction6.setChecked(oDockOutputWindow.isVisible())
		oCheckAction7.setChecked(oDockFormDesigner.isVisible())

	func CloseDockable nDock
		Switch nDock 
			on 1
				oCheckAction1.setChecked(False)
			on 2
				oCheckAction2.setChecked(False)
			on 3
				oCheckAction3.setChecked(False)
			on 4
				oCheckAction4.setChecked(False)
			on 5
				oCheckAction5.setChecked(False)
			on 6
				oCheckAction6.setChecked(False)
			on 7
				oCheckAction7.setChecked(False)
		off
