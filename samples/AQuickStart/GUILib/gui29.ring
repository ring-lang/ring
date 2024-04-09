Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {
                setwindowtitle("QCheckBox")
                new qcheckbox(win1) {
                        setGeometry(100,100,150,30)
                        settext("New Customer!")
                        setstatechangedevent("pchange()")
                }
                showMaximized()
        }
        exec()
}

Func pChange

        new qMessageBox(Win1) {
                setWindowTitle("Checkbox")
                settext("State Changed!")
                show()
        }
