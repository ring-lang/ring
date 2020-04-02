# Project : CalmoSoft Bejeweled Game
# Date    : 02/04/2020-03:33:28
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 8
move = 0
nextMove = newlist(2,2)
width = 60
height = 60
C_Spacing = 1

Button = newlist(size,size)
ButtonColor = newlist(size,size)
cmbMove = newlist(size,size)
LayoutButtonRow = list(size)

C_Empty = 'border-radius:6px;color:black; background-color: white'
C_RedStyle   = 'border-radius:6px;color:black; background-color: yellow'
C_VioletStyle   = 'border-radius:6px;color:black; background-color: violet'
C_GreenStyle   = 'border-radius:6px;color:black; background-color: green'
C_RedStyle   = 'border-radius:6px;color:black; background-color: red'
C_Bluetyle   = 'border-radius:6px;color:black; background-color: blue'
C_OrangeStyle   = 'border-radius:6px;color:black; background-color: orange'
C_BlackStyle   = 'border-radius:6px;color:black; background-color: black'

StyleList = [C_RedStyle,C_VioletStyle,C_GreenStyle,
             C_RedStyle,C_Bluetyle,C_OrangeStyle,C_BlackStyle]

app = new qApp 
{
      win = new qWidget() {
	    setWindowTitle('CalmoSoft Bejeweled Game')
	    move(600,200)
	    reSize(600,600)
	    winheight = win.height()
	    fontSize = 8 + (winheight / 100)

	    for Row = 1 to size
         	for Col = 1 to size
		    Button[Row][Col] = new QPushButton(win) {
                                       x = 50+(Row-1)*width
                                       y = 50+(Col-1)*height
                                       setgeometry(x,y,width,height)
                                       rndStyle = random(len(StyleList)-1) + 1
                                       ButtonColor[Row][Col] = rndStyle
				       setStyleSheet(StyleList[rndStyle])
                                       setclickevent("pButtonPress(" + string(Row) + "," + string(Col) + ")")
                                       setSizePolicy(1,1) }				       
		next
            next

            show()
   }
   exec()
}

func pMoveGems()
     if (nextMove[1][1] = nextMove[2][1]) and (nextMove[1][2]-1 = nextMove[2][2])
        pMoveLeft(nextMove[1][2],nextMove[1][1])
     ok
     if (nextMove[1][1] = nextMove[2][1]) and (nextMove[1][2]+1 = nextMove[2][2])
        pMoveRight(nextMove[1][2],nextMove[1][1])
     ok
     if (nextMove[1][1]-1 = nextMove[2][1]) and (nextMove[1][2] = nextMove[2][2])
        pMoveUp(nextMove[1][2],nextMove[1][1])
     ok
     if (nextMove[1][1]+1 = nextMove[2][1]) and (nextMove[1][2] = nextMove[2][2])
        pMoveDown(nextMove[1][2],nextMove[1][1])
     ok

func pMoveLeft(Row,Col)
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row-1][Col]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row-1][Col] = color1
     sleep(0.5)
     Button[Row][Col].setStyleSheet(StyleList[color2])
     sleep(0.5)
     Button[Row-1][Col].setStyleSheet(StyleList[color1])

func pMoveRight(Row,Col)
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row+1][Col]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row+1][Col] = color1
     sleep(0.5)
     Button[Row][Col].setStyleSheet(StyleList[color2])
     sleep(0.5)
     Button[Row+1][Col].setStyleSheet(StyleList[color1])

func pMoveUp(Row,Col)
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row][Col-1]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row][Col-1] = color1
     sleep(0.5)
     Button[Row][Col].setStyleSheet(StyleList[color2])
     sleep(0.5)
     Button[Row][Col-1].setStyleSheet(StyleList[color1])

func pMoveDown(Row,Col)
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row][Col+1]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row][Col+1] = color1
     sleep(0.5)
     Button[Row][Col].setStyleSheet(StyleList[color2])
     sleep(0.5)
     Button[Row][Col+1].setStyleSheet(StyleList[color1])
 
func pButtonPress(Row,Col)
     move = move + 1
     nextMove[move][1] = Col
     nextMove[move][2] = Row
     if move = 2
        pMoveGems()
     ok
     if move = 2
        move = 0
     ok
     
func pExit()
	win.close()
	app.quit()	

