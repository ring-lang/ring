### Program: Game Of life
### Author:	 Bert Mariani
### Date:	 2018-10-22
###
### TAB set to 3 Spaces
### 
###------------------------------------------------------------------------------
# The RULES
# For a space that is 'populated':
#	Each cell with one or no neighbors dies, as if by solitude.
#	Each cell with four or more neighbors dies, as if by overpopulation.
#	Each cell with two or three neighbors survives.
#
# For a space that is 'empty' or 'unpopulated'
#	Each cell with three neighbors becomes populated. 
###-----------------------------------------------------------------------------

load "stdlibcore.ring"
load "lightguilib.ring"

PatternType = "Glider"		### 1,2
timeDelay	= 200		    ### 1=millisecs	 1000=second
cellSize	= 75			### Max	 34, 67, 100
FlagStartOn	= False			### Start Button OFF - Flip On/Off
timerPopCount	= 1			### MovesLabel
FlagFirstClick	= 1			### Next Click - manual
currentPattern  = "A"		### Used for Stop/Start of same pattern
PAddNext		= 1			### pArray added Cells - New Length

###---------------------------
### WINDOW SIZE, ARRAY SIZE

sizeX	= 800 sizeY	= 600	### Size of Window

hSize	= 40				### Size of array, Display -2 -2 smaller left-right
vSize	= 40				### Size of array, Display -2 -2 smaller top-bottom

h		= 0					### Horizontal coordinate of Cell
v		= 0					### Vertical coordinate of Cell

###---------------------------------------------------------- 
### Global so other functions can access the workWidget items

aArray			= null
bArray			= null
aButton			= null
workWidget		= null
LayoutButtonRow = null
comboPatternType = null
TimerMan		= null
StartButton		= null
SliderSpeed		= null
SliderSize		= null
MovesLabel		= null
StartButton     = null
StopButton      = null
 
 
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

	aArray	= list(hSize, vSize)		### Internal Array with Letters
	bArray	= list(hSize, vSize)		### Working Array to check Live Cells, Extinguished Cells
	pArray	= list(hSize * vSize, 2)	### Populated Array - Cell-Soord ["11"][33"] 
	qArray	= list(hSize * vSize, 2)	### Populated Array - Cell-Soord ["11"][33"]
		
	aButton = list(hSize, vSize)		### Button Array with Display Colors

	DrawWidget()
	
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
#See "DrawWidget: "+ nl
	 
	workWidget = new qWidget()				### Global definition for workWidget
	{
	
		PopulateArray()						### With Pattern Type in ComboBox
		setWinIcon(self,"gameoflife.png")
		setWindowTitle('Game of Life')
		setStyleSheet('background-color:gray')

		workHeight = workWidget.height()
		fontSize   = 8 + (workHeight / 100)
		
		resize(sizeX, sizeY)
	 

		###-----------------------------------------------------------------------
		### QVBoxLayout lays out widgets in a vertical column, from top to bottom.
		
		LayoutButtonMain = new QVBoxLayout()				### Vertical
		
		LayoutButtonMain.setSpacing(C_Spacing)
		LayoutButtonMain.setContentsMargins(5,5,5,5)
		

			
		###----------------------------------------------
		### BUTTON ROWS

		LayoutButtonRow = list(hSize)		  
			for Row = 3 to hSize -3
			
				###-----------------------------------------------------------------------
				### QHBoxLayout lays out widgets in a horizontal row, from left to right
				
				###See "Row: "+ Row +nl
				LayoutButtonRow[Row] = new QHBoxLayout()	### Horizontal
				{
					setSpacing(C_Spacing0)
					setContentsmargins(0,0,0,0)
				}
			   
				for Col = 3 to vSize -3
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
					
					LayoutButtonRow[Row].AddWidget(aButton[Row][Col])	### Widget - Add HORIZONTAL BUTTON
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
				
				ClearButton	= new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,50,0))
					setStyleSheet("background-color:White")
					setText(" Load ")
					setClickEvent("LoadClick()")	  
				}	
				
				StopButton	 = new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,50,0))
					setStyleSheet("background-color: rgb(255,102,102)")
					setText(" Stop ")
					setClickEvent("StopClick()")	  
				}

				StartButton	 = new QPushButton(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,50,0))
					setStyleSheet("background-color: White")
					setText(" Start ")
					setClickEvent("StartClick()")	  
				}

				

				###-------------------------------------------------------- 
				### Combo Box for Pattern Types
				### patternType = comboPatternType.currentText()

				comboPatternType = new QComboBox(workWidget) 
				{
					setStyleSheet("color:black;background-color:White")
					setFont(new qFont("Calibri",fontsize,50,0))
					aList = ["Clear","UserPattern","Glider","SmallExploder","Exploder","10CellRow","LightweightSpaceship","Tumbler","GosperGliderGun"]
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
					setValue( 100 - (timeDelay / 10) )				### 1=millisec	1000=sec Flip Scale
					setValueChangedEvent("SliderSpeedMove()")

				}	

				###-----------------------------------
				### Timer Pops every 1-1000 millisecond

				TimerMan = new qTimer(workWidget)
				{
					setInterval(timeDelay)					### 1=millisec	1000=sec
					setTimeoutEvent("TimerManPlay()" )		### >>>== Function
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
					setValue(cellSize )			### 50 / 100 = 0.5 sec delay between moves
					setValueChangedEvent("SliderSizeMove()")

				}	

				MovesLabel = new qLabel(workWidget) 
				{
					setFont(new qFont("Calibri",fontsize,100,0))
					setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
					setStyleSheet("background-color:darkGray")
					setText("	  "+ 0 +"	  ")
				}					

			LayoutDataRow.AddWidget(comboPatternType)
			LayoutDataRow.AddWidget(ClearButton)
			LayoutDataRow.AddWidget(StopButton)			
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
	
	h = 0+ Row		### Convert to Number
	v = 0+ Col

	aArray[h][v] = 1	### F-fill
	aButton[h][v] { setStyleSheet(C_ButtonYellowStyle) } 
	SEE "UserButton: "+ h +"-"+ v +nl
	
