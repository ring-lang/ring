# Form/Window Controller - Source Code File

load "firstwindowView.ring"

load "secondwindowController.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:firstwindowController)
		exec()
	}
}

class firstwindowController from windowsControllerParent

	oView = new firstwindowView

	func OpenSecondWindow
		openWindow(:SecondWindowController)
		lastWindow().setMessage("Message from the first window")
		
