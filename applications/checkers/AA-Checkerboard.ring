### Program: Checkers 2 Players - Manual - International Rules - MUST Jump
### Author:  Bert Mariani
### Date:    2019-04-10

load "stdlibcore.ring"
load "lightguilib.ring"
load "CheckerPuzzles.ring"     ### A File with Checker Puzzles to Solve  

###-------------------
### Track Moves

TurnColor       = "Black"      ### "Black"
FlagStartMove   = 0

###-------------------
### WINDOW SIZE

sizeX  = 700 sizeY  = 600       ### Size of Window

hSize   = 8 +2 +2   ### Size of array, Display -4 smaller
vSize   = 8 +2 +2   ### Size of array, Display -4 smaller

h   = 0 ### Horizontal coordinate of Cell
v   = 0 ### Vertical coordinate of Cell


###----------------------------------------------------------
### Global so other functions can access the workWidget items

aArray           = null
aButton          = null
workWidget       = null
recordArray      = null
comboPromotePawn = null
comboPuzzleName  = null
puzzleName       = "BoardLayout"  ### Default setup

TitletMoves       = null
TitletInvalidMove = null
LayoutButtonRow   = null


FlagMustJump  = 0      ### Count how many jumps possible
aArrayMustJump  = null      ### Record MustJump moves: Piece(BP) From(h,v) To(h.v)
PreviousMoveJump = 0        ### Used if multiply Jump possible

###-------------------------

FlagStartMove = 0
FromRow = 1
FromCol = 1
ToRow   = 5
ToCol   = 3
OldRow  = 3
OldCol  = 3
PickedPiece = "ee"

###-----------------------------------------------------------
### 1 - Who = index into Lookup Table,  1,2,3,4 Good  || 0 = no entry
###     Who = Find(aLookup, aArray[h][v], 1)        ### Find Key: field 1
###           DrawImage( aLookup[Who][2], h, v )    ### Find Value: field 2
###         

aLookup = [ ["BP","CKR-BP.png"],
            ["BK","CKR-BK.png"],
            ["WP","CKR-WP.png"],
            ["WK","CKR-WK.png"]
          ]

###-------------------------------------------------------------
###  Standard Board Layout
###  ChessPuzzles.ring has Other Layouts to Solve
###     Ex. Puzzle1, Puzzle2, Puzzle3  etc
      
BoardLayout = [ 
    ["..","WP","..","WP","..","WP","..","WP"],
    ["WP","..","WP","..","WP","..","WP",".."],
    ["..","WP","..","WP","..","WP","..","WP"],  
    ["ee","..","ee","..","ee","..","ee",".."],
    ["..","ee","..","ee","..","ee","..","ee"],
    ["BP","..","BP","..","BP","..","BP",".."],  
    ["..","BP","..","BP","..","BP","..","BP"],
    ["BP","..","BP","..","BP","..","BP",".."] ]
    

 
###--------------------------------------------------------------
### Piece on Square - Scale it later
### Windows Icon for Application

King      = AppFile("CKR-BK.png")
oKing     = new QPixmap(King)
bWidth    = oKing.width()         ### 50 
bHeight   = oKing.height()        ### 50

nMoves    = 0   ### Source        Move =2 by Black  =3 by White
oldNMoves = 9   ### Destination   Move =2 by Black  =3 by While
oldH   = 0
oldV   = 0

###-----------------------

C_ButtonImageWidth  = 60 
C_ButtonImageHeight = 60 
C_ButtonMinWidth    = 70
C_ButtonMinHeight   = 70
C_Spacing  = 2
C_ButtonFirstStyle  = 'border-radius:1px; color:black; background-color: rgb(229,249,203) ;'        ### Square pale
C_ButtonSecondStyle = 'border-radius:1px; color:black; background-color: rgb(179,200,93); '         ### Square dark
C_ButtonPickStyle   = 'border-radius:1px; color:black; background-color: rgb(255,255,93); '         ### Yellow             
C_ButtonDestStyle   = 'border-radius:1px; color:black; background-color: rgb(204,255,204); '        ### Cyan
C_ButtonCheckStyle  = 'border-radius:1px; color:black; background-color: rgb(204,93,93); '          ### Rust
C_ButtonInvalidStyle= 'border-radius:1px; color:black; background-color: rgb(255,102,102); '        ### Light Pink
C_ButtonPaleStyle   = 'border-radius:1px; color:black; background-color:rgb(255,255,204); '         ### Pale white turn
C_ButtonDarkStyle   = 'border-radius:1px; color:black; background-color:rgb(204,255,255); '         ### Pale black turn
C_ButtonTurnStyle   = 'border-radius:1px; color:black; background-color: rgb(128,191,255); '        ### Maya blue
                        ###'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '
    
    
    
###=============================================================================
###=============================================================================
### The shortest app function you ever seen !
### The DrawWidget function does what is normally in this section

app = new qApp 
{
    
    DrawWidget()
    NewGameStart()
    exec()
}
    
###---------------------


###=================================================
###=================================================

### FUNCTIONS 

###---------------------------------------------------------------------------
### Layout the Grid Square, Create the Arrays
### workWidget items need to be made Global. Make available to other functions

