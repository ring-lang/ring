Load "guilib.ring"
load "internetlib.ring"
/*
 +------------------------------------------------------------------------------------------
 +        Program Name : GetQuotesHistoryDraw.ring
 +        Date         : 2016.05.21
 +        Author       : Bert Mariani
 +        Purpose      : Fetch stock quotes history from finance.yahoo.com and Draw Chart
 +------------------------------------------------------------------------------------------
*/


###--------------------------------------
### DRAW CHART  area size 1000 x 1000
###

arrayPricesL = []					### Create a List

New qapp {
        win1 = new qwidget() {
		        ### Position and Size on Screen
                setwindowtitle("Drawing using QPainter")
      			setgeometry( 10, 25, 1000, 1000)
				
				### Draw within this Win Box
                label1 = new qlabel(win1) {
						### Label Position and Size
                        setgeometry(10, 10, 950, 950)
                        settext(" ")
				}

				lineedit1 = new qlineedit(win1) {
						### Text Field Position and Size ==> TICKER SYMBOL
                        setGeometry(10, 10, 70, 20)
                }
				
                new qpushbutton(win1) {
						### Button Position and Size
                        setgeometry(80, 10, 80, 20)
                        settext("Stock Symbol")
                        setclickevent("Draw()")	### Call DRAW function
                }

				Today = Date()
				lineedit2 = new qlineedit(win1) {
						### Text Field Position and Size ==> TODAY
                        setGeometry(160, 10, 70, 20)
						lineedit2.settext(Today) 
                }

				Yesterday = Date()
						arrayDate = split(Today, "/")
						OldDay    = arrayDate[2]
						OldMonth  = arrayDate[1]
						OldYear   = arrayDate[3] - 7    ### Go back 7 years <<<<<
						Yesterday = OldMonth +"/"+ OldDay +"/"+ OldYear
					
				
				lineedit2 = new qlineedit(win1) {
						### Text Field Position and Size	==> YESTERDAY
                        setGeometry(230, 10, 70, 20)
						lineedit2.settext(Yesterday) 
                }
				
				lineedit3 = new qlineedit(win1) {
						### Text Field Position and Size	==> High Low Current
						setGeometry(300, 10, 200, 20)	
						lineedit3.settext("High Low Current") 
				}
						
				
                show()
        }
        exec()
}

###------------------------
### FUNCTIONS
###

Func Draw
                $symbol = lineedit1.text()
				arrayPricesL = []					### Clear list
				
				returnCode = FetchData($symbol)		### FETCH DATA for this symbol
				
				if returnCode = "BAD"
					see "Bad Ticker " + returnCode +nl
					lineedit1.settext( "Bad Ticker" )
					return
				ok

		
				p1 = new qpicture()
                color = new qcolor() {
                        setrgb(0,0,255,255)
                }
                pen = new qpen() {
                        setcolor(color)
                        setwidth(1)
                }
                new qpainter() {
                        begin(p1)
                        setpen(pen)
                        						
						z = len(arrayPricesL)
						
						for x = 1 to z
							y = arrayPricesL[z+1-x]
							drawline( (x*2), 900 , (x*2), 900 - y)
						next	
						drawline(10, 900, 920, 900 )
						
							current = arrayPricesL[1]
							high    = max(arrayPricesL)				
							low     = min(arrayPricesL)

								### see "High " + high + " Low " + low + " Current " + current + "Len " +z +nl
						
						lineedit3.settext( "High " + high + " Low " + low + " Current " + current ) 
						
						
										
                        endpaint()
                }
                label1 { setpicture(p1) show() }
return				


###-------------------------

Func Split cstring, delimiter
	return str2list(substr(cstring, delimiter, nl))
	
###-------------------------	

###----------------

Func min aList
  min = aList[1]
  for x in aList
    if x < min
      min = x
    ok
  next
return min

###----------------

Func max aList
  max = aList[1]
  for x in aList
    if x > max
      max = x
    ok
  next
return max

###----------------


###--------------------------
### FETCH data from YAHOO
###

Func FetchData $thisSymbol

	see "Symbol called: " + $thisSymbol +nl
	
	Today = Date()
	arrayDate = split(Today, "/")
		### see "Day " + arrayDate[1] + " Month " +arrayDate[2] + " Year " + arrayDate[3] +nl

	###-----------------------------------------------------------------------------------
	###   HistoryDate MM/DD/YYYY  Subtract -1 from Month.  03 returns => April 2015-04-15
	###

	$MonthStart   = arrayDate[2]		### = "01" 
	$DayStart     = arrayDate[1]		### = "15" 
	$YearStart    = arrayDate[3] - 7	###	= "2009"  Go back 7 Years for data <<<<<

	$MonthEnd     = arrayDate[2]		### ="05" 
	$DayEnd       = arrayDate[1]		### ="14" 
	$YearEnd      = arrayDate[3]		###	="2016" 

	$DayWeekMonth = "w"                 ### Options are  "d" daily, "w" weekly, "m" monthly

	$symbol      =  $thisSymbol  		### "AAPL"
	$urlbase     = "http://ichart.yahoo.com/table.csv?s="         
	$urlbaseType = "&a=" + $MonthStart + "&b=" + $DayStart + "&c=" + $YearStart + "&d=" + $MonthEnd + "&e=" + $DayEnd + "&f=" + $YearEnd + "&g=" + $DayWeekMonth + "&ignore=.csv"

	$url         = $urlbase + $symbol + $urlbaseType   ### Join as URL to fetch              
		### see  $url + nl + nl

	cStr = download($url)
	write("download.txt",cStr)
	
	lineOne = substr( cStr, 1, 4)
	if lineOne != "Date"				### Date,Open,High,Low,Close,Volume,Adj Close
		see "Ticker not found " + $thisSymbol +nl
		return "BAD"
	ok

	###--------------------------------------------------
	### READ data and extract ADJ-CLOSE Price into List
	### Date,Open,High,Low,Close,Volume,Adj Close
	###

	aList = str2list(cStr)

	for L1 in aList
		cStr = Split(L1, ",")
			### see  cStr[1] + " " + cStr[7] +nl	### ECHO Date and Close
		Add( arrayPricesL, number(cStr[7]) )	        ### ADD Aj-Close to new List
	next

	del(arrayPricesL,1)						#       ### Delete title lines Date,Open,High,Low,Close,Vol.Adj-Close
	z = len(arrayPricesL)
		### see arrayPricesL
	See "arrayPricesL length " + z +nl

	###--------------------------
	### Find High and Low Price
	###

	high  = max(arrayPricesL)				
	low   = min(arrayPricesL)				
	See "MaxPrice " + high + "   MinPrice " + low +nl

return

###-------------------------------------------------------



