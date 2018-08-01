# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteController from RNoteControllerBase 

	LoadSettings()

	CreateMainWindow()

	func pNofileopened
		New qMessageBox(win1) {
			setWindowTitle("Sorry")
			setText("Save/Select the file first!")
			show()
		}

	func pSetActiveFileName
		oDockSourceCode.setWindowTitle("Source Code : " + cActiveFileName)

	func pTextChanged
		lAskToSave = true
		pSetFont()
		pSetActiveLineColor()

	func pCursorPositionChanged
		nLine = textedit1.textcursor().blocknumber()+1
		StatusMessage(" Line : "+nLine+
					" Column : " +(textedit1.textcursor().columnnumber()+1) +
					" Total Lines : " + textedit1.document().linecount())
		pSetActiveLineColor()
		aFilesLines[cActiveFileName] = nLine


	func pRingNotepadXButton
		pSaveSettings() 

