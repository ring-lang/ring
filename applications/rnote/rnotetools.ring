class RNoteTools

	func RunTool cFileName
		oProcessEditbox.setplaintext("")
		oProcessText.setFocus(0)
		chdir(JustFilePath(cFileName))
		oProcess = pRunProcess(cRingEXE,cFileName,cpGetProcessData)
		chdir(exefolder())

	func RunToolConsole cFileName
		if iswindows()
			System('start '+exefolder()+'ring "' + cFileName + '"' + nl)
		else
			cCode = 'cd $(dirname "'+cFileName+'") ; ' + ' ring "' + cFileName + '"' + nl
			system(cCode)
		ok

	func pFormDesigner		
		cFormFileName = cCurrentDir + "../formdesigner/formdesigner.ring"
		RunTool(cFormFileName)

	func pREPLConsole
		cAppFileName = cCurrentDir + "../ringrepl/repl.ring"
		RunToolConsole(cAppFileName)

	func pREPLGUI
		cAppFileName = cCurrentDir + "../ringrepl/replw.ring"
		# RunTool will split parameters using "," as separator 
		if nDefaultStyle <= 3 
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
		but isMacosx()
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