Func DrawWidget()
     
    ### Global definition for workWidget

    workWidget = new qWidget()              
    {
        # Set the Window Icon
        setWindowIcon(new qIcon(new qPixmap(King)))

        aArray  = list(hSize, vSize) ### Internal Array with Letters
        aButton = list(hSize, vSize) ### Internal Array with Letters
        recordArray = list(1, 2) ### Record the Moves ...  WN 8-7  to  6-6
        
        setWindowTitle('Checkers 2 Players')
        setStyleSheet('background-color:White')

        workHeight = workWidget.height()
        fontSize   = 8 + (workHeight / 100)
        
        resize(sizeX, sizeY)
     

        ###----------------------------------------------
        ### Title Top Row - Moves Count
            
                            
            TitletMoves = new qLineEdit(workWidget) 
            {
                #setStyleSheet(C_ButtonDarkStyle)   ### Leave White default
                setFont(new qFont("Calibri",fontsize,100,0))
                setAlignment( Qt_AlignVCenter)
                setAlignment( Qt_AlignVCenter)
                setText(" Moves: "+ nMoves)
            }   

            TitletInvalidMove = new qLineEdit(workWidget) 
            {
                setStyleSheet(C_ButtonDarkStyle)
                setFont(new qFont("Calibri",fontsize,100,0))
                setAlignment( Qt_AlignVCenter)
                setAlignment( Qt_AlignVCenter)
                setText(" Black ")
            }       
    
            ###-------------------------------------------------------- 
            ### Combo Box for Puzzles
            ### patternType = comboPatternType.currentText()

            
            comboPuzzleName = new QComboBox(workWidget) 
            {
                setStyleSheet("background-color:White")
                setFont(new qFont("Calibri",fontsize,50,0))
                #aList = ["BoardLayout","Puzzle1","Puzzle2","Puzzle3"]
                aList = PuzzleList                  ### From CheckerPuzzles.ring file
                for x in aList additem(x,0) next                
            }   
                    
        
            NewGame  = new QPushButton(workWidget) 
            {
                setStyleSheet("background-color:rgb(255,204,229)")
                setFont(new qFont("Calibri",fontsize,100,0))
                setText(" New Game ")
                setClickEvent("NewGameStart()")   
            }               

        ###------------------------------------------------

        ###-----------------------------------------------------------------------
        ### QVBoxLayout lays out widgets in a vertical column, from top to bottom.
        
        ### Vertical
        LayoutButtonMain = new QVBoxLayout()                
        
        LayoutButtonMain.setSpacing(C_Spacing)
        LayoutButtonMain.setContentsMargins(5,5,5,5)
        

        ### Horizontal - TOP ROW
            LayoutTitleRow = new QHBoxLayout()              
            {
                setSpacing(C_Spacing)
                setContentsMargins(0,0,0,0)
            }
                
            
            LayoutTitleRow.AddWidget(TitletMoves)
            LayoutTitleRow.AddWidget(TitletInvalidMove) 
            LayoutTitleRow.AddWidget(comboPuzzleName)           
            LayoutTitleRow.AddWidget(NewGame)       
                                
            LayoutButtonMain.AddLayout(LayoutTitleRow)      
            
        ###----------------------------------------------
        ### BUTTON ROWS

        LayoutButtonRow = list(hSize)   
        
        ###---------------------------------------------------------------------
        ### QHBoxLayout lays out widgets in a horizontal row, from left to right        
        
        odd = 1
        for Row = 3 to hSize -2
                    
            LayoutButtonRow[Row] = new QHBoxLayout()    ### Horizontal
            {
                setSpacing(C_Spacing)
                setContentsmargins(0,0,0,0)
            }
           
           
            for Col = 3 to vSize -2
           
                ###-------------------
                ### Create Buttons

                    aButton[Row][Col] = new QPushButton(workWidget)     
                    {
                        if odd % 2
                            setStyleSheet(C_ButtonFirstStyle)
                            odd++
                        else
                            setStyleSheet(C_ButtonSecondStyle)
                            odd++
                        ok
                        setClickEvent("UserLeftClick(" + string(Row) +
                                 "," + string(Col) + ")")   
                        setSizePolicy(1,1)   
						setMinimumWidth(C_ButtonMinWidth)
						setMinimumHeight(C_ButtonMinHeight)							                               
                    }
                    
                ### Widget - Add Horizontal Button
                    LayoutButtonRow[Row].AddWidget(aButton[Row][Col])   
            next
            odd++

           ### Layout - Add ROW of BUTTONS             
                LayoutButtonMain.AddLayout(LayoutButtonRow[Row])            
        next
        
        ###-------------------------------------------------
            
            
        setLayout(LayoutButtonMain)
        
        for h = 1 to hSize
            for v = 1 to vSize
                    ### e - empty Visible Squares  3--10
                    aArray[h][v] = "ee" 
                    
                if h < 3 OR h > 10 or V < 3 or V > 10
                        ### "." - dot InVisible Squares  1-2,  3--10,  11-12
                        aArray[h][v] = '.'          
                ok
            next
        next


        DrawPieces(puzzleName)
    
        show()
    }

return

###============================================================


###============================================================
### DrawImage( "BK", Row , Col )    PieceName = "BK" etc
###
###         Who = Find(aLookup, aArray[h][v], 1)    ### Find Key: field 1
###         if  Who != 0                            ### There is a Piece on the Internal Array
###             DrawImage( aLookup[Who][2], h, v )  ### Find Value: field 2
###         ok
###       

Func DrawImage( PieceName, Row,  Col  )
    
    Who = Find(aLookup, PieceName, 1)
    if Who != 0 
    {
        PieceImage = aLookup[Who][2]
        
        aButton[Row][Col] { 
                            oPiece = new qpixmap(PieceImage)    ### Piece is a aPixMap
                            nImageWidth  = oPiece.Width()       ### Piece, not Square    
                            nImageHeight = oPiece.Height()      ### Piece, not Square   
                            oPiece = oPiece.scaled(nImageWidth , nImageHeight ,0,0) 
                            setIcon(new qIcon(oPiece)) 
                            setIconSize(new qSize(C_ButtonImageWidth , C_ButtonImageHeight ))
                          }     
    }
    
return


###----------------------------------------------------------
###  DrawPieces( BoardLayout )
### "BoardLayout","Puzzle1","Puzzle2","Puzzle3"
###  ChessPuzzles.ring has Code and Puzzles

