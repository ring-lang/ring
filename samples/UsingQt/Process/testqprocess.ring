load "guilib.ring"

new qApp {
	win = new qWidget() {
		setwindowtitle("Test qProcess")
		new qPushbutton(win) {
			setText("Run")
			setclickevent("test()")
		}
		resize(400,400)
		show()
	}
	exec()
}

func test 
	new qProcess(NULL) {
		setprogram(exefilename())
		aArg = new qStringList() {
			Append(exefolder()+"../applications/fifteenpuzzle/FifteenPuzzleGame.ring")
		}
		setArguments(aArg)
		start_3(QIODevice_ReadWrite)
	}
