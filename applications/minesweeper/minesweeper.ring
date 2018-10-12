## Program:  MineSweeper - Button Screen
### Author:  Bert Mariani, Gal Zsolt ~ CalmoSoft ~
### Date:    2018-09-18
###
### TAB set to 3 Spaces
### aArray Letters: "."-Edge, e-empty, E-EmptyVisited, C-Chosen, M-Mine, B-Boom

load "stdlib.ring"
load "guilib.ring"


hSize  = 12 +2    ### Size of array, Display -2 smaller
vSize  = 12 +2    ### Size of array, Display -2 smaller
nMines = 40       ### Number of Mines
nScore = 0        ### Player Score

h      = 0        ### H-coord of Cell
v      = 0        ### V-coord of Cell

moveX  = 490 moveY  = 100       ### Open Window on Screen Position
sizeX  = 600 sizeY  = 600       ### Size of Window

aArray = newList(hSize, vSize)  ### Internal Array with Letters
button = newlist(hSize, vSize)  ### Button Array with Display Colors

C_SPACING  = 1

C_EmptyButtonStyle  = 'border-radius:8px; background-color:blue'
C_ButtonRedStyle    = 'border-radius:8px; color:black; background-color: red'
C_ButtonYellowStyle = 'border-radius:8px; color:black; background-color: yellow'
C_ButtonVioletStyle = 'border-radius:8px; color:black; background-color: violet'

C_ButtonWhiteStyle  = 'border-radius:8px; color:black; background-color: silver'
C_ButtonGreenStyle  = 'border-radius:8px; color:black; background-color: lime'
C_ButtonOrangeStyle = 'border-radius:8px; color:black; background-color: orange'
C_ButtonBlueStyle   = 'border-radius:8px; color:black; background-color: blue'

LayoutButtonRow = list(hSize)

###=============================================================================

app = new qApp
{


    win = new qWidget()
    {
        setWindowTitle('Game MinesSweeper')
          move(moveX, moveY)
        resize(sizeX, sizeY)
        setStyleSheet('background-color:white')

        winHeight = win.height()
        fontSize  = 8 + (winheight / 100)


        ###-----------------------------------------------------------------------
        ### QVBoxLayout lays out widgets in a vertical column, from top to bottom.

        LayoutButtonMain = new QVBoxLayout()                ### Vertical

        LayoutButtonMain.setSpacing(C_Spacing)
        LayoutButtonMain.setContentsMargins(5,5,5,5)

            for Row = 2 to hSize -1

                ###-----------------------------------------------------------------------
                ### QHBoxLayout lays out widgets in a horizontal row, from left to right

                LayoutButtonRow[Row] = new QHBoxLayout()    ### Horizontal
                {
                    setSpacing(C_Spacing)
                    setContentsmargins(0,0,0,0)
                }

               for Col = 2 to vSize -1
                    button[Row][Col] = new QPushButton(win) ### Create Buttons
                    {
                        setStyleSheet(C_EmptyButtonStyle)
                        setClickEvent("GetUserInput(" + string(Row) + "," + string(Col) + ")")  ### CLICK
                        setSizePolicy(1,1)
                    }

                    LayoutButtonRow[Row].AddWidget(button[Row][Col])    ### Widget-Add Buttons
               next

               LayoutButtonMain.AddLayout(LayoutButtonRow[Row])         ### Layout - Add Row
            next

            ###-----------------------------------------------------
            ###-----------------------------------------------------
                nbrRowCellsMsg = new qLabel(win)
                {
                    setFont(new qFont("Calibri",fontsize,100,0))
                    setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                    setStyleSheet("background-color:orange")
                    setText("Rows: ")
                }

                nbrRowCells = new qLineEdit(win)
                {
                    setFont(new qFont("Calibri",fontsize,100,0))
                    setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                    setText(""+ (hSize -2))
                }

                nbrColCellsMsg = new qLabel(win)
                {
                    setFont(new qFont("Calibri",fontsize,100,0))
                    setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                    setStyleSheet("background-color:orange")
                    setText("Cols: ")
                }

                nbrColCells = new qLineEdit(win)
                {
                    setFont(new qFont("Calibri",fontsize,100,0))
                    setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                    setText(""+ (vSize -2))
                }

                nbrMinesMsg = new qLabel(win)
                {
                    setFont(new qFont("Calibri",fontsize,100,0))
                    setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                    setStyleSheet("background-color:orange")
                    setText("Mines: ")
                }

                nbrMines = new qLineEdit(win)
                {
                    setFont(new qFont("Calibri",fontsize,100,0))
                    setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                    setText(""+ nMines)
                }


                playerScoreMsg = new qLabel(win)
                {
                    setFont(new qFont("Calibri",fontsize,100,0))
                    setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                    setStyleSheet("background-color:orange")
                    setText("Score:")
                }

                playerScore = new qLineEdit(win)
                {
                    setFont(new qFont("Calibri",fontsize,100,0))
                    setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                    setText(""+ nScore)
                }

                newGame  = new QPushButton(win)
                {
                    setFont(new qFont("Calibri",fontsize,100,0))
                    setStyleSheet("background-color:violet")
                    setText("New Game")
                    setClickEvent("NewGameStart()")
                }


                    LayoutDataRow = new QHBoxLayout()   ### Horizontal

                    LayoutDataRow.AddWidget(nbrRowCellsMsg)
                    LayoutDataRow.AddWidget(nbrRowCells)

                    LayoutDataRow.AddWidget(nbrColCellsMsg)
                    LayoutDataRow.AddWidget(nbrColCells)

                    LayoutDataRow.AddWidget(nbrMinesMsg)
                    LayoutDataRow.AddWidget(nbrMines)

                    LayoutDataRow.AddWidget(playerScoreMsg)
                    LayoutDataRow.AddWidget(playerScore)

                    LayoutDataRow.AddWidget(newGame)


                    LayoutButtonMain.AddLayout(LayoutDataRow)           ### Layout - Add Row

            ###-----------------------------------------------------
            ###-----------------------------------------------------

        setLayout(LayoutButtonMain)

        PopulateArray()             ###<<<  Game Internal Array

        show()
    }

    exec()
}

