### Program: Sudoku Puzzle
### Author:  Bert Mariani
###          Nestor Kuka ( "Kendrick Ledet" "Roland Yonaba") 
###                      ( "Prakash Reddy")
### Date:    2019-04-30

### http://www.paulspages.co.uk/sudoku/howtosolve/
### https://www.kristanix.com/sudokuepic/sudoku-solving-techniques.php
### https://www.youtube.com/watch?v=b123EURtu3I&feature=youtu.be
### https://www.nytimes.com/crosswords/game/sudoku/easy

load "stdlibclasses.ring"
load "lightguilib.ring"
load "SudokuPuzzles.ring"               ### A File with SUDOKU Puzzles to Solve

###----------------------------------
### CHANGE - Create to SudokuC.ring
### Change "mylib" to "mylibSudoku"
###
###     load "mylib.ring"
###         if iswindows()
###             LoadLib("mylib.dll")
###         but ismacosx()
###             LoadLib("libmylib.dylib")
###         else
###             LoadLib("libmylib.so")
###         ok
###-----------------------------------
### mylibSudoku.ring
###     if iswindows()
###         LoadLib("mylibSudoku.dll")
###     but ismacosx()
###         LoadLib("libmylibSudoku.dylib")
###     else
###         LoadLib("libmylibSudoku.so")
### ok
###------------------------------------

See  "Loading SudokuC Library: mylibSudoku.dll "+nl                     ### C-Code routine for Solver Calculations
load "mylibSudoku.ring"

See  "Loading SudokuC Library: mylibSudokuGenerator.dll "+nl        ### C-Code routine for Generator Calculations
load "mylibSudokuGenerator.ring"

###-------------------
### WINDOW SIZE

moveX  = 200 moveY  = 100       ### Open Window on Screen Position
sizeX  = 840 sizeY  = 820       ### Size of Window

hSize = 9   ### Size of array, Display -4 smaller
vSize = 9   ### Size of array, Display -4 smaller
hPos  = 0   ### Horizontal coordinate of Cell
vPos  = 0   ### Vertical coordinate of Cell


###----------------------------------------------------------
### Global so other functions can access the workWidget items

aArray           = null
playArray        = null
aButton          = null
workWidget       = null
HintsInSquare    = null

TitletMoves       = null
TitletInvalidMove = null
LayoutButtonRow   = null

comboPuzzleName  = null
comboPuzzleGen   = null


puzzleName       = "EnterYourOwn"  ### Default setup
gfontSize        = 10
gHintArray       = [0,0,0, 0,0,0, 0,0,0, 0,0]   ### last 2 are Row-Col


OldRow = 0
OldCol = 0
nMoves = 0
gNbrRightClick = 0 ### RightMouse-SelectMenu-Nbr | Start with default "0" which means "clear" "no number"
gcountIter = 0     //  iteration

aSQColor = [
    [0,0,0, 1,1,1, 0,0,0],
    [0,0,0, 1,1,1, 0,0,0],
    [0,0,0, 1,1,1, 0,0,0],

    [1,1,1, 0,0,0, 1,1,1],
    [1,1,1, 0,0,0, 1,1,1],
    [1,1,1, 0,0,0, 1,1,1],

    [0,0,0, 1,1,1, 0,0,0],
    [0,0,0, 1,1,1, 0,0,0],
    [0,0,0, 1,1,1, 0,0,0] ]

### Default initial puzzle to display
aArray =[
    [0,6,0, 0,0,0, 0,0,7],
    [1,0,7, 0,2,9, 0,0,0],
    [3,2,9, 0,0,0, 8,0,0],

    [0,0,0, 1,0,0, 2,4,0],
    [6,7,8, 0,4,0, 1,9,5],
    [0,1,2, 0,0,6, 0,0,0],

    [0,0,6, 0,0,1, 3,7,9],
    [0,0,0, 6,8,0, 4,0,2],
    [7,0,0, 0,0,0, 0,8,0] ]


playArray = aArray          ### PLAY ARRAY - Record moves etc

aButton = [
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0] ]


dupArray =  [
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0] ]

zeroArray = [
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0] ]

regionArray = [
    [1,1,1, 2,2,2, 3,3,3],
    [1,1,1, 2,2,2, 3,3,3],
    [1,1,1, 2,2,2, 3,3,3],

    [4,4,4, 5,5,5, 6,6,6],
    [4,4,4, 5,5,5, 6,6,6],
    [4,4,4, 5,5,5, 6,6,6],

    [7,7,7, 8,8,8, 9,9,9],
    [7,7,7, 8,8,8, 9,9,9],
    [7,7,7, 8,8,8, 9,9,9] ]
    
aHints = [
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0],
    [0,0,0, 0,0,0, 0,0,0] ]

###-------------------------

C_Spacing  = 2
C_ButtonFirstStyle  = 'border-radius:1px; color:black; background-color: rgb(229,249,203) ;'        ### Square pale
C_ButtonSecondStyle = 'border-radius:1px; color:black; background-color: rgb(179,200,93); '         ### Square dark

C_ButtonFirstStyleBlue  = 'border-radius:1px; color:blue; background-color: rgb(229,249,203) ;'        ### Square pale Blue Nbr
C_ButtonSecondStyleBlue = 'border-radius:1px; color:blue; background-color: rgb(179,200,93); '         ### Square dark

C_ButtonFirstStyleCyan  = 'border-radius:1px; color:darkgreen; background-color: rgb(229,249,203) ;'   ### Square pale Cyan Nbr
C_ButtonSecondStyleCyan = 'border-radius:1px; color:darkgreen; background-color: rgb(179,200,93); '    ### Square dark

C_ButtonFirstStyleRed  = 'border-radius:1px; color:red; background-color: rgb(229,249,203) ;'        ### Square pale Blue Nbr
C_ButtonSecondStyleRed = 'border-radius:1px; color:red; background-color: rgb(179,200,93); '         ### Square dark

C_ButtonPickStyle   = 'border-radius:1px; color:black; background-color: rgb(255,255,93); '         ### Yellow
C_ButtonDestStyle   = 'border-radius:1px; color:black; background-color: rgb(204,255,204); '        ### Cyan

C_ButtonPaleStyle   = 'border-radius:1px; color:black; background-color:rgb(255,255,204); '         ### Pale white turn
C_ButtonDarkStyle   = 'border-radius:1px; color:black; background-color:rgb(204,255,255); '         ### Dark black turn

