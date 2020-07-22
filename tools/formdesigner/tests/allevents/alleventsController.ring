# Form/Window Controller - Source Code File

load "alleventsView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:alleventsController)
		exec()
	}
}

class alleventsController from windowsControllerParent

	oView = new alleventsView

	func ClickOnWindow 
		oView.win.setwindowtitle("Click Event!")
