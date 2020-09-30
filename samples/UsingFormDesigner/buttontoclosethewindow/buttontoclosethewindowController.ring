# Form/Window Controller - Source Code File

load "buttontoclosethewindowView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:buttontoclosethewindowController)
		exec()
	}
}

class buttontoclosethewindowController from windowsControllerParent

	oView = new buttontoclosethewindowView

	func CloseWindow
		oView.win.close()
