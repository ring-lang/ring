# Form/Window Controller - Source Code File

load "sumtwonumbersView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		openWindow(:sumtwonumbersController)
		exec()
	}
}

class sumtwonumbersController from windowsControllerParent

	oView = new sumtwonumbersView

	func SumNumbers
		oView {
			LineEdit3.setText( "" + ( 0 + LineEdit1.text() + LineEdit2.text() ) )
		}
