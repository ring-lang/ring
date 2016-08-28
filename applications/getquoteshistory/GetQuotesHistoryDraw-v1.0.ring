Load "guilib.ring"

/*
 +-----------------------------------------------------------------------------------------
 +        Program Name : GetQuotesHistoryDraw.ring
 +        Date         : 2016.04.21
 +        Author       : Bert Mariani
 +        Purpose      : Fetch stock quotes history from finance.yahoo.com and Draw Chart
 +----------------------------------------------------------------------------------------
*/



###--------------------------------------------------
### List of TICKER SYMBOLS xxx.tickers file REQUIRED 


	TickersDir   = "B:\RING\samples\"
	#TickersFile  = "GetQuotesTickers.tickers"
	#TickersUse   = TickersDir + TickersFile 	### INITIAL file.tickers to use
	TickersList = []  							###	["GetQuotesTickers.tickers", "GetReits.tickers", "GetRailroad.tickers" ]

	mylist = dir(TickersDir)

	for x in mylist
			Name = x[1] ; Type = x[2]		
			
			if Type = 1
					#see " Type " + Type + " Directory : " + Name +nl			
			else
					#see " Type " + Type + " File : "      + Name +nl			
					cStr = Split(Name, ".")
					
					if cStr[2] = "tickers"
						Add( TickersList, Name )
					ok
			ok
	next

	# see TickersList
	TickersUse = TickersList[1]					### Use this Tickers List

###========================================================================

###------------------------------------------------------
### DRAW MAIN PAGE - CHART  size 1000 x 750
###
### Place Buttons, Labels, CheckBoxes in their place
###-----------------------------------------------------


###--------------------
### Create arrayLists
    arrayDate     = []
    arrayOpen     = []
    arrayHigh     = []
    arrayLow      = []
    arrayClose    = []
    arrayVolume   = []
    arrayAdjClose = []
	
	arrayDivDate  = []
    arrayDividend = []
 
###-------------------- 
### HeikenAshi  
    haOpen  = []          
    haHigh  = []
    haLow   = []
    haClose = []        

    Scale      = 1              ### Multiplier for Scaling Prices to Chart
    ScaleHi    = 1              ### Scale as per maxHighPrie
    sizeOfData = 1              ### Time periods retreived

    maxHighPrice     = 1
    minLowPrice      = 1
    maxActualHiPrice = 1
    minActualLoPrice = 1

###-------------------------------
### Window Size
    WinLeft   = 80                  ### 80    Window position on screen
    WinTop    = 80                  ### 80    Window position on screen
    WinWidth  = 1200                ### 1000  Window Size - Horizontal-X WinWidth
    WinHeight = 750                 ### 750   Window Size - Vertical-Y WinHeight
	WinRight  = WinLeft + WinWidth  ### 1080
	WinBottom = WinTop  + WinHeight ### 830
	
###----------------------------	
### Label1 Box Size           
    BoxLeft   = 80                  ###  Start corner   Label1 Box Start Position inside WIN1
    BoxTop    = 40                  ###  Start corner 
    BoxWidth  = WinWidth  -160      ###  End   corner   Label1 Box Size
    BoxHeight = WinHeight -80       ###  End   corner    
    
    WinBaseY  = BoxHeight -50       ### WinBaseY Line Bottom  where Price=0
	

###---------------------------	
### label2 LEFT BOX SIZE			 ###  setgeometry(0, 40, 80, BoxHeight)
    LBoxLeft   = 00                  ###  Start corner   Label1 Box Start Position inside WIN1
    LBoxTop    = 40                  ###  Start corner 
    LBoxWidth  = 80      			 ###  End   corner   Label1 Box Size
    LBoxHeight = WinHeight -80       ###  End   corner    
    
	
###---------------------------   
    Today 		= Date()
	StartDate 	= Date()
	
###---------------------------	


###==================================
### QAPP - WIN1
###
###==================================

