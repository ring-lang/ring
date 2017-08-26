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
					setWindowTitle("Form1")
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
				move(100,100)
				resize(400,400)
				setwidget(oModel.FormObject())
				oModel.ActiveObject().setSubWindow(this.oSub)
				setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint )
			}

		# Add the sub Window to the Mdi Area
			oArea = new qMdiArea(null) {
				addSubWindow(this.oSub,0)
				setHorizontalScrollBarPolicy(Qt_ScrollBarAlwaysOn)
				setVerticalScrollbarpolicy(Qt_ScrollBarAlwaysOn)
			}

		# Create the Main Window and use the Mdi Area
			win = new qMainwindow() {
				setWindowTitle("Form Designer")
				setcentralWidget(this.oArea)
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
			subFile = addmenu("File")
			subFile {
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+n"))
					setbtnimage(self,"image/new.png")
					settext("New")
					setclickevent(Method(:NewAction))
				}
				addaction(oAction)
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+o"))
					setbtnimage(self,"image/open.png")
					settext("Open")
					setclickevent(Method(:OpenAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+s"))
					setbtnimage(self,"image/save.png")
					settext("Save")
					setclickevent(Method(:SaveAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+e"))
					setbtnimage(self,"image/saveas.png")
					settext("Save As")
					setclickevent(Method(:SaveAsAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qaction(this.win) {
					settext("Close")
					setstatustip("Close File")
					setclickevent(Method(:CloseAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qaction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+q"))
					setbtnimage(self,"image/close.png")
					settext("Exit")
					setstatustip("Exit")
					setclickevent(Method(:ExitAction))
				}
				addaction(oAction)
			}
			subEdit = addmenu("Edit")
			subEdit {
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+v"))
					settext("Duplicate")
					setclickevent(Method(:Duplicate))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+f"))
					settext("Bring to front")
					setclickevent(Method(:BringToFront))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+b"))
					settext("Send to back")
					setclickevent(Method(:SendToBack))
				}
				addaction(oAction)
			}
			subView = addmenu("View")
			subView {
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+t"))
					settext("ToolBox")
					setclickevent(Method(:ToolBox))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+shift+p"))
					setclickevent(Method(:Properties))
					settext("Properties")
				}
				addaction(oAction)
				addseparator()
			}
			subHelp = addmenu("Help")
			subHelp {
				subHelpLF = addmenu("Language Reference")
				subHelpLF {
					oAction = new qAction(this.win) {
						settext("CHM File")
						setclickevent(Method(:OpenCHMAction))
					}
					addaction(oAction)
					oAction = new qAction(this.win) {
						settext("PDF File")
						setclickevent(Method(:OpenPDFAction))
					}
					addaction(oAction)
				}
				addseparator()
				subHelpTools = addmenu("Development Tools")
				subHelpTools {
					oAction = new qAction(this.win) {
						settext("Programming Language")
						setclickevent(Method(:LangAction))
					}
					addaction(oAction)
					oAction = new qAction(this.win) {
						settext("GUI Library")
						setclickevent(Method(:GUIAction))
					}
					addaction(oAction)
				}
				addseparator()
				oAction = new qAction(this.win) {
					settext("About")
					setclickevent(Method(:AboutAction))
				}
				addaction(oAction)
			}
		}
		win.setmenubar(menu1)

	func CreateStatusBar
		status1 = new qstatusbar(win) {
			showmessage("Ready!",0)
		}
		win.setstatusbar(status1)

	func CreateToolBar
		aBtns = [
				new qpushbutton(win) {
					setbtnimage(self,"image/new.png")
					setclickevent(Method(:NewAction))
					settooltip("New File")
				} ,
				new qpushbutton(win) {
					setbtnimage(self,"image/open.png")
					setclickevent(Method(:OpenAction))
					settooltip("Open File")
				} ,
				new qpushbutton(win) {
					setbtnimage(self,"image/save.png")
					setclickevent(Method(:SaveAction))
					settooltip("Save")
				 } ,
				new qpushbutton(win) {
					setbtnimage(self,"image/saveas.png")
					setclickevent(Method(:SaveAsAction))
					settooltip("Save As")
				 } ,
				new qpushbutton(win) {
					setbtnimage(self,"image/close.png")
					setclickevent(Method(:ExitAction))
					settooltip("Exit")
				}
			]

		tool1 = win.addtoolbar("files")  {
	  		for x in aBtns { addwidget(x) addseparator() }
		}

	func CreateToolBox
		oToolBox = new qWidget() {
 			this.oToolLock = new qPushButton(oToolBox) {
					setText(this.TextSize("Lock",20))
					setbtnimage(self,"image/lock.png")
					setCheckable(True)
					setChecked(false)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn1 = new qPushButton(oToolBox) {
					setText(this.TextSize("Select",20))
					setbtnimage(self,"image/select.png")
					setminimumwidth(150)
					setCheckable(True)
					setChecked(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn2 = new qPushButton(oToolBox) {
					setText(this.TextSize("Label",20))
					setbtnimage(self,"image/label.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn3 = new qPushButton(oToolBox) {
					setText(this.TextSize("Button",18))
					setbtnimage(self,"image/pushbutton.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn4 = new qPushButton(oToolBox) {
					setText(this.TextSize("LineEdit",19))
					setbtnimage(self,"image/textfield.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn5 = new qPushButton(oToolBox) {
					setText(this.TextSize("TextEdit",19))
					setbtnimage(self,"image/textarea.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn6 = new qPushButton(oToolBox) {
					setText(this.TextSize("ListWidget",17))
					setbtnimage(self,"image/listview.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn7 = new qPushButton(oToolBox) {
					setText(this.TextSize("Checkbox",16))
					setbtnimage(self,"image/checkbox.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn8 = new qPushButton(oToolBox) {
					setText(this.TextSize("Image",19))
					setbtnimage(self,"image/image.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn9 = new qPushButton(oToolBox) {
					setText(this.TextSize("Slider",20))
					setbtnimage(self,"image/slider.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn10 = new qPushButton(oToolBox) {
					setText(this.TextSize("Progressbar",15))
					setbtnimage(self,"image/progressbar.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn11 = new qPushButton(oToolBox) {
					setText(this.TextSize("SpinBox",17))
					setbtnimage(self,"image/spinner.bmp")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn12 = new qPushButton(oToolBox) {
					setText(this.TextSize("ComboBox",17))
					setbtnimage(self,"image/combobox.bmp")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn13 = new qPushButton(oToolBox) {
					setText(this.TextSize("DateTimeEdit",17))
					setbtnimage(self,"image/datepicker.bmp")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn14 = new qPushButton(oToolBox) {
					setText(this.TextSize("TableWidget",17))
					setbtnimage(self,"image/grid.bmp")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn15 = new qPushButton(oToolBox) {
					setText(this.TextSize("TreeWidget",17))
					setbtnimage(self,"image/tree.bmp")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn16 = new qPushButton(oToolBox) {
					setText(this.TextSize("RadioButton",17))
					setbtnimage(self,"image/radiobutton.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn17 = new qPushButton(oToolBox) {
					setText(this.TextSize("WebView",17))
					setbtnimage(self,"image/webview.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn18 = new qPushButton(oToolBox) {
					setText(this.TextSize("Dial Slider",20))
					setbtnimage(self,"image/dial.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn19 = new qPushButton(oToolBox) {
					setText(this.TextSize("Video Widget",17))
					setbtnimage(self,"image/videowidget.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn20 = new qPushButton(oToolBox) {
					setText(this.TextSize("Frame",20))
					setbtnimage(self,"image/frame.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn21 = new qPushButton(oToolBox) {
					setText(this.TextSize("LCD Number",17))
					setbtnimage(self,"image/lcdnumber.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn22 = new qPushButton(oToolBox) {
					setText(this.TextSize("HyperLink",20))
					setbtnimage(self,"image/hyperlink.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn23 = new qPushButton(oToolBox) {
					setText(this.TextSize("Timer",22))
					setbtnimage(self,"image/timer.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn24 = new qPushButton(oToolBox) {
					setText(this.TextSize("All Events",20))
					setbtnimage(self,"image/allevents.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn25 = new qPushButton(oToolBox) {
					setText(this.TextSize("Layout",20))
					setbtnimage(self,"image/layout.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn26 = new qPushButton(oToolBox) {
					setText(this.TextSize("Tab Widget",18))
					setbtnimage(self,"image/tab.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn27 = new qPushButton(oToolBox) {
					setText(this.TextSize("Statusbar",20))
					setbtnimage(self,"image/statusbar.png")
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn28 = new qPushButton(oToolBox) {
					setText(this.TextSize("Toolbar",20))
					setbtnimage(self,"image/toolbar.png")
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
			setMiniMumWidth(185)
		}
		oToolBoxDock = new qdockwidget(NULL,0) {
			setWindowTitle("ToolBox")
			setWidget(oScroll)
		}
		win.Adddockwidget(1,oToolBoxDock,1)

	func TextSize cText,nSize
		nSpaces = (nSize - len(cText))/2
		return copy(" ",nSpaces)+cText+Copy(" ",nSpaces)

	func CreateProperties
		oProperties = new qWidget() {
			oLabelObject = new qLabel(this.oProperties) {
				setText("Object")
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
				setHorizontalHeaderItem(0, new QTableWidgetItem("Property"))
				setHorizontalHeaderItem(1, new QTableWidgetItem("Value"))
				setHorizontalHeaderItem(2,  new QTableWidgetItem(""))
				setColumnwidth(0,190)
				setColumnwidth(2,40)
				setAlternatingRowColors(true)
				setitemChangedEvent(Method(:UpdateProperties))
				setminimumwidth(370)
			}
			oLayout2 = new qVBoxLayout() {
				AddLayout(oLayout1)
				AddWidget(this.oPropertiesTable)
			}
			setLayout(oLayout2)
		}
		oProperties2 = new qWidget() {
			oBtn1 = new qPushbutton(this.oProperties2) {
				setText("Align - Left Sides")
				setClickEvent(Method(:MSAlignLeft))
			}
			oBtn2 = new qPushbutton(this.oProperties2) {
				setText("Align - Right Sides")
				setClickEvent(Method(:MSAlignRight))
			}
			oBtn3 = new qPushbutton(this.oProperties2) {
				setText("Align - Top Sides")
				setClickEvent(Method(:MSAlignTop))
			}
			oBtn4 = new qPushbutton(this.oProperties2) {
				setText("Align - Bottom Sides")
				setClickEvent(Method(:MSAlignBottom))
			}
			oBtn5 = new qPushbutton(this.oProperties2) {
				setText("Center Vertically")
				setClickEvent(Method(:MSCenterVer))
			}
			oBtn6 = new qPushbutton(this.oProperties2) {
				setText("Center Horizontally")
				setClickEvent(Method(:MSCenterHor))
			}
			oBtn7 = new qPushbutton(this.oProperties2) {
				setText("Size - To Tallest")
				setClickEvent(Method(:MSSizeToTallest))
			}
			oBtn8 = new qPushbutton(this.oProperties2) {
				setText("Size - To Shortest")
				setClickEvent(Method(:MSSizeToShortest))
			}
			oBtn9 = new qPushbutton(this.oProperties2) {
				setText("Size - To Widest")
				setClickEvent(Method(:MSSizeToWidest))
			}
			oBtn10 = new qPushbutton(this.oProperties2) {
				setText("Size - To Narrowest")
				setClickEvent(Method(:MSSizeToNarrowest))
			}
			oBtn11 = new qPushbutton(this.oProperties2) {
				setText("Horizontal Spacing - Make Equal")
				setClickEvent(Method(:MSHorSpacingMakeEqual))
			}
			oBtn12 = new qPushbutton(this.oProperties2) {
				setText("Horizontal Spacing - Increase")
				setClickEvent(Method(:MSHorSpacingIncrease))
			}
			oBtn13 = new qPushbutton(this.oProperties2) {
				setText("Horizontal Spacing - Decrease")
				setClickEvent(Method(:MSHorSpacingDecrease))
			}
			oBtn14 = new qPushbutton(this.oProperties2) {
				setText("Vertical Spacing - Make Equal")
				setClickEvent(Method(:MSVerSpacingMakeEqual))
			}
			oBtn15 = new qPushbutton(this.oProperties2) {
				setText("Vertical Spacing - Increase")
				setClickEvent(Method(:MSVerSpacingIncrease))
			}
			oBtn16 = new qPushbutton(this.oProperties2) {
				setText("Vertical Spacing - Decrease")
				setClickEvent(Method(:MSVerSpacingDecrease))
			}
			oBtn17 = new qPushbutton(this.oProperties2) {
				setText("Text Color")
				setClickEvent(Method(:MSTextColor))
			}
			oBtn18 = new qPushbutton(this.oProperties2) {
				setText("Back Color")
				setClickEvent(Method(:MSBackColor))
			}
			oBtn19 = new qPushbutton(this.oProperties2) {
				setText("Font")
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
			setWindowTitle("Properties")
			setWidget(this.oProperties)
		}
		win.Adddockwidget(2,oPropertiesDock,2)

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

