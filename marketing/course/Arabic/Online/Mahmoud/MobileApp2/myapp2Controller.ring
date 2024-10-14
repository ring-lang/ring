# Form/Window Controller - Source Code File

load "myapp2View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:myapp2Controller)
		exec()
	}
}

class myapp2Controller from windowsControllerParent

	oView = new myapp2View

	func SayHello

		oView {
			lblMsg.setText("Hello " + txtName.text())
		}
