# Form/Window Controller - Source Code File

load "ringmenuView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:ringmenuController)
		exec()
	}
}

class ringmenuController from windowsControllerParent

	oView = new ringmenuView
