# Project : CalmoSoft Simple Go Game
# Date    : 28/10/2019-12:00:00
# Update  : 15/11/2019-05:05:59
# Author  : Gal Zsolt (~ CalmoSoft ~), Bert Mariani
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"

Size    = 19      ### Played on 19, 13, or 11 interectins

PlayerB = 1       ### Whose Turn
PlayerW = 0

start   = 0

rowOld  = 0       ### Set after first move
colOld  = 0       ### Set after first move

oldRowMove = 99   ### Flag set on MouseRelease
oldColMove = 99   ### Flag set on MouseRelease

aSquare  = list(Size * Size)    ### "." Dot=Empty B=Black W=White  K=BlackCapture  H=WhiteCapture
aLiberty = list(Size * Size)    ### 0,1,2,3,4,5

aCheckNeighbour = [][]          ### 2D
gEscape = 0                     ### gEscape Route = 1 True --- NOT Blocked
gDelay  = 0.2                   ### Sleep Delay

gBlackStones    =  Ceil(Size * Size / 2) ### 41  Start with 1/2 of Intersections
gWhiteStones    = Floor(Size * Size / 2) ### 40
gBlackCaptures  = 0
gWhiteCaptures  = 0
gBlackTerritory = 0
gWhiteTerritory = 0


//------------------------------------
// rgb(220,177,107,255) }               // From Empty-T.png image

oPicBlackT = new QPixmap("Black-T.png")  // Transparent image made with Paint-3D
oPicBlackL = new QPixmap("Black-L.png")  // Black Last Play
oPicBlackM = new QPixmap("Black-M.png")  // Black Opaque
0PicBlackC = new QPixmap("Black-C.png")  // Black Capture Territory

oPicWhiteT = new QPixmap("White-T.png")  // White Transparent
oPicWhiteL = new QPixmap("White-L.png")  // White Last Play
oPicWhiteM = new QPixmap("White-M.png")  // White Opaque
oPicWhiteC = new QPixmap("White-C.png")  // White Capture Territory

oPicEmptyT  = new QPixmap("Empty-T.png")  // Empty-T is for Board Squares


bWidth    =  oPicBlackT.width()       ### 80, 60, 50
bHeight   =  oPicBlackT.height()      ### 80
eWidth    =  oPicEmptyT.width()
eHeight   =  oPicEmptyT.height()
SqHeight  =  80


C_Spacing = 0 ### was 5
C_ButtonEmptyStyle  = 'background-color: rgb(220,177,107,255); border-radius: 0px; '
C_ButtonBorderStyle = 'background-color: rgb(220,177,107,255); border-radius: 0px; '

C_ButtonBlueStyle   = 'border-radius:6px;color:black; background-color: Cyan'
C_ButtonYellowStyle = 'border-radius:6px;color:black; background-color: Yellow'
C_ButtonOrangeStyle = 'border-radius:6px;color:black; background-color: Orange'
C_ButtonVioletStyle = 'border-radius:6px;color:black; background-color: Violet'

Button          = newlist(Size+1,Size)
LayoutButtonRow =    list(Size+4)

radioButton1 = new QRadioButton(null)  ###  9 Squares Size
radioButton2 = new QRadioButton(null)  ### 11
radioButton3 = new QRadioButton(null)  ### 13
radioButton4 = new QRadioButton(null)  ### 19

radioButton5 = new QRadioButton(null)  ### Territory Count

###--------------------------------------------
### Needed because of Short APP and DrawWidget

TitleStoneMoves = null
TitleCaptured   = null
TitleTerritory  = null
NewGame         = null
Radio1          = null
Radio2          = null
Radio3          = null
Radio4          = null
myfilter        = null
win             = null

Radio5          = null

###=====================================================
###=====================================================
###=====================================================

###================================================================
### The Shortest APP Function you ever seen !
### The DrawWidget function does what is normally in this section

app = new qApp
{

   DrawWidget()   ### Draw the Layout
   pStart()       ### Start the Game
   exec()         ### APP Loop
}

###---------------------


###=================================================

###----------------------------------------------------------
### This is Normally part of APP
### But need to be able to Re-Start on different Size Boards

