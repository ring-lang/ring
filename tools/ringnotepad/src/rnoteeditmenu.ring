# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Author : Gal Zsolt 
# Author : Marino Esteban

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
			setFontSelectedEvent(this.Method(:FontAction))
			show()
		}

	func FontAction	
		cFont = oFontDialog.selectedfont().tostring()
		SetFont()	# set the new font

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

	func LowerCase
		UpdateSelectedText(func cData {
			return Lower(cData)
		})
	
	func UpperCase
		UpdateSelectedText(func cData {
			return Upper(cData)
		})
	
	func Capitalize
		UpdateSelectedText(func cData {
			lCap = True 
			cNewStr = ""
			for nChar = 1 to len(cData)
				if lCap 
					cNewStr += Upper(cData[nChar])
					lCap = False
				else 
					cNewStr += cData[nChar]
					if cData[nChar] = " " or cData[nChar] = Char(13) or cData[nChar] = Char(10) 
						lCap = True 
					ok
				ok
			next  
			return cNewStr
		})

	func CommentLines
		UpdateSelectedText(func cData {
			aList = str2list(cData)
			for cItem in aList
				if len(cItem) > 3
					if cItem[1] = '/' and cItem[2] = '/'
						cItem = substr(cItem, 4)
						loop
					ok
				ok
				cItem = "// " + cItem
			next
			return list2str(aList)
		})

	func CommentBlocklines
		UpdateSelectedText(func cData {
			return "/*" + nl + cData + nl + "*/" 
		})

	func UpdateSelectedText fFunction
		oCursor = textedit1.textCursor()
		nStart = oCursor.SelectionStart() + 1
		nEnd = oCursor.SelectionEnd() + 1
		cStr = textedit1.toPlainText()
		cNewStr = ""
		if nStart > 1
			cNewStr += left(cStr,nStart-1)
		ok

		cNewStr2 = substr(cStr,nStart,nEnd-nStart)
		cNewStr += call fFunction(cNewStr2)

		if nEnd < len(cStr)
			cNewStr += substr(cStr,nEnd)
		ok
		textedit1.setPlainText(cNewStr)
