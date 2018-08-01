# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Class RNoteProgramMenu

	func pDebug
		if cActiveFileName = Null return pNofileopened() ok
		pSave()
		pDebugOperation(cActiveFileName)

	func pRun
		if cActiveFileName = Null return pNofileopened() ok
		pSave()
		pRunOperation(cActiveFileName)

	func pRunNoConsole
		if cActiveFileName = Null return pNofileopened() ok
		pSave()
		oDockOutputWindow { show() raise() }		
		pRunGUIOperation(cActiveFileName)

	func RunInBrowser
		if cActiveFileName = Null return pNofileopened() ok
		pSave()	
		RunWebApplication(this.cActiveFileName)

