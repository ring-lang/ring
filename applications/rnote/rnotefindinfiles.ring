# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteFindInFiles 

	func OpenFindInFiles 
		chdir(cCurrentDir+"../findinfiles")
		open_WindowAndLink(:findinfilesController,self)
		FindInFiles().setParentObject(self)
		FindInFiles().setFolder(cStartupFolder)
		chdir(cCurrentDir)

	func FindInFilesSelect cFile,nRow 
		CheckSaveBeforeChange()
		cActiveFileName = cFile 
		openFile(cFile)
		GotoLine(nRow)		
		AutoComplete()
		lAsktoSave = False
		cTextHash  = sha256(textedit1.toplaintext())
		oDockFunctionsList.setWindowTitle("Functions (Loading...)")
		oDockClassesList.setWindowTitle("Classes (Loading...)")
		DisplayFunctionsList()
		DisplayClassesList()
