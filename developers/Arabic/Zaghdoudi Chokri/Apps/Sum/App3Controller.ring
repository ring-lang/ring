# Form/Window Controller - Source Code File

load "App3View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:App3Controller)
		exec()
	}
}

class App3Controller from windowsControllerParent

	oView = new App3View

	func AddNbr
		oview{
			ListNbr.AddItem(txtNbr.text())
		}
	func SumNbr
		oView{
			nTotal = 0
			for x = 1 to ListNbr.count()
				nTotal += ListNbr.Item(x).text()
			next
			lblTotale.settext(""+nTotal)
		}
