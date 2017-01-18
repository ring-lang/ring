// author : CalmoSoft

load "guilib.ring"
app1 = new qapp {

        temp = ""
        button = list(12)   
 
        win1 = new qwidget() {
                   move(0,0)
                   resize(340, 380)
                   setwindowtitle("Calmosoft Dial")

                   for n = 1 to 9
                         col = n%3
                         if col = 0 col = 3 ok
                         row = ceil(n/3)
                         button[n] = new qpushbutton(win1)
                         {
                                            setgeometry(60+col*40,60+row*40,40,40)
                                            settext(string(n))
                                            setclickevent("ringnr(" + string(n) +")")   
                          } 
                  next

                  button[10] = new qpushbutton(win1)
                  {
                                       setgeometry(140, 220, 40, 40)
                                       settext(string(0))
                                       setclickevent("ringnr(" + string(0) +")")   
                    }

                    button[11] = new qpushbutton(win1)
                    {
                                         setgeometry(100, 220, 40, 40)
                                         settext("Clear")
                                         setclickevent("clearnr()")   
                     }

                     button[12] = new qpushbutton(win1)
                    {
                                          setgeometry(180, 220, 40, 40)
                                          settext("Dial")
                                          setclickevent("dial()")   
                     }

                     label = new qpushbutton(win1)
                     {
                                        setgeometry(100, 60, 120, 40)
                                        settext("")
                      } 
 
                   show()
        }
        exec()
}

func sleep x
       nTime = x * 1000
       oTest = new qTest
       oTest.qsleep(nTime)
return

func ringnr(dialnr)
        label{ temp = text() }
        label.settext(temp + string(dialnr))
return

func dial()
        button[12].settext("Ring")
        label{ temp = text() }
        label.settext("")
        for n=1 to len(temp)
              temp2 = substr(temp, n, 1)
              label{ temp3 = text() } 
              label.settext(temp3 + temp2)
              see temp3 + temp2 + nl
        next
return

func clearnr()
        label.settext("")
        button[12].settext("Dial")
return
