# Form/Window Controller - Source Code File

load "testView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:testController)
		exec()
	}
}

class testController from windowsControllerParent

	oView = new testView