Func DrawPieces(puzzleName)

    #Board = BoardLayout                     ### Default 
     Board = WhichPuzzle(puzzleName)         ### From ChessPuzzle.ring file
    
    #See "DrawPieces: "+ See puzzleName See nl 

    ### Empty out Internal Array -- 
    for h = 1 to hSize
        for v = 1 to vSize
            aArray[h][v] = "ee" ### e - empty
        next
    next
    
    ### Internal aArray -- looks like BoardLayout of Pieces
    for h = 3 to hSize -2
        for v = 3 to vSize -2
            aArray[h][v] = Board[h-2][v-2]
        next
    next

    ### Draw Pieces -- based on Internal Array, but not Empty
    for h = 3 to hSize -2
        for v = 3 to vSize -2   
            PieceName = aArray[h][v]
            DrawImage( PieceName, h, v )
        next
    next
    

Return

###------------------------------------------------------------
### Print Board Pieces
### Draw Pieces -- based on Internal Array, but not Empty

Func PrintBoardPieces()

    See nl+nl
    for h = 3 to hSize -2
        for v = 3 to vSize -2       
            See "  "+ aArray[h][v]
        next
        See nl
    next
return
###============================================================

###-----------------------------------------------------------
### NewGameStart 
### Layout = Board, Puzzles

Func NewGameStart()

    puzzleName = comboPuzzleName.currentText()
    See "NewGame: puzzleName: "+ puzzleName +nl
    
    workWidget.Close()

    hSize = 8 + 2 + 2   
    vSize = 8 + 2 + 2 
        
    for h = 1 to hSize
        for v = 1 to vSize
            aArray[h][v] = "ee" ### e - empty
        next
    next
        
    DrawWidget()                ### ===>>>  ReDraw the Board with stating layout
    
    TurnColor     = "Black"     ### "Black", White
    FlagStartMove =  0
    nMoves        =  0
    
    TitletMoves.setText(" Move: "+ nMoves )
    
return


###-----------------------------------------------
### USER CLICK 
### Get User - Cell Clicked - Horz-Vert

Func UserLeftClick(Row, Col)    


    Row = 0+ Row      ### Convert to number
    Col = 0+ Col
    H   = Row
    V   = Col
    
    
        ###----------------------------------------------------------------------
        ### NEW PICK - Yellow FROM-SQ, Restore Old DEST-SQ Color
        ### Do it for NEW COLOR Move
        
        TitletMoves.setText(" FlagStartMove: "+ FlagStartMove  )    ### SRC or DEST Move indicator
        
        RestoreSquareColor(OldRow, OldCol)                          ### Clear old Dest-Square
        aButton[Row][Col] { setStyleSheet(C_ButtonPickStyle) }      ### Yellow Highlight the  From-Square
        
        OldRow = Row                                                ### Save Current as OLD Square
        OldCol = Col
    
       
Play(Row,Col)

return


###==============================================================
### CheckJumpMove by Selected Piece  0=BAD  1-Good selection
### User MUST Jump. Did he select a Proper Piece FROM-SQ
    
Func CheckJumpMove(Piece, Row, Col)
    
            FlagJumpFromSQ = 0
            MustJ = 0
            MustJ = MustJump() 
            //See "0-CheckJumpMove MustJ: "+ MustJ +" "+ Piece +"-"+ Row +"-"+ Col +nl 
            
            if MustJ >= 1 AND FlagStartMove = 0  // AND PreviousMoveJump = 1                ### MORE than One Jump Possible for START MOVE
                    //See "0-MJ: "+ MustJ +" StartMove: "+ FlagStartMove  +nl
                
                    for i = 1 to len(aArrayMustJump) 
                        See "0-LIST-MJ: "+ aArrayMustJump[i] +nl
                        
                        Parts = split(aArrayMustJump[i], "|")   
                                                                    
                        TitletInvalidMove.setText( TurnColor +": Must Jump" )
                        //TitletInvalidMove { setStyleSheet("background-color:rgb(255,102,102)") }
                        
                        if Row = Parts[2] AND Col = Parts[3]
                            //See "0-Match: "+ Row +"-"+ Col +nl
                            FlagJumpFromSQ = 1
                        ok
                    
                    next    
                    
                    ### IF Selected Piece NOT of ListofJump - Pink it
            
                    if FlagJumpFromSQ = 0
                        aButton[Row][Col] { setStyleSheet(C_ButtonInvalidStyle) } 
                        RETURN  FlagJumpFromSQ 
                    ok
            
            ok
            
RETURN  True
            
###-----------------------------------------
### PLAY MOVE   
### Highlight the From-Square With Piece    
###  

Func Play(Row,Col)
       
  
    ###-----------------------------------------------------------------------
    ### Record Piece COLOR of FROM TO . Must Play FROM-Piece  TO-Empty Square
        
    PieceColorFrom = aArray[FromRow][FromCol]
    PieceColorTo   = aArray[Row][Col]
    
                
    ###==================================================
    ##===================================================
    ### FIRST MOVE - PICK Valid Piece,  NOT Empty Square 
    ### Valid piece = "B" or "W". 
    
