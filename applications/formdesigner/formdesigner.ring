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

		win = new qMainwindow() {
			setWindowTitle("Form Designer")		
			showmaximized()
		}