Func DrawWidget()


     oDesktop     = new qDesktopWidget()
     oRect        = oDesktop.screenGeometry( oDesktop.primaryScreen() )
     ScreenWidth  = oRect.width()
     ScreenHeight = oRect.Height()

     SqHeight = Floor( (ScreenHeight -40) / (Size +2) )
     See "Screen: "+ ScreenWidth +"-"+ScreenHeight +" SqHeight "+ SqHeight +" Size "+ Size +nl

    win = new qWidget()
    {
        setWindowTitle(" GO-Game ")
        setStyleSheet('background-color: rgb(220,177,107,255)')
        move(400,1)

        ###--------------------------------------------------------------------
        ### Adapt to Screen Size - bottom icons and Number of Square 11,13,19

        SqHeight     = Floor( (ScreenHeight -40) / (Size +2) )
        if SqHeight  > bHeight
            SqHeight = 80        ### Max size of Square <= Stone Icon
        ok


        newSize = SqHeight * (Size )                 // Number of Intersection + border numbers
        reSize( newSize, newSize)                    // Based on image size

        See "SqHeight: "+ SqHeight +" Size: "+ Size +nl

        winheight = win.height()
        fontSize  = 8 + (winheight / 250)

            ###------------------------------------------
            ### Mouse Events

            myfilter = new qallevents(win)

            myfilter.setMouseButtonReleaseEvent("pRelease()")
            myfilter.setMouseMoveEvent("pMove()")

            installeventfilter(myfilter)


      ###=========

         ###----------------------------------------------
         ### Title Top Row - Moves Count


         TitleStoneMoves = new qLineEdit(win)
         {
            setStyleSheet("background-color:rgb(220,177,107,255)")
            setFont(new qFont("Calibri",fontsize,100,50))
            setAlignment( Qt_AlignVCenter)
            setAlignment( Qt_AlignVCenter)
            setText(" Stones: BLK "+ gBlackStones +" : "+ gWhiteStones +" WHT ")
         }

         TitleCaptured = new qLineEdit(win)
         {
            setStyleSheet("background-color:rgb(220,177,107,255)")
            setFont(new qFont("Calibri",fontsize,100,60))
            setAlignment( Qt_AlignVCenter)
            setAlignment( Qt_AlignVCenter)
            setText(" Captures: BLK "+ gWhiteCaptures +" : "+ gBlackCaptures +" WHT " )
         }

         TitleTerritory = new qLineEdit(win)
         {
            setStyleSheet("background-color:rgb(220,177,107,255)")
            setFont(new qFont("Calibri",fontsize,100,70))
            setAlignment( Qt_AlignVCenter)
            setAlignment( Qt_AlignVCenter)
            setText(" Territory: BLK "+ gBlackTerritory +" : "+ gWhiteTerritory +" WHT " )
         }

         ###----------------------
         ## RadioButton

         Radio1 = new qRadioButton(win) { setText("9")   setToggledEvent("RadioBtnToggled()") }
         Radio2 = new qRadioButton(win) { setText("11")  setToggledEvent("RadioBtnToggled()") }
         Radio3 = new qRadioButton(win) { setText("13")  setToggledEvent("RadioBtnToggled()") }
         Radio4 = new qRadioButton(win) { setText("19")  setToggledEvent("RadioBtnToggled()") }

			Radio5 = new qRadioButton(win) { setText("Ter")  setClickedEvent("RadioBtnClicked()") }  ### ===>>> Territoty

         NewGame   = new QPushButton(win)
         {
            setStyleSheet("background-color:rgb(220,177,107,255)")
            setFont(new qFont("Calibri",fontsize,100,80))
            setText(" New Game ")
            setClickEvent("NewGame()")
         }

         ###------------------------------------------------

      ###=========

        ##------------------------------------------------------------------------------
        ### QVBoxLayout lays out Button Widgets in a vertical column, from top to bottom.
        ### VERTICAL

        LayoutButtonMain = new QVBoxLayout() { setSpacing(C_Spacing) setContentsmargins(0,0,0,0) }

      ###=========

         ### Horizontal - TOP ROW
         LayoutTitleRow = new QHBoxLayout()
         {
            setSpacing(C_Spacing)
            setContentsMargins(0,0,0,0)
         }

         LayoutTitleRow.AddWidget(TitleStoneMoves)
         LayoutTitleRow.AddWidget(TitleCaptured)
         LayoutTitleRow.AddWidget(TitleTerritory)
         LayoutTitleRow.AddWidget(Radio1)
         LayoutTitleRow.AddWidget(Radio2)
         LayoutTitleRow.AddWidget(Radio3)
         LayoutTitleRow.AddWidget(Radio4)

			LayoutTitleRow.AddWidget(Radio5)

         LayoutTitleRow.AddWidget(NewGame)

         ### Layout - Add  TITLE-ROW on TOP

         LayoutButtonMain.AddLayout(LayoutTitleRow)

      ###=========

        ###----------------------------------------------------
        ### Title Top Row , Col = LETTERS    @ A B C D E F G H I

        TitleLet = list(Size +1)        ### Array of qLabel Object
        Number = 64                     ### 64 = @ A B .. H I

        for Col = 1 to Size +1
            Letter = hex2str( hex(Number))
            TitleLet[Col] = new qLabel(win)
                            { setFont(new qFont("Calibri",fontSize,100,0))
                              setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                              setStyleSheet(C_ButtonBorderStyle)
                              setText(Letter)
                            }
            Number++
        next

        ###------------------------------------------
        ### Top Row,  Col = Letters A B..H I

        LayoutTitleRow = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }
            TitleLet[1].setText(" ")                    ### Blank out the @
            for Col = 1 to Size +1                      ### Add +1 because of LeftMost Labels @
                LayoutTitleRow.AddWidget(TitleLet[Col])
            next

        LayoutButtonMain.AddLayout(LayoutTitleRow)      ### Layout - Add  TITLE-ROW on TOP

        ###----------------------------------------------
        ###----------------------------------------------
        ### Vertical Rows Button = Numbers 1..9

        TitleNum = list(Size +1)    ### Array of qLabel Object

        for Row = 1 to Size
            Number = ""+ Row
            TitleNum[Row] = new qLabel(win)
                            { setFont(new qFont("Calibri",fontSize,100,0))
                              setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                              setStyleSheet(C_ButtonBorderStyle)
                              setText(Number)
                            }
        next

        ###-----------------------------------------------------------------------
        ###-----------------------------------------------------------------------
        ### QHBoxLayout lays out widgets in a horizontal row, from left to right
        ### Horizontal

        for Row = 1 to Size                            ### NOT Size+1
            LayoutButtonRow[Row] = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }

            LayoutButtonRow[Row].AddWidget(TitleNum[Row])

            ### CLICK PLAY MOVE >>pPlay()
            for Col = 1 to Size
                Button[Row][Col] = new QPushButton(win) ### Create PUSH BUTTONS
                                   { setClickEvent("pPlay(" + string(Row) + "," + string(Col) + ")")   ### CLICK PLAY MOVE >>> pPlay
                                     setSizePolicy(1,1)
                                   }

                LayoutButtonRow[Row].AddWidget(Button[Row][Col])    ### Widget - Add HORZ BOTTON
            next

            LayoutButtonMain.AddLayout(LayoutButtonRow[Row])         ### Layout - Add ROW of ButtonS
        next


        ###---------------------------------------------
        ###---------------------------------------------

        setLayout(LayoutButtonMain)

        ###---------------------------------------------
        ###---------------------------------------------

        pStart()    ### Draw the Board
        show()

    }   ### End of Win




