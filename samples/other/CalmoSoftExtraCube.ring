# Project : CalmoSoft Extra Cube
# Date    : 30/11/2019-11:55:00
# Update  : 30/11/2019-11:56:30
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : quiwox@gmail.com

load "stdlib.ring"
load "guilib.ring"

size = 10
C_ROWCOUNT = 10
C_COLCOUNT = 10
C_SPACING = 5
C_EMPTYBUTTONSTYLE =  'border-radius:17px;background-color:silver'
C_BUTTONVIOLETSTYLE = 'border-radius:17px;color:black; background-color: violet'
C_BUTTONBLUESTYLE = 'border-radius:17px;color:black; background-color: blue'
C_BUTTONORANGESTYLE = 'border-radius:17px;color:black; background-color: orange'
btn1 = newlist(C_ROWCOUNT,C_COLCOUNT)
btn2 = newlist(C_ROWCOUNT,C_COLCOUNT)
button1 = newlist(C_ROWCOUNT,C_COLCOUNT)
button2 = newlist(C_ROWCOUNT,C_COLCOUNT)
tableind = null
extracube = []
LayoutButtonRow = list(C_ROWCOUNT)

app = new qApp {
         StyleFusion()
         win = new qWidget() {
                  setWindowTitle('CalmoSoft Extra Cube')
                  move(550,140)
                  resize(600,600)
                  setstylesheet('background-color:white')
                  LayoutButtonMain = new QVBoxLayout()
                  LayoutButtonMain.setSpacing(C_SPACING)
                  LayoutButtonMain.setContentsmargins(0,0,0,0)
                  for Row = 1 to C_ROWCOUNT
                       LayoutButtonRow[Row] = new QHBoxLayout() {
                       setSpacing(C_SPACING)
                       setContentsmargins(0,0,0,0)
                       }
                       for Col = 1 to C_COLCOUNT
                            button1[Row][Col] = new QPushButton(win) {
                            setstylesheet(C_EMPTYBUTTONSTYLE)
                            setclickevent("pplay(" + string(Row) + "," + string(Col) + ")")
                            setSizePolicy(1,1)
                            }
                            LayoutButtonRow[Row].AddWidget(button1[Row][Col])
                       next
                       LayoutButtonMain.AddLayout(LayoutButtonRow[Row])
                  next
                  setLayout(LayoutButtonMain)
                  show()
         }

         win2 = new qWidget() {
                  setWindowTitle('CalmoSoft Extra Cube')
                  move(1200,140)
                  resize(600,600)
                  setstylesheet('background-color:white')
                  LayoutButtonMain = new QVBoxLayout()
                  LayoutButtonMain.setSpacing(C_SPACING)
                  LayoutButtonMain.setContentsmargins(0,0,0,0)
                  for Row = 1 to C_ROWCOUNT
                       LayoutButtonRow[Row] = new QHBoxLayout() {
                       setSpacing(C_SPACING)
                       setContentsmargins(0,0,0,0)
                       }
                       for Col = 1 to C_COLCOUNT
                            button2[Row][Col] = new QPushButton(win2) {
                            setstylesheet(C_EMPTYBUTTONSTYLE)
                            setclickevent("pplay(" + string(Row) + "," + string(Col) + ")")
                            setSizePolicy(1,1)
                            }
                            LayoutButtonRow[Row].AddWidget(button2[Row][Col])
                       next
                       LayoutButtonMain.AddLayout(LayoutButtonRow[Row])
                  next
                  setLayout(LayoutButtonMain)
                  show()
         }
         pbegin()
         exec()


         }

func pplay(n,m)
     if tableind = 1
        if extracube[1] = n and extracube[2] = m and btn1[n][m] = 1
           button1[n][m].setstylesheet(C_BUTTONVIOLETSTYLE)
           msgbox("You win!",1)
        else
           msgbox("Failed!",0)
        ok
     else
        if extracube[1] = n and extracube[2] = m and btn2[n][m] = 1
           button2[n][m].setstylesheet(C_BUTTONVIOLETSTYLE)
           msgbox("You win!",1)
        else
           msgbox("Failed!",0)
        ok
     ok

func pbegin()
       max = 0

       for n = 1 to size
           for m = 1 to size
               button1[n][m].setstylesheet(C_EMPTYBUTTONSTYLE)
               button2[n][m].setstylesheet(C_EMPTYBUTTONSTYLE)
           next
       next

       for n = 1 to size
            for m = 1 to size
                 max = max + 1
                 rnd1 = random(size-1) + 1
                 rnd2 = random(size-1) + 1
                 btn1[rnd1][rnd2] = 1
                 btn2[rnd1][rnd2] = 1
                 button1[rnd1][rnd2] { setstylesheet(C_BUTTONORANGESTYLE)
                                       button1[n][m].setenabled(true)
                                       win.show() }
                 button2[rnd1][rnd2] { setstylesheet(C_BUTTONBLUESTYLE)
                                       button1[n][m].setenabled(true)
                                       win2.show() }
                 if max = (size*size)/2
                    exit 2
                 ok
            next
       next
       tableind = random(1) + 1
       for n = 1 to size
            for m = 1 to size
                 rnd1 = random(size-1) + 1
                 rnd2 = random(size-1) + 1
                 if tableind = 1
                    if btn1[rnd1][rnd2] = 0
                       btn1[rnd1][rnd2] = 1
                       button1[rnd1][rnd2].setstylesheet(C_BUTTONORANGESTYLE)
                       extracube = [rnd1,rnd2]
                       exit 2
                    ok
                 else
                    if btn2[rnd1][rnd2] = 0
                       btn2[rnd1][rnd2] = 1
                       button2[rnd1][rnd2].setstylesheet(C_BUTTONBLUESTYLE)
                       extracube = [rnd1,rnd2]
                       exit 2
                    ok
                 ok
            next
       next 
       for n = 1 to size
            for m = 1 to size
                if btn1[n][m] = 0
                   button1[n][m].setenabled(false)
                ok
                if btn2[n][m] = 0
                   button2[n][m].setenabled(false)
                ok
            next
       next

func msgBox(cText,begin) 
	mb = new qMessageBox(win) {
	        setWindowTitle('Extra Cube')
	        setText(cText)
                setstandardbuttons(QMessageBox_OK) 
                result = exec()
                if begin = 1
                   pbegin() 
                else
                   return
                ok
        }
