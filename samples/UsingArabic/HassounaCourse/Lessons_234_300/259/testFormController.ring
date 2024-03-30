# Form/Window Controller - Source Code File

load "testFormView.ring"
load "hassounaLib.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:testFormController)
		exec()
	}
}

class testFormController from windowsControllerParent

	oView = new testFormView
	t = new FormTools(oView.win)
	
	func my()
		t.center()
		t.win().setWindowTitle("My New Title")
		t.icon("red_ring.png")
