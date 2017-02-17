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
