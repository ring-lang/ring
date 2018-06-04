# Project : Calendar
# Date    : 2018/06/03
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
load "guilib.ring"
load "stdlib.ring"
 
new qapp 
       {
        win1 = new qwidget() {
 
day = list(12)
pos = newlist(12,37)
month = list(12)
week = list(7)
weekday = list(7)
button = newlist(7,6)
monthsnames = list(12)
week = ["Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"]
months = ["January", "February", "March", "April", "May", "June", "July",
                "August", "September", "October", "November", "December"]
days = [5, 6, 0, 1, 2, 3, 4]
daysnew = [[6,2], [7,3], [1,4], [2,5], [3,6], [4,7], [5,1]]
mo = [4,0,0,3,5,1,3,6,2,4,0,2]
mon = [31,28,31,30,31,30,31,31,30,31,30,31]
m2 = (((1969-1900)%7) + floor((1969 - 1900)/4) % 7) % 7
for n = 1 to 12
     month[n] = (mo[n] + m2) % 7
     x = (month[n] + 1) % 7 + 1
     for m = 1 to len(daysnew)
          if daysnew[m][1] = x
             nr = m
          ok
     next
     day[n] = daysnew[nr][2]
next
 
for m = 1 to 12
     for n = 1 to day[m] - 1
          pos[m][n] = "  "
     next
next
 
for m = 1 to 12
     for  n = day[m] to 37
           if n < (mon[m] + day[m])
              pos[m][n] = n - day[m] + 1
           else
              pos[m][n] = "  "
           ok
     next
next
 
                  setwindowtitle("Calendar")
                  setgeometry(100,100,650,800)
                  label1 = new qlabel(win1) {
                              setgeometry(10,10,800,600)
                              settext("")
                  }
 
                 year = new qpushbutton(win1)
                                                  {
                                                  setgeometry(280,20,60,20)
                                                  year.settext("1969")
                                                  }
 
                 monthsnames[1] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(120,40,60,20)
                                                  monthsnames[1].settext(months[1])
                                                  }
 
                monthsnames[2] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(280,40,60,20)
                                                  monthsnames[2].settext(months[2])
                                                  }
 
                monthsnames[3] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(440,40,60,20)
                                                  monthsnames[3].settext(months[3])
                                                  }
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(60+col*20,60,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(220+col*20,60,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(380+col*20,60,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(60+col*20,60+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[1][nr] != "  "
                                                        button[n][m].settext(string(pos[1][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(220+col*20,60+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[2][nr] != "  "
                                                        button[n][m].settext(string(pos[2][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(380+col*20,60+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[3][nr] != "  "
                                                        button[n][m].settext(string(pos[3][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                monthsnames[4] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(120,220,60,20)
                                                  monthsnames[4].settext(months[4])
                                                  }
 
                monthsnames[5] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(280,220,60,20)
                                                  monthsnames[5].settext(months[5])
                                                  }
 
                monthsnames[6] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(440,220,60,20)
                                                  monthsnames[6].settext(months[6])
                                                  }
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(60+col*20,240,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(220+col*20,240,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(380+col*20,240,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(60+col*20,240+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[4][nr] != "  "
                                                        button[n][m].settext(string(pos[4][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(220+col*20,240+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[5][nr] != "  "
                                                        button[n][m].settext(string(pos[5][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(380+col*20,240+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[6][nr] != "  "
                                                        button[n][m].settext(string(pos[6][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                 monthsnames[7] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(120,400,60,20)
                                                  monthsnames[7].settext(months[7])
                                                  }
 
                monthsnames[8] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(280,400,60,20)
                                                  monthsnames[8].settext(months[8])
                                                  }
 
                monthsnames[9] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(440,400,60,20)
                                                  monthsnames[9].settext(months[9])
                                                  }
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(60+col*20,420,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(220+col*20,420,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(380+col*20,420,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(60+col*20,420+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[7][nr] != "  "
                                                        button[n][m].settext(string(pos[7][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(220+col*20,420+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[8][nr] != "  "
                                                        button[n][m].settext(string(pos[8][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(380+col*20,420+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[9][nr] != "  "
                                                        button[n][m].settext(string(pos[9][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
 
                 monthsnames[10] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(120,580,60,20)
                                                  monthsnames[10].settext(months[10])
                                                  }
 
                monthsnames[11] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(280,580,60,20)
                                                  monthsnames[11].settext(months[11])
                                                  }
 
                monthsnames[12] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(440,580,60,20)
                                                  monthsnames[12].settext(months[12])
                                                  }
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(60+col*20,600,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(220+col*20,600,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                        col = n%7
                        if col = 0 col = 7 ok
                        weekday[n] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(380+col*20,600,20,20)
                                                  weekday[n].settext(week[n])
                                                  }
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(60+col*20,600+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[10][nr] != "  "
                                                        button[n][m].settext(string(pos[10][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(220+col*20,600+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[11][nr] != "  "
                                                        button[n][m].settext(string(pos[11][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                  for n = 1 to 7
                       for m = 1 to 6
                            col = n%7
                            if col = 0 col = 7 ok
                            row = m
                            button[n][m] = new qpushbutton(win1)
                                                  {
                                                  setgeometry(380+col*20,600+row*20,20,20)
                                                  nr = (m-1)*7+n
                                                  if nr <= 37
                                                     if pos[12][nr] != "  "
                                                        button[n][m].settext(string(pos[12][nr]))
                                                     ok
                                                  ok
                                                  }
                       next
                  next
 
                  show()
        }
        exec()
        }
