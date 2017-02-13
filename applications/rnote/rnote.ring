# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Load "guilib.ring"
Load "stdlib.ring"

cActiveFileName = ""
aTextColor = [0,0,0]  
aBackColor = [255,255,255]
cFont = "MS Shell Dlg 2,14,-1,5,50,0,0,0,0,0"
cWebsite = "http://www.ring-lang.sf.net/doc/index.html"
cCurrentDir = CurrentDir() + "/"	# The Ring Notepad Folder
cStartUpFolder = exefolder() + "/../applications/"
lShowProject = True
lShowSourceCode = True
lShowBrowser = True
lShowFunctionsList = False
nTabSpaces = 0
aBrowserLinks = [
	["Local Help", "file:///"+exefolder() + "../docs/build/html/index.html"],
	["Localhost","http://localhost"],
	["Ring Website","http://ring-lang.sf.net"],
	["Ring Group (Google Groups)","https://groups.google.com/forum/#!forum/ring-lang"],
	["Ring Source Code (GitHub)","https://github.com/ring-lang/ring"],
	["Ring Samples (Rosetta Code)","https://rosettacode.org/wiki/Category:Ring"],
	["Ring Resources","http://ring-lang.sourceforge.net/resources.html"],
	["Ring Team","http://ring-lang.sourceforge.net/team.html"]
]

cSettingsFile = cCurrentDir + "ringnotepad.ini"
LoadSettings()

oSearch = NULL
oSearchValue = NULL 
oSearchCase = NULL
oSearchFilter = NULL
oReplaceValue = NULL

cSearchText = ""
cReplaceText = ""

lAskToSave = false

# Hash Table contains the File Name and the Line Number 

aFilesLines = []	# Used to remember the current line when we switch between many files

# For Auto-Complete
oAutoCompleteList = NULL
nAutoCompleteListSize = 0

