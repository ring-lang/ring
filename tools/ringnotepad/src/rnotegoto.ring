# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteGoto

	func Goto
		oInput = New QInputDialog(win1)
		{
			setwindowtitle(T_RINGNOTEPAD_ENTERTHELINENUMBER) # "Enter the line number?"
			setgeometry(100,100,400,50)
			setlabeltext(T_RINGNOTEPAD_LINE) # "Line"
			settextvalue(T_RINGNOTEPAD_DEFAULTLINE) # "1"
			r = exec()
		}
		if r=0 return ok
		nLine = 0 + oInput.textvalue()
		gotolineUsingQTextBlock(nLine)
 
	func GotoLine nLine
		// This function is old and no longer used 
		// It's ok for ASCII characters 
		// Doesn't work fine with UTF8 
		// So we have gotolineUsingQTextBlock() function 
		nLine--
		cStr = textedit1.toPlainText()
		nSize = len(cStr)
		for t=1 to nSize
			if cStr[t] = nl nLine-- ok
			if nLine = 0
				oCursor = textedit1.textcursor()
				oCursor.setposition(t,0)
				textedit1.settextcursor(oCursor)
				exit
			ok
		next

	func GotoLineUsingQTextBlock nLine 
		// This function support source code that contains UTF8 characters 
		// Get the character position
			nPos = textedit1.document().findblockbylinenumber(nLine-1).position()
		// Set the current character 
			oCursor = textedit1.textcursor()
			oCursor.setposition(nPos,0)
			textedit1.settextcursor(oCursor)
