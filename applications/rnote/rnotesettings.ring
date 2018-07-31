# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteSettings

	func pSaveSettingsToFile
		pSaveCurrentFolder()
		cSettings = "aTextColor = ["+aTextColor[1]+","+aTextColor[2]+","+aTextColor[3]+"]" + nl +
				"aBackColor = ["+aBackColor[1]+","+aBackColor[2]+","+aBackColor[3]+"]" + nl +
				"cFont = '" + cFont + "'" + nl +
				"cWebSite = '" + cWebsite + "'" + nl +
				"cStartupFolder = '" + cStartupFolder + "'" + nl +
				"lShowProject = " + oDockProjectFiles.isvisible() + nl +
				"lShowSourceCode = " + oDockSourceCode.isvisible() + nl +
				"lShowBrowser = " + oDockWebBrowser.isvisible() + nl +
				"lShowFunctionsList = " + oDockFunctionsList.isvisible() + nl +
				"lShowClassesList = " + oDockClassesList.isvisible() + nl +
				"lShowOutputWindow = " + oDockOutputWindow.isvisible() + nl +
				"lShowFormDesigner = " + oDockFormDesigner.isvisible() + nl +
				"nTabSpaces = " + nTabSpaces + nl +
				"nDefaultStyle = " + nDefaultStyle + nl +
				"nDefaultMode  = " + nDefaultMode + nl
		cSettings = substr(cSettings,nl,char(13)+char(10))
		write(cSettingsFile,cSettings)

	func pSaveSettings
		pSaveSettingsToFile()
		if lAsktoSave and cTextHash != sha256(textedit1.toplaintext())
			new qmessagebox(win1)
			{
				setwindowtitle("Save Changes?")
				settext("Some changes are not saved!")
				setInformativeText("Do you want to save your changes?")
				setstandardbuttons(QMessageBox_Yes | QMessageBox_No)
				result = exec()
				this.win1 {
				if result = QMessageBox_Yes
					this.pSave()
				but result = QMessageBox_Cancel
					return false
				ok
			}
		}
		ok
		return true

	func LoadSettings
		if fexists(cSettingsFile)
			eval(read(cSettingsFile))
		ok

	func RestoreSettings
		pSetColors()
		pSetFont()
		pSetWebsite()
		pSetWindows()
		pSetTabSpaces()
		pSelectStyleColor2(nDefaultStyle)
