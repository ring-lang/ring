# Form/Window Controller - Source Code File

load "menubarView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:menubarController)
		exec()
	}
}

class menubarController from windowsControllerParent

	oView = new menubarView

	func CloseWindow 
		oView.win.Close()

	func noAction
		? "No code to execute for this event"
