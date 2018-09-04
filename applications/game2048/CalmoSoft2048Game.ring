# Project : 2048 Game
# Date    : 2018/09/03
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 4
limit = 2
num = 0
flag = 0
x1 = 0
x2 = 0
y1 = 0
y2 = 0
nScore = 0
button = newlist(size,size)
buttonsave = newlist(size,size)
LayoutButtonRow = list(size+2)
moveleft = []
moveright = []
moveup = []
movedown = []
myfilter2 = null
myfilter3 = null
winheight = 0
winwidth = 0

app = new qApp {
          StyleFusion()
          processevents()
          win = new qWidget() {
                  setWindowTitle('2048 Game')
                  setgeometry(100,100,550,700)
                  setminimumwidth(300)
                  setminimumheight(300)
                  grabkeyboard()
                  setstylesheet('background-color:white')
                  move(490,100) 
                  for n = 1 to size
                       for m = 1 to size
                            button[n][m] = new MyButton(win)
                       next
                  next
                  newgame = new qLabel(win)
                  playerscore = new qLabel(win)
                  myfilter3 = new qAllEvents(win) {
                  setMouseButtonPressEvent("pPress()")
                  setMouseButtonReleaseEvent("pRelease()")}
                  installeventfilter(myfilter3)
                  myfilter2 = new qAllEvents(win) {
                  setkeypressevent("keypress()") }
                  installeventfilter(myfilter2)
                  winwidth = win.width()
                  winheight = win.height()
                  for n = 1 to size + 2
		       LayoutButtonRow[n] = new QHBoxLayout() {
                                                        setSpacing(3) }
                  next
                  for n = 1 to size
                       for m = 1 to size
                            button[n][m] { temp = text() }
                            buttonsave[n][m] = temp
                            buttonsave[n][m] = temp
                            fontsize = 10 + (winheight/25)
                            fontsize2 = 10 + (winheight/50)
                            button[n][m] = new MyButton(win) {
                                                   setFont(new qFont("Verdana",fontsize,100,0))
                                                   setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                                   setstylesheet('background-color:orange')
                                                   show()
                                                   }
                       next
                  next
                  for n = 1 to size
                       for m = 1 to size
                            LayoutButtonRow[n].AddWidget(button[m][n])
                            win.show()
                            temp = buttonsave[n][m]
                            button[n][m].settext(temp)
                       next
                  next
                  playerscore.close()
                  playerscore {
                                    setGeometry(0,4*floor(winheight/6),winwidth,floor(winheight/6))
                                    setFont(new qFont("Verdana",fontsize2,100,0))
                                    setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                    settext('Play Score: ' + nScore)
                                    show()
                                    }

                  newgame.close()
                  newgame  {
                                  setGeometry(0,5*floor(winheight/6),winwidth,floor(winheight/6))
                                  setFont(new qFont("Verdana",fontsize2,100,0))
                                  setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                  setstylesheet('background-color:violet')
                                  settext('New Game')
                                  myfilter4 = new qallevents(newgame)
                                  myfilter4.setMouseButtonPressEvent("pbegin()")
                                  installeventfilter(myfilter4)
                                  show()
                                  }
                  LayoutButtonRow[size+1].AddWidget(playerscore)
                  LayoutButtonRow[size+2].AddWidget(newgame)
                  LayoutButtonMain = new QVBoxLayout() {
                                               setSpacing(3)
                                               for n = 1 to size+2
                                                    AddLayout(LayoutButtonRow[n])
                                                    win.show()
                                               next }
		  win.setLayout(LayoutButtonMain)
                  win.show()
                  pbegin()  
                  show()
         }
    exec()
}

func pPress()
        x1 = myfilter3.getglobalx()
        y1 = myfilter3.getglobaly()
 
