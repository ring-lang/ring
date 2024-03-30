# Form/Window Controller - Source Code File

load "tabsView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:tabsController)
		exec()
	}
}

class tabsController from windowsControllerParent

	oView = new tabsView

	oView.tab1.settabsclosable(True)
	oView.tab1.settabcloserequestedevent(Method(:CloseTab))

	func CloseTab
		aPara  = oView.tab1.geteventparameters()
		nIndex = aPara[1]
		oView.tab1.removetab(nIndex)