New qapp {
        win1 = new qwidget() {
		
                ### Position and Size on Screen
                setwindowtitle("GetQuotesHistory-DrawChart using QPainter")
                setgeometry( WinLeft, WinTop, WinWidth, WinHeight)
                
                win1{ setwindowtitle("Initial Window Position: " +" L " + WinLeft +" T " + WinTop +" Width" + width() +" Height " +  height() ) }
				
				###------------------------------------------
				### ReSizeEvent ... Call WhereAreWe function
				
				myfilter = new qallevents(win1)
				myfilter.setResizeEvent("WhereAreWe()")
				installeventfilter(myfilter)
				
				###---------------------------
                ### Draw within this WIN BOX
				
                label1 = new qlabel(win1) {
                        setgeometry(BoxLeft, BoxTop, BoxWidth, BoxHeight)
                        settext("We are Here")

                }
				
				###-------------------------------
                ### Draw within this WIN LEFT BOX
				
                label2 = new qlabel(win1) {
                        setgeometry(LBoxLeft, LBoxTop, LBoxWidth, LBoxHeight)
                        settext("LeftBox")

                }
				
				

				###------------------------------------------------
                ### Text Field Position and Size ==> TICKER SYMBOL
				
                lineedit1 = new qlineedit(win1) {
                        setGeometry(BoxLeft +90, BoxTop -BoxTop, 70, 20)
                }

				###--------------------------------------
                ### GET STOCK Button Position and Size
                ### Call DRAW function
				
                new qpushbutton(win1) {
                        setgeometry(BoxLeft +160, BoxTop -BoxTop, 80, 20)
                        settext("Get Stock")
                        setclickevent("Draw()")
                }
				
				### GET PREVIOUS Stock
                new qpushbutton(win1) {
                        setgeometry(BoxLeft +00, BoxTop -BoxTop, 45, 20)
                        settext("<Prev")				
                        setclickevent("PrevSymbol()")
                }

				### GET NEXT Stock
                new qpushbutton(win1) {
                        setgeometry(BoxLeft +45, BoxTop -BoxTop, 45, 20)
                        settext("Next>")
                        setclickevent("NextSymbol()")
                }				
				
				###---------------------------------------------------
                ### Text Field Position and Size. TODAY is End Date
				
                Today = Date()
                lineedit2 = new qlineedit(win1) {
                        setGeometry(BoxLeft +240, BoxTop -BoxTop, 70, 20)
                        lineedit2.settext(Today)
                }

				###----------------------------------------------------------------
                ### Text Field Position and Size. YESTERDAY is *** 7 YEARS AGO ***
				
                Yesterday = Date()
                    aDateDMY = split(Today, "/")
                    OldDay    = aDateDMY[2]
                    OldMonth  = aDateDMY[1]
                    OldYear   = aDateDMY[3] - 7
                    Yesterday = OldMonth +"/"+ OldDay +"/"+ OldYear

				###----------------------------------------------	
                ### Text Field Position and Size ==> YESTERDAY
				
                lineedit2 = new qlineedit(win1) {
                        setGeometry(BoxLeft +310, BoxTop -BoxTop, 70, 20)
                        lineedit2.settext(Yesterday)
                }

				###--------------------------------------------------------
                ### Combo Box for Draw Style - Mountain, Line, Bar, Actual
				
                comboChartType = new QComboBox(win1) {
                        setGeometry(BoxLeft +380, BoxTop -BoxTop, 80, 20)
                        alist = ["Line","Bar","Mountain","Actual","Log","HeikenAshi"]
                        for x in aList additem(x,0) next
                }

				###----------------------------------------------------------
                ### Combo Box for Time Period Type - Weekly, Daily, Monthly
				
                comboTimePeriod = new QComboBox(win1) {
                        setGeometry(BoxLeft +440, BoxTop -BoxTop, 80, 20)
                        alistTime = ["Weekly", "Daily", "Monthly"]
                        for x in aListTime additem(x,0) next
                }
                
                ###---------------------------
                ### Button SELECT STOCK
				
                btn1 = new qpushbutton(win1) {

                        setGeometry(LBoxLeft, LBoxTop, LBoxWidth, 20)			 ### SELECT STOCK
                        settext("Select Symbol")
                        setclickevent("SelectSymbol()")      ### ==> Go Handle
                }
                
  
				### Combo Box for GetQuotesTickers Baskets
                comboTickersBasket = new QComboBox(win1) {
                        setGeometry(BoxLeft +520, BoxTop -BoxTop, 160, 20)
						aListBasket = Tickerslist
                        for x in aListBasket additem(x,0) next
						
						setactivatedEvent("GetBasket()")      ### ==> Go Handle
                }
	
				###-------------------------------
                ### List of STOCK TICKER SYMBOLS
				### CHECK if TickerFile EXISTS
				
				if fexists(TickersUse) = 0
					See "REQUIRES TickersUse: " + TickersUse +nl
					
					labelMsg = new qpushbutton(win1)
					{
							setText("REQUIRED TickersFile Missing:  " + TickersUse )
							setgeometry(250,100,650,60)
							setstylesheet("color: blue ; font-size: 12pt;")
							#setclickevent("pWork()")
					}
					
					# setWindowTitle("Messagebox")
					# setgeometry(100,100,600,80)
					# setStyleSheet("background-color: white;")
					# show()
				
				ok
				
                list1 = new qlistwidget(win1) {
                        setGeometry(LBoxLeft, LBoxTop +20, LBoxWidth, 140)		### <<< TICKER LIST
						
						

                        #--------------------------------------------------------
                        # alist = ["AMZN","AAPL","GOOGL","FB","NFLX","VTI","BLV"]
                        # for x in alist
                        #    additem(x)
                        # next
                        #---------------------------------------------------------
                       
                        cFile = read(TickersUse)				### ("C:\RING\bin\GetQuotesTickers.txt")
                        cFile = substr(cFile,windowsnl(),nl)
                        aList = str2list(cFile)
						
						TickersNbr = len(aList) -1				### Use for Prev-Next Symbol limit

                        ###----------------------------
                        ### WORKS. the EOF ignored
                        ###----------------------------
                        
                        for i = 1 to len(alist)     
                            if( alist[i] != '')
                                    # See 'List__' + alist[i] + '__' +nl
                                additem( alist[i] )
                            ok
                        next    
                          
                        ###------------------------------------
                        ### FAILS to handle EOF
                        ###------------------------------------
                        #for x in aList             
                        #    if ( x != '')
                        #            size = Len(x) 
                        #            See "Symbol__"  + x + "__Size__" +size + "__" +nl
                        #        additem( alist[x] )
                        #    ok
                        #next   
                        ####-----------------------------------

                        
                        setcurrentrow(3,2)
                             ### win1.setwindowtitle("Tickers Count : " + count() )
                             
                             
                }


				### Check Box - MOVING AVERAGE
				CheckMAvg = new qcheckbox(win1) {
                        setGeometry(LBoxLeft, LBoxTop +180, LBoxWidth, 20)
                        settext("MAvg-30")
						# setclickedEvent("CheckBoxMAvg()")
                }

				
				### Check Box - DIVIDEND
				CheckDividend = new qcheckbox(win1) {
                        setGeometry(LBoxLeft, LBoxTop +200, LBoxWidth, 20)
                        settext("Dividend")
						# setclickedEvent("CheckDividend()")
                }


                ###--------------------------------------------------
                ### END of WIN, BOX, and  Buttons
                ###--------------------------------------------------


            show()
        }
        exec()
}

###===============================================
### FUNCTIONS
###===============================================


Func CheckBoxMAvg
	See "StateChange: Check MAvg " + CheckMAvg.isChecked()  +nl   ### 0 - Uncheked  1 - Checked
return


Func CheckDividend
	See "StateChange: Check Dividend " + CheckDividend.isChecked()  +nl   ### 0 - Uncheked  1 - Checked
return

	
###-----------------------------------------
### FUNCTION Where Are We - Window Resized
###----------------------------------------

