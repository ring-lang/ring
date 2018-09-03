# Project : 2048 Game
# Date    : 2018/08/25
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>


load "stdlib.ring"
load "guilib.ring"

size = 4
limit = 6
flag = 0
nn = 0
mm = 0
num = [2,4,8,16,32,64]
button = newlist(size,size)
mdown = list(size)
mup = list(size)
mleft = list(size)
mright = list(size)
moveleft = []
moveright = []
moveup = []
movedown = []

app = new qApp {
          StyleFusion()
          win = new qWidget() {
                  setWindowTitle("2048 Game")
                  move(490,100) 
                  resize(450,500)
                  for n = 1 to size
                       for m = 1 to size
                            col = 100 + n*40
                            row = 100 + m*40
                            button[n][m] = new MyButton(win) {
                                                   setGeometry(col,row,40,40)
                                                   setstylesheet("forground-color:white; background-color:orange")
                                                   setClickEvent("keypress(" + string(n) + "," + string(m) + ")")
                                                   }
                        next
                  next
                  newgame = new qPushButton(win) {
                                    setGeometry(180,380,80,40)
                                    settext("New Game")
                                    setClickEvent("pbegin()")
                                    }
                  for nm = 1 to size
                       mdown[nm] = new qPushButton(win) {
                                            setGeometry(100+nm*40,100,40,40)
                                            settext("down")
                                            setClickEvent("pdown()")
                                            }
                  next
                  for um = 1 to size
                       mup[um] = new qPushButton(win) {
                                         setGeometry(100+um*40,300,40,40)
                                         settext("up")
                                         setClickEvent("pup()")
                                         }
                  next
                  for lm = 1 to size
                       mup[lm] = new qPushButton(win) {
                                        setGeometry(100,100+lm*40,40,40)
                                        settext("<<<")
                                        setClickEvent("pleft()")
                                        }
                  next
                  for rm = 1 to size
                       mright[rm] = new qPushButton(win) {
                                           setGeometry(300,100+rm*40,40,40)
                                           settext(">>>")
                                           setClickEvent("pright()")
                                           }
                  next
                  pbegin()
           show()
         }
    exec()
}

func keypress(np,mp)
       flag = 1
       nn = np
       mm = mp

func pbegin()
       for n = 1 to size
            for m = 1 to size
                 button[n][m].setStylesheet("background-color: orange")
                 button[n][m].settext("")
            next
        next
        for n = 1 to limit
             rn = random(size - 1) + 1
             rm = random(size - 1) + 1
             ran = random(limit - 1) + 1
             button[rn][rm].settext(string(num[ran]))
         next

func pdown()
       if flag = 0
          return
       ok
       button[nn][mm] {temp = text()}
       if temp = ""
          pmovedown()
          return
       ok
       if mm = 4
          msgBox("bad move")
          return
       ok
       for m = mm + 1 to size 
            button[nn][m] {move = text()}
            if move != ""
               button[nn][mm] {temp = text()}
               if move = temp
                  res = string(number(move) + number(temp))
                  button[nn][m].settext(res)
                  setStylesheet("background-color: orange")
                  button[nn][mm].settext("")
                  exit
               ok
            ok
       next

func pup()
       if flag = 0
          return
       ok
       button[nn][mm] {temp = text()}
       if temp = ""
          pmoveup()
          return
       ok
       if mm = 1
          msgBox("bad move")
          return
       ok
       for m = mm - 1 to 1 step -1
            button[nn][m] {move = text()}
            if move != ""
               button[nn][mm] {temp = text()}
               if move = temp
                  res = string(number(move) + number(temp))
                  button[nn][m].settext(res)
                  setStylesheet("background-color: orange")
                  button[nn][mm].settext("")
                  newnum()
                  exit
               ok
            ok
       next

func pleft()
       if flag = 0
          return
       ok
       button[nn][mm] {temp = text()}
       if temp = ""
          pmoveleft()
          return
       ok
       if nn = 1 and temp != ""
          msgBox("bad move")
          return
       ok
       for n = mm - 1 to 1 step -1
            button[n][mm] {move = text()}
            if move != ""
               button[nn][mm] {temp = text()}
               if move = temp
                  res = string(number(move) + number(temp))
                  button[n][mm].settext(res)
                  setStylesheet("background-color: orange")
                  button[nn][mm].settext("")
                  exit
               ok
            ok
       next

func pright()
       if flag = 0
          return
       ok
       button[nn][mm] {temp = text()}
       if temp = ""
          pmoveright()
          return
       ok
       if nn = 4
          msgBox("bad move")
          return
       ok
       for n = nn + 1 to size 
            button[n][mm] {move = text()}
            if move != ""
               button[nn][mm] {temp = text()}
               if move = temp
                  res = string(number(move) + number(temp))
                  button[n][mm].settext(res)
                  setStylesheet("background-color: orange")
                  button[nn][mm].settext("")
                  exit
               ok
            ok
       next