###=================================================
###=================================================

### FUNCTIONS

###------------------------------------------------------
### NewGameStart - Read Row Col Mines values, Score reset

Func NewGameStart()
#See "NewGameStart: " +nl

   ###--------------------------------------------
    ### Clear Buttons back to Blue and Blank Text

    for v = 2 to vSize -1
        for h = 2 to hSize -1
            button[h][v] { setStyleSheet(C_ButtonBlueStyle) setText("") }
        next
    next

    ###-------------------------------------
    ### Read User Grid Size and Mines Size
    ### Need to CAll Layout !!! ??? How
    ### Need to redo aArray and Button size  ??? How

    nScore = 0
    playerScore.setText(""+ nScore)

    # hSize  = 2+ nbrRowCells.text() ### 2 bigger that user types in
    # vSize  = 2+ nbrColCells.text()

    nMines = 0+ nbrMines.text()


    PopulateArray()

return

###------------------------------------------------
### Populate Internal Array and Mines

Func PopulateArray()
See "PopulateArray: "+ hSize +"-"+ vSize +" M: "+ nMines +nl

 aArray = newList(hSize, vSize) ### Internal Array with Letters
### ??? button = newlist(hSize, vSize)  ### Button Array with Display Colors

    n = 1
    for v = 1 to vSize
        for h = 1 to hSize

            if h = 1 OR v = 1 or h = hSize OR v = vSize
                aArray[h][v] = '.'  ### dot - Edges
            else
                aArray[h][v] = 'e'  ### e - Empty
            ok
          n++
        next
    next


    ###-------------------------------------------------
    ### Populate Mines at random

    for n = 1 to nMines
        h = random(hSize -3 ) +2    ### Prevent Zero and Edges
        v = random(vSize -3 ) +2    ### Inside grid only
        aArray[h][v] = 'M'          ### M - Mine
    next

return



###-----------------------------------------------
### START GAME !!!
### Get user to choose cell Horz-Vert

Func GetUserInput(m,n)
#See "GetUserInput: "+ m +"-"+ n +nl

    h = 0+ m                ### convert to number
    v = 0+ n

    Letter = aArray[h][v]
    ### SEE "Letter: "+ Letter + " MN: "+ m +"-"+ n +" HV: "+ h +"-"+ v +nl

   Play(h,v)

return

###-----------------------------------------

