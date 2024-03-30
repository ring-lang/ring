# Form/Window Controller - Source Code File

load "form1View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:form1Controller)
		exec()
	}
}

class form1Controller from windowsControllerParent

	oView = new form1View
