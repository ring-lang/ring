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
		regex = new qRegularExpression()
		regex.setPattern("^\d{1,20}$")
		match = regex.match(oView.txt.Text(),0,0,0)
		if match.hasMatch()
			oView.lbl.setStyleSheet("color:green")
			oView.lbl.setText("Correct")
		else
			oView.lbl.setStyleSheet("color:red")
			oView.lbl.setText("Incorrect")
		ok
	}





