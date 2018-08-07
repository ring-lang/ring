# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteFilesTabs

	func SetFileTab cFile 
		if len(aFilesLines) = 1
			filestabs.setTabText(0,cFile)
		else 
			if filestabs.count() != len(aFilesLines)
				filestabs.addtab(new qWidget(),cFile)
			else 
				nPos = find(aFilesLines,cFile,1)
				filestabs.setcurrentindex(nPos-1)
			ok
		ok

	func ChangeFileTab
		nIndex = filestabs.currentindex() + 1
		cFile = aFilesLines[nIndex][1]
		nRow = aFilesLines[nIndex][2]		
		cActiveFileName = cFile 
		openFile(cFile)
		GotoLine(nRow)		

	func CloseFileTab
		nIndex = filestabs.geteventparameters()[1]
		filestabs.removetab(nIndex)
		if filestabs.count() = 0
			filestabs.addtab(new qWidget(),cActiveFileName)
		ok
