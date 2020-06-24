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

	func LoadFile 
		oLoadDialog = new QFileDialog(NULL) 
		QFileDialog_getopenFileContent(oLoadDialog.pObject,"Text Files (*.txt)",Method(:FileLoaded))

	func SaveFile
		cStr 	= oView.TextEdit1.toPlainText()
		oBytes 	= new QByteArray()
		oBytes.append(cStr)
		if isWebAssembly()
			oSaveDialog = new QFileDialog(NULL) 
			QFileDialog_SaveFileContent(oSaveDialog.pObject,oBytes.pObject,"output.txt")
		else 
			msginfo("Sorry","This example need WebAssembly!")
		ok

func FileLoaded

	aList = QFileDialog_FileContentList()
	oView.TextEdit1.setPlainText(
		"File : " + aList[1] + nl +
		"Content : " + nl + aList[2]
	)
