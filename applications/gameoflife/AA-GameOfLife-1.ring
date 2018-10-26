### Program: Game Of life
### Author:	 Bert Mariani
### Date:	 2018-10-22
###
### TAB set to 3 Spaces
### 
###------------------------------------------------------------------------------
# The RULES
# For a space that is 'populated':
# 	Each cell with one or no neighbors dies, as if by solitude.
# 	Each cell with four or more neighbors dies, as if by overpopulation.
# 	Each cell with two or three neighbors survives.
#
# For a space that is 'empty' or 'unpopulated'
# 	Each cell with three neighbors becomes populated. 
###-----------------------------------------------------------------------------

load "stdlib.ring"
load "guilib.ring"

PatternType = "Glider"		### 1,2
timeDelay 	= 1				### 1=millisecs  1000=second
cellSize    = 75			### Max  34, 67, 100
flagStartOn	= False			### Start Button OFF - Flip On/Off
timerPopCount = 1			### MovesLabel

###---------------------------
### WINDOW SIZE, ARRAY SIZE

moveX  	= 200 moveY	= 100	### Open Window on Screen Position
sizeX  	= 800 sizeY	= 850	### Size of Window

hSize	= 38 		 		### Size of array, Display -2 smaller
vSize	= 47  				### Size of array, Display -2 smaller

h		= 0		 			### H-coord of Cell
v		= 0		 			### V-coord of Cell

###---------------------------------------------------------- 
### Global so other functions can access the workWidget items

aArray			= null
bArray          = null
aButton			= null
workWidget		= null
LayoutButtonRow = null
comboPatternType = null
oTimerMan		= null
StartButton 	= null
SliderSpeed 	= null
SliderSize  	= null
MovesLabel		= null
 
 
C_Spacing  = 1
C_Spacing0 = 0
C_Spacing5 = 5

C_ButtonEmptyStyle	= 'border-radius:1px; color:black; background-color: darkGray ; border-style: outset; border-width: 2px; border-radius: 2px; border-color: gray; '
C_ButtonWhiteStyle	= 'border-radius:1px; color:black; background-color: white;		border-style: outset; border-width: 1px; border-radius: 2px; border-color: darkGray; '

C_ButtonCyanStyle	= 'border-radius:1px; color:black; background-color: cyan;		border-style: solid;  border-width: 2px; border-radius: 2px; border-color: darkgray; '		  
C_ButtonVioletStyle = 'border-radius:3px; color:black; background-color: violet;	border-style: outset; border-width: 1px; border-radius: 2px; border-color: darkGray; '
C_ButtonYellowStyle = 'border-radius:3px; color:black; background-color: Yellow;	border-style: outset; border-width: 1px; border-radius: 2px; border-color: darkGray; '


###=============================================================================
###=============================================================================
### The shortest app function you ever seen !
### The DrawWidget function does what is normally in this section

app = new qApp 
{
	DrawWidget()
	
	exec()
}
	
###---------------------



###=================================================
###=================================================

### FUNCTIONS 

###---------------------------------------------------------------------------
### Layout the Grid Square, Create the Arrays
### workWidget items need to be made Global. Mke available toother functions

