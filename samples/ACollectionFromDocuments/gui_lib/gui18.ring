Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {
                setGeometry(100,100,450,500)
                setwindowtitle("Using QDial")
                new qdial(win1) {
                        setGeometry(100,100,250,300)
                }
                show()
        }
        exec()
}
