# Form/Window Controller - Source Code File

load "frmView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView
	load "hassounaLib.ring"
	t = new FormTools(oView.win)
	t.center()


	func test(){
		if IsMatch("^[A-Z][a-z]+\s[A-Z][a-z]+$",oView.txt.Text())
			oView.lbl.setStyleSheet("color:green")
			oView.lbl.setText("Correct")
		else
			oView.lbl.setStyleSheet("color:red")
			oView.lbl.setText("Incorrect")
		ok
	}





