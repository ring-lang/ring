# Form/Window Controller - Source Code File

load "form2View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:form2Controller)
		exec()
	}
}

class form2Controller from windowsControllerParent

	oView = new form2View

	func my()
		oView.Dial1.resize(100,100)
