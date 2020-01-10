# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteOutputWindow

	func RunProcess cProgram,cArg,cGetDataFunc
		aPara = split(cArg,",")
		oStringList = new qStringlist() {
			for cPara in aPara 
				append(cPara)
			next
		}
		oProcess = new qprocess(NULL) {
			setprogram( cProgram)
			setarguments(ostringlist)
			setreadyreadstandardoutputevent(cGetDataFunc)
			start_3(  QIODevice_ReadWrite )
		}
		return oProcess

	func GetProcessData 
		if ISNULL(oProcess) return ok
		cText = oProcess.readallstandardoutput().data()
		if isWindows()
			cText += WindowsNl()
		ok
		# Set the font
			oTFont.fromstring(cFont)
			oProcessEditbox.setFont(oTFont)
		oProcessEditbox.insertplaintext(cText)
		oCursor = oProcessEditbox.textcursor()
		nPos = max(len(oProcessEditbox.toplaintext())-1,0)
		oCursor.setPosition(nPos,QTextCursor_KeepAnchor)
		oCursor.setPosition(nPos,QTextCursor_MoveAnchor)
		oProcessEditbox.setTextCursor(oCursor)

	func SendProcessData
		if ISNULL(oProcess) return ok
		if isWindows()
			cText = oProcessText.text() + windowsnl()
		else 
			cText = oProcessText.text() + nl
		ok
		oProcess.write(cText ,len(cText))
		oProcessEditbox.insertplaintext(cText)
		oProcessText.setText("")

	func ClearProcess
		oProcessEditbox.setPlainText("")
