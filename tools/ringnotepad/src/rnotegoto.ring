# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteGoto

	func Goto
		oInput = New QInputDialog(win1)
		{
			setWindowTitle(T_RINGNOTEPAD_ENTERTHELINENUMBER) # "Enter the line number?"
			setGeometry(100,100,400,50)
			setLabelText(T_RINGNOTEPAD_LINE) # "Line"
			setIntValue(1) 
			setInputMode(1) # int
			setIntMaximum(1_000_000_000)
			setIntMinimum(1)
			r = exec()
		}
		if r=0 return ok
		nLine = oInput.intValue()
		gotoline(nLine)
 
	func GotoLine nLine 
		// This function support source code that contains UTF-8 characters 
		// Get the character position
			nPos = textedit1.document().findblockbylinenumber(nLine-1).position()
		// Set the current character 
			oCursor = textedit1.textcursor()
			oCursor.setposition(nPos,0)
			textedit1.settextcursor(oCursor)