MyApp = New qApp {
	PrepareAutoComplete()
	win1 = new qMainWindow() {
		oFilter = new qAllEvents(win1)
		oFilter.setCloseEvent("pSaveSettingsToFile()")
		installEventFilter(oFilter)
		setwindowtitle("Ring Notepad")
		setGeometry(100,100,400,400)
		aBtns = [
				new qpushbutton(win1) { 
					setbtnimage(self,"image/new.png") 
					setclickevent("pNew()")
					settooltip("New File")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/open.png") 
					setclickevent("pOpen()")
					settooltip("Open File")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/save.png")
					setclickevent("pSave()")
					settooltip("Save")
				 } ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/saveas.png")
					setclickevent("pSaveAs()")
					settooltip("Save As")
				 } ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/undo.png") 
					setclickevent("pUndo()")
					settooltip("Undo")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/cut.png")
					setclickevent("pCut()")
					settooltip("Cut")
				 } ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/copy.png") 
					setclickevent("pCopy()")
					settooltip("Copy")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/paste.png") 
					setclickevent("pPaste()")
					settooltip("Paste")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/font.png") 
					setclickevent("pFont()")
					settooltip("Font")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/colors.jpg") 
					setclickevent("pColor()")
					settooltip("Text Color")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/search.png") 
					setclickevent("pFind()")
					settooltip("Find and Replace")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/print.png") 
					setclickevent("pPrint()")
					settooltip("Print")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/debug.png") 
					setclickevent("pDebug()")
					settooltip("Debug (Run then wait!)")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/run.png") 
					setclickevent("pRun()")
					settooltip("Run the program")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/rungui.bmp") 
					setclickevent("pRunNoConsole()")
					settooltip("Run GUI Application (No Console)")
				} ,
				new qpushbutton(win1) { 
					setbtnimage(self,"image/close.png") 
					setclickevent("pQuit()")
					settooltip("Quit")
				} 
			]

		tool1 = addtoolbar("files")  {
	  		for x in aBtns addwidget(x) addseparator() next
		}

		menu1 = new qmenubar(win1) {		
			subFile = addmenu("File")
			subEdit = addmenu("Edit")
			subView = addmenu("View")
			subProgram = addmenu("Program")
			subBrowser = addmenu("Browser")
			subHelp = addmenu("Help")
			subFile { 
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+n"))
					setbtnimage(self,"image/new.png")
					settext("New")
					setclickevent("pNew()")
				}
				addaction(oAction)
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+o"))
					setbtnimage(self,"image/open.png") 
					settext("Open")
					setclickevent("pOpen()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+s"))
					setbtnimage(self,"image/save.png")
					settext("Save")
					setclickevent("pSave()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+e"))
					setbtnimage(self,"image/saveas.png")
					settext("Save As")
					setclickevent("pSaveAs()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+p"))
					setbtnimage(self,"image/print.png")
					settext("Print to PDF")
					setclickevent("pPrint()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qaction(win1) {
					setShortcut(new QKeySequence("Ctrl+q"))
					setbtnimage(self,"image/close.png") 
					settext("Exit")
					setstatustip("Exit")
					setclickevent("pQuit()")
				}
				addaction(oAction)
			}
			subEdit { 
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+z"))
					setbtnimage(self,"image/undo.png")
					settext("Undo")
					setclickevent("pUndo()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+x"))
					setbtnimage(self,"image/cut.png")
					settext("Cut")
					setclickevent("pCut()")
				}
				addaction(oAction)
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+c"))
					setbtnimage(self,"image/copy.png")
					settext("Copy")
					setclickevent("pCopy()")
				}
				addaction(oAction)
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+v"))
					setbtnimage(self,"image/paste.png")
					settext("Paste")
					setclickevent("pPaste()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+i"))
					setbtnimage(self,"image/font.png")
					settext("Font")
					setclickevent("pFont()")
				}
				addseparator()
				addaction(oAction)
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+t"))
					setbtnimage(self,"image/colors.jpg")
					settext("Text Color")
					setclickevent("pColor()")
				}
				addaction(oAction)
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+b"))
					setbtnimage(self,"image/colors.jpg")
					settext("Back Color")
					setclickevent("pColor2()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+g"))
					settext("Go to line")
					setclickevent("pGoto()")
				}
				addaction(oAction)
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+f"))
					setbtnimage(self,"image/search.png")
					settext("Find and Replace")
					setclickevent("pFind()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+h"))
					settext("Set Tab Width")
					setclickevent("pTabWidth()")
				}
				addaction(oAction)
			}				
			subView {
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+j"))
					setbtnimage(self,"image/project.png")
					settext("Project Files")
					setclickevent("pProject()")
				}
				addaction(oAction)			
				addseparator()	
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+u"))
					setbtnimage(self,"image/source.png")
					setclickevent("pSourceCode()")
					settext("Source Code")
				}
				addaction(oAction)	
				addseparator()	
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+w"))
					setbtnimage(self,"image/richtext.png")
					setclickevent("pWebBrowser()")
					settext("Web Browser")
				}
				addaction(oAction)
				addseparator()	
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+n"))
					setbtnimage(self,"image/source.png")
					setclickevent("pFunctionsList()")
					settext("Functions List")
				}
				addaction(oAction)		
			}
			subProgram { 
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+d"))
					setbtnimage(self,"image/debug.png")
					settext("Debug (Run then wait!)")
					setclickevent("pDebug()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+r"))
					setbtnimage(self,"image/run.png")
					settext("Run")
					setclickevent("pRun()")
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(win1) {
					setShortcut(new QKeySequence("Ctrl+F5"))
					setbtnimage(self,"image/run.png")
					settext("Run GUI Application (No Console)")
					setclickevent("pRunNoConsole()")
				}
				addaction(oAction)	
			}
			subBrowser { 

				for x=1 to len(aBrowserLinks)
					item = aBrowserLinks[x]
					oAction = new qAction(win1) {
						settext(item[1])
						setclickevent("pBrowserLink("+x+")")
					}
					addaction(oAction)	
					if x != len(aBrowserLinks)
						addseparator()	
					ok
				next
			}

			subHelp { 

				subHelpLF = addmenu("Language Reference")
				subHelpLF { 
					oAction = new qAction(win1) {
						settext("CHM File")
						setclickevent("pOpenCHM()")
					}
					addaction(oAction)
					oAction = new qAction(win1) {
						settext("PDF File")
						setclickevent("pOpenPDF()")
					}
					addaction(oAction)
				}
				addseparator()
				subHelpTools = addmenu("Development Tools")
				subHelpTools { 

					oAction = new qAction(win1) {
						settext("Programming Language")
						setclickevent("pLang()")
					}
					addaction(oAction)
					oAction = new qAction(win1) {
						settext("GUI Library")
						setclickevent("pGUI()")
					}
					addaction(oAction)
				}
				addseparator()
					oAction = new qAction(win1) {
						settext("About")
						setclickevent("pAbout()")
					}
					addaction(oAction)			
			}
		}

		setmenubar(menu1)

		status1 = new qstatusbar(win1) {
			showmessage("Ready!",0)
		}

		setstatusbar(status1)

		tree1 = new qtreeview(win1) {
			setclickedevent("pChangeFile()")
			setGeometry(00,00,200,400)
			setmaximumwidth(300)
			chdir(cStartUpFolder)
			oDir = new QDir()					
			ofile = new QFileSystemModel() {
				setrootpath(oDir.currentpath())				
				myfiles = new qstringlist()
				myfiles.append("*.ring")
				myfiles.append("*.rh")
				myfiles.append("*.txt")
				myfiles.append("*.html")
				myfiles.append("*.rhtml")
				myfiles.append("*.css")
				myfiles.append("*.js")
				myfiles.append("*.xml")
				myfiles.append("*.data")
				setnamefilters(myfiles)	
				setNameFilterDisables(false)
			}
			setmodel(ofile)
			myindex = ofile.index(oDir.currentpath(),0)
			for x = 1 to ofile.columncount()
				hidecolumn(x)
			next
			setcurrentindex(myindex)
			setexpanded(myindex,true)
			header().hide()			
			chdir(exefolder())
			if not ismacosx()
				cWebsite = "file:///"+oDir.CurrentPath() + "/../docs/build/html/index.html"
			ok
		}

		oDock1 = new qdockwidget(win1,0) {
			setGeometry(00,00,200,200)
			setwindowtitle("Project Files")
			setwidget(tree1)
		}

		textedit1 = new codeeditor(win1) {
			setCursorPositionChangedevent("pCursorPositionChanged()")
			setLineWrapMode(QTextEdit_NoWrap)
			setTextChangedEvent("pTextChanged()")			
		}
		AutoComplete()

		new RingCodeHighLighter( textedit1.document() )

		oDock2 = new qdockwidget(win1,0) {
			setwidget(textedit1)
			setwindowtitle("Source Code")			
		}

		oWebBrowser = new qWidget() {	
			setWindowFlags(Qt_SubWindow)
			oWBLabel = new qLabel(win1) {
				setText("Website: ")
			}	
			oWBText = new qLineEdit(win1) {
				setText(cWebSite)
				setReturnPressedEvent("pWebGo()")
			}
			oWBGo = new qPushButton(win1) {
				setText("Go")
				setClickEvent("pWebGo()")
			}
			oWBBack = new qPushButton(win1) {
				setText("Back")
				setClickEvent("pWebBack()")
			}
			oWBLayout1 = new qHBoxLayout() {
				addWidget(oWBLabel)
				addWidget(oWBText)
				addWidget(oWBGo)
				addWidget(oWBBack)
			}
			oWebView = new qWebView(win1) {
				loadpage(new qurl(cWebSite))
			}
			oWBlayout2 = new qVBoxLayout() {
				addLayout(oWBLayout1)
				addWidget(oWebView)
			}
			setLayout(oWBLayout2)
		}

		oDock3 = new qdockwidget(win1,0) {
			setwidget(oWebBrowser)		
			setwindowtitle("Web Browser")
		}	

		aFunctionsPos = []	# Lines Numbers for each function
		oFunctionsList = new qListwidget(win1) {
			setitemdoubleclickedevent("pSelectFunction()")
			setitemactivatedevent("pSelectFunction()")
		}

		oDock4 = new qDockwidget(win1,0) {
			setWidget(oFunctionsList)
			setwindowtitle("Functions List")
		}

		adddockwidget(1,oDock1,1)
		adddockwidget(2,oDock2,2)
		adddockwidget(2,oDock4,1)
		adddockwidget(2,oDock3,1)

		setwinicon(self,cCurrentDir + "/image/notepad.png")
		showmaximized()	
	}

	RestoreSettings()

	exec()
}