Func DrawWidget()
#See "DrawWidget: "+ nl
	 
	workWidget = new qWidget()				### Global definition for workWidget
	{
	
		aArray	= newList(hSize, vSize)		### Internal Array with Letters
		aButton = newlist(hSize, vSize)		### Button Array with Display Colors 
	
		PopulateArray()						### With Pattern Type in ComboBox

		setWindowTitle('Game of Life')
		setStyleSheet('background-color:gray')

		workHeight = workWidget.height()
		fontSize   = 8 + (workHeight / 100)
		
		  move(moveX, moveY)
		resize(sizeX, sizeY)
	 

		###-----------------------------------------------------------------------
		### QVBoxLayout lays out widgets in a vertical column, from top to bottom.
		
		LayoutButtonMain = new QVBoxLayout()				### Vertical
		
		LayoutButtonMain.setSpacing(C_Spacing)
		LayoutButtonMain.setContentsMargins(5,5,5,5)
		

			
		###----------------------------------------------
		### BUTTON ROWS

		LayoutButtonRow = list(hSize)		  
			for Row = 2 to hSize -1
			
				###-----------------------------------------------------------------------
				### QHBoxLayout lays out widgets in a horizontal row, from left to right
				
				###See "Row: "+ Row +nl
				LayoutButtonRow[Row] = new QHBoxLayout()	### Horizontal
				{
					setSpacing(C_Spacing0)
					setContentsmargins(0,0,0,0)
				}
			   
				for Col = 2 to vSize -1
					aButton[Row][Col] = new QPushButton(workWidget)	### Create Buttons
					{
						setStyleSheet(C_ButtonEmptyStyle)						
						setClickEvent("GetUserInput(" + string(Row) + "," + string(Col) + ")")	### GetUserInput CLICK ===>>>>
						setSizePolicy(1,1)
						
							###-------------------------------------------------
							### For Right Mouse Click - does NOT show depression
							myfilter = new qAllEvents(workWidget) 
							{
								setContextMenuEvent( "RightClickMouse(	" + string(Row) + "," + string(Col) + ")  " )  ### RIGHT CLICK CELL ===>>>>
							}
							installeventfilter(myfilter)						
						
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
				
				NextButton  = new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,50,0))
					setStyleSheet("background-color:White")
					setText(" Next ")
					setClickEvent("NextClick()")	  
				}	

				StartButton  = new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,50,0))
					setStyleSheet("background-color:White")
					setText(" Start ")
					setClickEvent("StartClick()")	  
				}

				

				###-------------------------------------------------------- 
				### Combo Box for Pattern Types
				### patternType = comboPatternType.currentText()

				comboPatternType = new QComboBox(workWidget) 
				{
					setStyleSheet("background-color:White")
					setFont(new qFont("Calibri",fontsize,50,0))
					aList = ["Clear","UserPattern","Glider","SmallExploder","Exploder","10CellRow","LightweightSpaceship", "Tumbler","GosperGliderGun"]
					for x in aList additem(x,0) next				
				}

				SpeedLabel = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,50,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:darkGray")
					setText(" Speed ")
				}	
				
				SliderSpeed = new qslider(workWidget) 
				{
					setorientation(Qt_Horizontal)
					setTickInterval(50)								
					setValue( 100 - (timeDelay / 10) )		    	### 1=millisec  1000=sec Flip Scale
					setValueChangedEvent("SliderSpeedMove()")

				}	

				###-----------------------------------
				### Timer Pops every 1-1000 millisecond

				oTimerMan = new qTimer(workWidget)
				{
					setInterval(timeDelay)					### 1=millisec  1000=sec
					setTimeoutEvent("TimerManPlay()" )  	### >>>== Function
					###start()
					stop()
				}
				

				SizeLabel = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,50,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:darkGray")
					setText(" Size ")
				}
				
				SliderSize = new qslider(workWidget) 
				{
					setorientation(Qt_Horizontal)				
					setMinimum(40)
					setMaximum(60)	
					setValue(cellSize )	    	### 50 / 100 = 0.5 sec delay between moves
					setValueChangedEvent("SliderSizeMove()")

				}	

				MovesLabel = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:darkGray")
					setText("     "+ 0 +"     ")
				}					

			LayoutDataRow.AddWidget(comboPatternType)
			LayoutDataRow.AddWidget(NextButton)	
			LayoutDataRow.AddWidget(StartButton)
			LayoutDataRow.AddWidget(SpeedLabel)
			LayoutDataRow.AddWidget(SliderSpeed)
			LayoutDataRow.AddWidget(SizeLabel)
			LayoutDataRow.AddWidget(SliderSize)
			LayoutDataRow.AddWidget(MovesLabel)
			

			LayoutButtonMain.AddLayout(LayoutDataRow)			### Layout - Add BOTTOM ROW
			
			###-------------------------------------------------
			###-------------------------------------------------			
			
		setLayout(LayoutButtonMain)
		

		show()
	}

return
###===============================================
###===============================================


###-----------------------------------------------
### START GAME !!!
### USER sets Cell Pattern to play

