# Project : CalmoSoft Telephone
# Author: Gal Zsolt (~ CalmoSoft ~)

load "guilib.ring"
load "stdlib.ring"

app1 = new qapp {

        temp = ""
        temp1 = ""
        button = list(12)   
        CounterMan = 0
 
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

                   tel = new qpushbutton(win1)
                   {
                                  setgeometry(100, 60, 120, 40)
                                  settext("")
                   } 

                   TimerMan = new qtimer(win1)
                   {
                                     setinterval(0.2)
                                     settimeoutevent("pTime()")
                                     stop()
                   }
                    show()
        }
        exec()
}

func ringnr(dialnr)
        tel{temp = text()}
        tel.settext(temp + string(dialnr))
        see char(7)
return

func dial()
        tel{temp = text()}
        clearnr()
        CounterMan = 0
        temp1 = ""
        TimerMan.start()

func pTime()
        CounterMan++
        pPlaySleep()
        sleep(0.2) 
        if CounterMan = len(temp)
            TimerMan.stop()
        ok

func pPlaySleep
       temp2 = substr(temp, CounterMan, 1)
       temp1 = temp1 + temp2
       tel.settext(temp1)
       see char(7)
return

func clearnr()
        tel.settext("")
return
