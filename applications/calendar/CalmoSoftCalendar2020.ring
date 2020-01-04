# project : CalmoSoft Calendar for Year 2020
# date    : 2020/01/02
# author  : Gal Zsolt (~ CalmoSoft ~)
# email   : <calmosoft@gmail.com>

load "guilib.ring"
load "stdlib.ring"

new qapp 
       {
	stylefusionblack()
        win1 = new qwidget() {
		   setWindowFlags(Qt_Window | Qt_WindowTitleHint | Qt_WindowSystemMenuHint | Qt_WindowCloseButtonHint | Qt_CustomizeWindowHint) 
		   setWinIcon(win1,"calendar.png") 
                   day = list(12)
                   pos = newlist(12,37)
                   month = list(12)
                   week = list(7)
                   weekday = list(7)
                   button = newlist(7,6)
                   monthsnames = list(12)
                   week = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
                   months = ["January", "February", "March", "April", "May", "June", "July",
                              "August", "September", "October", "November", "December"]
                   daysnew = [[5,1], [6,2], [7,3], [1,4], [2,5], [3,6], [4,7]]
                   mo = [4,0,0,3,5,1,3,6,2,4,0,2]
                   mon = [31,29,31,30,31,30,31,31,30,31,30,31]
                   leap = (floor((2020 - 1900)/4)) % 7
                   leap2 = floor(2020 - 1900) % 4
                   m2 = (((2020-1900)%7) + leap) % 7
                   for n = 1 to 12
                       month[n] = (mo[n] + m2) % 7
                       x = (month[n] + 1) % 7 + 1
                       for m = 1 to len(daysnew)
                           if daysnew[m][1] = x
                              nr = m
                           ok
                       next
                       day[n] = daysnew[nr][2]
                       if leap2 = 0 and n < 3
                          day[n] = (day[n] - 1) % 7
                          if day[n] = 0
                             day[n] = 7
                          ok
                       ok
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
                   setwindowtitle("Calendar for Year 2020")
                   setgeometry(100,100,850,800)
                   label1 = new qlabel(win1) {
                                setgeometry(10,10,800,600)
                                settext("")
                  }
                  year = new qpushbutton(win1)
                             { setgeometry(400,20,63,20)
                               year.settext("2020")
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
                             col = 160
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
                             col = 160 + (colnr-1)*240
                             row = 40 + rownr*180
                          ok
                          setgeometry(col,row,63,20)
                          monthsnames[n].settext(months[n])
                          }
     next

func showweeks(n)
     for m = 1 to 7
         col = m%7
         if col = 0
            col = 7 
         ok
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
                      colbegin = 60 + (colnr-1)*240
                      rowbegin = 60 + (rownr)*180
                      setgeometry(colbegin+col*30,rowbegin,30,20)
                      weekday[m].settext(week[m])
                                  }
     next

func showdays(ind)
     rownr = floor(ind/3)
     if ind%3 = 0
        rownr = floor(ind/3)-1
     ok
     rowbegin = 60+rownr*180
     daynr = 0
     for m = 1 to 6
         for n = 1 to 7
             daynr = daynr + 1
             col = n%7
             if col = 0 col = 7 ok
                row = m
                button[n][m] = new qpushbutton(win1)
                               {
                                if ind%3 = 1
                                   colbegin = 60
                                elseif ind%3 = 2
                                       colbegin = 300
                                else
                                   colbegin = 540
                                ok
                                setgeometry(colbegin+col*30,rowbegin+row*20,30,20)
                                nr = (m-1)*7+n
                                if nr <= 37
                                   if pos[ind][nr] != "  "
                                      button[n][m].settext(string(pos[ind][nr]))
                                      if ind = number(timelist()[10]) and pos[ind][nr] = number(timelist()[6])
                                         button[n][m].setstylesheet('background-color:orange')
                                      ok
                                   ok
                                ok
                                }
         next
     next
