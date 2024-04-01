# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteTools

	func RunTool cFileName
		oProcessEditbox.setplaintext("")
		oProcessText.setFocus(0)
		chdir(JustFilePath(cFileName))
		oProcess = RunProcess(cRingEXE,cFileName,cGetProcessData)
		chdir(exefolder())

	func RunToolConsole cFileName
		if iswindows()
			System('start '+exefolder()+'ring "' + cFileName + '"' + nl)
		else
			cCode = 'cd $(dirname "'+cFileName+'") ; ' + ' ring "' + cFileName + '"' + nl
			system(cCode)
		ok

	func OpenFormDesigner		
		cFormFileName = cCurrentDir + "../formdesigner/formdesigner.ring"
		RunTool(cFormFileName)

	func REPLConsole
		cAppFileName = cCurrentDir + "../ringrepl/ringrepl.ring"
		RunToolConsole(cAppFileName)

	func REPLGUI
		cAppFileName = cCurrentDir + "../ringrepl/ringreplw.ring"
		# RunTool will split parameters using "," as separator 
		if nDefaultStyle <= 3 or nDefaultStyle = STYLECOLOR_IMAGE2
			cAppFileName += ",1"	# Style Fusion White
		else
			cAppFileName += ",2"	# Style Fusion Black
		ok
		RunTool(cAppFileName)

	func OSTerminal
		if isWindows()
			cCommand = 'start cmd /K "cd ' + cStartupFolder + '"'
		but isLinux()
			cCommand = "gnome-terminal"
		but isMacOSX()
			cCommand = "open /Applications/Utilities/Terminal.app"
		else 
			return
		ok
		system(cCommand)

	func OSFilesManager 
		if cActiveFileName != Null
			cStartupFolder = justfilepath(cActiveFileName)
		ok
		new QDesktopServices {
			OpenURL(new qURL("file:///"+this.cStartupFolder))
		}


