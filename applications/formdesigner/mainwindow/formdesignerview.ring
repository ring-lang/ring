/*
**	Project : Form Designer 
**	File Purpose :  Form Designer View
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

Class FormDesignerView from WindowsViewParent

	oForm oSub oFilter oArea win

	oPropertiesDock oProperties oProperties2
	oObjectsCombo 	oPropertiesTable oLabelSelect

	oToolBoxDock	oToolLock
	oToolBtn1 oToolBtn2 oToolBtn3 oToolBtn4 oToolBtn5
	oToolBtn6 oToolBtn7 oToolBtn8 oToolBtn9 oToolBtn10
	oToolBtn11 oToolBtn12 oToolBtn13 oToolBtn14
	oToolBtn15  oToolBtn16 oToolBtn17 oToolBtn18
	oToolBtn19 oToolBtn20 oToolBtn21 oToolBtn22 oToolBtn23
	oToolBtn24 oToolBtn25 oToolBtn26 oToolBtn27  oToolBtn28

	func CreateMainWindow oModel

		# Create the form
			oModel.AddObject("Window",
				 new FormDesigner_qWidget() {
					setWindowTitle(T_FORMDESIGNER_FORMTITLE) # "Form1"
				}
			)

		# Create the Select/Draw Label
			oLabelSelect = new qlabel(oModel.FormObject()) {
				setGeometry(100,100,400,400)
		 		setstylesheet("background-color:rgba(50,150,255,0.3);border: 1px solid black")
				setautoFillBackground(false)
				settext("")
				setmousetracking(false)
				hide()
			}

		# Add the form to the Sub Window
			oSub =  new QMdiSubWindow(null) {
				if T_LAYOUTDIRECTION {
					move(22,132)
				else 
					move(100,100)
				}
				resize(400,400)
				setwidget(oModel.FormObject())
				oModel.ActiveObject().setSubWindow(this.oSub)
				setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint )
				setStylesheet("background-color: rgba(239,235,231,255); color:black")
			}

		# Add the sub Window to the Mdi Area
			oArea = new qMdiArea(null) {
				addSubWindow(this.oSub,0)
				setHorizontalScrollBarPolicy(Qt_ScrollBarAlwaysOn)
				setVerticalScrollbarpolicy(Qt_ScrollBarAlwaysOn)
			}

		# Create the Main Window and use the Mdi Area
			win = new qMainwindow() {
				setWindowTitle(T_FORMDESIGNER_FORMDESIGNER) # "Form Designer"
				setcentralWidget(this.oArea)
				setLayoutDirection(T_LAYOUTDIRECTION)
			}
			setwinicon(win,$cCurrentDir + "/image/formdesigner.png")

		# Create the ToolBox
			CreateToolBox()

		# Create Properties Window
			CreateProperties()

		# Create the Menubar
			if not ((ismacosx() or islinux()) and $FDSubApp) {
				CreateMenuBar()
			}

		# Create the Toolbar
			CreateToolBar()

		# Create the Statusbar
			CreateStatusBar()

		# Show the Window
			win.showmaximized()

	func WindowMoveResizeEvents
		oFilter = new qAllEvents(oSub) {
			setResizeEvent(this.Method(:ResizeWindowAction))
			setMoveEvent(this.Method(:MoveWindowAction))
			setMouseButtonPressEvent(this.Method(:MousePressAction))
			setMouseButtonReleaseEvent(this.Method(:MouseReleaseAction))
			setMouseMoveEvent(this.Method(:MouseMoveAction))
			setKeyPressevent(this.Method(:KeyPressAction))
		}
		oSub.installeventfilter(oFilter)

	func CreateMenuBar
		menu1 = new qmenubar(win) {
			subFile = addmenu(T_FORMDESIGNER_FILE) # "File"
			subFile {
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+n"))
					setbtnimage(self,"image/new.png")
					settext(T_FORMDESIGNER_NEW) # "New"
					setclickevent(Method(:NewAction))
				}
				addaction(oAction)
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+o"))
					setbtnimage(self,"image/open.png")
					settext(T_FORMDESIGNER_OPEN) # "Open"
					setclickevent(Method(:OpenAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+s"))
					setbtnimage(self,"image/save.png")
					settext(T_FORMDESIGNER_SAVE) # "Save"
					setclickevent(Method(:SaveAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+e"))
					setbtnimage(self,"image/saveas.png")
					settext(T_FORMDESIGNER_SAVEAS) # "Save As"
					setclickevent(Method(:SaveAsAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qaction(this.win) {
					settext(T_FORMDESIGNER_CLOSE) # "Close"
					setstatustip("Close File")
					setclickevent(Method(:CloseAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qaction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+q"))
					setbtnimage(self,"image/close.png")
					settext(T_FORMDESIGNER_EXIT) # "Exit"
					setstatustip("Exit")
					setclickevent(Method(:ExitAction))
				}
				addaction(oAction)
			}
			subEdit = addmenu(T_FORMDESIGNER_EDIT) # "Edit"
			subEdit {
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+v"))
					settext(T_FORMDESIGNER_DUPLICATE) # "Duplicate"
					setclickevent(Method(:Duplicate))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+f"))
					settext(T_FORMDESIGNER_BRINGTOFRONT) # "Bring to front"
					setclickevent(Method(:BringToFront))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+b"))
					settext(T_FORMDESIGNER_SENDTOBACK) # "Send to back"
					setclickevent(Method(:SendToBack))
				}
				addaction(oAction)
			}
			subView = addmenu(T_FORMDESIGNER_VIEW) # "View"
			subView {
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+t"))
					settext(T_FORMDESIGNER_TOOLBOX) # "ToolBox"
					setclickevent(Method(:ToolBox))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+p"))
					setclickevent(Method(:Properties))
					settext(T_FORMDESIGNER_PROPERTIES) # "Properties"
				}
				addaction(oAction)
				addseparator()
			}
			subHelp = addmenu(T_FORMDESIGNER_HELP) # "Help"
			subHelp {
				subHelpLF = addmenu(T_FORMDESIGNER_LANGUAGEREFERENCE) # "Language Reference"
				subHelpLF {
					oAction = new qAction(this.win) {
						settext(T_FORMDESIGNER_CHMFILE) # "CHM File"
						setclickevent(Method(:OpenCHMAction))
					}
					addaction(oAction)
					oAction = new qAction(this.win) {
						settext(T_FORMDESIGNER_PDFFILE) # "PDF File"
						setclickevent(Method(:OpenPDFAction))
					}
					addaction(oAction)
				}
				addseparator()
				subHelpTools = addmenu(T_FORMDESIGNER_DEVELOPMENTTOOLS) # "Development Tools"
				subHelpTools {
					oAction = new qAction(this.win) {
						settext(T_FORMDESIGNER_PROGRAMMINGLANGUAGE) # "Programming Language"
						setclickevent(Method(:LangAction))
					}
					addaction(oAction)
					oAction = new qAction(this.win) {
						settext(T_FORMDESIGNER_GUILIBRARY) # "GUI Library"
						setclickevent(Method(:GUIAction))
					}
					addaction(oAction)
				}
				addseparator()
				oAction = new qAction(this.win) {
					settext(T_FORMDESIGNER_ABOUT) # "About"
					setclickevent(Method(:AboutAction))
				}
				addaction(oAction)
			}
		}
		win.setmenubar(menu1)

	func CreateStatusBar
		status1 = new qstatusbar(win) {
			showmessage(T_FORMDESIGNER_READY,0) # "Ready!"
		}
		win.setstatusbar(status1)

	func CreateToolBar
		aBtns = [
				new qtoolbutton(win) {
					setbtnimage(self,AppFile("image/new.png"))
					setclickevent(Method(:NewAction))
					settooltip(T_FORMDESIGNER_TOOLBAR_NEWFILE) # "New File"
				} ,
				new qtoolbutton(win) {
					setbtnimage(self,AppFile("image/open.png"))
					setclickevent(Method(:OpenAction))
					settooltip(T_FORMDESIGNER_TOOLBAR_OPENFILE) # "Open File"
				} ,
				new qtoolbutton(win) {
					setbtnimage(self,AppFile("image/save.png"))
					setclickevent(Method(:SaveAction))
					settooltip(T_FORMDESIGNER_TOOLBAR_SAVE) # "Save"
				 } ,
				new qtoolbutton(win) {
					setbtnimage(self,AppFile("image/saveas.png"))
					setclickevent(Method(:SaveAsAction))
					settooltip(T_FORMDESIGNER_TOOLBAR_SAVEAS) # "Save As"
				 } ,
				new qtoolbutton(win) {
					setbtnimage(self,AppFile("image/close.png"))
					setclickevent(Method(:ExitAction))
					settooltip(T_FORMDESIGNER_TOOLBAR_EXIT) # "Exit"
				}
			]

		tool1 = win.addtoolbar("files")  {
	  		for x in aBtns { addwidget(x) addseparator() }
		}

	func CreateToolBox

		if T_LAYOUTDIRECTION {
			aToolBoxTextList = [
				:Lock = T_FROMDESIGNER_TOOLBOX_LOCK ,
				:Select = T_FROMDESIGNER_TOOLBOX_SELECT,
				:Label = T_FROMDESIGNER_TOOLBOX_LABEL,
				:Button = T_FROMDESIGNER_TOOLBOX_BUTTON,
				:LineEdit = T_FROMDESIGNER_TOOLBOX_LINEEDIT,
				:TextEdit = T_FROMDESIGNER_TOOLBOX_TEXTEDIT,
				:ListWidget = T_FROMDESIGNER_TOOLBOX_LISTWIDGET,
				:CheckBox = T_FROMDESIGNER_TOOLBOX_CHECKBOX,
				:Image = T_FROMDESIGNER_TOOLBOX_IMAGE,
				:Slider = T_FROMDESIGNER_TOOLBOX_SLIDER,
				:ProgressBar = T_FROMDESIGNER_TOOLBOX_PROGRESSBAR,
				:SpinBox = T_FROMDESIGNER_TOOLBOX_SPINBOX,
				:ComboBox = T_FROMDESIGNER_TOOLBOX_COMBOBOX,
				:DateTimeEdit = T_FROMDESIGNER_TOOLBOX_DATETIMEEDIT,
				:TableWidget = T_FROMDESIGNER_TOOLBOX_TABLEWIDGET,
				:TreeWidget = T_FROMDESIGNER_TOOLBOX_TREEWIDGET,
				:RadioButton = T_FROMDESIGNER_TOOLBOX_RADIOBUTTON,
				:WebView = T_FROMDESIGNER_TOOLBOX_WEBVIEW,
				:DialSlider = T_FROMDESIGNER_TOOLBOX_DIALSLIDER,
				:VideoWidget = T_FROMDESIGNER_TOOLBOX_VIDEOWIDGET,
				:Frame = T_FROMDESIGNER_TOOLBOX_FRAME,
				:LCDNumber = T_FROMDESIGNER_TOOLBOX_LCDNUMBER,
				:HyperLink = T_FROMDESIGNER_TOOLBOX_HYPERLINK,
				:Timer = T_FROMDESIGNER_TOOLBOX_TIMER,
				:AllEvents = T_FROMDESIGNER_TOOLBOX_ALLEVENTS,
				:Layout = T_FROMDESIGNER_TOOLBOX_LAYOUT,
				:TabWidget = T_FROMDESIGNER_TOOLBOX_TABWIDGET,
				:StatusBar = T_FROMDESIGNER_TOOLBOX_STATUSBAR,
				:ToolBar = T_FROMDESIGNER_TOOLBOX_TOOLBAR	
			]
		else 
			aToolBoxTextList = [
				:Lock = this.TextSize(T_FROMDESIGNER_TOOLBOX_LOCK,20) ,
				:Select = this.TextSize(T_FROMDESIGNER_TOOLBOX_SELECT,20),
				:Label = this.TextSize(T_FROMDESIGNER_TOOLBOX_LABEL,20),
				:Button = this.TextSize(T_FROMDESIGNER_TOOLBOX_BUTTON,18),
				:LineEdit = this.TextSize(T_FROMDESIGNER_TOOLBOX_LINEEDIT,19),
				:TextEdit = this.TextSize(T_FROMDESIGNER_TOOLBOX_TEXTEDIT,19),
				:ListWidget = this.TextSize(T_FROMDESIGNER_TOOLBOX_LISTWIDGET,17),
				:CheckBox = this.TextSize(T_FROMDESIGNER_TOOLBOX_CHECKBOX,16),
				:Image = this.TextSize(T_FROMDESIGNER_TOOLBOX_IMAGE,19),
				:Slider = this.TextSize(T_FROMDESIGNER_TOOLBOX_SLIDER,20),
				:ProgressBar = this.TextSize(T_FROMDESIGNER_TOOLBOX_PROGRESSBAR,15),
				:SpinBox = this.TextSize(T_FROMDESIGNER_TOOLBOX_SPINBOX,17),
				:ComboBox = this.TextSize(T_FROMDESIGNER_TOOLBOX_COMBOBOX,17),
				:DateTimeEdit = this.TextSize(T_FROMDESIGNER_TOOLBOX_DATETIMEEDIT,17),
				:TableWidget = this.TextSize(T_FROMDESIGNER_TOOLBOX_TABLEWIDGET,17),
				:TreeWidget = this.TextSize(T_FROMDESIGNER_TOOLBOX_TREEWIDGET,17),
				:RadioButton = this.TextSize(T_FROMDESIGNER_TOOLBOX_RADIOBUTTON,17),
				:WebView = this.TextSize(T_FROMDESIGNER_TOOLBOX_WEBVIEW,17),
				:DialSlider = this.TextSize(T_FROMDESIGNER_TOOLBOX_DIALSLIDER,20),
				:VideoWidget = this.TextSize(T_FROMDESIGNER_TOOLBOX_VIDEOWIDGET,17),
				:Frame = this.TextSize(T_FROMDESIGNER_TOOLBOX_FRAME,20),
				:LCDNumber = this.TextSize(T_FROMDESIGNER_TOOLBOX_LCDNUMBER,17),
				:HyperLink = this.TextSize(T_FROMDESIGNER_TOOLBOX_HYPERLINK,20),
				:Timer = this.TextSize(T_FROMDESIGNER_TOOLBOX_TIMER,22),
				:AllEvents = this.TextSize(T_FROMDESIGNER_TOOLBOX_ALLEVENTS,20),
				:Layout = this.TextSize(T_FROMDESIGNER_TOOLBOX_LAYOUT,20),
				:TabWidget = this.TextSize(T_FROMDESIGNER_TOOLBOX_TABWIDGET,18),
				:StatusBar = this.TextSize(T_FROMDESIGNER_TOOLBOX_STATUSBAR,20),
				:ToolBar = this.TextSize(T_FROMDESIGNER_TOOLBOX_TOOLBAR,20)		
			]
		}

		oToolBox = new qWidget() {
			setLayoutDirection(0)
 			this.oToolLock = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:Lock]) # "Lock"
					this.setToolbtnImage(self,AppFile("image/lock.png"))
					setCheckable(True)
					setChecked(false)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn1 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:Select]) # "Select"
					this.setToolbtnImage(self,AppFile("image/select.png"))
					setminimumwidth(150)
					setCheckable(True)
					setChecked(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn2 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:Label]) # "Label"
					this.setToolbtnImage(self,AppFile("image/label.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn3 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:Button]) # "Button"
					this.setToolbtnImage(self,AppFile("image/pushbutton.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn4 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:LineEdit]) # "LineEdit"
					this.setToolbtnImage(self,AppFile("image/textfield.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn5 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:TextEdit]) # "TextEdit"
					this.setToolbtnImage(self,AppFile("image/textarea.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn6 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:ListWidget]) # "ListWidget"
					this.setToolbtnImage(self,AppFile("image/listview.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn7 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:CheckBox]) # "Checkbox"
					this.setToolbtnImage(self,AppFile("image/checkbox.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn8 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:Image]) # "Image"
					this.setToolbtnImage(self,AppFile("image/image.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn9 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:Slider]) # "Slider"
					this.setToolbtnImage(self,AppFile("image/slider.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn10 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:ProgressBar]) # "Progressbar"
					this.setToolbtnImage(self,AppFile("image/progressbar.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn11 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:SpinBox]) # "SpinBox"
					this.setToolbtnImage(self,AppFile("image/spinner.bmp"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn12 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:ComboBox]) # "ComboBox"
					this.setToolbtnImage(self,AppFile("image/combobox.bmp"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn13 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:DateTimeEdit]) # "DateTimeEdit"
					this.setToolbtnImage(self,AppFile("image/datepicker.bmp"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn14 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:TableWidget]) # "TableWidget"
					this.setToolbtnImage(self,AppFile("image/grid.bmp"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn15 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:TreeWidget]) # "TreeWidget"
					this.setToolbtnImage(self,AppFile("image/tree.bmp"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn16 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:RadioButton]) # "RadioButton"
					this.setToolbtnImage(self,AppFile("image/radiobutton.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn17 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:WebView]) # "WebView"
					this.setToolbtnImage(self,AppFile("image/webview.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn18 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:DialSlider]) # "Dial Slider"
					this.setToolbtnImage(self,AppFile("image/dial.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn19 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:VideoWidget]) # "Video Widget"
					this.setToolbtnImage(self,AppFile("image/videowidget.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn20 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:Frame]) # "Frame"
					this.setToolbtnImage(self,AppFile("image/frame.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn21 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:LCDNumber]) # "LCD Number"
					this.setToolbtnImage(self,AppFile("image/lcdnumber.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn22 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:HyperLink]) # "HyperLink"
					this.setToolbtnImage(self,AppFile("image/hyperlink.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn23 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:Timer]) # "Timer"
					this.setToolbtnImage(self,AppFile("image/timer.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn24 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:AllEvents]) # "All Events"
					this.setToolbtnImage(self,AppFile("image/allevents.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn25 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:Layout]) # "Layout"
					this.setToolbtnImage(self,AppFile("image/layout.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn26 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:TabWidget]) # "Tab Widget"
					this.setToolbtnImage(self,AppFile("image/tab.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn27 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:StatusBar]) # "Statusbar"
					this.setToolbtnImage(self,AppFile("image/statusbar.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn28 = new qPushButton(oToolBox) {
					setText(aToolBoxTextList[:ToolBar]) # "Toolbar"
					this.setToolbtnImage(self,AppFile("image/toolbar.png"))
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}

			Layout1 = new qVBoxLayout() {
				AddWidget(this.oToolLock)
				AddWidget(this.oToolbtn1)
				AddWidget(this.oToolbtn2)
				AddWidget(this.oToolbtn3)
				AddWidget(this.oToolbtn4)
				AddWidget(this.oToolbtn5)
				AddWidget(this.oToolbtn6)
				AddWidget(this.oToolbtn7)
				AddWidget(this.oToolbtn8)
				AddWidget(this.oToolbtn9)
				AddWidget(this.oToolbtn10)
				AddWidget(this.oToolbtn11)
				AddWidget(this.oToolbtn12)
				AddWidget(this.oToolbtn13)
				AddWidget(this.oToolbtn14)
				AddWidget(this.oToolbtn15)
				AddWidget(this.oToolbtn16)
				AddWidget(this.oToolbtn17)
				AddWidget(this.oToolbtn18)
				AddWidget(this.oToolbtn19)
				AddWidget(this.oToolbtn20)
				AddWidget(this.oToolbtn21)
				AddWidget(this.oToolbtn22)
				AddWidget(this.oToolbtn23)
				AddWidget(this.oToolbtn24)
				AddWidget(this.oToolbtn25)
				AddWidget(this.oToolbtn26)
				AddWidget(this.oToolbtn27)
				AddWidget(this.oToolbtn28)
				insertStretch( -1, 1 )
			}
			btnsGroup = new qButtonGroup(oToolBox) {
				setbuttonClickedEvent(Method(:ToolBtnChangeAction))
				AddButton(this.oToolbtn1,0)
				AddButton(this.oToolbtn2,1)
				AddButton(this.oToolbtn3,2)
				AddButton(this.oToolbtn4,3)
				AddButton(this.oToolbtn5,4)
				AddButton(this.oToolbtn6,5)
				AddButton(this.oToolbtn7,6)
				AddButton(this.oToolbtn8,7)
				AddButton(this.oToolbtn9,8)
				AddButton(this.oToolbtn10,9)
				AddButton(this.oToolbtn11,10)
				AddButton(this.oToolbtn12,11)
				AddButton(this.oToolbtn13,12)
				AddButton(this.oToolbtn14,13)
				AddButton(this.oToolbtn15,14)
				AddButton(this.oToolbtn16,15)
				AddButton(this.oToolbtn17,16)
				AddButton(this.oToolbtn18,17)
				AddButton(this.oToolbtn19,18)
				AddButton(this.oToolbtn20,19)
				AddButton(this.oToolbtn21,20)
				AddButton(this.oToolbtn22,21)
				AddButton(this.oToolbtn23,22)
				AddButton(this.oToolbtn24,23)
				AddButton(this.oToolbtn25,24)
				AddButton(this.oToolbtn26,25)
				AddButton(this.oToolbtn27,26)
				AddButton(this.oToolbtn28,27)
			}
			setLayout(Layout1)
		}
		oScroll = new qScrollArea(null) {
			setWidget(oToolBox)
			setMiniMumWidth(195)
		}
		oToolBoxDock = new qdockwidget(NULL,0) {
			setLayoutDirection(0)
			setWindowTitle(T_FROMDESIGNER_TOOLBOX_WINDOWTITLE) # "ToolBox"
			setWidget(oScroll)
		}
		if T_LAYOUTDIRECTION {
			win.Adddockwidget(2,oToolBoxDock,2)
		else 
			win.Adddockwidget(1,oToolBoxDock,1)
		}

	func setToolbtnImage oObject,cImage
		//if not T_LAYOUTDIRECTION {
			setbtnImage(oObject,cImage)
		//}

	func TextSize cText,nSize
		nSpaces = (nSize - len(cText))/2
		return copy(" ",nSpaces)+cText+Copy(" ",nSpaces)

	func CreateProperties
		oProperties = new qWidget() {
			setLayoutDirection(T_LAYOUTDIRECTION)
			oLabelObject = new qLabel(this.oProperties) {
				setText(T_FROMDESIGNER_PROPERTIES_OBJECT) # "Object"
				setMaximumWidth(50)
			}
			this.oObjectsCombo = new qCombobox(this.oProperties) {
				setcurrentIndexChangedEvent(Method(:ChangeObjectAction))
			}
			oLayout1 = new qHBoxlayout() {
				AddWidget(oLabelObject)
				AddWidget(this.oObjectsCombo)
			}
			this.oPropertiesTable = new qTableWidget(this.oProperties) {
				setrowcount(0)
				setcolumncount(3)
				setselectionbehavior(QAbstractItemView_SelectRows)
				setHorizontalHeaderItem(0, new QTableWidgetItem(T_FROMDESIGNER_PROPERTIES_PROPERTY)) # "Property"
				setHorizontalHeaderItem(1, new QTableWidgetItem(T_FROMDESIGNER_PROPERTIES_VALUE)) # "Value"
				setHorizontalHeaderItem(2,  new QTableWidgetItem(""))
				setColumnwidth(0,190)
				setColumnwidth(2,40)
				setAlternatingRowColors(true)
				setitemChangedEvent(Method(:UpdateProperties))
				if T_LAYOUTDIRECTION {
					setminimumwidth(390)
				else 
					setminimumwidth(370)
				}
			}
			oLayout2 = new qVBoxLayout() {
				AddLayout(oLayout1)
				AddWidget(this.oPropertiesTable)
			}
			setLayout(oLayout2)
		}
		oProperties2 = new qWidget() {
			setLayoutDirection(T_LAYOUTDIRECTION)
			oBtn1 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS1) # "Align - Left Sides"
				setClickEvent(Method(:MSAlignLeft))
			}
			oBtn2 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS2) # "Align - Right Sides"
				setClickEvent(Method(:MSAlignRight))
			}
			oBtn3 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS3) # "Align - Top Sides"
				setClickEvent(Method(:MSAlignTop))
			}
			oBtn4 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS4) # "Align - Bottom Sides"
				setClickEvent(Method(:MSAlignBottom))
			}
			oBtn5 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS5) # "Center Vertically"
				setClickEvent(Method(:MSCenterVer))
			}
			oBtn6 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS6) # "Center Horizontally"
				setClickEvent(Method(:MSCenterHor))
			}
			oBtn7 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS7) # "Size - To Tallest"
				setClickEvent(Method(:MSSizeToTallest))
			}
			oBtn8 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS8) # "Size - To Shortest"
				setClickEvent(Method(:MSSizeToShortest))
			}
			oBtn9 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS9) # "Size - To Widest"
				setClickEvent(Method(:MSSizeToWidest))
			}
			oBtn10 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS10) # "Size - To Narrowest"
				setClickEvent(Method(:MSSizeToNarrowest))
			}
			oBtn11 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS11) # "Horizontal Spacing - Make Equal"
				setClickEvent(Method(:MSHorSpacingMakeEqual))
			}
			oBtn12 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS12) # "Horizontal Spacing - Increase"
				setClickEvent(Method(:MSHorSpacingIncrease))
			}
			oBtn13 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS13) # "Horizontal Spacing - Decrease"
				setClickEvent(Method(:MSHorSpacingDecrease))
			}
			oBtn14 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS14) # "Vertical Spacing - Make Equal"
				setClickEvent(Method(:MSVerSpacingMakeEqual))
			}
			oBtn15 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS15) # "Vertical Spacing - Increase"
				setClickEvent(Method(:MSVerSpacingIncrease))
			}
			oBtn16 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS16) # "Vertical Spacing - Decrease"
				setClickEvent(Method(:MSVerSpacingDecrease))
			}
			oBtn17 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS17) # "Text Color"
				setClickEvent(Method(:MSTextColor))
			}
			oBtn18 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS18) # "Back Color"
				setClickEvent(Method(:MSBackColor))
			}
			oBtn19 = new qPushbutton(this.oProperties2) {
				setText(T_FROMDESIGNER_PROPERTIES_MS19) # "Font"
				setClickEvent(Method(:MSFont))
			}
			oLayout = new qVBoxLayout() {
				AddWidget(oBtn1)
				AddWidget(oBtn2)
				AddWidget(oBtn3)
				AddWidget(oBtn4)
				AddWidget(oBtn5)
				AddWidget(oBtn6)
				AddWidget(oBtn7)
				AddWidget(oBtn8)
				AddWidget(oBtn9)
				AddWidget(oBtn10)
				AddWidget(oBtn11)
				AddWidget(oBtn12)
				AddWidget(oBtn13)
				AddWidget(oBtn14)
				AddWidget(oBtn15)
				AddWidget(oBtn16)
				AddWidget(oBtn17)
				AddWidget(oBtn18)
				AddWidget(oBtn19)
				insertStretch( -1, 1 )
			}
			setLayout(oLayout)
		}
		oPropertiesDock = new qDockWidget(NULL,0) {
			setLayoutDirection(0)
			setWindowTitle(T_FROMDESIGNER_PROPERTIES_WINDOWTITLE) # "Properties"
			setWidget(this.oProperties)
		}
		if T_LAYOUTDIRECTION {
			win.Adddockwidget(1,oPropertiesDock,1)
		else 
			win.Adddockwidget(2,oPropertiesDock,2)
		}

	func AddProperty cItem,lButton
		oPropertiesTable.blocksignals(True)
		nRow = oPropertiesTable.rowcount()
		oPropertiesTable.insertrow(nRow)
		# Property Name
			item = new qTableWidgetItem(cItem)
			item.setFlags(False)	# Can't Edit the Item
			oPropertiesTable.setItem(nRow,0,item)
		# Property Value
			item = new qTableWidgetItem("")
			oPropertiesTable.setItem(nRow,1,item)
		if lButton = False {
			item = new qTableWidgetItem("")
			item.setFlags(False)	# Can't Edit the Item
			oPropertiesTable.setItem(nRow,2,item)
		else
			oBtn = new qPushButton(NULL) {
				setText("::")
				setfixedwidth(30)
				setClickEvent(this.Method(:DialogButtonAction+"("+nRow+")"))
			}
			oPropertiesTable.setCellwidget(nRow,2,oBtn)
		}
		oPropertiesTable.blocksignals(false)

	func AddPropertyCombobox cItem,aList
		oPropertiesTable.blocksignals(True)
		nRow = oPropertiesTable.rowcount()
		oPropertiesTable.insertrow(nRow)
		# Property Name
			item = new qTableWidgetItem(cItem)
			item.setFlags(False)	# Can't Edit the Item
			oPropertiesTable.setItem(nRow,0,item)
		# Combobox
			oCombo = new qCombobox(NULL) {
				for cValue in aList { AddItem(cValue,0) }
				setCurrentIndexchangedevent(this.Method(:ComboItemAction+"("+nRow+")"))
			}
			oPropertiesTable.setCellwidget(nRow,1,oCombo)
		# No Button
			item = new qTableWidgetItem("")
			item.setFlags(False)	# Can't Edit the Item
			oPropertiesTable.setItem(nRow,2,item)
		oPropertiesTable.blocksignals(false)