C_ButtonInvalidStyle= 'border-radius:1px; color:black; background-color: rgb(255,102,102); '        ### Light Pink
                       ###'border-style: outset; border-width: 2px; border-radius: 2px; border-color: darkGray; '



###=============================================================================
###=============================================================================
### The shortest app function you ever seen !
### The DrawWidget function does what is normally in this section

app = new qApp
{

    DrawWidget()        ### Draw the Board
    NewGameStart()      ### Initialize the Values
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
        setWinIcon(self,"../icon.png")
        setWindowTitle('Sudoku')
        setStyleSheet('background-color:White')

        workHeight = workWidget.height()
        gfontSize   = 10 + (workHeight / 100)

        move(moveX, moveY)
        resize(sizeX, sizeY)

        ###----------------------------------------------
        ### Title Top Row - Moves Count

            TitletMoves = new qLineEdit(workWidget)
            {
                #setStyleSheet(C_ButtonDarkStyle)   ### Leave White default
                setFont(new qFont("Calibri",gfontSize,100,0))
                setAlignment( Qt_AlignVCenter)
                setAlignment( Qt_AlignVCenter)
                setText("Fill: "+ nMoves)

            }

            TitletInvalidMove = new qLineEdit(workWidget)
            {
                #setStyleSheet(C_ButtonInvalidStyle)
                setFont(new qFont("Calibri",gfontSize,100,0))
                setAlignment( Qt_AlignVCenter)
                setAlignment( Qt_AlignVCenter)
                setText("Msg: ")
            }

            HintsInSquare = new qcheckbox(workWidget) 
            {
                     setStyleSheet("background-color:rgb(255,204,229)")
                setFont(new qFont("Calibri",gfontSize,100,0))
                setText("HintSQ ")
            }
    

            SolveGame  = new QPushButton(workWidget)
            {
                setStyleSheet(C_ButtonDarkStyle)
                setFont(new qFont("Calibri",gfontSize,100,0))
                setText("Solve ")
                setClickEvent("Solve()")
            }

            SolveBrut  = new QPushButton(workWidget)
            {
                setStyleSheet(C_ButtonPaleStyle)
                setFont(new qFont("Calibri",gfontSize,100,0))
                setText("BrutForce ")
                setClickEvent("BrutForce()")
            }           
            
            comboPuzzleName = new QComboBox(workWidget)
            {
                setStyleSheet("background-color:White")
                setFont(new qFont("Calibri",gfontSize,50,0))
                #aList = ["BoardLayout","Puzzle1","Puzzle2","Puzzle3"]
                aList = PuzzleList                  ### From SudokuPuzzles.ring file
                for x in aList additem(x,0) next
                     //NewGameStart()
            }

                
                    LoadGame  = new QPushButton(workWidget)
                    {
                         setStyleSheet(C_ButtonPickStyle)
                         setFont(new qFont("Calibri",gfontSize,100,0))
                         setText("Load ")
                         setClickEvent("LoadPuzzle()")
                    }

                
            comboPuzzleGen = new QComboBox(workWidget)
            {
                setStyleSheet("background-color:White")
                setFont(new qFont("Calibri",gfontSize,50,0))
                aListDifficulty = ["GenPuzzle","Beginner","Easy","Medium","Hard","Extreme"]
                for x in aListDifficulty additem(x,0) next
            }
                
                    LoadGenerator  = new QPushButton(workWidget)
                    {
                         setStyleSheet(C_ButtonPickStyle)
                         setFont(new qFont("Calibri",gfontSize,100,0))
                         setText("Gen ")
                         setClickEvent("GenPuzzle()")
                    }               

            NewGame  = new QPushButton(workWidget)
            {
                setStyleSheet("background-color:rgb(255,204,229)")
                setFont(new qFont("Calibri",gfontSize,100,0))
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
            LayoutTitleRow.AddWidget(HintsInSquare)
            LayoutTitleRow.AddWidget(SolveGame)
            LayoutTitleRow.AddWidget(SolveBrut)
            LayoutTitleRow.AddWidget(comboPuzzleName)
                LayoutTitleRow.AddWidget(LoadGame)
                LayoutTitleRow.AddWidget(comboPuzzleGen)
                LayoutTitleRow.AddWidget(LoadGenerator)
            LayoutTitleRow.AddWidget(NewGame)

            LayoutButtonMain.AddLayout(LayoutTitleRow)

        ###----------------------------------------------
        ### BUTTON ROWS

        LayoutButtonRow = list(hSize)

        ###---------------------------------------------------------------------
        ### QHBoxLayout lays out widgets in a horizontal row, from left to right

        for Row = 1 to hSize
            LayoutButtonRow[Row] = new QHBoxLayout()    ### Horizontal
            {
                setSpacing(C_Spacing)
                setContentsmargins(0,0,0,0)
            }

            for Col = 1 to vSize
                ###-------------------
                ### Create Buttons

                    aButton[Row][Col] = new QPushButton(workWidget)
                    {
                        value = aSQColor[Row][Col]
                        if value = 1
                            setStyleSheet(C_ButtonFirstStyle)
                        but value = 0
                            setStyleSheet(C_ButtonSecondStyle)
                        else
                            setStyleSheet(C_ButtonInvalidStyle)
                        ok

                        setFont(new qFont("Calibri",gfontSize + 10, 100,0))
                        setClickEvent("UserLeftClick(" + string(Row) + "," + string(Col) + ")")
                        setSizePolicy(1,1)          ### Keep SQ size and nbr text proportionate

                            ###-------------------------------------------------
                            ### For Right Mouse Click - does NOT show depression
                            myfilter = new qAllEvents(workWidget)
                            {
                                setContextMenuEvent( "RightClickMouse(" + string(Row) + "," + string(Col) + ")")  ### RIGHT CLICK CELL ===>>>>
                            }
                            installeventfilter(myfilter)
                    }

                ### Widget - Add HORIZONTAL BUTTON
                    LayoutButtonRow[Row].AddWidget(aButton[Row][Col])

            next


           ### Layout - Add ROW of BUTTONS
           LayoutButtonMain.AddLayout(LayoutButtonRow[Row])

        next

        ###-------------------------------------------------

        setLayout(LayoutButtonMain)

        show()
    }

return

###============================================================
#
###============================================================
###

Func RestoreSQColors()

    for Row = 1 to 9
        for Col = 1 to 9

            value = aSQColor[Row][Col]

            value = aSQColor[Row][Col]
            if value = 1

                    if aArray[Row][Col] = 0 AND playArray[Row][Col] >= 1            ### Played Nbr BLUE
                        aButton[Row][Col] {setStyleSheet(C_ButtonFirstStyleBlue)}
                    else
                        aButton[Row][Col] {setStyleSheet(C_ButtonFirstStyle)}       ### Orig   Nbr BLACK
                    ok

            but value = 0

                    if aArray[Row][Col] = 0 AND playArray[Row][Col] >= 1
                        aButton[Row][Col] {setStyleSheet(C_ButtonSecondStyleBlue)}
                    else
                        aButton[Row][Col] {setStyleSheet(C_ButtonSecondStyle)}
                    ok

            else
                aButton[Row][Col] {setStyleSheet(C_ButtonInvalidStyle)}
            ok

        next
    next

return

###============================================================
###

Func LoadPuzzle()

    ###--------------------------------------------------------
   ### Check User selected which puzzle on the Drop-Down List
    

     puzzleName = comboPuzzleName.currentText() ### <<<=== From DropDown ComboBox
    See "NewGame: puzzleName: "+ puzzleName +nl

    playArray = zeroArray                           ### Clear previous play
    playArray = WhichPuzzle(puzzleName)             ### <<<=== From SudokuPuzzle.ring file
    aArray    = playArray
    
    aHints    = zeroArray
	
	CountSQFilled()
    NewGameStart()
     
return

###============================================================
###

Func GenPuzzle()
    
    ###--------------------------------------------------------
    ### Check User selected which GEN-Puzzle  Level on the Drop-Down List
    ###       aListDifficulty = ["GenPuzzle","Beginner","Easy","Medium","Hard","Extreme"]
    ###
    // Difficulty levels would vary from number of filled in squares
    //  - 17 Extreme
    //  - 26 Hard
    //  - 33 Newspaper level
    //  - 40 Easy
    //  - 50 Beginner    
     
     
     Level = 1
     difficulty = comboPuzzleGen.currentText()  ### <<<=== From DropDown ComboBox
         
     if     difficulty = "GenPuzzle"  Level = 3 
        but difficulty = "Beginner"   Level = 1  
        but difficulty = "Easy"       Level = 2 
        but difficulty = "Medium"     Level = 3 
        but difficulty = "Hard"       Level = 4 
        but difficulty = "Extreme"    Level = 5 
     ok 

       See "NewGame: GENERATOR puzzleName: Level: "+ Level +nl   
    
    sudoku = CreateTable(9,9,Level)                 ##>>> CALL C-Code with Row-Col Size and Level 2-EASY
    
        See "Generated Puzzle: "+nl  See ShowArray(sudoku)  See nl

    playArray = sudoku                              ### Use Generated Puzzle  
    aArray    = playArray  
    aHints    = zeroArray
	
	CountSQFilled()
    NewGameStart()
     
return

###============================================================
###

Func NewGameStart()

    

            ###--------------------------------------------------
            ### Color the SQ Buttons - Dark/Light and FONT Size


            for Row = 1 to 9
            for Col = 1 to 9

                    shade = aSQColor[Row][Col]

                    if shade = 1
                        aButton[Row][Col] {setStyleSheet(C_ButtonFirstStyle)  setFont(new qFont("Calibri",gfontSize + 10, 100,0))}
                    else 
                        aButton[Row][Col] {setStyleSheet(C_ButtonSecondStyle) setFont(new qFont("Calibri",gfontSize + 10, 100,0))}
                    ok      

            next
            next


        for Row = 1 to 9
        for Col = 1 to 9
            ###--------------------------------------------
            ### SQ BUTTONS -- Set NBR/Blank from -aARRAY

            nbr = aArray[Row][Col]
            if nbr = 0
                aButton[Row][Col]{setText("")}
            else
                aButton[Row][Col]{setText(""+ nbr )}
            ok

        next
        next


return

###====================================
### Show GRID array
Func ShowArray(alpha)

    See nl
    for h = 1 to 9
        for v = 1 to 9
            See " "+ alpha[h][v]
        next
        See nl
    next
    See nl
return

###====================================
### Show LINE array
Func ShowArrayLine(alpha)

    //See nl
    for h = 1 to len(alpha)
        See " "+ alpha[h]
    next
    //See nl
return

###====================================
Func UserLeftClick(Row, Col)

    Row = 0+ Row      ### Convert to number
    Col = 0+ Col

    OldRow = Row
    OldCol = Col
    

    SolveForNumber(Row,Col)     ### For This Region, What are the Possible Nbrs that can fit ?
    
    Hint(Row,Col)               ### Show User possible Nbr that do Not Duplicate


return

###=====================================

Func RightClickMouse(Row, Col)

    Row = 0+ Row      ### Convert to number
    Col = 0+ Col
    nbr = 88

        
    new qMenu(workWidget)
    {
        setStyleSheet("selection-color:black; selection-background-color:cyan;")

        oAction = new qAction(workWidget) { setText("1") setClickEvent("click(1)") }  addAction(oAction)
        oAction = new qAction(workWidget) { setText("2") setClickEvent("click(2)") }  addAction(oAction)
        oAction = new qAction(workWidget) { setText("3") setClickEvent("click(3)") }  addAction(oAction)
        oAction = new qAction(workWidget) { setText("4") setClickEvent("click(4)") }  addAction(oAction)
        oAction = new qAction(workWidget) { setText("5") setClickEvent("click(5)") }  addAction(oAction)
        oAction = new qAction(workWidget) { setText("6") setClickEvent("click(6)") }  addAction(oAction)
        oAction = new qAction(workWidget) { setText("7") setClickEvent("click(7)") }  addAction(oAction)
        oAction = new qAction(workWidget) { setText("8") setClickEvent("click(8)") }  addAction(oAction)
        oAction = new qAction(workWidget) { setText("9") setClickEvent("click(9)") }  addAction(oAction)
        oAction = new qAction(workWidget) { setText("0") setClickEvent("click(0)") }  addAction(oAction)

        oCursor = new qCursor()
        exec(oCursor.pos())
    }

    // See " RightClick: "+ Row +"-"+ Col  +" = "+ gNbrRightClick +nl

    ###--------------------------------------------
    ### Click() function called above RETURNS gNbrRightClick  Here
    ### Insert Nbr in SQ in BLUE

     shade = aSQColor[Row][Col]
     if shade = 1
         aButton[Row][Col] {setStyleSheet(C_ButtonFirstStyleBlue)     setFont(new qFont("Calibri",gfontSize + 10, 100,0)) setText(""+ gNbrRightClick ) }
            if gNbrRightClick = 0
                aButton[Row][Col] {setStyleSheet(C_ButtonFirstStyle)  setFont(new qFont("Calibri",gfontSize + 10, 100,0)) setText("" ) }   ### ERASE SQ when Nbr 0
            ok

     but shade = 0
         aButton[Row][Col] {setStyleSheet(C_ButtonSecondStyleBlue)    setFont(new qFont("Calibri",gfontSize + 10, 100,0)) setText(""+ gNbrRightClick ) }
            if gNbrRightClick = 0
                aButton[Row][Col] {setStyleSheet(C_ButtonSecondStyle) setFont(new qFont("Calibri",gfontSize + 10, 100,0))  setText("" ) }   ### ERASE SQ when Nbr 0
            ok
     ok


     playArray[Row][Col] = gNbrRightClick       ### PLAY Record Array

     CheckDuplicates(Row,Col)
     CountSQFilled()
     TitletInvalidMove.setText(" Msg:" )        ### Clear HINT Msg from Left-Mouse-Button

return

###=====================================

Func Click(nbr)
    //See "Click: "+ nbr +nl
    gNbrRightClick = nbr

return

###=====================================
### Count Filled SQ - return count

Func CountSQFilled()

    count = 0
    for h = 1 to 9
        for v = 1 to 9
            if playArray[h][v] >= 1
                count++
            ok
        next
    next

    left = 81 - count
    TitletMoves.setText("Fill: "+ count +"-"+ left )

return count

###=====================================------------------
### Check DUPLICATES - Use dupArray to identify  dup SQ
###

Func CheckDuplicates(Row,Col)

    //See "CheckDup: LastPlay: "+Row +"-"+ Col +nl

    dupArray = zeroArray    ### Clear Dups before starting
    RestoreSQColors()       ### Erase Red SQ

    for h = 1 to 9
        CheckDupRow(h)
    next

    for v = 1 to 9
        CheckDupCol(v)
    next

    for r = 1 to 9
        CheckDupRegion(r)
    next

    for h = 1 to 9
        for v = 1 to 9
            if dupArray[h][v] > 1
                 aButton[h][v] {setStyleSheet(C_ButtonInvalidStyle) }
                    ### Last button played
                    aButton[Row][Col] {setStyleSheet(C_ButtonPickStyle) }
            ok
        next
    next

    //ShowArray(dupArray)

return

###=====================================

Func CheckDupRow(Row)

    FlagDup = 0
    nbrCount = [0,0,0,0,0,0,0,0,0]

    ### Find occurrence of a number
    for i = 1 to 9
        nbr = playArray[Row][i]
        if nbr > 0
            nbrCount[nbr] = nbrCount[nbr]++
        ok
    next

    ### Occurrence > 1 goes to dupArray
    for i = 1 to 9
        if nbrCount[i] > 1
            FlagDup = 1
            ### i is the dup nbr value ex. 6
            ### find the 6 in the playArray ... aButton

            for k = 1 to 9
                if playArray[Row][k] = i
                    dupArray[Row][k] = nbrCount[i]
                    //See "DupRow: "+ i +"-"+ Row +" "+ nbrCount[i] +nl
                ok
            next
        ok
    next

return FlagDup

###=====================================
### nbrCount Col: 3
### 0 1 0 0 0 2 1 1 1   <<< Col 3 has 6 twice

Func CheckDupCol(Col)

    FlagDup = 0
    nbrCount = [0,0,0,0,0,0,0,0,0]

    ### Find occurrence of a number
    for i = 1 to 9
        nbr = playArray[i][Col]
        if nbr > 0
            nbrCount[nbr] = nbrCount[nbr]++
        ok
    next

    ### Occurrence > 1 goes to dupArray
    for i = 1 to 9
        if nbrCount[i] > 1
            FlagDup = 1
            ### i is the dup nbr value ex. 6
            ### find the 6 in the playArray ... aButton

            for k = 1 to 9
                if playArray[k][Col] = i
                    dupArray[k][Col] = nbrCount[i]
                    //See "DupCol: "+ i +"-"+ Col +" "+ nbrCount[i] +nl
                ok
            next
        ok
    next

return FlagDup

###=====================================
### Check for Dup in each of 9 Regions
### regionArray[
###    [1,1,1,2,2,2,3,3,3],
###    [1,1,1,2,2,2,3,3,3],
###    [1,1,1,2,2,2,3,3,3],
###    [4,4,4,5,5,5,6,6,6],
###    [4,4,4,5,5,5,6,6,6],
###    [4,4,4,5,5,5,6,6,6],
###    [7,7,7,8,8,8,9,9,9],
###    [7,7,7,8,8,8,9,9,9],
###    [7,7,7,8,8,8,9,9,9] ]

Func CheckDupRegion(Region)

    FlagDup = 0
    nbrCount = [0,0,0,0,0,0,0,0,0]

    for h = 1 to 9
        for v = 1 to 9
            if regionArray[h][v] = Region
                nbr = playArray[h][v]

                if nbr > 0
                    nbrCount[nbr] = nbrCount[nbr]++
                ok
            ok
        next
    next

    for h = 1 to 9
        for v = 1 to 9
            if regionArray[h][v] = Region

                for nbr = 1 to 9
                    if nbrCount[nbr] > 1 AND playArray[h][v] = nbr
                        FlagDup = 1
                        dupArray[h][v] = nbrCount[nbr]
                    ok
                next

            ok
        next
    next

return FlagDup

###=================================================================
### HINT
###     Can THIS SQUARE be filled with a NOT Used NBR
###
###     Show User possible Nbr that do Not Duplicate existing Buttons
###     User Left-Mouse clicks on a Row-Col
###     Find possible Nbrs that are NOT-IN  the Row, Col, Region for Square selected

###     CALLED BY LEFT_MOUSE BUTTON Click

Func Hint(Row,Col)

    ### For NBR 1 2 3 4 5 6 7 8 9  Increment count if Nbr Exist someplace else
    ### ANY position left with <<0>> is Possible Candidate
    
        ### REG Solve For Number RC: 6-8
        ### Row-Hint:  1 1 0 1 0 0 0 0 0 0 0
        ### Col-Hint:  1 2 0 1 1 0 1 0 1 0 0
        ### Reg-Hint:  2 3 0 2 2 0 1 0 2 0 0
        ###                ^     ^   ^         > 3 6 8 can fit
        ### NBR        1 2 3 4 5 6 7 8 9 R C           

    nbrCount = [0,0,0, 0,0,0, 0,0,0, 0,0]

    ###----------------
    ### Check this ROW

    for i = 1 to 9
        nbr = playArray[Row][i]
        if nbr > 0
            nbrCount[nbr] = nbrCount[nbr]++
        ok
    next

    //See "Row-Hint: " ShowArrayLine(nbrCount) See nl 
    
    ###----------------
    ### Check this Col

    for i = 1 to 9
        nbr = playArray[i][Col]
        if nbr > 0
            nbrCount[nbr] = nbrCount[nbr]++
        ok
    next

    //See "Col-Hint: " ShowArrayLine(nbrCount)  See nl 
    
    ###-------------------
    ### Check this Region

        RegionID = regionArray[Row][Col]        ### Region-ID 1..9  for SQ in this 
        for h = 1 to 9
            for v = 1 to 9

                curRegion = regionArray[h][v]   ### Current Region are we in for this SQ ?
                
                if curRegion = RegionID         ### Current Region == RegionID of SQ to solve
                    nbr = playArray[h][v]

                    if nbr > 0
                        nbrCount[nbr] = nbrCount[nbr]++
                    ok
                ok
            next
        next

    //See "Reg-Hint: " ShowArrayLine(nbrCount) See nl 

    ###--------------------------------------------------------------------
    ### HINT MSG:   Check is ANY Position or Nbr was NOT used --- Still <<0>>
    ###             HINT msg created, positions with <<0>> added to msg
    ### gHINTARRAY: gHintArray: 6-9 = 0 0 3 0 0 0 0 8 0
    
    MsgHint = "Hint:"
    HintNbrs = ""
            gHintArray = [0,0,0, 0,0,0, 0,0,0, 0,0] ### Zero it out, last 2 are Row-Col         
            gHintArray[10] = Row
            gHintArray[11] = Col
            
            k = 1
            for i = 1 to 9
                if nbrCount[i] = 0                  ### Nbr NOT Used Yet, Add it to Hint msg
                    MsgHint = MsgHint +" " + i
                    HintNbrs = HintNbrs +i          ### Squeeze then in Display SQuare
                    
                    gHintArray[i] = i               ### <<<=== Possible Nbr for this SQ
                    k++
                ok
            next
            TitletInvalidMove.setText(MsgHint)
            
            InsertNbrsSQ(Row,Col,HintNbrs)          ### HintsNbrs Show in SQUARE

    ###-------------------------------------------------------------
    ### CALLED by SOLVE()
    ###     RETURNS  Unique-Nbr value for that Row that Col, that Region
    ###     Is there ONLY ONE possible solution Nbr

        uniqNbr = 0
            k = 0                               ### k used to count for Unique-Nbr
            for i = 1 to 9
                if nbrCount[i] = 0              ### Nbr Not Used Yet in nbrCount[] position <<0>>
                    k++                         ### How many possible nbr found
                    uniqNbr = i
                ok
            next

            if k = 1                            ### ONLY ONE - Unique Nbr found
                return uniqNbr                  ### return UniqueNbr value 1..9 else 0 means NONE found
            ok
            
         

return 0

###========================================================
### SOLVE BUTTON CLICKED 
###         Scan all the SQuares one by one if a number fits
###             CALL HINT(Row,Col)
###                 UniqNbr returned for Empty SQ  Row-Col-Region
###                 Insert the Unique nbr return in the Current Row/Col
###
### ... Fill in playArray and aButton
###

### SOLVE BUTTON CLICKED

Func Solve()



    ###------------------
    
    for repeat = 1 to 1
        for h = 1 to 9
            for v = 1 to 9

                if playArray[h][v] = 0      ###        Check only SQ that is Empty
                    uniqNbr = Hint(h,v)     ### <<<=== CALL HINT() Is there 1 unique number possible

                    if uniqNbr != 0         ### Yes - Unique-Number returns value 1..9, 0 - NONE
                        InsertUniqNbr(h,v,uniqNbr)              
                    ok
                ok
            next
        next

        count = CountSQFilled()
        if count = 81
            TitletInvalidMove.setText("Finish " )
        ok

    next
    
    ###------------------------------------------------------
    ### SOLVE FOR NBR ALGO - Find Nbr that Fits the SQuare
    
    for s = 1 to 9 step 3
        for t = 1 to 9 step 3
            SolveForNumber(s,t)
        next
    next
    
    ###------------------------------------------
    ### aHINTS ARRAY
    
    //See "aHints: "+nl   ShowArray(aHints) See nl
    SolveaHintsArray()
    

return



###===========================================================
###===========================================================
## Insert this Nbr into the SQuare and color SQ same as it was

Func InsertUniqNbr(h,v,uniqNbr)

    //See nl+"InsertUniqNbr: "+ h +"-"+ v +"  "+ uniqNbr +nl

    playArray[h][v] = uniqNbr
    
    Value = aSQColor[h][v]      ### Value is Button Color
    if Value = 1
            aButton[h][v] {setStyleSheet(C_ButtonFirstStyleBlue)  setFont(new qFont("Calibri",gfontSize + 10, 100,0)) setText(""+ uniqNbr ) }
    but Value = 0
            aButton[h][v] {setStyleSheet(C_ButtonSecondStyleBlue) setFont(new qFont("Calibri",gfontSize + 10, 100,0)) setText(""+ uniqNbr ) }
    ok

    //ShowArray(playArray)
    
    FillHintsArray(h,v,uniqNbr)
    
return

###===========================================================
###===========================================================
### BrutForce RED -- Insert this Nbr into the SQuare and color SQ same as it was

Func InsertUniqNbrRED(h,v,uniqNbr)

    //See nl+"InsertUniqNbr: "+ h +"-"+ v +"  "+ uniqNbr +nl

    playArray[h][v] = uniqNbr
    
    Value = aSQColor[h][v]      ### Value is Button Color
    if Value = 1
            aButton[h][v] {setStyleSheet(C_ButtonFirstStyleRed)  setFont(new qFont("Calibri",gfontSize + 10, 100,0)) setText(""+ uniqNbr ) }
    but Value = 0
            aButton[h][v] {setStyleSheet(C_ButtonSecondStyleRed) setFont(new qFont("Calibri",gfontSize + 10, 100,0)) setText(""+ uniqNbr ) }
    ok

    //ShowArray(playArray)
    
    FillHintsArray(h,v,uniqNbr)
    
return

###===========================================================
### Insert HINT-NBRS into the SQuare and color SQ same as it was
### setFont(new qFont("Calibri",gfontSize + 10, 100,0))

Func InsertNbrsSQ(h,v,HintNbrs)

//See "InsertNbrsSQ.: "+ h +"-"+ v +"  "+ HintNbrs +nl

        
    if HintsInSquare.isChecked() = 1        ### TRUE - Show Hits inside the Square

        if playArray[h][v] !=0
            return
        ok
        
                
        Value = aSQColor[h][v]      ### Value is Button Color
        if Value = 1
                aButton[h][v] {setStyleSheet(C_ButtonFirstStyleCyan)  setFont(new qFont("Calibri", gfontSize -2, 100,0)) setText(""+ HintNbrs ) }
        but Value = 0
                aButton[h][v] {setStyleSheet(C_ButtonSecondStyleCyan) setFont(new qFont("Calibri", gfontSize -2, 100,0)) setText(""+ HintNbrs ) }
        ok

        ### NOT here ShowArray(playArray)
        
        FillHintsArray(h,v,HintNbrs)
        
    else
        ### Clear Hints in Square - the tiny numbers - erase
        Value = aSQColor[h][v]      ### Value is Button Color
        if Value = 1
                aButton[h][v] {setStyleSheet(C_ButtonFirstStyleCyan)  setText("" ) }
        but Value = 0
                aButton[h][v] {setStyleSheet(C_ButtonSecondStyleCyan) setText("" ) }
        ok
    
    ok
    
return

###============================================================
###============================================================
###============================================================


###============================================================
### For EACH REGION
###     For EACH SQAURE in the Region
###         Which Numbers are POSSIBLE for EACH EMPTY SQUARE in the Region
###         EACH EMPTY SQUARE has 9 possible results in its own Possible Number Array
###     Next
###
###         In the List of  EMPTY SQUARES - Possible Nbr Array
###         Count ALL the Possible Hints
###             if there is a UNIQUE Hint.
###                 Identify the SQ Row / Col with either Unique nbr
###                 Insert it into the Square
###

Func SolveForNumber(Row, Col)

    ThisRow = Row
    ThisCol = Col
    
    
    ###  1 2 3  4 5 6  7 8 9  R C
    RegionForNbr = [
        [0,0,0, 0,0,0, 0,0,0, 0,0],
        [0,0,0, 0,0,0, 0,0,0, 0,0],
        [0,0,0, 0,0,0, 0,0,0, 0,0],
        [0,0,0, 0,0,0, 0,0,0, 0,0],
        [0,0,0, 0,0,0, 0,0,0, 0,0],
        [0,0,0, 0,0,0, 0,0,0, 0,0],
        [0,0,0, 0,0,0, 0,0,0, 0,0],
        [0,0,0, 0,0,0, 0,0,0, 0,0],
        [0,0,0, 0,0,0, 0,0,0, 0,0] ]    ### last 2 are Row-Col
    
    //See "RegionForNbr: "  ShowArray(RegionForNbr)     See nl
    
    nbrCount = [0,0,0, 0,0,0, 0,0,0, 0,0]
    
    ###-------------------
    ### Check this Region

        //See nl +"REG Solve For Number RC: "+ThisRow +"-"+ ThisCol +nl
        RegionID = regionArray[ThisRow][ThisCol]        ### Region-ID 1..9  for SQ in this 
        
        k = 1
        for Row = 1 to 9
            for Col = 1 to 9

                ###----------------------------------------------------------------------
                ### Current Region == RegionID of SQ to solve AND playArray SQ is EMPTY
                
                    ### REG Solve For Number RC: 6-8
                    ### Row-Hint:  1 1 0 1 0 0 0 0 0 0 0
                    ### Col-Hint:  1 2 0 1 1 0 1 0 1 0 0
                    ### Reg-Hint:  2 3 0 2 2 0 1 0 2 0 0
                    ###                ^     ^   ^         > 3 6 8 can fit
                    ### NBR        1 2 3 4 5 6 7 8 9 R C    
                
                curRegion = regionArray[Row][Col]           
                if curRegion = RegionID   AND playArray[Row][Col] = 0           
                        
                    ###------------------------------------------------------------ 
                    ### CALL HINT() Fills-In: gHintArray: 6-9 == 0 0 3 0 0 0 0 8 0 
                    
                    uniqNbr = Hint(Row,Col)         ### Returns Uniq-Nbr if possible
                    if uniqNbr != 0                 ### Yes - Unique-Number returns value 1..9, 0 - NONE
                        InsertUniqNbr(Row,Col,uniqNbr)     

                        //See "REG UniqNbr Insert  RC: "+Row +"-"+ Col +" "+ uniqNbr +nl
                    ok
                    
                    //See "REG gHintArray: "+ Row +"-"+ Col +" -- "     ShowArrayLine(gHintArray) See nl    

                    RegionForNbr[k] = gHintArray
                    k++
                ok                  
                
            next
        next
        
        //See nl
        //See "REG After RegionForNbr: "   ShowArray(RegionForNbr)   See nl
        
        ### Count EACH-NBR in RegionForNbr position
        ### If it occurs ONCE - Insert it on position.
        ### nbrCount ==  0 0 3 0 0 1 1 2 0 --  Position = Nbr

            for h = 1 to 9
                for v = 1 to 9      
                        nbr = RegionForNbr[h][v] 
                        if nbr > 0
                            nbrCount[nbr] = nbrCount[nbr]++     ###<<<=== 
                        ok          
                next
            next
                                        
            //See "REG:..................."  ShowArrayLine(nbrCount) See nl
            
        ### Find Position =Nbr where the nbrCount values = 1 
        ### Then scan RegionForNbrber. Get Row-Col where Position-Nbr occurred
        ### Insert the Position-Nbr into the Square
        
                        ###  REG-6  4-7     2 4 0
                        ###  REG-6  5-7     1 9 5
                        ###  REG-6  6-7     0 0 0
                ### REG Solve For Number RC: 6-7
                ###
                ### REG gHintArray: 4-9 --  0 0 3 0 0 6 0 8 0   4 9  > 368
                ### REG gHintArray: 6-7 --  0 0 0 0 0 0 7 0 0   6 7  > 7
                ### REG gHintArray: 6-8 --  0 0 3 0 0 0 0 0 0   6 8  > 3
                ### REG gHintArray: 6-9 --  0 0 0 0 0 0 0 8 0   6 9  > 8
                ###
                ### REG: Sum of Position -  0 0 2 0 0 1 1 2 0   0 0
                ###                                   ^ ^ 
                ### REG PosNbr: 6  REG Found PosNbr: 6 at 4-9        > 6
                ### REG PosNbr: 7  REG Found PosNbr: 7 at 6-7        > 7
        
            PosNbr = 88
            for k = 1 to 9
                if nbrCount[k] = 1
                    PosNbr = k          ### Ex. 6
                    
                    //See "REG PosNbr: "+ PosNbr +"  "
                    
                        for h = 1 to 9
                            for v = 1 to 9
                                if RegionForNbr[h][v] = PosNbr
                                    GetRow = RegionForNbr[h][10]
                                    GetCol = RegionForNbr[h][11]
                                    InsertUniqNbr(GetRow,GetCol,PosNbr)
                                    
                                    //See "REG Found PosNbr: "+ PosNbr +" at "+ GetRow +"-"+GetCol +nl
                                    exit 2
                                ok      
                            next
                        next
                
                ok
            
            next
    


return

###========================================================
###========================================================
### aHINTS ARRAY -- Filled by InsertUniqNbr and InsertHintNbrs

Func FillHintsArray(Row, Col, Value)

#/*
# aHints: After a pass of Solve
#      1     2    3   4     5     6     7     8     9
#    ---------------------------------------------------- 
# 1  | 3467  467  357 1234  23456 9     1     2356  8
# 2  | 34689 4689 1   7     23456 23456 34569 23569 24569
# 3  | 3469  2    359 134   8     13456 7     3569  4569
# 4  | 1347  147  37  5     9     12346 8     236   26 
# 5  | 5     189  389 1238  236   7     369   4     269
# 6  | 2     489  6   348   34    34    5     7     1         <<<  34 Twin -- Remove 34 from this Row Cells. 6-4 Left with 8 = Solved
# 7  | 6789  3    789 49    1     45    2     5689  4569
# 8  | 1789  1789 4   6     7     25    9     58    3
# 9  | 69    5    2   349   34    8     46    1     7
#     
#*/
#
    
    ###------------------------------------------------
    ### ADD HINTS -- one for each Row-Col called
    
    aHints[Row][Col] = Value                ### Add Hint for this Square

    //See "aHints: "+nl   ShowArray(aHints) See nl


return

###========================================================
### Solve aHINTS Array
###
### aList = "a":"z"
### if find(aList,"p")  ? :True else ? :False ok
### PM3Hard2 = 34

Func SolveaHintsArray()

    //See "SolveaHintsArray: "+nl   ShowArray(aHints) See nl

    ###-----------------------------------------------------
    ### Across ROWS
    
    //See nl
    for h = 1 to 9
        for v = 1 to 9              ### Diff staring SQuare
        
            FindNbr = aHints[h][v]
                        
            if FindNbr != 0 OR FindNbr > 9
            
                for k = v+1 to 9            ### Go Across
                
                    if aHints[h][k] = FindNbr 
                        //See "FoundRow: "+ h +"-"+ v +" "+ FindNbr +" at "+ h +"-"+ k +" = "+ aHints[h][k] +nl   

                        ### Remove digits 34 from other squares on the Row              
                        RemoveHintDigits("Horizontal",h,v,k,FindNbr)
                                    
                    ok
                
                next
            ok
            
        next    
    next
    
    ###-----------------------------------------------------
    ### Across COLUMNS
    
    //See nl 
    for v = 1 to 9                  ### FLIP  Vert first
        for h = 1 to 9              ### Diff staring SQuare
        
            FindNbr = aHints[h][v]
                        
            if FindNbr != 0 OR FindNbr > 9
            
                for k = h+1 to 9    ### FLIP go Down
                
                    if aHints[k][v] = FindNbr       ### Flip 
                        //See "FoundCol: "+ h +"-"+ v +" "+ FindNbr +" at "+ k +"-"+ v +" = "+ aHints[k][v] +nl   ### Flip

                        ### Remove digits 34 from other squares on the Row
                        RemoveHintDigits("Vertical",h,v,k,FindNbr)
                    ok
                
                next
            ok
            
        next    
    next
    
    
    ###-------------------------------------------------------------------
    ###  Across REGIONS    1--      
    ###                 1- 123      ### FoundReg: 1 Pos: 3 13 at 7 = 13          
    ###                 2- 456      ### FoundReg: 1 Pos: 6 1379 at 9 = 1379 --- Remove 13 from 1379 --> 79    
    ###                 3- 789          
    ###

    //See nl
    curRegion = 1
    
    for RegionID = 1 to 9                       ### For EACH Region
        
            aRegion = [0,0,0, 0,0,0, 0,0,0]     ### Region Cell 1,2,3, 4,5,6, 7,8,9
            i = 1
            
            for h = 1 to 9
                for v = 1 to 9                              ### Diff staring SQuare     
                    curRegion = regionArray[h][v]           ### Region-ID 1..9  for SQ in this      
                    if curRegion = RegionID         
                        aRegion[i] = aHints[h][v]           ### HINTS in THIS REGION -- fill array horizontal of aRegion[]
                        i++
                    ok          
                next    
            next
        
        //See "RegionID: "+ RegionID +" "  See ShowArrayLine(aRegion)   See nl
        
            for j = 1 to 9                                  ### For EACH cell J on array horizontal of aRegion[]
                FindNbr   = aRegion[j]
                
                if FindNbr != 0 OR FindNbr > 9
                
                    for k = j+1 to 9                        ### Go Across aRegion using J nd K                                       
                        if aRegion[k] = FindNbr 
                            //See "FoundReg: "+ RegionID +" Pos: "+ j +" "+ FindNbr +" at "+ k +" = "+ aRegion[k] +nl 

                            ### FoundReg: 1 Pos: 3 13 at 7 = 13
                            ### FoundReg: 1 Pos: 6 1379 at 9 = 1379 --- Remove 13 from 1379 --> 79
                            ### aregion[0 0 13 0 0 1379 13 6 1379]
                            
                            ########### 
                            if FindNbr >= 11 and FindNbr <= 99                              ### 2 digit nbr
                                    for Pos = 1 to 9
                                        if !(Pos = j OR Pos = k) AND aRegion[Pos] > 9       ### Not filled Square
                                                                            
                                            sHints   = ""+ aRegion[Pos]
                                            sFindNbr = ""+ FindNbr
                                        
                                            sHints = substr(sHints, sFindNbr[1],"" )        ### Erase double-digit from other positions       
                                            sHints = substr(sHints, sFindNbr[2],"" )
                                            nHints = number(sHints) 
                                                
                                            aRegion[Pos] = nHints
                                        ok
                                    next
                                    
                                    ###------------------------------------------------------
                                    ### aRegion[] stick nHints into proper Region: Row-Col
                                        
                                    i = 1
                                    for p = 1 to 9
                                        for q = 1 to 9                              ### Diff staring SQuare
                                        
                                            curRegion = regionArray[p][q]           ### Region-ID 1..9  for this SQ coordinate      
                                    
                                            if curRegion = RegionID                 ### HINTS in THIS REGION -- fill line into Region Box
                                                        
                                                regNbr       = aRegion[i]
                                                aHints[p][q] = regNbr
                                                
                                                //See "curRegion: "+ curRegion +" i: "+ i + " regNbr: " + regNbr +nl            
                                                //See "aHints-pq.: "  ShowArray(aHints)  See nl
                                                                                    
                                                    if regNbr > 9
                                                        InsertNbrsSQ(p,q, regNbr)    
                                                    ok                                              
                                                    if regNbr > 0 AND regNbr <= 9
                                                        InsertUniqNbr(p,q, regNbr)
                                                    ok                                                                                          
                                                i++ 
                                            ok                              
                                        next    
                                    next    
                                    ###---------------      
                                
                            ok

                            ###########
                            
                        ok                  
                    next
                                
                ok
                next
        
        
        
    next
    ###--------------------------

 
return
###==========================================================




###==========================================================
### Remove HINT Digits from Row, Col, Reg

Func RemoveHintDigits(Type,h,v,k,FindNbr)

    ###-------------------
    ### ROW
    
    if Type = "Horizontal"
        ### Remove digits 34 from other squares on the Row, k = horz
        if FindNbr >= 11 and FindNbr <= 99                              ### 2 digit nbr
            Row = h
                for Col = 1 to 9
                    if !(Col = v OR Col = k) AND aHints[Row][Col] > 9   ### Not filled Square
                                                        
                        sHints   = ""+ aHints[Row][Col] 
                        sFindNbr = ""+ FindNbr
                    
                        sHints = substr(sHints, sFindNbr[1],"" )            
                        sHints = substr(sHints, sFindNbr[2],"" )
                        nHints = number(sHints)                         
            
                        //See "HORZ aHints[Row][Col]: "+ Row +"-"+ Col +" "+ aHints[Row][Col] +" "+ sFindNbr +" ---> "+ nHints  +nl
                        
                        if nHints > 9
                            InsertNbrsSQ(Row,Col,nHints)    
                        ok
                        if nHints <= 9
                            InsertUniqNbr(Row,Col,nHints)
                        ok
                        
                        
                    ok
                next
            
        ok
    ok
    
    ###---------------------
    ### COLUMN
    
    if Type = "Vertical"
        ### Remove digits 34 from other squares on the Col  k = vert
        if FindNbr >= 11 and FindNbr <= 99                              ### 2 digit nbr
            Col = v
                for Row = 1 to 9
                    if !(Row = h OR Row = k) AND aHints[Row][Col] > 9   ### Not filled Square
                                                        
                        sHints   = ""+ aHints[Row][Col] 
                        sFindNbr = ""+ FindNbr
                    
                        sHints = substr(sHints, sFindNbr[1],"" )            
                        sHints = substr(sHints, sFindNbr[2],"" )
                        nHints = number(sHints)                         
            
                        //See "VERT aHints[Row][Col]: "+ Row +"-"+ Col +" "+ aHints[Row][Col] +" "+ sFindNbr +" ---> "+ nHints  +nl
                        
                        if nHints > 9
                            InsertNbrsSQ(Row,Col,nHints)    
                        ok
                        if nHints <= 9
                            InsertUniqNbr(Row,Col,nHints)
                        ok
                        
                        
                    ok
                next
            
        ok
    ok

    
    ###-------------------
    ### REGION
    
    if Type = "X-Region"
        ### Remove digits 34 from other squares on the Row, k = horz
        if FindNbr >= 11 and FindNbr <= 99                              ### 2 digit nbr
            Row = h
                for Col = 1 to 9
                    if !(Col = v OR Col = k) AND aHints[Row][Col] > 9   ### Not filled Square
                                                        
                        sHints   = ""+ aHints[Row][Col] 
                        sFindNbr = ""+ FindNbr
                    
                        sHints = substr(sHints, sFindNbr[1],"" )            
                        sHints = substr(sHints, sFindNbr[2],"" )
                        nHints = number(sHints)                         
            
                        See "HORZ aHints[Row][Col]: "+ Row +"-"+ Col +" "+ aHints[Row][Col] +" "+ sFindNbr +" ---> "+ nHints  +nl
                        
                        if nHints > 9
                            InsertNbrsSQ(Row,Col,nHints)    
                        ok
                        if nHints <= 9
                            InsertUniqNbr(Row,Col,nHints)
                        ok
                        
                        
                    ok
                next
            
        ok
    ok
    
    ###---------------------    

return

###==========================================================
###
### CLICKED ON SOLVE BY BRUTFORCE  <<<===
###
### Insert Nbr as RED to show difference
###

Func BrutForce()

    sudokuBrut = playArray      ### Copy current playArray progress
    solveBrut(sudokuBrut)       ### ===>>> CALL SOLVER
    
    for h = 1 to 9
    for v = 1 to 9
        if playArray[h][v] = 0
            uniqNbr = sudokuBrut[h][v]  
            InsertUniqNbrRed(h,v,uniqNbr)   ### RED Nbr for BrutForce
        ok
    
    next
    next
    

return

###==========================================================   
###==========================================================
//
// CALL C-CODE  sudokuSolver  400X FASTER
//
//-----------------------------------------------------------------
// Sudoku solving via backtracking and recursion
// sudoku  : a 2-dimensional grid of numbers (0-9)
//           0 matches unknown values to be found.
// returns : true, if a solution was found,
//           false otherwise.
//
// CALL C-CODE  400X FASTER

Func solveBrut(sudoku)

		See "CALL sudokuSolver with array"+nl
    
	sudokuSolver(sudoku)        ###>>> CALL C-Code, Returns solved puzzle. Copy current playArray progress
	
		See "BACK from sudokuSolver "+nl
    
return true


###==========================================================   
###==========================================================




//=============================================
//=============================================
//=============================================             
