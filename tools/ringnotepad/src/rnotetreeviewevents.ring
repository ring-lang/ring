# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteTreeViewEvents

	func CheckSaveBeforeChange
		if cActiveFileName = NULL return ok
		SaveSettings()

	func ChangeFile
		CheckSaveBeforeChange()	# To ask to saving a file
		SaveCurrentFolder()
		oItem = tree1.currentindex()
		if ofile.isdir(oItem)
			return
		ok
		# Save the old file 
			cOldActiveFileName = cActiveFileName
		# Open Form Designer File 
		lActivateFormDesigner = False
		if right(ofile.filepath(oItem),6) = ".rform"
			StatusMessage(T_RINGNOTEPAD_TREEOPENFORMFILE) # "Open the form file..."
			if ofile.filepath(oItem) != cFormFile 
				cFormFile = ofile.filepath(oItem)
				FormDesigner().OpenFile(ofile.filepath(oItem))
			ok
			StatusMessage(T_RINGNOTEPAD_TREEREADY) # "Ready!"
			oDockFormDesigner.raise()
			cSourceFile = substr(cFormFile,".rform","Controller.ring")
			if fexists(FileNameEncoding(cSourceFile))
				cActiveFileName = cSourceFile
			else 
				return 
			ok
			lActivateFormDesigner = True
		else 
			cActiveFileName = ofile.filepath(oItem)
		ok
		# We get nLine before using textedit1.settext() to get the value before aFilesLines update
			nLine =  aFilesLines[cActiveFileName]
		try 
			textedit1.setPlaintext(read(FileNameEncoding(cActiveFileName)))
		catch 
			msginfo(T_RINGNOTEPAD_TREESORRY,T_RINGNOTEPAD_TREECANTOPENFILE + cActiveFileName)
			cActiveFileName = cOldActiveFileName
			return 
		end 
		textedit1.setfocus(0)
		CursorPositionChanged()
		SetActiveFileName()
		if nLine != NULL
			gotoline(nLine)
		ok
		AutoComplete()
		lAsktoSave = False
		cTextHash  = sha256(textedit1.toplaintext())
		DisplayFunctionsAndClasses()
		if lActivateFormDesigner
			oDockFormDesigner.raise()
		else 
			oDockSourceCode.raise()
			tree1.setFocus(0)
		ok
		StatusMessage(T_RINGNOTEPAD_TREEREADY) # "Ready!"

	func DisplayFunctionsAndClasses
		oDockFunctionsList.setWindowTitle(T_RINGNOTEPAD_TREELOADFUNCS) # "Functions (Loading...)"
		oDockClassesList.setWindowTitle(T_RINGNOTEPAD_TREELOADCLASSES) # "Classes (Loading...)"
		DisplayFunctionsList()
		DisplayClassesList()