return

		
###-----------------------------------------------------------
### NewGameStart - 
###
### hSize	=  38 ### 34 +4	  ### Size of array, Display -4 smaller
### vSize	=  46 ### 46 +4	  ### Size of array, Display -4 smaller

Func NewGameStart(L)
#See "NewGameStart: "+ nl

	workWidget.Close()
	DrawWidget()
	
	#See "NewGame CellSize: "+ hSize +"-"+ vSize +nl
		
return


###----------------------------------------------------------
### Populate Internal Array with 0=Empty, "."=Border
### Called by DrawWidget()

Func PopulateArray()
#See "PopulateArray: "+ nl

	p = 1
	for v = 1 to vSize
		for h = 1 to hSize
			aArray[h][v] = 0	### e - Empty
			bArray[h][v] = 0	### e - Empty
			pArray[p][1] = 0	### e - Empty
			pArray[p][2] = 0
			qArray[p][1] = 0	### e - Empty
			qArray[p][2] = 0		
			
			p++
		next
	next
	
return

###-----------------------------------------
##3 PLAY a MOVE CYCLE
	 
Func Play(h,v)
#See "Play: "+ h +"-"+ v +nl


	###------------------------------------
	### Make copy of array, Work with copy
	### Find 8 Neighbours for each Cell
	### Copy current aArray to Working bArray
	
	bArray = aArray					
	
		###---------------------------------
		### Track only the Active Cells.  
		### 2 Border Cells on each of 4 sides NOT shown
		
		if FlagFirstClick = 1
		#See "Play FirstClick: "+ FlagFirstClick +nl
			p = 1
			for h = 3 to hSize -3
				for v = 3 to vSize -3			
					if aArray[h][v] = 1
						pArray[p][1] = h 
						pArray[p][2] = v								
						p++
					ok
				next
			next
			FlagFirstClick = 0
		else
			
			###--------------------------------------
			### Copy Last qArray to pArray for Work
			### Increase Speed for subsequent steps
		
			#See "Play FirstClick: "+ FlagFirstClick +nl
			p = 1  
			q  = 1
			while qArray[q][1] !=0
				pArray[p][1] = qArray[q][1] 
				pArray[p][2] = qArray[q][2]		
				q++
				p++
			end
		ok
		
		Plength  = p -1		### End of Current List
		PAddNext = p		### Add New Live Cell
	
	
		###--------------------------------------------------------
		### Find Neighbours. Come to life, Survives, Die.
		
		for p = 1 to Plength
			h = pArray[p][1]
			v = pArray[p][2]
			
			Count = bArray[h-1][v-1] + bArray[h-1][v] + bArray[h-1][v+1] +
					bArray[h][v-1]					  + bArray[h][v+1] +
					bArray[h+1][v-1] + bArray[h+1][v] + bArray[h+1][v+1] ;
						
	
			###---------------------------
			### Check Live Cells
			
			if bArray[h][v] = 1	 AND Count < 2			### Dies				
				aArray[h][v] = 0						
				aButton[h][v] { setStyleSheet(C_ButtonEmptyStyle) }
				
				pArray[p][1] = 0
				pArray[p][2] = 0
			ok
			
			if bArray[h][v] = 1	 AND Count > 3			### Dies				
				aArray[h][v] = 0						
				aButton[h][v] { setStyleSheet(C_ButtonEmptyStyle) }
				
				pArray[p][1] = 0
				pArray[p][2] = 0
			ok
			
			if bArray[h][v] = 1	AND (Count = 2	OR Count = 3 )	### Survives
				aArray[h][v] = 1						
				aButton[h][v] { setStyleSheet(C_ButtonYellowStyle) }
			ok
			
			###--------------------------------------------
			### Check Empty Cells around Live Cells
			### 2 Border Cells on each of 4 sides are 0's
			 
			for he = h-1 to h+1
				for ve = v-1 to v+1
			
					if bArray[he][ve] = 0												### Empty Cell
					
						Count = bArray[he-1][ve-1] + bArray[he-1][ve] + bArray[he-1][ve+1] +
								bArray[he][ve-1]					  + bArray[he][ve+1] +
								bArray[he+1][ve-1] + bArray[he+1][ve] + bArray[he+1][ve+1] ;
																	
						if bArray[he][ve] = 0	 AND Count = 3							### LIFE		
							if he < hsize -2 AND ve < vSize -2 AND he > 2 AND ve > 2	### Inside Boundary
							
								if aArray[he][ve] != 1									### Already Came to Life - Dup
									aArray[he][ve] = 1									### Comes to Life at Count 3
									aButton[he][ve] { setStyleSheet(C_ButtonYellowStyle) } 
									
									pArray[PAddNext][1] = he
									pArray[PAddNext][2] = ve
									PAddNext++
								ok
							ok	

						ok
					ok		
					
				next	
			next

		next		
	
		###------------------------------------------------------
		### Scan pArray and Copy to qArray -- for Speed 
			
			###-----------------------------
			### Copy P to Q array. Drop 0-0
			
			#See nl
			q = 1
			for p = 1 to PAddNext
				if pArray[p][1] != 0
					qArray[q][1] = pArray[p][1]
					qArray[q][2] = pArray[p][2]					
					q++
				ok
			next
						
			qArray[q][1] = 0
			qArray[q][2] = 0
			#See "qAdd: "+ q +" "+ qArray[q][1] +"-"+ qArray[q][2] +nl

