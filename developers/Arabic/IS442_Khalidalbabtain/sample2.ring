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
