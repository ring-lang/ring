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
		Open_WindowAndLink(:SecondWindowController,self)

	func SendMessage
		if isMethod(self,:IsSecondWindow) {
			if IsSecondWindow() {
				SecondWindow().setMessage("Message from the first window")
			}
		}

	func setMessage cMessage 
		oView.Label1.setText(cMessage)
