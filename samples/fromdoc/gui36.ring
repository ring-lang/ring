Load "guilib.ring"

oApp = new myapp { start() }

Class MyApp

        oColor  win1

        Func start

                myapp = new qapp

                win1 = new qMainWindow() {
                        setwindowtitle("Color Dialog")
                        setgeometry(100,100,400,400)
                }

                new qpushbutton(win1) {
                        setgeometry(10,10,100,30)
                        settext("Get Color")
                        setclickevent("oApp.pColor()")
                }

                win1.show()
                myapp.exec()


        Func pColor
                myobj = new qcolordialog()
                aColor = myobj.GetColor()
                r=acolor[1] g=acolor[2] b=acolor[3]
                win1.setstylesheet("background-color: rgb("+r+", " + g+ "," + b + ")")
