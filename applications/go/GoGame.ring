# Project : CalmoSoft Simple Go Game
# Date    : 28/10/2019
# Update  : 17/12/2019
# Author  : Gal Zsolt (~ CalmoSoft ~), Bert Mariani
# Fix     : 24/10/2021  rgb -> fbga

load "stdlib.ring"
load "lightguilib.ring"

Size    = 19               ### Start with 19, Played on 19, 13, or 11 intersections
Size2   = Size * Size   ### Size^2 = Size Squared

PlayerC = "B"     ### Whose Turn

start   = 0

rowOld  = 0       ### Set after first move
colOld  = 0       ### Set after first move

oldRowMove = 99   ### Flag set on MouseRelease
oldColMove = 99   ### Flag set on MouseRelease

aSquare    = list(Size2)    ### "." Dot=Empty B=Black W=White  K=BlackCapture  H=WhiteCapture
aLiberty   = list(Size2)    ### 0,1,2,3,4,5
aDotSquare = list(Size2)    ### Dots Capture = Free, All-Black-Nbor, All-White-Nbor, Mixed-B-W-Nbor
                            ### (Memo: Nbr(s)/nbor means NeighBouR in CalmoSoft's naming convention)

aCheckNeighbour = []        ### 2D List  SQ Visit Liberty

gEscape = 0                 ### gEscape Route = 1 True --- NOT Blocked
gDelay  = 0.2               ### Sleep Delay

gBlackStones    =  Ceil(Size2 / 2)    ### 41  Start with 1/2 of Intersections
gWhiteStones    = Floor(Size2 / 2)    ### 40
gBlackCaptures  = 0
gWhiteCaptures  = 0
gBlackTerritory = 0
gWhiteTerritory = 0

Dot    = "."
WColor = "W"
BColor = "B"


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
C_ButtonEmptyStyle  = 'background-color: rgba(220,177,107,255); border-radius: 0px; '
C_ButtonBorderStyle = 'background-color: rgba(220,177,107,255); border-radius: 0px; '

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

