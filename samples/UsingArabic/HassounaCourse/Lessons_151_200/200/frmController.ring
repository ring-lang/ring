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
	oView.Toolbar1.setOrientation(2)
	#oView.Toolbar3.setOrientation(2)
	#oView.Toolbar5.setOrientation(2)
