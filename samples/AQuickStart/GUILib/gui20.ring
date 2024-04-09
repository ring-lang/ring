Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {
                setwindowtitle("Using QCheckBox")
                new qcheckbox(win1) {
                        setGeometry(100,100,150,30)
                        settext("New Customer!")
                }
                showMaximized()
        }
        exec()
}