Func Play(h,v)
#See "Play: "+ h +"-"+ v +nl

        if aArray[h][v] = 'e'       ### e-Empty
            aArray[h][v] = 'C'      ### C-Chosen
            button[h][v] { setStyleSheet(C_ButtonGreenStyle) setText("C") }

            CheckCellChosen(h,v)

            nScore = CountCellsOpened()
            playerScore.setText(""+ nScore)
        ok

        if aArray[h][v] = 'M'       ### M-Mine
            ### aArray[h][v] = 'B'      ### Boom !!!
            button[h][v] { setStyleSheet(C_ButtonRedStyle) setText("M") }
            See "Boom !!!" +nl
        ok

    ###end

    ###---------------------------------------
    ### BOOM !!! Mine was chosen - END of GAME


Return


###-------------------------------------
### Check 8 Neighbors of C cell clicked
### Flip e-empty to E-visited

Func CheckCellChosen(h,v)
#SEE "CheckCellChosen: "+ h +"-"+ v +nl

    See "HV:"+h +"-"+v +" "+ aArray[h][v] +nl

    for vert = v-1 to v+1
        for horz = h-1 to h+1

            if aArray[horz][vert] = 'e'
                aArray[horz][vert] = "E"

                button[horz][vert] { setStyleSheet(C_ButtonWhiteStyle) setText("E") }

                ### Count number of Mines around the E cell
                MineCount = CheckMines(horz,vert)

                if MineCount != 0
                    aArray[horz][vert] = MineCount
                     button[horz][vert] { setStyleSheet(C_ButtonYellowStyle) setText(""+ MineCount) }
                ok

                ### Flip e-Cells around E-Cell
                if MineCount = 0
                    CheckAroundE(horz,vert)
                ok

            ok
        next
    next

return

###---------------------------------------------------
### Count the number of MINES around C and E cell

Func CheckMines(h,v)
#SEE "CheckMines: "+ h +"-"+ v +nl

   MineCount = 0

    for vert = v-1 to v+1
        for horz = h-1 to h+1

            if aArray[horz][vert] = 'M'
                MineCount++
            ok
        next
    next

return MineCount

###--------------------------------------------------
### Check around E-cell for e-empty, Flip e to E

Func CheckAroundE(h,v)
#See "CheckAroundE: "+ h +"-"+ v +nl

    ### See "E: "+h +"-"+ v +nl
    for vert = v-1 to v+1
        for horz = h-1 to h+1

            if aArray[horz][vert] = 'e'
                aArray[horz][vert] = "E"
                    button[horz][vert] { setStyleSheet(C_ButtonWhiteStyle) setText("E") }


                ### Count number of Mines around the E cell
                MineCount = CheckMines(horz,vert)

                if MineCount != 0
                    aArray[horz][vert] = MineCount
                         button[horz][vert] { setStyleSheet(C_ButtonYellowStyle) setText(""+ MineCount) }
                ok

                ### Recursive - check around New E's
                ### Flip e-Cells around E-Cell
                if MineCount = 0
                    CheckAroundE(horz,vert)
                ok

            ok
        next
    next

return

###--------------------------------------------------
### Count Cells that were opened for playerScore

Func CountCellsOpened()
   ce = 0 cM = 0 cF = 0 cC = 0 c1 = 0 c2 = 0
    c3 = 0 c4 = 0 c5 = 0 c6 = 0 c7 = 0 c8 = 0

    cells = (hSize-2) * ( vSize-2)
    for v = 2 to vSize -1
        for h = 2 to hSize -1

            if aArray[h][v] = "e"  ce++  ok
            if aArray[h][v] = "M"  cM++  ok

         /* ### Debug distribution
            if aArray[h][v] = "E"  cF++  ok
         if aArray[h][v] = "C"  cC++  ok
            if aArray[h][v] = "1"  c1++  ok
            if aArray[h][v] = "2"  c2++  ok
            if aArray[h][v] = "3"  c3++  ok
            if aArray[h][v] = "4"  c4++  ok
            if aArray[h][v] = "5"  c5++  ok
            if aArray[h][v] = "6"  c6++  ok
            if aArray[h][v] = "7"  c7++  ok
            if aArray[h][v] = "8"  c8++  ok
         */

        next
    next

    #SEE "Cells Opened: "+ ce +" "+ cM +" "+ cF +" "+ cC +" "+ c1 +" "+ c2 +" "+ c3 +" "+ c4 +" "+ c5 +" "+ c6 +" "+ c7 +" "+ c8 +nl
    #count = cF +cC +c1 +c2 +c3 +c4 +c5 +c6 +c7 +c8
    count = cells - ce - cM     ### Total - NotPlayed - Mines
return count

###--------------------------------------------------