###====================================================
###====================================================
###====================================================

Func NewGame()

   See nl+"******** NewGame *********"+nl+nl

   win.Close()                         ### Close the current Layout

   RadioBtnToggled()                   ### Set the Size to play
   Button = newlist(Size+1,Size)       ### Set Button List two New Size

   gBlackStones    =  Ceil(Size * Size / 2) ### 41  Start with 1/2 of Intersections
   gWhiteStones    = Floor(Size * Size / 2) ### 40
   gBlackCaptures  = 0
   gWhiteCaptures  = 0
   gBlackTerritory = 0
   gWhiteTerritory = 0

   DrawWidget()                        ### Draw the New Layout

   pStart()

return

###====================================================

Func RadioBtnToggled()

   see("Radio Toggled: " + Radio1.isChecked() + Radio2.isChecked() + Radio3.isChecked() + nl)

   if Radio1.isChecked() Size =  9  ok
   if Radio2.isChecked() Size = 11  ok
   if Radio3.isChecked() Size = 13  ok
   if Radio4.isChecked() Size = 19  ok
return

###====================================================

Func RadioBtnClicked()

   See nl+ "Radio Clicked: " + Radio5.isChecked()  + " >>>>>>>>>>>>>>>>>>>> " nl+nl

   if Radio5.isChecked()
		for Dot = 1 to 3
			CalcTerritory(Dot)
		next
	ok

return


###====================================================
### START - Set all the Square to Empty Icon


Func pStart()

See "pStart Size: "+ Size +nl

   PlayerB  = 1
   PlayerW  = 0
   start    = 0

   aSquare  = []
   aLiberty = []

   aSquare  = list(Size * Size)    ### "." Dot=Empty B=Black W=White  K=BlackCapture  H=WhiteCapture
   aLiberty = list(Size * Size)    ### 0,1,2,3,4,5

   for i = 1 to (Size * Size)
      aSquare[i] = "."  ### Mark Row*Col = "Empty" with "."
   next


   for Row = 1 to Size
      for Col = 1 to Size
         button[Row][Col] { setIcon(new qIcon(new qPixMap("Empty-T.png")))
                            setIconSize(new qSize(SqHeight,SqHeight))
                            setStyleSheet(C_ButtonEmptyStyle)        ### Needed to fill Square, image too small

                            setEnabled(true)
                            blockSignals(false)                      ### ??? Goes back to Complement Color ??
                          }
      next
   next

return

###=========================================================
### MOUSE - Press, Release, Move  Event Handlers


