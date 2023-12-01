load "guilib.ring"

new QApp {
        win = new QWidget() {
                setWindowTitle("Printer")
                setGeometry(100,100,500,500)
                new QPushButton(win) {
                        setGeometry(20,20,100,30)
                        setText("Print")
                        setClickEvent("print()")
                }
		oPrinter = new QPrinter(0)
		oPreview = new QPrintPreviewWidget(oPrinter) {
			setParent(win)
			move(100,100) 	resize(500,500)
			setPaintRequestedEvent("printPreview()")
		}
                showmaximized()
        }
        exec()
}

func printPreview
	painter = new qpainter() {
		begin(oPrinter)
		myfont = new qfont("Times",50,-1,0)
		setfont(myfont)
		drawtext(100,100,"Test - Page (1)")
		oPrinter.newpage()
		drawtext(100,100,"Test - Page (2)")
		oPrinter.newpage()
		myfont2 = new qfont("Times",14,-1,0)
		setfont(myfont2)
		for x = 1 to 30
			drawtext(100,100+(20*x),"Number : " + x)
		next 
		 endpaint()
	}

func print
	oPreview.print()
