## Program:  MineSweeper - Button Screen
### Author:  Bert Mariani, Gal Zsolt ~ CalmoSoft ~
### Date:    2018-09-18
###
### TAB set to 3 Spaces
### aArray Letters: "."-Edge, e-empty, E-EmptyVisited, C-Chosen, M-Mine, B-Boom

load "stdlib.ring"
load "guilib.ring"


hSize   = 10 +2   ### Size of array, Display -2 smaller
vSize   = 10 +2   ### Size of array, Display -2 smaller
nMines  = 24      ### Number of Mines
nScore  = 0       ### Player Score
nClicks = 0		   ### Clicks played

h      = 0     ### H-coord of Cell
v      = 0     ### V-coord of Cell

moveX  = 200 moveY  = 100		### Open Window on Screen Position
sizeX  = 600 sizeY  = 600		### Size of Window

aArray          = null
aButton         = null
workWidget      = null 
LayoutButtonRow = null
 
C_Spacing  = 1
C_Spacing5 = 5

C_EmptyButtonStyle  = 'border-radius:4px; background-color:blue'
C_ButtonRedStyle    = 'border-radius:4px; color:black; background-color: red'
C_ButtonYellowStyle = 'border-radius:4px; color:black; background-color: yellow'
C_ButtonVioletStyle = 'border-radius:4px; color:black; background-color: violet'

C_ButtonWhiteStyle  = 'border-radius:4px; color:black; background-color: silver'
C_ButtonGreenStyle  = 'border-radius:4px; color:black; background-color: lime'
C_ButtonOrangeStyle = 'border-radius:4px; color:black; background-color: orange'
C_ButtonBlueStyle   = 'border-radius:4px; color:black; background-color: blue'


###=============================================================================

app = new qApp 
{

	DrawWidget()
	
    exec()
}
	
###---------------------



###=================================================
###=================================================

### FUNCTIONS 

###-------------------------------------------------
### Layout the Grid Square, Create the Arrays

Func DrawWidget()
See "DrawWidget: "+ nl
	 
	workWidget = new qWidget() 
	{
	
		aArray  = newList(hSize, vSize)	### Internal Array with Letters
		aButton = newlist(hSize, vSize)	### Button Array with Display Colors 
	
		PopulateArray()

		setWindowTitle('Game MinesSweeper')
		setStyleSheet('background-color:white')

		workHeight = workWidget.height()
		fontSize   = 8 + (workHeight / 100)
		
		  move(moveX, moveY)
		resize(sizeX, sizeY)
	 

		###----------------------------------------------
		### Title Top Row - Mines, Score, Time
			
				TitleMinesMsg = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:violet")
					setText("   Mines:   ")
				}
				
				TitleMines = new qLineEdit(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setText(""+ nMines)
				}				
	
				TitleClicksMsg = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:violet")
					setText("   Clicks:   ")
				}
				
				TitleClicks = new qLineEdit(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setText(""+ nClicks)
				}	

				TitleScoreMsg = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:violet")
					setText("   Score:   ")
				}
				
				TitleScore = new qLineEdit(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setText(""+ nScore)
				}	

				
      ###------------------------------------------------

		###-----------------------------------------------------------------------
		### QVBoxLayout lays out widgets in a vertical column, from top to bottom.
		
		LayoutButtonMain = new QVBoxLayout()				### Vertical
		
		LayoutButtonMain.setSpacing(C_Spacing)
		LayoutButtonMain.setContentsMargins(5,5,5,5)
		

			LayoutTitleRow = new QHBoxLayout()				### Horizontal - TOP ROW
			{
				setSpacing(C_Spacing5)
				setContentsMargins(0,0,0,0)
			}
				
			LayoutTitleRow.AddWidget(TitleMinesMsg)	
			LayoutTitleRow.AddWidget(TitleMines)		
			LayoutTitleRow.AddWidget(TitleClicksMsg)
			LayoutTitleRow.AddWidget(TitleClicks)
			LayoutTitleRow.AddWidget(TitleScoreMsg)
			LayoutTitleRow.AddWidget(TitleScore)	
							
			LayoutButtonMain.AddLayout(LayoutTitleRow)	### Layout - Add  TITLE-ROW on TOP
			
		###----------------------------------------------
		### Button Rows 

		LayoutButtonRow = list(hSize)		  
			for Row = 2 to hSize -1
			
			    ###-----------------------------------------------------------------------
			    ### QHBoxLayout lays out widgets in a horizontal row, from left to right
				
				#See "Row: "+ Row +nl
				LayoutButtonRow[Row] = new QHBoxLayout()	### Horizontal
				{
					setSpacing(C_Spacing)
					setContentsmargins(0,0,0,0)
				}
			   
			   for Col = 2 to vSize -1
					aButton[Row][Col] = new QPushButton(workWidget)	### Create Buttons
					{
						setStyleSheet(C_EmptyButtonStyle)
						setClickEvent("GetUserInput(" + string(Row) + "," + string(Col) + ")")  ### CLICK
						setSizePolicy(1,1)
					}
					
					LayoutButtonRow[Row].AddWidget(aButton[Row][Col])	### Widget - Add HORZ BOTTON
			   next
			   
			   LayoutButtonMain.AddLayout(LayoutButtonRow[Row])		### Layout - Add ROW of BUTTONS
			next

			###-------------------------------------------------
			###-------------------------------------------------
			### Bottom Row

				LayoutDataRow = new QHBoxLayout()	### Horizontal
				{
					setSpacing(C_Spacing5)
					setContentsMargins(0,0,0,0)
				}
				
				BeginnerGame  = new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setStyleSheet("background-color:violet")
					setText(" Beginner ")
					setClickEvent("NewGameStart(1)")      
				}	

				IntermediateGame  = new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setStyleSheet("background-color:violet")
					setText(" Intermediate ")
					setClickEvent("NewGameStart(2)")      
				}

				ExpertGame  = new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setStyleSheet("background-color:violet")
					setText(" Expert ")
					setClickEvent("NewGameStart(3)")      
				}				


			LayoutDataRow.AddWidget(BeginnerGame)	
			LayoutDataRow.AddWidget(IntermediateGame)
			LayoutDataRow.AddWidget(ExpertGame)

			LayoutButtonMain.AddLayout(LayoutDataRow)			### Layout - Add BOTTOM ROW
			
			###-------------------------------------------------
			###-------------------------------------------------			
			
		setLayout(LayoutButtonMain)

