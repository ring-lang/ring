# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteController from RNoteControllerBase 

	LoadSettings()

	MyApp = New qApp {
		this {
			# Custom Editor Style Color
				pCheckCustomColors()
				PrepareAutoComplete()	
			# Create the Main Window
				CreateMainWindow()
			# Default Settings
				SetMode(nDefaultMode) 
				RestoreSettings()
				win1.showmaximized()
		}
		exec()
	}
