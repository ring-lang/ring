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


	func btnGetSelected_Click(){
		strSelected = ""

		if oView.cbxJava.IsChecked() strSelected += "Java , " ok
		if oView.cbxCSharp.IsChecked() strSelected += "C Sharp , " ok
		if oView.cbxRing.IsChecked() strSelected += "Ring , " ok
		if oView.cbxVB.IsChecked() strSelected += "Visual Basic , " ok
		if oView.cbxPython.IsChecked() strSelected += "Python , " ok
		
		t.msgbox(strSelected)
	}


