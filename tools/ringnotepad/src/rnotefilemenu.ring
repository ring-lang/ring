# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteFileMenu

	func NewFile
		new qfiledialog(this.win1) {
			this.SaveCurrentFolder()
			cName = getsavefilename(this.win1,"New file",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				# Check removing .ring if we have another extension 
					cName = this.OneExtension(cName)
				write(this.FileNameEncoding(cName),"")
				this.cActiveFileName = cName
				this.textedit1.setPlaintext(read(this.FileNameEncoding(this.cActiveFileName)))
				this.SetActiveFileName()
				this.oDockSourceCode.raise()
			ok
		}

	func OneExtension cName
		cFolder = JustFilePath(cName)
		cName = JustFileName(cName)
		# Check removing .ring if we have another extension
			nPos = substr(cName,".")
			if nPos > 0 and nPos < len(cName)-4
				cName = left(cName,len(cName)-5)
			else 
				if nPos = 0
					cName += ".ring"
				ok
			ok
		cName = cFolder + cName
		return cName

	func Open
		CheckSaveBeforeChange()	# To ask about saving a file
		new qfiledialog(this.win1) {
			this.SaveCurrentFolder()
			cName = getopenfilename(this.win1,"open file",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				this.openFile(cName)
				this.oDockSourceCode.raise()
			ok
		}

	func OpenFile cName
		try
			textedit1.setPlaintext(read(FileNameEncoding(cName)))
			cActiveFileName = cName
			this.aFilesLines[this.cActiveFileName] = 1
			SetActiveFileName()
			lAsktoSave = False
			cTextHash  = sha256(textedit1.toplaintext())
			DisplayFunctionsAndClasses()
		catch 
			msginfo("Sorry","Can't open the file : " + cName)
		done

	func Save
		if cActiveFileName = NULL return SaveAs() ok
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

	func SaveAs
		new qfiledialog(win1) {
			this.SaveCurrentFolder()
			cName = getsavefilename(this.win1,"Save As",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				# Check removing .ring if we have another extension 
					cName = this.OneExtension(cName)
				this.cActiveFileName = cName
				this.writefile(this.cActiveFileName,this.textedit1.toplaintext())
				this.StatusMessage("File : " + this.cActiveFileName + " saved!")
				this.aFilesLines[this.cActiveFileName] = 1
				this.SetActiveFileName()
				lAskToSave = false
				cTextHash  = sha256(this.textedit1.toplaintext())
			ok
		}

	func WriteFile cFileName,cCode
		aCode = str2list(cCode)
		cFileName = FileNameEncoding(cFileName)
		fp = fopen(cFileName,"wb")
		if isWindows()
			aLineFeed = char(13)+char(10)
		else
			aLineFeed = char(10)
		ok
		for cLine in aCode
			fwrite(fp,cLine+aLineFeed)
		next
		fclose(fp)

	func FileNameEncoding cFileName
		if isWindows()
			oString = new qString2()
			oString.Append(cFileName)
			return oString.tolocal8bit().data()
		ok
		return cFileName

	func Print
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

	func Quit
		SaveSettings()
		win1.close()
