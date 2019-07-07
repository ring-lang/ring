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

	func LowerCase
		oCursor = textedit1.textCursor()
		nStart = oCursor.SelectionStart() + 1
		nEnd = oCursor.SelectionEnd() + 1
		cStr = textedit1.toPlainText()
		cNewStr = ""
		if nStart > 1
			cNewStr += left(cStr,nStart-1)
		ok
		cNewStr += lower(substr(cStr,nStart,nEnd-nStart)) 
		if nEnd < len(cStr)
			cNewStr += substr(cStr,nEnd)
		ok
		textedit1.setPlainText(cNewStr)
	
	func UpperCase
		oCursor = textedit1.textCursor()
		nStart = oCursor.SelectionStart() + 1
		nEnd = oCursor.SelectionEnd() + 1
		cStr = textedit1.toPlainText()
		cNewStr = ""
		if nStart > 1
			cNewStr += left(cStr,nStart-1)
		ok
		cNewStr += Upper(substr(cStr,nStart,nEnd-nStart)) 
		if nEnd < len(cStr)
			cNewStr += substr(cStr,nEnd)
		ok
		textedit1.setPlainText(cNewStr)
	
	func capitalize
		oCursor = textedit1.textCursor()
		nStart = oCursor.SelectionStart() + 1
		nEnd = oCursor.SelectionEnd() + 1
		cStr = textedit1.toPlainText()
		cNewStr = ""
		if nStart > 1
			cNewStr += left(cStr,nStart-1)
		ok
		lCap = True 
		for nChar = nStart to nEnd-nStart
			if lCap 
				cNewStr += Upper(cStr[nChar])
				lCap = False
			else 
				cNewStr += cStr[nChar]
				if cStr[nChar] = " " or cStr[nChar] = Char(13) or cStr[nChar] = Char(10) 
					lCap = True 
				ok
			ok
		next  
		if nEnd < len(cStr)
			cNewStr += substr(cStr,nEnd)
		ok
		textedit1.setPlainText(cNewStr)

	func commentlines
		oCursor = textedit1.textCursor()
		nStart = oCursor.SelectionStart()
		nEnd = oCursor.SelectionEnd()
		cStr = textedit1.toPlainText()
		cStr1 = left(cStr, nStart) 
		cStr2 = substr(cStr, nStart+1,nEnd-nStart+1)
		cStr3 = substr(cStr,nEnd+1)
		cStrL = str2list(cStr2)
		cList = [] 
		for x in cStrL
			if x[1] = '/' and x[2] = '/'
				x = substr(x, 4)
			else  
				x = '/'+'/' + ' ' + x
			ok
			if x != '' add(cList, x) ok
		next
		cStr2 = list2str(cList)
		cStr  = cStr1 + cStr2 + cStr3
		textedit1.setPlainText(cStr)
		oCursor.setposition(nEnd+1,0)
		textedit1.settextcursor(oCursor) 

	func commentBlocklines
		oCursor = textedit1.textCursor()
		nStart = oCursor.SelectionStart()
		nEnd = oCursor.SelectionEnd()
		cStr = textedit1.toPlainText()
		cStr1 = left(cStr, nStart) 
		cStr2 = substr(cStr, nStart, nEnd-nStart+1)
		cStr3 = substr(cStr,nEnd+1)
		cStrL = str2list(cStr2)
		cList = []
		for x in cStrL
			x = " "+" "+ x
			if x != '' add(cList, x) ok
		next
		cStr2 = list2str(cList)
		cStr  = cStr1 + "/*" + cStr2 + " */" + cStr3
		textedit1.setPlainText(cStr)
		oCursor.setposition(nEnd+1,0)
		textedit1.settextcursor(oCursor)
