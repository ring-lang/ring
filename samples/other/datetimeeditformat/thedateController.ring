# Form/Window Controller - Source Code File

load "thedateView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:thedateController)
		exec()
	}
}

class thedateController from windowsControllerParent

	oView = new thedateView
	oview.dt.SetCalendarpopup(true)
	oView.dt.Setdisplayformat("dd-MM-yyyy")
