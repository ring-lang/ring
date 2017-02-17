/*
**	Project : Form Designer (Under Development)
**	File Purpose :  Main File
**	Date : 2017.02.17
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "guilib.ring"

cCurrentDir = CurrentDir() + "/"

new qApp {
	Open_Window(:FormDesignerController)
	exec()
}

Class FormDesignerController from WindowsControllerParent
	oView = new FormDesignerView

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
		oToolBox = new qWidget() {
			
		}
		oToolBoxDock = new qdockwidget(NULL,0) {
			setWindowTitle("ToolBox")
			setWidget(oToolBox)
		}
		win.Adddockwidget(1,oToolBoxDock,1)
	# Create Properties Window
		oProperties = new qWidget() {
		}
		oPropertiesDock = new qDockWidget(NULL,0) {
			setWindowTitle("Properties")
			setWidget(oProperties)
		}
		win.Adddockwidget(2,oPropertiesDock,2)
	# Create the Menubar
		CreateMenuBar()

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
