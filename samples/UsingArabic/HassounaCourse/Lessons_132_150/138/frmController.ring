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

	func myShow()
		oView.win.shownormal()

	func max()
		oView.win.showmaximized()

	func min()
		oView.win.showminimized()

	func full()
		oView.win.showfullscreen()

