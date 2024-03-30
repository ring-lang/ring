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

	func CheckWebAssembly
		if ! isWebAssembly()
			msginfo("Sorry","This example need WebAssembly!")
			return False
		ok
		return True

	func DownloadFile
		if ! CheckWebAssembly() return ok
		cStr 	= oView.TextEdit1.toPlainText()
		WebAssemblyDownload("output.txt",cStr)

	func UpLoadFile 
		if ! CheckWebAssembly() return ok
		WebAssemblyUpload("Text Files (*.txt)",Method(:FileLoaded))

	func FileLoaded
		oView.TextEdit1.setPlainText(
			"File : " + WebAssemblyUploadedFileName() + nl +
			"Content : " + nl + WebAssemblyUploadedFileContent()
		)