Func WhereAreWe
		Rec = win1.framegeometry()
    
        WinWidth  = win1.width()            ### 1000 Current Values 
        WinHeight = win1.height()           ### 750 
        
        WinLeft   = Rec.left() +8           ### <<< QT FIX because of Win Title
        WinTop    = Rec.top()  +30          ### <<< QT FIX because of Win Title 
        WinRight  = Rec.right()
        WinBottom = Rec.bottom()

		# BoxLeft   = 80                  ###  Start corner   Label1 Box Start Position inside WIN1
		# BoxTop    = 40                  ###  Start corner 
		
		BoxWidth  = WinWidth  -160       	###  End   corner   Label1 Box Size
		BoxHeight = WinHeight -80       	###  End   corner   
		
		WinBaseY  = BoxHeight -50       	### WinBaseY Line Bottom  where Price=0

        win1{ setwindowtitle("Window ReSize: Win " +  WinWidth + "x" + WinHeight + " --- Box " + BoxWidth  + "x" + BoxHeight  + 
                              " --- LT " +  WinLeft + "-"   + WinTop  + " --- RB " + WinRight + "-" + WinBottom      ) }
		
		# See "We Are Here - setResizeEvent - " 
        # See " Win "  + WinWidth  + "x" + WinHeight + " --- Box  "  + BoxWidth + "x" + BoxHeight  
        # See " --- LT " + Winleft   + "-"   + WinTop    + " --- RB " + WinRight + "-"   + WinBottom +nl
        
          win1.setgeometry( WinLeft, WinTop, WinWidth, WinHeight )
        label1.setgeometry( BoxLeft, BoxTop, BoxWidth, BoxHeight )

		
	
return

###============================================================
### FUNCTION DARW -  After Stock Symbol selected handle it
###
###============================================================

