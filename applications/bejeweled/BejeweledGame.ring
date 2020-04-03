# Project : CalmoSoft Bejeweled Game
# Date    : 03/04/2020-08:31:18
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 8
move = 0
width = 60
height = 60
checkGems1 = 0
checkGems2 = 0

swapGems = ""
C_Spacing = 1

Button = newlist(size,size)
ButtonColor = newlist(size,size)
nextMove = newlist(2,2)
delGems = [][]

C_BLUE = "images/blue.png"
C_GREEN = "images/green.png"
C_ORANGE = "images/orange.png"
C_RED = "images/red.png"
C_VIOLET = "images/violet.png"
C_BLACK = "images/black.png"
C_YELLOW = "images/yellow.png"
C_EMPTY = "images/empty.png"

StyleList = [C_BLUE,C_GREEN,C_ORANGE,C_RED,C_VIOLET,C_BLACK,C_YELLOW,C_EMPTY]

app = new qApp 
{
      win = new qWidget() {
            app.StyleFusionBlack()
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
                                       createGems()
                                       setclickevent("pButtonPress(" + string(Row) + "," + string(Col) + ")")
                                       setSizePolicy(1,1) }				       
		next
            next
            show()
   }
   exec()
}

func createGems()
     while True
     for Row = 1 to size
         for Col = 1 to size
     rndStyle = random(len(StyleList)-2) + 1
     ButtonColor[Row][Col] = rndStyle
     Button[Row][Col] { seticon(new qicon(new qpixmap(StyleList[rndStyle])))
                        setIconSize(new qSize(70,70)) }
     next
     next
     checkHorizontalSameColorGems()
     checkVerticalSameColorGems()
     if (checkGems1 = 0) and (checkGems2 = 0)
        exit
     ok
     end

func checkHorizontalSameColorGems()
     checkGems1 = 0
     for Row = 1 to size - 2
         for Col = 1 to size
             for m = Col to size
                 if (ButtonColor[Row][m] = ButtonColor[Row+1][m]) and
                    (ButtonColor[Row][m] = ButtonColor[Row+2][m])
                    checkGems1 = 1
                 ok
             next
         next
     next

func checkVerticalSameColorGems()
     checkGems2 = 0
     for Row = 1 to size
         for Col = 1 to size
             for m = Col to size-2
                 if (ButtonColor[Row][m] = ButtonColor[Row][m+1]) and
                    (ButtonColor[Row][m] = ButtonColor[Row][m+2])
                    checkGems2 = 1
                 ok
             next
         next
     next


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
                       delGems = [][]
                    ok
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
                       delGems = [][]
                    ok
                 ok
             next
         next
     next

func showGems()
     for n = 1 to len(delGems)
         Button[delGems[n][1]][delGems[n][2]] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                                setIconSize(new qSize(50,50)) }
         ButtonColor[delGems[n][1]][delGems[n][2]] = len(StyleList)
     next 

func pMoveGems()
     if (nextMove[1][1] = nextMove[2][1]) and (nextMove[1][2]-1 = nextMove[2][2])
        swapGems = "Left"
        pSwapGems(nextMove[1][2],nextMove[1][1])
        deleteVerticalSameColorGems()
        deleteHorizontalSameColorGems()
     ok
     if (nextMove[1][1] = nextMove[2][1]) and (nextMove[1][2]+1 = nextMove[2][2])
        swapGems = "Right"
        pSwapGems(nextMove[1][2],nextMove[1][1])
        deleteVerticalSameColorGems()
        deleteHorizontalSameColorGems()
     ok
     if (nextMove[1][1]-1 = nextMove[2][1]) and (nextMove[1][2] = nextMove[2][2])
        swapGems = "Up"
        pSwapGems(nextMove[1][2],nextMove[1][1])
        deleteVerticalSameColorGems()
        deleteHorizontalSameColorGems()
     ok
     if (nextMove[1][1]+1 = nextMove[2][1]) and (nextMove[1][2] = nextMove[2][2])
        swapGems = "Down"
        pSwapGems(nextMove[1][2],nextMove[1][1])
        deleteVerticalSameColorGems()
        deleteHorizontalSameColorGems()
     ok

func pSwapGems(Row,Col)
     if swapGems = "Left"
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row-1][Col]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row-1][Col] = color1
     Button[Row][Col] { seticon(new qicon(new qpixmap(StyleList[color2])))
                        setIconSize(new qSize(70,70)) }
     Button[Row-1][Col] { seticon(new qicon(new qpixmap(StyleList[color1])))
                          setIconSize(new qSize(70,70)) }
     ok
     if swapGems = "Right"
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row+1][Col]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row+1][Col] = color1
     Button[Row][Col] { seticon(new qicon(new qpixmap(StyleList[color2])))
                        setIconSize(new qSize(70,70)) }
     Button[Row+1][Col] { seticon(new qicon(new qpixmap(StyleList[color1])))
                          setIconSize(new qSize(70,70)) }
     ok

     if swapGems = "Up"
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row][Col-1]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row][Col-1] = color1
     Button[Row][Col] { seticon(new qicon(new qpixmap(StyleList[color2])))
                        setIconSize(new qSize(70,70)) }
     Button[Row][Col-1] { seticon(new qicon(new qpixmap(StyleList[color1])))
                          setIconSize(new qSize(70,70)) }
     ok

     if swapGems = "Down"
     color1 = ButtonColor[Row][Col]
     color2 = ButtonColor[Row][Col+1]
     ButtonColor[Row][Col] = color2
     ButtonColor[Row][Col+1] = color1
     Button[Row][Col] { seticon(new qicon(new qpixmap(StyleList[color2])))
                        setIconSize(new qSize(70,70)) }
     Button[Row][Col+1] { seticon(new qicon(new qpixmap(StyleList[color1])))
                          setIconSize(new qSize(70,70)) }
     ok
 
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

