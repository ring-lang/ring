# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteView 

	func CreateMainWindow 

		MyApp = New qApp {
			# Custom Editor Style Color
			this.pCheckCustomColors()
			this.PrepareAutoComplete()
			this.win1 = new qMainWindow() {
				this.oFilter = new qAllEvents(this.win1)
				this.oFilter.setCloseEvent(Method(:pRingNotepadXButton))
				installEventFilter(this.oFilter)
				setwindowtitle("Ring Notepad")
				this.CreateToolbars()	
				this.CreateMenubar()
				this.CreateStatusbar()
				this.CreateProjectFiles()	
				this.CreateSourceCode()
				this.oWebBrowser = new qWidget() {
					setstylesheet("color: black ; background-color: rgba(239,235,231,255);")
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
				this.oDockWebBrowser = new qdockwidget(this.win1,0) {
					setwidget(this.oWebBrowser)
					setwindowtitle("Web Browser")
				}
				# Functions List
				this.aFunctionsPos = []	# Lines Numbers for each function
				this.oFunctionsList = new qListwidget(this.win1) {
					setitemdoubleclickedEvent(Method(:pSelectFunction))
					setitemactivatedEvent(Method(:pSelectFunction))
				}
				this.oDockFunctionsList = new qDockwidget(this.win1,0) {
					setWidget(this.oFunctionsList)
					setwindowtitle("Functions")
				}
				# Classes List
				this.aClassesPos = []	# Lines Numbers for each class
				this.oClassesList = new qListwidget(this.win1) {
					setitemdoubleclickedEvent(Method(:pSelectClass))
					setitemactivatedEvent(Method(:pSelectClass))
				}
				this.oDockClassesList = new qDockwidget(this.win1,0) {
					setWidget(this.oClassesList)
					setwindowtitle("Classes")
				}
				# Output Window
				this.oProcess = NULL
				this.oOutputWindow = new qWidget()
				oProcessLabel = new qLabel(this.oOutputWindow) {
					setText("Input :")
				}
				this.oProcessText = new qlineEdit(this.oOutputWindow) {
					setreturnPressedEvent(Method(:pSendProcessData))
				}
				oProcessbtnSend = new qpushbutton(this.oOutputWindow) {
					setText("Send")
					setClickEvent(Method(:pSendProcessData))
				}
				oClearbtn = new qpushbutton(this.oOutputWindow) {
					setText("Clear")
					setClickEvent(Method(:pClearProcess))
				}
				oProcessLayout1 = new qhboxlayout() {
					AddWidget(oProcessLabel)
					AddWidget(this.oProcessText)
					Addwidget(oProcessbtnSend)
	                		Addwidget(oClearbtn)
				}
				this.oProcessEditbox = new qPlaintextedit(this.oOutputWindow) 
				oProcessLayout2 = new qvboxlayout() {
					addWidget(this.oProcesseditbox)
					addlayout(oProcesslayout1)
				}
				this.oOutputWindow.setlayout(oProcessLayout2)
				this.oDockOutputWindow = new qDockWidget(this.win1,0) {
					setwidget( this.oOutputWindow )
					setwindowtitle("Output")
				}
				this.oDockFormDesigner = new qDockwidget(this.win1,0) {
					setwindowtitle("Form Designer")
				}
				this.pformdesignerdock()
				adddockwidget(Qt_LeftDockWidgetArea,this.oDockProjectFiles,1)
				adddockwidget(Qt_RightDockWidgetArea,this.oDockSourceCode,2)
				adddockwidget(Qt_RightDockWidgetArea,this.oDockFunctionsList,1)
				adddockwidget(Qt_RightDockWidgetArea,this.oDockClassesList,1)
				adddockwidget(Qt_RightDockWidgetArea,this.oDockWebBrowser,1)
				adddockwidget(Qt_BottomDockWidgetArea,this.oDockOutputWindow,1)
				adddockwidget(Qt_RightDockWidgetArea,this.oDockFormDesigner,1)
				this.win1 {
					tabifydockwidget(this.oDockFunctionsList,this.oDockClassesList)
					tabifydockwidget(this.oDockFunctionsList,this.oDockOutputWindow)
					tabifydockwidget(this.oDockSourceCode,this.oDockFormDesigner)
					tabifydockwidget(this.oDockSourceCode,this.oDockWebBrowser)
				}
				setwinicon(self,this.cCurrentDir + "/image/notepad.png")
				this.oDockSourceCode.raise()
				this.oDockFunctionsList.raise()
			}
			this {  
				pSetMode(nDefaultMode) 
				RestoreSettings()
				win1.showmaximized()
			}
			exec()
		}
	
	
	func CreateToolBars
		win1 {
			aBtns = [
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/new.png")
						setclickEvent(Method(:pNew))
						settooltip("New File (Ctrl+N)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/open.png")
						setclickEvent(Method(:pOpen))
						settooltip("Open File (Ctrl+O)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/save.png")
						setclickEvent(Method(:pSave))
						settooltip("Save (Ctrl+S)")
					 } ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/saveas.png")
						setclickEvent(Method(:pSaveAs))
						settooltip("Save As (Ctrl+E)")
					 } ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/undo.png")
						setclickEvent(Method(:pUndo))
						settooltip("Undo (Ctrl+Z)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/cut.png")
						setclickEvent(Method(:pCut))
						settooltip("Cut (Ctrl+X)")
					 } ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/copy.png")
						setclickEvent(Method(:pCopy))
						settooltip("Copy (Ctrl+C)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/paste.png")
						setclickEvent(Method(:pPaste))
						settooltip("Paste (Ctrl+V)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/font.png")
						setclickEvent(Method(:pFont))
						settooltip("Font (Ctrl+I)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/search.png")
						setclickEvent(Method(:pFind))
						settooltip("Find and Replace (Ctrl+F)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/print.png")
						setclickEvent(Method(:pPrint))
						settooltip("Print (Ctrl+P)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/debug.png")
						setclickevent(Method(:pDebug)) 
						settooltip("Debug - Run then wait! (Ctrl+D)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/run.png")
						setclickEvent(Method(:pRun))
						settooltip("Run the program (Ctrl+R) ")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/rungui.png")
						setclickEvent(Method(:pRunNoConsole))
						settooltip("Run GUI Application - No Console (Ctrl+F5)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/web.png")
						setclickEvent(Method(:RunInBrowser))
						settooltip("Run Web Application - Open In Browser (Ctrl+F6)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/close.png")
						setclickEvent(Method(:pQuit))
						settooltip("Quit (Ctrl+Q)")
					}
				]
	
			tool1 = addtoolbar("files")  {
				for x in aBtns addwidget(x) addseparator() next
			}
	
			# Main File Toolbar
			tool2 = addtoolbar("mainfile")  {
				oLblMainFile = new qLabel(this.win1) {
					setText("Main File : ")
				}
				this.oTxtMainFile = new qLineEdit(this.win1) {
					setStylesheet("border: 0px;  background-color: rgba(0, 0, 0, 0);")
					setReadOnly(True)
				}
				oBtnSetFile = new qtoolbutton(this.win1) {
					setbtnimage(self,"image/open.png")
					setclickEvent(Method(:pSetMainFile))
					settooltip("Set the Main File to be the current source file (Ctrl+Shift+M)")
				}
				oBtnDebugMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/debug.png")
						setclickevent(Method(:pDebugMainFile)) 
						settooltip("Main File : Debug  - Run then wait! (Ctrl+Shift+D)")
				} 
				oBtnRunMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/run.png")
						setclickEvent(Method(:pRunMainFile))
						settooltip("Main File : Run the program (Ctrl+Shift+R)")
				} 
				oBtnRunGUIMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/rungui.png")
						setclickEvent(Method(:pRunGUIMainFile))
						settooltip("Main File : Run GUI Application - No Console (Ctrl+Shift+F5)")
				} 
				oBtnRunWebMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/web.png")
						setclickEvent(Method(:RunInBrowserMainFile))
						settooltip("Main File : Run Web Application - Open In Browser (Ctrl+Shift+F6)")
				} 
				AddWidget(oLblMainFile)
				AddWidget(this.oTxtMainFile)
				AddWidget(oBtnSetFile)
				AddWidget(oBtnDebugMainFile)
				AddWidget(oBtnRunMainFile)
				AddWidget(oBtnRunGUIMainFile)
				AddWidget(oBtnRunWebMainFile)
			}
		}
	
	func CreateMenubar 
		win1 {
				menu1 = new qmenubar(this.win1) {
					subFile 	= addmenu("File")
					subEdit 	= addmenu("Edit")
					subView 	= addmenu("View")
					subProgram 	= addmenu("Program")
					subBrowser 	= addmenu("Browser")
					subTools 	= addmenu("Tools")
					subDistribute   = addmenu("Distribute")
					subHelp 	= addmenu("Help")
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
							setbtnimage(self,"image/colors.png")
							settext("Text Color")
							setclickEvent(Method(:pColor))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+b"))
							setbtnimage(self,"image/colors.png")
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
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+alt+f"))
							setbtnimage(self,"image/search.png")
							settext("Find in Files")
							setclickEvent(Method(:pFindInFiles))
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
							setShortcut(new QKeySequence("CTRL+SHIFT+f"))
							setbtnimage(self,"image/formdesigner.png")
							setclickEvent(Method(:pFormDesignerWindow))
							settext("Form Designer Window")
						}
						addaction(oAction)
						addseparator()
						subStyle = addmenu("Style")
						subStyle {
							setbtnimage(self,"image/colors.png")
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(0)"))
								settext("Windows")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(1)"))
								settext("Fusion : White")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(2)"))
								settext("Fusion : Blue")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(3)"))
								settext("Fusion : Black")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(4)"))
								settext("Modern")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(5)"))
								settext("Modern : Black")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(6)"))
								settext("Modern : Black 2")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(7)"))
								settext("Notepad : White")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(8)"))
								settext("Notepad : Purple")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(9)"))
								settext("Notepad : DarkBlue")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(10)"))
								settext("Notepad : Black")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(11)"))
								settext("Art")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(12)"))
								settext("Art 2")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(13)"))
								settext("Art 3")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(14)"))
								settext("Image")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetStyleColor(15)"))
								settext("Image 2")
							}
							addaction(oAction)
						}
						addseparator()
						subStyle = addmenu("Mode")
						subStyle {
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetMode(1)"))
								settext("General")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetMode(2)"))
								settext("Learning Ring (Editor + Documentation)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetMode(3)"))
								settext("Coding (Project File + Editor)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetMode(4)"))
								settext("Coding (All Windows)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetMode(5)"))
								settext("Coding (Code Editor)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetMode(6)"))
								settext("GUI Development (Code Editor + Form Designer)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetMode(7)"))
								settext("Web Development (Code Editor + Web Browser)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetMode(8)"))
								settext("Testing (Project Files + Code Editor + Output Window)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setclickEvent(Method("pSetMode(9)"))
								settext("Common (All Windows + Output Window in the bottom)")
							}
							addaction(oAction)
						}
					} 
					subProgram {
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+d"))
							setbtnimage(self,"image/debug.png")
							settext("Debug (Run then wait!)")
							setclickEvent(Method(:pDebug))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+r"))
							setbtnimage(self,"image/run.png")
							settext("Run")
							setclickEvent(Method(:pRun))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+F5"))
							setbtnimage(self,"image/rungui.png")
							settext("Run GUI Application (No Console)")
							setclickEvent(Method(:pRunNoConsole))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+F6"))
							setbtnimage(self,"image/web.png")
							settext("Run Web Application (Open In Browser)")
							setclickEvent(Method(:RunInBrowser))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+M"))
							setbtnimage(self,"image/open.png")
							settext("Set the Main File to be the current source file")
							setclickEvent(Method(:pSetMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+d"))
							setbtnimage(self,"image/debug.png")
							settext("Main File : Debug (Run then wait!)")
							setclickEvent(Method(:pDebugMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+r"))
							setbtnimage(self,"image/run.png")
							settext("Main File : Run")
							setclickEvent(Method(:pRunMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+F5"))
							setbtnimage(self,"image/rungui.png")
							settext("Main File : Run GUI Application (No Console)")
							setclickEvent(Method(:pRunGUIMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+F6"))
							setbtnimage(self,"image/web.png")
							settext("Main File : Run Web Application (Open In Browser)")
							setclickEvent(Method(:RunInBrowserMainFile))
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
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Alt+R"))
							settext("RingREPL - Console")
							setclickEvent(Method(:pREPLConsole))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Alt+Shift+R"))
							settext("RingREPL - GUI")
							setclickEvent(Method(:pREPLGUI))
						}
						addaction(oAction)
						addseparator()
						subOSTools = addmenu("Operating System Tools")
						subOSTools {
							oAction = new qAction(this.win1) {
								settext("Terminal (Command Prompt)")
								setShortcut(new QKeySequence("Alt+Shift+T"))
								setclickEvent(Method(:OSTerminal))
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								settext("Files Manager (Explorer)")
								setShortcut(new QKeySequence("Alt+Shift+F"))
								setclickEvent(Method(:OSFilesManager))
							}
							addaction(oAction)
						}
					}
					subDistribute {
						oAction = new qAction(this.win1) {
							settext("Generate Ring Object File (*.ringo)")
							setclickEvent(Method("pDistribute(1)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Build Console Application)")
							setclickEvent(Method("pDistribute(2)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Distribute Application - Use All Runtime)")
							setclickEvent(Method("pDistribute(3)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Distribute Application - Use All Runtime - Hide Console Window)")
							setclickEvent(Method("pDistribute(4)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Distribute RingQt Application)")
							setclickEvent(Method("pDistribute(5)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Distribute RingAllegro Game)")
							setclickEvent(Method("pDistribute(6)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Prepare Qt Project - Distribute for Mobile Devices)")
							setclickEvent(Method("pDistribute(7)"))
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
		}

	func CreateStatusbar
		win1 {
			this.status1 = new qstatusbar(this.win1) {
				showmessage("Ready!",0)
			}
			setstatusbar(this.status1)
		}

	func CreateProjectFiles
		win1 {
			this.tree1 = new qtreeview(this.win1) {
				setStylesheet("font-size: 30")
				setclickedEvent(Method(:pChangeFile))
				setActivatedEvent(Method(:pChangeFile))
				setGeometry(00,00,200,400)
				setminimumwidth(250)
                		chdir(this.cStartUpFolder)
				oDir = new QDir()
				this.ofile = new QFileSystemModel() {
					setrootpath(oDir.currentpath())
					myfiles = new qstringlist() {
						append("*.ring")
						append("*.rh")
						append("*.rform")
						append("*.txt")
						append("*.html")
						append("*.rhtml")
						append("*.css")
						append("*.js")
						append("*.xml")
						append("*.data")
						append("*.sh")
						append("*.bat")
						append("*.md")
						append("*.cf")
						append("*.qml")
					}
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
			this.oDockProjectFiles = new qdockwidget(this.win1,0) {
				setGeometry(00,00,200,200)
				setwindowtitle("Project Files")
				setwidget(this.tree1)
			}
		}

	func CreateSourceCode
		win1 {
			this.textedit1 = new codeeditor(this.win1) {
				setCursorPositionChangedEvent(Method(:pCursorPositionChanged))
				setLineWrapMode(QTextEdit_NoWrap)
				setTextChangedEvent(Method(:pTextChanged))
				setLineNumbersAreaColor(this.aStyleColors[:LineNumbersAreaColor])
				setLineNumbersAreaBackColor(this.aStyleColors[:LineNumbersAreaBackColor])
			}
			this.AutoComplete()
			this.oACTimer = new qtimer(this.win1) {
				setinterval(5000)
				settimeoutevent(Method(:AutoCompleteTimer))
				start()
			}
			new RingCodeHighLighter(this.textedit1.document() ) {
				if ismethod(self,:setkeywordsbold) 
					setKeywordsbold(this.lKeywordsBold)
				ok
				setColors(
					this.aStyleColors[:SyntaxKeywordsColor],
					this.aStyleColors[:SyntaxClassNamesColor],
					this.aStyleColors[:SyntaxCommentsColor],
					this.aStyleColors[:SyntaxLiteralsColor],
					this.aStyleColors[:SyntaxFunctionCallsColor]
				)
			}
			this.oDockSourceCode = new qdockwidget(this.win1,0) {
				setwidget(this.textedit1)
				setwindowtitle("Source Code")
				setminimumwidth(340)                                                     
                        }
		}
