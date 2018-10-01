# Project : 21 Game
# Author  : Gal Zsolt (CalmoSoft)
 
load "guilib.ring"
 
limit = 21
posold = 0
button = list(limit)
mynum = list(3)
yournum = list(3)
 
new qapp 
        {
        win1 = new qwidget() {
                  setwindowtitle("21 Game")
                  setgeometry(100,100,1000,600)
                  label1 = new qlabel(win1) {
                              setgeometry(10,10,1000,600)
                              settext("")
                  }
 
                  label2 = new qlabel(win1) {
                              setgeometry(240,50,120,40)
                              setAlignment(Qt_AlignHCenter)
                              setFont(new qFont("Verdana",12,100,0))
                              settext("my number:")
                  }
 
                  label3 = new qlabel(win1) {
                              setgeometry(640,50,120,40)
                              setAlignment(Qt_AlignHCenter)
                              setFont(new qFont("Verdana",12,100,0))
                              settext("your number:")
                  }
 
                  for p = 1 to 3
                       mynum[p] = new qpushbutton(win1) {
                                          setgeometry(200+p*40,100,40,40)
                                          setstylesheet("background-color:orange")
                                          settext(string(p))
                                          setclickevent("choose(" + string(p) + ",1)")
                                          }
                   next
 
                   for p = 1 to 3
                        yournum[p] = new qpushbutton(win1) {
                                             setgeometry(600+p*40,100,40,40)
                                             setstylesheet("background-color:white")
                                             settext(string(p))
                                             setclickevent("choose(" + string(p) + ",2)")
                                             }
                   next
 
                   for n = 1 to limit
                        button[n] = new qpushbutton(win1) {
                                          setgeometry(40+n*40,190,40,40)
                                          settext(string(n))
                                          }
                    next
                    show()
        }
        exec()
        }
 
func choose(ch,ym)
        pos = posold + ch
        if pos > limit
           msg = "You must choose number from 1 to " + string(limit - posold)
           msgBox(msg)
           for n = 1 to 3
                mynum[n].setenabled(false)
                yournum[n].setenabled(false)
           next
           return
        ok
        for n = posold+1 to pos
             if ym = 1
                button[n] { setstylesheet("background-color:orange") }
             else
                button[n] { setstylesheet("background-color:white") }
             ok
        next
        posold = pos
        if ym = 1
           for n = 1 to 3
                mynum[n].setenabled(false)
                yournum[n].setenabled(true)
           next
         else
           for n = 1 to 3
                mynum[n].setenabled(true)
                yournum[n].setenabled(false)
           next
         ok
         if pos = 21
            if ym = 1
               msgBox("I won!")
            else
               msgBox("You won!")
            ok
         ok
 
func msgBox(text) {
	m = new qMessageBox(win1) {
	       setWindowTitle("21 Game")
	       setText(text)
	       show()
	       }
        }
