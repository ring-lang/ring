# Project : Memory Game
# Date    : 2018/09/05
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 8
limit = 5
buttonold = newlist(size,size)
buttonnew = newlist(size,size)
LayoutButtonRow = list(size)

app = new qApp {
          StyleFusion()
          processevents()
          win = new qWidget() {
                  setWindowTitle('Memory Game')
                  setgeometry(100,100,300,300)
                  setminimumwidth(300)
                  setminimumheight(300)
                  setstylesheet('background-color:white')
                  move(490,100) 
                  winwidth = win.width()
                  winheight = win.height()
                  for n = 1 to size
                       for m = 1 to size
                            fontsize = 10 + (winheight/25)
                            buttonold[n][m] = new QPushButton(win) {
                                                       setFont(new qFont("Verdana",fontsize,100,0))
                                                       setstylesheet('background-color:gray')
                                                       setclickevent("pplay(" + string(n) + "," + string(m) + ")")
                                                       }
                       next
                  next
                  for n = 1 to size
                       for m = 1 to size
                            buttonnew[n][m] = new QPushButton(win)
                            buttonnew[n][m] = 0
                       next
                  next
                  for n = 1 to size
		       LayoutButtonRow[n] = new QHBoxLayout() {
                                                        setSpacing(3) }
                  next
                  for n = 1 to size
                       for m = 1 to size
                            LayoutButtonRow[n].AddWidget(buttonold[m][n])
                       next
                  next
                  LayoutButtonMain = new QVBoxLayout() {
                                               setSpacing(3)
                                               for n = 1 to size
                                                    AddLayout(LayoutButtonRow[n])
                                               next }
		  win.setLayout(LayoutButtonMain)
                  pbegin()  
                  show()
         }
    exec()
}

func pbegin() 
       for n = 1 to limit
            rx = random(size-1)+1
            ry = random(size-1)+1
            buttonnew[rx][ry] = 1
       next
       for n = 1 to size
            for m = 1 to size
                 if buttonnew[n][m] = 1
                    see "n = " + n + " m = " + m + nl
                    buttonold[n][m] {setstylesheet('background-color:orange')}
                                             //show()}
                 ok
             next
        next
        sleep(2)
        for n = 1 to size
             for m = 1 to size
                  if buttonnew[n][m] = 1
                     buttonold[n][m] {setstylesheet('background-color:gray')}
                  ok
              next
         next

func pplay(n,m) 
       if buttonnew[n][m] = 1
          buttonold[n][m] {setstylesheet('background-color:orange')}
       ok
