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
	oView.rdoRing.SetChecked(true)


	func btnGetSelected_Click()
	oView{
		strSelected = ""
		if  rdoCpp.IsChecked()  strSelected = "C Plus Plus"
		but rdoCs.IsChecked()   strSelected = "C Sharp"
		but rdoJava.IsChecked() strSelected = "Java"
		but rdoPy.IsChecked()   strSelected = "Python"
		but rdoRing.IsChecked() strSelected = "Ring"
		else strSelected = "Kotlin"
		ok
		this.t.MsgBox(strSelected)
	}



