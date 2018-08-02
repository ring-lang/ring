# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteDistribute

	func Distribute nOption
		if cActiveFileName = Null return Nofileopened() ok
		pSave()
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
			on 7	# qt project
				cPara += ",-dist,-allruntime,-gui,-mobileqt"
		off
		oDockOutputWindow { show() raise() }		
		oProcessEditbox.setplaintext("")
		chdir(JustFilePath(cActiveFileName))
		oProcess = RunProcess(cAppToRun,cPara,cGetProcessData)
		OSFilesManager()
		chdir(exefolder())

