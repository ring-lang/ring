# Project : Calendar
# Date    : 2018/06/05
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
                   daysnew = [[5,1], [6,2], [7,3], [1,4], [2,5], [3,6], [4,7]]
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
                 for n = 1 to 4
                      nr = (n-1)*3+1
                     showmonths(nr)
                 next
                 for n = 1 to 12
                     showweeks(n)
                 next
                 for n = 1 to 12
                     showdays(n)
                 next
                 show()
        }
        exec()
        }

func showmonths(m)
       for n = m to m + 2
            monthsnames[n] = new qpushbutton(win1)
                                        {
                                        if n%3 = 1
                                           col = 120
                                           rownr = floor(n/3)          
                                           if rownr = 0
                                              rownr = n/3
                                           ok
                                           if n = 1
                                              row = 40
                                           else
                                              row = 40+rownr*180
                                           ok
                                        else
                                           colnr = n%3
                                           if colnr = 0
                                              colnr = 3
                                           ok
                                           rownr = floor(n/3)
                                           if n%3 = 0
                                              rownr = floor(n/3)-1
                                           ok
                                           col = 120 + (colnr-1)*160
                                           row = 40 + rownr*180
                                        ok
                                        setgeometry(col,row,60,20)
                                        monthsnames[n].settext(months[n])
                                        }
       next

func showweeks(n)
        for m = 1 to 7
             col = m%7
             if col = 0 col = 7 ok
             weekday[m] = new qpushbutton(win1)
                                  {
                                  colnr = n % 3
                                  if colnr = 0
                                     colnr = 3
                                  ok
                                  rownr = floor(n/3) 
                                  if n%3 = 0
                                     rownr = floor(n/3)-1
                                  ok
                                  colbegin = 60 + (colnr-1)*160
                                  rowbegin = 60 + (rownr)*180
                                  setgeometry(colbegin+col*20,rowbegin,20,20)
                                  weekday[m].settext(week[m])
                                  }
        next

func showdays(ind)
        if ind >=1 and ind <= 3
           rowbegin = 60
        ok
        if ind >=4 and ind <= 6
           rowbegin = 240
        ok
       if ind >=7 and ind <= 9
           rowbegin = 420
        ok
       if ind >=10 and ind <= 12
           rowbegin = 600
        ok
        for m = 1 to 6
             for n = 1 to 7
                  col = n%7
                  if col = 0 col = 7 ok
                  row = m
                   button[n][m] = new qpushbutton(win1)
                                         {
                                          if ind%3 = 1
                                             colbegin = 60
                                          elseif ind%3 = 2
                                             colbegin = 220
                                          else
                                             colbegin = 380
                                          ok
                                          setgeometry(colbegin+col*20,rowbegin+row*20,20,20)
                                          nr = (m-1)*7+n
                                          if nr <= 37
                                             if pos[ind][nr] != "  "
                                                button[n][m].settext(string(pos[ind][nr]))
                                             ok
                                          ok
                                          }
             next
        next