Func GetUserInput(Row, Col)	
#See "GetUserInput: "+ Row +"-"+ Col +nl
	
	h = 0+ Row		### convert to number
	v = 0+ Col

	aArray[h][v] = 'F'	### e - Empty
	aButton[h][v] { setStyleSheet(C_ButtonYellowStyle) } 
	
	### Play(h,v)
	
return

		
###-----------------------------------------------------------
### NewGameStart - 
###
### hSize	=  38 ### 34 +2	  ### Size of array, Display -2 smaller
### vSize	=  46 ### 46 +2	  ### Size of array, Display -2 smaller

Func NewGameStart(L)
#See "NewGameStart: "+ nl

	workWidget.Close()
	DrawWidget()
	
	#See "NewGame CellSize: "+ hSize +"-"+ vSize +nl
		
return


###------------------------------------------------
### Populate Internal Array with 'e'
### Called by DrawWidget()

Func PopulateArray()
#See "PopulateArray: "+ nl


	for v = 1 to vSize
		for h = 1 to hSize

			if h = 1 OR v = 1 or h = hSize OR v = vSize 
				aArray[h][v] = '.'	### dot - Edges
			else	
				aArray[h][v] = 'e'	### e - Empty
			ok
		next
	next

	###-------------------------------------------------
	### Copt to working array - Use to determine flips
	
	bArray = aArray
	
	### patternType = comboPatternType.currentText()
	### See "PatternB: "+ patternType +nl
	### Pattern(patternType)
		
return





###-----------------------------------------
		 
Func Play(h,v)
#See "Play: "+ h +"-"+ v +nl

	# Find 8 Neighbours for each Cell
	bArray = aArray
		for v = 2 to vSize -1
			for h = 2 to hSize -1
			
					Count = 0
					for i = -1 to 1
						for j = -1 to 1
							if bArray[h+i][v+j] = 'F'
								Count++
							ok
						next
					next
										
					###See "HV: "+ h +"-"+ v +" C: "+ Count +" ab: "+ aArray[h][v]  + bArray[h][v]+nl					
					
					if bArray[h][v] = 'F'  AND Count < 2 +1   					### Self+1  0,1
						aArray[h][v] = 'e'	### Dies
					ok
					
					if bArray[h][v] = 'F'  AND Count > 3 +1  					### Self+1  4,5,6,7
						aArray[h][v] = 'e'	### Dies
					ok
					
					if bArray[h][v] = 'F'	AND (Count = 2 +1 OR Count = 3 +1)	### Self+1 2,3
						aArray[h][v] = 'F'	### Survives  
					ok
					
					if bArray[h][v] = 'e'  AND Count = 3   ### 2,3
						aArray[h][v] = 'F'	### Comes to Life
					ok
					
			next
		next		
	
	
	
	for v = 2 to vSize -1
		for h = 2 to hSize -1
		
			
			
			if aArray[h][v] = 'F'
				aButton[h][v] { setStyleSheet(C_ButtonYellowStyle) } 
			else
				aButton[h][v] { setStyleSheet(C_ButtonEmptyStyle) } 
			ok
			
			### if aArray[h][v] = 'e' AND bArray[h][v] = 'F'	
			### 	 aButton[h][v] { setStyleSheet(C_ButtonCyanStyle) } 
			### ok
			### See "|"+ aArray[h][v] + bArray[h][v] +" "
			
		next
		###See nl
	next		

Return

###-----------------------------------------------

Func NextClick()

	###------------------------
	### Play Pattern Selected
	
	oTimerMan.stop()
	
	patternType = comboPatternType.currentText()
	#See "PatternNext: "+ patternType +nl
	Pattern(patternType)
	
	Play(1,1)

return

###-----------------------------------------------

Func StartClick()

	###------------------------
	### Play Pattern Selected

	patternType = comboPatternType.currentText()
	#See "PatternStart: "+ patternType +nl
	Pattern(patternType)
	
	###-----------------------------
	### Start Timer - Flip ON/OFF
	
	if flagStartOn = False						### OFF ?
		flagStartOn = True						
		StartButton.setText(" Stop  ")
		oTimerMan.start()						### TIMER start
	else
		flagStartOn = False						
		oTimerMan.stop()
		StartButton.setText(" Start ")			### TIMER stop
	ok
	
	timerPopCount = 0