func pTextChanged
	lAskToSave = true
	pSetFont()
	textedit1.cyanline(textedit1)

func pWebGo
	cWebsite = oWBText.text() 
	oWebView.LoadPage( new qurl( cWebSite ) )

func pWebBack
	oWebView.Back()

func pProject
	if oDock1.isvisible()
		oDock1.hide()
	else
		oDock1.Show()
	ok
	
func pSourceCode
	if oDock2.isvisible()
		oDock2.hide()
	else
		oDock2.Show()
	ok

func pWebBrowser
	if oDock3.isvisible()
		oDock3.hide()
	else
		oDock3.Show()
	ok

func pFunctionsList
	if oDock4.isvisible()
		oDock4.hide()
	else
		oDock4.Show()
		DisplayFunctionsList()
	ok

func pCheckSaveBeforeChange
	if cActiveFileName = NULL return ok	
	cStr1 = substr(read(cActiveFileName),WindowsNl(),NL)
	if cStr1 != textedit1.toPlainText() pSaveSettings() ok

func pChangeFile
	pCheckSaveBeforeChange()	# To ask to saving a file
	pSaveCurrentFolder()
	oItem = tree1.currentindex()
	if ofile.isdir(oItem)
		return
	ok
	cActiveFileName = ofile.filepath(oItem)
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
	DisplayFunctionsList()
	StatusMessage("Ready!")

