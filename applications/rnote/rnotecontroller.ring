# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteController from RNoteControllerBase 

	LoadSettings()

	CreateMainWindow()

	func pTextChanged
		lAskToSave = true
		pSetFont()
		pSetActiveLineColor()

	func pCursorPositionChanged
		nLine = textedit1.textcursor().blocknumber()+1
		StatusMessage(" Line : "+nLine+
					" Column : " +(textedit1.textcursor().columnnumber()+1) +
					" Total Lines : " + textedit1.document().linecount())
		pSetActiveLineColor()
		aFilesLines[cActiveFileName] = nLine

	func pCheckSaveBeforeChange
		if cActiveFileName = NULL return ok
		pSaveSettings()

	func pChangeFile
		pCheckSaveBeforeChange()	# To ask to saving a file
		pSaveCurrentFolder()
		oItem = tree1.currentindex()
		if ofile.isdir(oItem)
			return
		ok
		# Open Form Designer File 
		lActivateFormDesigner = False
		if right(ofile.filepath(oItem),6) = ".rform"
			StatusMessage("Open the form file...")
			if ofile.filepath(oItem) != cFormFile 
				cFormFile = ofile.filepath(oItem)
				FormDesigner().OpenFile(ofile.filepath(oItem))
			ok
			StatusMessage("Ready!")
			oDockFormDesigner.raise()
			cSourceFile = substr(cFormFile,".rform","controller.ring")
			if fexists(cSourceFile)
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
		textedit1.setPlaintext(read(cActiveFileName))
		textedit1.setfocus(0)
		pCursorPositionChanged()
		pSetActiveFileName()
		if nLine != NULL
			gotoline(nLine)
		ok
		AutoComplete()
		lAsktoSave = False
		cTextHash  = sha256(textedit1.toplaintext())
		oDockFunctionsList.setWindowTitle("Functions (Loading...)")
		oDockClassesList.setWindowTitle("Classes (Loading...)")
		DisplayFunctionsList()
		DisplayClassesList()
		if lActivateFormDesigner
			oDockFormDesigner.raise()
		else 
			oDockSourceCode.raise()
			tree1.setFocus(0)
		ok
		StatusMessage("Ready!")

	func pSaveCurrentFolder
		oItem = tree1.currentindex()
		if ofile.isdir(oItem)
			cStartupFolder = ofile.filepath(oItem)
		else
			cFile = ofile.filepath(oItem)
			for t = len(cFile) to 1 step -1
				if cFile[t] = "/" or cFile[t] = "\"
					cFile = left(cFile,t-1)
					exit
				ok
			next
			cStartupFolder = cFile
		ok

	func GetActiveFolder
		return cStartUpFolder

	func pSetActiveFileName
		oDockSourceCode.setWindowTitle("Source Code : " + cActiveFileName)

	func pNofileopened
		New qMessageBox(win1) {
			setWindowTitle("Sorry")
			setText("Save/Select the file first!")
			show()
		}

	func pRingNotepadXButton
		pSaveSettings() 

	func StatusMessage cMsg
		status1.showmessage(cMsg,0)

