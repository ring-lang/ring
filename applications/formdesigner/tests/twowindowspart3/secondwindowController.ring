# Form/Window Controller - Source Code File

load "secondwindowView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:secondwindowController)
		exec()
	}
}

class secondwindowController from windowsControllerParent

	oView = new secondwindowView

	func CloseWindow 

		oView.win.Close()

	func setMessage cMessage

		oView.label1.setText(cMessage)

	func SendMessage 
		if isParent() {
			parent().setMessage("Message from the Second Window")
		}
