# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

# Load Standard Libraries
	load "guilib.ring"
	load "stdlib.ring"

# Load Ring Notepad Files 
	load "rnotebase.ring"
	load "rnoteview.ring"
	load "rnotemode.ring"
	load "rnotestyle.ring"
	load "rnoteautocomplete.ring"
	load "rnotelists.ring"
	load "rnotefind.ring"
	load "rnotegoto.ring"
	load "rnotesettings.ring"
	load "rnotefindinfiles.ring"

# Load the Form Designer 
	load "../formdesigner/formdesigner.ring"

# Load the Web Server - ServerPrepare Class
	load "../libdepwin/Apache2.2/ring/prepare.ring"

# Load the Find in files application 
	load "../findinfiles/findinfilesController.ring"

# Merge Classes 
	mergemethods(:RNoteController,:RNoteView)
	mergemethods(:RNoteController,:RNoteMode)
	mergemethods(:RNoteController,:RNoteStyle)
	mergemethods(:RNoteController,:RNoteAutoComplete)	
	mergemethods(:RNoteController,:RnoteLists)
	mergemethods(:RNoteController,:RnoteFind)
	mergemethods(:RNoteController,:RnoteGoto)
	mergemethods(:RNoteController,:RNoteSettings)
	mergemethods(:RNoteController,:RNoteFindInFiles)

# Create the Ring Notepad Object
	Open_WindowNoShow(:RNoteController)