###----------------------------

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
     ScreenWidth  = oDesktop.width()
     ScreenHeight = oDesktop.Height()

     SqHeight = Floor( (ScreenHeight -40) / (Size +2) )
     See "Screen: "+ ScreenWidth +"-"+ScreenHeight +" SqHeight "+ SqHeight +" Size "+ Size +nl

    win = new qWidget()
    {
        setWinIcon(self,"White-T.png")
        setWindowTitle(" GO-Game ")
        setStyleSheet('background-color: rgba(220,177,107,255)')
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
            setStyleSheet("background-color:rgba(220,177,107,255)")
            setFont(new qFont("Calibri",fontsize,100,50))
            setAlignment( Qt_AlignVCenter)
            setAlignment( Qt_AlignVCenter)
            setText(" Stones: BLK "+ gBlackStones +" : "+ gWhiteStones +" WHT ")
         }

         TitleCaptured = new qLineEdit(win)
         {
            setStyleSheet("background-color:rgba(220,177,107,255)")
            setFont(new qFont("Calibri",fontsize,100,60))
            setAlignment( Qt_AlignVCenter)
            setAlignment( Qt_AlignVCenter)
            setText(" Captures: BLK "+ gWhiteCaptures +" : "+ gBlackCaptures +" WHT " )
         }

         TitleTerritory = new qLineEdit(win)
         {
            setStyleSheet("background-color:rgba(220,177,107,255)")
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

         Radio5 = new qRadioButton(win) { setText("Ter")  setClickedEvent("RadioBtnClicked()") }  ### ===>>> Territory

         NewGame   = new QPushButton(win)
         {
            setStyleSheet("background-color:rgba(220,177,107,255)")
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

        TitleLet = list(Size +0)        ### +1 Array of qLabel Object
        Number = 65                     ### 64 = @ A B .. H I

        for Col = 1 to Size +0
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
            //TitleLet[1].setText(" ")                  ### Blank out the @
            for Col = 1 to Size +0                      ### Add +1 because of LeftMost Labels @
                LayoutTitleRow.AddWidget(TitleLet[Col])
            next

        LayoutButtonMain.AddLayout(LayoutTitleRow)      ### Layout - Add  TITLE-ROW on TOP

        ###----------------------------------------------
        ###----------------------------------------------
        ### Vertical Rows Button = Numbers 1..9

        TitleNum = list(Size +1)    ### Array of qLabel Object

        for Row = 1 to Size
        //See "VerticalRow: "+ Row +nl

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

        ### ERROR if Size Default 9, Then Increased from Small to Large for New Game

        for Row = 1 to Size                            ### NOT Size+1
            //See "LayoutButtonRow: Size: "+ Size +" Size2: "+ Size2 +" Row: "+ Row +nl  ### DEBUG
            LayoutButtonRow[Row] = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }

            LayoutButtonRow[Row].AddWidget(TitleNum[Row])

            ### CLICK PLAY MOVE >>pPlay()
            for Col = 1 to Size
                Button[Row][Col] = new QPushButton(win) ### Create PUSH BUTTONS
                                   { setClickEvent("pPlay(" + string(Row) + "," + string(Col) + ")")   ### CLICK PLAY MOVE >>> pPlay
                                     setSizePolicy(1,1)
                                   }

                LayoutButtonRow[Row].AddWidget(Button[Row][Col])    ### Widget - Add HORIZONTAL BUTTON
            next

            LayoutButtonMain.AddLayout(LayoutButtonRow[Row])         ### Layout - Add ROW of Buttons
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
   Button = newlist(Size+1,Size)       ### Set Button List to New Size

   gBlackStones    =  Ceil(Size2 / 2)  ### 41  Start with 1/2 of Intersections
   gWhiteStones    = Floor(Size2 / 2)  ### 40
   gBlackCaptures  = 0
   gWhiteCaptures  = 0
   gBlackTerritory = 0
   gWhiteTerritory = 0

   DrawWidget()                        ### Draw the New Layout

   pStart()

return

###====================================================

Func RadioBtnToggled()

   see"Radio Toggled: " + Radio1.isChecked() + Radio2.isChecked() + Radio3.isChecked() + Radio4.isChecked() + Radio5.isChecked() +nl

   if Radio1.isChecked() Size =  9   Size2 = (Size * Size) ok
   if Radio2.isChecked() Size = 11   Size2 = (Size * Size) ok
   if Radio3.isChecked() Size = 13   Size2 = (Size * Size) ok
   if Radio4.isChecked() Size = 19   Size2 = (Size * Size) ok
return

###====================================================

Func RadioBtnClicked()

   See nl+ "Radio Clicked: Territory " + Radio5.isChecked()  + " >>==>>==>>==>>==>>==>>==>>==>>==>>> " +nl

   if Radio5.isChecked()
         See "RadioBtnClicked: CALL  CalcTerritory " +nl+nl


            ###-------------------------------------------------------
            ### Clear residue if Radio-Ter clicked again during game

            for i = 1 to Size2
                if ( aSquare[i] = "n" OR
                     aSquare[i] = "x" OR
                     aSquare[i] = "y" )

                     aSquare[i] = DOT
                ok
            next


         CalcTerritory()
   ok

return


###====================================================
### START - Set all the Square to Empty Icon


Func pStart()

   //See "pStart Size: "+ Size +nl

   PlayerC  = "B"

   start    = 0

   aSquare  = []
   aLiberty = []

   aSquare  = list(Size2)     ### "." Dot=Empty B=Black W=White  K=BlackCapture  H=WhiteCapture
   aLiberty = list(Size2)     ### 0,1,2,3,4,5

   for i = 1 to (Size2)
      aSquare[i] = "."        ### Mark Row*Col = "Empty" with "."
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

    relX = myfilter.getx()                   ### Canvas
    relY = myfilter.gety()

    Row = floor( relY / SqHeight ) //-1      ### Mouse Position to Square
    Col = floor( relX / SqHeight  ) //-1

         if Row < 1  Row = 1 ok              ### Stay within boundary size
         if Col < 1  Col = 1 ok
         if Row > Size  Row = Size ok
         if Col > Size  Col = Size ok

    oldRowMove = 99  ### Flag set on Mouse Move Release. Prevent Illegal Move on Occupied Square
    oldColMove = 99  ### Flag set on Mouse Move Release

    pPlay(Row,Col)                           ### Out New Stone (circle) in Square

return

###===========================================================
### MOUSE MOVES
### Co-Ord -- CANVAS = getx , SCREEN =  myfilter.getglobalx()

Func pMove

    curX = myfilter.getx()
    curY = myfilter.gety()

    //----------------------------------
    // NEW Mouse Position

    Row = floor( curY / SqHeight ) //-1         ### Mouse Position to Square
    Col = floor( curX / SqHeight  ) //-1

         if Row < 1  Row = 1 ok                 ### Stay within boundary size
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

    if PlayerC = "B"
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
### DISPLAY ASQUARE  with B W     Dot
### Display aLiberty with 1 2 3 4 .
### Call Display(Square)  or Display(Liberty)

Func Display(aType)

    //See "Display aType: Size: "+Size +" Size2: "+ Size2  +nl

    See nl + "....... 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9" +nl
    for Row = 1 to Size

        RowStart = ((Row-1)*Size) +1            ### Allow up to 19*19 = 361

        if    RowStart <  10     RowStart = "00"+  RowStart
        but   RowStart < 100     RowStart =  "0"+  RowStart
        ok

        if Row < 10   cRow = "0"+ Row  ok       ### Add leading alpha "0"
        See " "+ RowStart +" "+ cRow

        ### Print Dots

        RowIndex = (Row-1) * Size               ### Start of Row
        for Col = 1 to Size
            Offset =  RowIndex + Col            ### Offset into aLiberty (0*9+4) = 4 , (1*9+4) = 13

            See " "+ aType[Offset]
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

    for i = 1 to  Size2
            aLiberty[i] = "."

            if  ( aSquare[i] = "n"  OR  aSquare[i] = "x"  OR  aSquare[i] = "y" )
                aSquare[i] = DOT
            ok
    next

    ###--------------------
    ### Fill aLiberty Array

    for SqNbr = 1 to (Size2)

            aDirSq =  CalcSqrNbr(SqNbr)          ### Returns Square Number -- 1-N, 2-S, 3-W, 4-E and 5-CurSq

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

    See "CalcLiberty: CALL Display aLiberty: "+nl
    Display(aLiberty)
    See "CalcLiberty: CALL Display aSquare: "+nl
    Display(aSquare)

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
    if Col = 0  Col = Size  ok

return [Row,Col,CurSq]

###=================================================
### CALCULATE ROW-COL from Square Number  1..81
###     Return Square number
###     If OUT-OF-BOUNDS:   -1

Func CalcRC(CurSq)

    Row = Ceil( CurSq / Size )      ### 21 / 9  = 2.3 => 2 ,  18/9 = 2 , 17/9 = 1.9 => 1
    Col = CurSq % Size              ### 21 % 9  = 3 ,    17%9 = 8 ,  18%9 = 0 =>9 ,  19%9 = 1
    if Col = 0  Col = Size  ok

    RC = "" +Row +"-"+ Col          ### Return format  "3-4"
return RC


###========================================================
### Find same color neighbours - Return SqNbr as Array 1..4
###
###  North  -4 -3 -2 -1  0
###                          East
###  West    1  2  3  4  5   6%5=1
###  5%5=0   6  7  8  9 10  11%5=1
### 10%5=0  11 12 13 14 15  16%5=1
### 15%5=0  16 17 18 19 20  21%5=1
### 20%5=0  21 22 23 24 25  26%5=1
###
###  South  26 27 28 28 30

Func FindColorNbor(SqrNbr, Color)

   RC = CalcRC(SqrNbr)
   //See "FindColorNbr: "+ SqrNbr +" "+ RC +" "+ Color +nl

    North = SqrNbr - Size   if  North  < 1           OR  aSquare[North] != Color    North = -1  ok
    East  = SqrNbr + 1      if (East   % Size) = 1   OR  aSquare[East]  != Color    East  = -1  ok
    South = SqrNbr + Size   if  South  > Size2       OR  aSquare[South] != Color    South = -1  ok
    West  = SqrNbr - 1      if (West   % Size) = 0   OR  aSquare[West]  != Color    West  = -1  ok

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

See nl+"=========================="+nl
See    "==> "

    if gBlackStones = 0
        See "GAME FINISHED: "+nl
      CalcTerritory()

      TitleStoneMoves.setStyleSheet("background-color:rgba(255,255,255,255)")
        TitleCaptured.setStyleSheet("background-color:rgba(255,255,255,255)")
       TitleTerritory.setStyleSheet("background-color:rgba(255,255,255,255)")
        return
    ok

    start = start + 1
    SqrNbr = ((Row-1) * Size) + Col         ### 1..81

     ###-----------------------------------------------------------
     ### NEW STONE with CIRCLE - Add to Board - LastPlay

     if PlayerC = "B"

        Button[Row][Col] { setIcon(new qIcon(new qPixMap("Black-L.png")))   ### Black Circle Player-1
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(true)
                         }

        aSquare[ SqrNbr]  = "B"
        lastColor = "B"
        gBlackStones--

        PlayerC = "W"

        See "pPlay: "+ lastColor +" SQ "+  SqrNbr +" "+ Row +"-"+ Col +nl

     else

        Button[Row][Col] { setIcon(new qIcon(new qPixMap("White-L.png")))   ### White Circle Player-2
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(true)
                         }

        aSquare[ SqrNbr] = "W"
        lastColor = "W"
        gWhiteStones--

        PlayerC = "B"

        See "pPlay: "+ lastColor +" SQ "+  SqrNbr +" "+ Row +"-"+ Col +nl

     ok

     ###-------------------------------------
     ### OLD STONE make Solid  => Old Row-Col
     ### Do NOT do this on FIRST MOVE.

    if start > 1    ### Do NOT do this on FIRST MOVE.

        if PlayerC = "B"

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

    See "pPlay: Display aSqaure: "+nl
    Display(aSquare)

    See "pPlay CALLS CheckCapture with: SQ "+ SqrNbr +" "+ Row +"-"+ Col +" "+ lastColor +nl

    ###---------------------------------------------
    ### ===>>>   BlockCount 0 means Escape Possible

    BlockCount = CheckCapture( SqrNbr,lastColor )

                 See ">=>=>= pPlay: Got Return: BlockCount: "+ BlockCount +" gEscape "+ gEscape +nl

                 if BlockCount > 0
                     See "pPlay: BlockCount: "+ BlockCount +" Remove Captures Stones "+ nl
                     RemoveCapturedStones()
                 ok


   TitleStoneMoves.setText(" Stones: BLK "+ gBlackStones +" : "+ gWhiteStones +" WHT ")
   if gWhiteStones = 0
      TitleStoneMoves.setText("FINISH: BLK "+ gBlackStones +" : "+ gWhiteStones +" WHT ")
   ok

return



###============================================
### CHECK-CAPTURE(ROW, COL, LASTCOLOR)
###    Last-Play Row Col Color -- Called By pPlay
###    Check OppColor Neighbours ?
###    North (R-1,C)  South(R+1,C)  East(R,C-1)  West(R,C+1)


Func CheckCapture(SqrNbr, lastColor)

    RC  = CalcRC(SqrNbr)
    RCA = CalcRowCol(SqrNbr)

    See nl+"================================= "+nl
    See    "==> Func-CheckCapture: "+lastColor +" "+ SqrNbr +" RC "+ RC +" RCA "+ RCA[1] +"-"+ RCA[2] +nl+nl

    See "CheckCapture: CALL CalcLiberty "+nl
    gEscape = 0                                 ### gEscape Route 1 True , NOT Blocked
    CalcLiberty()                               ### Liberties 0..4 calculated

    aCheckNeighbour = []                        ### Square Nbr White Visited=1


    ###------------------------------------------------------
    ### Return [North, East, South, West, SqrNbr]  Invalid -1

    aDirSq = CalcSqrNbr(SqrNbr)                 ### SqrNbr returned in array

    OppColor = "W"  if lastColor = "W"  OppColor = "B"   ok

    Blocked = 0
    for k = 1 to 4
        if ( aDirSq[k] >= 1           AND
             aLiberty[aDirSq[k]] = 0  AND
              aSquare[aDirSq[k]] = OppColor )   ### OppColor NO gEscape

            Blocked++
            Add (aCheckNeighbour, [aDirSq[k], OppColor, 1] )    ### This is blocked, Visit=1

            RC = CalcRC( aDirSq[k] )            ### Sq to "R-C"
            See nl+"CheckCapture By: "+lastColor +" Blocks "+ OppColor +" "+ aDirSq[k] +" "+ RC +" Liberty: "+ aLiberty[ aDirSq[k] ] +" >>>>> " +nl+nl

            ###---------------------------------
            ### SET gEscape if Nbor has Liberty

            FindNbor(aDirSq[k], OppColor)       ### ===>>>
        ok
    next


    if gEscape = 1
        Blocked = 0                             ### FindNbor SET gEscape also when Blocked >= 1
        See nl+"Check-Capture: ESCAPE ROUTE EXIST: BlockedValue: "+Blocked +" "+ OppColor +" "+ SqrNbr +" "+ RC +" >>>>> " +nl+nl
    ok

    RC = CalcRC(SqrNbr)
    See nl+"Check-Capture By: "+ lastColor  +" BlockedValue: "+ Blocked +" "+ OppColor +" "+ SqrNbr +" "+ RC +" >>>>> " +nl+nl


return Blocked

###===============================================================
### FindNeighbours -- Same Color
### aCheckNeighbour = []    List of SQ Visit,  Liberty

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
                //See "FindNbor: Nbor Find: "+ Nbor +" Sq: "+ aSqToVisit[k] +" "+ RC +" "+ aSquare[aSqToVisit[k]] +nl

            ###-------------------------
            ### ADD - to List

            if Nbor = 0
                Add (aCheckNeighbour, [aSqToVisit[k], OppColor, 0] )    ### 0 = Not Visited
                //See "FindNbor: Nbor Add.: "+ Nbor +" Sq: "+ aSqToVisit[k] +" "+ RC +" "+ aSquare[aSqToVisit[k]] +nl
            ok

        ok
    next

    ###---------------------------------------
    ### Show Nbor LIST


    for i = 1 to len(aCheckNeighbour)

        RC    = CalcRC(aCheckNeighbour[i][1])

        SQ    = aCheckNeighbour[i][1]
        Color = aCheckNeighbour[i][2]
        Visit = aCheckNeighbour[i][3]
        Liberty = aLiberty[SQ]

        //See "FindNbor: Nbor List: "+ i +" Sq: "+ SQ  +" "+ RC +" "+ Color +" V "+ visit +" L "+ Liberty  +nl

        ###-----------------------
        ### gEscape ROUTE Exists

        if Liberty  > 0
            gEscape = 1                      ###  ===>>> ESCAPE FOUND
            See "FindNbr: gEscape ROUTE FOUND Liberty: "+ Liberty +" "+ OppColor +" "+ SQ +" "+ RC +" >>>>> " +nl

            RETURN                           ###  ===>>>>  RETURN
        ok

        ###------------------------
        ### RECURSION Call

        if Visit = 0
            aCheckNeighbour[i][3] = 1        ### Now SET=VISIT for this SQ

            RC = CalcRC(SQ)
            //See nl+"FindNbor: SET VISIT Recursion Call: "+SQ +" "+ Color +" "+ RC +" <<<<<>>>>> " +nl

            FindNbor(SQ, OppColor)           ### ===>>> <<<===  RECURSIVE CALL  Does this SQ have Non-Visited nbor

        ok

    next

    RC = CalcRC( CurSq)
    //See "Recursion ALL Done: Return "+ CurSq +" "+ RC +" "+ OppColor +nl+nl


return

###=============================================================
### Remove Captured Stones - List = aCheckNeighbour[i][1]) = Sq

Func RemoveCapturedStones()

    for k = 1 to len(aCheckNeighbour)

        SQ    =  aCheckNeighbour[k][1]
        Color =  aCheckNeighbour[k][2]
        aRC   =  CalcRowCol(SQ)
         RC   =  CalcRC(SQ)

        aSquare[SQ] = "."                                            ### Erase W/B from Square
        See "RemoveCapturedStones: "+SQ +" "+ RC +" "+ Color +nl

        Row = aRC[1]
        Col = aRC[2]

            ###-----------------------------------------------------
            ### Some Animation
              button[Row][Col] { setstylesheet(C_ButtonVioletStyle) }
              app.processevents()
              sleep(gDelay)

        button[Row][Col] { setIcon(new qIcon(new qPixMap("Empty-T.png")))
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setStyleSheet(C_ButtonEmptyStyle)         ### Needed to fill Square, image too small

                           setEnabled(true)
                           blockSignals(false)                       ### ??? Goes back to Complement Color ??
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
###      - Touches Blank AND White  = FREE
###      - Touches ONLY Black      = BlackTerritory
###      - Touches ONLY White      = WhiteTerritory
###
### aCheckNeighbour = []           ### 2D
###         SQ      = aCheckNeighbour[i][1]
###         Color   = aCheckNeighbour[i][2]
###         Visit   = aCheckNeighbour[i][3]
###         Liberty = aLiberty[SQ]
###

Func CalcTerritory()
    Color = DOT
    aCheckNeighbour = []

   ###----------------------------
   ### 2nd CalcTer etc -- Remove the Old Captures
   ### CLEAR out Small Blk and Wht captures in GUI

    for i = 1 to Size2
       if  (   aDotSquare[i] = "x"  OR  aDotSquare[i] = "y" ) AND aSquare[i] = DOT  ### DEBUG Change Size

                RC = CalcRowCol(i)
                Row = RC[1]
                Col = RC[2]

                //See "CalcTer: CLEAR CapTerSq: "+ i + " "+ RC[1] +"-"+ RC[2] +nl

                button[Row][Col] { setIcon(new qIcon(new qPixMap("Empty-T.png")))
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setStyleSheet(C_ButtonEmptyStyle)         ### Needed to fill Square, image too small

                           setEnabled(true)
                           blockSignals(false)                       ### ??? Goes back to Complement Color ??
                         }

       ok
    next


   ###------------------------------
   ### Put back from 0 to DOT
   ### Will be owned by Nobody=n, Black=x, White=w

   for i = 1 to Size2
       aDotSquare[i] = DOT
       aLiberty[i]   = DOT
   next

   //--------------------------------------------------

    for ThisSquare = 1 to  Size2

       aCheckNeighbour = []

       RC = CalcRC(ThisSquare)
       //See "CalcTer: FindNbor for ThisSquare: "+ThisSquare +" "+ RC +nl

       if aSquare[ThisSquare] = DOT  AND aDotSquare[ThisSquare] = DOT
             FindNbor(ThisSquare, DOT)           ### ===>>>
       else
          LOOP                                   ### Skip Black or White
       ok


       aCheckNeighbour = Sort(aCheckNeighbour, 1)

       ###------------------------------------------------------------
       ### List all the DOT Squares connected to Dot-ThisSquare Nbors

       for i = 1 to len(aCheckNeighbour)
            RC    = CalcRC(aCheckNeighbour[i][1])
            SQ    = aCheckNeighbour[i][1]
            Color = aCheckNeighbour[i][2]
            Visit = aCheckNeighbour[i][3]
            Liberty = aLiberty[SQ]
            //See "CalcTer: DOT Nbor List: "+ i +" Sq: "+ SQ  +" "+ RC +" "+ Color +" V "+ visit +" L "+ Liberty  +nl
       next

       ###---------------------------------------------------------------------
       ### Are there Neighbours of the DOT squares --- Black or White Nbor, or Mixed

       SumBlk = 0
       SumWht = 0

       for i = 1 to len(aCheckNeighbour)
          SQ = aCheckNeighbour[i][1]
          RC = CalcRC(SQ)

          aBlkWht = DotBlkWhtNbor(SQ)      ### ===>>>  Count number of Blk and Wht Nbors
          CBlk =  aBlkWht[1]
          CWht =  aBlkWht[2]

          //See "CalcTer: CurSq: "+SQ +" "+ RC +" Blk "+ CBlk +" Wht "+ CWht +nl
          SumBlk = SumBlk + CBlk
          SumWht = SumWht + CWht
       next

       See "CalcTer: DOT-Nbors: Blk "+ SumBlk +" Wht "+ SumWht +nl

       //----------------------------------------
       // Who owns the DOT Sq Territory

       if SumBlk >= 1 AND SumWht >= 1
          // Nobody's Territory
          for i = 1 to len(aCheckNeighbour)
             SQ = aCheckNeighbour[i][1]
             RC = CalcRC(SQ)

             if !(aDotSquare[SQ] = "x" OR aDotSquare[SQ] = "y")
                aDotSquare[SQ] = "n"
             ok
          next

       but SumBlk >= 1 AND SumWht = 0
          // Black's Territory

          for i = 1 to len(aCheckNeighbour)
             SQ = aCheckNeighbour[i][1]
             RC = CalcRC(SQ)

             if !(aDotSquare[SQ] = "x" OR aDotSquare[SQ] = "y")
                aDotSquare[SQ] = "x"
             ok
          next

       but SumBlk = 0 AND SumWht >= 1
          // White's Territory

          for i = 1 to len(aCheckNeighbour)
             SQ = aCheckNeighbour[i][1]
             RC = CalcRC(SQ)

             if !(aDotSquare[SQ] = "x" OR aDotSquare[SQ] = "y")
                aDotSquare[SQ] = "y"
             ok
          next

       ok

       ###---------------------------------------------
       ### Copy the Black and White Stones from aSquare

       for i = 1 to Size2
          if aSquare[i] = "B"  OR    aSquare[i] = "W"
             aDotSquare[i] = aSquare[i]
          ok
       next

       //See "CalcTer: Display aDotSquare"+nl
       //Display(aDotSquare)


    next

    See nl+"CalcTer: End of aDotSquares to look at "+nl+nl

   ###--------------------------------------------------------------
   ### Check for SINGLE DOTS ---  Any Left Over Dots in aDotSquare for Corner Capture

   FindSingleDots()

   ###---------------------------------
   ### Draw update Territory Captures

   aSquare = aDotSquare
   FillCapturesTerritory()

    //See "CalcTer: Display aDotSquare"+nl    Display(aDotSquare)
      See "CalcTer: Display aSquare"+nl       Display(aSquare)

    ###------------------------
    ### Territory update count

    gBlackTerritory = 0
    gWhiteTerritory = 0
    for i = 1 to Size2
        if aDotSquare[i] = "x"   gBlackTerritory++ ok
        if aDotSquare[i] = "y"   gWhiteTerritory++ ok
    next
    TitleTerritory.setText(" Territory: BLK "+ gBlackTerritory +" : "+ gWhiteTerritory +" WHT " )


return


###===========================================================
### aDotSquare --- Will be owned by Nobody=n, Black=x, White=w

Func FillDotOwner(Owner)

   aDotToVisit =[]                     ### These are Dot that B or W owns

   for i = 1 to len(aCheckNeighbour)

      RC    = CalcRC(aCheckNeighbour[i][1])
      SQ    = aCheckNeighbour[i][1]
      Color = aCheckNeighbour[i][2]
      Visit = aCheckNeighbour[i][3]
      Liberty = aLiberty[SQ]

      if Liberty = Dot                 ### Liberty = 0  need to be inspected
         See "FillDotOwner: SQ "+SQ +" "+ RC +" "+ Owner +nl
         aDotSquare[SQ] = Owner
      else
         Add( aDotToVisit, SQ)
      ok

   next


   for i = 1 to len(aDotToVisit)
      SQV= aDotToVisit[i]
      RC = CalcRc(SQV)
      See "FillDotOwner: aDotToVisit: "+SQV +" "+ RC +nl
   next

   See "FillDotOwner: Display aDotSquare"+nl
   Display(aDotSquare)

return


###===========================================================
### Does any DOT in the Nbor List have a Black or White Nbor

Func  DotBlkWhtNbor(SqrNbr)

   //See "DotBlkWhtNbor:: Check Nbors of "+SqrNbr +" "+ RC +nl

   FlagBColor = 0
   FlagWColor = 0

    North = SqrNbr - Size
    if  North < 1
         North = -1
    else
         RC = CalcRC(North)
         //See "North: "+ North +" "+ RC +" "+ aSquare[North] +nl

         if  aSquare[North] = BColor
             FlagBColor++
         ok
         if  aSquare[North] = WColor
             FlagWColor++
         ok
    ok


    East  = SqrNbr +1
    if (East % Size) = 1
      East  = -1
    else
         RC = CalcRC(East)
         //See "East.: "+ East +" "+ RC +" "+ aSquare[East] +nl

         if  aSquare[East] = BColor
             FlagBColor++
         ok
         if  aSquare[East] = WColor
             FlagWColor++
         ok
    ok

    South = SqrNbr + Size
    if South > Size2
         South = -1
    else
         RC = CalcRC(South)
         //See "South: "+ South +" "+ RC +" "+ aSquare[South] +nl

         if  aSquare[South] = BColor
             FlagBColor++
         ok
         if  aSquare[South] = WColor
             FlagWColor++
         ok
    ok

    West  = SqrNbr -1
    if (West % Size) = 0
         West  = -1
    else
         RC = CalcRC(West)
         //See "West.: "+ West +" "+ RC +" "+ aSquare[West]+nl

         if  aSquare[West] = BColor
             FlagBColor++
         ok
         if  aSquare[West] = WColor
             FlagWColor++
         ok
    ok

   RC = CalcRC(SqrNbr)
   //See "CalcTer: Nbors of DOT "+SqrNbr +" "+ RC + " FlagB "+ FlagBColor +" FlagW "+  FlagWColor +nl


return [FlagBColor, FlagWColor]

###==================================================================
### Check if aDotSquare[i] has Single Dots surrounded by Black White

Func FindSingleDots()

   //See "FindSingleDots"+nl

   for ThisSquare = 1 to Size2                  ### 1..81
      if aDotSquare[ThisSquare] = Dot           ### Look for Single DOT

         RC = CalcRC(ThisSquare)
         //See "FindSingleDots: ThisSquare: "+ThisSquare +" "+ RC  +nl

         SumBlk = 0
         SumWht = 0

         aBlkWht = DotBlkWhtNbor(ThisSquare)    ### ===>>>  Count number of Blk and Wht Nbors

         CBlk =  aBlkWht[1]
         CWht =  aBlkWht[2]

         //See "FindSingleDots: ThisSquare: "+ThisSquare +" "+ RC +" Blk "+ CBlk +" Wht "+ CWht +nl
         SumBlk = SumBlk + CBlk
         SumWht = SumWht + CWht

         ###-------------------------------
         ### Check Nbor Colors

         if SumBlk >= 1  and SumWht >= 1
            aDotSquare[ThisSquare]  = "n"
         ok

         if SumBlk >= 1  and SumWht  = 0
            aDotSquare[ThisSquare]  = "x"
         ok

         if SumBlk  = 0  and SumWht >= 1
            aDotSquare[ThisSquare]  = "y"
         ok

         //---------------------------------

      ok
   next

return

###==============================================
### Draw the Mini-Stones for Captured Territory

Func FillCapturesTerritory()


   for k = 1 to ( Size2)               ### Add the x and y capture to aSquare

      RC = CalcRowCol(k)
      Row = RC[1]
      Col = RC[2]

      //See "FillCapturesTerritory: Sq: "+k +" "+ Row +"-"+ Col  +nl

      if aSquare[k] = "x"

        Button[Row][Col] { setIcon(new qIcon(new qPixMap("Black-C.png")))   ### Black Circle Player-1
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(false)
                         }
      ok

      if aSquare[k] = "y"

        Button[Row][Col] { setIcon(new qIcon(new qPixMap("White-C.png")))   ### White Circle Player-2
                           setIconSize(new qSize(SqHeight,SqHeight))
                           setEnabled(true)
                           blockSignals(false)
                         }
      ok

   next
   //------------------------------------------


return


###===============================

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


