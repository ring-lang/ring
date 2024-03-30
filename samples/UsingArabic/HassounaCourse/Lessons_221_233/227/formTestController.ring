# Form/Window Controller - Source Code File

load "formTestView.ring"
load "hassounaLib.ring"

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
	t = new FormTools(oView.win)
	t.center()

	func test()
		dc = new DigitalClock(oView.win)
		fL = dc.GetLargeClock()
		fl.move(100,100)

	func test2()
		dc = new DigitalClock(oView.win)
		fM = dc.GetMiddleClock()
		fm.move(200,200)

	func test3()
		dc = new DigitalClock(oView.win)
		fL = dc.GetSmallClock()
		fl.move(100,100)
