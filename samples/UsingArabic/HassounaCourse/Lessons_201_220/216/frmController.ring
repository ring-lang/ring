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
	oView.tab1.SetCurrentChangedEvent(method(:changeTab))

	func go() oView.tab1{ setCurrentIndex( currentIndex()+1 ) }

	func back() oView.tab1{ setCurrentIndex( currentIndex()-1 ) }

	func changeTab() msgInfo(" ", "Page " + (oView.tab1.currentIndex()+1) )

