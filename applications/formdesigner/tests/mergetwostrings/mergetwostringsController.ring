# Form/Window Controller - Source Code File

load "mergetwostringsView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:mergetwostringsController)
		exec()
	}
}

class mergetwostringsController from windowsControllerParent

	oView = new mergetwostringsView

	func MergeStrings
		oView {
			lineedit3.settext( lineedit1.text() + lineedit2.text() )
		}
