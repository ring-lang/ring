# Project : 2048 Game
# Date    : 2018/08/23
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>


load "stdlib.ring"
load "guilib.ring"

size = 4
limit = 6
nn = 0
mm = 0
num = [2,4,8,16,32,64]
button = newlist(size,size)
mdown = list(size)
mup = list(size)
mleft = list(size)
mright = list(size)
app = new qApp {
          win = new qWidget() {
                  setWindowTitle("Don't accept Spaces")
                  move(490,100) 
                  resize(450,500)
                  for n = 1 to size
                       for m = 1 to size
                            col = 100 + n*40
                            row = 100 + m*40
                            button[n][m] = new qPushButton(win) {
                                                   setGeometry(col,row,40,40)
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
       nn = np
       mm = mp

func pbegin()
       for n = 1 to size
            for m = 1 to size
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
       if mm = 4
          see "bad move" + nl
          return
       ok
       for m = mm + 1 to size 
            button[nn][m] {move = text()}
            if move != ""
               button[nn][mm] {temp = text()}
               if move = temp
                  res = string(number(move) + number(temp))
                  button[nn][m].settext(res)
                  button[nn][mm].settext("")
                  exit
               ok
            ok
       next

func pup()
       if mm = 1
          see "bad move" + nl
          return
       ok
       for m = mm - 1 to 1 step -1
            button[nn][m] {move = text()}
            if move != ""
               button[nn][mm] {temp = text()}
               if move = temp
                  res = string(number(move) + number(temp))
                  button[nn][m].settext(res)
                  button[nn][mm].settext("")
                  newnum()
                  exit
               ok
            ok
       next

func pleft()
       if nn = 1
          see "bad move" + nl
          return
       ok
       for n = mm - 1 to 1 step -1
            button[n][mm] {move = text()}
            if move != ""
               button[nn][mm] {temp = text()}
               if move = temp
                  res = string(number(move) + number(temp))
                  button[n][mm].settext(res)
                  button[nn][mm].settext("")
                  exit
               ok
            ok
       next

func pright()
       if nn = 4
          see "bad move" + nl
          return
       ok
       for n = nn + 1 to size 
            button[n][mm] {move = text()}
            if move != ""
               button[nn][mm] {temp = text()}
               if move = temp
                  res = string(number(move) + number(temp))
                  button[n][mm].settext(res)
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
