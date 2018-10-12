## Program:  MineSweeper - Button Screen
### Author:  Bert Mariani, Gal Zsolt ~ CalmoSoft ~
### Date:    2018-09-18
###
### TAB set to 3 Spaces
### aArray Letters: "."-Edge, e-empty, E-EmptyVisited, C-Chosen, M-Mine, B-Boom

load "stdlib.ring"
load "guilib.ring"


hSize  = 15     ### Size of array, Display -2 smaller
vSize  = 15     ### Size of array, Display -2 smaller
nMines = 45     ### Number of Mines

h      = 0      ### H-coord of Cell
v      = 0      ### V-coord of Cell

aArray = newList(hSize, vSize)	### Internal Array with Letters
button = newlist(hSize, vSize)	### Button Array with Display Colors

C_SPACING  = 1

C_EmptyButtonStyle  = 'border-radius:8px; background-color:blue'
C_ButtonRedStyle    = 'border-radius:8px; color:black; background-color: red'
C_ButtonYellowStyle = 'border-radius:8px; color:black; background-color: yellow'
C_ButtonVioletStyle = 'border-radius:8px; color:black; background-color: violet'

C_ButtonWhiteStyle  = 'border-radius:8px; color:black; background-color: silver'
C_ButtonGreenStyle  = 'border-radius:8px; color:black; background-color: lime'
C_ButtonOrangeStyle = 'border-radius:8px; color:black; background-color: orange'

LayoutButtonRow = list(hSize)


app = new qApp {

	###------------------------------------------------
	### Populate array

	n = 1
	for v = 1 to vSize
		for h = 1 to hSize

			if h = 1 OR v = 1 or h = hSize OR v = vSize 
				aArray[h][v] = '.'  ### dot- Edges
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
	
	
	###------------------------------------------	
	
         StyleFusion()
         win = new qWidget() {
                  setWindowTitle('Game')
                    move(490,100)
                  resize(600,600)
                  setstylesheet('background-color:white')
				  
                  LayoutButtonMain = new QVBoxLayout()
                  LayoutButtonMain.setSpacing(C_Spacing)
                  LayoutButtonMain.setContentsMargins(5,5,5,5)
				  
                  for Row = 2 to hSize -1
                       LayoutButtonRow[Row] = new QHBoxLayout() {
                       setSpacing(C_Spacing)
                       setContentsmargins(0,0,0,0)
                       }
					   
                       for Col = 2 to vSize -1
                            button[Row][Col] = new QPushButton(win) {
                            setstylesheet(C_EmptyButtonStyle)
                            setclickevent("GetUserInput(" + string(Row) + "," + string(Col) + ")")  ### CLICK
                            setSizePolicy(1,1)
                            }
							
                            LayoutButtonRow[Row].AddWidget(button[Row][Col])
                       next
                       LayoutButtonMain.AddLayout(LayoutButtonRow[Row])
                  next
                  setLayout(LayoutButtonMain)
                  show()
         }
        exec()
         }

###=================================================
###=================================================

### FUNCTIONS 

###-------------------------------------
### Get user to choose cell Format 2-4

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

	###-----------------------------------------------
	### START GAME !!!
	### Get user to choose cell Horz-Vert

		
		if aArray[h][v] = 'e'       ### e-Empty
			aArray[h][v] = 'C'      ### C-Chosen
			button[h][v] { setstylesheet(C_ButtonGreenStyle) settext("C") }	
			CheckCellChosen(h,v)
		ok

		if aArray[h][v] = 'M'       ### M-Mine
			### aArray[h][v] = 'B'      ### Boom !!! 
         button[h][v] { setstylesheet(C_ButtonRedStyle) settext("M") }			
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
				
				button[horz][vert] { setstylesheet(C_ButtonWhiteStyle) settext("E") }

                ### Count number of Mines around the E cell
                MineCount = CheckMines(horz,vert)
				
                if MineCount != 0   
                    aArray[horz][vert] = MineCount 
					 button[horz][vert] { setstylesheet(C_ButtonYellowStyle) settext(""+ MineCount) }
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
				    button[horz][vert] { setstylesheet(C_ButtonWhiteStyle) settext("E") }

                ### Count number of Mines around the E cell
                MineCount = CheckMines(horz,vert)
				
                if MineCount != 0   
                    aArray[horz][vert] = MineCount 
					     button[horz][vert] { setstylesheet(C_ButtonYellowStyle) settext(""+ MineCount) }
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



	
