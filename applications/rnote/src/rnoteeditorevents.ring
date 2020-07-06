# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteEditorEvents

	func TextChanged
		lAskToSave = true
		SetFont()
		SetActiveLineColor()

	func CursorPositionChanged
		nLine = textedit1.textcursor().blocknumber()+1
		StatusMessage(" Line : "+nLine+
					" Column : " +(textedit1.textcursor().columnnumber()+1) +
					" Total Lines : " + textedit1.document().linecount())
		SetActiveLineColor()
		if cActiveFileName != NULL
			aFilesLines[cActiveFileName] = nLine
		ok