func pRelease()
        x2 = myfilter3.getglobalx()
        y2 = myfilter3.getglobaly()
        xx1 = floor(x1/floor(winwidth/4)) - 2
        xx2 = floor(x2/floor(winwidth/4)) - 2
        yy1 = floor(y1/floor(winheight/6)) - 1
        yy2 = floor(y2/floor(winheight/6)) - 1
        bool = (yy1 <= size) and (yy2 <= size)
        if (yy1 = yy2) and (xx2 < xx1) and bool
           pleft()
        ok
        if (yy1 = yy2) and (xx1 < xx2) and bool
           pright()
        ok
        if (xx1 = xx2) and (yy2 < yy1) and bool
           pup()
        ok
        if (xx1 = xx2) and (yy1 < yy2) and bool
           pdown()
        ok

func keypress() 
        nKey = myfilter2.getkeycode() 
        switch nKey
                   on 16777234 pleft()
                   on 16777236 pright()
                   on 16777235 pup()
                   on 16777237 pdown()
        off

func pbegin()
       numbers = [['2','2'],['2','4']]
       randnew = newlist(2,2)
       for n = 1 to size
            for m = 1 to size
                 button[n][m].setStylesheet('background-color: orange')
                 button[n][m].settext('')
            next
        next
        while true
                rn1 = random(size - 1) + 1
                rm1 = random(size - 1) + 1
                rn2 = random(size - 1) + 1
                rm2 = random(size - 1) + 1
                bool = (rn1 = rn2) and (rm1 = rm2)
                if not bool
                   exit
                ok
        end
        rand = random(limit - 1) + 1
        button[rn1][rm1].settext(numbers[rand][1])
        button[rn2][rm2].settext(numbers[rand][2])
        nScore = 0
        playerscore.settext('Play Score: ')

func pdown()
        num = gameover()
        if num = size*size
           flag = 1
           msgBox('You lost!')
           pbegin()
        ok
        if flag = 0
           pmovedown()
           sleep(0.5)
           newnum()
        ok

func pup()
        num = gameover()
        if num = size*size
           flag = 1
           msgBox('You lost!')
           pbegin()
        ok
        if flag = 0
           pmoveup()
           sleep(0.5)
           newnum()
        ok

func pleft()
        num = gameover()
        if num = size*size
           flag = 1
           msgBox('You lost!')
           pbegin()
        ok
        if flag = 0
           pmoveleft()
           sleep(0.5)
           newnum()
        ok

func pright()
        num = gameover()
        if num = size*size
           flag = 1
           msgBox('You lost!')
           pbegin()
        ok
        if flag = 0
           pmoveright()
           sleep(0.5)
           newnum()
        ok

func pmoveleft()
       for n = 1 to size
            moveleft = []
            for m = 1 to size
                 button[m][n] {temp = text()}
                 if temp != ''
                    add(moveleft,temp)
                 ok
            next
            movetilesleft(n,moveleft)
       next

func movetilesleft(nr,moveleft)
       for p = 1 to len(moveleft) - 1
            temp1 = moveleft[p]
            temp2 = moveleft[p+1]
            temp = string(number(temp1) + number(temp2))
            if (temp1 = temp2) and (temp1 != '0') and (temp2 != '0') and (temp1 != '') and (temp2 != '')
               if temp != '0' and temp != ''
                  nScore = nScore + temp
                  playerscore.settext('Play Score: ' + nScore)
                  flag = 1
                  moveleft[p] = temp
                  del(moveleft,p+1)
               ok
            ok
       next
       for n = 1 to len(moveleft)
            button[n][nr].settext(moveleft[n])
       next
       for n = len(moveleft) + 1 to size 
            if n <= size
               button[n][nr].setStylesheet('background-color: orange')
               button[n][nr].settext('')
            ok
       next
       return

func pmoveright()
       for n = 1 to size
            moveright = []
            for m = size to 1 step -1
                 button[m][n] {temp = text()}
                 if temp != ''
                    add(moveright,temp)
                 ok
            next
            movetilesright(n,moveright)
        next
        return

