# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteTabWidth

	func TabWidth
		oInput = New QInputDialog(win1)
		{
			setwindowtitle("Set the Tab Width")
			setgeometry(100,100,400,50)
			setlabeltext("Spaces Count")
			settextvalue("1")
			r = exec()
		}
		if r=0 return ok
		nTabSpaces = 0 + oInput.textvalue()
		SetTabSpaces()

	func SetTabSpaces
		oTFont.fromstring(cFont)
		oFontMetrics = new QFontMetrics(oTFont)
		nSpaceWidth = oFontMetrics.horizontalAdvance(" ",1)
		textedit1.setTabStopWidth(nTabSpaces*nSpaceWidth)
