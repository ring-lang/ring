# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Class RNoteViewMenu

	func pProject
		oDockProjectFiles { if isvisible() hide() else Show() ok }

	func pSourceCode
		oDockSourceCode   { if isvisible() hide() else Show() ok }

	func pWebBrowser
		oDockWebBrowser	  { if isvisible() hide() else Show() ok }

	func pFunctionsList
		oDockFunctionsList {
			if isvisible()
				hide()
			else
				Show()
				this.DisplayFunctionsList()
			ok
		}

	func pClassesList
		oDockClassesList {
			if isvisible()
				hide()
			else
				Show()
				this.DisplayClassesList()
			ok
		}

	func pOutputWindow
		oDockOutputWindow {
			if isvisible()
				hide()
			else
				Show()
			ok	
		}

	func pFormDesignerWindow
		oDockFormDesigner {
			if isvisible()
				hide()
			else
				Show()
			ok
		}

