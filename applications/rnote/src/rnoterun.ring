# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Class RNoteRun

	func DebugOperation cActiveFileName
		cDir = CurrentDir()
		chdir(exefolder())
		cFileName = FileNameEncoding(cActiveFileName)
		if isBatchFile(cFileName)
			cCode = RunBatchFile(cFileName)
		else 
			if iswindows()
				cCode = 'start '+cCurrentDir+'batch\run "' + cFileName + '"' + nl
			else
				cCode = 'cd $(dirname "'+cFileName+'") ; ' + ' ring "' + cFileName + '"' + nl
			ok
		ok
		system(cCode)
		chdir(cDir)

	func RunOperation cActiveFileName
		cDir = CurrentDir()
		chdir(exefolder())
		cFileName = FileNameEncoding(cActiveFileName)
		if isBatchFile(cFileName)
			cCode = RunBatchFile(cFileName)		
		else 
			if iswindows()
				cCode = 'start '+cCurrentDir+'batch\run2 "' + cFileName + '"' + nl
			else
				cCode = 'cd $(dirname "'+cFileName+'") ; ' + ' ring "' + cFileName + '"' + nl
			ok
		ok
		system(cCode)
		chdir(cDir)

	func RunGUIOperation cActiveFileName
		oProcessEditbox.setplaintext("")
		cDir = CurrentDir()
		chdir(JustFilePath(cActiveFileName))
		if isBatchFile(cActiveFileName)
			cCode = RunBatchFile(cActiveFileName)
			oProcess = RunProcess(cCode,"",cGetProcessData)
		else 
			oProcess = RunProcess(cRingEXE,cActiveFileName,cGetProcessData)
		ok
		chdir(cDir)

	func RunWebApplication cFile
		cFileName = FileNameEncoding(cFile)
		if isWindows() 
			if cWebApplicationFolder != JustFilePath(cFileName)
				cWebApplicationFolder = JustFilePath(cFileName)
				new ServerPrepare { 
					setApplicationPath(this.cWebApplicationFolder)
					PrepareConfigurationFile() 
					cServerExe = getserverExeFile()
				}	
				oProcess = RunProcess(cCurrentDir + "batch\killwebserver.bat","",cGetProcessData)			
				oProcess.waitForFinished(3000)
				oWebServerProcess = RunProcess(cServerEXE,"",cGetProcessData)			
				sleep(3)
				oProcessEditbox.setplaintext("")
			ok
			new QDesktopServices {
				OpenURL(new qURL("http://localhost:8080/"+JustFileName(cFile)))
			}
		else 
			cWebURL = cFileName
			nPos = substr(cWebURL,"htdocs")
			cWebURL = substr(cWebURL,nPOS+7)
			new QDesktopServices {
				OpenURL(new qURL("http://localhost/"+cWebURL))
			}
		ok

	func isBatchFile cFile 
		if right(lower(trim(cFile)),4) = ".bat" or 
			right(lower(trim(cFile)),3) = ".sh"
			return True 
		ok
		return False 

	func RunBatchFile cFile
		if iswindows()
			chdir(JustFilePath(cFile))
			cCode = cFile
		else
			cCode = 'cd $(dirname "'+cFile+'") ; ' + './' + cFile +  nl
		ok
		return cCode 
