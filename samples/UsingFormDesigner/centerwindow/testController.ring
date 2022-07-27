# Form/Window Controller - Source Code File

load "testView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:testController)
		exec()
	}
}

class testController from windowsControllerParent

	oDesktop = new QDesktopWidget()
	oView = new testView
	Center_the_Window()

	func Center_the_Window
		
		oView.win {
			move((this.oDesktop.Width()-Width())/2,(this.oDesktop.Height()-Height())/2)
		}
