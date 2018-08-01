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

	func pSave
		if cActiveFileName = NULL return pSaveAs() ok
		writefile(cActiveFileName,textedit1.toplaintext())
		StatusMessage("File : " + cActiveFileName + " saved!")
		lAskToSave = false
		cTextHash  = sha256(textedit1.toplaintext())
		AutoComplete()
		displayFunctionsList()
		displayClassesList()
		# Save Active Form in the Form Designer
			if isFormDesigner()
				FormDesigner().SaveIfOnlyFileIsOpened()
			ok
			StatusMessage("Ready!")

	func pSaveAs
		new qfiledialog(win1) {
			this.pSaveCurrentFolder()
			cName = getsavefilename(this.win1,"Save As",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				this.cActiveFileName = cName
				this.writefile(this.cActiveFileName,this.textedit1.toplaintext())
				this.StatusMessage("File : " + this.cActiveFileName + " saved!")
				this.pSetActiveFileName()
				lAskToSave = false
				cTextHash  = sha256(this.textedit1.toplaintext())
			ok
		}

	func pOpen
		new qfiledialog(this.win1) {
			this.pSaveCurrentFolder()
			cName = getopenfilename(this.win1,"open file",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				this.openFile(cName)
				this.oDockSourceCode.raise()
			ok
		}

	func OpenFile cName
		this.cActiveFileName = cName
		this.textedit1.setPlaintext(read(this.cActiveFileName))
		this.pSetActiveFileName()

	func pNew
		new qfiledialog(this.win1) {
			this.pSaveCurrentFolder()
			cName = getsavefilename(this.win1,"New file",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				write(cName,"")
				this.cActiveFileName = cName
				this.textedit1.setPlaintext(read(this.cActiveFileName))
				this.pSetActiveFileName()
				this.oDockSourceCode.raise()
			ok
		}

	func WriteFile cFileName,cCode
		aCode = str2list(cCode)
		fp = fopen(cFileName,"wb")
		for cLine in aCode
			fwrite(fp,cLine+char(13)+char(10))
		next
		fclose(fp)

	func pPrint
		StatusMessage("Printing to File : RingDoc.pdf")
		printer1 = new qPrinter(0) {
			setoutputformat(1)	# 1 = pdf
			setoutputfilename(this.cCurrentDir+"RingDoc.pdf")
			this.textedit1.print(printer1)
		}
		StatusMessage("Done!")
		new QDesktopServices {
			OpenURL(new qURL("file:///"+substr(this.cCurrentDir,"\","/")+"RingDoc.pdf")) 
		}

	func pRingNotepadXButton
		pSaveSettings() 

	func pQuit
		pSaveSettings()
		myapp.quit()

	func StatusMessage cMsg
		status1.showmessage(cMsg,0)