func pSetActiveFileName
	oDock2.setWindowTitle("Source Code : " + cActiveFileName)

func pCursorPositionChanged
	nLine = textedit1.textcursor().blocknumber()+1
	StatusMessage(" Line : "+nLine+
			    " Column : " +(textedit1.textcursor().columnnumber()+1) +
			    " Total Lines : " + textedit1.document().linecount())
	textedit1.cyanline(textedit1)
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

func pFind
	if isobject(oSearch)
		oSearch.activatewindow()
		return
	ok
	oSearch = new qWidget()
	{
		oLblFindWhat = new qLabel(oSearch)
		{
			setText("Find What : ")
		}
		oSearchValue = new qlineedit(oSearch)
		{
			setText(cSearchText)
			setReturnPressedEvent("pFindValue()")
		}
		oLayout1 = new qHBoxLayout()
		{
			addWidget(oLblFindWhat)
			addWidget(oSearchValue)
		}		
		oLblReplaceWith = new qLabel(oSearch)
		{
			setText("Replace with ")
		}
		oReplaceValue = new qlineedit(oSearch)
		{
			setText(cReplaceText)
		}

		oLayout2 = new qHBoxLayout()
		{
			addWidget(oLblReplaceWith)
			addWidget(oReplaceValue)
		}
		oSearchCase = new qCheckbox(oSearch)
		{
			setText("Case Sensitive")
		}
		oLayout3 = new qHBoxLayout()
		{
			addWidget(oSearchCase)			
		}
		oBtnFind = new qPushButton(oSearch)
		{
			setText("Find/Find Next")
			setclickevent("pFindValue()")
		}
		oBtnReplace = new qPushButton(oSearch)
		{
			setText("Replace")
			setclickevent("pReplace()")
		}
		oBtnReplaceAll = new qPushButton(oSearch)
		{
			setText("Replace All")
			setclickevent("pReplaceAll()")
		}
		oBtnClose = new qPushButton(oSearch)
		{
			setText("Close")
			setclickevent("pSearchClose()")
		}
		oLayout4 = new qHBoxLayout()
		{
			addWidget(oBtnFind)
			addWidget(oBtnReplace)
			addWidget(oBtnReplaceAll)
			addWidget(oBtnClose)
		}
		oLayout5 = new qVBoxLayout()
		{
			AddLayout(oLayout1)
			AddLayout(oLayout2)
			AddLayout(oLayout3)
			AddLayout(oLayout4)
		}

		setLayout(oLayout5)

		setwinicon(oSearch,"image/notepad.png")
		setWindowTitle("Find/Replace")		
		setStyleSheet("background-color:white;")
		setFixedsize(550,160)
		setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint) 

		oSearchFilter = new qallevents(oSearch)
		oSearchFilter.setKeyPressEvent("pSearchKeyPress()")								
		installeventfilter(oSearchFilter)

		show()
	}

