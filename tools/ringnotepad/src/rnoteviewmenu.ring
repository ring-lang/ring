# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteViewMenu

	func ActivateProjectWindow
		oDockProjectFiles { show() raise() }

	func ActivateSourceCodeWindow
		oDockSourceCode { show() raise() }

	func ActivateWebBrowserWindow
		oDockWebBrowser { show() raise() }

	func ActivateFunctionsListWindow
		oDockFunctionsList { show() raise() }
		this.DisplayFunctionsList()

	func ActivateClassesListWindow
		oDockClassesList { show() raise() }
		this.DisplayClassesList()

	func ActivateOutputWindow
		oDockOutputWindow { show() raise() }

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

