# Form/Window Controller - Source Code File

load "frmView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:frmController)
		exec()
	}
}

class frmController from windowsControllerParent

	oView = new frmView
	load "hassounaLib.ring"
	myWin = new formTools( oView.win )

	func myShow()
		myWin.winNormal()

	func max()
		myWin.winmax()

	func min()
		mywin.winmin()

	func full()
		mywin.winfull()

	func center()
		mywin.center()
