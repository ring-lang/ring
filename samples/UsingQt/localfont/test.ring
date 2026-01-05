load "guilib.ring"

oFontDB = new QFontDatabase()
loadedFontID = oFontDB.addApplicationfont("pirulen.ttf")
aFam= oFontDB.applicationfontfamilies(loadedFontID)
cFont = aFam.at(0)
oFont = new QFont(cFont,0,0,0)
oFont.setPointSize(20)

app = new QApp {
	win = new QWidget() {
		setWindowTitle("Load local font file")
		resize(800,600)
		lbl = new QLabel(win) {
			move(100,100)
			setfont(oFont)
			setText("I LOVE PROGRAMMING")
		}
		show()
	}
	
	exec()
}