if FlagStartMove = 0
            
            PickedPiece = aArray[Row][Col] 
            See nl+"0-StartMove: "+ FlagStartMove +" Piece-FR: "+ PickedPiece +"-"+ Row +"-"+ Col +nl
        
            ###----------------------------------------------
            ### Start Move is EMPTY Button. IGNORE - RETURN
            
            if PieceColorTo[1] = "e"
                aButton[Row][Col] { setStyleSheet(C_ButtonInvalidStyle) }
                RETURN  
            ok
        
            ###-----------------------------------------------------
            ### Enforce WHOSE TURN: Use IgnoreTurnColor = True to Debug
                
            if TurnColor[1] != PickedPiece[1]                               ### "White" != "BK" 
                aButton[Row][Col] { setStyleSheet(C_ButtonInvalidStyle) }   ###  NOT Your Turn
                RETURN
            ok      
            
            ###------------------------------------------------------------------
            ### StartMove = 0 Check if MUST JUMP move to be made. FlagJumpFromSQ
            ### User MUST Jump. Did he select a Proper Piece FROM-SQ
            
            FlagSelectedJumpFromSQ = CheckJumpMove(PickedPiece, Row, Col)
            
            if FlagSelectedJumpFromSQ = 0
                //See "0-BAD-SelectedJumpFromSQ: "+ FlagSelectedJumpFromSQ  +" "+ PickedPiece +"-"+ Row +"-"+ Col   +nl
                RETURN
                
            else
                //See "0-GOOD-SelectedJumpFromSQ: "+ FlagSelectedJumpFromSQ  +" "+ PickedPiece +"-"+ Row +"-"+ Col   +nl

            ok  
          
            ###-----------------------------------------------------------
            ### FlagStartMove =1 Taken.  SECOND MOVE is Next. RECORD Move
            
            FlagStartMove = 1                                               
            FromRow = Row
            FromCol = Col
        
            RETURN 
ok
        
        
            ###=====================================
            ###=====================================
            ### SECOND MOVE
    
            ###--------------------------------------------------------------- 
            ### SAME COLOR PIECE on First and Second Move
            ### CHANGED MIND by Player the FROM-Piece-Color = To-Piece-Color

if FlagStartMove = 1
            
            ###-----------------------------------------------------------------------
            ### CHANGED MIND - User selected First "BP-8-7"... then Second "BP-8-5"
            
        if   PieceColorFrom[1] = PieceColorTo[1]                            
        
                See nl+"1-StartMove: "+ FlagStartMove +" Piece-FR: "+ PickedPiece +"-"+ Row +"-"+ Col +nl
                
                PickedPiece = aArray[Row][Col]      
                aButton[Row][Col] { setStyleSheet(C_ButtonPickStyle) }      ### Yellow the FROM-SQUARE  
                RestoreSquareColor(FromRow, FromCol)                        ### Changed Mind - FROM SQUARE - Un-Yellow
                            
                FromRow = Row                                               ### New FROM PickedPiece Coordinate
                FromCol = Col
                                
                FlagStartMove = 1                                           ### SECOND MOVE is Next
                
                RETURN
        ok  
    
            ###-------------------------------------------------------------
            ### SECOND - Piece MOVED to EMPTY SQUARE - for Piece Picked 
            ### FlagStartMove = 1
        
        if aArray[Row][Col] = "ee" ### EMPTY
     
                    aButton[Row][Col] { setStyleSheet(C_ButtonDestStyle) }          ### Cyan Highlight the TO-Square
            
                    ###----------------------------------------------------------
                    ### FLAG - Valid Move, Jump, Crown for Piece Picked, True =1

                    ValidM = 0 ValidJ = 0 CrownP = 0  
                    

                    ValidM = ValidMove( PickedPiece, FromRow, FromCol, Row, Col)      
                    ValidJ = ValidJump( PickedPiece, FromRow, FromCol, Row, Col)      
                    CrownP = PromotePawn(PickedPiece, FromRow, FromCol, Row, Col)     
                    
                    
                        ###---------------------------------------------------------
                        ### NOT VALID - FALSE=0 Move or Jump.  MSG and Color restore 
                    if ValidM = 0 AND ValidJ = 0
                    
                        FlagStartMove = 0           
                        RestoreSquareColor(FromRow, FromCol)            ### Clear From-Square

                        //TitletInvalidMove.setText( TurnColor +": Invalid Move to Square" )
                        //TitletInvalidMove { setStyleSheet("background-color:rgb(255,102,102)") }    
                        aButton[Row][Col] { setStyleSheet(C_ButtonInvalidStyle) }   ### Invalid Move            
                                    
                        RETURN
                        
                        ###---------------------------
                        ### VALID - TRUE=1 MOVE OR JUMP
                    else         
                        TitletInvalidMove.setText(" Msg: Valid Move Jump ")
                        TitletInvalidMove { setStyleSheet(C_ButtonDestStyle)}  ### OK - Pale color
                    ok
                        

                        ###-------------------
                        ### PAWN was CROWNED ?
                    if CrownP = 0                                       ### 0 - NOT a Crowning move 
                        aArray[Row][Col] = aArray[FromRow][FromCol]     ### Move Piece from Old to New Square
                        PieceName = aArray[Row][Col]
                        DrawImage( PieceName, Row, Col )
                    ok 
                        
                        
                        
                        ###-----------------------------------------
                        ### Copy Internal Piece LAYOUT From-Cell to To-Cell
                        ### Color From-Square
                                  
                    ClearSquare(FromRow, FromCol)                       ### Remove Piece - From Square
                    
                        ###--------------------------------------------------------------------
                        ### Another JUMP POSSIBLE ?
                        ###     BUT NOT on a Valid SLIDE Move, that can jump on the NEXT Move
                        ###         0-StartMove: 0 Piece-FR: WP-6-9
                        ###         1-StartMove: 1 Piece-TO: WP-7-8 MJ: 1
                        
                    OldaArrayMustJump = aArrayMustJump
                    
                    MustJ = 0
                    MustJ = MustJump()  
                    See "1-StartMove: "+ FlagStartMove  +" Piece-TO: "+ PickedPiece +"-"+ Row +"-"+ Col +" MJ: "+ MustJ +nl
                    
                    ### SLIDE: IF Piece-TO was a SLIDE-TO, instead of JUMP-TO. BAD Slide instead of Jump
                                    
                    if ValidM = 1  // AND MustJ >= 0
                        See "1-StartMove: "+ FlagStartMove  +" Slide ValidM: " + ValidM +nl
                        
                        FlagGoodSlide = 0
                        
                        if len(OldaArrayMustJump) >= 1
                                for i = 1 to len(OldaArrayMustJump) 

                                    Parts = split(OldaArrayMustJump[i], "|")    
                                    //See "1-StartMove: "+ FlagStartMove +" SlideTO: "+ Row +"-"+ Col +" Jump-TO: "+ Parts[4] +"-"+ Parts[5] +nl
                                    
                                    if Row = Parts[4] AND Col = Parts[5]                        
                                        FlagGoodSlide = 1
                                    ok
                                next
                                
                                if FlagGoodSlide = 0
                                    See "1-StartMove: "+ FlagStartMove +" BAD SlideTO: "+ Row +"-"+ Col +" MUST Jump-TO: "+ Parts[4] +"-"+ Parts[5] +nl
                                    ClearSquare(Row, Col)                                       ### Remove Piece - From Square
                                    aButton[Row][Col] { setStyleSheet(C_ButtonInvalidStyle) }   ### Invalid Move/Jump 
                                                             
                                    aArray[FromRow][FromCol] = PickedPiece
                                    DrawImage(PickedPiece, FromRow, FromCol)
                                    PrintBoardPieces()
                                    
                                    TitletInvalidMove.setText( PickedPiece +": Must Jump" )
                                    TitletInvalidMove { setStyleSheet(C_ButtonInvalidStyle)}  ### OK - Pale color
                                
                                    FlagStartMove = 1       ### AGAIN - MUST-JUMP
                                    RETURN
                                ok
                        ok
                        
                    else
                        
                        if MustJ >= 1 AND FlagStartMove = 1                 ### MORE than One Jump Possible
                            
                            FromRow = Row                                   ### New FROM PickedPiece Coordinate
                            FromCol = Col
                                if PickedPiece[1] = "B"  TurnColor = "Black"  else  TurnColor = "White"  ok
                                
                                TitletInvalidMove.setText( TurnColor +": More Jump ")
                                TitletInvalidMove { setStyleSheet("background-color:rgb(255,255,204)")}  ### OK - Pale color
                                aButton[Row][Col] { setStyleSheet(C_ButtonPickStyle) }      ### Yellow the FROM-SQUARE  
                                
                            FlagStartMove = 1       ### AGAIN - MUST-JUMP
                            PreviousMoveJump = 1
                            RETURN
                        ok                              
                        
                    ok
                    
                    
                    FlagStartMove = 0 
                    WhoseTurn(PickedPiece)
                    RecordNewMove(PickedPiece, FromRow, FromCol, Row, Col)


            ### Check if MORE Jumps = CALL SELF
            ### UserLeftClick(Row, Col)         
                        
        else
            ### NOT Empty TO-SQ
            ### from if: aArray[Row][Col] = "ee" ### Empty
            
            FlagStartMove = 0           
            RestoreSquareColor(FromRow, FromCol)                ### Clear From-Square

            //TitletInvalidMove.setText( TurnColor +" Invalid Move/Jump to Square" )
            //TitletInvalidMove { setStyleSheet("background-color:rgb(255,102,102)") }    
            aButton[Row][Col] { setStyleSheet(C_ButtonInvalidStyle) }   ### Invalid Move/Jump    
            
        ok
