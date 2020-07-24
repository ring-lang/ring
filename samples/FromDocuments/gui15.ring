Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {
                setGeometry(100,100,450,260)
                setwindowtitle("Using QSpinBox")
                        new qspinbox(win1) {
                                setGeometry(50,100,350,30)
                                setvalue(50)
                        }
                show()
        }
        exec()
}
