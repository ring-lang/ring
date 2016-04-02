Load "guilib.ring"

new qApp {
        win1 = new qWidget()
        {
                label1 = new qpushbutton(win1)
                {
                        setText("Test")
                        setgeometry(10,10,200,50)
                        setstylesheet("color: purple ; font-size: 30pt;")
                        setclickevent("pWork()")
                }
                setWindowTitle("Messagebox")
                setgeometry(100,100,600,80)
                setStyleSheet("background-color: white;")
                show()
        }
        exec()
}

func pWork
        new qmessagebox(win1)
        {
                setwindowtitle("messagebox title")
                settext("messagebox text")
                setInformativeText("Do you want to save your changes?")
                setstandardbuttons(QMessageBox_Yes | QMessageBox_No | QMessageBox_Close)
                result = exec()
                win1 {
                        if result = QMessageBox_Yes
                                setwindowtitle("Yes")
                        but result = QMessageBox_No
                                setwindowtitle("No")
                        but result = QMessageBox_Close
                                setwindowtitle("Close")
                        ok
                }
        }
