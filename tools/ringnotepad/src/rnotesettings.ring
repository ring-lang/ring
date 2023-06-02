# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteSettings

	func SaveSettingsToFile
		SaveCurrentFolder()
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

	func SaveSettings
		SaveSettingsToFile()
		if lAsktoSave and cTextHash != sha256(textedit1.toplaintext())
			new qmessagebox(win1)
			{
				setwindowtitle(T_RINGNOTEPAD_SAVECHANGES) # "Save Changes?"
				settext(T_RINGNOTEPAD_SOMECHANGESNOTSAVED) # "Some changes are not saved!"
				setInformativeText(T_RINGNOTEPAD_DOYOUWANTTOSAVECHANGES) # "Do you want to save your changes?"
				setstandardbuttons(QMessageBox_Yes | QMessageBox_No)
				result = exec()
				this.win1 {
				if result = QMessageBox_Yes
					this.Save()
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
		SetColors()
		SetFont()
		SetWebsite()
		SetWindows()
		SetTabSpaces()
		SelectStyleColor2(nDefaultStyle)

	func SetWindows
		if not lShowProject  		oDockProjectFiles.close() else oDockProjectFiles.show() ok
		if not lShowSourceCode  	oDockSourceCode.close() else oDockSourceCode.show() ok
		if not lShowBrowser  		oDockWebBrowser.close() else oDockWebBrowser.show() ok
		if not lShowFunctionsList 	oDockFunctionsList.close() else oDockFunctionsList.show() ok
		if not lShowClassesList 	oDockClassesList.close() else oDockClassesList.show() ok
		if not lShowOutputWindow 	oDockOutputWindow.close() else oDockOutputWindow.show() ok
		if not lShowFormDesigner 	oDockFormDesigner.close() else oDockFormDesigner.show() ok