Func pReplace
	oCursor = textedit1.textCursor()
	if oCursor.HasSelection() = false
		new qMessagebox(oSearch)
		{
			SetWindowTitle("Replace") 
			SetText("No Selection")
			show()	
		}
		return false
	ok
	cValue = oSearchValue.text()
	cSelected = oCursor.SelectedText()
	if oSearchCase.checkState() = Qt_Unchecked
		cValue = lower(cValue)	
		cSelected = lower(cSelected)
	ok
	if cSelected != cValue
		new qMessagebox(oSearch)
		{
			SetWindowTitle("Replace") 
			SetText("No Match")
			show()	
		}
		return false
	ok
	cValue = oReplaceValue.text()
	nStart = oCursor.SelectionStart()
	nEnd = oCursor.SelectionEnd()
	cStr = textedit1.toPlainText()
	cStr = left(cStr,nStart)+cValue+substr(cStr,nEnd+1)
	textedit1.setPlainText(cStr)	
	return pFindValue()

Func pReplaceAll
	cStr = textedit1.toPlainText()
	cOldValue = oSearchValue.text()
	cNewValue = oReplaceValue.text()
	if oSearchCase.checkState() = Qt_Unchecked
		# Not Case Sensitive
		cStr = SubStr(cStr,cOldValue,cNewValue,true)
	else
		# Case Sensitive
		cStr = SubStr(cStr,cOldValue,cNewValue)
	ok
	textedit1.setPlainText(cStr)	
	new qMessagebox(oSearch)
	{
		SetWindowTitle("Replace All") 
		SetText("Operation Done")
		show()	
	}

Func pSearchClose
	oSearch.close() 
	oSearch = NULL
	cSearchText = oSearchValue.text()
	cReplaceText = oReplaceValue.text()


func pSearchKeyPress
	if oSearchFilter.getKeyCode() = Qt_Key_Escape
		pSearchClose()		
	ok

func pFindValue
	oCursor = textedit1.textcursor()
	nPosStart = oCursor.Position() + 1
	cValue = oSearchValue.text()
	cStr = textedit1.toplaintext()
	cStr = substr(cStr,nPosStart)
	if oSearchCase.checkState() = Qt_Unchecked
		cStr = lower(cStr)  cValue = lower(cValue)
	ok
	nPos = substr(cStr,cValue)
	if nPos > 0
		nPos += nPosStart - 2
		oCursor = textedit1.textcursor()
		oCursor.setposition(nPos,0)
		textedit1.settextcursor(oCursor)
		oCursor = textedit1.textcursor()
		oCursor.setposition(nPos+len(cValue),1)
		textedit1.settextcursor(oCursor)
		return true
	else
		new qMessagebox(oSearch)
		{
			SetWindowTitle("Search") 
			SetText("Cannot find :" + cValue)
			show()	
		}
		return false
	ok		

func pNofileopened
 	New qMessageBox(win1) {
		setWindowTitle("Sorry")
		setText("Save the file first!")
		show()
	}

func pDebug
	if cActiveFileName = Null return pNofileopened() ok
	pSave()
	if iswindows()
		cCode = 'start '+cCurrentDir+'run "' + cActiveFileName + '"' + nl 
	else
		cCode = 'cd $(dirname "'+cActiveFileName+'") ; ' + ' ring "' + cActiveFileName + '"' + nl 
	ok
	system(cCode)

func pRun
	if cActiveFileName = Null return pNofileopened() ok
	pSave()
	if iswindows()
		cCode = 'start '+cCurrentDir+'run2 "' + cActiveFileName + '"' + nl 
	else
		cCode = 'cd $(dirname "'+cActiveFileName+'") ; ' + ' ring "' + cActiveFileName + '"' + nl 
	ok
	system(cCode)

func pRunNoConsole
	if cActiveFileName = Null return pNofileopened() ok
	pSave()
	if iswindows()
		cCode = 'start /b '+cCurrentDir+'run2 "' + cActiveFileName + '"' + nl 		
	else
		cCode = 'cd $(dirname "'+cActiveFileName+'") ; ' + ' ring "' + cActiveFileName + '"' + nl 
	ok
	system(cCode)
	

