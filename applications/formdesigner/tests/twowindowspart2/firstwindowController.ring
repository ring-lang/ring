# Form/Window Controller - Source Code File

load "firstwindowView.ring"

load "secondwindowController.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:firstwindowController)
		exec()
	}
}

class firstwindowController from windowsControllerParent

	oView = new firstwindowView

	func OpenSecondWindow
		open_window(:SecondWindowController)
		last_window().setMessage("Message from the first window")
		
