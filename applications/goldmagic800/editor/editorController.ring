# Gold Magic 800 3D Game - Level Editor
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>
# Form/Window Controller - Source Code File

load "editorView.ring"
load "editorConstants.ring"

import System.GUI


if IsMainSourceFile() {
	new App {
		StyleFusion()
		openWindow(:editorController)
		exec()
	}
}

class editorController from windowsControllerParent


	aLevel  = list(C_ROWS,C_COLS)
	PrepareLevel()

	aButton = list(C_ROWS,C_COLS)

	oView = new editorView

	DrawButtons()

	cCurrentFileName = ""

	RandomGen()

	func PrepareLevel
		for y = 1 to C_ROWS
			for x = 1 to C_COLS
				aLevel[y][x] = C_GROUND
			next 
		next 
	
	func Close 
		oView.Close()
		
	func DrawButtons
		for y = 1 to C_ROWS
			for x = 1 to C_COLS
				aButton[y][x] = new qPushButton(oView.win) {
					move(x*50-11,y*30+66)
					resize(50,30)
					setClickEvent(Method("CellClick("+y+","+x+")"))
				}				
			next 	
		next 

	func CellClick y,x
		nIndex = oView.listWidget1.currentrow()
		# We must have only one player and one door 
			if nIndex = C_PLAYER  
				for nY = 1 to C_ROWS
					for nX = 1 to C_COLS
						if aLevel[nY][nX] = C_PLAYER  
							aLevel[nY][nX] = C_GROUND
							aButton[nY][nX].setstylesheet("")	
							aButton[nY][nX].setText("")
						ok
					next 
				next
			ok
		aLevel[y][x] = nIndex
		setButtonColor(y,x,nIndex)
		aButton[y][x].show()
		UpdateGoldMarkCount()

	func UpdateGoldMarkCount
		# Update Gold Mark Count 
			nGMCount = 0
			for nY = 1 to C_ROWS
				for nX = 1 to C_COLS
					if aLevel[nY][nX] = C_GOLDMARK
						nGMCount++ 
					ok
				next 
			next
			oView.LabelGMCount.setText("" + nGMCount)

	func List2RingCode aList
		cCode = "["+Windowsnl()
		lStart = True
		for item in aList {
			if !lStart {
				cCode += ","
			else 
				lStart = False
			}
			if isString(item) {
				cCode += '"' + item + '"' 
			elseif isnumber(item)
				cCode += (""+item)
			elseif islist(item)
				cCode += List2RingCode(item)
			}
		}
		cCode += windowsnl()+"]"
		return cCode

	func LoadLevel
		cDir = currentdir()
		cEXEName = justfilename(exefilename())
		if cEXEName = "ring.exe" or cEXEName = "ringw.exe"
			chdir("../levels")
		else 
			chdir("levels")
		ok
		new qfiledialog(oView.win) {
			cName = getopenfilename(this.oView.win,"Open Level",CurrentDir(),"level files(*.level)")
			if cName != NULL
				this.LoadLevelFile(cName)
			ok
		}
		chdir(cDir)
		UpdateGoldMarkCount()

	func LoadLevelFile cName
		this.oView.lblFile.setText("File : " + JustFileName(cName))
		this.cCurrentFileName = cName
		eval(read(cName))
		this.aLevel = aLevelData 
		for y = 1 to C_ROWS
			for x = 1 to C_COLS
				nIndex = this.aLevel[y][x]
				this.setButtonColor(y,x,nIndex)
			next
		next

	func SetButtonColor y,x,nIndex 
		switch nIndex 
			on C_PLAYER
				aButton[y][x].setstylesheet("color:white;background-color:black;")	
				aButton[y][x].setText("P")
			on C_GROUND	
				aButton[y][x].setstylesheet("")	
				aButton[y][x].setText("")
			on C_WALL
				aButton[y][x].setstylesheet("color:white;background-color:purple;")	
				aButton[y][x].setText("W")
			on C_DOOR
				aButton[y][x].setstylesheet("color:white;background-color:green;")	
				aButton[y][x].setText("D")
			on C_GOLDGROUND
				aButton[y][x].setstylesheet("color:black;background-color:cyan;")	
				aButton[y][x].setText("G")
			on C_DOOR2
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D2")
			on C_GOLDCUBE
				aButton[y][x].setstylesheet("color:purple;background-color:cyan;")	
				aButton[y][x].setText("GC")
			on C_DOOR3
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D3")
			on C_DOOR4
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D4")
			on C_DOOR5
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D5")
			on C_DOOR6
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D6")
			on C_DOOR7
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D7")
			on C_DOOR8
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D8")
			on C_DOOR9
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D9")
			on C_DOOR10
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D10")
			on C_DOOR11
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D11")
			on C_DOOR12
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D12")
			on C_DOOR13
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D13")
			on C_DOOR14
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D14")
			on C_DOOR15
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D15")
			on C_DOOR16
				aButton[y][x].setstylesheet("color:White;background-color:green;")	
				aButton[y][x].setText("D16")
			on C_GOLDMARK
				aButton[y][x].setstylesheet("color:Black;background-color:Yellow;")	
				aButton[y][x].setText("GM")
			on C_PATHMARK
				aButton[y][x].setstylesheet("color:Black;background-color:Gray;")	
				aButton[y][x].setText("PM")
		off				

	func SaveLevel 
		cContent = List2RingCode(aLevel)
		cDir = currentdir()
		chdir("../levels")
		new qfiledialog(oView.win) {
			cName = getsavefilename(this.oView.win,"Save Level",CurrentDir()+"/"+this.cCurrentFileName,"level files(*.level)")
			if cName != NULL
				this.oView.lblFile.setText("File : " + cName)
				this.cCurrentFileName = cName
				write(cName,"aLevelData = " + cContent)				
			ok
		}
		chdir(cDir)

	func UpdateLevel
		if cCurrentFileName = NULL
			msginfo("Sorry","No level loaded!")
			return 
		ok
		cContent = List2RingCode(aLevel)
		write(cCurrentFileName,"aLevelData = " + cContent)				
		msginfo("Update Level","Operation done!")


	func Clear 
		for y = 1 to C_ROWS
			for x = 1 to C_COLS
				aButton[y][x].setText("")
				aButton[y][x].setstylesheet("")		
				aLevel[y][x] = C_GROUND
			next
		next 
		cCurrentFileName = ""
		this.oView.lblFile.setText("File : ")

	func RandomGen
		Clear()
		# Random Player Location 
			aPoint = GetNewCell()
			y=aPoint[:y] x=aPoint[:x]
			aButton[y][x].setstylesheet("color:white;background-color:black;")	
			aButton[y][x].setText("P")
			aLevel[y][x] = C_PLAYER
		# Random Door Location 
			aPoint = GetNewCell()
			y=aPoint[:y] x=aPoint[:x]
			aButton[y][x].setstylesheet("color:white;background-color:green;")	
			aButton[y][x].setText("D")
			aLevel[y][x] = C_DOOR

	func GetNewCell 
		do
			x = Random(19) + 1
			y = Random(19) + 1
		again not IsEmptyCell(y,x)
		return [:y = y, :x = x]

	func IsEmptyCell y,x
		if y>=1 and y<=20 and x>=1 and x<=20
			if aLevel[y][x] = C_GROUND return True ok
		ok
		return False 
