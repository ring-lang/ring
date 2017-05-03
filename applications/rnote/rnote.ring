# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

# Load Standard Libraries
	Load "guilib.ring"
	Load "stdlib.ring"

# Load the Form Designer 
	Load "../formdesigner/formdesigner.ring"
	import formdesigner 

# Create the Ring Notepad Object
	Open_WindowNoShow(:RNote)

Class RNote from WindowsControllerParent 

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
	lShowOutputWindow = False
	lShowClassesList = False
	lShowFormDesigner = False
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

	MyApp win1 oFilter aBtns tool1 menu1 status1
	Tree1 TextEdit1 oDock1 oDock2 oDock3 oDock4 oDock5 oDock6 oDock7
	oWebBrowser oWebView  oWBText 
	oFile oFunctionsList oClassesList
	oProcessEditbox oProcessText oProcess
	aFunctionsPos aClassesPos

	nFormDesignerWindowID 

	# Methods 
	   cpGetProcessData = Method(:pGetProcessData)

	CreateMainWindow()

	func CreateMainWindow 

	MyApp = New qApp {
		# Custom Editor Style Color
		this.pCheckCustomColors()
		this.PrepareAutoComplete()
		this.win1 = new qMainWindow() {
			oFilter = new qAllEvents(this.win1)
			oFilter.setCloseEvent(Method(:pSaveSettingsToFile))
			installEventFilter(oFilter)
			setwindowtitle("Ring Notepad")
			setGeometry(100,100,400,400)
			aBtns = [
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/new.png")
						setclickEvent(Method(:pNew))
						settooltip("New File")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/open.png")
						setclickEvent(Method(:pOpen))
						settooltip("Open File")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/save.png")
						setclickEvent(Method(:pSave))
						settooltip("Save")
					 } ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/saveas.png")
						setclickEvent(Method(:pSaveAs))
						settooltip("Save As")
					 } ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/undo.png")
						setclickEvent(Method(:pUndo))
						settooltip("Undo")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/cut.png")
						setclickEvent(Method(:pCut))
						settooltip("Cut")
					 } ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/copy.png")
						setclickEvent(Method(:pCopy))
						settooltip("Copy")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/paste.png")
						setclickEvent(Method(:pPaste))
						settooltip("Paste")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/font.png")
						setclickEvent(Method(:pFont))
						settooltip("Font")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/colors.jpg")
						setclickEvent(Method(:pColor))
						settooltip("Text Color")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/search.png")
						setclickEvent(Method(:pFind))
						settooltip("Find and Replace")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/print.png")
						setclickEvent(Method(:pPrint))
						settooltip("Print")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/debug.png")
						setclickEvent(Method(:pDebug))
						settooltip("Debug (Run then wait!)")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/run.png")
						setclickEvent(Method(:pRun))
						settooltip("Run the program")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/rungui.bmp")
						setclickEvent(Method(:pRunNoConsole))
						settooltip("Run GUI Application (No Console)")
					} ,
					new qpushbutton(this.win1) {
						setbtnimage(self,"image/close.png")
						setclickEvent(Method(:pQuit))
						settooltip("Quit")
					}
				]

			tool1 = addtoolbar("files")  {
				for x in aBtns addwidget(x) addseparator() next
			}

			menu1 = new qmenubar(this.win1) {
				subFile = addmenu("File")
				subEdit = addmenu("Edit")
				subView = addmenu("View")
				subProgram = addmenu("Program")
				subBrowser = addmenu("Browser")
				subTools = addmenu("Tools")
				subHelp = addmenu("Help")
				subFile {
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+n"))
						setbtnimage(self,"image/new.png")
						settext("New")
						setclickEvent(Method(:pNew))
					}
					addaction(oAction)
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+o"))
						setbtnimage(self,"image/open.png")
						settext("Open")
						setclickEvent(Method(:pOpen))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+s"))
						setbtnimage(self,"image/save.png")
						settext("Save")
						setclickEvent(Method(:pSave))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+e"))
						setbtnimage(self,"image/saveas.png")
						settext("Save As")
						setclickEvent(Method(:pSaveAs))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+p"))
						setbtnimage(self,"image/print.png")
						settext("Print to PDF")
						setclickEvent(Method(:pPrint))
					}
					addaction(oAction)
					addseparator()
					oAction = new qaction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+q"))
						setbtnimage(self,"image/close.png")
						settext("Exit")
						setstatustip("Exit")
						setclickEvent(Method(:pQuit))
					}
					addaction(oAction)
				}
				subEdit {
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+z"))
						setbtnimage(self,"image/undo.png")
						settext("Undo")
						setclickEvent(Method(:pUndo))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+x"))
						setbtnimage(self,"image/cut.png")
						settext("Cut")
						setclickEvent(Method(:pCut))
					}
					addaction(oAction)
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+c"))
						setbtnimage(self,"image/copy.png")
						settext("Copy")
						setclickEvent(Method(:pCopy))
					}
					addaction(oAction)
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+v"))
						setbtnimage(self,"image/paste.png")
						settext("Paste")
						setclickEvent(Method(:pPaste))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+i"))
						setbtnimage(self,"image/font.png")
						settext("Font")
						setclickEvent(Method(:pFont))
					}
					addseparator()
					addaction(oAction)
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+t"))
						setbtnimage(self,"image/colors.jpg")
						settext("Text Color")
						setclickEvent(Method(:pColor))
					}
					addaction(oAction)
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+b"))
						setbtnimage(self,"image/colors.jpg")
						settext("Back Color")
						setclickEvent(Method(:pColor2))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+g"))
						settext("Go to line")
						setclickEvent(Method(:pGoto))
					}
					addaction(oAction)
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+f"))
						setbtnimage(self,"image/search.png")
						settext("Find and Replace")
						setclickEvent(Method(:pFind))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+h"))
						settext("Set Tab Width")
						setclickEvent(Method(:pTabWidth))
					}
					addaction(oAction)
				}
				subView {
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+j"))
						setbtnimage(self,"image/project.png")
						settext("Project Files")
						setclickEvent(Method(:pProject))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+u"))
						setbtnimage(self,"image/source.png")
						setclickEvent(Method(:pSourceCode))
						settext("Source Code")
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+w"))
						setbtnimage(self,"image/richtext.png")
						setclickEvent(Method(:pWebBrowser))
						settext("Web Browser")
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Alt+f"))
						setbtnimage(self,"image/source.png")
						setclickEvent(Method(:pFunctionsList))
						settext("Functions List")
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Alt+c"))
						setbtnimage(self,"image/source.png")
						setclickEvent(Method(:pClassesList))
						settext("Classes List")
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Alt+o"))
						setbtnimage(self,"image/source.png")
						setclickEvent(Method(:pOutputWindow))
						settext("Output Window")
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Alt+f"))
						setbtnimage(self,"image/formdesigner.png")
						setclickEvent(Method(:pFormDesignerWindow))
						settext("Form Designer Window")
					}
					addaction(oAction)

				}
				subProgram {
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+d"))
						setbtnimage(self,"image/debug.png")
						settext("Debug (Run then wait!)")
						setclickEvent(Method(:pDebug))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+r"))
						setbtnimage(self,"image/run.png")
						settext("Run")
						setclickEvent(Method(:pRun))
					}
					addaction(oAction)
					addseparator()
					oAction = new qAction(this.win1) {
						setShortcut(new QKeySequence("Ctrl+F5"))
						setbtnimage(self,"image/run.png")
						settext("Run GUI Application (No Console)")
						setclickEvent(Method(:pRunNoConsole))
					}
					addaction(oAction)
				}
				subBrowser {

					for x=1 to len(this.aBrowserLinks)
						item = this.aBrowserLinks[x]
						oAction = new qAction(this.win1) {
							settext(item[1])
							setclickEvent(Method(:pBrowserLink+"("+x+")"))
						}
						addaction(oAction)
						if x != len(this.aBrowserLinks)
							addseparator()
						ok
					next
				}
				subTools {
					oAction = new qAction(this.win1) {
						settext("Form Designer")
						setclickEvent(Method(:pFormDesigner))
					}
					addaction(oAction)
				}

				subHelp {

					subHelpLF = addmenu("Language Reference")
					subHelpLF {
						oAction = new qAction(this.win1) {
							settext("CHM File")
							setclickEvent(Method(:pOpenCHM))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext("PDF File")
							setclickEvent(Method(:pOpenPDF))
						}
						addaction(oAction)
					}
					addseparator()
					subHelpTools = addmenu("Development Tools")
					subHelpTools {

						oAction = new qAction(this.win1) {
							settext("Programming Language")
							setclickEvent(Method(:pLang))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext("GUI Library")
							setclickEvent(Method(:pGUI))
						}
						addaction(oAction)
					}
					addseparator()
						oAction = new qAction(this.win1) {
							settext("About")
							setclickEvent(Method(:pAbout))
						}
						addaction(oAction)
				}
			}

			setmenubar(menu1)

			this.status1 = new qstatusbar(this.win1) {
				showmessage("Ready!",0)
			}

			setstatusbar(this.status1)

			this.tree1 = new qtreeview(this.win1) {
				setclickedEvent(Method(:pChangeFile))
				setGeometry(00,00,200,400)
				setmaximumwidth(300)
				chdir(this.cStartUpFolder)
				oDir = new QDir()
				this.ofile = new QFileSystemModel() {
					setrootpath(oDir.currentpath())
					myfiles = new qstringlist()
					myfiles.append("*.ring")
					myfiles.append("*.rh")
					myfiles.append("*.rform")
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
				setmodel(this.ofile)
				myindex = this.ofile.index(oDir.currentpath(),0)
				for x = 1 to this.ofile.columncount()
					hidecolumn(x)
				next
				setcurrentindex(myindex)
				setexpanded(myindex,true)
				header().hide()
				chdir(exefolder())
				if not ismacosx()
					this.cWebsite = "file:///"+oDir.CurrentPath() + "/../docs/build/html/index.html"
				ok
			}

			this.oDock1 = new qdockwidget(this.win1,0) {
				setGeometry(00,00,200,200)
				setwindowtitle("Project Files")
				setwidget(this.tree1)
			}

			this.textedit1 = new codeeditor(this.win1) {
				setCursorPositionChangedEvent(Method(:pCursorPositionChanged))
				setLineWrapMode(QTextEdit_NoWrap)
				setTextChangedEvent(Method(:pTextChanged))
				setLineNumbersAreaColor(this.aStyleColors[:LineNumbersAreaColor])
				setLineNumbersAreaBackColor(this.aStyleColors[:LineNumbersAreaBackColor])
			}
			this.AutoComplete()

			new RingCodeHighLighter(this.textedit1.document() ) {
				setColors(
					this.aStyleColors[:SyntaxKeywordsColor],
					this.aStyleColors[:SyntaxClassNamesColor],
					this.aStyleColors[:SyntaxCommentsColor],
					this.aStyleColors[:SyntaxLiteralsColor],
					this.aStyleColors[:SyntaxFunctionCallsColor]
				)
			}

			this.oDock2 = new qdockwidget(this.win1,0) {
				setwidget(this.textedit1)
				setwindowtitle("Source Code")
			}

			this.oWebBrowser = new qWidget() {
				setWindowFlags(Qt_SubWindow)
				oWBLabel = new qLabel(this.win1) {
					setText("Website: ")
				}
				this.oWBText = new qLineEdit(this.win1) {
					setText(this.cWebSite)
					setReturnPressedEvent(Method(:pWebGo))
				}
				oWBGo = new qPushButton(this.win1) {
					setText("Go")
					setClickEvent(Method(:pWebGo))
				}
				oWBBack = new qPushButton(this.win1) {
					setText("Back")
					setClickEvent(Method(:pWebBack))
				}
				oWBLayout1 = new qHBoxLayout() {
					addWidget(oWBLabel)
					addWidget(this.oWBText)
					addWidget(oWBGo)
					addWidget(oWBBack)
				}
				this.oWebView = new qWebView(this.win1) {
					loadpage(new qurl(this.cWebSite))
				}
				oWBlayout2 = new qVBoxLayout() {
					addLayout(oWBLayout1)
					addWidget(this.oWebView)
				}
				setLayout(oWBLayout2)
			}

			this.oDock3 = new qdockwidget(this.win1,0) {
				setwidget(this.oWebBrowser)
				setwindowtitle("Web Browser")
			}

			# Functions List

			this.aFunctionsPos = []	# Lines Numbers for each function
			this.oFunctionsList = new qListwidget(this.win1) {
				setitemdoubleclickedEvent(Method(:pSelectFunction))
				setitemactivatedEvent(Method(:pSelectFunction))
			}

			this.oDock4 = new qDockwidget(this.win1,0) {
				setWidget(this.oFunctionsList)
				setwindowtitle("Functions")
			}

			# Classes List

			this.aClassesPos = []	# Lines Numbers for each class
			this.oClassesList = new qListwidget(this.win1) {
				setitemdoubleclickedEvent(Method(:pSelectClass))
				setitemactivatedEvent(Method(:pSelectClass))
			}

			this.oDock6 = new qDockwidget(this.win1,0) {
				setWidget(this.oClassesList)
				setwindowtitle("Classes")
			}

			# Output Window

			this.oProcess = NULL

			oProcessWindow = new qWidget()

			oProcessLabel = new qLabel(oProcessWindow) {
				setText("Input :")
			}
			this.oProcessText = new qlineEdit(oProcessWindow) {
				setreturnPressedEvent(Method(:pSendProcessData))
			}

			oProcessbtnSend = new qpushbutton(oProcessWindow) {
				setText("Send")
				setClickEvent(Method(:pSendProcessData))
			}

			oProcessLayout1 = new qhboxlayout() {
				AddWidget(oProcessLabel)
				AddWidget(this.oProcessText)
				Addwidget(oProcessbtnSend)
			}
			this.oProcessEditbox = new qPlaintextedit(oProcessWindow)

			oProcessLayout2 = new qvboxlayout() {
				addWidget(this.oProcesseditbox)
				addlayout(oProcesslayout1)
			}

			oProcessWindow.setlayout(oProcessLayout2)

			this.oDock5 = new qDockWidget(this.win1,0) {
				setwidget( oProcessWindow )
				setwindowtitle("Output")
			}

			this.oDock7 = new qDockwidget(this.win1,0) {
				setwindowtitle("Form Designer")
			}
			this.pformdesignerdock()

			adddockwidget(1,this.oDock1,1)
			adddockwidget(2,this.oDock2,2)
			adddockwidget(2,this.oDock4,1)
			adddockwidget(2,this.oDock6,1)
			adddockwidget(2,this.oDock3,1)
			adddockwidget(2,this.oDock5,1)
			adddockwidget(2,this.oDock7,1)

			this.win1.tabifydockwidget(this.oDock5,this.oDock4)
			this.win1.tabifydockwidget(this.oDock5,this.oDock6)
			this.win1.tabifydockwidget(this.oDock2,this.oDock7)
			this.win1.tabifydockwidget(this.oDock2,this.oDock3)

			setwinicon(self,this.cCurrentDir + "/image/notepad.png")
			showmaximized()
		}

		this.RestoreSettings()

		exec()
	}

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

	func pClassesList
		if oDock6.isvisible()
			oDock6.hide()
		else
			oDock6.Show()
			DisplayClassesList()
		ok

	func pOutputWindow
		if oDock5.isvisible()
			oDock5.hide()
		else
			oDock5.Show()
		ok

	func pFormDesignerWindow
		if oDock7.isvisible()
			oDock7.hide()
		else
			oDock7.Show()
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
		DisplayClassesList()
		StatusMessage("Ready!")

	func pSetActiveFileName
		oDock2.setWindowTitle("Source Code : " + cActiveFileName)

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

	func pFind
		if isobject(oSearch)
			oSearch.activatewindow()
			return
		ok
		oSearch = new qWidget()
		{
			oLblFindWhat = new qLabel(this.oSearch)
			{
				setText("Find What : ")
			}
			this.oSearchValue = new qlineedit(this.oSearch)
			{
				setText(this.cSearchText)
				setReturnPressedEvent(Method(:pFindValue))
			}
			oLayout1 = new qHBoxLayout()
			{
				addWidget(oLblFindWhat)
				addWidget(this.oSearchValue)
			}
			oLblReplaceWith = new qLabel(this.oSearch)
			{
				setText("Replace with ")
			}
			this.oReplaceValue = new qlineedit(this.oSearch)
			{
				setText(this.cReplaceText)
			}

			oLayout2 = new qHBoxLayout()
			{
				addWidget(oLblReplaceWith)
				addWidget(this.oReplaceValue)
			}
			this.oSearchCase = new qCheckbox(this.oSearch)
			{
				setText("Case Sensitive")
			}
			oLayout3 = new qHBoxLayout()
			{
				addWidget(this.oSearchCase)
			}
			oBtnFind = new qPushButton(this.oSearch)
			{
				setText("Find/Find Next")
				setclickEvent(Method(:pFindValue))
			}
			oBtnReplace = new qPushButton(this.oSearch)
			{
				setText("Replace")
				setclickEvent(Method(:pReplace))
			}
			oBtnReplaceAll = new qPushButton(this.oSearch)
			{
				setText("Replace All")
				setclickEvent(Method(:pReplaceAll))
			}
			oBtnClose = new qPushButton(this.oSearch)
			{
				setText("Close")
				setclickEvent(Method(:pSearchClose))
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

			setwinicon(this.oSearch,"image/notepad.png")
			setWindowTitle("Find/Replace")
			setFixedsize(550,160)
			setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint)

			this.oSearchFilter = new qallevents(this.oSearch)
			this.oSearchFilter.setKeyPressEvent(Method(:pSearchKeyPress))
			installeventfilter(this.oSearchFilter)

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
			oProcessEditbox.setplaintext("")
			oProcessText.setFocus(0)
			oProcess = pRunProcess(cCurrentDir+"run2.bat",cActiveFileName,cpGetProcessData)
		else
			cCode = 'cd $(dirname "'+cActiveFileName+'") ; ' + ' ring "' + cActiveFileName + '"' + nl
			system(cCode)
		ok

	func pSave
		if cActiveFileName = NULL return pSaveAs() ok
		writefile(cActiveFileName,textedit1.toplaintext())
		StatusMessage("File : " + cActiveFileName + " saved!")
		lAskToSave = false
		AutoComplete()
		displayFunctionsList()
		displayClassesList()
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
			ok
		}

	func pPrint
		StatusMessage("Printing to File : RingDoc.pdf")
		printer1 = new qPrinter(0) {
			setoutputformat(1)	# 1 = pdf
			setoutputfilename("RingDoc.pdf")
			this.textedit1.print(printer1)
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
			myfont.fromstring(this.cFont)
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
		}
		this.aTextColor = [r,g,b]
		pSetColors()

	Func pColor2
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

	Func pSetColors
		this.textedit1.setstylesheet("color: rgb(" + aTextColor[1] + "," + aTextColor[2] +
					"," + aTextColor[3] + ");" + "background-color: rgb(" +
					aBackColor[1] + "," + aBackColor[2] + "," +
					aBackColor[3] + ")")

	Func pSetWindows
		if not lShowProject  	oDock1.close() else oDock1.show() ok
		if not lShowSourceCode  oDock2.close() else oDock2.show() ok
		if not lShowBrowser  	oDock3.close() else oDock3.show() ok
		if not lShowFunctionsList oDock4.close() else oDock4.show() ok
		if not lShowClassesList oDock6.close() else oDock6.show() ok
		if not lShowOutputWindow oDock5.close() else oDock5.show() ok
		if not lShowFormDesigner oDock7.close() else oDock7.show() ok

	func pOpen
		new qfiledialog(this.win1) {
			this.pSaveCurrentFolder()
			cName = getopenfilename(this.win1,"open file",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				this.cActiveFileName = cName
				this.textedit1.setPlaintext(read(this.cActiveFileName))
				this.pSetActiveFileName()
			ok
		}

	func pNew
		new qfiledialog(this.win1) {
			this.pSaveCurrentFolder()
			cName = getsavefilename(this.win1,"New file",this.cStartupFolder,"source files(*.ring)")
			if cName != NULL
				write(cName,"")
				this.cActiveFileName = cName
				this.textedit1.setPlaintext(read(this.cActiveFileName))
				this.pSetActiveFileName()
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
			setwinicon(win,this.cCurrentDir + "/image/notepad.png")
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
				"lShowClassesList = " + oDock6.isvisible() + nl +
				"lShowOutputWindow = " + oDock5.isvisible() + nl +
				"lShowFormDesigner = " + oDock7.isvisible() + nl +
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
				this.win1 {
				if result = QMessageBox_Yes
					this.pSave()
				but result = QMessageBox_Cancel
					return false
				ok
			}
		}
		ok
		return true

	Func pSetWebsite
		oWebView { loadpage(new qurl(this.cWebSite)) }
		oWBText  { setText(this.cWebSite) }

	Func LoadSettings
		if fexists(cSettingsFile)
			eval(read(cSettingsFile))
		ok

	Func RestoreSettings
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
				cLine = substr(cLine,"("," (")
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
		oDock4.setWindowTitle("Functions ("+oFunctionsList.Count()+")")
		StatusMessage("Creating functions list ... Done!")

	func pSelectFunction
		nIndex = oFunctionsList.currentrow() + 1
		nLine = aFunctionsPos[nIndex][2]
		gotoline(nLine)

	func DisplayClassesList
		oClassesList.clear()
		if oDock6.isvisible() = false return ok
		aClassesPos = []	# Lines numbers for each class
		if cActiveFileName = NULL return ok
		# Set the font
			oFont = new qfont("",0,0,0)
			oFont.fromstring(cFont)
			oClassesList.setFont(oFont)
		StatusMessage("Creating Classes list ... Please Wait!")
		aFileContent = str2list(read(cActiveFileName))
		nLineNumber = 0
		for cLine in aFileContent
			nLineNumber++
			cLine = lower(trim(cLine))
			if substr(cLine,"class ") > 0
				aList = Split(cLine," ")
				if len(aList) >= 2
					cClassName = lower(trim(aList[2]))
					if lower(trim(aList[1])) = "class"
						aClassesPos + [cClassName , nLineNumber]
					ok
				ok
			ok
		next
		aClassesPos = Sort(aClassesPos,1)
		for cClass in aClassesPos
			oClassesList.addItem(cClass[1])
		next
		oDock6.setWindowTitle("Classes ("+oClassesList.Count()+")")
		StatusMessage("Creating classes list ... Done!")

	func pSelectClass
		nIndex = oClassesList.currentrow() + 1
		nLine = aClassesPos[nIndex][2]
		gotoline(nLine)

	func StatusMessage cMsg
		status1.showmessage(cMsg,0)

	func pRunProcess cProgram,cArg,cGetDataFunc
		oStringList = new qStringlist() {
			append(cArg)
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
		aText = str2list(cText)
		for x = len(aText) to 1 step -1
			if substr(aText[x],"echo off") or trim(aText[x]) = NULL or isprint(aText[x]) = false
				del(aText,x)
			ok
		next
		cText = list2str(aText)
		see cText
		# Set the font
			oFont = new qfont("",0,0,0)
			oFont.fromstring(cFont)
			oProcessEditbox.setFont(oFont)
		oProcessEditbox.insertplaintext(cText)

	func pSendProcessData
		if ISNULL(oProcess) return ok
		cText = oProcessText.text() + windowsnl()
		oProcess.write(cText ,len(cText))
		oProcessEditbox.insertplaintext(cText)

	func pFormDesigner		
		cFormFileName = cCurrentDir + "../formdesigner/formdesigner.ring"
		if iswindows()
			oProcessEditbox.setplaintext("")
			oProcessText.setFocus(0)
			oProcess = pRunProcess(cCurrentDir+"run2.bat",cFormFileName,cpGetProcessData)
		else
			cCode = 'cd $(dirname "'+cFormFileName+'") ; ' + ' ring "' + cFormFileName + '"' + nl
			system(cCode)
		ok		

	func pFormDesignerDock
		cDir = CurrentDir()
		chdir(exefolder() + "/../applications/formdesigner")
		open_window(:FormDesignerController)
		Last_Window().setParentObject(self)
		nFormDesignerWindowID = Last_WindowID()
		oDock7.setWidget(Last_Window().oView.win)
		chdir(cDir)

	func FormDesignerObject
		return GetObjectByID(nFormDesignerWindowID)

	func GetActiveFolder
		return cStartUpFolder

	func pCheckCustomColors
		if True	# Switch to Use the Style or Not
			pStyleWhite()
		ok

	func pStyleBlue()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorWhite ,
				:LineNumbersAreaBackColor 	= colordarkBlue,
				:ActiveLineBackColor 		= colordarkBlue,
				:SyntaxKeywordsColor		= colorWhite,
				:SyntaxClassNamesColor 		= ColorWhite,
				:SyntaxCommentsColor 		= ColorSilver,
				:SyntaxLiteralsColor 		= ColorCyan,
				:SyntaxFunctionCallsColor 		= ColorGreen
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [0,0,135]
			MyApp.StylefusionCustom(
				new qColor() { setrgb(0,0,128,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(0,0,128,255) },
				new qColor() { setrgb(0,0,128,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(0,0,128,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(255,0,0,255) },
				new qColor() { setrgb(142,45,197,255) },
				new qColor() { setrgb(0,0,128,255)}
			)

	func pStyleBlack()
			MyApp.StyleFusionBlack()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorWhite ,
				:LineNumbersAreaBackColor 	= colorBlack,
				:ActiveLineBackColor 		= colorBlack,
				:SyntaxKeywordsColor		= colorWhite,
				:SyntaxClassNamesColor 		= ColorWhite,
				:SyntaxCommentsColor 		= ColorSilver,
				:SyntaxLiteralsColor 		= ColorCyan,
				:SyntaxFunctionCallsColor 		= ColorGreen
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [0,0,0]

	func pStyleWhite()
			MyApp.StyleFusion()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorBlack ,
				:LineNumbersAreaBackColor 	= colorCyan,
				:ActiveLineBackColor 		= colorCyan,
				:SyntaxKeywordsColor		= colordarkBlue,
				:SyntaxClassNamesColor 		= ColordarkMagenta,
				:SyntaxCommentsColor 		= ColorRed,
				:SyntaxLiteralsColor 		= ColorDarkGreen,
				:SyntaxFunctionCallsColor 	= ColorBlue
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [0,0,0]
			aBackColor = [255,255,255]
