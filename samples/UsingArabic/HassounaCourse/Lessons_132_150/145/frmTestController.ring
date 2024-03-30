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
	T = new FormTools(oView.win)

	func btn_click(){
		T.msgBox("Hello World")
	}

	func btn2_click(){
		T.msgBox("Hello " + T.inputBox("Enter Your Name:"))
	}

	func btn3_click(){
		#frm2 = T.showNewForm()
		frm2 = T.GetNewForm()

		t2 = new FormTools(frm2)
		t2.winnormal()
	}
