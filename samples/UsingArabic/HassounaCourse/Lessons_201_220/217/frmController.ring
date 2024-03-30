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

	func changeTab() #msgInfo(" ", "Page " + (oView.tab1.currentIndex()+1) )

	func getCount() msginfo(" ", " " + oView.tab1.count())

	func AddTab() oView{ tab1.AddTab(new qWidget() , txtTabName.text()) }

	func DelTab() oView{ tab1.removeTab( tab1.count()-1 ) }
