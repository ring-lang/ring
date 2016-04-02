Load "guilib.ring"

New MyWindow()

new qApp { exec() }

class mywindow from qwidget
        Func init
                super.init()
                setwindowtitle("First Window")
                setgeometry(100,100,400,400)
                setstylesheet("background-color: purple;")
                settooltip("my first window!")
                show()
