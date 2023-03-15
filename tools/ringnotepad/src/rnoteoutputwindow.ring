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
		# Set the font
			oTFont.fromstring(cFont)
			oProcessEditbox.setFont(oTFont)
		if isWindows() cText = substr(cText,WindowsNL(),nl) ok
		cCurrentText = oProcessEditbox.toplaintext()
		C_OUTPUTBUFFERSIZE = 1024*1024 # 1 MB
		cText = right(cCurrentText,min(C_OUTPUTBUFFERSIZE-len(cText),len(cCurrentText)) ) + cText
		oProcessEditbox.setplaintext(cText)
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
		oProcessEditbox.movecursor(13,0)
		oProcessEditbox.insertplaintext(cText)
		oProcessText.setText("")

	func ClearProcess
		oProcessEditbox.clear()
		if ISNULL(oProcess) { return }
		oProcess.setreadyreadstandardoutputevent("")
		oProcess.kill()
		oProcessEditbox.clear()