Func pRelease

    relX = myfilter.getx()                  ### Canvas
    relY = myfilter.gety()

    Row = floor( relY / SqHeight ) //-1      ### Mouse Position to Square
    Col = floor( relX / SqHeight  ) //-1

         if Row < 1  Row = 1 ok             ### Stay within boundary size
         if Col < 1  Col = 1 ok
         if Row > Size  Row = Size ok
         if Col > Size  Col = Size ok

    oldRowMove = 99  ### Flag set on Mouse Move Release. Prevent Illigal Move on Occupied Square
    oldColMove = 99  ### Flag set on Mouse Move Release

    pPlay(Row,Col)                          ### Out New Stone (circle) in Square

return

###===========================================================
### MOUSE MOVES
### Co-Ord -- CANVAS = getx , SCREEN =  myfilter.getglobalx()

Func pMove

    curX = myfilter.getx()
    curY = myfilter.gety()

    //----------------------------------
    // NEW Mouse Position

    Row = floor( curY / SqHeight ) //-1        ### Mouse Position to Square
    Col = floor( curX / SqHeight  ) //-1

         if Row < 1  Row = 1 ok               ### Stay within boundary size
         if Col < 1  Col = 1 ok
         if Row > Size  Row = Size ok
         if Col > Size  Col = Size ok

    ###--------------------------------
    ### Square OCCUPIED - illegal move

    if aSquare[ ((Row-1) * Size) + Col]  != "."
      return
    ok

    //-----------------------------------------------------------------
    // EMPTY OLD SQUARE - Previous Mouse Position if different Row-Col
    //                    Flag=99 set by Mouse Release

    if (oldRowMove != Row OR oldColMove != Col) AND oldRowMove != 99

        Button[oldRowMove][oldColMove] { setIcon(new qIcon(new qPixMap("Empty-T.png")))
                                         setIconSize(new qSize(SqHeight,SqHeight))
                                         setStyleSheet(C_ButtonEmptyStyle)

                                         setEnabled(true)
                                         blockSignals(false)
                                       }
    ok

    //-----------------------------------------
    // CURRENT MOUSE MOVE - Row-Col

    if PlayerB = 1
        Button[Row][Col] { setIcon(new qIcon(new qPixMap("Black-M.png")))   ### Black Last Play (with white circle)
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(false)
                         }

    else
        Button[Row][Col] { setIcon(new qIcon(new qPixMap("White-M.png")))   ### White Last Play (with white circle)
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(false)
                         }
    ok


    oldRowMove = Row
    oldColMove = Col

return



###=========================================================
###=========================================================
###=========================================================

##---------------------
### Display "Square"  with B W     Dot
### Display "Liberty" with 1 2 3 4 .
### Call Display(Square)  or Display(Liberty)

Func Display(Type)

    See nl + "....... 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9" +nl
    for Row = 1 to Size

        RowStart = ((Row-1)*Size) +1            ### Allow up to 19*19 = 361

        if    RowStart <  10     RowStart = "00"+ RowStart
        elseif RowStart < 100    RowStart =  "0"+ RowStart
        ok

        if Row < 10   Row = "0"+ Row  ok        ### Add leading 0
        See " "+ RowStart +" "+ Row

        ### Print Dots
        RowIndex = (Row-1) * Size               ### Start of Row
        for Col = 1 to Size

            Offset =  RowIndex + Col            ### Offset into aLiberty (0*9+4) = 4 , (1*9+4) = 13

            if Type = "Square"
               See " "+ aSquare[ Offset ]          ### Dot "."   OffSet ?! sometimes Error on 19
            elseif Type = "Liberty"
               See " "+ aLiberty[ Offset ]         ### Dot "."
            ok

        next
        See nl

    next
    See nl+nl
return



###=========================================
### CALCULATE LIBERTY 0..4 for each Square
### Each Square - W/B Assign Liberty number 0,1,2,3,4,


Func CalcLiberty()

    ###------------------------------------
    ### Empty ALL Squares -- Fill With Dots

    for Row = 1 to Size
        for Col = 1 to Size
            CurSq = (Row-1) * Size + Col            ### Offset into aLiberty (0*9+4) = 4 , (1*9+4) = 13
            libertyCount = "."                      ### Fill with "." Dots
            aLiberty[CurSq] = libertyCount
        next
    next

    ###--------------------
    ### Fill aLiberty Array

    for SqNbr = 1 to (Size * Size)

            aDirSq =  CalcSqrNbr(SqNbr)           ### Returns Square Number -- 1-N, 2-S, 3-W, 4-E and 5-CurSq

            North = aDirSq[1]
            East  = aDirSq[2]
            South = aDirSq[3]
            West  = aDirSq[4]
            CurSq = aDirSq[5]

            ###---------------------------------------------
            ### Black and White Squares - Count Liberties

            if aSquare[CurSq] = "W" OR aSquare[CurSq] = "B"

                libertyCount = 0
                aLiberty[CurSq] = libertyCount

                if North != -1  if aSquare[North] = "."  libertyCount++  ok  ok
                if East  != -1  if aSquare[East] = "."   libertyCount++  ok  ok
                if South != -1  if aSquare[South] = "."  libertyCount++  ok  ok
                if West  != -1  if aSquare[West] = "."   libertyCount++  ok  ok

                aLiberty[CurSq] = libertyCount
            ok

    next

    //Display("Liberty")