func pSave
	if cActiveFileName = NULL return pSaveAs() ok
	writefile(cActiveFileName,textedit1.toplaintext())
	StatusMessage("File : " + cActiveFileName + " saved!")
	lAskToSave = false
	AutoComplete()
	displayFunctionsList()
	StatusMessage("Ready!")

func pSaveAs
	new qfiledialog(win1) {
		pSaveCurrentFolder()
		cName = getsavefilename(win1,"Save As",cStartupFolder,"source files(*.ring)")
		if cName != NULL
			cActiveFileName = cName
			writefile(cActiveFileName,textedit1.toplaintext())
			StatusMessage("File : " + cActiveFileName + " saved!")	
			pSetActiveFileName()
			lAskToSave = false
		ok	
	}

func pPrint
	StatusMessage("Printing to File : RingDoc.pdf")
	printer1 = new qPrinter(0) {
		setoutputformat(1)	# 1 = pdf
		setoutputfilename("RingDoc.pdf")
		textedit1.print(printer1)
	}
	StatusMessage("Done!")
	system("RingDoc.pdf")

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

		myfont = new qfont("",0,0,0)
		myfont.fromstring(cFont)
		setcurrentfont(myfont)

		aFont = getfont()
	}

	if aFont[1] != NULL
		cFont = aFont[1]
		pSetFont()	# set the new font
	ok	

Func pSetFont
	myfont = new qfont("",0,0,0)
	myfont.fromstring(cFont)
	oCursor = textedit1.textCursor()
	oCursor.clearselection()
	textedit1.settextcursor(oCursor)
	textedit1.Document().setdefaultfont(myfont)
	

Func pColor
	new qcolordialog() { 
		r = exec()		
		if r = 0 return ok
		oColor = currentcolor()
		r = oColor.red()
		g = oColor.green()
		b = oColor.blue()
		aTextColor = [r,g,b]
	}	
	pSetColors()

Func pColor2
	new qcolordialog() { 
		r = exec()		
		if r = 0 return ok
		oColor = currentcolor()
		r = oColor.red()
		g = oColor.green()
		b = oColor.blue()
		aBackColor = [r,g,b]
	}	
	pSetColors()
	
Func pSetColors
	textedit1.setstylesheet("color: rgb(" + aTextColor[1] + "," + aTextColor[2] +
				"," + aTextColor[3] + ");" + "background-color: rgb(" +
				aBackColor[1] + "," + aBackColor[2] + "," +
				aBackColor[3] + ")")

Func pSetWindows
	if not lShowProject  	oDock1.close() else oDock1.show() ok
	if not lShowSourceCode  oDock2.close() else oDock2.show() ok
	if not lShowBrowser  	oDock3.close() else oDock3.show() ok
	if not lShowFunctionsList oDock4.close() else oDock4.show() ok

func pOpen
	new qfiledialog(win1) {
		pSaveCurrentFolder()
		cName = getopenfilename(win1,"open file",cStartupFolder,"source files(*.ring)")			
		if cName != NULL
			cActiveFileName = cName
			textedit1.setPlaintext(read(cActiveFileName))
			pSetActiveFileName()
		ok
	}
	
func pNew
	new qfiledialog(win1) {
		pSaveCurrentFolder()
		cName = getsavefilename(win1,"New file",cStartupFolder,"source files(*.ring)")
		if cName != NULL
			write(cName,"")
			cActiveFileName = cName
			textedit1.setPlaintext(read(cActiveFileName))			
			pSetActiveFileName()
		ok	
	}
	
Func WriteFile cFileName,cCode
	aCode = str2list(cCode)
	fp = fopen(cFileName,"wb")
	for cLine in aCode
		fwrite(fp,cLine+char(13)+char(10))	
	next
	fclose(fp)

Func MsgBox cTitle,cMessage
	win = new qMessagebox(win1) {
		setwindowtitle(cTitle)
		setText(cMessage)
		setwinicon(win,cCurrentDir + "/image/notepad.png")
		show()
	}
	

