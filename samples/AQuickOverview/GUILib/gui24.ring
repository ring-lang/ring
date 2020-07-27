Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {
                setwindowtitle("Using QFrame")
                for x = 0 to 10
                        frame1 = new qframe(win1,0) {
                                setGeometry(100,20+50*x,400,30)
                                setframestyle(QFrame_Raised | QFrame_WinPanel)
                        }
                next
                showMaximized()
        }
        exec()
}
