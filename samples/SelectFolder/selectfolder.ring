load "guilib.ring"

new qApp {
	w = new qWidget() {
		oFile = new qFileDialog(w)
		cFolder = oFile.getExistingDirectory(w,"Open Directory","c:\",0)
		w.setWindowTitle(cFolder)
		show()
	}
	exec()
}
