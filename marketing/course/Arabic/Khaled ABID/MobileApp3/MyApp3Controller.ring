# Form/Window Controller - Source Code File

load "MyApp3View.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:MyApp3Controller)
		exec()
	}
}

class MyApp3Controller from windowsControllerParent

	oView = new MyApp3View

	func AddNumber
		oView {
			ListNumbers.AddItem(txtNumber.text())	
		}

	func SumNumbers
		oView {
			nSum = 0
			for x=1 to ListNumbers.Count()
				nSum = nSum + ListNumbers.Item(x).text()
			next
			lblSum.setText(""+nSum)
		}