Func pLang
	MsgBox("Programming Language",
		"This application developed using the Ring programming language")

Func pGUI
	MsgBox("GUI Library",
		"This application uses the Qt GUI Library through RingQt")

Func pAbout
	MsgBox("About",
		"2016-2017, Mahmoud Fayed <msfclipper@yahoo.com>")		

Func pSaveCurrentFolder
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

Func pSaveSettingsToFile
	pSaveCurrentFolder()
	cSettings = "aTextColor = ["+aTextColor[1]+","+aTextColor[2]+","+aTextColor[3]+"]" + nl + 
		    "aBackColor = ["+aBackColor[1]+","+aBackColor[2]+","+aBackColor[3]+"]" + nl +
		    "cFont = '" + cFont + "'" + nl + 
		    "cWebSite = '" + cWebsite + "'" + nl +
		    "cStartupFolder = '" + cStartupFolder + "'" + nl + 
		    "lShowProject = " + oDock1.isvisible() + nl +
		    "lShowSourceCode = " + oDock2.isvisible() + nl +
		    "lShowBrowser = " + oDock3.isvisible() + nl +
		    "lShowFunctionsList = " + oDock4.isvisible() + nl +
		    "nTabSpaces = " + nTabSpaces + nl
	cSettings = substr(cSettings,nl,char(13)+char(10))
	write(cSettingsFile,cSettings)

Func pSaveSettings
	pSaveSettingsToFile()
	if lAsktoSave
		new qmessagebox(win1)
		{
			setwindowtitle("Save Changes?")
			settext("Some changes are not saved!")
			setInformativeText("Do you want to save your changes?")
			setstandardbuttons(QMessageBox_Yes | QMessageBox_No | QMessageBox_Cancel)
			result = exec()
			win1 {
			if result = QMessageBox_Yes
				pSave()
			but result = QMessageBox_Cancel
				return false
			ok
		}
	}	
	ok
	return true

Func pSetWebsite
	oWebView { loadpage(new qurl(cWebSite)) }	
	oWBText  { setText(cWebSite) }		

Func LoadSettings	
	if fexists(cSettingsFile)
		eval(read(cSettingsFile))
	ok

Func RestoreSettings
	LoadSettings()
	pSetColors()
	pSetFont()
	pSetWebsite()
	pSetWindows()
	pSetTabSpaces()

Func pQuit
	if pSaveSettings() 
		myapp.quit()
	ok

Func pOpenCHM
	System( "start " + exefolder()+"/../docs/ring.chm" )

Func pOpenPDF
	System( "start " + exefolder()+"/../docs/ring.pdf" )

Func pTabWidth
	
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

Func pSetTabSpaces

	oFont = new qfont("",0,0,0)
	oFont.fromstring(cFont)
	oFontMetrics = new QFontMetrics(oFont)
	nSpaceWidth = oFontMetrics.Width(" ",1)
	textedit1.setTabStopWidth(nTabSpaces*nSpaceWidth)


Func pBrowserLink x

	cLink = aBrowserLinks[x][2]

	oWebView { loadpage(new qurl(cLink)) }	
	oWBText  { setText(cLink) }		

	oDock3.Show()

# Create a function to add Ring List to qStringList
func AddItems aList,oList 
	for Item in aList 
		oList.Append(Item)
	next

