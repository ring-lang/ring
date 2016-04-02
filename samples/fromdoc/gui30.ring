Load "guilib.ring"

new qApp {
        win1 = new qwidget() {
                setgeometry(100,100,200,70)
                setwindowtitle("Timer")
                label1 = new qlabel(win1) {
                        setgeometry(10,10,200,30)
                        settext(thetime())
                }
                new qtimer(win1) {
                        setinterval(1000)
                        settimeoutevent("pTime()")
                        start()
                }
                show()
        }
        exec()
}

func ptime
        label1.settext(thetime())

Func thetime
        return "Time : " + Time()
