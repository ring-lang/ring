# Form/Window Controller - Source Code File

load "frmForWindowStateView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:frmForWindowStateController)
		exec()
	}
}

class frmForWindowStateController from windowsControllerParent

	oView = new frmForWindowStateView
	#oview.win.show()
	#oview.win.showmaximized()
	#oview.win.showminimized()
	#oview.win.showfullscreen()
