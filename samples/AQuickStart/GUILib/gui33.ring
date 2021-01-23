Load "guilib.ring"
new qApp {
        win1 = new qwidget() {
                setwindowtitle("Printer")
                setgeometry(100,100,500,500)
                myweb = new qwebview(win1) {
                        setgeometry(100,100,1000,500)
                        loadpage(new qurl("http://google.com"))
                }
                new qpushbutton(win1) {
                        setGeometry(20,20,100,30)
                        settext("Print")
                        setclickevent("print()")
                }
                showmaximized()
        }
        exec()
}

func print
        printer1 = new qPrinter(0) {
                setoutputformat(1)      # 1 = pdf
                setoutputfilename("test.pdf")
                painter = new qpainter() {
                        begin(printer1)
                        myfont = new qfont("Times",50,-1,0)
                        setfont(myfont)
                        drawtext(100,100,"test")
                        printer1.newpage()
                        drawtext(100,100,"test2")
                        endpaint()
                }
        }

        printer1 = new qPrinter(0) {
                setoutputformat(1)
                setoutputfilename("test2.pdf")
                myweb.print(printer1,' system("test2.pdf") ')
                myweb.show()
        }

        system ("test.pdf")
