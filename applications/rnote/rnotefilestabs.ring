# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteFilesTabs

	func SetFileTab cFile 
		if len(aFilesLines) = 1
			filestabs.setTabText(0,cFile)
		else 
			filestabs.addtab(new qWidget(),cFile)
		ok

	func ChangeFileTab

	func CloseFileTab

