# Form/Window Controller - Source Code File

load "timerView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:timerController)
		exec()
	}
}

class timerController from windowsControllerParent

	oView = new timerView

	DisplayTime()

	func DisplayTime
		oView.Label1.setText("Time : " + Time())
