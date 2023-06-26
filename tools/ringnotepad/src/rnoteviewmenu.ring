# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteViewMenu

	func ActivateProjectWindow
		oDockProjectFiles { show() raise() }
		Tree1.setFocus(0)

	func ActivateSourceCodeWindow
		oDockSourceCode { show() raise() }
		TextEdit1.setFocus(0)

	func ActivateWebBrowserWindow
		oDockWebBrowser { show() raise() }
		oWBText.setFocus(0)

	func ActivateFunctionsListWindow
		oDockFunctionsList { show() raise() }
		this.DisplayFunctionsList()
		oFunctionsList.setFocus(0)

	func ActivateClassesListWindow
		oDockClassesList { show() raise() }
		this.DisplayClassesList()
		oClassesList.setFocus(0)

	func ActivateOutputWindow
		oDockOutputWindow { show() raise() }
		oProcessText.setFocus(0)

	func ActivateFormDesignerWindow
		oDockFormDesigner { show() raise() }

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

