/*
IS442-Mohammed Mosoud  
*/
Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {

                setGeometry(100,100,600,150)
                setwindowtitle("Using QProgressBar")

                for x = 10 to 100 step 10
                        new qprogressbar(win1) {
                                setGeometry(100,x,350,30)
                                setvalue(x)
                        }
                next

                show()
        }
        exec()
}