return


###========================================================
### CALCULATE SQUARE NUMBER 1..81 from Row-Col --  1..Size
###     Return Square number 1..81,  If OUT-OF-BOUNDS: -1

Func CalcSqrNbr(SqrNbr)

    //SqrNbr = ((Row-1) * Size) +Col          // This Square

    North = SqrNbr - Size   if  North < 1            North = -1  ok
    East  = SqrNbr +1       if (SqrNbr % Size) = 0   East  = -1  ok
    South = SqrNbr + Size   if  South > Size*Size    South = -1  ok
    West  = SqrNbr -1       if (West % Size)   = 0   West  = -1  ok

return [North,East,South,West, SqrNbr]

###=================================================
### CALCULATE ROW-COL from Square Number  1..81
###     Return Square number 1..81
###     If OUT-OF-BOUNDS:   -1

Func CalcRowCol(CurSq)

    Row = Ceil( CurSq / Size )      ### 21 / 9  = 2.3 => 2 ,  18/9 = 2 ,  17/9 = 1.9 => 1
    Col = CurSq % Size              ### 21 % 9  = 3 ,         17%9 = 8 ,  18%9 = 0 =>9    ,  19%9 = 1
    if Col = 0  Col = 9  ok

return [Row,Col,CurSq]

###=================================================
### CALCULATE ROW-COL from Square Number  1..81
###     Return Square number
###     If OUT-OF-BOUNDS:   -1

Func CalcRC(CurSq)

    Row = Ceil( CurSq / Size )      ### 21 / 9  = 2.3 => 2 ,  18/9 = 2 , 17/9 = 1.9 => 1
    Col = CurSq % Size              ### 21 % 9  = 3 ,    17%9 = 8 ,  18%9 = 0 =>9 ,  19%9 = 1
    if Col = 0  Col = 9  ok

    RC = "" +Row +"-"+ Col          ### Return format  "3-4"
return RC


###========================================================
### Find same color neighbours - Return SqNbr as Array 1..4

Func FindColorNbor(SqrNbr, Color)

    North = SqrNbr - Size   if  North < 1            OR  aSquare[North] != Color    North = -1  ok
    East  = SqrNbr +1       if (SqrNbr % Size) = 0   OR  aSquare[East]  != Color    East  = -1  ok
    South = SqrNbr + Size   if South > Size*Size     OR  aSquare[South] != Color    South = -1  ok
    West  = SqrNbr -1       if (West % Size)   = 0   OR  aSquare[West]  != Color    West  = -1  ok

return [North,East,South,West, SqrNbr]


###=========================================


###=========================================================
###=========================================================
###=========================================================


###=========================================================
### CLICK - PLAY MOVE ON SQUARE
###
### PLAY  - PUT STONE on Empty Square - then Block Signals
###         ERASE OLD STONE on Old Row-Col

Func pPlay(Row,Col)

See nl+"===================="+nl+nl
See "==>Func-pPlay: "+Row +"-"+ Col +nl

    start = start + 1
    SqNbr = ((Row-1) * Size) + Col         ### 1..81

     ###-----------------------------------------------------------
     ### NEW STONE with CIRCLE - Add to Board - LastPlay

     if PlayerB = 1

        Button[Row][Col] { setIcon(new qIcon(new qPixMap("Black-L.png")))   ### Black Circle Player-1
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(true)
                         }

        aSquare[ SqNbr]  = "B"
        lastColor = "B"
        gBlackStones--

        PlayerB = 0
        PlayerW = 1

        See nl+ "pPlay: "+ Row +"-"+ Col +" "+ lastColor +" - "+ aSquare[ SqNbr]  +" "+  SqNbr +nl

     else

        Button[Row][Col] { setIcon(new qIcon(new qPixMap("White-L.png")))   ### White Circle Player-2
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(true)
                         }

        aSquare[ SqNbr] = "W"
        lastColor = "W"
        gWhiteStones--

        PlayerB = 1
        PlayerW = 0

        See nl+ "pPlay: "+ Row +"-"+ Col +" "+ lastColor +" => "+ aSquare[ SqNbr] +" "+ SqNbr +nl

     ok

     ###-------------------------------------
     ### OLD STONE make Solid  => Old Row-Col
     ### Do NOT do this on FIRST MOVE.

    if start > 1    ### Do NOT do this on FIRST MOVE.

        if PlayerB = 1

            Button[rowOld][colOld] { setIcon(new qIcon(new qPixMap("Black-T.png")))    ### Black Solid
                                     setIconSize(new qSize(SqHeight,SqHeight))
                                     setEnabled(true)
                                     blockSignals(true)
                                   }

            aSquare[ ((rowOld-1) * Size) + colOld]  = "B"

        else

            Button[rowOld][colOld] { setIcon(new qIcon(new qPixMap("White-T.png")))     ### White Solid
                                     setIconSize(new qSize(SqHeight,SqHeight))
                                     setEnabled(true)
                                     blockSignals(true)
                                   }

            aSquare[ ((rowOld-1) * Size) + colOld] = "W"

        ok
    ok

    rowOld = Row
    colOld = Col


                 //Display("Square")
    BlockCount = CheckCapture( SqNbr,lastColor )   ### ===>>>   BlockCount 0 means Escape Possible

                 See "pPlay BlockCount: "+ BlockCount +nl

                 if BlockCount > 0
                     RemoveCapturedStones()
                 ok


   TitleStoneMoves.setText(" Stones: BLK "+ gBlackStones +" : "+ gWhiteStones +" WHT ")
   if gWhiteStones = 0
      TitleStoneMoves.setText("GAME OVER Stones: BLK "+ gBlackStones +" : "+ gWhiteStones +" WHT ")
   ok

