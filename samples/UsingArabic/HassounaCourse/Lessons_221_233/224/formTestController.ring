# Form/Window Controller - Source Code File

load "formTestView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:formTestController)
		exec()
	}
}

class formTestController from windowsControllerParent

	oView = new formTestView
	load "hassounaLib.ring"
	t = new FormTools(oView.win)
	t.center()

	func test()
		dc = new DigitalClock(oView.win)
		dc.GetLargeClock()
