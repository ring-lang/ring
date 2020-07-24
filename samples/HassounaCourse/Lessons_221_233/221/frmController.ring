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
	t.Center()
	showDT()

	func showDT() oView.lblDT.setText( date() + "  " + time() )


