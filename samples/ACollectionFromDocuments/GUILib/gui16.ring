Load "guilib.ring"

New qApp {

        win1 = new qMainWindow() {

                setGeometry(100,100,500,400)
                setwindowtitle("Using QSlider")

                new qslider(win1) {
                        setGeometry(100,100,50,130)
                        settickinterval(50)
                }

                new qslider(win1) {
                        setGeometry(100,250,250,30)
                        settickinterval(50)
                        setorientation(Qt_Horizontal)
                }

                show()

        }

        exec()
}
