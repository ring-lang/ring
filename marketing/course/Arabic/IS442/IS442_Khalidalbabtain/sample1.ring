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
