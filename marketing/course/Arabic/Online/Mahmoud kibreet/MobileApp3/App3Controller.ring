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

func AddNumber
	oView {
		ListNumbers.additem(txtNumber.text())
	}

Func SumNumbers
oView {
	nSum = 0
	for x = 1 to ListNumbers.count()
		nSum = nSum + ListNumbers.item(x).text()
	next 
	lblSum.settext("" + nSum)
}
