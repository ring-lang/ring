# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteTabWidth

	func TabWidth
		oInput = New QInputDialog(win1)
		{
			setwindowtitle(T_RINGNOTEPAD_SETTHETABWIDTH) # "Set the Tab Width"
			setgeometry(100,100,400,50)
			setlabeltext(T_RINGNOTEPAD_SPACESCOUNT) # "Spaces Count"
			settextvalue(T_RINGNOTEPAD_DEFAULTSPACESCOUNT) # "1"
			r = exec()
		}
		if r=0 return ok
		nTabSpaces = 0 + oInput.textvalue()
		SetTabSpaces()

	func SetTabSpaces
		oTFont.fromstring(cFont)
		oFontMetrics = new QFontMetrics(oTFont)
		nSpaceWidth = oFontMetrics.horizontalAdvance(" ",1)
		textedit1.setTabStopDistance(nTabSpaces*nSpaceWidth)
