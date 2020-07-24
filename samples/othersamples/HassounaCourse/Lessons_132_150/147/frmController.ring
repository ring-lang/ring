# Form/Window Controller - Source Code File

load "frmView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView

	load "hassounaLib.ring"
	t = new FormTools(oView.win)

	func btnShowText_Click(){
		t.msgbox( oView.TextEdit1.toPlainText() )
	}

	func btnSetText_Click(){
		oView.TextEdit1.setPlainText("Hello" + nl + "Welcome")
	}
