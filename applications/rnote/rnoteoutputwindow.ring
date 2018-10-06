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
		oProcessEditbox.insertplaintext(cText)

	func SendProcessData
		if ISNULL(oProcess) return ok
		cText = oProcessText.text() + windowsnl()
		oProcess.write(cText ,len(cText))
		oProcessEditbox.insertplaintext(cText)
		oProcessText.setText("")

	func ClearProcess
		oProcessEditbox.setPlainText("")