Return

###---------------------------
### Clear Cells -- PATTERN

Func LoadPatternClear()
	
	p = 1
	for h = 1 to hSize 
		for v = 1 to vSize 
				aArray[h][v] = 0	### e - Empty
				
				if h < hsize -2 AND v < vSize -2 AND h > 2 AND v > 2
					aButton[h][v] { setStyleSheet(C_ButtonEmptyStyle)  }
				ok
				
				pArray[p][1] = 0  pArray[p][2] = 0
				qArray[p][1] = 0  qArray[p][2] = 0
				
		next
	next
	
	#Play(1,1)	### Play 1 move
	
return	

###-----------------------------------------------

Func LoadClick()

	###------------------------
	### Play LoadPattern Selected


	TimerMan.stop()
	
	#LoadPatternClear()
	
	patternType = comboPatternType.currentText()
	
	if patternType != "UserPattern"
		LoadPatternClear()
		LoadPattern(patternType)
	else
		See "Load: "+ patternType +nl
	
	ok
	
	FlagFirstClick = 1
	
	#Play(1,1)	
	#TimerMan.start()


return

###----------------------------------------------- 

Func StopClick()

	TimerMan.stop()
	
	 StopButton.setStyleSheet("background-color: rgb(255,102,102)")	
	StartButton.setStyleSheet("background-color: White")	
	 
	
return

###-----------------------------------------------

Func StartClick()

	TimerMan.stop()
	timerPopCount = 0
	
	StartButton.setStyleSheet("background-color: rgb(51,255,51)")
	 StopButton.setStyleSheet("background-color: White")			
	
	TimerMan.start()

return

###-----------------------------------------------
### Timer Pops - Play a Move
### Simulates player move

