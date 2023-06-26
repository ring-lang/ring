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

	func checkWebApplication cFileName
		if left(read(cFileName),2) != "#!"
			msginfo(T_RINGNOTEPAD_NOTWEBAPPSORRY,T_RINGNOTEPAD_NOTWEBAPPMSG)
			return false 
		ok
		return true 

	func RunInBrowser
		if cActiveFileName = Null return Nofileopened() ok
		Save()	
		if ! checkWebApplication(cActiveFileName) return ok
		RunWebApplication(cActiveFileName)
