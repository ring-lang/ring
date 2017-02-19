/*
**	Project : Form Designer (Under Development)
**	File Purpose :  Main File
**	Date : 2017.02.17
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "guilib.ring"
load "stdlib.ring"

cCurrentDir = CurrentDir() + "/"

new qApp {
	StyleFusion()
	Open_Window(:FormDesignerController)
	exec()
}

Class FormDesignerController from WindowsControllerParent

	oView = new FormDesignerView
	oModel = new FormDesignerModel

	func Start
		oView.win.Show()
		oModel.AddObject("Window",oView.win,"qwidget")
		AddObjectsToCombo()
		AddObjectProperties()

	func AddObjectsToCombo
		for item in oModel.GetObjects() {
			oView.oObjectsCombo.AddItem(item[1],0)
		}

	func AddObjectProperties
		aProperties = ["X","Y","Width","Height","Title","Text Color","Back Color","Font"]
		for Item in aProperties {
			oView.AddProperty(Item)
		}

	func UpdateProperties
		nRow = oView.oPropertiesTable.Currentrow()
		nCol = oView.oPropertiesTable.Currentcolumn() 
		if nRow = 4 and nCol = 1 {	# Title 
			oView.oForm.setWindowTitle(oView.oPropertiesTable.item(nRow,nCol).text())
		}

	func NewAction

	func OpenAction

	func SaveAction

	func SaveAsAction

	func ExitAction
		Super.CloseAction()

Class FormDesignerView from WindowsViewParent

	# Create the form 
		oForm = new qWidget() {
			setWindowTitle("Form1")
		}
	# Add the form to the Sub Window
		oSub =  new QMdiSubWindow(null) {
			move(100,100)
			resize(400,400)
			setwidget(oForm)
		}
	# Add the sub Window to the Mdi Area
		oArea = new qMdiArea(null) {
			addSubWindow(oSub,0)
		}
	# Create the Main Window and use the Mdi Area
		win = new qMainwindow() {
			setWindowTitle("Form Designer")		
			setcentralWidget(oArea)
			showmaximized()
		}	
		setwinicon(win,cCurrentDir + "/image/project.png")
	# Create the ToolBox
		CreateToolBox()

	# Create Properties Window
		oObjectsCombo
		oPropertiesTable
		CreateProperties()

	# Create the Menubar
		CreateMenuBar()

	# Create the Toolbar 
		CreateToolBar()

	# Create the Statusbar 
		CreateStatusBar()

	func CreateMenuBar
		menu1 = new qmenubar(win) {		
			subFile = addmenu("File")
			subFile { 
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+n"))
					setbtnimage(self,"image/new.png")
					settext("New")
					setclickevent(Method(:NewAction))
				}
				addaction(oAction)
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+o"))
					setbtnimage(self,"image/open.png") 
					settext("Open")
					setclickevent(Method(:OpenAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+s"))
					setbtnimage(self,"image/save.png")
					settext("Save")
					setclickevent(Method(:SaveAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+e"))
					setbtnimage(self,"image/saveas.png")
					settext("Save As")
					setclickevent(Method(:SaveAsAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qaction(this.win) {
					setShortcut(new QKeySequence("Ctrl+q"))
					setbtnimage(self,"image/close.png") 
					settext("Exit")
					setstatustip("Exit")
					setclickevent(Method(:ExitAction))
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
	  		for x in aBtns addwidget(x) addseparator() next
		}

	func CreateToolBox
		oToolBox = new qWidget() {
 			btn1 = new qPushButton(oToolBox) {
					setText(this.TextSize("Select",20))
					setbtnimage(self,"image/select.png") 
					setminimumwidth(150)
					setCheckable(True)
					setChecked(True)
			}
 			btn2 = new qPushButton(oToolBox) {
					setText(this.TextSize("Label",20))
					setbtnimage(self,"image/label.png") 
					setCheckable(True)
			}
 			btn3 = new qPushButton(oToolBox) {
					setText(this.TextSize("Button",18))
					setbtnimage(self,"image/pushbutton.png") 
					setCheckable(True)
			}
 			btn4 = new qPushButton(oToolBox) {
					setText(this.TextSize("LineEdit",19))
					setbtnimage(self,"image/textfield.png") 
					setCheckable(True)
			}
 			btn5 = new qPushButton(oToolBox) {
					setText(this.TextSize("TextEdit",19))
					setbtnimage(self,"image/textarea.png") 
					setCheckable(True)
			}
 			btn6 = new qPushButton(oToolBox) {
					setText(this.TextSize("ListWidget",17))
					setbtnimage(self,"image/listview.png") 
					setCheckable(True)
			}
 			btn7 = new qPushButton(oToolBox) {
					setText(this.TextSize("Checkbox",16))
					setbtnimage(self,"image/checkbox.png") 
					setCheckable(True)
			}
 			btn8 = new qPushButton(oToolBox) {
					setText(this.TextSize("Image",19))
					setbtnimage(self,"image/image.png") 
					setCheckable(True)
			}
 			btn9 = new qPushButton(oToolBox) {
					setText(this.TextSize("Slider",20))
					setbtnimage(self,"image/slider.png") 
					setCheckable(True)
			}
 			btn10 = new qPushButton(oToolBox) {
					setText(this.TextSize("Progressbar",15))
					setbtnimage(self,"image/progressbar.png") 
					setCheckable(True)
			}
			Layout1 = new qVBoxLayout() {
				AddWidget(btn1)
				AddWidget(btn2)
				AddWidget(btn3)
				AddWidget(btn4)
				AddWidget(btn5)
				AddWidget(btn6)
				AddWidget(btn7)
				AddWidget(btn8)
				AddWidget(btn9)
				AddWidget(btn10)
				insertStretch( -1, 1 )
			}
			btnsGroup = new qButtonGroup(oToolBox) {
				AddButton(btn1,0)
				AddButton(btn2,1)
				AddButton(btn3,2)
				AddButton(btn4,3)
				AddButton(btn5,4)
				AddButton(btn6,5)
				AddButton(btn7,6)
				AddButton(btn8,7)
				AddButton(btn9,8)
				AddButton(btn10,9)
			}
			setLayout(Layout1)
		}
		oToolBoxDock = new qdockwidget(NULL,0) {
			setWindowTitle("ToolBox")
			setWidget(oToolBox)
		}
		win.Adddockwidget(1,oToolBoxDock,1)

	func TextSize cText,nSize
		nSpaces = (nSize - len(cText))/2
		return copy(" ",nSpaces)+cText+Copy(" ",nSpaces)

	func CreateProperties
		oProperties = new qWidget() {
			oLabelObject = new qLabel(oProperties) {
				setText("Object")
				setMaximumWidth(50)
			}
			this.oObjectsCombo = new qCombobox(oProperties) {
			}
			oLayout1 = new qHBoxlayout() {
				AddWidget(oLabelObject)
				AddWidget(this.oObjectsCombo)
			}
			this.oPropertiesTable = new qTableWidget(oProperties) {				
				setrowcount(0)
				setcolumncount(2)
				setselectionbehavior(QAbstractItemView_SelectRows)
				setHorizontalHeaderItem(0, new QTableWidgetItem("Property"))
				setHorizontalHeaderItem(1, new QTableWidgetItem("Value"))
				setAlternatingRowColors(true)
				horizontalHeader().setStyleSheet("color: blue")
				verticalHeader().setStyleSheet("color: red")
				setitemChangedEvent(Method(:UpdateProperties))
			}
			oLayout2 = new qVBoxLayout() {
				AddLayout(oLayout1)
				AddWidget(this.oPropertiesTable)
			}
			setLayout(oLayout2)
		}
		oPropertiesDock = new qDockWidget(NULL,0) {
			setWindowTitle("Properties")
			setWidget(oProperties)
		}
		win.Adddockwidget(2,oPropertiesDock,2)

	func AddProperty cItem
		oPropertiesTable.blocksignals(True)
		nRow = oPropertiesTable.rowcount()
		oPropertiesTable.insertrow(nRow)
		item = new qTableWidgetItem(cItem)
		item.setFlags(False)	# Can't Edit the Item
		oPropertiesTable.setItem(nRow,0,item)
		item = new qTableWidgetItem("")
		oPropertiesTable.setItem(nRow,1,item)
		oPropertiesTable.blocksignals(false)

Class FormDesignerModel

	aObjectsList = []

	func AddObject cName,oObject,cType
		aObjectsList + [cName,oObject,cType]

	func GetObjects
		return aObjectsList
