# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

# Load Standard Libraries
	Load "guilib.ring"
	Load "stdlib.ring"

# Load Ring Notepad Files 
	Load "rnoteview.ring"
	Load "rnotemode.ring"
	Load "rnotestyle.ring"
	Load "rnoteautocomplete.ring"
	Load "rnotelists.ring"
	Load "rnotefind.ring"
	Load "rnotesettings.ring"
	Load "rnotefindinfiles.ring"

# Load the Form Designer 
	Load "../formdesigner/formdesigner.ring"

# Load the Web Server - ServerPrepare Class
	Load "../libdepwin/Apache2.2/ring/prepare.ring"

# Load the Find in files application 
	Load "../findinfiles/findinfilesController.ring"

# Merge Classes 
	mergemethods(:RNoteController,:RNoteView)
	mergemethods(:RNoteController,:RNoteMode)
	mergemethods(:RNoteController,:RNoteStyle)
	mergemethods(:RNoteController,:RNoteAutoComplete)	
	mergemethods(:RNoteController,:RnoteLists)
	mergemethods(:RNoteController,:RnoteFind)
	mergemethods(:RNoteController,:RNoteSettings)
	mergemethods(:RNoteController,:RNoteFindInFiles)

# Create the Ring Notepad Object
	Open_WindowNoShow(:RNoteController)