Func PrepareAutoComplete
	oAutoCompleteList = new qStringList()
	# Add Ring Keywords
		aKeywords = ["again","and","but","bye","call","case","catch",
			"changeringkeyword","changeringoperator","class",
			"def","do","done","else","elseif","end","exit","for","from",
			"func","get","give","if","import","in","load","loadsyntax",
			"loop","new","next","not","off","ok","on","or","other",
			"package","private","put","return","see","step","switch",
			"to","try","while"]
		AddItems(aKeywords,oAutoCompleteList)
	# Add Ring Functions 
		aCFunctionsList = cfunctions()
		for cFunction in aCFunctionsList
			cFunction += "()"
		next
		AddItems(aCFunctionsList,oAutoCompleteList)
	# Add Ring Methods
		aCMethodsList = aCFunctionsList
		for x = len(aCMethodsList) to 1 step -1 
			cMethod = aCMethodsList[x]
			nPos = substr(cMethod,"_") 
			if nPos
				aCMethodsList[x] = substr(aCMethodsList[x],nPos+1) 
			else	
				del(aCMethodsList,x)
			ok
		next 
		AddItems(aCMethodsList,oAutoCompleteList)
		oAutoCompleteList.RemoveDuplicates()
	# Add Ring Classes
		aClassesList = classes()
		aClassesNoInit = ["qapp"]
		for cClass in aClassesList 
			if find(aClassesNoInit,cClass) = 0
				cClass = cClass + "() {" + nl + "}"
			else
				cClass = cClass + " {" + nl + "}"
			ok
		next 
		AddItems(aClassesList,oAutoCompleteList)
	# Add Ring Libraries
		aLibsList = ['load "guilib.ring"' , 'load "stdlib.ring"' , 
				'load "weblib.ring"', 'load "ringlibcurl.ring"']
		AddItems(aLibsList,oAutoCompleteList)
	# Save the List Size
		nAutoCompleteListSize = oAutoCompleteList.Count()

Func AutoComplete
	StatusMessage("Prepare Auto-Complete ... Please Wait!")
	# Prepare the list
		while oAutoCompleteList.Count() > nAutoCompleteListSize
			oAutoCompleteList.RemoveAt(oAutoCompleteList.Count()-1)
		end 
	# Add words in the current file 		
		if cActiveFileName != NULL and fexists(cActiveFileName)
			cFileContent = read(cActiveFileName)
			if len(cFileContent) < 30720  # 30 Kbyte
				StatusMessage("Prepare Auto-Complete ... Get File Words!")
				aList = Split(cFileContent," ")
				StatusMessage("Prepare Auto-Complete ... Filter!")
				for x = len(aList) to 1 step -1 
					if not isalnum(aList[x])
						del(aList,x)
					ok
				next
				AddItems(aList,oAutoCompleteList)
			ok
		ok		
	StatusMessage("Prepare Auto-Complete ... Remove Duplicates!")
	oAutoCompleteList.RemoveDuplicates()
	StatusMessage("Prepare Auto-Complete ... Sort!")
	oAutoCompleteList.Sort()
	oCompleter = new qCompleter3(oAutoCompleteList,textedit1)
	oCompleter.setCaseSensitivity(Qt_CaseInsensitive)
	oCompleter.setCompletionMode(QCompleter_PopupCompletion)
	oFont = new qfont("",0,0,0)
	oFont.fromstring(cFont)
	oCompleter.popup().setFont(oFont)
	textedit1.setCompleter(oCompleter)
	StatusMessage("Prepare Auto-Complete ... Done!")

func DisplayFunctionsList
	oFunctionsList.clear()
	if oDock4.isvisible() = false return ok 
	aFunctionsPos = []	# Lines numbers for each function 
	if cActiveFileName = NULL return ok
	# Set the font
		oFont = new qfont("",0,0,0)
		oFont.fromstring(cFont)
		oFunctionsList.setFont(oFont)
	StatusMessage("Creating functions list ... Please Wait!")
	aFileContent = str2list(read(cActiveFileName))
	nLineNumber = 0
	for cLine in aFileContent
		nLineNumber++ 
		cLine = lower(trim(cLine))
		if substr(cLine,"func ") > 0
			aList = Split(cLine," ")
			if len(aList) >= 2
				cFuncName = lower(trim(aList[2]))
				if isalnum(cFuncName)	and lower(trim(aList[1])) = "func"
					aFunctionsPos + [cFuncName+"()" , nLineNumber] 
				ok
			ok
		ok
	next
	aFunctionsPos = Sort(aFunctionsPos,1)
	for cFunc in aFunctionsPos 
		oFunctionsList.addItem(cFunc[1])
	next
	oDock4.setWindowTitle("Functions List ("+oFunctionsList.Count()+")")
	StatusMessage("Creating functions list ... Done!")

func pSelectFunction
	nIndex = oFunctionsList.currentrow() + 1
	nLine = aFunctionsPos[nIndex][2]
	gotoline(nLine)

func StatusMessage cMsg
	status1.showmessage(cMsg,0)

