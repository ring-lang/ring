Class RNoteEditMenu

	func pUndo
		textedit1.undo()
		StatusMessage("Undo!")

	func pCut
		textedit1.cut()
		StatusMessage("Cut!")

	func pCopy
		textedit1.copy()
		StatusMessage("Copy!")

	func pPaste
		textedit1.paste()
		StatusMessage("Paste!")

	func pFont
		oFontDialog = new qfontdialog() {

			this.oTempFont.fromstring(this.cFont)
			setcurrentfont(this.oTempFont)

			aFont = getfont()
		}
		if aFont[1] != NULL
			cFont = aFont[1]
			pSetFont()	# set the new font
		ok

	func pSetFont
		oTempFont.fromstring(cFont)
		oCursor = textedit1.textCursor()
		oCursor.clearselection()
		textedit1.settextcursor(oCursor)
		textedit1.Document().setdefaultfont(oTempFont)

	func pColor
		new qcolordialog() {
			r = exec()
			if r = 0 return ok
			oColor = currentcolor()
			r = oColor.red()
			g = oColor.green()
			b = oColor.blue()
		}
		this.aTextColor = [r,g,b]
		pSetColors()

	func pColor2
		new qcolordialog() {
			r = exec()
			if r = 0 return ok
			oColor = currentcolor()
			r = oColor.red()
			g = oColor.green()
			b = oColor.blue()
		}
		this.aBackColor = [r,g,b]
		pSetColors()

	func pSetColors
		this.textedit1.setstylesheet("QPlainTextEdit { color: rgb(" + aTextColor[1] + "," + aTextColor[2] +
					"," + aTextColor[3] + ");" + "background-color: rgb(" +
					aBackColor[1] + "," + aBackColor[2] + "," +
					aBackColor[3] + ") }")

