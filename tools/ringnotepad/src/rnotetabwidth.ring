# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteTabWidth

	func TabWidth
		oInput = New QInputDialog(win1)
		{
			setWindowTitle(T_RINGNOTEPAD_SETTHETABWIDTH) # "Set the Tab Width"
			setGeometry(100,100,400,50)
			setLabelText(T_RINGNOTEPAD_SPACESCOUNT) # "Spaces Count"
			setIntValue(1) 
			setInputMode(1) # int
			setIntMaximum(100)
			setIntMinimum(0)
			r = exec()
		}
		if r=0 return ok
		nTabSpaces = oInput.intValue()
		SetTabSpaces()

	func SetTabSpaces
		oTFont.fromstring(cFont)
		oFontMetrics = new QFontMetrics(oTFont)
		nSpaceWidth = oFontMetrics.horizontalAdvance(" ",1)
		textedit1.setTabStopDistance(nTabSpaces*nSpaceWidth)
