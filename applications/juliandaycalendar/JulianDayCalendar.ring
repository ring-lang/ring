# project : CalmoSoft Julian Day Calendar for year 2020
# date    : 2020/01/14
# author  : Gal Zsolt (~ CalmoSoft ~)
# email   : <calmosoft@gmail.com>

load "lightguilib.ring"
load "stdlibcore.ring"

actYear    = timelist()[19]
aYears     = 1904:2099
nYearIndex = find(aYears,0+actYear) - 1 
msg = "After the Month of February add one to the Day Number for Leap Years: 2008, 2012, 2016, 2020, 2024, 2028, 2032, 2036, 2040 ......"

btnSizeW = 30
btnSizeH = 20

new qapp 
       {
	stylefusionblack()
        win1 = new qwidget() {
		   setWindowFlags(Qt_Window | Qt_WindowTitleHint | Qt_WindowSystemMenuHint | Qt_WindowCloseButtonHint | Qt_CustomizeWindowHint) 
		   setWinIcon(win1,"calendar.png")
                   setwindowtitle("Julian Day Calendar")
                   resize(1200,700)
                   button = newlist(31,31)
                   btndays = list(31)
                   btnmonths = list(12)
                   monthsnames = list(12)
                   months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                              "Aug", "Sep", "Oct", "Nov", "Dec"]
                   mon = [31,29,31,30,31,30,31,31,30,31,30,31]

                   label1 = new qlabel(win1) {
                                setgeometry(700,50,85,30)
                                setFont(new qFont("Verdana",15,100,0))
                                setstylesheet("color:white;background-color:violet;")
                                setAlignment(Qt_AlignVCenter | Qt_AlignHCenter)
                                settext("Year:")
                   }

                   yearCmb = new qcombobox(win1) {
    	                     move(800,50)
                             resize(100,30)
                             setstylesheet("color:white;background-color:red;")
                             setFont(new qFont("Verdana",15,100,0))
                             for x in aYears additem(string(x),0) next
                             setcurrentIndex(nYearIndex)
                             setactivatedEvent("changeYear(nYearIndex)")
                             show() }

                   labelJulian = new qLabel(win1)
                                 { setgeometry(100,50,600,30)
                                   setFont(new qFont("Verdana",15,100,0))
                                   setAlignment(Qt_AlignVCenter | Qt_AlignHCenter)
                                   settext("Julian Day Calendar")
                                 }

                   labelMsg = new qLabel(win1)
                              { setgeometry(80,100,1000,30)
                                setFont(new qFont("Verdana",10,100,0))
                                setAlignment(Qt_AlignVCenter | Qt_AlignHCenter)
                                settext(msg)
                              }

                   for n = 1 to 31
                       for m = 1 to 24
                           button[n][m] = new qpushbutton(win1)
                                          { setgeometry(100+btnSizeW*n,150+btnSizeH*m,btnSizeW,btnSizeH)
                                            settext("")
                                          }
                       next 
                   next

                   for n = 1 to 31
                       btndays[n] = new qpushbutton(win1)
                                    { setgeometry(100+btnSizeW*n,150,btnSizeW,btnSizeH)
                                      settext(string(n))
                                    }
                   next

                   for n = 1 to 12
                       btnmonths[n] = new qpushbutton(win1)
                                      { setgeometry(100,150+btnSizeH*n*2,btnSizeW,btnSizeH)
                                        settext(months[n])
                                      }
                   next

                   btnday = new qpushbutton(win1)
                            { setgeometry(100,150,btnSizeW,btnSizeH)
                              settext("Day")
                            }

                   showdays(nYearIndex)

                   show()
        }
        exec()
        }

func changeYear(new2Year)

     new2Year = yearCmb.currentindex()
     new2Year = new2Year + 1904
     win1.setwindowtitle("Julian Day Calendar for Year " + string(new2Year))
     for m = 1 to 24
         for n = 1 to 31
             button[n][m].settext("")
             button[n][m].setstylesheet('background-color:black')
         next
     next

     showdays(new2Year)

func showdays(newYear)
     sum = 0
     leap = floor(newYear - 1900) % 4
     if leap = 0
        mon = [31,29,31,30,31,30,31,31,30,31,30,31]
     else
        mon = [31,28,31,30,31,30,31,31,30,31,30,31]
     ok

     for n = 1 to 12
         for q = 1 to mon[n] 
             sum = sum + 1  
             button[q][n*2].settext(string(sum))
             if newYear = timelist()[19] and n = number(timelist()[10]) and q = number(timelist()[6])
                button[q][n*2].setstylesheet('background-color:orange')
             ok
         next 
     next

     button[29][3] { setstylesheet('background-color:orange')
                     settext("Leap")
                   }

     button[29][4].setstylesheet('background-color:violet')                