return

###-----------------------------------------------
### Timer Pops - Play a Move
### Simulates player move

Func TimerManPlay()

	if flagStartOn = True
		timerPopCount++
	else
		timerPopCount = 0
	ok
	
	MovesLabel.setText("     "+ timerPopCount +"     ")	
	Play(1,1)
	
return

###-----------------------------------------------
### Increase Speed Slider
### setValue(100 - timeDelay )	

Func SliderSpeedMove()

	sliderPos = SliderSpeed.value()     	### 0 - 100 
	
	timeDelay  = 1000 - (sliderPos * 10)    ### Slow 1-100 Fast  => 10-1000 millesec - FLIP
	oTimerMan.setInterval(timeDelay)		### 1000 = 1 sec
	
	See "timeDelay: "+ timeDelay +nl
	
 
return

###-----------------------------------------------
### Size/Number of Cells to display on Release

Func SliderSizeMove()
	
	cellSize = SliderSize.value()  		### 0 - 100  40--50--60
	
	if cellSize < 45  
		L = 1   hSize = 18	vSize = 22	
	elseif cellSize < 55
		L = 2   hSize = 28	vSize = 24	
	else
		L = 3   hSize = 38	vSize = 46	
	ok

	See "cellSize: "+ cellSize +nl
		
	workWidget.Close()	
	DrawWidget()
	
	
return


###------------------------------------------
### Message Box - Lost or Won

Func MsgBox(Msg)

	mb = new qMessageBox(workWidget) 
			{
				setFont(new qFont("Courier",12,50,0))
				setWindowTitle('Minesweeper Game')
				setStyleSheet(C_ButtonYellowStyle)
				setText(Msg)
				setStandardButtons(QMessageBox_OK) 
				result = exec()	### Needed to show Popup window
			}

###-------------------------------------


###--------------------------------------------------
### RightMouse Click on PushButton - 

Func RightClickMouse(Row,Col)
See "RightClick: "+ Row +"-"+ Col +nl

	aButton[Row][Col] { setStyleSheet(C_ButtonCyanStyle) }
	
	
return

###---------------------------
### Clear Cells -- PATTERN

Func PatternClear()
	for v = 2 to vSize -1
		for h = 2 to hSize -1	
				aArray[h][v] = 'e'	### e - Empty
				aButton[h][v] { setStyleSheet(C_ButtonEmptyStyle)  }
		next
	next
return	

###-------------------------------------------------------------
### Set Initial Pattern
### 	Visible Cells start at H=2 and V=2
###
###		patternType = comboPatternType.currentText()
###		Pattern(patternType)
###
###		["Clear","Glider","SmallExploder","Exploder","10CellRow","LightweightSpaceship", "Tumbler","GosperGliderGun"]
	
Func Pattern(patternType)

if patternType = "Clear"
		PatternClear()
		### NewGameStart(3)
	return
ok	

