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

	nSecondWindowID=0

	func OpenSecondWindow
		openWindow(:SecondWindowController)
		nSecondWindowID = lastWindowID()
		SecondWindow().setFirstWindowID(ObjectID())

	func IsSecondWindow
		return nSecondWindowID

	func SecondWindow
		return GetObjectByID(nSecondWindowID)

	func SendMessage
		if IsSecondWindow() {
			SecondWindow().setMessage("Message from the first window")
		}

	func setMessage cMessage 
		oView.Label1.setText(cMessage)
