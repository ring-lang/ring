load "guilib.ring"

new QApp {
        win1 = new QWidget() {
                setWindowTitle("Printer Preview Dialog")
                setGeometry(100,100,800,880)
		printer1 = new QPrinter(0)
		oPreview = new QPrintPreviewDialog(printer1) {
			setParent(win1)
			move(10,10) 
			setPaintRequestedEvent("printPreview()")
		}
                show()
        }
        exec()
}

func printPreview
	painter = new qpainter() {
		begin(printer1)
		myfont = new qfont("Times",50,-1,0)
		setfont(myfont)
		drawtext(100,100,"Test - Page (1)")
		printer1.newpage()
		drawtext(100,100,"Test - Page (2)")
		printer1.newpage()
		myfont2 = new qfont("Times",14,-1,0)
		setfont(myfont2)
		for x = 1 to 30
			drawtext(100,100+(20*x),"Number : " + x)
		next 
		 endpaint()
	}
