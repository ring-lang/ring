# Project : CalmoSoft Simple Go Game
# Date    : 28/10/2019-12:00:00
# Update  : 15/11/2019-05:05:59
# Author  : Gal Zsolt (~ CalmoSoft ~), Bert Mariani
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"

Size    = 9       ### Played on 19, 13, or 11 interectins

PlayerB = 1       ### Whose Turn
PlayerW = 0

start   = 0

rowOld  = 0       ### Set after first move
colOld  = 0       ### Set after first move

oldRowMove = 99   ### Flag set on MouseRelease
oldColMove = 99   ### Flag set on MouseRelease

rowLastPlay = 0   ### Record LastPlay
colLastPlay = 0
    

aSquare = list(Size * Size)    ### "." Dot=Empty B=Black W=White  K=BlackCapture  H=WhiteCapture


//------------------------------------
// rgb(220,177,107,255) }               // From Empty-T.png image

oPicBlack  = new QPixmap("Black-T.png")  // Transparent image made with Paint-3D
oPicBlackL = new QPixmap("Black-L.png")  // Black Last Play
oPicBlackM = new QPixmap("Black-M.png")  // Black Opaque

oPicWhite  = new QPixmap("White-T.png")  // White Transparent
oPicWhiteL = new QPixmap("White-L.png")  // White Last Play
oPicWhiteM = new QPixmap("White-M.png")  // White Opaque

oPicEmpty  = new QPixmap("Empty-T.png")    // Empty-T is for Board Squares


bWidth    = oPicBlack.width()       ### 80
bHeight   = oPicBlack.height()      ### 80
eWidth    = oPicEmpty.width()
eHeight   = oPicEmpty.height()


C_Spacing = 0 ### was 5
C_ButtonEmptyStyle  = 'background-color: rgb(220,177,107,255); border-radius: 0px; '
C_ButtonBorderStyle = 'background-color: rgb(220,177,107,255); border-radius: 0px; '  


C_ButtonBlueStyle   = 'border-radius:6px;color:black; background-color: Cyan'
C_ButtonYellowStyle = 'border-radius:6px;color:black; background-color: Yellow'
C_ButtonOrangeStyle = 'border-radius:6px;color:black; background-color: Orange'
C_ButtonVioletStyle = 'border-radius:6px;color:black; background-color: Violet'


Button = newlist(Size+1,Size)
LayoutButtonRow = list(Size+4)

###=====================================================
###=====================================================

app = new qApp
{
    win = new qWidget() 
    {
        setWindowTitle('Go Game')
        setStyleSheet('background-color: rgb(220,177,107,255)')

        move(400,40)
        newSize = eWidth * (size +1)      // number of intersection + border numbers
        reSize( newSize, newSize)         // Based on image size

        winheight = win.height()
        fontSize  = 8 + (winheight / 100)
          
            ###------------------------------------------
            ### Mouse Events
            
            myfilter = new qallevents(win)

            myfilter.setMouseButtonReleaseEvent("pRelease()")
            myfilter.setMouseMoveEvent("pMove()")

            installeventfilter(myfilter)

        ##------------------------------------------------------------------------------
        ### QVBoxLayout lays out Button Widgets in a vertical column, from top to bottom.
        ### VERTICAL

        LayoutButtonMain = new QVBoxLayout() { setSpacing(C_Spacing) setContentsmargins(0,0,0,0) }

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

        for Row = 1 to Size    #                        ### NOT Size+1
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
   }
   exec()
 }

###====================================================

###====================================================
###====================================================
### START - Set all the Square to Empty Icon


Func pStart()

     PlayerB  = 1
     PlayerW  = 0
     start    = 0
    
    for i = 1 to (Size * Size)
      aSquare[i] = "."  ### Mark Row*Col = "Empty" with "."
    next
    
    
    for Row = 1 to Size
        for Col = 1 to Size
            button[Row][Col] { setIcon(new qIcon(new qPixMap("Empty-T.png")))
                               setIconSize(new qSize(eWidth,eHeight))
                               setStyleSheet(C_ButtonEmptyStyle)        ### Needed to fill Square, image too small
                           
                               setEnabled(true)
                               blockSignals(false)                      ### ??? Goes back to Complement Color ??          
                             }
      next 
    next

return

###=========================================================

Func DisplaySquare()
    
   See nl+nl + " 1 2 3 4 5 6 7 8 9 " +nl
   for Row = 1 to Size
      for Col = 1 to Size
         See " "+ aSquare[ ((Row-1) * Size) + Col] 
      next
      See nl
   next
   See nl+nl
return   


