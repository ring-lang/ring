// Bert Mariani
// GetHistoryDraw-57-A2-YieldMACD.ring
//
// cd C:\MyStuff\AA-GetQuotesHistoryDraw
// c:\ring\bin\ring.exe  GetQuotesHistoryDraw-57-A5-YieldMACD.ring
//
// HISTORY
// $url = 'https://query1.finance.yahoo.com/v8/finance/chart/AAPL?metrics=high?&interval=1wk&range=1mo'
//
// DIVIDENDS
// $url1 = 'view-source:https://www.tickertech.net/bnkinvest/cgi/?n=2&ticker='
// $url1 =             'https://www.tickertech.net/bnkinvest/cgi/?n=2&ticker='
// $url2 = 'BMO.CA'
// $url3 = '&js=on&head=1&a=historical&w=dividends2&noform=1&footer=off'
// $url  =  $url1 + $url2 + $url3
//----------------------------------------------------------------------

load "guilib.ring"
load "libcurl.ring"
load "stdlibcore.ring"
load "jsonlib.ring"

/*
 +---------------------------------------------------------------------------------------------------------
 +        Program Name : GetQuotesHistoryDraw-v1.2.ring
 +        Date         : 2016.04.21
 +        Author       : Bert Mariani
 +        Purpose      : Fetch stock quotes history from finance.yahoo.com and Draw Chart

 +---------------------------------------------------------------------------------------------------------
*/

###-------------------------------------------------

Today     = " "
YesterDay = " "


Table1 = NULL
pBox0  = NULL ; pBox1 = NULL ; pBox2 = NULL ; pBox3 = NULL ; pBox4 = NULL ; pBox5 = NULL ; pBox6 = NULL ;
cbo0   = NULL ; cbo1  = NULL ; cbo2  = NULL ; cbo3  = NULL ; cbo4  = NULL ; cbo5  = NULL ; cbo6  = NULL ;

sortedlist  = []
companyList = []

###--------------------------------------------------
### Draw Mouse Line
nX = 0  nY = 0 # initial position of cursor
fX = 0  fY = 0 # final   position of cursor
oX = 0  oY = 0 # old     position of cursor

xPos    = 100
yPos    = 100

xWidth  = 600
yHeight = 600   ### Canvas position on Screen

Picasso    = 0   ### pointer to Painter
imageStock = 0   ### pointer to image 
daVinci    = 0
MonaLisa   = 0
Canvas     = 0

###--------------------------------------------------
### NEED NEED  NEED
### MusicList

    GetDataMusicList         = "GetDataMusicList.txt"                 ###  List of Songs to Play.  In this Current Directory
    LastPlayed = 1                                                    ###  Flag Inc+1 every video. List 1,2,3,4 ... NO 0 zero


###--------------------------------------------------
### NEED  NEED  NEED
### List of TICKER SYMBOLS xxx.tickers file REQUIRED

        ###-------------------------------------
        # FORMAT
        # Symbol Name           Group
        # A     AgilentTechnolo Health
        # AA    AlcoaInc        Materials
        # AAL   AmericanAirline Industrials
        ###---------------------------------------

    TickersDir  = CurrentDir()
    TickersList = []
    TickersUse  = ""



###========================================================================

###------------------------------------------------------
### DRAW MAIN PAGE - CHART  size 1000 x 750
###
### Place Buttons, Labels, CheckBoxes in their place
###-----------------------------------------------------


###--------------------
### Create arrayLists
    aHistory = []
    arrayDate     = list(360)
    arrayOpen     = list(360)
    arrayHigh     = list(360)
    arrayLow      = list(360)
    arrayClose    = list(360)
    arrayVolume   = list(360)
    arrayAdjClose = list(360)

    arrayDivDate  = list(360)
    arrayDividend = list(360)

###----------------------------------------------------
### For BALANCE calc for 2 stocks re-balancing
### Pass Ticker Symbol ZXY to FetchData as an exception
    Z1arrayDate     = list(360)
    Z1arrayOpen     = list(360)
    Z1arrayHigh     = list(360)
    Z1arrayLow      = list(360)
    Z1arrayClose    = list(360)
    Z1arrayVolume   = list(360)
    Z1arrayAdjClose = list(360)

    Z2arrayDate     = list(360)
    Z2arrayOpen     = list(360)
    Z2arrayHigh     = list(360)
    Z2arrayLow      = list(360)
    Z2arrayClose    = list(360)
    Z2arrayVolume   = list(360)
    Z2arrayAdjClose = list(360)

    Z3arrayDate     = list(360)
    Z3arrayOpen     = list(360)
    Z3arrayHigh     = list(360)
    Z3arrayLow      = list(360)
    Z3arrayClose    = list(360)
    Z3arrayVolume   = list(360)
    Z3arrayAdjClose = list(360)

    Z4arrayDate     = list(360)
    Z4arrayOpen     = list(360)
    Z4arrayHigh     = list(360)
    Z4arrayLow      = list(360)
    Z4arrayClose    = list(360)
    Z4arrayVolume   = list(360)
    Z4arrayAdjClose = list(360)

    Normalize            = 0  ### How many inital shares can be bought for 100000. calc value for all weeks
    NormalizeHigh        = 1
    NormalizeActualHigh  = 1  ### Compare stocks - highest price
    NormalizePercentHigh = 1  ### Compare stocks - highest percent


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
    WinLeft   = 180                 ### 80    Window position on screen
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
   
   BoxOffsetPrice  = 45
   BoxOffsetLine   = 60


###---------------------------
### label2 LEFT BOX SIZE             ###  setgeometry(0, 40, 80, BoxHeight)
    LBoxLeft   = 00                  ###  Start corner   Label1 Box Start Position inside WIN1
    LBoxTop    = 40                  ###  Start corner
    LBoxWidth  = 80                  ###  End   corner   Label1 Box Size
    LBoxHeight = WinHeight -80       ###  End   corner

    HzSp       = 2                   ###  Horizontal Spacing when drawing lines

###---------------------------
    ChartType = "Line"

###-----------------------------
### PEN Colors
###-----------------------------



    colorRed    = new qcolor() { setrgb(204,000,000,255) }
    colorGreen  = new qcolor() { setrgb(000,204,000,255) }
    colorBlue   = new qcolor() { setrgb(000,000,255,255) }
    colorGray   = new qcolor() { setrgb(128,128,128,255) }

    colorBrown  = new qcolor() { setrgb(153,076,000,255) }
    colorBlack  = new qcolor() { setrgb(000,000,000,255) }
    colorWhite  = new qcolor() { setrgb(255,255,255,255) }
    colorOrange = new qcolor() { setrgb(255,128,000,255) }

    colorYellow = new qcolor() { setrgb(255,255,000,255) }
    colorPurple = new qcolor() { setrgb(153,153,255,255) }
    colorPink   = new qcolor() { setrgb(255,051,255,255) }
    colorLime   = new qcolor() { setrgb(128,255,000,255) }

    penBlue1   = new qpen() { setcolor(colorBlue)   setwidth(1) }
    penRed1    = new qpen() { setcolor(colorRed)    setwidth(1) }
    penGreen1  = new qpen() { setcolor(colorGreen)  setwidth(1) }
	penBlack1  = new qpen() { setcolor(colorBlack)  setwidth(1) }
	
    penRed    = new qpen() { setcolor(colorRed)    setwidth(2) }
    penGreen  = new qpen() { setcolor(colorGreen)  setwidth(2) }
    penBlue   = new qpen() { setcolor(colorBlue)   setwidth(2) }
    penGray   = new qpen() { setcolor(colorGray)   setwidth(2) }
															
    penBrown  = new qpen() { setcolor(colorBrown)  setwidth(2) }
    penBlack  = new qpen() { setcolor(colorBlack)  setwidth(2) }
    penWhite  = new qpen() { setcolor(colorWhite)  setwidth(2) }
    penOrange = new qpen() { setcolor(colorOrange) setwidth(2) }
															
    penYellow = new qpen() { setcolor(colorYellow) setwidth(2) }
    penPurple = new qpen() { setcolor(colorPurple) setwidth(2) }
    penPink   = new qpen() { setcolor(colorPink)   setwidth(2) }
    penLime   = new qpen() { setcolor(colorLime)   setwidth(2) }

    penGreen3  = new qpen() { setcolor(colorGreen)  setwidth(2) }


    arrayPenColor = [penRed,penBlue,PenRed,PenGreen,PenBlack,PenOrange,PenPurple,PenLime,PenYellow]

###---------------------------
    Today       = Date()
    StartDate   = Date()

###---------------------------
    itemList  = ["Symbol","Name","Group"]   ### Fill in Window Title Bar

    arrayRatio  = []
    TotalRatio  = 0     ###  RatioCalc() for this stock. Used for Ranking system
    companyList = []    ###  Calc Ratios for each company on a structured array

###-------------------------------------------
### imageStock Size for growing image
    imageW = 100 ;  imageH = 100 ; GrowBy = 8

   
###-------------------------------------------
   
   
###==============================================
### QAPP - WIN1  ==>> START HERE <<===
###
### Position of Buttons, DropDown, Actions
###==============================================
   

   
###==============================================
### QAPP - WIN1  ==>> START HERE <<===
###
### Position of Buttons, DropDown, Actions
###==============================================

