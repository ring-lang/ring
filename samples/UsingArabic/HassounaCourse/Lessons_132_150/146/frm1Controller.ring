# Form/Window Controller - Source Code File

load "frm1View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frm1Controller)
		exec()
	}
}

class frm1Controller from windowsControllerParent

	oView = new frm1View

	func f2()
		load "frm2Controller.ring"
		openWindow(:frm2Controller)

	func f3()
		load "frm3Controller.ring"
		openWindow(:frm3Controller)

