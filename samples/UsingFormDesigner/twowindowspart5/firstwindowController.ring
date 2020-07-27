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
		openWindowAndLink(:SecondWindowController,self)

	func SendMessage
		if isMethod(self,:IsSecondWindow) {
			if IsSecondWindow() {
				SecondWindow().setMessage("Message from the first window")
			}
		}

	func setMessage cMessage 
		oView.Label1.setText(cMessage)
