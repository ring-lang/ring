load "guilib.ring"

new QApp {
        win = new QWidget() {
                setWindowTitle("Generating a simple report")
                setGeometry(100,100,500,500)
                btnPrint = new QPushButton(win) {
                        setGeometry(20,20,100,30)
                        setText("Print")
                        setClickEvent("print()")
                }
                btnClose = new QPushButton(win) {
                        setGeometry(20,120,100,30)
                        setText("Close Application")
                        setClickEvent("win.close()")
                }
		oPrinter = new QPrinter(0) {
			setOutputFormat(1)
			setOutputFilename("report.pdf")
		}
		oPreview = new QPrintPreviewWidget(oPrinter) {
			setParent(win)
			move(100,100) 	resize(500,500)
			setPaintRequestedEvent("printPreview()")
		}
		oBtnsLayout = new QHBoxLayout() {
			addWidget(btnPrint)
			addWidget(btnClose)
		}
		oLayout = new QVBoxLayout() {
			addWidget(oPreview)
			addLayout(oBtnsLayout)
		}
		setLayout(oLayout)
                showMaximized()
        }
        exec()
}

func printPreview
	painter = new QPainter() {
		begin(oPrinter)
		myFont = new qfont("Times",40,-1,0)
		setFont(myfont)
		drawText(200,100,"A Simple Report")
		myFont = new qfont("Times",30,-1,0)
		setFont(myfont)
		drawText(100,200,"Date: " + date())
		drawText(100,300,"Time: " + time())
		oPrinter.newpage()
		drawtext(200,100,"Numbers And Squares")
		myfont = new qfont("Times",14,-1,0)
		setfont(myfont)
		drawText(100,200,"Number")
		drawText(300,200,"Square")
		for x = 1 to 20
			drawText(100,250+(30*x),"" + x)
			drawText(300,250+(30*x),"" + (x*x))
		next 
		endPaint()
	}

func print

	oPreview.print()
	new QDesktopServices { 
		openURL(new QURL("report.pdf") ) 
	} 
