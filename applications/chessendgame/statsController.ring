# Form/Window Controller - Source Code File

load "statsView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:statsController)
		exec()
	}
}

class statsController from windowsControllerParent

	oView = new statsView
