# Form/Window Controller - Source Code File

load "sayhelloView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:sayhelloController)
		exec()
	}
}

class sayhelloController from windowsControllerParent

	oView = new sayhelloView

	func SayHello 
		oView {
			LineEdit2.setText("Hello "+ LineEdit1.text() )
		}
