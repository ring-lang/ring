# Form/Window Controller - Source Code File

load "fileappView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:fileappController)
		exec()
	}
}

class fileappController from windowsControllerParent

	oView = new fileappView

	oDialog = new QFileDialog(oView.win) {
		setFileSelectedevent(Method(:FileSelected))
	}
	AddAttribute(oDialog,:Type)

	func LoadFile 
		oDialog { 
			Type = :Load
			setWindowTitle("Open File")
			setLabelText(QFileDialog_Accept,"Open")
			Show()
		}

	func SaveFile
		oDialog { 
			Type = :Save
			setWindowTitle("Save File")
			setLabelText(QFileDialog_Accept,"Save")
			Show()
		}

	func FileSelected 
		cFileName = oDialog.selectedfiles().at(0)
		switch oDialog.Type
			on :Load
				oView.TextEdit1.setText(read(cFileName))
			on :Save
				write(cFileName,oView.TextEdit1.toPlainText())
		off

