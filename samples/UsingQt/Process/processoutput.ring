load "stdlibcore.ring"
load "guilib.ring"

win	 = NULL
textEdit = NULL
oProcess = NULL

func main

	cProg="ring"
	arg="test.ring"
	runprocess(cProg,arg,"pGetData()")

	oApp = new QApp {
		win = new qwidget() { 
			setWindowTitle("Using QProcess")
			resize(400,400)
			btn = new QPushButton(win) { 
				setText("Close")
				setClickEvent("win.close()")
			}
			textEdit = new QTextEdit(win) { move(0,50) }
			show() 
		} 
		exec()
	}

func runprocess (cProgram,cArg,cGetDataFunc){
	aPara = split(cArg," ")
	oStringList = new qStringlist() {
		for cPara in aPara
			append(cPara)
		next
	}
	oProcess = new qprocess(NULL) {
		setprogram( cProgram)
		setarguments(oStringlist)
		setreadyreadstandardoutputevent(cGetDataFunc)
		start_3( QIODevice_ReadWrite )
	}
	return oProcess
}

func pGetData
	if ISNULL(oProcess) return ok
	cText = oProcess.readallstandardoutput().data()
	textEdit.setText(cText)
