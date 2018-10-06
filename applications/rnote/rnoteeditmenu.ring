# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteEditMenu

	func Undo
		textedit1.undo()
		StatusMessage("Undo!")

	func Cut
		textedit1.cut()
		StatusMessage("Cut!")

	func CopyText
		textedit1.copy()
		StatusMessage("Copy!")

	func Paste
		textedit1.paste()
		StatusMessage("Paste!")

	func Font
		oFontDialog = new qfontdialog() {

			this.oTFont.fromstring(this.cFont)
			setcurrentfont(this.oTFont)

			aFont = getfont()
		}
		if aFont[1] != NULL
			cFont = aFont[1]
			SetFont()	# set the new font
		ok

	func SetFont
		oTFont.fromstring(cFont)
		oCursor = textedit1.textCursor()
		oCursor.clearselection()
		textedit1.settextcursor(oCursor)
		textedit1.Document().setdefaultfont(oTFont)
		if lSetProjectFilesFont 
			oTFont.setFamily("Roboto")
			oTFont.setStrikeout(False)
			oTFont.setbold(False)
			oTFont.setpointsize(max(oTFont.pointsize()-2,8))
			tree1.setfont(oTFont)
		ok

	func SelectColor
		new qcolordialog() {
			r = exec()
			if r = 0 return ok
			oColor = currentcolor()
			r = oColor.red()
			g = oColor.green()
			b = oColor.blue()
		}
		this.aTextColor = [r,g,b]
		SetColors()

	func SelectColor2
		new qcolordialog() {
			r = exec()
			if r = 0 return ok
			oColor = currentcolor()
			r = oColor.red()
			g = oColor.green()
			b = oColor.blue()
		}
		this.aBackColor = [r,g,b]
		SetColors()

	func SetColors
		this.textedit1.setstylesheet("QPlainTextEdit { color: rgb(" + aTextColor[1] + "," + aTextColor[2] +
					"," + aTextColor[3] + ");" + "background-color: rgb(" +
					aBackColor[1] + "," + aBackColor[2] + "," +
					aBackColor[3] + ") }")