Class RNoteController from WindowsControllerParent 

	cActiveFileName 	= ""
	aTextColor 		= [0,0,0]
	aBackColor 		= [255,255,255]
	cFont 			= 'Consolas,16,-1,5,50,0,0,0,0,0'
	oTempFont 		= new qfont("",0,0,0)
	cWebsite 		= "http://www.ring-lang.sf.net/doc1.8/index.html"
	cCurrentDir 		= CurrentDir() + "/"	# The Ring Notepad Folder
	cStartUpFolder 		= exefolder() + "/../applications/"
	cRingEXE 		= exefilename()
	lShowProject 		= True
	lShowSourceCode 	= True
	lShowBrowser 		= True
	lShowFunctionsList 	= True
	lShowOutputWindow 	= True
	lShowClassesList 	= True
	lShowFormDesigner 	= True
	nTabSpaces 		= 8
	aBrowserLinks 		= [
		["Local Help", "file:///"+exefolder() + "../docs/build/html/index.html"],
		["Localhost","http://localhost"],
		["Ring Website","http://ring-lang.sf.net"],
		["Ring Group (Google Groups)","https://groups.google.com/forum/#!forum/ring-lang"],
		["Ring Source Code (GitHub)","https://github.com/ring-lang/ring"],
		["Ring Samples (Rosetta Code)","https://rosettacode.org/wiki/Category:Ring"],
		["Ring Resources","http://ring-lang.sourceforge.net/resources.html"],
		["Ring Team","http://ring-lang.sourceforge.net/team.html"]
	]

	# Define Colors
		colordarkBlue   	= new qcolor() { setrgb(0,0,128,255) }
		colordarkMagenta 	= new qcolor() { setrgb(128,0,128,255) }
		colorRed    		= new qcolor() { setrgb(255,000,000,255) }
		colorDarkGreen  	= new qcolor() { setrgb(000,128,000,255) }
		colorGreen	  	= new qcolor() { setrgb(000,255,000,255) }
		colorBlue   		= new qcolor() { setrgb(000,000,255,255) }
		colorCyan   		= new qcolor() { setrgb(000,255,255,255) }
		colorWhite  		= new qColor() { setrgb(255,255,255,255) }
		colorBlack  		= new qColor() { setrgb(0,0,0,255) }
		colorSilver 		= new qColor() { setrgb(128,128,128,255) }
		colorPurple 		= new qColor() { setrgb(128,0,128,255) }

	# Default Editor Style Colors
		aStyleColors = [
			:LineNumbersAreaColor 		= colorBlack ,
			:LineNumbersAreaBackColor 	= colorCyan,
			:ActiveLineBackColor 		= colorCyan,
			:SyntaxKeywordsColor		= colordarkBlue,
			:SyntaxClassNamesColor 		= ColordarkMagenta,
			:SyntaxCommentsColor 		= ColorRed,
			:SyntaxLiteralsColor 		= ColorDarkGreen,
			:SyntaxFunctionCallsColor 	= ColorBlue
		]

	# Default Style 
		STYLECOLOR_WINDOWS 			= 0
		STYLECOLOR_WHITE 			= 1
		STYLECOLOR_BLUE 			= 2
		STYLECOLOR_BLACK 			= 3
		STYLECOLOR_MODERN 			= 4
		STYLECOLOR_MODERNBLACK 			= 5
		STYLECOLOR_MODERNBLACK2 		= 6
		STYLECOLOR_NOTEPADWHITE 		= 7
		STYLECOLOR_NOTEPADPURPLE 		= 8
		STYLECOLOR_NOTEPADDARKBLUE 		= 9
		STYLECOLOR_NOTEPADBLACK 		= 10
		STYLECOLOR_ART		 		= 11
		STYLECOLOR_ART2		 		= 12
		STYLECOLOR_ART3		 		= 13
		STYLECOLOR_IMAGE	 		= 14
		STYLECOLOR_IMAGE2	 		= 15
		nDefaultStyle  				= STYLECOLOR_WHITE
		lKeywordsBold 				= True

	# Default Mode
		VIEWMODE_GENERAL 	= 1
		VIEWMODE_LEARNINGRING	= 2
		VIEWMODE_CODING		= 3
		VIEWMODE_CODING2	= 4
		VIEWMODE_CODING3	= 5
		VIEWMODE_GUIDEV		= 6
		VIEWMODE_WEBDEV		= 7
		VIEWMODE_TESTING	= 8
		VIEWMODE_COMMON		= 9
		nDefaultMode		= VIEWMODE_GENERAL

	cSettingsFile 	= cCurrentDir + "ringnotepad.ini"
	LoadSettings()

	oSearch 	= NULL
	oSearchValue 	= NULL
	oSearchCase 	= NULL
	oSearchFilter 	= NULL
	oReplaceValue 	= NULL

	cSearchText 	= ""
	cReplaceText 	= ""

	lAskToSave 	= false
	cTextHash	= sha256("")

	# Hash Table contains the File Name and the Line Number

	aFilesLines 	= []	# Used to remember the current line when we switch between many files

	# For Auto-Complete
	oAutoCompleteList 	= NULL
	nAutoCompleteListSize 	= 0

	MyApp win1 oFilter aBtns tool1 menu1 status1
	tool2 oTxtMainFile
	Tree1 TextEdit1 oDockProjectFiles oDockSourceCode oDockWebBrowser 
	oDockFunctionsList oDockOutputWindow oDockClassesList oDockFormDesigner
	oWebBrowser oWebView  oWBText 
	oFile oFunctionsList oClassesList
	oOutputWindow oProcessEditbox oProcessText oProcess
	aFunctionsPos aClassesPos

	oACTimer=NULL			# Auto-Complete Timer 
	oCompleter=NULL 		# The completer object

	cFormFile = ""

	# Methods 
	   cpGetProcessData = Method(:pGetProcessData)

	cWebApplicationFolder = ""

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

	func pGoto
		oInput = New QInputDialog(win1)
		{
			setwindowtitle("Enter the line number?")
			setgeometry(100,100,400,50)
			setlabeltext("Line")
			settextvalue("1")
			r = exec()
		}
		if r=0 return ok
		nLine = 0 + oInput.textvalue()
		gotoline(nLine)

	func gotoline nLine
		nLine--
		cStr = textedit1.toPlainText()
		nSize = len(cStr)
		for t=1 to nSize
			if cStr[t] = nl nLine-- ok
			if nLine = 0
				oCursor = textedit1.textcursor()
				oCursor.setposition(t,0)
				textedit1.settextcursor(oCursor)
				exit
			ok
		next


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