winApp1 =New qapp
{

    win1 = new qMainWindow()
    {
    	setWinIcon(self,"appicon.png")
        ###--------------------------------------------
        ### FILTERS 
         
        
        myfilter = new qallevents(win1)

            ###------------------------------------------
            ### Mouse Event
        
            myfilter.setMouseButtonPressEvent("pPress()")
            myfilter.setMouseButtonReleaseEvent("pRelease()")
            myfilter.setMouseMoveEvent("pMove()")
        
            installeventfilter(myfilter)
        
            ###------------------------------------------
            ### ReSizeEvent ... Call WhereAreWe function

            myfilter.setResizeEvent( "WhereAreWe()")
            myfilter.setMoveEvent( "WhereMoved()" )  

       //----------------------------------------
       
        Canvas = new qlabel(win1)
        {
            ### daVinci paints the MonaLisa on the Canvas
            MonaLisa  = new qPixMap2( 2000, 2000)

            daVinci = new qpainter()
            {
               begin(MonaLisa)
               #endpaint()                  ### This will Stop the Painting

               ###-------------------------------
               ### Draw Yellow Rect in the Middle
                   #setBrush(brushS)             ### Brush - Solid, Yellow    
                   #setpen(penBlue)
                   #drawRect(indent, indent, xWidth - (2*indent), yHeight - (2*indent))    
            }

            setPixMap(MonaLisa)
        }       
        
        //-----------------------------
    
    
        ###--------------------------
        ### READ TICKERS LIST

        mylist = dir(TickersDir)

            for x in mylist
                Name = x[1] ; Type = x[2]

                if Type = 1
                    #Type 1 Directory
                    #See " Dir.Type " + Type + " Dir.: " + Name +nl
                else
                    #Type 2 File
                    #See " FileType " + Type + " File: " + Name +nl

                    cStr = Split(Name, ".")                 ### ["GetTkr1.tickers", "GetTkr2.tickers"]

                    if cStr[2] = "tickers"
                        #See " Tkr.Type " + Type + " File: " + Name +nl
                        Add( TickersList, Name )
                    ok
                ok
            next

        # See TickersList
        TickersUse = TickersList[1]                 ### Use Tickers List - first entry

        ###--------------------------------------------------
        ### Read lines for Music List


        if fexists(GetDataMusicList)
            cFile = Read(GetDataMusicList)                ### ("\GetQuotesTickers.tickers")
            cFile = substr(cFile,windowsnl(),nl)
            musicList = str2list(cFile)
        else
            See nl + "musicList NOT found: " + GetDataMusicList +nl
            musicList = ["stock.mp3"]
            MessageBox( "musicList NOT found: " +nl +"--> " + GetDataMusicList +nl + "One line per song example: stock.mp3   " +nl )

        ok

        ###-------------------------------------

        ###-------------------------
        ### BMP Background
        ### WinWidth   WinHeight

            setwindowtitle("QLabel - Display image")
            imageStock = new qlabel(win1) {
                    image = new qpixmap("stock.jpg")
                    AspectRatio = image.width() / image.height()

                    imageW = 200
                    imageH = imageH / AspectRatio

                    setpixmap(image.scaled(imageW , imageH ,0,0))   ### Size-H, Siz-V, Aspect, Transform

                    PosLeft = (BoxWidth  - imageW ) / 2
                    PosTop  = (BoxHeight - imageH ) / 2
                    setGeometry(PosLeft,PosTop,imageW,imageH)

            }

            LabelMan = new qlabel(win1)
            {
                setgeometry(0,10,80,30)
                settext(theTime())          ### ==>> func
            }

            TimerMan = new qtimer(win1)
            {
                setinterval(100)
                settimeoutevent("pTime()")  ### ==>> func
                start()
            }


            TimerMan2 = new qtimer(win1)
            {
                setinterval(1000)
                settimeoutevent("pTime2()")  ### ==>> func
                #start()
            }

            BarMan = new qprogressbar(win1)
            {
                setGeometry(80, 20 , 300, 10)    ###  Position X Y, Length, Thickness
                setvalue(25)                     ###  Percent filled
            }

         

         
         
            ###----------------------------------------------------------        
            ### Position and Size on Screen
            setwindowtitle("GetQuotesHistory-DrawChart using QPainter")
            setgeometry( WinLeft, WinTop, WinWidth, WinHeight)

            win1{ setwindowtitle("Initial Window Position: " +" L " + WinLeft +" T " + WinTop +" Width" + width() +" Height " +  height() ) }



            ###---------------------------
            ### Draw within this WIN BOX

            label1 = new qlabel(win1) {
            setGeometry(BoxLeft, BoxTop, BoxWidth, BoxHeight)
            //setText("RightBox")
            setstylesheet("color: blue ; font-size: 12pt;")
            }

            ###-------------------------------
            ### Draw within this WIN LEFT BOX

            label2 = new qlabel(win1) {
            setgeometry(LBoxLeft, LBoxTop, LBoxWidth, LBoxHeight)
            //settext("LeftBox")
            }



 
            ###------------------------------------------------
            ### Text Field Position and Size ==> TICKER SYMBOL

            lineedit1 = new qlineedit(win1) {
                                setGeometry(BoxLeft +90+50, BoxTop -BoxTop, 70, 20)
            }

            ###--------------------------------------
            ### GET STOCK Button Position and Size
            ### Call DRAW function

            new qpushbutton(win1) {
                    setgeometry(BoxLeft +160+50, BoxTop -BoxTop, 80, 20)
                    settext("Get Stock")
                    setclickevent("DrawStockButton()")
                    setStyleSheet("background-color: aqua")
            }

            ### GET PREVIOUS Stock
            new qpushbutton(win1) {
                    setgeometry(BoxLeft +00+50, BoxTop -BoxTop, 45, 20)
                    settext("<Prev")
                    setclickevent("PrevSymbol()")
                    setStyleSheet("background-color: aqua")
            }

            ### GET NEXT Stock
            new qpushbutton(win1) {
                    setgeometry(BoxLeft +45+50, BoxTop -BoxTop, 45, 20)
                    settext("Next>")
                    setclickevent("NextSymbol()")
                    setStyleSheet("background-color: aqua")
            }

            ###---------------------------------------------------
            ### Text Field Position and Size. TODAY is End Date

            Today = Date()
            lineedit2 = new qlineedit(win1) {
                    setGeometry(BoxLeft +240+50, BoxTop -BoxTop, 70, 20)
                    lineedit2.settext(Today)
            }

            ###----------------------------------------------------------------
            ### Text Field Position and Size. YESTERDAY is *** 7 YEARS AGO ***

            Yesterday = Date()
                aDateDMY  = Split(Today, "/")
                OldDay    = aDateDMY[2]
                OldMonth  = aDateDMY[1]
                OldYear   = aDateDMY[3] - 7
                Yesterday = OldMonth +"/"+ OldDay +"/"+ OldYear

            ###----------------------------------------------
            ### Text Field Position and Size ==> YESTERDAY

            lineedit2 = new qlineedit(win1) {
                    setGeometry(BoxLeft +310+50, BoxTop -BoxTop, 70, 20)
                    lineedit2.settext(Yesterday)
            }

            ###--------------------------------------------------------
            ### Combo Box for Draw Style - Mountain, Line, Bar, Actual

            comboChartType = new QComboBox(win1) {
                    setGeometry(BoxLeft +380+50, BoxTop -BoxTop, 100, 20)
                    alist = [ "HeikenAshi","Line","Bar","Log","Mountain","Actual" ]
                    for x in aList additem(x,0) next
            }

            ###----------------------------------------------------------
            ### Combo Box for Time Period Type - Weekly, Daily, Monthly

            comboTimePeriod = new QComboBox(win1) {
                    setGeometry(BoxLeft +480+50, BoxTop -BoxTop, 60, 20)
                    alistTime = ["Weekly", "Daily", "Monthly"]
                    for x in aListTime additem(x,0) next
            }

            ###-----------------------------------------------------------
            ### BASKETS - Button -- GetQuotesTickers BASKETS
            ### Show list of different baskers with xxx.tickers available

            comboTickersBasket = new QComboBox(win1) {
                    setGeometry(BoxLeft +540+50, BoxTop -BoxTop, 140, 20)
                    aListBasket = Tickerslist

                    for x in aListBasket
                        additem(x,0)
                    next

                    setactivatedEvent("GetBasket()")      ### ==> Go Handle newly selected Basket of tickers
            }

            ###----------------------------------------------------------
            ### COMPARE Stocks Button
            ### INPUT Stocks Field

            lineedit1Compare = new qlineedit(win1) {
                    setgeometry(BoxLeft +680+50, (BoxTop -BoxTop), 80, 20)
            }


            new qpushbutton(win1) {
                    setGeometry(BoxLeft +760+50, (BoxTop -BoxTop), 80, 20)
                    settext("Compare:")
                    setclickevent("CompareStocks()")
                    setStyleSheet("background-color: aqua")
            }

            ###----------------------------------------------------------
            ### BALANCE Stocks Button


            ###----------------------------
            ### MUSIC Button

            musicButton = new qpushbutton(win1)
            {
                  setGeometry(BoxLeft +920, (BoxTop -BoxTop), 80, 20)
                  settext("PlayVideo")
                  setclickevent("PlayVideo()")  ### ==>> Func PlayVideo --  Movie Button
            }

            // THis DRAWS THE GREEN SQUARE
            //videowidget = new qvideowidget(win1)
            //{
            //    setgeometry(BoxLeft +45, BoxTop, 250, 200)
            //    setstylesheet("background-color: green")
            //}

            player = new QMediaPlayer()
            {
             videowidget = new qvideowidget(win1)  // insert here
                setMedia(new qurl("stock.mp3"))
                setVideoOutput(videowidget)
                play()

            }

            ###--------------------------------------------------
            ###--------------------------------------------------
            ###--------------------------------------------------


            ###---------------------------------------------------
            ### Button -- LEFT BOX --- SELECT STOCK from Tickers List DropDown

            btn1 = new qpushbutton(win1) {

                    setGeometry(LBoxLeft, LBoxTop, LBoxWidth, 20)            ### SELECT STOCK
                    settext("Select Symbol")
                    setclickevent("SelectSymbol()")      ### ==> Go Handle
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


            ###---------------------------------------------------
            ### TICKERS -- LEFT LIST BOX - Stock Select - Button

            list1 = new qlistwidget(win1) {
                    setGeometry(LBoxLeft, LBoxTop +20, LBoxWidth, 140)      ### <<< TICKER LIST



                    #--------------------------------------------------------
                    # alist = ["AMZN","AAPL","GOOGL","FB","NFLX","VTI","BLV"]
                    # for x in alist
                    #    additem(x)
                    # next
                    #---------------------------------------------------------

                    cFile = read(TickersUse)                ### \GetQuotesTickers.tickers")
                    cFile = substr(cFile,windowsnl(),nl)
                    aList = str2list(cFile)

                    TickersNbr = len(aList) -1              ### Use for Prev-Next Symbol limit

                    ###----------------------------
                    ### WORKS. the EOF ignored
                    ###
                    ### TickersUse List 164 _BRKB       BerkshireHathaw Financials_
                    ### TickersUse List 165 _BRKR       BrukerCorp.     Health_
                    ###
                    ###----------------------------

                    for i = 1 to len(aList)
                        if( aList[i] != '')
                                  #See "TickersUse List " +i +" _"+  aList[i] +"_" +nl
                                  componentList = Split(aList[i], " ")

                                  if  substr(componentList[1], "/")
                                    See "LeftListBox Ticker has Slash:   " + aList[i] +nl
                                    MessageBox("LeftListBox Ticker has Slash:   " + aList[i] )
                                  ok

                            additem( aList[i] )
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


            ###------------------------------
            ### Check Box - MOVING AVERAGE

            CheckMAvg = new qcheckbox(win1) {
                    setGeometry(LBoxLeft, LBoxTop +180, LBoxWidth, 20)
                    settext("MAvg-30")
                    # setclickedEvent("CheckBoxMAvg()")
            }

            ###------------------------------
            ### Check Box - MOVING AVERAGE

            CheckMAvg10 = new qcheckbox(win1) {
                    setGeometry(LBoxLeft, LBoxTop +320, LBoxWidth, 20)
                    settext("MAvg-10")
                    # setclickedEvent("CheckBoxMAvg2()")
            }

            ###-------------------------
            ### Check Box - DIVIDEND

            CheckDividend = new qcheckbox(win1) {
                    setGeometry(LBoxLeft, LBoxTop +200, LBoxWidth, 20)
                    settext("Dividend")
                    # setclickedEvent("CheckDividend()")
            }

            ###-------------------------
            ### Check Box - YIELD

            CheckYield = new qcheckbox(win1) {
                    setGeometry(LBoxLeft, LBoxTop +220, LBoxWidth, 20)
                    settext("Yield")
                    # setclickedEvent("CheckYield()")
            }


            ###-------------------------
            ### Check Box - Ratio-Rank

            CheckRatio = new qcheckbox(win1) {
                    setGeometry(LBoxLeft, LBoxTop +240, LBoxWidth, 20)
                    settext("Ratio")
                    # setclickedEvent("CheckRatio()")
            }

            

            ###----------------------------
            ### Check Box - Compare to SPY

            CheckCompareSPY = new qcheckbox(win1) {
                    setGeometry(LBoxLeft, LBoxTop +260, LBoxWidth, 20)
                    settext("CmpSPY")
                    # setclickedEvent("CheckCompareSPY()")
            }
   
            ###-------------------------
            ### Check Box - DataHistory


            
            ###-------------------------
            ### Check Box - MACD

            CheckMACD = new qcheckbox(win1) {
                    setGeometry(LBoxLeft, LBoxTop +300, LBoxWidth, 20)
                    settext("MACD")
                    # setclickedEvent("CheckMACD()")
            }            

         
            ###--------------------------------------------------
            ### END of WIN, BOX, and  Buttons
            ###--------------------------------------------------



        ###--------------------------------------------------------
        ###See "Show-setup " +nl
      
        show()

    }  ### Win-1
   
   
      ###==============================================================


    exec()
}

###-----------------------------------------------
###-----------------------------------------------
###-----------------------------------------------


###=====================================================================================================
###=====================================================================================================
###=====================================================================================================
### FUNCTIONS
###=====================================================================================================


###=============================================================

Func CheckBoxMAvg()
    See "StateChange: Check MAvg " + CheckMAvg.isChecked()  +nl         ### 0 - Uncheked  1 - Checked
return

Func CheckDividend()
    See "StateChange: Check Dividend " + CheckDividend.isChecked()  +nl ### 0 - Uncheked  1 - Checked
return

Func CheckYield()
    See "StateChange: Check Vield " + CheckYield.isChecked()  +nl       ### 0 - Uncheked  1 - Checked
return

Func CheckRatio()
    See "StateChange: Check Ratio " + CheckRatio.isChecked()  +nl       ### 0 - Uncheked  1 - Checked
return

//Func CheckDataHistory()
//    See "StateChange: Check DataHistory " + CheckDataHistory.isChecked()  +nl       ### 0 - Uncheked  1 - Checked
//return

Func CheckCompareSPY() 
     See "StateChange: Check CompareSPY " + CheckCompareSPY.isChecked()  +nl        ### 0 - Uncheked  1 - Checked
return

Func CheckMACD()
    See "StateChange: Check MACD " + CheckMACD.isChecked()  +nl       ### 0 - Uncheked  1 - Checked
return


###---------------------------------------
### Function Window Moved
###---------------------------------------
Func WhereMoved()

    xPos = win1.x()  +8          ### <<< QT FIX because of Win Title
    yPos = win1.y() +30          ### <<< QT FIX because of Win Title

    win1{ setwindowtitle("Window Moved: xPos: " + xPos +" yPos: "+ yPos ) }  
return


###-----------------------------------------
### FUNCTION Where Are We - Window Resized
###----------------------------------------

Func WhereAreWe()
        Rec = win1.framegeometry()

        # WinWidth  = win1.width()          ### 1000 Current Values
        # WinHeight = win1.height()         ### 750

        WinWidth  = Rec.width()             ### 1000 Current Values
        WinHeight = Rec.height()            ### 750

        WinLeft   = Rec.left() +8           ### <<< QT FIX because of Win Title
        WinTop    = Rec.top()  +30          ### <<< QT FIX because of Win Title
        WinRight  = Rec.right()
        WinBottom = Rec.bottom()

        # BoxLeft   = 80                    ###  Start corner   Label1 Box Start Position inside WIN1
        # BoxTop    = 40                    ###  Start corner

        BoxWidth  = WinWidth  -160          ###  End   corner   Label1 Box Size
        BoxHeight = WinHeight -80           ###  End   corner

        WinBaseY  = BoxHeight -50           ### WinBaseY Line Bottom  where Price=0

        win1{ setwindowtitle("Window ReSize: Win " +  WinWidth + "x" + WinHeight + " --- Box " + BoxWidth  + "x" + BoxHeight  +
                              " --- LT " +  WinLeft + "-"   + WinTop  + " --- RB " + WinRight + "-" + WinBottom      ) }


         label1.setgeometry( BoxLeft, BoxTop, BoxWidth, BoxHeight )



return


###--------------------------------------------------------------------
### Function - Mouse Pressed
###    setCompositionMode(26) = to Draw Eleastic Line

Func pPress
return    
    nX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    ny = myfilter.getglobaly()      ### Screen co-ord, NOT Canvas

   #See "Press = Canvas MonaLisa daVinci "+ nX +"-"+ nY + nl
      
   win1.setWindowTitle("Press: Top " + nX +"-" +nY +" Bottom "+ fX +"-" +fY )

      
   oX = nX  ### Save Pressed point as OLD points
    oY = nY

   

   
return

###------------------------------------------------------------------------
### Function Mouse Released
###

Func pRelease
 return
    fX = myfilter.getglobalx()          ### Screen co-ord, NOT Canvas
    fY = myfilter.getglobaly()

   #See "Release Canvas MonaLisa daVinci "+ fX +"-"+ fY + nl
   
    win1.setWindowTitle("Release: Top " + nX +"-" +nY +" Bottom "+ fX +"-" +fY +" Width "+ (fX-nX) + " Height "+ (fY-nY) )

    pDrawMouseLine()

    Canvas.setPixMap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
   

return

###------------------------------------------------------------------------
### Fuction Move Move
###

Func pMove
return
    fX = myfilter.getglobalx()      ### Screen co-ord, NOT Canvas
    fY = myfilter.getglobaly()

   #See "Move Canvas MonaLisa daVinci "+ fX +"-"+ fY +nl
   
    win1.setWindowTitle("Move: Top " + nX +"-" +nY +" Bottom "+ fX +"-" +fY +" Width "+ (fX-nX) + " Height "+ (fY-nY) )

    pDrawMouseLine()

    Canvas.setpixmap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
    
    oX = fX  ### Save OLD points
    oY = fY
    

return

###----------------------------
### Function DrawMouseLine
###

Func pDrawMouseLine()
return

       daVinci.drawLine( nX - xPos, nY - yPos, oX - xPos, oY - yPos )  ### ReDraw OLD Line to Erase
       daVinci.drawLine( nX - xPos, nY - yPos, fX - xPos, fY - yPos )  ### Draw NEW Line
      
      #See "Draw Canvas MonaLisa daVinci "+ nX +"-"+ nY +"   "+ fX +"-"+ fY+nl
           
return

###------------------------------------
### Function DrawMouseLine - CLEAR
###

Func pClear()
return
    daVinci.setCompositionMode(0)   ### Put back to default mode 0
    
    #Canvas.setpixmap(MonaLisa)      ### Need this setpixmap to display imageLabel
    Canvas.show()
return

###---------------------------


###=====================================================================================================
###=====================================================================================================
###=====================================================================================================


###============================================================
### FUNCTION DARW -  After Stock Symbol selected handle it
###
###============================================================


Func DrawStockButton()

        ###-----------------------------
        ### FETCH DATA for this symbol
        ### CLEAR arrayClose
        ###-----------------------------

        $symbol = Upper( lineedit1.text() )          ### Read text field
        lineedit1.setText($Symbol)

        itemList[1] = $symbol               ### Win Title >>> Symbol Name Group


        Draw($symbol)
return

###==============================================================================
###==============================================================================
### Draw:  Fetch each Ticker in List, Draw it Innternally, before calling Paint

Func Draw(theseTickers)

    ###---------------------------------------------
    ### Remove SPLASH image by setting size to Zero

        imageStock.clear()

    ###-----------------------
    ### PAINT the Chart
    ###-----------------------


    MonaLisa   = new qpicture()             ### Create a new PICTURE

    daVinci = new qpainter()                // Close } is many lines down
    {   
        begin(MonaLisa)                     ### Pens and Colors defined at start of program

        if( isString(theseTickers) )        ### Draw SINGLE Ticker -- Draw Stock, or BALANCE ZXY
            $Symbol = theseTickers

            theseTickers = []
            Add(theseTickers, $Symbol)
        ok
      
      if( CheckCompareSPY.isChecked() )
         Add(theseTickers, "SPY")   
         ###Reverse(theseTickers)
      ok
      
      
            oFont = new qFont("Calibri",12,33,0)    ### name, intensity, italic
            setFont( oFont)

      colorNbr = i

    //=================================================
    //=================================================
    //=================================================
    
    
    ###-----------------------------------
    ### MULTIPLE TICKERS
    ###-----------------------------------
    
    $LastSymbol = "SPY"                     // Save, because very last is Blank

    if( isList(theseTickers) )              ### Draw MULTIPLE Tickers -- Compare:
        colorNbr = 1                        ### INCREMENT IT LATER --Draw each stock a new color, Red, Blue, Green etc
        for $Symbol in theseTickers

            See "Draw: " + $Symbol +nl      // Draw: BMO

                    ###-----------------------------------------------------------------
                    ### LIVE Yahoo or HISTORY Data or Balance or ConstantInvesting Data
                    ###-----------------------------------------------------------------

                        ### From Func BALANCE - 2 Stocks Re-Balance results
                        ### Info already extracted and formatted in array

                    if ( substr($symbol,1,3) = "Z1-" )      ### $symbol = "Z1"
                            arrayDate     = Z1arrayDate
                            arrayOpen     = Z1arrayOpen
                            arrayHigh     = Z1arrayHigh
                            arrayLow      = Z1arrayLow
                            arrayClose    = Z1arrayClose
                            arrayVolume   = Z1arrayVolume
                            arrayAdjClose = Z1arrayAdjClose

                    but ( substr($Symbol,1,3) = "Z2-" )     ### $symbol = "Z2"
                            arrayDate     = Z2arrayDate
                            arrayOpen     = Z2arrayOpen
                            arrayHigh     = Z2arrayHigh
                            arrayLow      = Z2arrayLow
                            arrayClose    = Z2arrayClose
                            arrayVolume   = Z2arrayVolume
                            arrayAdjClose = Z2arrayAdjClose

                    but ( substr($Symbol,1,3) = "Z3-"  )    ### $symbol = "Z3"
                            arrayDate     = Z3arrayDate
                            arrayOpen     = Z3arrayOpen
                            arrayHigh     = Z3arrayHigh
                            arrayLow      = Z3arrayLow
                            arrayClose    = Z3arrayClose
                            arrayVolume   = Z3arrayVolume
                            arrayAdjClose = Z3arrayAdjClose

                    but ( substr($Symbol,1,3) = "Z4-"  )    ### $symbol = "Z4"
                            arrayDate     = Z4arrayDate
                            arrayOpen     = Z4arrayOpen
                            arrayHigh     = Z4arrayHigh
                            arrayLow      = Z4arrayLow
                            arrayClose    = Z4arrayClose
                            arrayVolume   = Z4arrayVolume
                            arrayAdjClose = Z4arrayAdjClose

                    ###-----------------------------------------
                    ### Use HISORY DATA
                    ###-----------------------------------------

                    else

                        ###-----------------------------
                        ### Use YAHOO DATA - PRICE
                        ###-----------------------------

                        returnCode = FetchData($Symbol,"Price")         ### <<<=== returnCode = GET YAHOO DATA

                        if returnCode = "BAD"
                            See "Ticker return code: " + returnCode + " :for Symbol: " + $Symbol +nl
                            lineedit1.settext( "BadTkr-" + $Symbol )
                            return
                        ok
 
                    ok

            ###----------------------------------------------------------


            ###------------------------------------------------------------------------
            ### Note AAPL split 7 to 1 -- maxHighPrice 129.88 maxActualHiPrice 705.07
            ###------------------------------------------------------------------------


                ###------------------------------
                ### Normal Single Stock display
                ###------------------------------

                maxHighPrice      = max(arrayAdjClose)
                minLowPrice       = min(arrayAdjClose)

                maxActualHiPrice  = max(arrayClose)         ###  NEW YAHOO mess  --- max(arrayHigh)
                minActualLoPrice  = min(arrayLow)

                ###------------------------------------
                ### Normalize Call from Compare Button
                ###------------------------------------

                if  Normalize = 1                                           ### Normalize ON =1
                    maxHighPrice     = NormalizeHigh
                    maxActualHiPrice = NormalizeActualHigh

                        AmountInit = 100000
                        SharesInit = AmountInit / arrayAdjClose[1]          ### Starting Price

                        for i = 1 to len(arrayAdjClose)
                            ValueInit = arrayAdjClose[i] *  SharesInit

                            arrayOpen[i]     = ValueInit
                            arrayHigh[i]     = ValueInit
                            arrayLow[i]      = ValueInit
                            arrayClose[i]    = ValueInit
                            arrayAdjClose[i] = ValueInit

                        next
                ok

                           
            sizeOfData = len(arrayClose)
            z          = len(arrayClose)   ### <<< SIZE OF DATA


            Scale    = WinBaseY / maxHighPrice          ### Mulpiplier to Scales Prices to Chart
            ScaleHi  = WinBaseY / maxActualHiPrice

            # See "WinBaseY " +WinBaseY +" maxHighPrice " + maxHighPrice +" maxActualHiPrice " + maxActualHiPrice +" Scale " + Scale +" ScaleHi " +ScaleHi +nl
            

            //================================================
            //================================================
            //================================================


            ###----------------------------------------------
            ### ChartType - ComboBox selected for chart type
            ### "Mountain","Line","Hi-Low","Candle","Bars"
            ###----------------------------------------------

            chartType = comboChartType.currentText()

            ###------------------------------------------------------------------------------------
            ### Draw Vertically Spaced Price Lines -- BLUE PEN - Use Base 12
            ###------------------------------------------------------------------------------------

DrawVerticalLine(theseTickers, $Symbol)




            ###--------------------------------------------------------------------------------------
            ### Draw HORIZONTALY Spaced  Date Lines -- BLUE PEN
            ### Find beginning of Year 2016. Draw line.
            ### Horizontal Placing of Vertical Lines every 2 lines  HzSp = 2
            ###--------------------------------------------------------------------------------------

DrawHorizontalLines()



            ###-----------------------------------------------------------------------------
            ### SCALE PRICES. Max Price to fit top of chart -- RED PEN  -- z = sizeOfData
            ###------------------------------------------------------------------------------

            setpen(penRed)

                if( isList(theseTickers) )                          ### Draw Multiple Tickers -- Compare:
                    daVinci.setpen(arrayPenColor[colorNbr % 8 +1] )         ### Change color for easch stock
                    colorNbr++                                      ### Next color
                    daVinci.drawText( 60, ( 20 * colorNbr) , $Symbol )      ### Draw Symbol to match Color

                ok

            ###---------------------
            ### Draw Line Chart
            ###---------------------

if chartType = "Line"
   DrawLineChart()
   
ok


            ###-------------------------------------------------------------------
            ### Draw BAR CHART
            ### Needs High Low Close prices. Splits ratio of AdjClose to Close
            ###-------------------------------------------------------------------


            if chartType = "Bar"
			
			    //daVinci.setPen(penBlue1)
                for x = 1 to z
                    SplitAdjRatio = ( arrayAdjClose[x] / arrayClose[x] )

                     yHi =     arrayHigh[x] * Scale * SplitAdjRatio ### Hi - NOW split  * SplitAdjRatio ### Split Adj
                     yLo =      arrayLow[x] * Scale * SplitAdjRatio ### Lo - NOW split  * SplitAdjRatio
                     yCl =    arrayClose[x] * Scale * SplitAdjRatio ### CL - NOT split  * SplitAdjRatio 2017-06-01 Yahoo mess


                    ###---------------------------------------------
                    ### If Huge Split then High to Low exaggerated
                    ###---------------------------------------------

                    if yHi > yLo * 1.25
                        daVinci.drawline( (x*HzSp), WinBaseY -yLo , (x*HzSp), WinBaseY - yCl )  ### Low - Low

                    else
                        daVinci.drawline( (x*HzSp),    WinBaseY -yHi , (x*HzSp),    WinBaseY - yLo )  ### High - Low
                        daVinci.drawline( (x*HzSp) -1, WinBaseY -yCl , (x*HzSp) +1, WinBaseY - yCl )  ### Close Notch
                    ok

                next
				//daVinci.setPen(penBlue)
            ok




            ###--------------------------
            ### DRAW MOUNTAIN CHART
            ###--------------------------
            
if chartType = "Mountain"   
   DrawMountainChart()
ok 

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
   DrawActualChart()
ok





            ###-------------------------------------
            ### Draw LOG CHART | maxLog, scaleLog
            ### y / BaseNbr is percent of maxHighPrice
            ###-------------------------------------

if chartType = "Log"
   DrawLogChart()
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
   DrawHeikenAshiChart()
ok



            ###------------------------------------------------------------------------------
            ### DRAW MvgAVG-30 CHART - Use Blue Pen
            ### Check MAvg " + CheckMAvg.isChecked()  +nl   ### 0 - Uncheked  1 - Checked
            ###------------------------------------------------------------------------------

if CheckMAvg.isChecked() = 1
   DrawMvgAvg30()
ok


           //===============================================

            ###------------------------------------------------------------------------------
            ### DRAW MvgAVG-10 CHART - Use Blue Pen
            ### Check MAvg " + CheckMAvg.isChecked()  +nl   ### 0 - Uncheked  1 - Checked
            ###------------------------------------------------------------------------------

if CheckMAvg10.isChecked() = 1
   DrawMvgAvg10()
ok


            ###===============================
            ### MACD CALC DRAW for this stock
            ### Used 12, 26 , 12-26 , 12        
            //
            //  MACD - Introduction The acronym MACD stands for Moving Average Convergence Divergence.
            //  MACD is a simple and useful technical analysis indicator first developed by Gerald Appel.
            //  MACD is made of two lines, the MACD Line, and the Trigger Line.
            //  Sometimes, the Trigger Line is called the Signal Line.
            //  To construct the MACD Line using the typical parameters:
            //     Calculate a 12-day EMA (*)
            //     Calculate a 26-day EMA
            //  To create the MACD Line, subtract the 26-day EMA from the 12-day EMA and plot the difference.
            //     MACD Line = 12-day - 26-day
            //  To create the Trigger Line (Signal), plot a 9-day EMA of the MACD line.  (*)
            //     TriggerLine = 9-day EMA of MACD line
            //            

if CheckMACD.isChecked() = 1
   DrawMACDChart()
ok

           
            ###=======================================================

            ###------------------------------------------------------------------------------
            ### DRAW DIVIDEND CHART
            ### Magnify by 5X  -
            ### -- $1 quarter =>  $5  ==> Mentally: Double / 10 => Quarterly estimate
            ### Mountain Style - Use Blue Pen
            ### CheckDividend.isChecked() = 1   ### 0 - UnChecked  1 - Checked
            ###----------------------------------------------------------------------
                        ###
                        ###    1       2
                        ### Date,      Dividends
                        ### 2016-07-12,0.310000
                        ### 2016-06-09,0.339000
                        ### 2016-05-11,0.213000
                        ### 2016-04-08,0.259000     yyyy-mm-dd => Date : dd/mm/yyy
                        ###
                        ###---------------------------

        if Normalize = 0
        
if CheckDividend.isChecked() = 1  ||  CheckYield.isChecked() = 1 
   DrawDividendChart( $Symbol)
ok
        ok
		
        $LastSymbol = $Symbol    // SAVE Needed because very last in List is Blank , ALSO for WinTitle    

     	###-----------------------------------
        ### END of MULTIPLE TICKERS Sectiob
        ###-----------------------------------
      
        next    ### for $Symbol in theseTickers
        
    ok          ### if( isList(theseTickers) )


    ###==============================================================

    Normalize = 0   ### Turn OFF  Compare, Balance, ConstantValue

	###-----------------------------------------
	### END of DRAW TYPES
	###-----------------------------------------

            ###----------------------------
            ### RATIO NBR -- CALC DRAW for this stock
            ### Used for Ranking system
			
if CheckRatio.isChecked() = 1
   DrawRatioChart()
ok   
			
			###-------------------------------------
            ### Draw Line Chart FRAME and WinINFO
			
DrawFrameWinTitleInfo($LastSymbol)

           

        ###-------------------------------------------
        ### Reset COMPARE, BALANCE, CONSTANT VALUE:  maxHighPriceBig = 0
        ###-------------------------------------------
        maxHighPriceBig = 0

        ### See "EndPaint-draw " +nl
        endpaint()
    }                // // END -- DAVINCI = NEW QPAINTER()


    label1 {
            #See "SetPicture-draw " +nl

            setpicture(MonaLisa)
            
            #See "Show-draw " + 
            show()
           }


return

###=====================================================================================
###=====================================================================================
###=====================================================================================


###=====================================================================================
### FUNCTION ROUTINES
###=====================================================================================

###-------------------------------------------------------------------------------
### FUNCTION GetBasket  BUTTON -- Newly selected Baskets of Tickers to use
###------------------------------------------------------------------------------

Func GetBasket()
        TickersFile = comboTickersBasket.currentText()
        TickersUse  = TickersDir +"\"+ TickersFile

        cFile = read(TickersUse)
        cFile = substr(cFile,windowsnl(),nl)
        aList = str2list(cFile)

        ###----------------------------
        ### WORKS. the EOF ignored
        ###----------------------------

        ### REMOVE ITEMS from current tickers list, one at a time

            counter = list1.count()             ### Current list of tickers count
            for i = counter to 0 step -1
                list1.takeItem(i)               ### Remove item

                # See "RemovedList " +i +"__" +nl
            next


        ### ADD ITEMS from new tickers list
        
            for i = 1 to len(aList)
                if( aList[i] != '')
                          #See 'GetBasket NewList ' +i +" __" + aList[i] + '__' +nl
                          componentList = Split(aList[i], " ")

                          if  substr(componentList[1], "/")
                            See "GetBasket: Ticker has Slash:   " + aList[i] +nl
                            MessageBox("GetBasket: Ticker has Slash:   " + aList[i]  )
                          ok

                    list1.additem( aList[i] )
                ok
            next

    return

###---------------------------------
### FUNC SelectSymbol  -- BUTTON
###---------------------------------

Func SelectSymbol

        ###----------------------------------
        ### Use Selected Row
        ### Fill in the Symbol Field
        ### Call DRAW function
        ###
            ### Position = list1.currentrow()
            ### PosData  = list1.item(list1.currentrow()).text()
            ### See " Next Pos " + Position +" PosData " + PosData +nl
            ### list1.setcurrentrow(Position +1, 3)
            ###
                ### NewList 888 __CTT        CatchmarkTimbe   YFinanc __
                ### NewList 889 __CTWS       ConnecticutWat   QUtilit __
                ### NewList 890 __CTXS       CitrixSystemsI   QInform __
                ###----------------------------------------------------------

        Item = list1.item(list1.currentrow()).text()        ### Get from SelectSymbols drop down list

        itemList = Split(Item, char(09) )                   ### Space 32 dec,  Tab 09 dec
        #See "SelectSymbol Item: " +Item +nl
        #See itemList

        if( len(itemList) = 1 )
            Add(itemList, "Name")
            Add(itemList, "Group")
        ok

        lineedit1.settext(itemList[1])                      ### Put in Getstock field for fetching  
        $symbol = Upper( lineedit1.text() )          ### Read text field
        lineedit1.setText($Symbol)

        Draw($symbol)


return

###-------------------------------
### FUNC NextSymbol -- BUTTON
###-------------------------------

Func NextSymbol

        ###----------------------------------
        ### Use Selected Current Row +1

        Position   = list1.currentrow()
        TickersNbr = list1.count()                          ### Size of Row Count

        if Position = TickersNbr -1
            See "NextSymbol Position: " + Position +" TickersNbr " + TickersNbr +nl
            return                                          ### Do NOT go More
        ok
        list1.setcurrentrow(Position +1, 3)

        Item = list1.item(list1.currentrow()).text()

        itemList = Split(Item, char(09) )                   ### Space 32 dec,  Tab 09 dec
        if( len(itemList) = 1 )
            Add(itemList, "Name")
            Add(itemList, "Group")
        ok

        lineedit1.settext(itemList[1])
        $symbol = Upper( lineedit1.text() )          ### Read text field
        lineedit1.setText($Symbol)

        Draw($symbol)

Return

###------------------------------
### FUNC PrevSymbol -- BUTTON
###------------------------------

Func PrevSymbol

        ###----------------------------------
        ### Use Selected Current Row -1

        Position   = list1.currentrow()
        TickersNbr = list1.count()                          ### Size of Row Count

        if Position = 0
            #See "PreSymbol Position: " + Position +" TickersNbr " + TickersNbr +nl
            return                                          ### Do NOT go Less
        ok
        list1.setcurrentrow(Position -1, 3)

        Item = list1.item(list1.currentrow()).text()

        itemList = Split(Item, char(09) )                   ### Space 32 dec,  Tab 09 dec
        if( len(itemList) = 1 )
            Add(itemList, "Name")
            Add(itemList, "Group")
        ok

        lineedit1.settext(itemList[1])
        $symbol = Upper( lineedit1.text() )          ### Read text field
        lineedit1.setText($Symbol)

        Draw($symbol)

return

###------------------------------------------------------------------------------

###----------------
### Func Xmin()
###----------------

Func Xmin (aList)
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

Func Xmax (aList)
  max = aList[1]
  for x in aList
    if x > max
      max = x
    ok
  next
return max

###----------------

###===========================================================================
###===========================================================================
###===========================================================================


Func FetchData($thisSymbol, TypeOfData  )

    TimePeriod = comboTimePeriod.currentText()  ### "w-Weekly", "d-Daily", "m-Monthly, v-dividend"

    Today    = Date()                           ### 14/05/2016  mm/dd/yyyy
    aDateDMY = Split(Today, "/")                ### 14 05 2016

        if TimePeriod = "Weekly"
                #Period = 7                                 ### 7 years of Weekly => 364 periods
                $DayWeekMonth = "1wk"
                StartDate = AddDays(Today, ( -365.25 * 7 ))

        but TimePeriod = "Daily"
                #Period = 2                                 ### 2 years of Daily => 260 -> 520 periods
                $DayWeekMonth = "1d"
                StartDate = AddDays(Today, ( -580 ))        ### 524 days ~ 360 stock periods

        else TimePeriod = "Monthly"
                #Period = 30                                ### 30 years of Monthly => 360 periods
                $DayWeekMonth = "1mo"
                StartDate = AddDays(Today, ( -365.25 * 30 ))
        ok

        ManualDate = lineedit2.text()

      
      if StartDate != ManualDate
         StartDate = ManualDate     ### Manual Start Date in label2
      ok


        ###------------------------
        ### DIVIDEND
        ### NEW YAHOO format  &events=div

        $Events = "history"          ### Default History Data

        if TypeOfData = "Dividend"
              $Events = "div"
        ok


    ###--------------------------------------------------------------------
    ###   HistoryDate MM/DD/YYYY  Month -1.  Ex. 03 => April 2015-04-15
    ###
    ###   URL - Put it together -- $urlbase + $symbol + $urlbaseType
    ###--------------------------------------------------------------------

    arrayStartDate = split(StartDate, "/")                ### How far back to go in time, days, weeks, months


    ###----------------------------------
    ### NEW YAHOO Interface
    ### &events=history  or div
    ###----------------------------------

        $symbol   =  $thisSymbol                         ### "AAPL"


        $Period1 = EpochTime( StartDate, "00:00:00")    ### 7 years ago
        $Period2 = EpochTime( Date(), "18:00:00" )          ### Today 11 PM


    //=====================================================================================
    // Part 1
    // CURL INIT

    curl = curl_easy_init()              // START CURL INIT     
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.54.1" )   // FIX "Too many requests"  
    
    //=====================================================================================
    // Part 2 --- Send URL as Request
    // Build URL from Parts, Set the Range of Time, and Iterval of Frequency
    //
    // "validRanges": [ "1d", "5d", "1mo", "3mo", "6mo",  "1y", "2y",  "5y", "10y", "ytd", "max" ]
                    
    
    $Interval = '1wk'                      // <<< DEFAULT Interval FOR  $url4                            
    $Range    = '10y'                      // <<< Range     $url6 
    
    
                chartPeriod = comboTimePeriod.currentText()                        // "Weekly", "Daily", "Monthly"
            if chartPeriod = "Weekly"  $Range =  '10y'   $Interval = '1wk'    ok    // 360 weeks = 7 years
            if chartPeriod = "Monthly" $Range =  'max'   $Interval = '1m'    ok    // 360 months = 30 Years
            if chartPeriod = "Daily"   $Range =  '2y'    $Interval = '1d'    ok    // 360 days   = 16 monts 72 weeks

    
    $url1 = 'https://query1.finance.yahoo.com/v8/finance/chart/'
    $url2 =  $Symbol                            // <<< Ticker 'RY'
    $url3 = '?metrics=high?&interval='
    $url4 =  $Interval                        // <<< Interval   1wk'                           
    $url5 = '&range='
    $url6 =  $Range     
    
    $url2 = $Symbol                          // <<< Ticker
    $url4 = $Interval                        // <<< Interval                             
    $url6 = $Range                           // <<< Range       


    $url = $url1 + $url2 + $url3 + $url4 + $url5 + $url6            
            
    //----------------------------------------------------
    // BUILT URL COMBO => to GET DATA HISTORY
 
    $url = $url1 + $url2 + $url3 + $url4 + $url5 + $url6    
    
    //========================================================================
    // Part 3
    // CURL GET DATA  $URL ===>>> Site
          
    curl_easy_setopt(curl, CURLOPT_URL, $url);   ### <<<=== SetOpt + URL               
    cStr = curl_easy_perform_silent(curl)        ### <<<=== GET DATA ===>>> cStr
 
            //----------------------------------------       
            // DEBUG        
            //See "===== cStr Data: ===== "+nl+nl
            //See cStr  
    
    //===========================================================================
    // Part 4 Data Returned in JSON format. Convert it to Array aList
    // SAVE the WEBPAGE DATA to cSTR  OR "sample.json" File,  for the READ to work.

    aList = JSON2List( cStr )   // Reads cStr Json format returned
    
    
    if substr( cStr, 'No data found, symbol may be delisted') 
       See aList[:chart][:error][:code]  +" | "+ aList[:chart][:error][:description]  +nl
       return "BAD"
    ok

    
    aOpen      =  aList[:chart][:result][1][:indicators][:quote][1][:open]
    aHigh      =  aList[:chart][:result][1][:indicators][:quote][1][:high]
    aLow       =  aList[:chart][:result][1][:indicators][:quote][1][:low]
    aClose     =  aList[:chart][:result][1][:indicators][:quote][1][:close]
    aVolume    =  aList[:chart][:result][1][:indicators][:quote][1][:volume]
    aAdjClose  =  aList[:chart][:result][1][:indicators][:adjclose][1][:adjclose]
    aTimeStamp =  aList[:chart][:result][1][:timestamp]
    aTimeDate  =  list(len(aTimeStamp))
    aHistory   =  list(len(aTimeStamp))
    
    //--------------------------------------------------
    // Convert EPOCH Seconds to Human Readable Date format
    
    for k = 1 to len(aTimeStamp)
          $EpochStart  = aList[:chart][:result][1][:timestamp][k]
          aTimeDate[k] = EpochToDate($EpochStart) 
    next    
    
    //-----------------------------------------------------
    // SHOW LINES of HISTORY DATA - Oldest to Newest
    // 16/09/2024,86.08,90.07,85.76,89.91,4813300,89.91
    // 23/09/2024,90.07,90.42,89.48,90.10,1105300,90.10
    // 25/09/2024,89.82,90.23,89.92,89.96,12033,89.96   
    // aHistory[len(aTimeStamp)] = 'Date,Open,High,Low,Close,Adj Close,Volume'
    //------------------------------------------------------------------------
    
    for k = 1 to len(aTimeStamp) 
        $NextLine   = aTimeDate[k] +","+ aOpen[k] +","+ aHigh[k] +","+ aLow[k] +","+ aClose[k] +","+  aVolume[k] +","+ aAdjClose[k] 
        aHistory[k] = $NextLine
    next    

    //--------------------------
    
    endData  = len(aTimeStamp)                // BMO 524   SMR 136  lines
    srtData  = endData - 360                  //     164      -224  start point
      
    //--------------------------------
    // DATA < 360 entries for Stock: SMR
    
    if srtData < 0
       fillpt  = -(srtData)  // -224 => 224

        // Fil lwith first valid data
        for r = 1 to fillpt                   // 1-224 Fill In  
            arrayDate[r]       = aTimeDate[1]
            arrayOpen[r]       =     aOpen[1]
            arrayHigh[r]       =     aHigh[1]
            arrayLow [r]       =      aLow[1]
            arrayClose[r]      =    aClose[1]
            arrayVolume        =   aVolume[1]
            arrayAdjClose[r]   = aAdjClose[1]       
        next
            fillpt = r
            s = 1
        for r = fillpt to 360                   // 1-224 Fill In  
            arrayDate[r]       = aTimeDate[s]
            arrayOpen[r]       =     aOpen[s]
            arrayHigh[r]       =     aHigh[s]
            arrayLow [r]       =      aLow[s]
            arrayClose[r]      =    aClose[s]
            arrayVolume        =   aVolume[s]
            arrayAdjClose[r]   = aAdjClose[s]   
            s++         
        next            
            
       
    else    
        //------------------------------------
        // DATA <= 360 entries for Stock: BMO
        
        for r = 1 to 360         // Stocks with 360 data points
            arrayDate[r]       = aTimeDate[r + srtData ]
            arrayOpen[r]       =     aOpen[r + srtData ]
            arrayHigh[r]       =     aHigh[r + srtData ]
            arrayLow [r]       =      aLow[r + srtData ]
            arrayClose[r]      =    aClose[r + srtData ]
            arrayVolume        =   aVolume[r + srtData ]
            arrayAdjClose[r]   = aAdjClose[r + srtData ]
        
        next
    
    ok

    
Return



//============================================================= 
//=============================================================
// FUNCTIONS
// EPOCH TO DATE --Convert Epoch Secs to Human Readable Date

Func EpochToDate(EpochSecs)

   NbrDays   = EpochSecs / 86400                    // 1726776001
   DateHuman = AddDays( "01/01/1970", NbrDays )     // 19/09/2024
   DateHuman = substr( DateHuman,"/", "-" )
   
 return DateHuman                                   // 19/09/2024
 

###-----------------------------------------------------
### FUNC MovingAverage
###-----------------------------------------------------
### MovingAverage
### timePeriod 10 =>  1-10  2-11 3-12 4-13  Diff is 9
### Newest price is Index 1 Oldest price is Index 362
###------------------------------------------------------

Func MovingAverage (arrayPrices, timePeriod)

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


    next


    ###-----------------------------
    ### Second MAvg Sum  11 to 362
    ###-----------------------------

    for i = timePeriod + 1 to z
        sumPrices = sumPrices - arrayPrices[i-timePeriod] + arrayPrices[i]  ### 11-10 = Drop 1, Count 2 to 11
        mvgAvg    = sumPrices / timePeriod                                  ### Divide by 10
        Add (arrayMvgAvg, mvgAvg)

    next


return arrayMvgAvg

###----------------------------------


###-----------------------------------
### FUNC HeikenAshiCalc
###-----------------------------------

Func HeikenAshiCalc()

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

              haOpen[i] =  arrayOpen[i] * ScaleAdjClose     ### * ScaleAdjClose
              haHigh[i] =  arrayHigh[i] * ScaleAdjClose     ### * ScaleAdjClose
               haLow[i] =   arrayLow[i] * ScaleAdjClose     ### * ScaleAdjClose
             haClose[i] = arrayClose[i] * ScaleAdjClose     ### * ScaleAdjClose 2017-06-01 Yahoo mess
            #haClose[i] = arrayAdjClose[i]                  ### NEW YAHOO mess  2017-06-25 Yahoo mess again

         
        next

        ###------------------------------------
        ### Do the rest of the array
        ### Find Max and Min using aList array
        ###-------------------------------------


        for   i = 2 to z

            haClose[i] = ( haOpen[i] + haHigh[i] + haLow[i] + haClose[i] ) / 4      ### AVG of 4 Current

             haOpen[i] = ( haOpen[i-1] + haClose[i-1] ) / 2                         ### AVG of 2 Previous Calc

                 aList = [ haHigh[i], haOpen[i], haClose[i] ]                       ### MAX
             haHigh[i] =   max( aList )

                 aList = [ haLow[i], haOpen[i], haClose[i] ]                        ### MIN
              haLow[i] =   min( aList )


        next

return

###==========================================================
###==========================================================
###
### Function: CompareStocks Button
###             Read line field and covert to list with the ","separator
###             SPY,GOOG
###             $symbol = lineedit1.text()
### maxHighPriceBig

Func CompareStocks()
    cStr = lineedit1Compare.text()                               ### lineedit2.settext(Today)
    
        cStr = Upper( lineedit1Compare.text()  )          ### Read text field
        lineedit1Compare.setText(cStr)

            if cStr = NULL
               return
            ok

    cStr = substr(cStr, "/",",")   ### F.Slash to Comma
    cStr = substr(cStr, ":",",")   ### Colon to Comma
    cStr = substr(cStr,"  "," ")  ### Double space to Single space
    cStr = substr(cStr, " ",",")   ### Space to Comma
    delimiter = ","

    compareStockList = str2list( substr(cStr, delimiter, nl) )   ### Same as Func Split

//    See "CompareStock List" +nl
//    See  compareStockList
//	  See "================="+nl

    ###=======================================
    AmountInit       = 100000
    maxHighPriceList = [1]
    maxPercentChange = [1]

    //   12345678911234567892123456789312345678941234567895123456789612345678971234567898
    //   Sym.    Mult    Adj..   Start   End..   Div$.   Price+  Profit  Div%    Price%
    //   BMO     1.52    59.69   77.56   90.57   0       13.01   13.01   0       16.77  
    

    See "Sym."+tab+"Mult"+tab+"Adj.."+tab+"Start"+tab+"End.."+tab+"Div$."+tab+"Price+"+tab+"Profit"+tab+"Div%"+tab+ "Price% " +nl
    
    divPrf = 0; pricePrf = 0    // initialize
          
    for ticker in compareStockList
        cStr1 = FetchData( ticker, "Price")

        ###----------------------------------
        ### Check if Ticker return code "BAD"

        if cStr1 = "BAD"
            See "Ticker RetCode: "+ ticker +" - "+ cStr1 +nl
            lineedit1.settext( "BadTkr: " + ticker)
            return
        ok
		
		if CheckDividend.isChecked() = 1  ||  CheckYield.isChecked() = 1 
		   FetchDividend( ticker, "dividend"  )
		else
			for i = 1 to 360
				arrayDivDate[i]  =  "1992-03-04"
				arrayDividend[i] =  0.00
			next	   
		ok

        ###-------------------------------------------------
        ### NORMALIZE VTI and BLV
        

       startPriceAct  = arrayClose[1]     // Weekly pick end of the week data Friday
       endPriceAct    = arrayClose[360] 
       
       SharesInit = AmountInit / arrayAdjClose[1]
       
        for i = 1 to len(arrayAdjClose)

            ValueInit = arrayAdjClose[i] *  SharesInit

            arrayOpen[i]     = ValueInit
            arrayHigh[i]     = ValueInit
            arrayLow[i]      = ValueInit
            arrayClose[i]    = ValueInit
            arrayAdjClose[i] = ValueInit

        next 

          startPrice   = arrayAdjClose[1]   / SharesInit   // Adjusted Start Price
          endPrice     = arrayAdjClose[360] / SharesInit
 
   
         //divAmount = 0
//-----------------------------------------------
// Dividend add 360 weeks or 52 weeks or 30Years
    chartPeriod = comboTimePeriod.currentText()                    ### "Weekly", "Daily", "Monthly"
    if chartPeriod = "Weekly"  DaysAgo = 365 * 7    ok
    if chartPeriod = "Monthly" DaysAgo = 365 * 30   ok
    if chartPeriod = "Daily"   DaysAgo = 365 + 5    ok
	
	
    // Today: 29/09/2024  DaysAgo: 2555  Yesterday: 01/10/2017
	 Yester = AddDays( Date(), -DaysAgo)
    aYester = split( Yester, '/')                   // 01/10/2017
    nYester = aYester[3] + aYester[2] + aYester[1]  // 20171001

	divAmount     = 0
	
	$StartDiv = 2
	for i = 2 to len(arrayDividend)                    // -1
	    aToday  = split( arrayDivDate[i], '-')         // 2024-04-24
		nToday  = aToday[1]  + aToday[2] + aToday[3]

	    if nToday >= nYester	
		   $StartDiv = i
		   exit
		ok
	next

	for i = $StartDiv to len(arrayDividend)          //-1    
     		if arrayDivDate[i] != arrayDivDate[i-1]
			   divDate     = arrayDivDate[i]       
			   divAmount  += arrayDividend[i]  
				  //See "DivTicker: "+ ticker +" Date: "+ arrayDivDate[i] +" "+ arrayDividend[i] +nl
			ok
	next  
	
	//TotalDiv for Period |  divAmount  += arrayDividend[i]   // 360
	
//--------------------------------		 
		 

      maxHighPrice  = max(arrayAdjClose)   
      PercentChange = maxHighPrice / startPrice
      
      Add( maxHighPriceList, maxHighPrice)
      Add( maxPercentChange, PercentChange)
      
      multiple = endPrice    / startPrice
      pricePrf = endPriceAct - startPriceAct
      totalPrf = pricePrf    + divAmount
      divPct   = divAmount   / startPriceAct * 100
      pricePct = pricePrf    / startPriceAct * 100
      
      
    
    
      // Tile at start of section
      See ""+      
      ticker         +tab+
      multiple       +tab+  
      startPrice     +tab+ 
      startPriceAct  +tab+  
      endPriceAct    +tab+ 
      divAmount      +tab+ 
      pricePrf       +tab+ 
      totalPrf       +tab+
      divPct         +tab+
      pricePct       +tab+
      nl


    next

    ###=======================================
    ### Use the ticker with the biggest percent increase when drawing multiple stocks
   
    maxHighPriceBiggest     = max(maxHighPriceList)
    See "maxHighPriceBiggest: "+     maxHighPriceBiggest  +nl   // Highest Normalized Price
      
    Normalize            = 1                         ### Turn ON
    NormalizeHigh        = maxHighPriceBiggest
    NormalizeActualHigh  = maxHighPriceBiggest       ### 506799.81 
    NormalizePercentHigh = maxHighPriceBiggest / AmountInit   ### 5.07 

    Draw(compareStockList)      ### ===>> Func Draw

return


###-----------------------------------------------------------------------
### Function RatioCalc
### Compare Last price to each and every Price in last 52 Periods (week)

Func RatioCalc()

    sizeOfData = len(arrayClose)
    z = sizeOfData
    arrayRatio = list(sizeOfData)

    Period     = 52

    for j = 1 to Period
        arrayRatio[j] = 100
    next

    for j = Period +1 to (z)                                          ### Moving Ratio for Period

        Ratio      =  0
        TotalRatio =  0

       #for i = (j - Period +1) to (j-1)                          ### 52..51....2..1
        for i = (j - Period   ) to (j-1)                          ### 52..51....2..1

            #See "J: " +j +" I: "+ i +nl
            if arrayAdjClose[j] > arrayAdjClose[i]
                Ratio = arrayAdjClose[j] - arrayAdjClose[i]       ###  100 /80  = 1.25
            else
                Ratio = - (arrayAdjClose[i] - arrayAdjClose[j])   ###  100 / 125 => -(125/100) = -1.25
            ok

            TotalRatio += Ratio

        next

        TotalRatio = (TotalRatio / arrayClose[z] / Period * 100) + 100
        #See "Ratio: " + j +" -- "+ TotalRatio +nl

        arrayRatio[j] = TotalRatio

    next
        #See arrayRatio

Return TotalRatio

###=================================================
###=================================================
###================================================

###-----------------------------------
### Function PlayVideo Button
###                     setMedia(new qurl("stock.mp3"))

Func PlayVideo()

    listSize = len(musicList)
    song = LastPlayed % (listSize +1)               ### Modulo listSize + 1 to find next song
    if song = 0  song++ ok              ### List 0 BAD, List starts with 1

    See nl + "musicList Song: " + song +" |"
    See musicList[song]
    See "| "

    player.setMedia(new qurl(musicList[song]))

    LastPlayed +=1
    player.play()   ### ==>> Play Movie Button

return

###-----------------------------------
### Fuction TimerMan
func pTime

        ###-----------------
        ### IMAGE


        if imageW > BoxWidth
            TimerMan.stop()          ### GrowBy
            #See "TimerMan STOP" +nl
        ok

        imageW += GrowBy
        imageH  = imageW / AspectRatio

        imageStock.setpixmap(image.scaled(imageW , imageH ,0,0))   ### Size-H, Siz-V, Aspect, Transform

        PosLeft = (WinWidth  - imageW ) / 2
        PosTop  = (WinHeight - imageH ) / 2
        imageStock.setGeometry(PosLeft,PosTop,imageW,imageH)

        ###-----------------------------
        ### PROGRESS BAR and Time

        LabelMan.settext(theTime())     ### ==>> func

        Inc   = ceil( 100 / (BoxHeight / growBy) )
        Ruler = ceil( (imageH / BoxHeight) * 100  )

        if BarMan.value() >= 99        ### ProgressBar start over.
            BarMan.setvalue(0)

            BarMan.hide()
            LabelMan.hide()
        ok

        BarMan{ setvalue(Ruler) }


return

###-----------------------------------
Func theTime()

    return "Time : " + Time()

###-----------------------------------
### Pops every 1 second

Func pTime2()

    LabelMan.settext(theTime())     ### ==>> func
    See "Time: " +Time() +" --- "

    ### PROGRESS BAR - Data History fetch
    Position   = list1.currentrow()
    TickersNbr = list1.count()

    Ruler = ceil( ( Position / TickersNbr ) * 100  )

    BarMan{ setvalue(Ruler) }

return

###-----------------------------------

Func MessageBox( message)
        new qmessagebox(win1) {
                setwindowtitle("MessageBox")
                settext(message )
                setstylesheet("background-color : Yellow")
                show()
        }
return



#############################
#############################
#############################


//================================================================
//================================================================
// DIVIDENDS
// $url1 = 'view-source:https://www.tickertech.net/bnkinvest/cgi/?n=2&ticker='
// $url1 =             'https://www.tickertech.net/bnkinvest/cgi/?n=2&ticker='
// $url2 = 'BMO.CA'
// $url3 = '&js=on&head=1&a=historical&w=dividends2&noform=1&footer=off'
// $url  =  $url1 + $url2 + $url3

Func FetchDividend($Symbol, TypeOfData  )


    //--------------------
    // Pre-Fill with 0.00
    
    count         = 360
    for i = 1 to 360
        arrayDivDate[i]  =  "1992-03-04"
        arrayDividend[i] =  0.00
    next


    //--------------------------
    // Convert Canada .TO symbol to .ca
                   
    if substr( $Symbol, ".TO" )                      // HR-UN.TO 
       //See "Convert: |"+ $Symbol  +"|"                
       $SymbolT = substr( $Symbol,  ".TO", "" )      // Remove .TO  -> HR-UN    
       $SymbolU = substr( $SymbolT, "-UN", ".UN" )   // HR.UN
       $SymbolD = substr( $SymbolU, "-", "." )       // Change Dash to Dot
       $SymbolB = $SymbolD + ".CA"                   // HR.UN.CA   
       $Symbol  = $SymbolB   
       //See " ==> |" + $Symbol +"|" +nl
    ok
    //----------------------------------------------- 
                    
    

    $url1 = 'https://www.tickertech.net/bnkinvest/cgi/?n=2&ticker='
    $url2 = $Symbol
    $url3 = '&js=on&head=1&a=historical&w=dividends2&noform=1&footer=off'
    $url  =  $url1 + $url2 + $url3

    //=====================================================================================
    // CURL INIT

    curl = curl_easy_init()              // START CURL INIT     
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.54.1" )   // FIX "Too many requests"  
    
    //=====================================================================================


    //=========================================================================== 
    // CURL GET ===>>>  

    curl_easy_setopt(curl, CURLOPT_URL, $url);   ### <<<=== SetOpt + URL               
    cStr = curl_easy_perform_silent(curl)        ### <<<=== GET DATA ===>>> cStr
  
    // See "cSTR: DEBUG"+ nl
    // See cStr  // Debug
    
    aLines = str2list(cStr)                     // Array of cStr -> Lines
    
    //===========================================================================

    FlagFoundDate = 0                  // cSTR does it have "DATE"
    kPos = 1                           // Lines Nbr pointer SAVE FOR Next k  
    
    for k = kPos to len(aLines)-4        // Current position in aLines / cStr
        Line = aLines[k]  
        countDiv = 1      // Get 40 dividens
         
        nPos = substr( Line, '222">Date</' )     // FOUND DATE in cSTR  >Date<  the >Div< 
     
        if nPos = 0
            //  Not found in this Line in cStr from DividendChannel
        else
        
        //--------------------------------------------------------------
        // Firt "DATE" position found. Start in Lines +4 for next symbol
        // FOUND DATE in cSTR 
    
        FlagFoundDate = 1                 // cSTR does it have "DATE"
        kPos = k+4   
                      
            for k2 = kPos to len(aLines)-4 Step 4
            
                    //-----------------------
                    // Inspect 4 Lines
                    
                    for p = 0 to 3
                        NextLine = aLines[k2+p]                  // Find data value between >...<
    
                        if substr( NextLine, 'Data may be adjusted for splits' )   // END of DIVIDENDS
                           //See $Symbol + " EndOfDiv: Data may be adjusted for splits" + nl
                           exit 2
                        else
              
                        
                        nPos1 = substr( NextLine, '222">' ) 
                        nPos2 = substr( NextLine, '</font' ) 
                                                
                                //------------------------                  
                                // Get data between >..< positions
                        
                                if nPos1 > 0 
                                    Value = substr(NextLine, nPos1+5, (nPos2 - nPos1 -5) ) 
                            
                                    if p = 0   $Date  = Value     ok      // >07/30/24<
                                    if p = 1   $Div   = Value     ok      // >1.119<        
                                    if p = 2   $tr1   = "abc"     ok      // blank data     
                                    if p = 3   $tr2   = "xyz"     ok      // blank data
        
                                else
                                    // Nada
                                ok                      
                        ok
                        
                    next
                            
                            

                    //-----------------------------------------------------
                    // Modify DIVIDEND To
                    // Draw: BMO
                    // 360 1 07/30/24  1.119  mm/dd/yy
                    // 359 1 04/26/24  1.106
                    // 358 1 01/29/24  1.123
                    //
                    // Date,Dividends
                    // 2022-02-14,1.940000    yyy-mm-dd
                    //------------------------------------------    

                    aDate     = split( $Date, "/")
                    yearDate  = aDate[3]
                    monthDate = aDate[1]
                    dayDate   = aDate[2]
                    
                    if yearDate > 80
                       yearDate = "19" + yearDate
                    else
                       yearDate = "20"+ yearDate
                    ok
                    
                    $Date = yearDate +"-"+ monthDate +"-"+ dayDate    // yyyy-mm-dd
                                
                    arrayDivDate[count]  =  $Date                ### ADD Data to arrayLists
                    arrayDividend[count] =  $Div            
                                
                    count--
                                      
                    //-----------------------------------------------------                 
                                                      
            next 
            
                    //--------------------------
                    // Canada Restore .CA symbol Name to .TO
                    
                    $Ticker = $Symbol
                    if substr( $Ticker, ".CA" )                   // RY.CA -> RT.TO
                       //See "Restore: |"+ $Ticker  +"|"
                       $TickerU = substr( $Ticker, ".CA", "" )
                       $TickerD = substr( $TickerU, ".", "-" )
                       $Ticker  = $TickerD + ".TO"      
                       $Symbol = $Ticker                       
                       //See " ==> |"+ $Symbol  +"|" +nl
                       
                    ok
                    //---------------------------
                    

            //See "Exit to Here --Data may be adjusted for splits-- Dividends Done"+nl +nl              
            //See $Symbol  +tab   +" FetchDiv Done: "  +nl  
            
                                             
        ok                 // if else nPos=0
             
    next                  // forloop  k in Line
    
Return                    // Return GetQuotes

//================================================================
//================================================================

           ###===============================
            ### MACD CALC DRAW for this stock
            ### Used 12, 26 , 12-26 , 12        
            //
            //  MACD - Introduction The acronym MACD stands for Moving Average Convergence Divergence.
            //  MACD is a simple and useful technical analysis indicator first developed by Gerald Appel.
            //  MACD is made of two lines, the MACD Line, and the Trigger Line.
            //  Sometimes, the Trigger Line is called the Signal Line.
            //  To construct the MACD Line using the typical parameters:
            //     Calculate a 12-day EMA (*)
            //     Calculate a 26-day EMA
            //  To create the MACD Line, subtract the 26-day EMA from the 12-day EMA and plot the difference.
            //     MACD Line = 12-day - 26-day
            //  To create the Trigger Line (Signal), plot a 9-day EMA of the MACD line.  (*)
            //     TriggerLine = 9-day EMA of MACD line
            //            

Func DrawMACDChart()

    z  = len(arrayClose)   ### <<< SIZE OF DATA


    aMvgAvg12 = [] 
    aMvgAvg26 = []


    aMvgAvg12     = MovingAverage(arrayClose, 12)                      
    aMvgAvg26     = MovingAverage(arrayClose, 26)
    aMvgAvgDiff   = aMvgAvg12
    aMvgAvgSignal = aMvgAvg26 


    for i = 1 to 360
      Diff = aMvgAvg12[i] - aMvgAvg26[i]
      aMvgAvgDiff[i] = Diff
    next

    aMvgAvgSignal = MovingAverage(aMvgAvgDiff, 9)  

    //==============================================


    MidChart = ( WinBaseY / 2)

    //-------------------
    // MACD-DIFF 12-26 Advance

    daVinci.setpen(penRed) 
    x = 1
    yOld = aMvgAvgDiff[x] * Scale + MidChart
    xOld = 1

    for x = 1 to z
      y = aMvgAvgDiff[x] * Scale  + MidChart
      daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

      yOld = y
      xOld = x
    next
    //-----------------------   

    //-----------------------
    // MACD SIGNAL-9 trailing

    daVinci.setpen(penBlue) 
    x = 1
    yOld = aMvgAvgSignal[x] * Scale + MidChart
    xOld = 1

    for x = 1 to z
      y = aMvgAvgSignal[x] * Scale + MidChart
      daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

      yOld = y
      xOld = x
    next
    //-----------------------                


 Return


//================================================================
//================================================================

            ###------------------------------------------------------------------------------
            ### DRAW MvgAVG-10 CHART - Use Blue Pen
            ### Check MAvg " + CheckMAvg.isChecked()  +nl   ### 0 - Uncheked  1 - Checked
            ###------------------------------------------------------------------------------

Func DrawMvgAvg10()

    z  = len(arrayClose)   ### <<< SIZE OF DATA
    
    daVinci.setpen(penBlack1)

 
    if chartType != "Actual"
       aMvgAvg = []
       aMvgAvg = MovingAverage(arrayAdjClose, 10)
          # See "Returned MAvg " +nl
          # See aMvgAvg +nl

       x = 1
       yOld = aMvgAvg[x] * Scale
       xOld = 1

       for x = 1 to z
          y = aMvgAvg[x] * Scale
          daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

          yOld = y
          xOld = x
       next
    else
    
      ###--------------------------
      ### ActualChart - AdjClose MAvg

       daVinci.setpen(penBlue1)
       aMvgAvg = []
       aMvgAvg = MovingAverage(arrayAdjClose, 10)


       x = 1
       yOld = aMvgAvg[x] * ScaleHi
       xOld = 1

       for x = 1 to z
          y = aMvgAvg[x] * ScaleHi
          daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

          yOld = y
          xOld = x
       next

        ###-------------------------
        ### ActualChart - Close MAvg
        
       setpen(penBlue1) 
       aMvgAvg = []
       aMvgAvg = MovingAverage(arrayClose, 10)


       x = 1
       yOld = aMvgAvg[x] * ScaleHi
       xOld = 1

       for x = 1 to z
          y = aMvgAvg[x] * ScaleHi
          daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

          yOld = y
          xOld = x
       next              
    
    
    ok

Return

//================================================================
//================================================================

Func DrawMvgAvg30()

    z  = len(arrayClose)   ### <<< SIZE OF DATA

    daVinci.setpen(penRed1)

    if chartType != "Actual"
       aMvgAvg = []
       aMvgAvg = MovingAverage(arrayAdjClose, 30)
          # See "Returned MAvg " +nl
          # See aMvgAvg +nl

       x = 1
       yOld = aMvgAvg[x] * Scale
       xOld = 1

       for x = 1 to z
          y = aMvgAvg[x] * Scale
          daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

          yOld = y
          xOld = x
       next
    else
    
      ###--------------------------
      ### ActualChart - AdjClose MAvg
      
       daVinci.setpen(penRed1)
       aMvgAvg = []
       aMvgAvg = MovingAverage(arrayAdjClose, 30)

       x = 1
       yOld = aMvgAvg[x] * ScaleHi
       xOld = 1

       for x = 1 to z
          y = aMvgAvg[x] * ScaleHi
          daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

          yOld = y
          xOld = x
       next

        ###-------------------------
        ### ActualChart - Close MAvg
        
       daVinci.setpen(penBlue1) 
       aMvgAvg = []
       aMvgAvg = MovingAverage(arrayClose, 30)


       x = 1
       yOld = aMvgAvg[x] * ScaleHi
       xOld = 1

       for x = 1 to z
          y = aMvgAvg[x] * ScaleHi
          daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

          yOld = y
          xOld = x
       next              
    
    
    ok

Return


//================================================================
//================================================================

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

Func DrawHeikenAshiChart()


    HeikenAshiCalc()                    ### >>> CALL CALC

    z     = sizeOfData                  ### 1 is Newest  z is Oldest  entry
    SP    = HzSp
    Start = 1    ### 360 * 2/4  = 180

    H = 1                           ### INC draw price horizontal spacing H = H+1
    for x = Start to z              ### 180 to 360


        ###------------------------------------
        ### Color Blue - Line in middle of Bar

        daVinci.setpen(penBlue1)
        yHi = haHigh[x]  * Scale
        yLo = haLow[x]   * Scale
        yOp = haOpen[x]  * Scale
        yCl = haClose[x] * Scale
        
        # See "H: "+haHigh[x] +" L: "+haLow[x] + " O: "+haOpen[x] +" C: "+ haClose[x] +nl

        daVinci.drawline( (H*SP) +1, WinBaseY - yHi , (H*SP) +1, WinBaseY - yLo )

        ###------------------------
        ### Color Green or Red Bar

        daVinci.setpen(penRed1)                                      ###  Red   = SELL
        if( haClose[x] > haOpen[x] ) daVinci.setpen(penGreen1) ok    ###  Green = BUY

       

        daVinci.drawline( (H*SP   ), WinBaseY -yOp , (H*SP   ), WinBaseY - yCl )  ### Thick - SP lines
        daVinci.drawline( (H*SP +1), WinBaseY -yOp , (H*SP +1), WinBaseY - yCl )  ### Thick - 2 lines
        daVinci.drawline( (H*SP +2), WinBaseY -yOp , (H*SP +2), WinBaseY - yCl )  ### Thick - 2 lines

        H = H +1    ### <<<<< INC H+1
    next

    ### Draw last horizontal line to show closing price
    daVinci.drawline( (H*SP ), WinBaseY -yCl , (H*SP +10), WinBaseY - yCl )  ### Thick - 2 lines

 
return

//================================================================
//================================================================

//================================================================
//================================================================

Func DrawLineChart()

    z= len(arrayClose)   ### <<< SIZE OF DATA

    x = 1
    yOld = arrayAdjClose[x] * Scale
    xOld = 1

    for x = 1 to z
        y = arrayAdjClose[x] * Scale
        
        daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)
                        
        yOld = y
        xOld = x
    next

return

//=================================================================
//=================================================================

Func DrawHorizontalLines()

    z   = len(arrayClose)   ### <<< SIZE OF DATA
    
    daVinci.setpen(penBlue1)
 
    # HzSp = 2    ### Horizontal spacing every 2 lines
    HzSp = ( ( BoxWidth - BoxOffsetLine ) / sizeOfData )                         ### Horizon Space self adjusting as per width of Box



    chartPeriod = comboTimePeriod.currentText()                    ### "Weekly", "Daily", "Monthly"
    if chartPeriod = "Weekly"  Interval = ( 7 )             ok
    if chartPeriod = "Monthly" Interval = ( 365.25 /12 )    ok
    if chartPeriod = "Daily"   Interval = ( 7/5 )           ok


    ###--------------------
    ### TODAY's DATE
    ###
    ### Date,Open,High,Low,Close,Volume,Adj Close
    ### 2016-08-22,76.510002,77.010002,75.629997,76.269997,743900,76.269997
    ###--------------------


    cDate1    = date()

    aDateDMY  = Split(cDate1, "/")                              ### TODAY dd/mm/yyyy  16/06/2016
    Year      = number(aDateDMY[3]) +1                          ### Present Year 2016
    cDate2    = "01/01/" + Year                                 ### Next    Year 2017

    DaysAgo   = DiffDays(cDate1, cDate2)

    x         = HzSp * (z - (DaysAgo / Interval) )              ### Future Year >> 2017  interval in days


    ###------------------------------------------
    ### Draw Year VERTICAL for each of 7 Years
    ###------------------------------------------

    for count = 0 to 7

        daVinci.drawline( x, 10, x, WinBaseY)                               ### DRAW LINE
        # See " Count " + count + " Year " + Year + " X " +x + " DaysAgo " + DaysAgo +nl

        ### WEEKLY MONTHY Dates

        if ((chartPeriod = "Weekly") or (chartPeriod = "Monthly"))
            daVinci.drawText( x, WinBaseY +20, (string(Year)) )             ### YEAR DATE
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
                Year    = Year ### - 1          ###  Get Year 2016 instaead of 2017
                if count = 1 exit ok

                Month = number(aDateDMY[2])
                DaysTill30  = (30 - aDateDMY[1]) / Interval

                # See "DayTill30 " + DaysTill30 +nl

                for countM = 1 to 17
                    cDate2 = AddDays( cDate1, (( (-360) / 17 ) * countM ) )
                    DaysAgo = DiffDays(cDate1, cDate2)
                    x       = HzSp * (z - ( DaysAgo / 1 ) + DaysTill30 )


                    MonthName =  arrayMonthName[Month]
                    daVinci.drawline( x, 10, x, WinBaseY)             ### Vertical Line
                    daVinci.drawText( x, WinBaseY +20, MonthName  )   ### MonthName

                    Month = (Month - 1) % 12                  ### Jan replaced by Year
                        if Month = 0
                           Month = 12
                        ok

                        if Month = 1
                            Year = Year -1
                            arrayMonthName[Month] = string(Year)

                            ### See "Daily: " + MonthName +" "+  Month +" "+ Year +nl

                        ok
                next

            ok

    next
Return

//=================================================================
//=================================================================

Func DrawVerticalLine(theseTickers, $Symbol)

    daVinci.setpen(penBlue1)

    BaseNbr  = 12
    vLine    = 0                                                    ### Log Chart bottom line
    Magnify  = BaseNbr                                                   ### MAGNIFY LOG Chart
    maxLog   = log(maxHighPrice  )* log(BaseNbr * Magnify)               ### 728 = 6.8 log
 
    scaleLog = WinBaseY / maxlog                                    ### WinBaseY / 6.8  = 124

    for y = 0 to BaseNbr

        if (chartType = "Log") and (y > 0)                          ### Skip Log 0
            vLine    = WinBaseY / BaseNbr
            pL       = log( (maxHighPrice / BaseNbr) * y ) *  log(y * Magnify)   ### y / BaseNbr is percent of maxHighPrice
            vLine    = scaleLog * pL
            priceInc = string(maxHighPrice / BaseNbr * y)


        but chartType = "Actual"
            priceInc  = string(maxActualHiPrice / BaseNbr * y)

        ### Compare:  more than one entry - max price = 100
        ### Put Percentages on the right side

    
        but ( len(theseTickers) > 1)                                 ### Compare:  more than one entry
            priceInc = string(  NormalizePercentHigh / BaseNbr * y)

        else
            ### Other Charts - Line, Bar, Mountain, Heiken-Ashi
            priceInc  = string(maxHighPrice / BaseNbr * y)

        ok

            if (chartType = "Log")
                daVinci.drawline( 10, WinBaseY - (1 * vLine) , BoxWidth, WinBaseY - (1 * vLine ) )

                daVinci.drawText( 10, WinBaseY - (1 * vLine) +10, priceInc )                            ### Price on Left and Right
                daVinci.drawText( BoxWidth - BoxOffsetPrice, WinBaseY - (1 * vLine) +10, priceInc )                           
                daVinci.drawText( BoxWidth - BoxOffsetPrice, (BoxTop -BoxTop) +20 ,      $Symbol  )

            else
                ### Other Charts - Line, Bar, Mountain, Heiken-Ashi
                vLine    = WinBaseY / BaseNbr
                daVinci.drawline( 10, WinBaseY - (y * vLine)    , BoxWidth, WinBaseY - (y * vLine) )
                
                daVinci.drawText( 10, WinBaseY - (y * vLine) +10, priceInc )                           ### Draw Price Below the Horizontal Price Line
                daVinci.drawText( BoxWidth - BoxOffsetPrice, WinBaseY - (y * vLine) +15, priceInc )
                daVinci.drawText( BoxWidth - BoxOffsetPrice, (BoxTop -BoxTop) +35,       $Symbol  )                  
            ok


    next

Return

//==================================================================
//==================================================================

            ### DRAW ACTUAL CHART
            ### drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)
            ###--------------------------

Func DrawActualChart()

    z  = len(arrayClose)   ### <<< SIZE OF DATA

    ###---------------------------------------
    ### Adjusted Close --- MORL big dividends

    daVinci.setpen(penRed)
    x = 1
    yOld = arrayAdjClose[x] * ScaleHi
    xOld = 1

    for x = 1 to z
        y = arrayAdjClose[x] * ScaleHi
        daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

        yOld = y
        xOld = x
    next

    ###-----------------------------------------
    ### Actual Close  ... PreSplits --- AAPL

    daVinci.setpen(penBlue)
    x = 1
    yOld = arrayAdjClose[x] * ScaleHi
    xOld = 1

    for x = 1 to z
        y = arrayClose[x] * ScaleHi
        daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

        yOld = y
        xOld = x
    next          
            

Return

//==================================================================
//==================================================================

            ###--------------------------
            ### DRAW MOUNTAIN CHART
            ###--------------------------
            
    
Func  DrawMountainChart()

    z  = len(arrayClose)   ### <<< SIZE OF DATA
            
    for x = 1 to z
        y = arrayAdjClose[x] * Scale
        daVinci.drawline( (x*HzSp), WinBaseY , (x*HzSp), WinBaseY - y)
    next

 
 Return

//==================================================================
//==================================================================

            ###------------------------------------------------------------------------------
            ### DRAW DIVIDEND CHART
            ### Magnify by 5X  -
            ### -- $1 quarter =>  $5  ==> Mentally: Double / 10 => Quarterly estimate
            ### Mountain Style - Use Blue Pen
            ### CheckDividend.isChecked() = 1   ### 0 - UnChecked  1 - Checked
            ###----------------------------------------------------------------------
                        ###
                        ###    1       2
                        ### Date,      Dividends
                        ### 2016-07-12,0.310000
                        ### 2016-06-09,0.339000
                        ### 2016-05-11,0.213000
                        ### 2016-04-08,0.259000     yyyy-mm-dd => Date : dd/mm/yyy
                        ###
                        ###---------------------------

if CheckDividend.isChecked() = 1  ||  CheckYield.isChecked() = 1 
   DrawDividendChart()
ok

Func DrawDividendChart($Symbol)

    daVinci.setpen(penGreen3)

    FetchDividend($Symbol, "Dividend"  )   // <<<===

    cDate1    = date()                     // Todays Date
    
    chartPeriod = comboTimePeriod.currentText()                    ### "Weekly", "Daily", "Monthly"
    if chartPeriod = "Weekly"  Interval = ( 7 )             ok
    if chartPeriod = "Monthly" Interval = ( 365.25 /12 )    ok
    if chartPeriod = "Daily"   Interval = ( 7/5 )           ok
    

    MagnifyDiv = 10                // BaseNbr
    z = len(arrayDivDate)          // 360

    for x = 2 to z                 // 2 to z

        if( arrayDivDate[x] != arrayDivDate[x-1] )                  // NOT BackFilled

            DivDate   = substr(arrayDivDate[x], "-" , "")             ### To be able to compare with = sign
            PriceDate = substr(arrayDate[1],    "-" , "")
            
            for i = z to 2 step -1
               PriceDate = substr(arrayDate[i],    "-" , "")
               if PriceDate < DivDate
                  PriceX = arrayAdjClose[i]
                  exit
               ok             
            next


            if ( DivDate > PriceDate   )

                aDivDate = Split(arrayDivDate[x], "-")
                cDate2   = aDivDate[3] +"/"+ aDivDate[2] +"/"+ aDivDate[1]
                DaysAgo  = DiffDays(cDate1, cDate2)

                hPos     = HzSp * (z - (DaysAgo / Interval) )

                y = arrayDividend[x] * Scale * MagnifyDiv   ###<<<=== Height of Div to Display
              
                //---------------------------------                                  
        
                Divx   =  arrayDividend[x]          // PriceX =  arrayAdjClose[i]
                yield  =  Divx / PriceX * 100 * 1   // Scale Yield 2 4
                
                yieldScale = yield * Scale * MagnifyDiv   ###<<<=== Height of Div to Display
                
                
                //-------------------------------------                            
                // See "Div: "+x +" "+ arrayDivDate[x] +" "+ arrayDividend[x]  +" "+ hPos  +nl
                
                if hPos > 2                               // Fix for Daily display
                     if CheckDividend.isChecked() = 1 
                         daVinci.setpen(penGreen3)
                         daVinci.drawline( (hPos), WinBaseY , (hPos), WinBaseY - y)
                     ok
                     
                     if CheckYield.isChecked() = 1
                         daVinci.setpen(penOrange)
                         daVinci.drawline( (hPos+2), WinBaseY , (hPos+2), WinBaseY - yieldScale)
                     ok
                ok
                
            ok
        ok

    next
                                
 Return
 
       
//==================================================================
//==================================================================

            ###----------------------------
            ### RATIO NBR -- CALC DRAW for this stock
            ### Used for Ranking system
			
		
Func DrawRatioChart()		

    z  = len(arrayClose)   ### <<< SIZE OF DATA
	
	TotalRatio     = RatioCalc()
	#maxHighPrice  = max(arrayAdjClose)
	ScaleRatio     = WinBaseY / 200          ### Max RatioCalc - set at 200

	daVinci.setpen(penOrange)
	x    = 1
	yOld = arrayRatio[x] * ScaleRatio
	xOld = 1

	for x = 1 to z
		y = arrayRatio[x] * ScaleRatio
		daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

		yOld = y
		xOld = x
	next

	### Draw stright line reference 100
    daVinci.setpen(penRed)
	y = 100 * ScaleRatio
	daVinci.drawline( 1 * HzSp , WinBaseY - y, (z*HzSp), WinBaseY - y)

Return


//==================================================================
//==================================================================

            ###------------------------
            ### Draw Line Chart FRAME

Func DrawFrameWinTitleInfo($LastSymbol)

	daVinci.setpen(penGreen)

			
	daVinci.drawline(        1,            1,        1, BoxHeight    )             ### WinLeft Line vetical
	daVinci.drawline(        1, BoxHeight -1, BoxWidth, BoxHeight -1 )             ### Bottom Line horizontal

            
            ###--------------------------------------------------
            ### Win Title Info: PRICE  HIGH LOW DIVIDENDS
            
	Yield    = 0
	TotalDiv = 0 
	Dividend = 0
	DividendDate = date()

         
	if CheckDividend.isChecked() = 1
	


		//-----------------------------------------------
		// Dividend add 360 weeks or 52 weeks or 30Years
		
		chartPeriod = comboTimePeriod.currentText()                    ### "Weekly", "Daily", "Monthly"
		if chartPeriod = "Weekly"  DaysAgo = 365 * 7    ok
		if chartPeriod = "Monthly" DaysAgo = 365 * 30   ok
		if chartPeriod = "Daily"   DaysAgo = 365 + 5    ok
		
		
		// Today: 29/09/2024  DaysAgo: 2555  Yesterday: 01/10/2017
		 Yester = AddDays( Date(), -DaysAgo)
		aYester = split( Yester, '/')                   // 01/10/2017
		nYester = aYester[3] + aYester[2] + aYester[1]  // 20171001

		divAmount     = 0
		
		$StartDiv = 2
		for i = 2 to len(arrayDividend)                    // -1
			aToday  = split( arrayDivDate[i], '-')         // 2024-04-24
			nToday  = aToday[1]  + aToday[2] + aToday[3]

			if nToday >= nYester	
			   $StartDiv = i
			   exit
			ok
		next

		for i = $StartDiv to len(arrayDividend)          //-1    
				if arrayDivDate[i] != arrayDivDate[i-1]
				   divDate     = arrayDivDate[i]       
				   divAmount  += arrayDividend[i]  
					  //See "DivTicker: "+ ticker +" Date: "+ arrayDivDate[i] +" "+ arrayDividend[i] +nl
				ok
		next  
		
		//TotalDiv for Period |  divAmount  += arrayDividend[i]   // 360

		TotalDiv = divAmount



		Yield = TotalDiv / arrayClose[360] *100
		See "|"+ $LastSymbol +"| Last 360 days: TotalDiv: "+ TotalDiv  +" Yield: "+Yield +" Price360: "+ arrayClose[360] +nl

	ok
	

	//---------------------------------------------------

	PriceChange = arrayClose[360] - arrayClose[359]
	$symbol     = lineedit1.text() 
	$maxHigh    = max(arrayHigh)
 
	win1{ setwindowtitle("Symbol:  " + $symbol +"  -- Low: "+ minLowPrice +" High: "+ $maxHigh +" Cur: "+
	      arrayClose[360] +" Chg: "+ PriceChange +" --- "+ itemList[1] +" "+  itemList[2] +" "+ 
		  itemList[3]  +" --- CurDIV: "+ Dividend +" TotDIV: "+ TotalDiv +" YIELD: "+ Yield +"%" +
		  " Date: "+ DividendDate +" --- Ratio: "+ TotalRatio ) 
		}

    ###-------------------------------------------
	
return
//==================================================================
//==================================================================


Func DrawLogChart()

    z  = len(arrayClose)   ### <<< SIZE OF DATA

	
	// FROM VerticalLines               
	BaseNbr  = 12
	vLine    = 0                                               ### Log Chart bottom line
	Magnify  = BaseNbr                                         ### MAGNIFY LOG Chart
	maxLog   = log(maxHighPrice  )* log(BaseNbr * Magnify)     ### 728 = 6.8 log     
	scaleLog = WinBaseY / maxlog                               ### WinBaseY / 6.8  = 124

	x = 1
	yOld =  log( arrayAdjClose[x] ) * scaleLog * log((arrayAdjClose[x]  / maxHighPrice ) *   BaseNbr * Magnify)          ### Last Price
	xOld = 1

	for x = 1 to z
		pL = log( arrayAdjClose[x] ) * log( (arrayAdjClose[x]  / maxHighPrice ) * BaseNbr * Magnify)
		yL = scaleLog * pL
		y  = yL
		daVinci.drawline( xOld * HzSp , WinBaseY - yOld , (x*HzSp), WinBaseY - y)

		yOld = y
		xOld = x

	next


Return

//===================================================================
//===================================================================

###------------------------------------
      
######################################
######################################
######################################

Class Company 
   namez 
   valuez

   
###=======================================



