if patternType = "Glider"
		h = (hSize -2 ) / 4 
		v = (vSize -2 ) / 4			
		aArray[h+0][v+1] = 'F' ; 	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+1][v+2] = 'F' ;    aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)  }	
		
		aArray[h+2][v+0] = 'F' ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+2][v+1] = 'F' ;	aButton[h+2][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+2][v+2] = 'F' ;	aButton[h+2][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
	return
ok	
			
					
			
if patternType = "SmallExploder"
		###-------------------------
		h = (hSize -2 ) / 2
		v = (vSize -2 ) / 2	
		
		aArray[h+0][v+1] = 'F' ; 	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		                                   
		aArray[h+1][v+0] = 'F' ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+1] = 'F' ;    aButton[h+1][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+2] = 'F' ;    aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
	                                       
		aArray[h+2][v+0] = 'F' ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+2][v+2] = 'F' ;	aButton[h+2][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		                                   
		aArray[h+3][v+1] = 'F' ;	aButton[h+3][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
	return		
ok		

if patternType = "Exploder"
		h = (hSize -2 ) / 2 
		v = (vSize -2 ) / 2	
		
		aArray[h+0][v+0] = 'F' ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+2] = 'F' ;    aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+4] = 'F' ;    aButton[h+0][v+4] { setStyleSheet(C_ButtonYellowStyle)  }
                                           
		aArray[h+1][v+0] = 'F' ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+1][v+4] = 'F' ;	aButton[h+1][v+4] { setStyleSheet(C_ButtonYellowStyle)  }
                                           
		aArray[h+2][v+0] = 'F' ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+2][v+4] = 'F' ;	aButton[h+2][v+4] { setStyleSheet(C_ButtonYellowStyle)  }		
	                                       
		aArray[h+3][v+0] = 'F' ;	aButton[h+3][v+0] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+3][v+4] = 'F' ;	aButton[h+3][v+4] { setStyleSheet(C_ButtonYellowStyle)  }
		                                   
		aArray[h+4][v+0] = 'F' ;	aButton[h+4][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+4][v+2] = 'F' ;    aButton[h+4][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+4][v+4] = 'F' ;    aButton[h+4][v+4] { setStyleSheet(C_ButtonYellowStyle)  }		
		
	return		
ok

if patternType = "10CellRow"
		h = (hSize -2 ) / 2  
		v = (vSize -2 ) / 2 -5	

		aArray[h+0][v+0] = 'F' ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+1] = 'F' ;    aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+2] = 'F' ;    aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+0][v+3] = 'F' ;	aButton[h+0][v+3] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+0][v+4] = 'F' ;	aButton[h+0][v+4] { setStyleSheet(C_ButtonYellowStyle)  }                                         
		aArray[h+0][v+5] = 'F' ;	aButton[h+0][v+5] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+0][v+6] = 'F' ;	aButton[h+0][v+6] { setStyleSheet(C_ButtonYellowStyle)  }		                                       
		aArray[h+0][v+7] = 'F' ;	aButton[h+0][v+7] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+0][v+8] = 'F' ;	aButton[h+0][v+8] { setStyleSheet(C_ButtonYellowStyle)  }		                                   
		aArray[h+0][v+9] = 'F' ;	aButton[h+0][v+9] { setStyleSheet(C_ButtonYellowStyle)  }
	return
ok		

if patternType = "LightweightSpaceship"
		h = (hSize -2 ) / 2 
		v = (vSize -2 ) / 2	

		aArray[h+0][v+1] = 'F' ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+2] = 'F' ;    aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+3] = 'F' ;    aButton[h+0][v+3] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+0][v+4] = 'F' ;	aButton[h+0][v+4] { setStyleSheet(C_ButtonYellowStyle)  }	
		                                   
		aArray[h+1][v+0] = 'F' ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                         
		aArray[h+1][v+4] = 'F' ;	aButton[h+1][v+4] { setStyleSheet(C_ButtonYellowStyle)  }	
		                                   
		aArray[h+2][v+4] = 'F' ;	aButton[h+2][v+4] { setStyleSheet(C_ButtonYellowStyle)  }		                                       
		                                   
		aArray[h+3][v+0] = 'F' ;	aButton[h+3][v+0] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+3][v+3] = 'F' ;	aButton[h+3][v+3] { setStyleSheet(C_ButtonYellowStyle)  }	
	return		
		
ok	