func newnum()
        nums = [2,4]
        while true
                rn = random(size - 1) + 1
                rm = random(size - 1) + 1
                ran = random(len(nums) - 1) + 1
                if button[rn][rm].text() = ""
                   button[rn][rm].settext(string(nums[ran]))
                   exit
                ok
        end

func pmoveleft()
       for n = 1 to size
            moveleft = []
            for m = 1 to size
                 button[m][n] {temp = text()}
                 if temp != ""
                    add(moveleft,temp)
                 ok
            next
            movetilesleft(n,moveleft)
        next
        newnum()
        return

func movetilesleft(nr,moveleft)
       for p = 1 to len(moveleft) - 1
            button[p][nr] {temp1 = text()}
            button[p+1][nr] {temp2 = text()}
            if temp1 = temp2
               temp = string(number(temp1) + number(temp2))
               if temp != "0"
                  moveleft[p] = temp
                  del(moveleft,p+1)
                  exit
               ok
            ok
       next
       for n = 1 to len(moveleft)
            button[n][nr].settext(moveleft[n])
       next
       for n = len(moveleft) + 1 to size 
            if n <= size
               button[n][nr].setStylesheet("background-color: orange")
               button[n][nr].settext("")
            ok
       next

func pmoveright()
       for n = 1 to size
            moveright = []
            for m = size to 1 step -1
                 button[m][n] {temp = text()}
                 if temp != ""
                    add(moveright,temp)
                 ok
            next
            movetilesright(n,moveright)
        next
        newnum()
        return

func movetilesright(nr,moveright)
       for p = len(moveright) - 1 to 1 step -1
            button[p][nr] {temp1 = text()}
            button[p+1][nr] {temp2 = text()}
            if temp1 = temp2
               temp = string(number(temp1) + number(temp2))
               if temp != "0"
                  moveright[p] = temp
                  del(moveright,p+1)
                  exit
               ok
            ok
       next
       for n = 1 to len(moveright)
            button[size-n+1][nr].settext(moveright[n])
       next
       for n = 1 to size - len(moveright)
            if n <= size
               button[n][nr].setStylesheet("background-color: orange")
               button[n][nr].settext("")
            ok
       next

func pmoveup()
       for n = 1 to size
            moveup = []
            for m = 1 to size
                 button[n][m] {temp = text()}
                 if temp != ""
                    add(moveup,temp)
                 ok
            next
            movetilesup(n,moveup)
        next
        newnum()
        return

func movetilesup(nr,moveup)
        for p = 1 to len(moveup) - 1
            button[nr][p] {temp1 = text()}
            button[nr][p+1] {temp2 = text()}
            if temp1 = temp2
               temp = string(number(temp1) + number(temp2))
               if temp != "0"
                  moveup[p] = temp
                  del(moveup,p+1)
                  exit
               ok
            ok
       next
       for n = 1 to len(moveup)
            button[nr][n].settext(moveup[n])
       next
       for n = len(moveup) + 1 to size 
            if n <= size
               button[nr][n].setStylesheet("background-color: orange")
               button[nr][n].settext("")
            ok
       next

func pmovedown()
       for n = 1 to size
            movedown = []
            for m = size to 1 step -1
                 button[n][m] {temp = text()}
                 if temp != ""
                    add(movedown,temp)
                 ok
            next
            movetilesdown(n,movedown)
        next
        newnum()
        return

func movetilesdown(nr,movedown)
        for p = 1 to len(movedown) - 1
            button[nr][p] {temp1 = text()}
            button[nr][p+1] {temp2 = text()}
            if temp1 = temp2
               temp = string(number(temp1) + number(temp2))
               if temp != "0"
                  movedown[p] = temp
                  del(movedown,p+1)
                  exit
               ok
            ok
       next
       for n = 1 to len(movedown)
            button[nr][size-n+1].settext(movedown[n])
       next
       for n = size - len(movedown) to 1 step -1 
            if n <= size
               button[nr][n].setStylesheet("background-color: orange")
               button[nr][n].settext("")
            ok
       next

func msgBox(text) {
	m = new qMessageBox(win) {
	       setWindowTitle("21 Game")
	       setText(text)
	       show()
	       }
        }

class MyButton from qPushButton
       func setText cValue 
              Super.setText(cValue)
              switch cValue 
                        on "2" setStyleSheet("foreground-color:blue; background-color: yellow")
                        on "4" setStylesheet("foreground-color:white; background-color: violet")
                        on "8" setStylesheet("foreground-color:white; background-color: blue")
                        on "16" setStylesheet("foreground-color:yellow; background-color: gray")
                        on "32" setStylesheet("foreground-color:white; background-color: red")
                        on "64" setStylesheet("foreground-color:white; background-color: gray")
              off
