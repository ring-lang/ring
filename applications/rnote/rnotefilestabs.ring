# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteFilesTabs

	func SetFileTab cFile 
		filestabs.blocksignals(True)
		if len(aFilesLines) = 1
			filestabs.setTabText(0,JustFileName(cFile))
		else 
			if filestabs.count() != len(aFilesLines)
				filestabs.addtab(new qWidget(),JustFileName(cFile))
				filestabs { setcurrentindex( count() - 1 ) }
			else 
				nPos = find(aFilesLines,cFile,1)
				filestabs.setcurrentindex(nPos-1)
			ok
		ok
		filestabs.blocksignals(False)

	func ChangeFileTab
		nIndex = filestabs.currentindex() + 1
		cFile = aFilesLines[nIndex][1]
		nRow = aFilesLines[nIndex][2]		
		cActiveFileName = cFile 
		openFile(cFile)
		GotoLine(nRow)		
		displayFunctionsList()
		displayClassesList()

	func CloseFileTab
		filestabs.blocksignals(True)
		nIndex = filestabs.geteventparameters()[1]
		if filestabs.count() != 1
			filestabs.removetab(nIndex)
			del(aFilesLines,nIndex+1)
			if nIndex > 0
				filestabs.setcurrentindex(nIndex-1)
			else 
				filestabs.setcurrentindex(nIndex)
			ok
			ChangeFileTab()
		else 
			cActiveFileName  = ""
			this.aFilesLines = []
			lAskToSave 	 = false
			cTextHash	 = sha256("")
			filestabs.setTabText(0,"noname")
			textedit1.blocksignals(True)
			textedit1.setPlaintext("")
			textedit1.blocksignals(False)
		ok
		filestabs.blocksignals(False)
