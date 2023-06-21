# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteEditorEvents

	func TextChanged
		lAskToSave = true
		SetFont()
		SetActiveLineColor()

	func CursorPositionChanged
		lEditorHasFocus = textedit1.hasfocus()
		nLine = textedit1.textcursor().blocknumber()+1
		StatusMessage(T_RINGNOTEPAD_CURSORLINE+nLine+
					T_RINGNOTEPAD_CURSORCOLUMN +(textedit1.textcursor().columnnumber()+1) +
					T_RINGNOTEPAD_CURSORTOTALLINES + textedit1.document().linecount())
		SetActiveLineColor()
		if cActiveFileName != NULL
			aFilesLines[cActiveFileName] = nLine
		ok
		if lEditorHasFocus
			textedit1.setfocus(0)
		ok