ok

return  

###=========================================================
### RESTORE SQUARE Color - Remove Yellow Highlight Select

Func RestoreSquareColor(FromRow, FromCol)

    #See"FuncRestoreSquareColor: "+ FromRow +"-"+ FromCol +nl

            if (FromRow + FromCol ) % 2
                aButton[FromRow][FromCol] { setStyleSheet(C_ButtonSecondStyle) }
            else
                aButton[FromRow][FromCol] { setStyleSheet(C_ButtonFirstStyle) }
            ok
    
    
return

###-------------------------------------------------------
### RESTORE All SQUAREs Color - Remove Yellow Highlight Select

Func RestoreAllSquareColor(FromRow, FromCol)

    #See"FuncRestoreSquareColor: "+ FromRow +"-"+ FromCol +nl

    for FromCol = 3 to 10
        for FromRow = 3 to 10
            if (FromRow + FromCol ) % 2
                aButton[FromRow][FromCol] { setStyleSheet(C_ButtonSecondStyle) }
            else
                aButton[FromRow][FromCol] { setStyleSheet(C_ButtonFirstStyle) }
            ok
        next
    next
    
return


###------------------------------------------------
### CLEAR SQUARE - Remove Piece from - From-Square  

Func ClearSquare(FromRow, FromCol)

    #See"FuncClearSquare: "+ FromRow +"-"+ FromCol +nl

    aArray[FromRow][FromCol] = "ee"                             ### Empty From-Cell
    
    ### Restore From-Square Solid Color
    if (FromRow + FromCol ) % 2
        aButton[FromRow][FromCol] {     
            oMine = new qpixmap2(0,0)
            setIcon(new qIcon(oMine))
            setStyleSheet(C_ButtonSecondStyle)  
        }       
    else
        aButton[FromRow][FromCol] {     
            oMine = new qpixmap2(0,0)
            setIcon(new qIcon(oMine))
            setStyleSheet(C_ButtonFirstStyle)   
        }
    ok      
            
return

###----------------------------------------------------------
### Whose Turn To Play Next. PickedPiece was the Last Played

Func WhoseTurn(PickedPiece)

    if PickedPiece[1] = "W"
        TurnColor = "Black"
        TitletInvalidMove { setStyleSheet(C_ButtonDarkStyle)}
    else
        TurnColor = "White"
        TitletInvalidMove { setStyleSheet(C_ButtonPaleStyle)}
    ok
    
    TitletInvalidMove.setText(TurnColor)
return          

###------------------------------------------
### Increase Moves Counter. Record Move