Func TimerManPlay()

	TimerMan.stop()
	
	timerPopCount++
	MovesLabel.setText("	 "+ timerPopCount +"	 ")	
	
	###-----------------------------------------------
	### Prevent interrupt during lay calculations

	Play(1,1)
	TimerMan.start()
	
return

###-----------------------------------------------
### Increase Speed Slider
### setValue(100 - timeDelay )	

Func SliderSpeedMove()

	sliderPos = SliderSpeed.value()				### 0 - 100 
	
	timeDelay  = 1000 - (sliderPos * 10) 		### Slow 1-100 Fast	 => 10-1000 milli-seconds - FLIP
	#See "timeDelay: "+ timeDelay +nl
	TimerMan.setInterval(timeDelay)			### 1000 = 1 sec
	
return

###-----------------------------------------------
### Size/Number of Cells to display on Release

Func SliderSizeMove()
	
	cellSize = SliderSize.value()				### 0 - 100	 40--50--60
	
	###-------------------------------------------
	### Only 3 sizes Small-40 Medium-50 Large-60
	
	if cellSize < 45  
		L = 1	hSize = 28	vSize = 28	
	elseif cellSize < 55
		L = 2	hSize = 38	vSize = 38	
	else
		L = 3	hSize = 48	vSize = 48	
	ok

	See "cellSize: "+ cellSize +nl
	
	aArray	= list(hSize, vSize)			### Internal Array with Letters
	bArray	= list(hSize, vSize)			### Working Array - Live and Exploded
	pArray	= list((hSize * vSize), 2)	### Populated Array - Coordinate h and v
	qArray	= list((hSize * vSize), 2)	### Populated Array - Coordinate h and v
		
	aButton = list(hSize, vSize)			### Button Array with Display Colors
		
	workWidget.Close()	
	DrawWidget()
	
	
return


###------------------------------------------
### Message Box - Lost or Won

Func MsgBox(Msg)

	mb = new qMessageBox(workWidget) 
			{
				setFont(new qFont("Courier",12,50,0))
				setWindowTitle('Game of Life')
				setStyleSheet(C_ButtonYellowStyle)
				setText(Msg)
				setStandardButtons(QMessageBox_OK) 
				result = exec()	### Needed to show Popup window
			}

###-------------------------------------


###--------------------------------------------------
### RightMouse Click on PushButton - 

Func RightClickMouse(Row,Col)
#See "RightClick: "+ Row +"-"+ Col +nl

	aButton[Row][Col] { setStyleSheet(C_ButtonCyanStyle) }
	
return



###-------------------------------------------------------------
### Set Initial Pattern
###		Visible Cells start at H=2 and V=2
###
###		patternType = comboPatternType.currentText()
###		LoadPattern(patternType)
###
###		["Clear","Glider","SmallExploder","Exploder","10CellRow","LightweightSpaceship", "Tumbler","GosperGliderGun"]
	
Func LoadPattern(patternType)
#See "Func-LoadPattern: "+ patternType +nl

if patternType = "Clear"

	LoadPatternClear()
	return
ok	

if patternType = "Glider"
		h = (hSize -4 ) / 4 
		v = (vSize -4 ) / 4			
				
		aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}	
		aArray[h+1][v+2] = 1 ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)	}	
		
		aArray[h+2][v+0] = 1 ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+2][v+1] = 1 ;	aButton[h+2][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+2][v+2] = 1 ;	aButton[h+2][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
	return
ok	
			
					
			
if patternType = "SmallExploder"
		###-------------------------
		h = (hSize -4 ) / 2
		v = (vSize -4 ) / 2	
		
		aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
										   
		aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+1][v+1] = 1 ;	aButton[h+1][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+1][v+2] = 1 ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
										   
		aArray[h+2][v+0] = 1 ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)	}	
		aArray[h+2][v+2] = 1 ;	aButton[h+2][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
										   
		aArray[h+3][v+1] = 1 ;	aButton[h+3][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
	return		
ok		

if patternType = "Exploder"
		h = (hSize -4 ) / 2 
		v = (vSize -4 ) / 2	
		
		aArray[h+0][v+0] = 1 ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+0][v+2] = 1 ;	aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+0][v+4] = 1 ;	aButton[h+0][v+4] { setStyleSheet(C_ButtonYellowStyle)	}
										   
		aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}	
		aArray[h+1][v+4] = 1 ;	aButton[h+1][v+4] { setStyleSheet(C_ButtonYellowStyle)	}
										   
		aArray[h+2][v+0] = 1 ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)	}	
		aArray[h+2][v+4] = 1 ;	aButton[h+2][v+4] { setStyleSheet(C_ButtonYellowStyle)	}		
										   
		aArray[h+3][v+0] = 1 ;	aButton[h+3][v+0] { setStyleSheet(C_ButtonYellowStyle)	}	
		aArray[h+3][v+4] = 1 ;	aButton[h+3][v+4] { setStyleSheet(C_ButtonYellowStyle)	}
										   
		aArray[h+4][v+0] = 1 ;	aButton[h+4][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+4][v+2] = 1 ;	aButton[h+4][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+4][v+4] = 1 ;	aButton[h+4][v+4] { setStyleSheet(C_ButtonYellowStyle)	}		
		
	return		
