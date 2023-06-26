# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteMainFileToolbar

	func SetMainFile
		oTxtMainFile.setText(cActiveFileName)

	func GetMainFile
		cMainFileName = trim(oTxtMainFile.text())
		if cMainFileName = NULL 
			SetMainFile() 
			cMainFileName = trim(oTxtMainFile.text())
		ok
		return cMainFileName

	func DebugMainFile
		cMainFileName = GetMainFile()
		if cMainFileName = Null return Nofileopened() ok
		if not fexists(FileNameEncoding(cMainFileName)) return ok
		Save()
		DebugOperation(cMainFileName)

	func RunMainFile
		cMainFileName = GetMainFile()
		if cMainFileName = Null return Nofileopened() ok
		if not fexists(FileNameEncoding(cMainFileName)) return ok
		Save()
		RunOperation(cMainFileName)

	func RunGUIMainFile
		cMainFileName = GetMainFile()
		if cMainFileName = Null return Nofileopened() ok
		if not fexists(FileNameEncoding(cMainFileName)) return ok
		oDockOutputWindow { show() raise() }		
		Save()
		RunGUIOperation(cMainFileName)

	func RunInBrowserMainFile
		cMainFileName = GetMainFile()
		if cMainFileName = Null return Nofileopened() ok
		if not fexists(FileNameEncoding(cMainFileName)) return ok
		Save()
		if ! checkWebApplication(cMainFileName) return ok
		RunWebApplication(cMainFileName)

