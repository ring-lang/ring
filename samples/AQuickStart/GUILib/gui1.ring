load "guilib.ring"

oApp = new QApp {

        win = new QWidget() {

                setWindowTitle("Hello World")
                setGeometry(100,100,370,250)

                lbl1 = new QLabel(win) {
                        setText("What is your name ?")
                        setGeometry(10,20,350,30)
                        setAlignment(Qt_AlignHCenter)
                }

                btn1 = new QPushButton(win) {
                        setGeometry(10,200,100,30)
                        setText("Say Hello")
                        setClickEvent("pHello()")
                }

                btn2 = new qpushbutton(win) {
                        setGeometry(150,200,100,30)
                        setText("Close")
                        setClickEvent("pClose()")
                }

                lineedit1 = new QLineEdit(win) {
                        setGeometry(10,100,350,30)
                }

                show()
        }

        exec()
}

func pHello
        lineedit1.setText( "Hello " + lineedit1.text())

func pClose
        oApp.quit()