Func Draw

                
	###-----------------------------
	### FETCH DATA for this sysmbol
	### CLEAR arrayClose
	###-----------------------------
	
	$symbol = lineedit1.text()
	arrayClose = []

	###-----------------------------------------------------------------------------
	### FETCH DATA.  "Price"  "Dividend"
 	###		returnCode = FetchData($symbol,"Price")
	###		returnCode = FetchData($symbol,"Dividend")
	###
	###             If -- BAD -- Yahoo did NOT return valid data for this Ticker
	###----------------------------------------------------------------------------
	
	returnCode = FetchData($symbol,"Price")

		if returnCode = "BAD"
			See "Ticker return code " + returnCode + " for Symbol " + $symbol +nl
			lineedit1.settext( "Bad Ticker" )
			return
		ok
	

	
	###-----------------------------
	### PEN Colors
	###-----------------------------
	
	p1 = new qpicture()
	
		colorRed   = new qcolor() { setrgb(205,  0,  0,255) }
		colorGreen = new qcolor() { setrgb(  0,205,  0,255) }
		colorBlue  = new qcolor() { setrgb(0,    0,255,255) }
		colorGray  = new qcolor() { setrgb(128,128,128,255) }
		
		penRed   = new qpen() { setcolor(colorRed)   setwidth(1) }
		penGreen = new qpen() { setcolor(colorGreen) setwidth(1) }
		penBlue  = new qpen() { setcolor(colorBlue)  setwidth(1) }
		penGray  = new qpen() { setcolor(colorGray)  setwidth(1) }

	###-----------------------
	### PAINT the Chart
	###-----------------------

	new qpainter() {
			begin(p1)
			z = sizeOfData
		  
			###------------------------------------------------------------------------
			### Note AAPL split 7 to 1 -- maxHighPrice 129.88 maxActualHiPrice 705.07
		
			Scale    = WinBaseY / maxHighPrice           ### Mulpiplier to Scales Prices to Chart
			ScaleHi  = WinBaseY / maxActualHiPrice
						
			# See "WinBaseY " +WinBaseY +" maxHighPrice " + maxHighPrice +" maxActualHiPrice " + maxActualHiPrice +" Scale " + Scale +" ScaleHi " +ScaleHi +nl		
			
			###----------------------------------------------
			### ChartType - ComboBox selected for chart type
			### "Mountain","Line","Hi-Low","Candle","Bars"
			###----------------------------------------------
			
			setpen(penBlue)
			chartType = comboChartType.currentText()


			###------------------------------------------------------------------------------------
			### Draw Vertically Spaced Price Lines
			###------------------------------------------------------------------------------------

			setpen(penBlue)

			vLine    = 0                                                    ### Log Chart bottom line
			Magnify  = 10                                                   ### MAGNIFY LOG Chart
			maxLog   = log(maxHighPrice  )* log(10 * Magnify)               ### 728 = 6.8 log
			scaleLog = WinBaseY / maxlog                                    ### WinBaseY / 6.8  = 124


			for y = 0 to 10

				if (chartType = "Log") and (y > 0)                          ### Skip Log 0
					vLine    = WinBaseY /10
					pL       = log( (maxHighPrice / 10) * y ) *  log(y * Magnify)   ### y / 10 is percent of maxHighPrice
					vLine    = scaleLog * pL
					priceInc = string(maxHighPrice / 10 * y)


				but chartType = "Actual"
					priceInc  = string(maxActualHiPrice / 10 * y)

				else
					### Other Charts - Line, Bar, Mountain, Heiken-Ashi
					priceInc  = string(maxHighPrice / 10 * y)
					
				ok

					if (chartType = "Log")
						drawline( 10, WinBaseY - (1 * vLine) , BoxWidth, WinBaseY - (1 * vLine ) )
						drawText( 10, WinBaseY - (1 * vLine) +10, priceInc )

					else
						### Other Charts - Line, Bar, Mountain, Heiken-Ashi
						vLine    = WinBaseY /10
						drawline( 10, WinBaseY - (y * vLine)    , BoxWidth, WinBaseY - (y * vLine) )
						drawText( 10, WinBaseY - (y * vLine) +10, priceInc )                           ### Draw Price Below the Horizontal Price Line
					ok


			next


			###--------------------------------------------------------------------------------------
			### Draw HORIZONTALY Spaced  Date Lines
			### Find beginning of Year 2016. Draw line.
			### Horizontal Placing of Vertical Lines every 2 lines  HzSp = 2
			###--------------------------------------------------------------------------------------
			
			# HzSp = 2    ### Horizontal spacing every 2 lines
			HzSp = ( ( BoxWidth-2 ) / sizeOfData )                         ### Horizon Space self adjusting as per width of Box
			
			

			chartPeriod = comboTimePeriod.currentText()                    ### "Weekly", "Daily", "Monthly"
				if chartPeriod = "Weekly"  Interval = ( 7 )             ok
				if chartPeriod = "Monthly" Interval = ( 365.25 /12 )    ok
				if chartPeriod = "Daily"   Interval = ( 7/5 )           ok

			cDate1    = date()                                              
				aDateDMY = split(cDate1, "/")								### TODAY dd/mm/yyyy  16/06/2016
				Year      = number(aDateDMY[3]) +1                          ### Present Year 2016  
				cDate2    = "01/01/" + Year                                 ### Next    Year 2017
				
				DaysAgo   = DiffDays(cDate1, cDate2)
				
				x         = HzSp * (z - (DaysAgo / Interval) )              ### Future Year >> 2017  interval in days

			
				###------------------------------------------
				### Draw Year VERTICAL for each of 7 Years
				###------------------------------------------
				
				for count = 0 to 7
				 
					drawline( x, 10, x, WinBaseY)                               ### DRAW LINE
					# See " Count " + count + " Year " + Year + " X " +x + " DaysAgo " + DaysAgo +nl

					### WEEKLY MONTHY Dates
					
					if ((chartPeriod = "Weekly") or (chartPeriod = "Monthly"))
						drawText( x, WinBaseY +20, (string(Year)) )             ### YEAR DATE
					ok

						if chartPeriod = "Weekly"                               ### WEEKLY
							Year    = Year - 1                  
							cDate2  = "01/01/" + Year
							DaysAgo = DiffDays(cDate1, cDate2)
							x       = HzSp * (z - (DaysAgo / Interval) )
							
							
						ok


						if chartPeriod = "Monthly"                              ### MONTHLY
							Year    = Year - 4
							cDate2  = "01/01/" + Year
							DaysAgo = DiffDays(cDate1, cDate2)
							x        = HzSp * (z - (DaysAgo / Interval) )
						ok

						###------------------------------------------------------------------------
						### Fetch 2 years data = 24 months 731 days  (23 months 701 days)
						### 483 TradePeriods = 2016-06-01 to 2014-07-01  (701 ActualDays 23 Months)
						### 360 TradePeriods = 2016-06-01 to 2014-12-26  (523 ActualDays 17 Months)
						### 254 TradePeriods = 2016-06-01 to 2015-06-01  (366 ActualDays 12 Months)
						###-------------------------------------------------------------------------

						### DAILY Dates                                        ### DAILY
						
						arrayMonthName = ["Jan","Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
						
						if chartPeriod = "Daily"
							Year    = Year - 1
							if count = 1 exit ok

							Month = number(aDateDMY[2])
							DaysTill30  = (30 - aDateDMY[1]) / Interval       
							
							# See "DayTill30 " + DaysTill30 +nl
							
							for countM = 1 to 17
								cDate2 = AddDays( cDate1, (( (-360) / 17 ) * countM ) )
								DaysAgo = DiffDays(cDate1, cDate2)
								x       = HzSp * (z - ( DaysAgo / 1 ) + DaysTill30 )

								
								
								MonthName =  arrayMonthName[Month]
								drawline( x, 10, x, WinBaseY)
								drawText( x, WinBaseY +20, MonthName  )

								Month = (Month - 1) % 12
									if Month = 0  Month = 12  ok
									if Month = 1
										arrayMonthName[Month] = string(Year)
										Year = Year -1
									ok
							next

						ok
					
				next


			###-----------------------------------------------------------------------------
			### SCALE PRICES RED. Max Price to fit top of chart
			###------------------------------------------------------------------------------

			setpen(penRed)
			z = sizeOfData
			

			###---------------------
			### Draw Line Chart
			###---------------------

			if chartType = "Line"
				x = 1
				yOld = arrayAdjClose[x] * Scale
				xOld = 1

				for x = 1 to z
					y = arrayAdjClose[x] * Scale
					drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

					yOld = y
					xOld = x
				next
			ok

			###-------------------------------------------------------------------
			### Draw BAR CHART
			### Needs High Low Close prices. Splits ratio of AdjClose to Close
			###-------------------------------------------------------------------

			if chartType = "Bar"
				for x = 1 to z
					SplitAdjRatio = ( arrayAdjClose[x] / arrayClose[x] )
					
					yHi =  arrayHigh[x] * Scale * SplitAdjRatio	### Split Adj
					yLo =   arrayLow[x] * Scale * SplitAdjRatio
					yCl = arrayClose[x] * Scale * SplitAdjRatio
							
					# See "ScaleHi " + ScaleHi  +" Scale " + Scale +" SpliAdjRatio " + SplitAdjRatio +" Index " +x +" yHi " +yHi +" yLo " +yLo +" yCl " + yCl +" Hi " + arrayHigh[x] +" Low " + arrayLow[x] +" Close " + arrayClose[x] + arrayLow[x] +" AdjClose " + arrayAdjClose[x]+nl
					
					###---------------------------------------------
					### If Huge Split then High to Low exaggerated
					###---------------------------------------------
					
					if yHi > yLo * 1.25
						drawline( (x*HzSp), WinBaseY -yLo , (x*HzSp), WinBaseY - yCl )  ### Low - Low
						
					else
						drawline( (x*HzSp),    WinBaseY -yHi , (x*HzSp),    WinBaseY - yLo )  ### High - Low
						drawline( (x*HzSp) -1, WinBaseY -yCl , (x*HzSp) +1, WinBaseY - yCl )  ### Close Notch
					ok
					
				next
			ok

			
			###--------------------------
			### DRAW MOUNTAIN CHART
			###--------------------------

			if chartType = "Mountain"
				for x = 1 to z
					y = arrayAdjClose[x] * Scale
					drawline( (x*HzSp), WinBaseY , (x*HzSp), WinBaseY - y)
				next
			ok

			###--------------------------
			### DRAW ACTUAL CHART
			### drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)
			###--------------------------
			
			if chartType = "Actual"
				### PreSplits --- AAPL 
				setpen(penBlue)
				x = 1
				yOld = arrayAdjClose[x] * ScaleHi
				xOld = 1

				for x = 1 to z
					y = arrayClose[x] * ScaleHi
					drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

					yOld = y
					xOld = x
				next			
				
				### Adjusted --- MORL big dividends
				setpen(penRed)
				x = 1
				yOld = arrayAdjClose[x] * ScaleHi
				xOld = 1

				for x = 1 to z
					y = arrayAdjClose[x] * ScaleHi
					drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

					yOld = y
					xOld = x
				next				
				
			ok

				
						
			###-------------------------------------
			### Draw LOG CHART
			### y / 10 is percent of maxHighPrice
			###-------------------------------------


			if chartType = "Log"

				x = 1
				yOld =  log( arrayAdjClose[x] ) * scaleLog * log((arrayAdjClose[x]  / maxHighPrice ) *   10 * Magnify)          ### Last Price
				xOld = 1

				for x = 1 to z
					pL = log( arrayAdjClose[x] ) * log( (arrayAdjClose[x]  / maxHighPrice ) * 10 * Magnify)
					yL = scaleLog * pL
					y  = yL
					drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

					yOld = y
					xOld = x

				next
			ok


			###-------------------------------------------------------
			### DRAW HEIKENASHI CHART. 
			###
			### Use SP for Spacing Horizontal
			### Start PriceIndex[x] so that last price fits chart
			###
			###             x   1   2   3   4   5   6   ... 360
			### horizontal S=2  2   4   6   8   10  12 
			###
			###             x   180 181 182 183 184 185 ... 360
			### horizontal S=4  4   8   12  16  20  24
			###
			###             x   240 240 243 244 245 246 ... 360
			### horizontal S=6  6   12  18  24  30  36 
			###-------------------------------------------------------
			
			if chartType = "HeikenAshi"
				HeikenAshiCalc()				 	### >>> CALL CALC 
				
				z     = sizeOfData                  ### 1 is Newest  z is Oldest  entry
				SP    = HzSp 
				Start = 1    ### 360 * 2/4  = 180 
				
				H = 1                           ### INC draw price horizontal spacing H = H+1
				for x = Start to z              ### 180 to 360
				
				
					###-------------
					### Color Gray
					
					setpen(penGray)
					yHi = haHigh[x] * Scale 
					yLo =  haLow[x] * Scale 
																		 
					drawline( (H*SP), WinBaseY -yHi , (H*SP), WinBaseY - yLo )     
					
					###------------------------
					### Color Green or Read 
					
					setpen(penRed)                                      ###  Red   = SELL                           
					if( haClose[x] > haOpen[x] ) setpen(penGreen) ok    ###  Green = BUY
					
					yOp =  haOpen[x] * Scale 
					yCl = haClose[x] * Scale
					
					drawline( (H*SP   ), WinBaseY -yOp , (H*SP   ), WinBaseY - yCl )  ### Thick - SP lines
					drawline( (H*SP +1), WinBaseY -yOp , (H*SP +1), WinBaseY - yCl )  ### Thick - 2 lines
					drawline( (H*SP +2), WinBaseY -yOp , (H*SP +2), WinBaseY - yCl )  ### Thick - 2 lines
					
					H = H +1    ### <<<<< INC H+1
				next                            
		
			ok  
			
			###--------------------------------------------------

			
				
			
			###------------------------------------------------------------------------------
			### DRAW MvgAVG CHART - Use Blue Pen
			### Check MAvg " + CheckMAvg.isChecked()  +nl   ### 0 - Uncheked  1 - Checked
			###------------------------------------------------------------------------------

			setpen(penBlue)
			
			#if chartType = "Line"
			if CheckMAvg.isChecked() = 1
				aMvgAvg = []
				aMvgAvg = MovingAverage(arrayAdjClose, 30)
					# See "Returned MAvg " +nl
					# See aMvgAvg +nl
				
				x = 1
				yOld = aMvgAvg[x] * Scale
				xOld = 1

				for x = 1 to z
					y = aMvgAvg[x] * Scale
					drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

					yOld = y
					xOld = x
				next
			ok
			

		
			###------------------------------------------------------------------------------
			### DRAW DIVIDEND CHART 
			### Magnify by 5X  -
			### -- $1 quarter =>  $5  ==> Mentally: Double / 10 => Quarterly estimate
			### Mountain Style - Use Blue Pen
			### CheckDividend.isChecked() = 1   ### 0 - Uncheked  1 - Checke
			###----------------------------------------------------------------------
			            ###
						###    1       2    
						###	Date,      Dividends
						###	2016-07-12,0.310000
						###	2016-06-09,0.339000
						###	2016-05-11,0.213000
						###	2016-04-08,0.259000		yyyy-mm-dd => Date : dd/mm/yyy
						###---------------------------


			setpen(penGreen)
			
			if CheckDividend.isChecked() = 1
				returnCode = FetchData($symbol, "Dividend")

				MagnifyDiv = 5
				z = len(arrayDivDate)
				
				for x = 2 to z		
				
					if( arrayDivDate[x] != arrayDivDate[x-1] )

						DivDate   = substr(arrayDivDate[x], "-" , "")		      ### To be able to compare with = sign
						PriceDate = substr(arrayDate[1],    "-" , "")
							
								if ( DivDate > PriceDate   )
										
									aDivDate = Split(arrayDivDate[x], "-")
									cDate2   = aDivDate[3] +"/"+ aDivDate[2] +"/"+ aDivDate[1]
									DaysAgo  = DiffDays(cDate1, cDate2)
									
									hPos     = HzSp * (z - (DaysAgo / Interval) )
																								
									y = arrayDividend[x] * Scale * MagnifyDiv
									drawline( (hPos), WinBaseY , (hPos), WinBaseY - y)		

								ok	
					ok
					
				next
			ok			
			
			
			
			###-----------------------------------------
			### END of DRAW TYPES
			###-----------------------------------------

			###------------------------
			### Draw Line Chart FRAME

			setpen(penGreen)
			  
			# drawline(        1,            1, BoxWidth,            1 )             ### WinTop line horizonal
			drawline(        1,            1,        1, BoxHeight    )             ### WinLeft Line vetical            
			drawline(        1, BoxHeight -1, BoxWidth, BoxHeight -1 )             ### Bottom Line horizontal
			# drawline( BoxWidth,            1, BoxWidth, BoxHeight    )             ### WinRight Line vertical                      
			
			# drawline( BoxWidth / 2 ,             1 , BoxWidth / 2 , BoxHeight     )   ### Central vertical   
			# drawline(            1 , BoxHeight / 2 , BoxWidth     , BoxHeight / 2 )   ### Central horizontal                                          
			
			###--------------------------------------------------
			### Win Title Info
			
			# win1{ setwindowtitle("DrawButton Win: " +  WinWidth + "x" + WinHeight + " --- Box " + BoxWidth  + "x" + BoxHeight  + 
			# 		  " --- LeftTop " +  WinLeft + "-"   + WinTop  + " --- RightBot" + WinRight + "-" + WinBottom  +
			# 		  " --- sizeOfData " + sizeOfData + " Low "	+ minLowPrice + " High " + maxHighPrice + " StartDate " + StartDate + " Today " + Today						  
			# 		) }
			
			win1{ setwindowtitle("Symbol:  " + $symbol +"  --- Low "	+ minLowPrice +" High " + maxHighPrice +" Cur " + arrayClose[360]	) }			
			
			###--------------------------------------------------

		endpaint()
	}
	label1 { setpicture(p1) show() }
				
return


###==================================
### FUNCTION ROUTINES
###==================================

###-----------------------------------
### FUNCTION GetBasket  BUTTON --- Tickers
###-----------------------------------

Func GetBasket
		TickersFile = comboTickersBasket.currentText()
		TickersUse  = TickersDir + TickersFile 
	   
		cFile = read(TickersUse)
		cFile = substr(cFile,windowsnl(),nl)
		aList = str2list(cFile)

		###----------------------------
		### WORKS. the EOF ignored
		###----------------------------
	
		counter = list1.count()
		# See "Counter1 " +counter +nl
		 
		for i = counter to 0 step -1
			list1.takeItem(i)
		next
		
		# counter = list1.count()
		# See "Counter2 " +counter +nl
		
		for i = 1 to len(aList)     
			if( aList[i] != '')
					 # See 'b-List__' + aList[i] + '__' +nl
				list1.additem( aList[i] )
			ok
		next  
	return				

###---------------------------------
### FUNC SelectSymbol  -- BUTTON
###---------------------------------

func SelectSymbol
            # btn1.settext( string(list1.currentrow() ))
            # btn1.settext( list1.item(list1.currentrow()).text() )

		###----------------------------------
		### Use Selected Row
        ### Fill in the Symbol Field
        ### Call DRAW function
		###
		### Position = list1.currentrow() 
		### PosData  = list1.item(list1.currentrow()).text()
		### See " Next Pos " + Position +" PosData " + PosData +nl
		### list1.setcurrentrow(Position +1, 3)
		
        Item = list1.item(list1.currentrow()).text()
        lineedit1.settext(Item)
        Draw()

return

###-------------------------------
### FUNC NextSymbol -- BUTTON
###-------------------------------

func NextSymbol
            
		###----------------------------------
		### Use Selected Current Row +1
	
		Position = list1.currentrow() 
		
		TickersNbr = list1.count()			### Size of Row Count
		# See " Next Pos " + Position +" TickersNbr " + TickersNbr +nl
		
		if Position = TickersNbr
			return
		ok
		list1.setcurrentrow(Position +1, 3)
		
        Item = list1.item(list1.currentrow()).text()
        lineedit1.settext(Item)
        Draw()

return

###------------------------------
### FUNC PrevSymbol -- BUTTON
###------------------------------

func PrevSymbol
            
		###----------------------------------
		### Use Selected Current Row -1
		
		Position = list1.currentrow() 
		# See " Next Pos " + Position +nl
		
		if Position = 0
			return		### Do NOT go Less
		ok
		list1.setcurrentrow(Position -1, 3)
		
        Item = list1.item(list1.currentrow()).text()
        lineedit1.settext(Item)
        Draw()

return

###---------------------------------------
### FUNC Split  By Dot
### Call:      cStr = Split(Name, ".")
###--------------------------------------

Func Split cstring, delimiter
	cStrList = str2list(substr(cstring, delimiter, nl))
return cStrList	

###------------------

###----------------
### Func Xmin
###----------------

Func Xmin aList
  min = aList[1]
  for x in aList
    if x < min
      min = x
    ok
  next
return min

###----------------
### FINC Xmax
###----------------

Func Xmax aList
  max = aList[1]
  for x in aList
    if x > max
      max = x
    ok
  next
return max

###----------------


###======================================================
### FUNC FetchData -- from YAHOO
###======================================================


    ###-------------------------------------------------
    ### Join as URL to fetch Symbol data from Yahoo
    ###
    ### 	$urlbase =             "http://ichart.yahoo.com/table.csv?s="
    ### 	$urlbase = "http://real-chart.finance.yahoo.com/table.csv?s="
    ### 	http://ichart.yahoo.com/table.csv?s=AAPL&a=05&b=31&c=2009&d=05&e=31&f=2016&g=w&ignore=.csv
    ### 	http://real-chart.finance.yahoo.com/table.csv?s=AAPL&a=04&b=31&c=2014&d=04&e=31&f=2016&g=w&ignore=.csv
    ###
    ###-------------------------------------------------
	###
	### returnCode = FetchData($symbol,"Price")
	### returnCode = FetchData($symbol,"Dividend")
	###-------------------------------------------------

Func FetchData $thisSymbol, TypeOfData

    TimePeriod = comboTimePeriod.currentText()  ### "w-Weekly", "d-Daily", "m-Monthly, v-dividend"
	
	Today = Date()                              ### 14/05/2016  mm/dd/yyyy
    aDateDMY = split(Today, "/")               ### 14 05 2016

        if TimePeriod = "Weekly"
                #Period = 7              					### 7 years of Weekly => 364 periods
                $DayWeekMonth = "w"
				StartDate = AddDays(Today, ( -365.25 * 7 )) 
				
        but TimePeriod = "Daily"
                #Period = 2              					### 2 years of Daily => 260 -> 520 periods
                $DayWeekMonth = "d"
				StartDate = AddDays(Today, ( -580 ))		### 	### 524 days ~ 360 stock periods
				
        else TimePeriod = "Monthly"
                #Period = 30             					### 30 years of Monthly => 360 periods
                $DayWeekMonth = "m"
				StartDate = AddDays(Today, ( -365.25 * 30 ))
        ok

		
		
		###------------------------
		### DIVIDEND  
		
		if TypeOfData = "Dividend"
				$DayWeekMonth = "v"
		ok



    ###--------------------------------------------------------------------
    ###   HistoryDate MM/DD/YYYY  Month -1.  Ex. 03 => April 2015-04-15
	###
	###   URL - Put it together -- $urlbase + $symbol + $urlbaseType
    ###--------------------------------------------------------------------

	arrayStartDate = split(StartDate, "/")
		
    $MonthStart   = arrayStartDate[2]            ###  "05"	STARTDATE
    $DayStart     = arrayStartDate[1]            ###  "14"
    $YearStart    = arrayStartDate[3]            ###  "2009"

    $MonthEnd     = aDateDMY[2]           		 ###  "05"    TODAY
    $DayEnd       = aDateDMY[1]            	 ###  "14"
    $YearEnd      = aDateDMY[3]            	 ###  "2016"

    ### $DayWeekMonth = "w"                 	###  SET in TimePeriod --- OPTIONS are "d" daily, "w" weekly, "m" monthly, v-dividend

    
    $symbol      =  $thisSymbol             ### "AAPL"    
                    See "Symbol_" +$symbol +"_" +nl


    $urlbase     = "http://ichart.yahoo.com/table.csv?s="
    $urlbaseType = "&a=" + $MonthStart + "&b=" + $DayStart + "&c=" + $YearStart + "&d=" + $MonthEnd + "&e=" + $DayEnd + "&f=" + $YearEnd + "&g=" + $DayWeekMonth + "&ignore=.csv"

    $url         = $urlbase + $symbol + $urlbaseType
                   ### See "Sym " + $symbol +" URL " + $url + nl + nl

    ###--------------------------------
    ### Download Data and Save to File
    ###--------------------------------

		###-------------
		### DIVIDEND
		
		if TypeOfData  = "Dividend"
			dStr= download($url)
			write("dividend.txt",dStr)
			ExtractDividendData(dStr)
			return
		ok
 
		###-----------------------------
		### PRICES - Default Selection 
		
		cStr= download($url)
		write("download.txt",cStr)

		
			###-----------------------------------------------
			### Date,Open,High,Low,Close,Volume,Adj Close
			### Check if Data was Returned
			###-----------------------------------------------
			
			### PRICES
			lineOne = substr( cStr, 1, 4)
			if lineOne != "Date"
				See "Yahoo - Ticker not found xxx" + $thisSymbol + "xxx" +nl
				return "BAD"
			ok

			ExtractPriceData(cStr)
	

return



###-------------------------------------------------
### FUNC ExtractPriceData
###-------------------------------------------------

Func ExtractPriceData   cStr

    ###------------------------------------------------------------------------------
    ### READ data and extract CLOSE Price into List
    ###    1    2    3    4   5     6      7
    ### 1. Date,Open,High,Low,Close,Volume,Adj Close
    ### 2. 2016-05-23,704.25,715.00,696.419983,714.909973,2826WinBaseY,714.909973
    ### 3. 2016-05-16,710.130005,714.469971,688.76001,702.799988,4134700,702.799988
    ###
    ###--------------------------------------------------------------------------------

    

    aList = str2list(cStr)
    del(aList,1)										### Remove - First line is Header
    
    sizeOfData = len(aList)
    z = sizeOfData
	
	# See "Old sizeOfData " + sizeOfdata  +nl
	
	### Remove Add items to data fill if quote history is too short
	if sizeOfData > 360 
		for z = z to 360 +1 step -1						### Stop Short when decrementing 361
			# See "Del "  +z + " Line " + aList[z] +nl
			Del(aList,z )								### Delete older lines
		next
	ok	
	
	if sizeOfData < 360
		for z = z  to 360 -1  							### Stop Short when incrementing 359
			Add(aList, aList[z] )						### Add repeat of oldest line
			# See "Add "  +z + " Line " + aList[z] +nl			
		next	
	ok
	
	sizeOfData = len(aList)
    z = sizeOfData
	
	# See "New sizeOfData " + sizeOfdata  +nl
      
    ### Clear the arrays for new stock
    arrayDate       = []
    arrayOpen       = []
    arrayHigh       = []
    arrayLow        = []
    arrayClose      = []
    arrayVolume     = []
    arrayAdjClose   = []      

    for L1 in aList
        cStr = Split(L1, ",")                       ### Split fields in line
        Add(arrayDate,     cStr[1] )                ### ADD Data to arrayLists
        Add(arrayOpen,     number(cStr[2] ) )
        Add(arrayHigh,     number(cStr[3] ) )
        Add(arrayLow,      number(cStr[4] ) )
        Add(arrayClose,    number(cStr[5] ) )
        Add(arrayVolume,   number(cStr[6] ) )
        Add(arrayAdjClose, number(cStr[7] ) )
    next

    ###------------------------------------------------------------------------------------------
    ### Reverse the Input Price Data because the Newest is 1  and the Oldest is z 362 from Yahoo
    ### Convert to Oldest 1 2 3  . . . 360 361 362  Newest
    ###------------------------------------------------------------------------------------------
    
    arrayDate     = reverse(     arrayDate )
    arrayOpen     = reverse(     arrayOpen )
    arrayHigh     = reverse(     arrayHigh )
    arrayLow      = reverse(      arrayLow )
    arrayClose    = reverse(    arrayClose )
    arrayVolume   = reverse(   arrayVolume )  
    arrayAdjClose = reverse( arrayAdjClose )
    
	###--------------------------------------------------------------------
	### Note: AAPL Split 7:1  maxHighPrice 129.88 maxActualHiPrice 705.07
	
    maxHighPrice      = max(arrayAdjClose)
    minLowPrice       = min(arrayAdjClose)

    maxActualHiPrice  = max(arrayHigh)
    minActualLoPrice  = min(arrayLow)



return


###----------------------------------------------------



###-------------------------------------------------
### FUNC ExtractPriceData
###-------------------------------------------------

Func ExtractDividendData  dStr

    ###------------------------------------------------------------------------------
    ### READ Dividend dataa nd extract Date and Dividends into List
    ###    1       2    
	###	Date,      Dividends
	###	2016-07-12,0.310000
	###	2016-06-09,0.339000
	###	2016-05-11,0.213000
	###	2016-04-08,0.259000
	###---------------------------
    

    aList = str2list(dStr)
    del(aList,1)										### Remove - First line is Header

    sizeOfData = len(aList)								### 7 Years ~ 28 Quarterly, 88 Monthly, 30 Year = 360 Monthly
    z = sizeOfData
	
	#See "Old sizeOfData " + sizeOfdata  +nl
	
	### REMOVE ADD ITEMS to data fill if quote history is too short
	
	if sizeOfData = 0	
	    aDateDMY = Split(date(),"/")
		newDate  = aDateDMY[3] +"-"+ aDateDMY[2] +"-"+ aDateDMY[1]	### Yahoo format yyyy-mm-dd  Ring dd-mm-yyyy
		
		newInfo = newDate + "," + "0.0"
		Add(aList, newInfo)

		for z = 1  to 360 -1  							### Stop Short when incrementing 359
			Add(aList, aList[z] )						### Add repeat of oldest line
		next	
	ok	

	
	if sizeOfData > 360 
		for z = z to 360 +1 step -1						### Stop Short when decrementing 361
			# See "Del "  +z + " Line " + aList[z] +nl
			Del(aList,z )								### Delete older lines
		next
	ok	
	
	if sizeOfData < 360
		for z = z  to 360 -1  							### Stop Short when incrementing 359
			Add(aList, aList[z] )						### Add repeat of oldest line
			# See "Add "  +z + " Line " + aList[z] +nl			
		next	
	ok
	
	
	sizeOfData = len(aList)
    z = sizeOfData
	
	#See "New sizeOfData " + sizeOfdata  +nl
      
    ### Clear the arrays for new stock
    arrayDivDate    = []
    arrayDividend   = []
     

    for L1 in aList
        dStr = Split(L1, ",")                        ### Split fields in line
        Add(arrayDivDate,   dStr[1] )                ### ADD Data to arrayLists
        Add(arrayDividend,  number(dStr[2] ) )
    next

    ###------------------------------------------------------------------------------------------
    ### Reverse the Input Price Data because the Newest is 1  and the Oldest is z 362 from Yahoo
    ### Convert to Oldest 1 2 3  . . . 360 361 362  Newest
    ###------------------------------------------------------------------------------------------
    
    arrayDivDate     = reverse( arrayDivDate )
    arrayDividend    = reverse( arrayDividend )

return



###-----------------------------------------------------
### FUNC MovingAverage
###-----------------------------------------------------
### MovingAverage  
### timePeriod 10 =>  1-10  2-11 3-12 4-13  Diff is 9
### Newest price is Index 1 Oldest price is Index 362
###------------------------------------------------------

Func MovingAverage arrayPrices, timePeriod

    arrayMvgAvg  = []                               ### Results go in this array
    z = sizeOfData                                  ### 1 is Newest  z is Oldest  entry                         
    
    periodFix  = timePeriod - 1                     ### 1 to 10 =>  (1+ (10-1)) => 10
    sumPrices  = 0
    
    ###-------------------------
    ### First MAvg Sum 1 to 10
    ###-------------------------
    
    for i = 1 to  timePeriod                        ### Sum from 1 to 10
        sumPrices = sumPrices + arrayPrices[i]
        mvgAvg    = sumPrices / i
        Add( arrayMvgAvg, mvgAvg)   
        
            # See " Ind " + i + " sumPrices " +sumPrices + " curPrice " + arrayPrices[i] + " mvgAvg " +mvgAvg + " Z " +z + " P " +timePeriod  +nl

    next
    
    
    ###-----------------------------
    ### Second MAvg Sum  11 to 362
    ###-----------------------------
    
    for i = timePeriod + 1 to z 
        sumPrices = sumPrices - arrayPrices[i-timePeriod] + arrayPrices[i]  ### 11-10 = Drop 1, Count 2 to 11
        mvgAvg    = sumPrices / timePeriod                                  ### Divide by 10
        Add (arrayMvgAvg, mvgAvg)
        
             # See " Ind " +i + " Sum " +sumPrices + " curPrice " + arrayPrices[i] + " mvgAvg " +mvgAvg +nl
    next
    
        
return arrayMvgAvg

###----------------------------------


###-----------------------------------
### FUNC HeikenAshiCalc
###-----------------------------------

Func HeikenAshiCalc 

        ###---------------------------------------
        ###
        ### Read more: Heikin-Ashi: A Better Candlestick 
        ### Investopedia http://www.investopedia.com/articles/technical/04/092204.asp#ixzz4BJGWATL0 
        ###         
        ### haClose = ( O+H+L+C ) /4
        ### haOpen  = ( haOpen (previous bar) + haClose (previous bar) ) /2
        ### haHigh  =   Maximum(H, haOpen, haClose)
        ### haLow   =   Minimum(L, haOpen, haClose)     
        ###
        ###---------------------------------------
        
        z = sizeOfData  
        
        ###-----------------------------------------------------------
        ### Make Heiken Ashi Arrays same size as Input Price Data
        ###-----------------------------------------------------------
		


        
        haOpen  = list(z)           
        haHigh  = list(z) 
        haLow   = list(z) 
        haClose = list(z)   

        ###-----------------------------------
        ### Copy List  from arrayInput to HA
        ###-----------------------------------
		
		### APPLE Split causes problems unless normalized for Split
		### 2014-06-02, 633, 651, 622, 645, 82564300, 88		
		### 2014-06-09,  92,  95,  90,  91, 58629400, 87      <<< Previous day change
		###
		### GOOGLE Split Problem ---
		### 2014-04-07,  544,  568,  530,  537, 3388900, 537  <<< Previous day
		### 2014-03-31, 1130, 1144,  544,  545, 4357600, 545  <<< Same Day change
		### 2014-03-24, 1184, 1184, 1102, 1120, 5637600, 560
		###
        
		for i = 1 to z
			ScaleAdjClose = arrayAdjClose[i] / arrayClose[i]
             haOpen[i] =  arrayOpen[i]  * ScaleAdjClose 
             haHigh[i] =  arrayHigh[i]  * ScaleAdjClose
              haLow[i] =   arrayLow[i]  * ScaleAdjClose 
            haClose[i] = arrayClose[i]  * ScaleAdjClose
			
			if haHigh[i] > 1.25 haLow[i]
				haHigh[i] = haClose[i]
				haOpen[i] = haClose[i]
			ok
			
			
				# See "I " +i +" ScaleAdj " +ScaleAdjClose +" haClose " +haClose[i] +" arrayClose " +arrayClose[i] +" arrayAdj " +arrayAdjClose[i] +nl
		next
        
        ###------------------------------------
        ### Do the rest of the array
        ### Find Max and Min using aList array
        ###-------------------------------------

        
        for   i = 2 to z
		
	        haClose[i] = ( haOpen[i] + haHigh[i] + haLow[i] + haClose[i] ) / 4	 	### AVG of 4 Current
                         
             haOpen[i] = ( haOpen[i-1] + haClose[i-1] ) / 2 						### AVG of 2 Previous Calc
            
                 aList = [ haHigh[i], haOpen[i], haClose[i] ]						### MAX
             haHigh[i] =   max( aList )
            
                 aList = [ haLow[i], haOpen[i], haClose[i] ]						### MIN
              haLow[i] =   min( aList )			  
			  

        next

return



###-----------------------------------
###-----------------------------------
