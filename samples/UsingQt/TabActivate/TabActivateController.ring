# Form/Window Controller - Source Code File

load "TabActivateView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:TabActivateController)
		exec()
	}
}

class TabActivateController from windowsControllerParent

	oView = new TabActivateView

	pageChanged()

	oView.tab1.setCurrentChangedEvent(Method(:PageChanged))

	func pageChanged
		switch oView.tab1.currentIndex()
			on 0
				oView.lineedit1.setText("Page (1) - Time: " + Time())
			on 1
				oView.lineedit2.setText("Page (2) - Time: " + Time())
			on 2
				oView.lineedit3.setText("Page (3) - Time: " + Time())
		off
