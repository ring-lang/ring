# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Class RNoteFileMenu

	func pNew
		new qfiledialog(this.win1) {
			this.SaveCurrentFolder()
			cName = getsavefilename(this.win1,"New file",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				write(cName,"")
				this.cActiveFileName = cName
				this.textedit1.setPlaintext(read(this.cActiveFileName))
				this.SetActiveFileName()
				this.oDockSourceCode.raise()
			ok
		}

	func pOpen
		new qfiledialog(this.win1) {
			this.SaveCurrentFolder()
			cName = getopenfilename(this.win1,"open file",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				this.openFile(cName)
				this.oDockSourceCode.raise()
			ok
		}

	func OpenFile cName
		this.cActiveFileName = cName
		this.textedit1.setPlaintext(read(this.cActiveFileName))
		this.SetActiveFileName()

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
			this.SaveCurrentFolder()
			cName = getsavefilename(this.win1,"Save As",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				this.cActiveFileName = cName
				this.writefile(this.cActiveFileName,this.textedit1.toplaintext())
				this.StatusMessage("File : " + this.cActiveFileName + " saved!")
				this.SetActiveFileName()
				lAskToSave = false
				cTextHash  = sha256(this.textedit1.toplaintext())
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

	func pQuit
		pSaveSettings()
		myapp.quit()

