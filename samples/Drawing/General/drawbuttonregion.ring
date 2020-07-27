# Sample : Add Button After Drawing the button region using the Mouse
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2017.02.04

Load "guilib.ring"

lPress = false

nX = 0
nY = 0

nButtons = 0

C_TOPMARGIN = 25
C_LEFTMARGIN = 5

new qApp {

        win = new qWidget()
        {
                setWindowTitle("Add Button After Drawing the button region using the Mouse")
                setGeometry(100,100,600,600)

		myfilter = new qallevents(win)
		myfilter.setMouseButtonPressEvent("pPress()")
		myfilter.setMouseButtonReleaseEvent("pRelease()")
		myfilter.setMouseMoveEvent("pMove()")
		installeventfilter(myfilter)

             	label1 = new qlabel(win) {
			setGeometry(100,100,400,400)
		 	setstylesheet("background-color:transparent;border: 1px solid black")				 
			setautoFillBackground(false)
			settext("")
			setmousetracking(false)
			hide()
		}


                show()
        }

        exec()
}


Func pPress
        nX = myfilter.getglobalx()
        ny = myfilter.getglobaly()
	Label1.raise()

Func pRelease
        label1.hide()
	aRect = GetRectDim()
	nButtons++
	new qPushButton(win) {
			move(aRect[1],aRect[2])
			resize(aRect[3],aRect[4])
			settext("button [" + nButtons + "]")
			show()
	}

func pMove
	aRect = GetRectDim()
        label1 {
		move(aRect[1],aRect[2]) resize(aRect[3],aRect[4])
		show()
       }
	

func GetRectDim
	nX2 = myfilter.getglobalx()
        ny2 = myfilter.getglobaly()
	top = min(Ny2,ny) - win.y() - C_TOPMARGIN
	left = min(nX2,nx) - win.x() - C_LEFTMARGIN
	width = max(nX,nX2) - min(nX,nX2)  
	height = max(nY,nY2) - min(nY,nY2)  
	return [left,top,width,height]