Func RecordNewMove(PickedPiece, FromRow, FromCol, Row, Col)
  //nMoves++
  //return

    nMoves++            
    FR = FromRow-2  FC = FromCol-2
    TR = Row-2      TC = Col-2
    TitletMoves.setText(" Move: "+ nMoves +" : "+ PickedPiece  +" "+ FR +"-"+ FC +" >> "+ TR +"-"+ TC )
    
    #Details = ""+ nMoves +" "+ PickedPiece +" "+ FR +" "+ FC +" "+ TR +" "+ TC
     Details = ""+ nMoves +" "+ PickedPiece +" "+ FromRow +" "+ FromCol +" "+ Row +" "+ Col
    
    Add( recordArray, Details)
    See nl+nl  See recordArray  See nl+nl
    
return

###==========================================
###==========================================
        
###------------------------------------------
### VALID MOVE for ALL PIECES
###  Col 
#    1   1 2                      11 12
#    2   1 2 -------------------- 11 12
#    3   1 2 | - 4 - 6 - 8 - 10 | 11 12 => Row
#    4   1 2 | 3 - 5 - 7 - 9 -  | 11 12
#    5   1 2 | - 4 - 6 - 8 - 10 | 11 12
#    6   1 2 | 3 - 5 - 7 - 9 -  | 11 12
#    7   1 2 | - 4 - 6 - 8 - 10 | 11 12
#    8   1 2 | 3 - 5 - 7 - 9 -  | 11 12
#    9   1 2 | - 4 - 6 - 8 - 10 | 11 12
#    10  1 2 | 3 - 5 - 7 - 9 -  | 11 12
#    11  1 2 -------------------- 11 12
#    12  1 2                      11 12
#
#    Direction-Col-Row  -V  +^   -V+ +^  -V /=^
#    Piece              BP  WP    BK     WK
#-------------------------------------------
#

Func ValidMove( Piece, oldH, oldV, h, v)

    #SEE "Func ValidMove: "+ Piece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl

    FlagValidMove = 0   
    if       
            Piece = "BK"  result = ValidMoveBK( Piece, oldH, oldV, h, v) 
        but Piece = "BP"  result = ValidMoveBP( Piece, oldH, oldV, h, v)
        but Piece = "WK"  result = ValidMoveWK( Piece, oldH, oldV, h, v) 
        but Piece = "WP"  result = ValidMoveWP( Piece, oldH, oldV, h, v)
        
        else See "Switch-Case: Failed: " Piece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl
    ok  
    FlagValidMove = result
    
return FlagValidMove

###================================================
###================================================
###================================================

### VALID JUMPS for ALL Pieces

Func ValidJump( Piece, oldH, oldV, h, v)

    #SEE "Func ValidMove: "+ Piece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl

    FlagValidJump = 0   
    if       
            Piece = "BK"  result = ValidJumpBK( Piece, oldH, oldV, h, v) 
        but Piece = "BP"  result = ValidJumpBP( Piece, oldH, oldV, h, v)
        but Piece = "WK"  result = ValidJumpWK( Piece, oldH, oldV, h, v) 
        but Piece = "WP"  result = ValidJumpWP( Piece, oldH, oldV, h, v)
        
        else See "Switch-Case: Failed: " Piece +" "+ oldH +"-"+ oldV +" "+ h +"-"+ v +nl
    ok  
    FlagValidJump = result
    
return FlagValidJump

###-----------------------------------------------


###================================================
###================================================
###================================================
### VALID MOVE BY PIECES
###------------------------------------------------

###--------------------------------------------
### BlackPawn

Func ValidMoveBP(Piece, oldH, oldV, h, v)

    FlagValidMove = 0
    PossibleMove  = [[-1,-1],[-1,1]] 
        
    for i = 1 to 2
        if( h = oldH + PossibleMove[i][1]) AND (v = oldV + PossibleMove[i][2] )
            
            SquareTo = aArray[h][v] 
            #See "SquareTo: "+ SquareTo +" hv:"+ h +"-"+ v +nl
            
            if SquareTo[1] = "e"   ### Empty Piece on square 
                FlagValidMove = 1
                exit
            ok
        ok
    next
    
return FlagValidMove

###--------------------------------------------
### WhitePawn


Func ValidMoveWP(Piece, oldH, oldV, h, v)

    FlagValidMove = 0
    PossibleMove  = [[1,-1],[1,1]] 
        
    for i = 1 to 2
        if ( h = oldH + PossibleMove[i][1]   AND v = oldV + PossibleMove[i][2] )
            
            SquareTo = aArray[h][v] 
            
            if SquareTo[1] = "e"   ### Empty Piece on square 
                FlagValidMove = 1
                exit
            ok
        ok
    next
    
return FlagValidMove

###--------------------------------------------
###--------------------------------------------
### BlackKing


Func ValidMoveBK(Piece, oldH, oldV, h, v)

    FlagValidMove = 0
    PossibleMove  = [[-1,-1],[-1,1],[1,-1],[1,1]] 
        
    for i = 1 to 4
        if ( h = oldH + PossibleMove[i][1] AND v = oldV + PossibleMove[i][2] )
            
            SquareTo = aArray[h][v] 
            
            if SquareTo[1] = "e"   ### Empty Piece on square 
                FlagValidMove = 1
                exit
            ok
        ok
    next
    
return FlagValidMove

###--------------------------------------------
###--------------------------------------------
### WhiteKing


Func ValidMoveWK(Piece, oldH, oldV, h, v)

    FlagValidMove = 0
    PossibleMove  = [[-1,-1],[-1,1],[1,-1],[1,1]] 
        
    for i = 1 to 4
        if ( h = oldH + PossibleMove[i][1] AND v = oldV + PossibleMove[i][2] )
            
            SquareTo = aArray[h][v] 
            
            if SquareTo[1] = "e"   ### Empty Piece on square 
                FlagValidMove = 1
                exit
            ok
        ok
    next
    
return FlagValidMove

###--------------------------------------------

