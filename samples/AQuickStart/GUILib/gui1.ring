Load "guilib.ring"

MyApp = New qApp {

        win1 = new qWidget() {

                setwindowtitle("Hello World")
                setGeometry(100,100,370,250)

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

                btn2 = new qpushbutton(win1) {
                        setGeometry(150,200,100,30)
                        settext("Close")
                        setclickevent("pClose()")
                }

                lineedit1 = new qlineedit(win1) {
                        setGeometry(10,100,350,30)
                }

                show()
        }

        exec()
}

Func pHello
        lineedit1.settext( "Hello " + lineedit1.text())

Func pClose
        MyApp.quit()
