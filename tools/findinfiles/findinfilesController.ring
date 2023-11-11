# Application : Find in files 
# Author      : Mahmoud Fayed <msfclipper@yahoo.com>
# Date        : 2018.03.06

load "findinfilesView.ring"
import System.GUI
if isMainSourceFile() { 
	new App
	{
		StyleFusion()
		open_window(:findinfilesController)
		exec()
	}
}

class findinfilesController from WindowsControllerParent

	oView = new findinfilesView

	cCurrentDir 	= currentdir()
	setFolder(cCurrentDir)

	aResult 	= []
	nFilesCount 	= 0
	nMatches 	= 0
	
	aResultFiles	= []
	
	lShowNoOutputMessage = True	

	oSearchFilter = new qallevents(oView.win)
	oSearchFilter.setKeyPressEvent(Method(:SearchKeyPress))
	oView.win.installeventfilter(oSearchFilter)



	func setFolder cFolder 
		oView.txtFolder.setText(cFolder)

	func search
		Qt_ItemIsSelectable 	= 1
		Qt_ItemIsEnabled 	= 32
		aResult = []
		aResultFiles	= []
		oView {
			cText = txtFind.text()
			cFolder = trim(txtFolder.text())
			cExtension = trim(txtExtension.text())
			if trim(cText) = NULL or trim(cFolder) = NULL or trim(cExtension) = NULL {
				return 
			}
			try { 
				cDir = currentdir()
				chdir(this.cCurrentDir)
				aFiles = ListAllFiles(cFolder,cExtension)
				chdir(cDir)
			Catch 
				msginfo("Sorry","Can't open the folder!")
				return 
			} 
			nRow = 0
			this.StartOutput()
			Statusbar1.ShowMessage("Searching " + len(aFiles) + 
					" files for " + cText ,0)
			this.nFilesCount 	= 0
			this.nMatches 		= 0
			for cFile in aFiles step 1 { 
				try
					cFileText = read(cFile)
				catch 
					loop
				done
				aList = str2list(cFileText)
				nMax = len(aList)
				lFound = False 
				for x = 1 to nMax step 1 { 
					cLine = aList[x]
					if checkMatchCase.checkstate() {
						nPos = substr(cLine,cText)
					else 
						nPos = substr(upper(cLine),upper(cText))
					}
					cLine = substr(cLine,Tab,"")
					cLine = trim(cLine)
					if nPos { 
						this.nMatches++
						if lFound = False {
							lFound = True 
							this.nFilesCount++
						}
						nRow++
						TableOutput.setRowCount(nRow)
						oItem = new TableWidgetItem(cFile)
						oItem.setFlags(Qt_ItemIsSelectable|Qt_ItemIsEnabled)
						TableOutput.setItem(nRow,1,oItem)
						oItem = new TableWidgetItem(""+x)
						oItem.setFlags(Qt_ItemIsSelectable|Qt_ItemIsEnabled)
						TableOutput.setItem(nRow,2,oItem)
						oItem = new TableWidgetItem(cLine)
						oItem.setFlags(Qt_ItemIsSelectable|Qt_ItemIsEnabled)
						TableOutput.setItem(nRow,3,oItem)
						this.aResult + [cFile,x]
						if not find(this.aResultFiles,cFile) {
							this.aResultFiles + cFile 
						}
					}
				}
			}
			if nRow = 0 { 
				if this.lShowNoOutputMessage {
					Statusbar1.ShowMessage("Done...",0)
					msginfo("Sorry","No Output!")
				}
				return 
			}
			Statusbar1.ShowMessage("" +
				this.nMatches + " matches across " +
				this.nFilesCount + " files" ,0)
		}

	func StartOutput

		oView {
			TableOutput.setRowCount(0)
			TableOutput.hide()
			TableOutput.show()
		}

	func browse

		new QFileDialog(oView.win)
		{
			cFolder = getExistingDirectory(this.oView.win,"Open Directory","Folder",0)
		}
		oView.txtFolder.setText(cFolder)

	func close

		oView.win.close()

	func SelectResult 

		nIndex	= oView.TableOutput.currentrow()
		cFile  	= aResult[nIndex][1]
		nRow 	= aResult[nIndex][2]
		if isParent() {
			parent().FindInFilesSelect(cFile,nRow)
		}

	func Replace 
		nIndex	  = oView.TableOutput.currentrow()
		if nIndex = 0
			msginfo("Sorry","Please select a line first!")
			return
		ok
		cFile  	  = aResult[nIndex][1]
		nRow 	  = aResult[nIndex][2]
		cText     = oView.txtFind.text()		
		cReplace  = oView.txtReplace.text()
		lCase	  = oView.checkMatchCase.checkstate()
		try
			cContent  = read(cFile)
		catch
			return 
		end
		aContentList = str2list(cContent)
		if lCase {
			aContentList[nRow] = substr(aContentList[nRow],cText,cReplace)
		else 
			aContentList[nRow] = substr(aContentList[nRow],cText,cReplace,True)
		}
		cContent = list2str(aContentList)
		if isWindows() {
			cContent = substr(cContent,nl,Windowsnl())
		}
		write(cFile,cContent)
		lShowNoOutputMessage = False 
		search()
		lShowNoOutputMessage = True
		oView.Statusbar1.ShowMessage("Replace operation done, In file : " + cFile,0)

	func ReplaceAll
		cText     = oView.txtFind.text()		
		cReplace  = oView.txtReplace.text()
		lCase	  = oView.checkMatchCase.checkstate()
		for cFile in aResultFiles {
			try
				cContent  = read(cFile)
			catch 
				loop
			end
			if lCase {
				cContent = substr(cContent,cText,cReplace)
			else 
				cContent = substr(cContent,cText,cReplace,True)
			}		
			write(cFile,cContent)	
		}
		# Calling search() will modify aResultFiles 
			cMsg = "Replace All operation done, In " + len(aResultFiles) + " files"
		lShowNoOutputMessage = False 
		search()
		lShowNoOutputMessage = True
		oView.Statusbar1.ShowMessage(cMsg,0)

	func SearchKeyPress
		if oSearchFilter.getKeyCode() = Qt_Key_Escape
			Close()
		ok
