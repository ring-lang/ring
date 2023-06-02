# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteActiveFile

	func Nofileopened
		msginfo(T_RINGNOTEPAD_SORRY,T_RINGNOTEPAD_SELECTTHEFILEFIRST)

	func SetActiveFileName
		oDockSourceCode.setWindowTitle(T_RINGNOTEPAD_SOURCECODECOLON + cActiveFileName)
		setFileTab(cActiveFileName)