if patternType = "Tumbler"
		h = (hSize -2 ) / 2 
		v = (vSize -2 ) / 2	
		
		aArray[h+0][v+1] = 'F' ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+2] = 'F' ;    aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+4] = 'F' ;    aButton[h+0][v+4] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+0][v+5] = 'F' ;	aButton[h+0][v+5] { setStyleSheet(C_ButtonYellowStyle)  }	
		                                   
		aArray[h+1][v+1] = 'F' ;	aButton[h+1][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+2] = 'F' ;    aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+4] = 'F' ;    aButton[h+1][v+4] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+1][v+5] = 'F' ;	aButton[h+1][v+5] { setStyleSheet(C_ButtonYellowStyle)  }	
                                           
		aArray[h+2][v+2] = 'F' ;	aButton[h+2][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+2][v+4] = 'F' ;    aButton[h+2][v+4] { setStyleSheet(C_ButtonYellowStyle)  }
	                                       
                                           
		aArray[h+3][v+0] = 'F' ;	aButton[h+3][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+3][v+2] = 'F' ;    aButton[h+3][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+3][v+4] = 'F' ;    aButton[h+3][v+4] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+3][v+6] = 'F' ;	aButton[h+3][v+6] { setStyleSheet(C_ButtonYellowStyle)  }	
                                           
		aArray[h+4][v+0] = 'F' ;	aButton[h+4][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+4][v+2] = 'F' ;    aButton[h+4][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+4][v+4] = 'F' ;    aButton[h+4][v+4] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+4][v+6] = 'F' ;	aButton[h+4][v+6] { setStyleSheet(C_ButtonYellowStyle)  }	
                                           
		aArray[h+5][v+0] = 'F' ;	aButton[h+5][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+5][v+1] = 'F' ;    aButton[h+5][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+5][v+5] = 'F' ;    aButton[h+5][v+5] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+5][v+6] = 'F' ;	aButton[h+5][v+6] { setStyleSheet(C_ButtonYellowStyle)  }
	return		
		
ok

if patternType = "GosperGliderGun"
		horz = (hSize -2 ) / 4 
		vert = (vSize -2 ) / 6
		
		h = horz+2 	v = vert+0	### A
		#SEE "A:"+ h +"-"+ v +nl
		aArray[h+0][v+0] = 'F' ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+1] = 'F' ;    aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+0] = 'F' ;    aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+1][v+1] = 'F' ;	aButton[h+1][v+1] { setStyleSheet(C_ButtonYellowStyle)  }		

		h = horz+2  v = vert+8	### B
		#SEE "B:"+ h +"-"+ v +nl
		aArray[h+0][v+1] = 'F' ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+2] = 'F' ;    aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+0] = 'F' ;    aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+1][v+2] = 'F' ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+2][v+0] = 'F' ;    aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+2][v+1] = 'F' ;	aButton[h+2][v+1] { setStyleSheet(C_ButtonYellowStyle)  }		

		h = horz+4  v = vert+16	### C
		#SEE "C:"+ h +"-"+ v +nl
		aArray[h+0][v+0] = 'F' ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+1] = 'F' ;    aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+0] = 'F' ;    aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+1][v+2] = 'F' ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+2][v+0] = 'F' ;    aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                      
	

		h = horz+0  v = vert+22	### D
		#SEE "D:"+ h +"-"+ v +nl
		aArray[h+0][v+1] = 'F' ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+2] = 'F' ;    aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+0] = 'F' ;    aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+1][v+2] = 'F' ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+2][v+0] = 'F' ;    aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+2][v+1] = 'F' ;	aButton[h+2][v+1] { setStyleSheet(C_ButtonYellowStyle)  }		

		h = horz+0  v = vert+34 ### E
		#SEE "E:"+ h +"-"+ v +nl
		aArray[h+0][v+0] = 'F' ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+1] = 'F' ;    aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+0] = 'F' ;    aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+1][v+1] = 'F' ;	aButton[h+1][v+1] { setStyleSheet(C_ButtonYellowStyle)  }			

		h = horz+7  v = vert+35	### F
		#SEE "F:"+ h +"-"+ v +nl
		aArray[h+0][v+0] = 'F' ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+1] = 'F' ;    aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+1][v+0] = 'F' ;    aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+1][v+2] = 'F' ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+2][v+0] = 'F' ;    aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)  }       

		h = horz+12  v = vert+24	### G
		#SEE "G:"+ h +"-"+ v +nl
		aArray[h+0][v+0] = 'F' ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+1] = 'F' ;    aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)  }
		aArray[h+0][v+2] = 'F' ;    aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)  }                                      
		aArray[h+1][v+0] = 'F' ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)  }	
		aArray[h+2][v+1] = 'F' ;    aButton[h+2][v+1] { setStyleSheet(C_ButtonYellowStyle)  }  
	return 		
		
ok 

return
###-------------------------------
