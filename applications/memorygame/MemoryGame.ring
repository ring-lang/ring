# Project : Memory Game
# Date    : 2018/09/07
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlibcore.ring"
load "lightguilib.ring"

size = 8
limit = 5
nScore = 0
bsumold = 0
bsumnew = 1
buttonold = list(size,size)
buttonnew = list(size,size)
LayoutButtonRow = list(size)
winwidth = 0
winheight = 0

app = new qApp {
          StyleFusion()
          processevents()
          win = new qWidget() {
		  setWinIcon(self,"memory.png")
                  setWindowTitle('Memory Game')
                  setgeometry(100,100,600,600)
                  setminimumwidth(300)
                  setminimumheight(300)
                  move(490,100) 
                  winwidth = win.width()
                  winheight = win.height()
                  setstylesheet('background-color:white')
                  fontsize = 10 + (winheight/25)
                  fontsize2 = 8 + (winheight/70)
                  for n = 1 to size
                       for m = 1 to size
                            buttonold[n][m] = new QPushButton(win) {
                                                       setFont(new qFont("Verdana",fontsize,100,0))
                                                       setstylesheet('background-color:gray')
                                                       setclickevent("pplay(" + string(n) + "," + string(m) + ")")
							setSizePolicy(1,1)
                                                       }
                       next
                  next
                  for n = 1 to size
                       for m = 1 to size
                            buttonnew[n][m] = 0
                       next
                  next
                  for n = 1 to size
		       LayoutButtonRow[n] = new QHBoxLayout() 
                  next
                  for n = 1 to size
                       for m = 1 to size
                            LayoutButtonRow[n].AddWidget(buttonold[m][n])
                            win.show()
                       next
                  next
                  playerscore = new QLabel(win) {
                                      //setGeometry(0,8*floor(winheight/10),winwidth,floor(winheight/10))
                                      setFont(new qFont("Verdana",fontsize2,100,0))
                                      setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                      settext("Play Score:")
                                      show()
                                      }
                  newgame  = new QPushButton(win) {
                                     //setGeometry(0,9*floor(winheight/10),winwidth,floor(winheight/10))
                                     setFont(new qFont("Verdana",fontsize2,100,0))
                                     setstylesheet("background-color:violet")
                                     settext("New Game")
                                     setclickevent("pbegin()")
                                     show()
                                     }
                  LayoutButtonMain = new QVBoxLayout() {
                                               for n = 1 to size
                                                    AddLayout(LayoutButtonRow[n])
                                               next
                                               AddWidget(playerscore)
                                               AddWidget(newgame)
                                               win.show() }
		  win.setLayout(LayoutButtonMain)
                  win.show()
                  pbegin()  
         }
    exec()
}

func pbegin() 
       nScore = 0
       bsumold = 0
       bsumnew = 0
       playerscore.settext("Play Score:")
       buttonnew = list(size,size)
       for n = 1 to limit
            rx = random(size-1)+1
            ry = random(size-1)+1
            buttonnew[rx][ry] = 1
       next
       for n = 1 to size
            for m = 1 to size
                 buttonold[n][m] {setstylesheet('background-color:gray')
                                          setenabled(true)}
            next
       next
       for n = 1 to size
            for m = 1 to size
                 if buttonnew[n][m] = 1
                    bsumold = bsumold + 1
                    buttonold[n][m].setstylesheet('background-color:orange')
                    buttonold[n][m].show()
                 ok
             next
        next
        see nl
        app.processevents()
        sleep(3)
        for n = 1 to size
             for m = 1 to size
                  if buttonnew[n][m] = 1
                     buttonold[n][m] {setstylesheet('background-color:gray')}
                  ok
              next
         next

func pplay(n,m) 
       if buttonnew[n][m] = 1
          nScore = nScore + 1
          bsumnew = bsumnew + 1
          buttonold[n][m] {setstylesheet('background-color:orange')
                                   setenabled(false)}
          if bsumold = bsumnew and bsumold != 0 and bsumnew != 0
             msgBox("You won!")
          ok
       else
          nScore = nScore - 1
          buttonold[n][m] {setstylesheet('background-color:white')
                                   setenabled(false)}
       ok
       playerscore.settext("Play Score: " + nScore)
       gameover()

func gameover()
       if nScore = -3
          msgBox("Game Over!")
       ok

func msgBox cText 
	mb = new qMessageBox(win) {
	        setWindowTitle('Memory Game')
	        setText(cText)
                setstandardbuttons(QMessageBox_OK) 
                result = exec()
                pbegin() 
        }
