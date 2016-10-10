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
	myobj = new qcolordialog() { 
		r = exec()		
		if r = 0 return ok
		oColor = currentcolor()
		r = oColor.red()
		g = oColor.green()
		b = oColor.blue()
	}	
             win1.setstylesheet("background-color: rgb("+r+", " + g+ "," + b + ")")
