/*
IS442-naifmohammed
*/



Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setwindowtitle("Using QStatusbar")
                setGeometry(100,100,400,400)

                status1 = new qstatusbar(win1) {
                        showmessage("Ready!",0)
                }

                setstatusbar(status1)
                show()
        }

        exec()
}
