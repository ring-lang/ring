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
	//oView.LineEdit1.setEchoMode(0) #Normal
	//oView.LineEdit1.setEchoMode(1) #No Echo
	//oView.LineEdit1.setEchoMode(2) #Password
	oView.LineEdit1.setEchoMode(3) #Password Echo On Edit
