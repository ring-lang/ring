IS442 Group, My first Ring program

/*
	IS442 - khalid al-babtain
*/

Load "guilib.ring"

MyApp = New qApp {

        win1 = new qWidget() {

                setwindowtitle("Welcome")
                setGeometry(100,100,400,300)


                label1 = new qLabel(win1) {
                        settext("What is your name ?")
                        setGeometry(10,20,350,30)
                        setalignment(Qt_AlignHCenter)
                }

                btn1 = new qpushbutton(win1) {
                        setGeometry(10,200,100,30)
                        settext("Say Hello")
                        setclickevent("pHello()")
                }

                btn1 = new qpushbutton(win1) {
                        setGeometry(150,200,100,30)
                        settext("Close")
                        setclickevent("pClose()")
                }

                lineedit1 = new qlineedit(win1) {
                        setGeometry(10,100,350,30)
                        settextchangedevent("pChange()")
                        setreturnpressedevent("penter()")
                }

                show()
        }

        exec()
}

Func pHello
        lineedit1.settext( "Hello " + lineedit1.text())

Func pClose
        MyApp.quit()

Func pChange
        win1 { setwindowtitle( lineedit1.text() ) }

Func pEnter
        new qmessagebox(win1) {
                setwindowtitle("Thanks")
                settext("Hi " + lineedit1.text() )
                setstylesheet("background-color : white")
                show()
        }


/*
	IS442 - khalid al-babtain
*/

Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {

                setwindowtitle("QProgressBar valueChanged Event")

                progress1 = new qprogressbar(win1) {
                        setGeometry(100,100,350,30)
                        setvalue(10)
                        setvaluechangedevent("pChange()")
                }

                new qpushbutton(win1) {
                        setGeometry(10,10,100,30)
                        settext("increase")
                        setclickevent("pIncrease()")
                }

                showMaximized()

        }

        exec()
}

func pIncrease
        progress1 { setvalue(value()+1)  }

func pchange
        win1.setwindowtitle("value : " + progress1.value() )



/*
	IS442 - khalid al-babtain
*/

Load "guilib.ring"
New qapp {
        win1 = new qwidget() {
                setwindowtitle("Drawing using QPainter")
                setgeometry(100,100,500,500)
                label1 = new qlabel(win1) {
                        setgeometry(10,10,400,400)
                        settext("")
                }
                new qpushbutton(win1) {
                        setgeometry(200,400,100,30)
                        settext("draw")
                        setclickevent("draw()")
                }

                show()
        }
        exec()
}

Func draw
                p1 = new qpicture()
                color = new qcolor() {
                        setrgb(0,0,255,255)
                }
                pen = new qpen() {
                        setcolor(color)
                        setwidth(10)
                }
                new qpainter() {
                        begin(p1)
                        setpen(pen)
                        drawline(500,150,950,450)
                        drawline(950,550,500,150)
                        endpaint()
                }
                label1 { setpicture(p1) show() }

