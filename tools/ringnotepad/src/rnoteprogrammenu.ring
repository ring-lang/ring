# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteProgramMenu

	func Debug
		if cActiveFileName = Null return Nofileopened() ok
		Save()
		DebugOperation(cActiveFileName)

	func Run
		if cActiveFileName = Null return Nofileopened() ok
		Save()
		RunOperation(cActiveFileName)

	func RunNoConsole
		if cActiveFileName = Null return Nofileopened() ok
		Save()
		oDockOutputWindow { show() raise() }		
		RunGUIOperation(cActiveFileName)

	func RunInBrowser
		if cActiveFileName = Null return Nofileopened() ok
		Save()	
		RunWebApplication(this.cActiveFileName)

        func MakeFilesExecutable
                if cActiveFileName = Null return Nofileopened() ok
		Save()
                apacheConfigPath = cCurrentDir+ "batch/apache_config/"
                lastRunPathFile = apacheConfigPath + "lastrundirpath.txt"
                lastRunPath = substr(read(lastRunPathFile),nl , "")
                cAppDir = JustFilePath(this.cActiveFileName)
                if substr(cAppDir, lastRunPath)
                        cAppDir = lastRunPath
                ok
                if IsWindows()
                        
                elseif IsMacOSX()
                        system('osascript -e ' + char(39) + 'tell app "Terminal" to do script "'+cCurrentDir+'batch/apache_config/makeexecutable.sh ' + cAppDir + char(34) + char(39))
                else
                        system("x-terminal-emulator -e "+cCurrentDir+ "batch/apache_config/makeexecutable.sh " + cAppDir)
                ok