###================================================
###================================================
###================================================
### VALID JUMPS BY PIECES
###------------------------------------------------

###--------------------------------------------
### BlackPawn


Func ValidJumpBP(Piece, oldH, oldV, h, v)

    wh = 0  wv = 0
    FlagValidJump = 0
    PossibleJump  = [[-2,-2],[-2,2]] 
    ColorPieceOn  = [[-1,-1],[-1,1]]
        
    for i = 1 to 2
        if( h = oldH + PossibleJump[i][1]) AND (v = oldV + PossibleJump[i][2] )
            
            wh = oldH + ColorPieceOn[i][1]  ### Next Square
            wv = oldV + ColorPieceOn[i][2]
            
            PieceColor = aArray[wh][wv]     ### White Piece
            SquareTo   = aArray[h][v]       ### Must be Empty for Jump to land
            
            ### White Piece on square between Jump. Land on Empty Square
            if PieceColor[1] = "W" AND SquareTo[1] = "e"       
                
                aArray[wh][wv] = "ee"
                ClearSquare(wh, wv)
                FlagValidJump = 1
                exit
            ok
        ok
    next
    
return FlagValidJump

###--------------------------------------------
### WhitePawn


Func ValidJumpWP(Piece, oldH, oldV, h, v)

    FlagValidJump = 0
    PossibleJump  = [[2,-2],[2,2]] 
    ColorPieceOn  = [[1,-1],[1,1]] 
        
    for i = 1 to 2
        if ( h = oldH + PossibleJump[i][1]   AND v = oldV + PossibleJump[i][2] )
                        
            wh = oldH + ColorPieceOn[i][1] 
            wv = oldV + ColorPieceOn[i][2]
            
            PieceColor = aArray[wh][wv] 
            
            if PieceColor[1] = "B"   ### White Piece on square between jump 

                aArray[wh][wv] = "ee"
                ClearSquare(wh, wv)
                FlagValidJump = 1
                exit
            ok
        ok
    next
    
return FlagValidJump

###--------------------------------------------
###--------------------------------------------
### BlackKing


Func ValidJumpBK(Piece, oldH, oldV, h, v)

    FlagValidJump = 0
    PossibleJump  = [[-2,-2],[-2,2],[2,-2],[2,2]] 
    ColorPieceOn  = [[-1,-1],[-1,1],[1,-1],[1,1]]
        
    for i = 1 to 4
        if ( h = oldH + PossibleJump[i][1] AND v = oldV + PossibleJump[i][2] )
    
            wh = oldH + ColorPieceOn[i][1] 
            wv = oldV + ColorPieceOn[i][2]
            
            PieceColor = aArray[wh][wv] 
            
            if PieceColor[1] = "W"   ### White Piece on square between jump     
                
                aArray[wh][wv] = "ee"
                ClearSquare(wh, wv)
                FlagValidJump = 1
                exit
            ok
        ok
    next
    
return FlagValidJump

###--------------------------------------------
###--------------------------------------------
### WhiteKing


Func ValidJumpWK(Piece, oldH, oldV, h, v)

    FlagValidJump = 0
    PossibleJump  = [[-2,-2],[-2,2],[2,-2],[2,2]] 
    ColorPieceOn  = [[-1,-1],[-1,1],[1,-1],[1,1]] 
        
    for i = 1 to 4
        if ( h = oldH + PossibleJump[i][1] AND v = oldV + PossibleJump[i][2] )
            
    
            wh = oldH + ColorPieceOn[i][1] 
            wv = oldV + ColorPieceOn[i][2]
            
            PieceColor = aArray[wh][wv] 
            
            if PieceColor[1] = "B"   ### White Piece on square between jump     
                
                aArray[wh][wv] = "ee"
                ClearSquare(wh, wv)
                FlagValidJump = 1
                exit
            ok
        ok
    next
    
return FlagValidJump

###--------------------------------------------
###--------------------------------------------
### Promote Pawn if on Other Side BP v=10
### Turn Pawn into KING
### Update Array and Image on Board
        
Func PromotePawn(Piece, oldH, oldV, h, v)
        
        CrownP = 0
        
        if h = 3 AND Piece = "BP"
            aArray[h][v] = "BK"                
            PieceName = aArray[h][v]
            DrawImage( PieceName, h, v )     
            CrownP = "1"
        ok
    
        if h = 10 AND Piece = "WP"
            aArray[h][v] = "WK"                
            PieceName = aArray[h][v]
            DrawImage( PieceName, h, v )      
            CrownP = "1"
        ok
   
return CrownP

###================================================
###================================================
###================================================

###=================================================
### MUST JUMP - check for jumps of TurnColor
### aArrayMustJump is LIST Piece,hFrom,vFrom,hTo,vTo 

Func MustJump()

    FlagMustJump = 0
    aArrayMustJump  = []
    
    for h = 3 to 10
        for v = 3 to 10
        
            Piece = aArray[h][v]    ### Each Piece on Each Square
            
            if TurnColor = "Black"
            
                if Piece = "BP"     FlagMustJump = MustJumpBP( Piece, h, v)     ok              
                if Piece = "BK"     FlagMustJump = MustJumpBK( Piece, h, v)     ok 
            else
                if Piece = "WP"     FlagMustJump = MustJumpWP( Piece, h, v)     ok              
                if Piece = "WK"     FlagMustJump = MustJumpWK( Piece, h, v)     ok 
            ok
        next
    next

    

return  FlagMustJump

###===============================