return



###============================================
### CHECK-CAPTURE(ROW, COL, LASTCOLOR)
###    Last-Play Row Col Color -- Called By pPlay
###    Check OppColor Neighbours ?
###    North (R-1,C)  South(R+1,C)  East(R,C-1)  West(R,C+1)


Func CheckCapture(SqrNbr, lastColor)

    gEscape = 0                                 ### gEscape Route 1 True , NOT Blocked
    CalcLiberty()                               ### Liberties 0..4 calculated

	 RC = CalcRowCol(SqrNbr)
See nl+"==>Func-CheckCapture: "+ SqrNbr +" "+ lastColor +" "+ RC[1] +"-"+ RC[2] +nl

    aCheckNeighbour = [][]                      ### Square Nbr White Visited=1


    ###------------------------------------------------------
    ### Return [North, East, South, West, SqrNbr]  Invalid -1

    aDirSq = CalcSqrNbr(SqrNbr)                ### SqrNbr returned in array

    OppColor = "W"  if lastColor = "W"  OppColor = "B"   ok

    Blocked = 0
    for k = 1 to 4
        if ( aDirSq[k] >= 1           AND
             aLiberty[aDirSq[k]] = 0  AND
              aSquare[aDirSq[k]] = OppColor )   ### OppColor NO gEscape

            Blocked++
            Add (aCheckNeighbour, [aDirSq[k], OppColor, 1] )    ### This is blocked, Visit=1

            RC = CalcRC( aDirSq[k] )            ### Sq to "R-C"
            See nl+"Blocks "+ OppColor +" "+ aDirSq[k] +" "+ RC +" Liberty: "+ aLiberty[ aDirSq[k] ] +nl+nl

            ###---------------------------------
            ### SET gEscape if Nbor has Liberty

            FindNbor(aDirSq[k], OppColor)       ### ===>>>
        ok
    next

	 RC = CalcRC(SqrNbr)
    See nl+"Check-Capture: BlockedValue: "+ Blocked +" "+ OppColor +" "+ SqrNbr +" "+ RC +nl+nl
    
    if gEscape = 1 
        Blocked = 0                             ### FindNbor SET gEscape also when Blocked >= 1
        See nl+"Check-Capture: gEscape ROUTE Exist: BlockedValue: "+Blocked +" "+ SqrNbr +" "+ RC   +nl+nl
    ok	 
	 

return Blocked




###===============================================================
### FindNeighbours -- Same Color
### aCheckNeighbour = [][]  List of SQ Visit,  Liberty

Func FindNbor(CurSq, OppColor)

