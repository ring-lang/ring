# Form/Window Controller - Source Code File

load "frmTestView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmTestController)
		exec()
	}
}

class frmTestController from windowsControllerParent

	oView = new frmTestView

	load "hassounaLib.ring"
	frmT = new FormTools(oView.win)

	func btn_click(){
		frmT.msgBox("Hello World")
	}

	func btn2_click(){
		#name = frmT.inputBox("Enter Your Name:")
		#frmT.msgBox("Hello " + name)

		frmT.msgBox("Hello " + frmT.inputBox("Enter Your Name:"))
	}


