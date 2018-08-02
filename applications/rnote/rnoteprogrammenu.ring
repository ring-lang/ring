# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Class RNoteProgramMenu

	func Debug
		if cActiveFileName = Null return Nofileopened() ok
		pSave()
		DebugOperation(cActiveFileName)

	func Run
		if cActiveFileName = Null return Nofileopened() ok
		pSave()
		RunOperation(cActiveFileName)

	func RunNoConsole
		if cActiveFileName = Null return Nofileopened() ok
		pSave()
		oDockOutputWindow { show() raise() }		
		RunGUIOperation(cActiveFileName)

	func RunInBrowser
		if cActiveFileName = Null return Nofileopened() ok
		pSave()	
		RunWebApplication(this.cActiveFileName)