RC = CalcRC(CurSq)  ### Row,Col,SqrNbr
//See nl+"==>Func-FindNbor: "+CurSq +" "+ OppColor +" "+ RC +nl


    ###----------------------------------------------------
    ### Find Same Color Neighbour NSWE that was NOT visited
    ###     Return [North, South, West, East, SqrNbr]  Invalid -1

    aSqToVisit = FindColorNbor(CurSq, OppColor)                 ### N S W E array returned

    for k = 1 to 4

        if aSqToVisit[k] > 0                                    ### Valid Neighbour Square 1..81

            ###-------------------------
            ### Find - was SQ Visited

            Nbor = Find( aCheckNeighbour, aSqToVisit[k], 1)     ### SqNbr in Col 1
                RC   = CalcRC(aSqToVisit[k])
                //See "Nbor Find: "+ Nbor +" Sq: "+ aSqToVisit[k] +" "+ RC +" "+ aSquare[aSqToVisit[k]] +nl

            ###-------------------------
            ### ADD - to List

            if Nbor = 0
                Add (aCheckNeighbour, [aSqToVisit[k], OppColor, 0] )    ### Not Visited
                //See "Nbor Add.: "+ Nbor +" Sq: "+ aSqToVisit[k] +" "+ RC +" "+ aSquare[aSqToVisit[k]] +nl
            ok

        ok
    next

    ###---------------------------------------
    ### Show Nbor LIST

    for i = 1 to len(aCheckNeighbour)

        RC      = CalcRC(aCheckNeighbour[i][1])

        SQ      = aCheckNeighbour[i][1]
        Color   = aCheckNeighbour[i][2]
        Visit   = aCheckNeighbour[i][3]
        Liberty = aLiberty[SQ]

       // See    "Nbor List: "+ i +" Sq: "+ SQ  +" "+ RC +" "+ Color +" V "+ visit +" L "+ Liberty +nl
    next

    ###----------------------------------------

    for i = 1 to len(aCheckNeighbour)

        RC    = CalcRC(aCheckNeighbour[i][1])

        SQ    = aCheckNeighbour[i][1]
        Color = aCheckNeighbour[i][2]
        Visit = aCheckNeighbour[i][3]
        Liberty = aLiberty[SQ]

        ###-----------------------
        ### gEscape ROUTE Exists

        if Liberty > 0
		      gEscape = 1								###  ===>>> ESCAPE FOUND
            See "FindNbr gEscape ROUTE FOUND: "+ gEscape =" "+ SQ +" "+ RC   +nl

            return
        ok

        ###------------------------
        ### RECURSION Call

        if Visit = 0
            aCheckNeighbour[i][3] = 1               ### Now SET=VISIT for this SQ

				RC = CalcRC(SQ)
            //See nl+"Recursion Call: "+SQ +" "+ Color +" "+ RC +nl
            FindNbor(SQ, OppColor)      ### ===>>> <<<===  RECURSIVE CALL  Does this SQ have Non-Visited nbor

        ok

    next

    See "Recursion Done: Do we ever get Here "+nl


return

###=============================================================
### Remove Captured Stones - List = aCheckNeighbour[i][1]) = Sq

Func RemoveCapturedStones()

    for k = 1 to len(aCheckNeighbour)

        SQ    =  aCheckNeighbour[k][1]
        Color =  aCheckNeighbour[k][2]
        aRC   =  CalcRowCol(SQ)

        aSquare[SQ] = "."               ### Erase W/B from Square

        Row = aRC[1]
        Col = aRC[2]

            ###-----------------------------------------------------
            ### Some Animation
              button[Row][Col] { setstylesheet(C_ButtonVioletStyle) }
              app.processevents()
              sleep(gDelay)

        button[Row][Col] { setIcon(new qIcon(new qPixMap("Empty-T.png")))
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setStyleSheet(C_ButtonEmptyStyle)        ### Needed to fill Square, image too small

                           setEnabled(true)
                           blockSignals(false)                      ### ??? Goes back to Complement Color ??
                         }
        Sleep(gDelay)

        if Color = "B"  gBlackCaptures++  ok
        if Color = "W"  gWhiteCaptures++  ok

        TitleCaptured.setText(" Captures: BLK "+ gWhiteCaptures +" : "+ gBlackCaptures +" WHT " )

    next

return

###===============================================================
###===============================================================
###===============================================================



###=====================================
### Pick a Empty Square 1..81
### Visit Neighbours
###		- Touchs Blank AND White  = Escape
###		- Touches ONLY Black = BlackTerrritory
###      - Touches ONLY White = WhiteTerritory
### Flip the Dots to White - Figure out Black capturing
### Flip the Dots to Blacl - Figure out Wite capturing
###
### aSquare  = list(Size * Size)    ### "." Dot=Empty B=Black W=White  K=BlackCapture  H=WhiteCapture
### aLiberty = list(Size * Size)    ### 0,1,2,3,4,5
###
### gEscape = 0                     			### gEscape Route = 1 True --- NOT Blocked
### aCheckNeighbour = [][]          			### 2D
### 		   SQ      = aCheckNeighbour[i][1]
###         Color   = aCheckNeighbour[i][2]
###         Visit   = aCheckNeighbour[i][3]
###         Liberty = aLiberty[SQ]
###

Func CalcTerritory(Sq)

	aSquareSave = aSquare							### Original B W Dot Save
	Dot  = "."
	BlkX = "x"											### Black uses x for territory captured
	WhtY = "y"

   WColor = "W"  BColor = "B"  BCap = BlkX		### Do Black Capture first
	
