# Project : CalmoSoft Bejeweled Game
# Date    : 03/04/2020-08:31:18
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
delGems = [][]

C_EMPTY = "images/empty.jpg"
C_BLUE = "images/blue.jpg"
C_GREEN = "images/green.jpg"
C_ORANGE = "images/orange.jpg"
C_RED = "images/red.jpg"
C_VIOLET = "images/violet.jpg"
C_WHITE = "images/white.jpg"
C_Empty = 'border-radius:6px;color:black; background-color: white'

StyleList = [C_BLUE,C_GREEN,C_ORANGE,C_RED,C_VIOLET,C_WHITE]

app = new qApp 
{
      win = new qWidget() {
	    setWindowTitle('CalmoSoft Bejeweled Game')
	    reSize(580,580)
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
                                       seticon(new qicon(new qpixmap(StyleList[rndStyle])))
                                       setIconSize(new qSize(70,70))
                                       setclickevent("pButtonPress(" + string(Row) + "," + string(Col) + ")")
                                       setSizePolicy(1,1) }				       
		next
            next
            show()
   }
   exec()
}

func deleteHorizontalSameColorGems()
     delGems = [][]
     for Row = 1 to size - 2
         for Col = 1 to size
             for m = Col to size
                 if (ButtonColor[Row][m] = ButtonColor[Row+1][m]) and
                    (ButtonColor[Row][m] = ButtonColor[Row+2][m])
                    add(delGems,[Row,m])
                    add(delGems,[Row+1,m])
                    add(delGems,[Row+2,m])
                 else
                    if len(delGems) > 2
                       showGems()
                    ok
                    delGems = [][]
                 ok
             next
         next
     next

func deleteVerticalSameColorGems()
     delGems = [][]
     for Row = 1 to size
         for Col = 1 to size
             for m = Col to size-2
                 if (ButtonColor[Row][m] = ButtonColor[Row][m+1]) and
                    (ButtonColor[Row][m] = ButtonColor[Row][m+2])
                    add(delGems,[Row,m])
                    add(delGems,[Row,m+1])
                    add(delGems,[Row,m+2])
                 else
                    if len(delGems) > 2
                       showGems()
                    ok
                    delGems = [][]
                 ok
             next
         next
     next

func showGems()
     for n = 1 to len(delGems)
         Button[delGems[n][1]][delGems[n][2]] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                                setIconSize(new qSize(100,100)) }
     next 

func pMoveGems()
     if (nextMove[1][1] = nextMove[2][1]) and (nextMove[1][2]-1 = nextMove[2][2])
        pMoveLeft(nextMove[1][2],nextMove[1][1])
        deleteVerticalSameColorGems()
        deleteHorizontalSameColorGems()
     ok
     if (nextMove[1][1] = nextMove[2][1]) and (nextMove[1][2]+1 = nextMove[2][2])
        pMoveRight(nextMove[1][2],nextMove[1][1])
        deleteVerticalSameColorGems()
        deleteHorizontalSameColorGems()
     ok
     if (nextMove[1][1]-1 = nextMove[2][1]) and (nextMove[1][2] = nextMove[2][2])
        pMoveUp(nextMove[1][2],nextMove[1][1])
        deleteVerticalSameColorGems()
        deleteHorizontalSameColorGems()
     ok
     if (nextMove[1][1]+1 = nextMove[2][1]) and (nextMove[1][2] = nextMove[2][2])
        pMoveDown(nextMove[1][2],nextMove[1][1])
        deleteVerticalSameColorGems()
        deleteHorizontalSameColorGems()
     ok

func pMoveLeft(Row,Col)
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row-1][Col]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row-1][Col] = color1
     Button[Row][Col] { seticon(new qicon(new qpixmap(StyleList[color2])))
                        setIconSize(new qSize(70,70)) }
     Button[Row-1][Col] { seticon(new qicon(new qpixmap(StyleList[color1])))
                          setIconSize(new qSize(70,70)) }

func pMoveRight(Row,Col)
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row+1][Col]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row+1][Col] = color1
     Button[Row][Col] { seticon(new qicon(new qpixmap(StyleList[color2])))
                        setIconSize(new qSize(70,70)) }
     Button[Row+1][Col] { seticon(new qicon(new qpixmap(StyleList[color1])))
                          setIconSize(new qSize(70,70)) }

func pMoveUp(Row,Col)
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row][Col-1]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row][Col-1] = color1
     Button[Row][Col] { seticon(new qicon(new qpixmap(StyleList[color2])))
                        setIconSize(new qSize(70,70)) }
     Button[Row][Col-1] { seticon(new qicon(new qpixmap(StyleList[color1])))
                          setIconSize(new qSize(70,70)) }

func pMoveDown(Row,Col)
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row][Col+1]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row][Col+1] = color1
     Button[Row][Col] { seticon(new qicon(new qpixmap(StyleList[color2])))
                        setIconSize(new qSize(70,70)) }
     Button[Row][Col+1] { seticon(new qicon(new qpixmap(StyleList[color1])))
                          setIconSize(new qSize(70,70)) }
 
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

