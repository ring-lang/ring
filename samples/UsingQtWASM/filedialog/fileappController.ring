# Form/Window Controller - Source Code File

load "fileappView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:fileappController)
		exec()
	}
}

class fileappController from windowsControllerParent

	oView = new fileappView

	oLoadDialog  oSaveDialog  

	func LoadFile 
		oLoadDialog = new QFileDialog(NULL) {
			setFileSelectedevent(Method(:LoadFileOperation))
			setWindowTitle("Open File")
			setLabelText(QFileDialog_Accept,"Open")
			setNameFilter("Text files (*.txt)")
			setDefaultSuffix("txt")
			setFileMode(QFileDialog_ExistingFile)
			setViewMode(QFileDialog_List)
			exec()
		}

	func SaveFile
		oSaveDialog = new QFileDialog(NULL) {
			setFileSelectedevent(Method(:SaveFileOperation))
			setWindowTitle("Save File")
			setLabelText(QFileDialog_Accept,"Save")
			setNameFilter("Text files (*.txt)")
			setDefaultSuffix("txt")
			setFileMode(QFileDialog_AnyFile)
			setViewMode(QFileDialog_List)
			exec()
		}

	func LoadFileOperation
		if oLoadDialog.selectedfiles().count() = 0 return ok
		cFileName = oLoadDialog.selectedfiles().at(0)
		oView.TextEdit1.setText(read(cFileName))

	func SaveFileOperation
		if oSaveDialog.selectedfiles().count() = 0 return ok
		cFileName = oSaveDialog.selectedfiles().at(0)
		write(cFileName,oView.TextEdit1.toPlainText())