for z = 1 to 2	

	Display("Square")									### Before
	for k = 1 to ( Size*Size )						### Walk and Flip, Dot to W and W to Dot
		if aSquare[k] = Dot
			aSquare[k] = WColor
		elseif aSquare[k] = WColor
			aSquare[k] = Dot
		ok
	next
	Display("Square")									### After
	
	//-----------------------------
   // Check Captures
	
	for k = 1 to  ( Size*Size )					

		if aSquare[k] = BColor
			CheckCapture(k, BColor)

			See nl+"CalcTerritoy Sq: "+k +" Returned gEscape: "+ gEscape +nl+nl
			if gEscape = 1
				loop							 			### Escape FOUND for this Stone, Try next one
			else
				See nl+"NO Escape Found" +nl+nl

				for p = 1 to len(aCheckNeighbour)
					aSquare[aCheckNeighbour[p][1]] = BCap		### Replace Dot with Black Capture "x"
				next
				//Display("Square")
			ok

      ok

		RC = CalcRC(k)
		See "Territory-Done: "+BColor +" "+ k +" "+ RC +nl
		//Display("Square")
		
	next
	
	See "Check Territory Finished "+nl
	
	//------------------------------
	//  UN-Flip Dot and White
	
		for k = 1 to ( Size*Size )					### UN-Flip, Dot to W and W to Dot
			if aSquare[k] = WColor
				aSquare[k] = Dot
			elseif aSquare[k] = Dot
				aSquare[k] = WColor
			ok
		next
		//Display("Square")
	
	//--------------------------------
	// Save Capture result for Black
	
	if BColor = "B"
		aSquareBlkCapture = aSQuare		      ### Save BkackCapture
	ok
	if BColor = "W"
		aSquareWhtCapture = aSQuare		      ### Save WhiteCapture 
	ok
	
	//-------------------------------
	// Restore Orig Board aSquare 
	// Do next color White

   aSquare = aSquareSave                   	### Restore orig, now do White Captures, flip Letters
   WColor = "B"  BColor = "W"  BCap = WhtY

next

	//--------------------------------------------------------
	// Restore Orig Board add the x, and y Captures and Count

	gBlackTerritory = 0
	gWhiteTerritory = 0
	
	aSquare = aSquareSave							### Restore Orig aSquare
	for k = 1 to ( Size * Size)					### Add the x and y capture to aSquare
		if aSquareBlkCapture[k] = BlkX
			aSquare[k] = BlkX
			gBlackTerritory++
		ok
	
		if aSquareWhtCapture[k] = WhtY
			aSquare[k] = WhtY
			gWhiteTerritory++
		ok	
	
	next
	TitleTerritory.setText(" Territory: BLK "+ gBlackTerritory +" : "+ gWhiteTerritory +" WHT " )
	
	Display("Square")									### Display Final B,x,  W,y
	
	//--------------------------------
	
	FillCapturesTerritory()
	
return

###==============================================
### Draw the Mini-Stones for Captured Territory
	
Func FillCapturesTerritory()

   aCapturedT = aSquare							   ### Original B W Dot Save
	Dot  = "."
	BlkX = "x"											### Black uses x for territory captured
	WhtY = "y"
	
	for k = 1 to ( Size * Size)					### Add the x and y capture to aSquare
	
		RC = CalcRowCol(k)
		Row = RC[1]
		Col = RC[2]
	
		if aSquare[k] = BlkX
			
        Button[Row][Col] { setIcon(new qIcon(new qPixMap("Black-C.png")))   ### Black Circle Player-1
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(false)
                         }
     ok

		if aSquare[k] = WhtY
		
        Button[Row][Col] { setIcon(new qIcon(new qPixMap("White-C.png")))   ### White Circle Player-2
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(false)
                         }	
		ok
	
	next
	//------------------------------------------


return

###=====================================

###------------------------------------------------------------
#
#....  1 2 3 4 5 6 7 8 9  ..... 1 2 3 4 5 6 7 8 9     .... 1 2 3 4 5 6 7 8 9   ..... 1 2 3 4 5 6 7 8 9
# 001  . . . . . . . . .    1   . . . . . . . . .     001  . . . . . . . . .     1   . . . . . . . . .
# 010  . . . . . . . . .    2   . . . . . . . . .     010  . . . . . 3 . . .<    2   . . . . . B . . .
# 019  . . . . 2 1 2 . .<   3   . . . . B W B . .     019  . . . . 2 0 2 . .     3   . . . . B W B . .
# 028  . . . 3 0 0 2 . .    4   . . . B W W B . .     028  . . . 3 0 0 2 . .     4   . . . B W W B . .
# 037  . . . . 2 2 . . .    5   . . . . B B . . .     037  . . . . 2 2 . . .     5   . . . . B B . . .
# 046  . . . . . . . . .    6   . . . . . . . . .     046  . . . . . . . . .     6   . . . . . . . . .
# 055  . . . . . . . . .    7   . . . . . . . . .     055  . . . . . . . . .     7   . . . . . . . . .
# 064  . . . . . . . . .    8   W . . . . . . . .     064  . . . . . . . . .     8   W . . . . . . . .
# 073  1 2 . . . . . . .    9   W W . . . . . . .     073  1 2 . . . . . . .     9   W W . . . . . . .
#                ^                                                   ^
#      gEscape at 3-6 24        W gEscape at 3-6 24        W NoEsc at 3-6 24         Block by B at 2-6 15
#