ok

if patternType = "10CellRow"
		h = (hSize -4 ) / 2 +2	 
		v = (vSize -4 ) / 2 -3	

		aArray[h+0][v+0] = 1 ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+0][v+2] = 1 ;	aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)	}									   
		aArray[h+0][v+3] = 1 ;	aButton[h+0][v+3] { setStyleSheet(C_ButtonYellowStyle)	}	
		aArray[h+0][v+4] = 1 ;	aButton[h+0][v+4] { setStyleSheet(C_ButtonYellowStyle)	}										  
		aArray[h+0][v+5] = 1 ;	aButton[h+0][v+5] { setStyleSheet(C_ButtonYellowStyle)	}	
		aArray[h+0][v+6] = 1 ;	aButton[h+0][v+6] { setStyleSheet(C_ButtonYellowStyle)	}											   
		aArray[h+0][v+7] = 1 ;	aButton[h+0][v+7] { setStyleSheet(C_ButtonYellowStyle)	}	
		aArray[h+0][v+8] = 1 ;	aButton[h+0][v+8] { setStyleSheet(C_ButtonYellowStyle)	}										   
		aArray[h+0][v+9] = 1 ;	aButton[h+0][v+9] { setStyleSheet(C_ButtonYellowStyle)	}
	return
ok		

if patternType = "LightweightSpaceship"
		h = (hSize -4 ) / 2 
		v = (vSize -4 ) / 2	

		aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+0][v+2] = 1 ;	aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+0][v+3] = 1 ;	aButton[h+0][v+3] { setStyleSheet(C_ButtonYellowStyle)	}									   
		aArray[h+0][v+4] = 1 ;	aButton[h+0][v+4] { setStyleSheet(C_ButtonYellowStyle)	}	
										   
		aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}										  
		aArray[h+1][v+4] = 1 ;	aButton[h+1][v+4] { setStyleSheet(C_ButtonYellowStyle)	}	
										   
		aArray[h+2][v+4] = 1 ;	aButton[h+2][v+4] { setStyleSheet(C_ButtonYellowStyle)	}											   
										   
		aArray[h+3][v+0] = 1 ;	aButton[h+3][v+0] { setStyleSheet(C_ButtonYellowStyle)	}	
		aArray[h+3][v+3] = 1 ;	aButton[h+3][v+3] { setStyleSheet(C_ButtonYellowStyle)	}	
	return		
		
ok	

