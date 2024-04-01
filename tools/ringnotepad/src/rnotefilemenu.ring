# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteFileMenu

	func NewFile
		new qfiledialog(this.win1) {
			this.SaveCurrentFolder()
			cName = getsavefilename(this.win1,T_RINGNOTEPAD_FILEMENUNEWFILE,this.cStartupFolder,T_RINGNOTEPAD_FILEMENUFILETYPE)
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
			cName = getopenfilename(this.win1,T_RINGNOTEPAD_FILEMENUOPENFILE,this.cStartupFolder,T_RINGNOTEPAD_FILEMENUFILETYPE)
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
			msginfo(T_RINGNOTEPAD_FILEMENUSORRY,T_RINGNOTEPAD_FILEMENUCANTOPEN + cName)
		done

	func refereshFileInfo
 		lAskToSave = false
		cTextHash  = sha256(textedit1.toplaintext())
		AutoComplete()
		displayFunctionsList()
		displayClassesList()

	func Save
		if cActiveFileName = NULL return SaveAs() ok
		writefile(cActiveFileName,textedit1.toplaintext())
		StatusMessage(T_RINGNOTEPAD_FILEMENUFILE + cActiveFileName + T_RINGNOTEPAD_FILEMENUSAVE)
		refereshFileInfo()
		# Save Active Form in the Form Designer
			if isFormDesigner()
				FormDesigner().SaveIfOnlyFileIsOpened()
			ok
			StatusMessage(T_RINGNOTEPAD_FILEMENUREADY)

	func SaveAs
		new qfiledialog(win1) {
			this.SaveCurrentFolder()
			cName = getsavefilename(this.win1,T_RINGNOTEPAD_FILEMENUSAVEAS,this.cStartupFolder,T_RINGNOTEPAD_FILEMENUFILETYPE)
			if cName != NULL
				# Check removing .ring if we have another extension 
					cName = this.OneExtension(cName)
				this.cActiveFileName = cName
				this.writefile(this.cActiveFileName,this.textedit1.toplaintext())
				this.StatusMessage(T_RINGNOTEPAD_FILEMENUFILE + this.cActiveFileName + T_RINGNOTEPAD_FILEMENUSAVE)
				this.aFilesLines[this.cActiveFileName] = 1
				this.SetActiveFileName()
				this.refereshFileInfo()
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
	    # Starting from Ring 1.16 - We don't need this function
		if number(version()) <= 1.15
			if isWindows()
				oString = new qString2()
				oString.Append(cFileName)
				return oString.tolocal8bit().data()
			ok
		ok
		return cFileName

	func Print
		StatusMessage(T_RINGNOTEPAD_FILEMENUPRINTING)
		printer1 = new qPrinter(0) {
			setoutputformat(1)	# 1 = pdf
			setoutputfilename(this.cCurrentDir+T_RINGNOTEPAD_FILEMENUOUTFILE)
			this.textedit1.print(printer1)
		}
		StatusMessage(T_RINGNOTEPAD_FILEMENUDONE)
		new QDesktopServices {
			OpenURL(new qURL("file:///"+substr(this.cCurrentDir,"\","/")+T_RINGNOTEPAD_FILEMENUOUTFILE)) 
		}

	func Quit
		RingNotepadXButton()
