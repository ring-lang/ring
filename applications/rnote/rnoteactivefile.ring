# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Class RNoteActiveFile

	func Nofileopened
		msginfo("Sorry","Save/Select the file first!")

	func pSetActiveFileName
		oDockSourceCode.setWindowTitle("Source Code : " + cActiveFileName)
