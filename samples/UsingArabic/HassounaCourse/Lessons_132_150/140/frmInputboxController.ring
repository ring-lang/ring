# Form/Window Controller - Source Code File

load "frmInputboxView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmInputboxController)
		exec()
	}
}

class frmInputboxController from windowsControllerParent

	oView = new frmInputboxView

	func showinput()
		mywin = oView.win
		check = false
		myInput = new InputDialog(mywin) {
			setWindowTitle("input")
			setLabeltext("Enter Name:")
			setTextValue("Ahmed")
			if exec() 
				check = true
			ok
		}
		if check oView.lblMsg.setText( myInput.textValue() ) ok
