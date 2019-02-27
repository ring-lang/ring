# Form/Window Controller - Source Code File

load "App2View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:App2Controller)
		exec()
	}
}

class App2Controller from windowsControllerParent

	oView = new App2View

	func SayHello
		oview{
			lblMsg.setText("Salut " + txtNom.text())
		}
	func CloseApp
		oview.win.close()
