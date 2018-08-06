# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Class RNoteRun

	func DebugOperation cActiveFileName
		cDir = CurrentDir()
		chdir(exefolder())
		if iswindows()
			cCode = 'start '+cCurrentDir+'batch\run "' + cActiveFileName + '"' + nl
		else
			cCode = 'cd $(dirname "'+cActiveFileName+'") ; ' + ' ring "' + cActiveFileName + '"' + nl
		ok
		system(cCode)
		chdir(cDir)

	func RunOperation cActiveFileName
		cDir = CurrentDir()
		chdir(exefolder())
		if iswindows()
			cCode = 'start '+cCurrentDir+'batch\run2 "' + cActiveFileName + '"' + nl
		else
			cCode = 'cd $(dirname "'+cActiveFileName+'") ; ' + ' ring "' + cActiveFileName + '"' + nl
		ok
		system(cCode)
		chdir(cDir)

	func RunGUIOperation cActiveFileName
		oProcessEditbox.setplaintext("")
		cDir = CurrentDir()
		chdir(JustFilePath(cActiveFileName))
		oProcess = RunProcess(cRingEXE,cActiveFileName,cGetProcessData)
		chdir(cDir)

	func RunWebApplication cFile
		if isWindows() 
			if cWebApplicationFolder != JustFilePath(cFile)
				cWebApplicationFolder = JustFilePath(cFile)
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
			cWebURL = cFile
			nPos = substr(cWebURL,"htdocs")
			cWebURL = substr(cWebURL,nPOS+7)
			new QDesktopServices {
				OpenURL(new qURL("http://localhost/"+cWebURL))
			}
		ok


