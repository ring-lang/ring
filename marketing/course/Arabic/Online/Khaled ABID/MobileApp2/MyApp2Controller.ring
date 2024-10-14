# Form/Window Controller - Source Code File

load "MyApp2View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:MyApp2Controller)
		exec()
	}
}

class MyApp2Controller from windowsControllerParent

	oView = new MyApp2View

	func SayHi
		oView {
			lblMsg.settext("Hi " + txtName.text())
		}
