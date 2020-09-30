Load "guilib.ring"

New QApp {

        Win1 = New QWidget () {

                SetGeometry(100,100,400,400)
                SetWindowTitle("Input Dialog")

                New QPushButton(win1)
                {

                        SetText ("Input Dialog")
                        SetGeometry(100,100,100,30)
                        SetClickEvent("pWork()")
                }

                Show()
        }

        exec()
}

Func pWork
        oInput = New QInputDialog(win1)
        {
                setwindowtitle("What is your name?")
                setgeometry(100,100,400,50)
                setlabeltext("User Name")
                settextvalue("Mahmoud")
                lcheck = exec()
                if lCheck win1.setwindowtitle(oInput.textvalue()) ok
        }
