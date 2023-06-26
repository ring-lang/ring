# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteProgramMenu

	func Debug
		if cActiveFileName = Null return Nofileopened() ok
		Save()
		DebugOperation(cActiveFileName)

	func Run
		if cActiveFileName = Null return Nofileopened() ok
		Save()
		RunOperation(cActiveFileName)

	func RunNoConsole
		if cActiveFileName = Null return Nofileopened() ok
		Save()
		oDockOutputWindow { show() raise() }		
		RunGUIOperation(cActiveFileName)

	func RunInBrowser
		if cActiveFileName = Null return Nofileopened() ok
		Save()	
		RunWebApplication(this.cActiveFileName)