###=========================================================
### CLICK - Play Move on Square
### PLAY  - Put Stone on Empty Square - then Block Signals
###         Erase Old Stone on Old Row-Col

Func pPlay(Row,Col)

    See "pPlay: "+ Row +"-"+ Col +nl
    start = start + 1
    
     ###-----------------------------------------------------------
     ### NEW Stone with Circle - Add to Board - LastPlay
     
     if PlayerB = 1

        Button[Row][Col] { setIcon(new qIcon(new qPixMap("Black-L.png")))   ### Black Circle Player-1 
                           setIconSize(new qSize(bWidth,bHeight))
                           setEnabled(true)
                           blockSignals(true)
                         }
                  
        aSquare[ ((Row-1) * Size) + Col]  = "B"                
        PlayerB = 0
        PlayerW = 1
        
     else

        Button[Row][Col] { setIcon(new qIcon(new qPixMap("White-L.png")))   ### White Circle Player-2 
                           setIconSize(new qSize(bWidth,bHeight))
                           setEnabled(true)
                           blockSignals(true)
                         }
                  
        aSquare[ ((Row-1) * Size) + Col] = "W"           
        PlayerB = 1
        PlayerW = 0
          
     ok

     ###-------------------------------------
     ### OLD Stone make Solid  => Old Row-Col 
     ### Do NOT do this on FIRST MOVE.
      
    if start > 1    ### Do NOT do this on FIRST MOVE.

        if PlayerB = 1

            Button[rowOld][colOld] { setIcon(new qIcon(new qPixMap("Black-T.png")))    ### Black Solid
                                     setIconSize(new qSize(bWidth,bHeight))
                                     setEnabled(true)
                                     blockSignals(true)
                                   }
                         
            aSquare[ ((rowOld-1) * Size) + colOld]  = "B"                  
        else

            Button[rowOld][colOld] { setIcon(new qIcon(new qPixMap("White-T.png")))     ### White Solid 
                                     setIconSize(new qSize(bWidth,bHeight))
                                     setEnabled(true)
                                     blockSignals(true)
                                   }
                                   
            aSquare[ ((rowOld-1) * Size) + colOld] = "W"                       
        ok
    ok

    rowOld = Row
    colOld = Col
    
    rowLastPlay = Row   ### Record LastPlay
    colLastPlay = Col
    
    DisplaySquare()

return


###=========================================================

###--------------------------------------------------------------------
### MOUSE - Press, Release, Move  Event Handlers


Func pRelease

    relX = myfilter.getx()                  ### Canvas
    relY = myfilter.gety()

    Row = floor( relY / bHeight ) //-1        ### Mouse Position to Square 
    Col = floor( relX / bWidth  ) //-1    
   
         if Row < 1  Row = 1 ok             ### Stay within boundary size
         if Col < 1  Col = 1 ok
         if Row > Size  Row = Size ok
         if Col > Size  Col = Size ok  

    oldRowMove = 99  ### Flag set on Mouse Move Release. Prevent Illigal Move on Occupied Square
    oldColMove = 99  ### Flag set on Mouse Move Release

    pPlay(Row,Col)                          ### Out New Stone (circle) in Square

return

###------------------------------------------------------------------------
### MOUSE MOVES
### Co-Ord -- CANVAS = getx , SCREEN =  myfilter.getglobalx()

Func pMove

    curX = myfilter.getx()      
    curY = myfilter.gety()

    //----------------------------------
    // NEW Mouse Position

    Row = floor( curY / bHeight ) //-1        ### Mouse Position to Square 
    Col = floor( curX / bWidth  ) //-1   

         if Row < 1  Row = 1 ok             ### Stay within boundary size
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
                                         setIconSize(new qSize(bWidth,bHeight))
                                         setStyleSheet(C_ButtonEmptyStyle)  
                                                                            
                                         setEnabled(true)
                                         blockSignals(false)   
                                       }                              
    ok
    
    //-----------------------------------------
    // CURRENT MOUSE MOVE - Row-Col

    if PlayerB = 1 
        Button[Row][Col] { setIcon(new qIcon(new qPixMap("Black-M.png")))   ### Black Last Play (with white circle)
                           setIconSize(new qSize(bWidth,bHeight))
                           setEnabled(true)
                           blockSignals(false)
                         }  
                                                                      
    else
        Button[Row][Col] { setIcon(new qIcon(new qPixMap("White-M.png")))   ### White Last Play (with white circle)
                           setIconSize(new qSize(bWidth,bHeight))
                           setEnabled(true)
                           blockSignals(false) 
                         }                          
    ok

    
    oldRowMove = Row
    oldColMove = Col
     
return


###-----------------------------------------
 