###DEBUG TEST
TitleScore.setText("xyz") +nl
SEE "DEBUG TitleScore: "+ TitleScore.text() +nl

		show()
    }

return

###-----------------------------------------------------------
### NewGameStart - Read Row Col Mines values, Score reset 
### Level L: 1-Beginner, 2-Intermediate, 3-Expert, 4-Custom

Func NewGameStart(L)
See "NewGameStart: "+ nl

###DEBUG TEST
workWidget.TitleScore.setText("abc") +nl
SEE "DEBUG TitleScore: "+ workWidget.TitleScore.text() +nl

 		
		nClicks = 0
		nScore  = 0

		if  L = 1
		 		hSize = 12  vSize = 12  nMines  = 24
		but L = 2
		 		hSize = 22  vSize = 22  nMines  = 96
		but L = 3
		 		hSize = 42  vSize = 42  nMines  = 384
		ok

	workWidget.Close()
	DrawWidget()
	
return


###------------------------------------------------
### Populate Internal Array and Mines

Func PopulateArray()
See "PopulateArray: "+ nl

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
			aButton[h][v] { setStyleSheet(C_ButtonGreenStyle) setText("C") }	
			
			nClicks++
			#TitleClicks.setText("99")
			
			CheckCellChosen(h,v)		
			nScore = CountCellsOpened()

         See "Score Clicks: "+ nClicks +"-"+ nScore +nl
			#workWidget.TitleScore.setText(""+ nScore)	
	
		ok

		if aArray[h][v] = 'M'       ### M-Mine
			### aArray[h][v] = 'B'      ### Boom !!! 
             aButton[h][v] { setStyleSheet(C_ButtonRedStyle) setText("M") }			
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
				
				aButton[horz][vert] { setStyleSheet(C_ButtonWhiteStyle) setText("E") }

                ### Count number of Mines around the E cell
                MineCount = CheckMines(horz,vert)
				
                if MineCount != 0   
                    aArray[horz][vert] = MineCount 
					 aButton[horz][vert] { setStyleSheet(C_ButtonYellowStyle) setText(""+ MineCount) }
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
				    aButton[horz][vert] { setStyleSheet(C_ButtonWhiteStyle) setText("E") }
										

                ### Count number of Mines around the E cell
                MineCount = CheckMines(horz,vert)
				
                if MineCount != 0   
                    aArray[horz][vert] = MineCount 
					     aButton[horz][vert] { setStyleSheet(C_ButtonYellowStyle) setText(""+ MineCount) }					 
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
		next 
	next
	
	#SEE "Cells Opened: "+ ce +" "+ cM +" "+ cF +" "+ cC +" "+ c1 +" "+ c2 +" "+ c3 +" "+ c4 +" "+ c5 +" "+ c6 +" "+ c7 +" "+ c8 +nl
	
	count = cF +cC +c1 +c2 +c3 +c4 +c5 +c6 +c7 +c8
return count
	
###--------------------------------------------------
