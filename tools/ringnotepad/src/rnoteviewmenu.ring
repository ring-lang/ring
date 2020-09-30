# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteViewMenu

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

