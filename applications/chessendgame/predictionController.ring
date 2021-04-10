# Form/Window Controller - Source Code File

load "predictionView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:predictionController)
		exec()
	}
}

class predictionController from windowsControllerParent

	oView = new predictionView

	oView { 
		txtWKF.setText("a")
		txtWKR.setText("1")
		txtWRF.setText("b")
		txtWRR.setText("3")
		txtBKF.setText("c")
		txtBKR.setText("2")
		listAlgorithm.setCurrentRow(1,QItemSelectionModel_Select)
	}

	func closeWindow 
		oView.win.close()
