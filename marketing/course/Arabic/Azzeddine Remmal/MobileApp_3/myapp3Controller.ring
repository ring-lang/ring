# Form/Window Controller - Source Code File

# Form/Window Controller - Source Code File

load "MyApp3View.ring"

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
			ListNumbers.AddItem(txtNumber.text())
		}

	func SumNumbers 
		oView {
			nSum = 0
			for x = 1 to ListNumbers.Count()
				nSum = nSum + ListNumbers.Item(x).text()
			next
			lblSum.setText(""+nSum)
		}
