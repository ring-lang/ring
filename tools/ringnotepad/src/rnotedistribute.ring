# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteDistribute

	func Distribute nOption
		if cActiveFileName = Null return Nofileopened() ok
		Save()
		cAppToRun = exefolder()+"/ring2exe"
		cPara = cActiveFileName
		switch nOption
			on 1	# ringo
				cAppToRun = exefolder()+"/ring"
				cPara += ",-go,-norun"
			on 2	# exe 
				cPara += ",-static"
			on 3	# dist allruntime
				cPara += ",-dist,-allruntime"
			on 4	# dist allruntime gui
				cPara += ",-dist,-allruntime,-gui"
			on 5	# ringqt
				cPara += ",-dist,-qt,-gui"
			on 6	# ringallegro 
				cPara += ",-dist,-allegro,-freeglut,-opengl,-gui"
			on 7	# qt project (mobile)
				cPara += ",-dist,-allruntime,-gui,-mobileqt"
			on 8	# qt project (WebAssembly)
				cPara += ",-dist,-allruntime,-gui,-webassemblyqt"
			on 9	# light guilib (QtCore, QtGui & QtWidgets)
				cPara += ",-dist,-gui,-lightguilib"
			on 10	# exe gui
				cPara += ",-static,-gui"
		off
		oDockOutputWindow { show() raise() }		
		oProcessEditbox.setplaintext("")
		chdir(JustFilePath(cActiveFileName))
		oProcess = RunProcess(cAppToRun,cPara,cGetProcessData)
		OSFilesManager()
		chdir(exefolder())

