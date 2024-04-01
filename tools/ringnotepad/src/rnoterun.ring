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
			elseif isMacOSX()
                                cCode = 'osascript -e ' + char(39) + 'tell app "Terminal" to do script "'+cCurrentDir+'batch/run.sh ' + JustFilePath(cFileName) + ' ' + JustFileName(cFileName) + char(34) + char(39) + nl
                        else
                                cCode = "x-terminal-emulator -e "+cCurrentDir+'batch/run.sh ' + JustFilePath(cFileName) + ' ' + JustFileName(cFileName) + nl
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
			elseif isMacOSX()
                                cCode = 'osascript -e ' + char(39) + 'tell app "Terminal" to do script "'+cCurrentDir+'batch/run2.sh ' + JustFilePath(cFileName) + ' ' + JustFileName(cFileName) + char(34) + char(39) + nl
                        else
                                cCode = "x-terminal-emulator -e "+cCurrentDir+'batch/run2.sh ' + JustFilePath(cFileName) + ' ' + JustFileName(cFileName) + nl
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
                        apacheConfigPath = cCurrentDir+ "batch/apache_config/"
                        lastRunPathFile = apacheConfigPath + "lastrundirpath.txt"
                        if fexists(lastRunPathFile)
                                lastRunPath = substr(read(lastRunPathFile),nl , "")
                        else
                                lastRunPath = ""
                        ok
                        cAppDir = JustFilePath(cFileName)
                        if len(lastRunPath) = 0 OR Substr(cAppDir, lastRunPath) = 0
                                apacheConfigTxt = read(apacheConfigPath + "webapp.conf.bak")
                                apacheConfigTxt = substr(apacheConfigTxt, "#{RingWebAppPath}", cAppDir)
                                apacheConfigTxt = substr(apacheConfigTxt, "#{RingApacheConfigDir}", apacheConfigPath)
                                write(apacheConfigPath + "ringwebapp.local.conf", apacheConfigTxt)
                                if isMacOSX()
                                        system('osascript -e ' + char(39) + 'tell app "Terminal" to do script "'+cCurrentDir+'batch/apache_config/setwebappconf.sh ' + apacheConfigPath + ' ' + cAppDir + char(34) + char(39))
                                else
                                        system("x-terminal-emulator -e "+cCurrentDir+ "batch/apache_config/setwebappconf.sh " + apacheConfigPath + " " + cAppDir)
                                ok
                                return
                        else
                                cAppDir = lastRunPath
                        ok
			cWebURL = substr(cFileName, cAppDir, "")
			new QDesktopServices {
				OpenURL(new qURL("http://ringwebapp.local:8060/"+ cWebURL))
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
