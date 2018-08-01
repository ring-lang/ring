# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteFindInFiles 

	func pFindInFiles 
		chdir(cCurrentDir+"../findinfiles")
		open_WindowAndLink(:findinfilesController,self)
		FindInFiles().setParentObject(self)
		chdir(cCurrentDir)

	func FindInFilesSelect cFile,nRow 
		pCheckSaveBeforeChange()
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
