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

	nFirstWindowID=0 

	func CloseWindow 
		oView.win.Close()

	func SetFirstWindowID nID
		nFirstWindowID = nID
	
	func FirstWindow 
		return GetObjectByID(nFirstWindowID)

	func IsFirstWindow
		return nFirstWindowID

	func setMessage cMessage
		oView.label1.setText(cMessage)

	func SendMessage 
		if isFirstWindow() {
			FirstWindow().setMessage("Message from the Second Window")
		}
