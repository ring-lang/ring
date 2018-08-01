# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Class RNoteActiveFile

	func pNofileopened
		New qMessageBox(win1) {
			setWindowTitle("Sorry")
			setText("Save/Select the file first!")
			show()
		}

	func pSetActiveFileName
		oDockSourceCode.setWindowTitle("Source Code : " + cActiveFileName)
