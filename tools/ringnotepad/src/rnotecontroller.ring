# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteController from RNoteControllerBase 

	loadSettings()

	oApp = New QApp 
	oApp.setLayoutDirection(T_RINGNOTEPAD_LAYOUTDIRECTION)
	# Custom Editor Style Color
		checkCustomColors()
		prepareAutoComplete()	
	# Create the Main Window
		createMainWindow()
	# Default Settings
		setMode(nDefaultMode) 
		restoreSettings()
		win1 {
			move(0,0)
			resize(800,600)
			showMaximized()
		}
	oApp.exec()