func movetilesright(nr,moveright)
       flag = 0
       for p = 2 to len(moveright)
            temp1 = moveright[p]
            temp2 = moveright[p-1]
             if (temp1 = temp2) and (temp1 != '0') and (temp2 != '0') and (temp1 != '') and (temp2 != '')
               temp = string(number(temp1) + number(temp2))
               if temp != '0' and temp != ''
                  nScore = nScore + temp
                  playerscore.settext('Play Score: ' + nScore)
                  flag = 1
                  moveright[p] = temp
                  del(moveright,p-1)
               ok
            ok
       next
       for n = 1 to len(moveright)
            button[size-n+1][nr].settext(moveright[n])
       next
       for n = 1 to size - len(moveright)
            if n <= size
               button[n][nr].setStylesheet('background-color: orange')
               button[n][nr].settext('')
            ok
       next

func pmoveup()
       for n = 1 to size
            moveup = []
            for m = 1 to size
                 button[n][m] {temp = text()}
                 if temp != ''
                    add(moveup,temp)
                 ok
            next
            movetilesup(n,moveup)
        next
        return

func movetilesup(nr,moveup)
        flag = 0
        for p = 1 to len(moveup) - 1
             temp1 = moveup[p] 
             temp2 = moveup[p+1]
             if (temp1 = temp2) and (temp1 != '0') and (temp2 != '0') and (temp1 != '') and (temp2 != '')
               temp = string(number(temp1) + number(temp2))
               if temp != '0' and temp != ''
                  nScore = nScore + temp
                  playerscore.settext('Play Score: ' + nScore)
                  flag = 1
                  moveup[p] = temp
                  del(moveup,p+1)
               ok
            ok
       next
       for n = 1 to len(moveup)
            button[nr][n].settext(moveup[n])
       next
       for n = len(moveup) + 1 to size 
            if n <= size
               button[nr][n].setStylesheet('background-color: orange')
               button[nr][n].settext('')
            ok
       next

func pmovedown()
       for n = 1 to size
            movedown = []
            for m = size to 1 step -1
                 button[n][m] {temp = text()}
                 if temp != ''
                    add(movedown,temp)
                 ok
            next
            movetilesdown(n,movedown)
        next
        return

func movetilesdown(nr,movedown)
        flag = 0
        for p = 1 to len(movedown) - 1
             temp1 = movedown[p]
             temp2 = movedown[p+1]
             if (temp1 = temp2) and (temp1 != '0') and (temp2 != '0') and (temp1 != '') and (temp2 != '')
               temp = string(number(temp1) + number(temp2))
               if temp != '0' and temp != ''
                  nScore = nScore + temp
                  playerscore.settext('Play Score: ' + nScore)
                  flag = 1
                  movedown[p] = temp
                  del(movedown,p+1)
               ok
            ok
       next
       for n = 1 to len(movedown)
            button[nr][size-n+1].settext(movedown[n])
       next
       for n = size - len(movedown) to 1 step -1 
            if n <= size
               button[nr][n].setStylesheet('background-color: orange')
               app.processevents()
               button[nr][n].settext('')
            ok
       next

func newnum()
        while true
                rn = random(size - 1) + 1
                rm = random(size - 1) + 1
                if button[rn][rm].text() = ''
                   button[rn][rm].settext('2')
                   exit
                ok
        end
        return

func gameover()
        num = 0
        flag = 0
        for n = 1 to size
             for m = 1 to size 
                  if button[n][m].text() != ''
                     num = num + 1
                  ok
              next
        next
        return num

func msgBox(text) {
	m = new qMessageBox(win) {
	       setWindowTitle('2048 Game')
	       setText(text)
	       show()
	       }
        }

func showarray(vect)
        see "["
        svect = ""
        for n = 1 to len(vect)
              svect = svect + vect[n] + " "
        next
        svect = left(svect, len(svect) - 1)
        see svect
        see "]" + nl

class MyButton from qLabel
       func setText(cValue)
              Super.setText(cValue)
              switch cValue 
                        on '2' setStyleSheet('foreground-color:blue; background-color: yellow')
                        on '4' setStylesheet('foreground-color:white; background-color: violet')
                        on '8' setStylesheet('foreground-color:white; background-color: blue')
                        on '16' setStylesheet('foreground-color:black; background-color: green')
                        on '32' setStylesheet('foreground-color:white; background-color: red')
                        on '64' setStylesheet('foreground-color:white; background-color: gray')
                        on '128' setStylesheet('foreground-color:violet; background-color: white')
              off