if patternType = "Tumbler"
		h = (hSize -4 ) / 2 
		v = (vSize -4 ) / 2	
		
		aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+0][v+2] = 1 ;	aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+0][v+4] = 1 ;	aButton[h+0][v+4] { setStyleSheet(C_ButtonYellowStyle)	}									   
		aArray[h+0][v+5] = 1 ;	aButton[h+0][v+5] { setStyleSheet(C_ButtonYellowStyle)	}	
										   
		aArray[h+1][v+1] = 1 ;	aButton[h+1][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+1][v+2] = 1 ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+1][v+4] = 1 ;	aButton[h+1][v+4] { setStyleSheet(C_ButtonYellowStyle)	}									   
		aArray[h+1][v+5] = 1 ;	aButton[h+1][v+5] { setStyleSheet(C_ButtonYellowStyle)	}	
										   
		aArray[h+2][v+2] = 1 ;	aButton[h+2][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+2][v+4] = 1 ;	aButton[h+2][v+4] { setStyleSheet(C_ButtonYellowStyle)	}
										   
										   
		aArray[h+3][v+0] = 1 ;	aButton[h+3][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+3][v+2] = 1 ;	aButton[h+3][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+3][v+4] = 1 ;	aButton[h+3][v+4] { setStyleSheet(C_ButtonYellowStyle)	}									   
		aArray[h+3][v+6] = 1 ;	aButton[h+3][v+6] { setStyleSheet(C_ButtonYellowStyle)	}	
										   
		aArray[h+4][v+0] = 1 ;	aButton[h+4][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+4][v+2] = 1 ;	aButton[h+4][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+4][v+4] = 1 ;	aButton[h+4][v+4] { setStyleSheet(C_ButtonYellowStyle)	}									   
		aArray[h+4][v+6] = 1 ;	aButton[h+4][v+6] { setStyleSheet(C_ButtonYellowStyle)	}	
										   
		aArray[h+5][v+0] = 1 ;	aButton[h+5][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+5][v+1] = 1 ;	aButton[h+5][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
		aArray[h+5][v+5] = 1 ;	aButton[h+5][v+5] { setStyleSheet(C_ButtonYellowStyle)	}									   
		aArray[h+5][v+6] = 1 ;	aButton[h+5][v+6] { setStyleSheet(C_ButtonYellowStyle)	}
	return		
		
ok

###------------------------------------------------------
### This Multi=pattern is TOO BIG for the Smaller Grids
### Check Limits

if patternType = "GosperGliderGun"
		horz = (hSize -4 ) / 4 
		vert = (vSize -4 ) / 6
		
		h = horz+2	v = vert+0	### A
		if (h < hSize -3  AND v < vSize -3)
			aArray[h+0][v+0] = 1 ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}									   
			aArray[h+1][v+1] = 1 ;	aButton[h+1][v+1] { setStyleSheet(C_ButtonYellowStyle)	}		
		ok
		
		h = horz+2	v = vert+8	### B
		if (h < hSize -3  AND v < vSize -3)
			aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+0][v+2] = 1 ;	aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}									   
			aArray[h+1][v+2] = 1 ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)	}	
			aArray[h+2][v+0] = 1 ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)	}									   
			aArray[h+2][v+1] = 1 ;	aButton[h+2][v+1] { setStyleSheet(C_ButtonYellowStyle)	}		
		ok
		
		h = horz+4	v = vert+16	### C
		if (h < hSize -3  AND v < vSize -3)
			aArray[h+0][v+0] = 1 ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}									   
			aArray[h+1][v+2] = 1 ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)	}	
			aArray[h+2][v+0] = 1 ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)	}									   
		ok

		h = horz+0	v = vert+22	### D
		if (h < hSize -3  AND v < vSize -3)
			aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+0][v+2] = 1 ;	aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}									   
			aArray[h+1][v+2] = 1 ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)	}	
			aArray[h+2][v+0] = 1 ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)	}									   
			aArray[h+2][v+1] = 1 ;	aButton[h+2][v+1] { setStyleSheet(C_ButtonYellowStyle)	}		
		ok
		
		h = horz+0	v = vert+34 ### E
		if (h < hSize -3  AND v < vSize -3)
			aArray[h+0][v+0] = 1 ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}									   
			aArray[h+1][v+1] = 1 ;	aButton[h+1][v+1] { setStyleSheet(C_ButtonYellowStyle)	}			
		ok
		
		h = horz+7	v = vert+35	### F
		if (h < hSize -3  AND v < vSize -3)
			aArray[h+0][v+0] = 1 ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}									   
			aArray[h+1][v+2] = 1 ;	aButton[h+1][v+2] { setStyleSheet(C_ButtonYellowStyle)	}	
			aArray[h+2][v+0] = 1 ;	aButton[h+2][v+0] { setStyleSheet(C_ButtonYellowStyle)	}		
		ok
		
		h = horz+12	 v = vert+24	### G
		if (h < hSize -3  AND v < vSize -3)
			aArray[h+0][v+0] = 1 ;	aButton[h+0][v+0] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+0][v+1] = 1 ;	aButton[h+0][v+1] { setStyleSheet(C_ButtonYellowStyle)	}
			aArray[h+0][v+2] = 1 ;	aButton[h+0][v+2] { setStyleSheet(C_ButtonYellowStyle)	}									   
			aArray[h+1][v+0] = 1 ;	aButton[h+1][v+0] { setStyleSheet(C_ButtonYellowStyle)	}	
			aArray[h+2][v+1] = 1 ;	aButton[h+2][v+1] { setStyleSheet(C_ButtonYellowStyle)	} 
		ok
		
	return		
		
ok 

return
###-------------------------------