class RNoteController from RNoteControllerBase 

	LoadSettings()

	CreateMainWindow()

	func pSetActiveLineColor
		textedit1.SetActiveLineColor(aStyleColors[:ActiveLineBackColor])

	func pTextChanged
		lAskToSave = true
		pSetFont()
		pSetActiveLineColor()

	func pWebGo
		cWebsite = oWBText.text()
		oWebView.LoadPage( new qurl( cWebSite ) )

	func pWebBack
		oWebView.Back()

	func pProject
		oDockProjectFiles { if isvisible() hide() else Show() ok }

	func pSourceCode
		oDockSourceCode   { if isvisible() hide() else Show() ok }

	func pWebBrowser
		oDockWebBrowser	  { if isvisible() hide() else Show() ok }

	func pFunctionsList
		oDockFunctionsList {
			if isvisible()
				hide()
			else
				Show()
				this.DisplayFunctionsList()
			ok
		}

	func pClassesList
		oDockClassesList {
			if isvisible()
				hide()
			else
				Show()
				this.DisplayClassesList()
			ok
		}

	func pOutputWindow
		oDockOutputWindow {
			if isvisible()
				hide()
			else
				Show()
			ok	
		}

	func pFormDesignerWindow
		oDockFormDesigner {
			if isvisible()
				hide()
			else
				Show()
			ok
		}

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

	func pSetActiveFileName
		oDockSourceCode.setWindowTitle("Source Code : " + cActiveFileName)

	func pCursorPositionChanged
		nLine = textedit1.textcursor().blocknumber()+1
		StatusMessage(" Line : "+nLine+
					" Column : " +(textedit1.textcursor().columnnumber()+1) +
					" Total Lines : " + textedit1.document().linecount())
		pSetActiveLineColor()
		aFilesLines[cActiveFileName] = nLine

	func pNofileopened
		New qMessageBox(win1) {
			setWindowTitle("Sorry")
			setText("Save/Select the file first!")
			show()
		}

	func pDebug
		if cActiveFileName = Null return pNofileopened() ok
		pSave()
		pDebugOperation(cActiveFileName)

	func pDebugOperation cActiveFileName
		if iswindows()
			cCode = 'start '+cCurrentDir+'run "' + cActiveFileName + '"' + nl
		else
			cCode = 'cd $(dirname "'+cActiveFileName+'") ; ' + ' ring "' + cActiveFileName + '"' + nl
		ok
		system(cCode)

	func pRun
		if cActiveFileName = Null return pNofileopened() ok
		pSave()
		pRunOperation(cActiveFileName)

	func pRunOperation cActiveFileName
		if iswindows()
			cCode = 'start '+cCurrentDir+'run2 "' + cActiveFileName + '"' + nl
		else
			cCode = 'cd $(dirname "'+cActiveFileName+'") ; ' + ' ring "' + cActiveFileName + '"' + nl
		ok
		system(cCode)

	func pRunNoConsole
		if cActiveFileName = Null return pNofileopened() ok
		pSave()
		oDockOutputWindow { show() raise() }		
		pRunGUIOperation(cActiveFileName)

	func pRunGUIOperation cActiveFileName
		oProcessEditbox.setplaintext("")
		chdir(JustFilePath(cActiveFileName))
		oProcess = pRunProcess(cRingEXE,cActiveFileName,cpGetProcessData)
		chdir(exefolder())

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


	func pUndo
		textedit1.undo()
		StatusMessage("Undo!")

	func pCut
		textedit1.cut()
		StatusMessage("Cut!")

	func pCopy
		textedit1.copy()
		StatusMessage("Copy!")

	func pPaste
		textedit1.paste()
		StatusMessage("Paste!")

	func pFont
		oFontDialog = new qfontdialog() {

			this.oTempFont.fromstring(this.cFont)
			setcurrentfont(this.oTempFont)

			aFont = getfont()
		}
		if aFont[1] != NULL
			cFont = aFont[1]
			pSetFont()	# set the new font
		ok

	func pSetFont
		oTempFont.fromstring(cFont)
		oCursor = textedit1.textCursor()
		oCursor.clearselection()
		textedit1.settextcursor(oCursor)
		textedit1.Document().setdefaultfont(oTempFont)

	func pColor
		new qcolordialog() {
			r = exec()
			if r = 0 return ok
			oColor = currentcolor()
			r = oColor.red()
			g = oColor.green()
			b = oColor.blue()
		}
		this.aTextColor = [r,g,b]
		pSetColors()

	func pColor2
		new qcolordialog() {
			r = exec()
			if r = 0 return ok
			oColor = currentcolor()
			r = oColor.red()
			g = oColor.green()
			b = oColor.blue()
		}
		this.aBackColor = [r,g,b]
		pSetColors()

	func pSetColors
		this.textedit1.setstylesheet("QPlainTextEdit { color: rgb(" + aTextColor[1] + "," + aTextColor[2] +
					"," + aTextColor[3] + ");" + "background-color: rgb(" +
					aBackColor[1] + "," + aBackColor[2] + "," +
					aBackColor[3] + ") }")

	func pSetWindows
		if not lShowProject  		oDockProjectFiles.close() else oDockProjectFiles.show() ok
		if not lShowSourceCode  	oDockSourceCode.close() else oDockSourceCode.show() ok
		if not lShowBrowser  		oDockWebBrowser.close() else oDockWebBrowser.show() ok
		if not lShowFunctionsList 	oDockFunctionsList.close() else oDockFunctionsList.show() ok
		if not lShowClassesList 	oDockClassesList.close() else oDockClassesList.show() ok
		if not lShowOutputWindow 	oDockOutputWindow.close() else oDockOutputWindow.show() ok
		if not lShowFormDesigner 	oDockFormDesigner.close() else oDockFormDesigner.show() ok

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

	func MsgBox cTitle,cMessage
		win = new qMessagebox(win1) {
			setwindowtitle(cTitle)
			setText(cMessage)
			setwinicon(win,this.cCurrentDir + "/image/notepad.png")
			show()
		}

	func pLang
		MsgBox("Programming Language",
			"This application developed using the Ring programming language" + nl +
			"Ring Version : " + version())

	func pGUI
		MsgBox("GUI Library",
			"This application uses the Qt GUI Library through RingQt")

	func pAbout
		MsgBox("About",
			"Ring Notepad (Ring Version : " + Version() + ")" + nl +			
			"2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>")

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

	func pRingNotepadXButton
		pSaveSettings() 

	func pSetWebsite
		oWebView { loadpage(new qurl(this.cWebSite)) }
		oWBText  { setText(this.cWebSite) }


	func pQuit
		pSaveSettings()
		myapp.quit()

	func pOpenCHM
		new QDesktopServices {
			OpenURL(new qURL("file:///"+substr(exefolder(),"\","/")+"../docs/ring.chm") )
		}

	func pOpenPDF
		new QDesktopServices {
			OpenURL(new qURL("file:///"+substr(exefolder(),"\","/")+"../docs/ring.pdf") )
		}

	func pTabWidth
		oInput = New QInputDialog(win1)
		{
			setwindowtitle("Set the Tab Width")
			setgeometry(100,100,400,50)
			setlabeltext("Spaces Count")
			settextvalue("1")
			r = exec()
		}
		if r=0 return ok
		nTabSpaces = 0 + oInput.textvalue()
		pSetTabSpaces()

	func pSetTabSpaces
		oTempFont.fromstring(cFont)
		oFontMetrics = new QFontMetrics(oTempFont)
		nSpaceWidth = oFontMetrics.Width(" ",1)
		textedit1.setTabStopWidth(nTabSpaces*nSpaceWidth)

	func pBrowserLink x
		cLink = aBrowserLinks[x][2]
		oWebView { loadpage(new qurl(cLink)) }
		oWBText  { setText(cLink) }
		oDockWebBrowser.Show()
		oDockWebBrowser.raise()


	func StatusMessage cMsg
		status1.showmessage(cMsg,0)

	func pRunProcess cProgram,cArg,cGetDataFunc
		aPara = split(cArg,",")
		oStringList = new qStringlist() {
			for cPara in aPara 
				append(cPara)
			next
		}
		oProcess = new qprocess(NULL) {
			setprogram( cProgram)
			setarguments(ostringlist)
			setreadyreadstandardoutputevent(cGetDataFunc)
			start_3(  QIODevice_ReadWrite )
		}
		return oProcess

	func pGetProcessData 
		if ISNULL(oProcess) return ok
		cText = oProcess.readallstandardoutput().data()
		# Set the font
			oTempFont.fromstring(cFont)
			oProcessEditbox.setFont(oTempFont)
		oProcessEditbox.insertplaintext(cText)

	func pSendProcessData
		if ISNULL(oProcess) return ok
		cText = oProcessText.text() + windowsnl()
		oProcess.write(cText ,len(cText))
		oProcessEditbox.insertplaintext(cText)
		oProcessText.setText("")

	func pFormDesigner		
		cFormFileName = cCurrentDir + "../formdesigner/formdesigner.ring"
		RunTool(cFormFileName)

	func RunTool cFileName
		oProcessEditbox.setplaintext("")
		oProcessText.setFocus(0)
		chdir(JustFilePath(cFileName))
		oProcess = pRunProcess(cRingEXE,cFileName,cpGetProcessData)
		chdir(exefolder())

	func RunToolConsole cFileName
		if iswindows()
			System('start '+exefolder()+'ring "' + cFileName + '"' + nl)
		else
			cCode = 'cd $(dirname "'+cFileName+'") ; ' + ' ring "' + cFileName + '"' + nl
			system(cCode)
		ok

	func pREPLConsole
		cAppFileName = cCurrentDir + "../ringrepl/repl.ring"
		RunToolConsole(cAppFileName)

	func pREPLGUI
		cAppFileName = cCurrentDir + "../ringrepl/replw.ring"
		# RunTool will split parameters using "," as separator 
		if nDefaultStyle <= 3 
			cAppFileName += ",1"	# Style Fusion White
		else
			cAppFileName += ",2"	# Style Fusion Black
		ok
		RunTool(cAppFileName)

	func pFormDesignerDock
		cDir = CurrentDir()
		chdir(exefolder() + "/../applications/formdesigner")
		# Import Classes 
			import formdesigner 
		open_windowAndLink(:FormDesignerController,self)
		# We still use setParentObject() and avoid using
		# IsRNOTE() and RNote() in the Form Designer 
		# So we can reuse the Form Designer in other Projects
		# I.e. Ring Notepad need to know about the Form Designer 
		# But It's necessary for the Form Designer to Know that
		# It's used in another project!
		FormDesigner().setParentObject(self)
		oDockFormDesigner.setWidget(FormDesigner().oView.win)
		chdir(cDir)

	func GetActiveFolder
		return cStartUpFolder

	func pCheckCustomColors
		if True	# Switch to Use the Style or Not
			pSelectStyleColor(nDefaultStyle)
			LoadSettings()
		ok

	func pClearProcess
		oProcessEditbox.setPlainText("")

	func pSetMainFile
		oTxtMainFile.setText(cActiveFileName)

	func GetMainFile
		cMainFileName = trim(oTxtMainFile.text())
		if cMainFileName = NULL 
			pSetMainFile() 
			cMainFileName = trim(oTxtMainFile.text())
		ok
		return cMainFileName

	func pDebugMainFile
		cMainFileName = GetMainFile()
		if cMainFileName = Null return pNofileopened() ok
		if not fexists(cMainFileName) return ok
		pSave()
		pDebugOperation(cMainFileName)

	func pRunMainFile
		cMainFileName = GetMainFile()
		if cMainFileName = Null return pNofileopened() ok
		if not fexists(cMainFileName) return ok
		pSave()
		pRunOperation(cMainFileName)

	func pRunGUIMainFile
		cMainFileName = GetMainFile()
		if cMainFileName = Null return pNofileopened() ok
		if not fexists(cMainFileName) return ok
		oDockOutputWindow { show() raise() }		
		pSave()
		pRunGUIOperation(cMainFileName)

	func ClearActiveFormFile
		cFormFile = ""

	func RunInBrowser
		if cActiveFileName = Null return pNofileopened() ok
		pSave()	
		RunWebApplication(this.cActiveFileName)

	func RunWebApplication cFile
		if isWindows() 
			if cWebApplicationFolder != JustFilePath(cFile)
				cWebApplicationFolder = JustFilePath(cFile)
				new ServerPrepare { 
					setApplicationPath(this.cWebApplicationFolder)
					PrepareConfigurationFile() 
					cServerExe = getserverExeFile()
				}	
				oProcess = pRunProcess(cCurrentDir + "killwebserver.bat","",cpGetProcessData)			
				oProcess.waitForFinished(3000)
				oWebServerProcess = pRunProcess(cServerEXE,"",cpGetProcessData)			
				sleep(3)
				oProcessEditbox.setplaintext("")
			ok
			new QDesktopServices {
				OpenURL(new qURL("http://localhost:8080/"+JustFileName(cFile)))
			}
		else 
			cWebURL = cFile
			nPos = substr(cWebURL,"htdocs")
			cWebURL = substr(cWebURL,nPOS+7)
			new QDesktopServices {
				OpenURL(new qURL("http://localhost/"+cWebURL))
			}
		ok

	func RunInBrowserMainFile
		cMainFileName = GetMainFile()
		if cMainFileName = Null return pNofileopened() ok
		if not fexists(cMainFileName) return ok
		pSave()
		RunWebApplication(cMainFileName)

	func OSTerminal
		if isWindows()
			cCommand = 'start cmd /K "cd ' + cStartupFolder + '"'
		but isLinux()
			cCommand = "gnome-terminal"
		but isMacosx()
			cCommand = "open /Applications/Utilities/Terminal.app"
		else 
			return
		ok
		system(cCommand)

	func OSFilesManager 
		if cActiveFileName != Null
			cStartupFolder = justfilepath(cActiveFileName)
		ok
		new QDesktopServices {
			OpenURL(new qURL("file:///"+this.cStartupFolder))
		}

	func pDistribute nOption
		if cActiveFileName = Null return pNofileopened() ok
		pSave()
		cAppToRun = exefolder()+"/ring2exe"
		cPara = cActiveFileName
		switch nOption
			on 1	# ringo
				cAppToRun = exefolder()+"/ring"
				cPara += ",-go,-norun"
			on 2	# exe 
				cPara += ",-static"
			on 3	# dist allruntime
				cPara += ",-dist,-allruntime"
			on 4	# dist allruntime gui
				cPara += ",-dist,-allruntime,-gui"
			on 5	# ringqt
				cPara += ",-dist,-qt,-gui"
			on 6	# ringallegro 
				cPara += ",-dist,-allegro,-freeglut,-opengl,-gui"
			on 7	# qt project
				cPara += ",-dist,-allruntime,-gui,-mobileqt"
		off
		oDockOutputWindow { show() raise() }		
		oProcessEditbox.setplaintext("")
		chdir(JustFilePath(cActiveFileName))
		oProcess = pRunProcess(cAppToRun,cPara,cpGetProcessData)
		OSFilesManager()
		chdir(exefolder())

