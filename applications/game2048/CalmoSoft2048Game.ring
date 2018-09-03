# Project : 2048 Game
# Date    : 2018/08/26
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 4
limit = 6
numbers = [2,4,8,16,32,64]
button = newlist(size,size)
moveleft = []
moveright = []
moveup = []
movedown = []

app = new qApp {
          StyleFusion()
          win = new qWidget() {
                  setWindowTitle('2048 Game')
                  move(490,100) 
                  resize(450,500)
                  for n = 1 to size
                       for m = 1 to size
                            col = 100 + n*40
                            row = 100 + m*40
                            button[n][m] = new MyButton(win) {
                                                   setGeometry(col,row,40,40)
                                                   setstylesheet('background-color:orange')
                                                   }
                        next
                  next
                  newgame = new qPushButton(win) {
                                    setGeometry(180,380,80,40)
                                    setstylesheet('background-color:violet')
                                    settext('New Game')
                                    setClickEvent('pbegin()')
                                    }
                  mup = new qPushButton(win) {
                             setGeometry(140,300,40,40)
                             settext('up')
                             setClickEvent('pup()')
                             }
                  mdown = new qPushButton(win) {
                                 setGeometry(180,300,40,40)
                                 settext('down')
                                 setClickEvent('pdown()')
                                 }
                  mleft = new qPushButton(win) {
                              setGeometry(220,300,40,40)
                              settext('left')
                              setClickEvent('pleft()')
                              }
                  mright = new qPushButton(win) {
                                setGeometry(260,300,40,40)
                                settext('right')
                                setClickEvent('pright()')
                                }
                  pbegin()
           show()
         }
    exec()
}

func pbegin()
       for n = 1 to size
            for m = 1 to size
                 button[n][m].setStylesheet('background-color: orange')
                 button[n][m].settext('')
            next
        next
        for n = 1 to limit
             rn = random(size - 1) + 1
             rm = random(size - 1) + 1
             ran = random(limit - 1) + 1
             button[rn][rm].settext(string(numbers[ran]))
         next

func pdown()
       if gameover() = 1
          return
       ok
       pdownnew()
       pmovedown()
       newnum()

func pdownnew()
       if gameover() = 1
          return
       ok
       pmovedown()

func pup()
       if gameover() = 1
          return
       ok
       pupnew()
       pmoveup()
       newnum()

func pupnew()
       if gameover() = 1
          return
       ok
       pmoveup()

func pleft()
       if gameover() = 1
          return
       ok
       pleftnew()
       pmoveleft()
       newnum()

func pleftnew()
       if gameover() = 1
          return
       ok
       pmoveleft()

func pright()
       if gameover() = 1
          return
       ok
       prightnew()
       pmoveright()
       newnum()

func prightnew()
       if gameover() = 1
          return
       ok
       pmoveright()

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
       for p = 1 to (len(moveleft) - 1)
            button[p][nr] {temp1 = text()}
            button[p+1][nr] {temp2 = text()}
            if (temp1 = temp2) and (temp1 != '0') and (temp2 != '0') and (temp1 != '') and (temp2 != '')
               temp = string(number(temp1) + number(temp2))
               moveleft[p] = temp
               del(moveleft,p+1)
               exit
            ok
       next
       for n = 1 to len(moveleft)
            c1 = (moveleft[n] = '')
            c2 = (moveleft[n] = '0')
            if  c1 or c2
               del(moveleft,n)
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
       for p = 2 to len(moveright)
            button[size-p+2][nr] {temp1 = text()}
            button[size-p+1][nr] {temp2 = text()}
             if (temp1 = temp2) and (temp1 != '0') and (temp2 != '0') and (temp1 != '') and (temp2 != '')
               temp = string(number(temp1) + number(temp2))
               if temp != '0'
                  moveright[p] = temp
                  del(moveright,p-1)
                  exit
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
        for p = 1 to len(moveup) - 1
            button[nr][size-p+1] {temp1 = text()}
            button[nr][size-p] {temp2 = text()}
             if (temp1 = temp2) and (temp1 != '0') and (temp2 != '0') and (temp1 != '') and (temp2 != '')
               temp = string(number(temp1) + number(temp2))
               if temp != '0'
                  moveup[p+1] = temp
                  del(moveup,p)
                  exit
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
        for p = 1 to len(movedown) - 1
             button[nr][size-p+1] {temp1 = text()}
             button[nr][size-p] {temp2 = text()}
             if (temp1 = temp2) and (temp1 != '0') and (temp2 != '0') and (temp1 != '') and (temp2 != '')
               temp = string(number(temp1) + number(temp2))
               if temp != '0'
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
               button[nr][n].setStylesheet('background-color: orange')
               button[nr][n].settext('')
            ok
       next

func newnum()
        nums = [2,4]
        while true
                rn = random(size - 1) + 1
                rm = random(size - 1) + 1
                ran = random(len(nums) - 1) + 1
                if button[rn][rm].text() = ''
                   button[rn][rm].settext(string(nums[ran]))
                   exit
                ok
        end
        return

func gameover()
        num = 0
        for n = 1 to size
             for m = 1 to size 
                  if button[n][m].text() != ''
                     num = num + 1
                  ok
              next
        next
        if num = size*size
           msgBox('You lost!')
           return 1
        ok
        return

func msgBox(text) {
	m = new qMessageBox(win) {
	       setWindowTitle('21 Game')
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

class MyButton from qPushButton
       func setText cValue 
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
