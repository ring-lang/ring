# Form/Window Controller - Source Code File

load "setlabeltextView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:setlabeltextController)
		exec()
	}
}

class setlabeltextController from windowsControllerParent

	oView = new setlabeltextView

	func one   
		oView.label1.settext("ONE")

	func two   
		oView.label1.settext("TWO")

	func three 
		oView.label1.settext("THREE")