Func MustJumpBP(Piece, h, v)

    //FlagMustJump = 0
    PossibleJump  = [[-2,-2],[-2,2]] 
    ColorPieceOn  = [[-1,-1],[-1,1]]
        
    for i = 1 to 2
            hNew = h + PossibleJump[i][1]       ### Dest. square
            vNew = v + PossibleJump[i][2]            
            wh   = h + ColorPieceOn[i][1]       ### Next Square
            wv   = v + ColorPieceOn[i][2]
            
            PieceColor = aArray[wh][wv]         ### White Piece
            SquareTo   = aArray[hNew][vNew]     ### Must be Empty for Jump to land
            
           
            ### White Piece on square between Jump. Land on Empty Square
            
            if (hNew < 3 OR hNew > 10 OR vNew < 3 OR vNew > 10)
                #See "OutofBounds: MJ-BP: "+ PieceColor +" Old:"+ h +"-"+ v +" wh:"+ wh +"-"+ wv +" New:"+ hNew +"-"+ vNew +nl          
            else            
                if  (  PieceColor[1] = "W" AND SquareTo[1] = "e"   AND (hNew != 2 OR hNew != 11 OR vNew != 2 OR vNew != 11) )   
                        FlagMustJump++
                        Add( aArrayMustJump, Piece +"|"+ h +"|"+ v +"|"+ hNew +"|"+ vNew)                      
                ok
            ok
        
    next
    
return FlagMustJump

###===============================
Func MustJumpWP(Piece, h, v)


    //FlagMustJump = 0
    PossibleJump  = [[2,-2],[2,2]] 
    ColorPieceOn  = [[1,-1],[1,1]] 
        
    for i = 1 to 2
            hNew = h + PossibleJump[i][1] 
            vNew = v + PossibleJump[i][2]            
            wh   = h + ColorPieceOn[i][1]       ### Next Square
            wv   = v + ColorPieceOn[i][2]
            
            PieceColor = aArray[wh][wv]         ### Black Piece
            SquareTo   = aArray[hNew][vNew]     ### Must be Empty for Jump to land
            
           
            ### White Piece on square between Jump. Land on Empty Square
            
            if (hNew < 3 OR hNew > 10 OR vNew < 3 OR vNew > 10)
                #See "OutofBounds: MJ-WP: "+ PieceColor +" Old:"+ h +"-"+ v +" wh:"+ wh +"-"+ wv +" New:"+ hNew +"-"+ vNew +nl          
            else            
                if  ( PieceColor[1] = "B" AND SquareTo[1] = "e"  AND (hNew != 2 OR hNew != 11 OR vNew != 2 OR vNew != 11) )         
                        FlagMustJump++
                        Add( aArrayMustJump, Piece +"|"+ h +"|"+ v +"|"+ hNew +"|"+ vNew)
                ok
            ok 
            
    next
    
return  FlagMustJump

###===============================
Func MustJumpBK(Piece, h, v)


    //FlagMustJump = 0
    PossibleJump  = [[-2,-2],[-2,2],[2,-2],[2,2]] 
    ColorPieceOn  = [[-1,-1],[-1,1],[1,-1],[1,1]]
        
    for i = 1 to 4
            hNew = h + PossibleJump[i][1] 
            vNew = v + PossibleJump[i][2]            
            wh   = h + ColorPieceOn[i][1]       ### Next Square
            wv   = v + ColorPieceOn[i][2]
            
            PieceColor = aArray[wh][wv]         ### White Piece
            SquareTo   = aArray[hNew][vNew]     ### Must be Empty for Jump to land
            
           
            ### White Piece on square between Jump. Land on Empty Square
            
            if (hNew < 3 OR hNew > 10 OR vNew < 3 OR vNew > 10)
                #See "OutofBounds: MJ-BK: "+ PieceColor +" Old:"+ h +"-"+ v +" wh:"+ wh +"-"+ wv +" New:"+ hNew +"-"+ vNew +nl          
            else
                if  (  PieceColor[1] = "W" AND SquareTo[1] = "e" AND (hNew != 2 OR hNew != 11 OR vNew != 2 OR vNew != 11) )         
                        FlagMustJump++
                        Add( aArrayMustJump, Piece +"|"+ h +"|"+ v +"|"+ hNew +"|"+ vNew)                     
                ok
            ok
        
    next
    
return FlagMustJump


###------------------------------------------------
Func MustJumpWK(Piece, h, v)


    //FlagMustJump = 0
    PossibleJump  = [[-2,-2],[-2,2],[2,-2],[2,2]] 
    ColorPieceOn  = [[-1,-1],[-1,1],[1,-1],[1,1]]
        
    for i = 1 to 4
            hNew = h + PossibleJump[i][1] 
            vNew = v + PossibleJump[i][2]            
            wh   = h + ColorPieceOn[i][1]       ### Next Square
            wv   = v + ColorPieceOn[i][2]
            
            PieceColor = aArray[wh][wv]         ### White Piece
            SquareTo   = aArray[hNew][vNew]     ### Must be Empty for Jump to land
            
           
            ### White Piece on square between Jump. Land on Empty Sqre

            if (hNew < 3 OR hNew > 10 OR vNew < 3 OR vNew > 10)
                #See "OutofBounds: MJ-WK: "+ PieceColor +" Old:"+ h +"-"+ v +" wh:"+ wh +"-"+ wv +" New:"+ hNew +"-"+ vNew +nl          
            else            
                if  (  PieceColor[1] = "B" AND SquareTo[1] = "e" AND (hNew != 2 OR hNew != 11 OR vNew != 2 OR vNew != 11) )         
                        FlagMustJump++
                        Add( aArrayMustJump, Piece +"|"+ h +"|"+ v +"|"+ hNew +"|"+ vNew)
                ok
            ok
        
    next
    
return FlagMustJump


###------------------------------------------------


###================================================
###------------------------------------------------
### Message Box 
    
Func MsgBox(cText) 
    mb = new qMessageBox(workWidget) 
        {
            setWindowTitle('Chess')
            setText(cText)
            setStandardButtons(QMessageBox_OK) 
            result = exec()
            See "MsgBox Result: "+ result +nl
        }
return

###--------------------------------
