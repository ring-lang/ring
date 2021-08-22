# Project : Elevator Game
# Date    : 21/08/2021-02:26:57
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"

floorCount		= 7
randEvelator		= 1
randWait		= 1
randOld			= 0
nFloor			= 0
count			= 0
flag			= 0
targetFloor		= 0
floor			= list(floorCount)
floorbtn		= list(floorCount)
floorCall		= list(floorCount)

C_UP			= "images/up.jpg"
C_DOWN			= "images/down.jpg"
C_WAIT			= "images/wait.jpg"
C_EMPTY			= "images/empty.jpg"
C_OPEN			= "images/elevatoropen.jpg"
C_CLOSE			= "images/elevatorclose.jpg"
C_CLOSEELEVATOR		= "images/closeevelator.jpg"
C_RECTANGLE		= "images/rectangle.jpg"

floorbtn[1]		= "images/floor0.jpg"
floorbtn[2]		= "images/floor1.jpg"
floorbtn[3]		= "images/floor2.jpg"
floorbtn[4]		= "images/floor3.jpg"
floorbtn[5]		= "images/floor4.jpg"
floorbtn[6]		= "images/floor5.jpg"
floorbtn[7]		= "images/floor6.jpg"

oFont			= new qfont("Verdana",16,0,0)
C_ButtonOrangeStyle	= 'border-radius:6px;color:black; background-color: orange'

app = new qApp {       

	stylefusionblack()
	processevents()

	win = new qWidget() {

		setWindowTitle('Elevator Game')
		setWindowIcon(new qIcon(new qPixmap(C_OPEN)))
		move(550,140)
		reSize(800,700)
		app.processEvents()

		for n = 1 to floorCount
			floor[n] = new QPushButton(win)	{
				setgeometry(150,510-(n-2)*90,85,85)
			}
		next

		showFloor = new QPushButton(win) {
			setgeometry(150,15,90,25)
			setstylesheet(C_ButtonOrangestyle)
			setfont(oFont)
		}

		rectangle = new QPushButton(win) { 
			setgeometry(330,55,100,180)
			setstylesheet(C_ButtonOrangestyle)
			setIconSize(new QSize(66,66))
		}

		down = new QPushButton(win) {
			setgeometry(350,150,66,66)
			setfont(oFont)
			seticon(new qicon(new qpixmap(C_DOWN)))
			setIconSize(new qSize(66,66))
			setclickevent("pMoveDown()")
		}

		up = new QPushButton(win) {
			setgeometry(350,70,66,66) 
			setfont(oFont)
			seticon(new qicon(new qpixmap(C_UP)))
			setIconSize(new qSize(66,66))
			setclickevent("pMoveUp()")
		}

		newGame = new QPushButton(win) {
			setgeometry(550,300,150,50)
			setstylesheet(C_ButtonOrangestyle)
                        setfont(oFont)
                        settext("New Game")
                        setclickevent("pNewGame()")
		}

		exitButton = new QPushButton(win) {
			setgeometry(550,500,150,50)
			setstylesheet(C_ButtonOrangestyle)
			setfont(oFont)
			setClickEvent("pExit()")
			settext("Exit")
		}

		rectangleFloor = new QPushButton(win) {
			setgeometry(280,260,190,420)
			setstylesheet(C_ButtonOrangestyle)
			setIconSize(new qSize(66,66))
		}

		floorCall[1] = new QPushButton(win) {
			setgeometry(343,506,66,66)
			seticon(new qicon(new qpixmap(floorbtn[1])))
			setIconSize(new qSize(100,100))
			settext("GF")
			setclickevent("pMove(" + "1" + ")")
		}

		floorCall[2] = new QPushButton(win) {
			setgeometry(300,420,66,66)
			seticon(new qicon(new qpixmap(floorbtn[2])))
			setIconSize(new qSize(100,100))
			setclickevent("pMove(" + "2" + ")")
		}

		floorCall[3] = new QPushButton(win) {
			setgeometry(386,420,66,66)
			seticon(new qicon(new qpixmap(floorbtn[3])))
			setIconSize(new qSize(100,100))
			setclickevent("pMove(" + "3" + ")")
		}

		floorCall[4] = new QPushButton(win) {
			setgeometry(300,344,66,66)
			seticon(new qicon(new qpixmap(floorbtn[4])))
			setIconSize(new qSize(100,100))
			setclickevent("pMove(" + "4" + ")")
			show()	
		}

		floorCall[5] = new QPushButton(win) {
			setgeometry(386,344,66,66)
			seticon(new qicon(new qpixmap(floorbtn[5])))
			setIconSize(new qSize(100,100))
			setclickevent("pMove(" + "5" + ")")
			show()	
		}

		floorCall[6] = new QPushButton(win) {
			setgeometry(300,268,66,66)
			seticon(new qicon(new qpixmap(floorbtn[6])))
			setIconSize(new qSize(100,100))
			setclickevent("pMove(" + "6" + ")")
		}

		floorCall[7] = new QPushButton(win) {
			setgeometry(386,268,66,66)
			seticon(new qicon(new qpixmap(floorbtn[7])))
			setIconSize(new qSize(100,100))
			setclickevent("pMove(" + "7" + ")")
		}

		close = new QPushButton(win) {
			setgeometry(340,592,66,66)
			seticon(new qicon(new qpixmap(C_CLOSEELEVATOR)))
			setIconSize(new qSize(66,66))
			setclickevent("pClose()")
		}

		show()
	}
	pBegin()
	exec()   
}

func pNewGame
	pBegin()
	pWait()

func pBegin
	flag = 0
	count = 0
	for n = 1 to floorCount
		floor[n] {
			seticon(new qicon(new qpixmap(C_EMPTY)))
			setIconSize(new qSize(100,100))
		}	
	next
	randEvelator = random(floorCount-1) + 1
	for n = 1 to floorCount
		floorCall[n] { setenabled(False) }
	next
	up { setenabled(True) }
	down { setenabled(True) }
	pWait()

func pWait
	floor[randWait] {
		seticon(new qicon(new qpixmap(C_EMPTY)))
		setIconSize(new qSize(100,100))
	}
	randWait = random(floorCount-1) + 1

	while true 
		if randWait != randEvelator
			nFloor = randEvelator
			floor[randWait] { 
				seticon(new qicon(new qpixmap(C_WAIT)))
				setIconSize(new qSize(100,100)) 
			}
			floor[randEvelator] {
				seticon(new qicon(new qpixmap(C_CLOSE)))
				setIconSize(new qSize(100,100))
			}
			showFloor.settext(string(randEvelator-1))
			for n = 1 to floorCount
				floorCall[n] { setenabled(False) }
			next
			exit
		else
			randEvelator = random(floorCount-1) + 1
		ok
	end
 
func pMove sourceFloor
	if flag = 1
		n = 0
		pClose()
		app.processEvents()
		sleep(0.5)
		up { setenabled(false) }
		down { setenabled(false) }
		count = count + 1
		if count = 1
			targetFloor = randWait
		else
			targetFloor = randOld
		ok
		n = 0
		if sourceFloor > targetFloor
			for n = targetFloor to sourceFloor - 1
				app.processEvents()
				sleep(0.5)
				floor[n] {
					seticon(new qicon(new qpixmap(C_EMPTY)))
					setIconSize(new qSize(100,100))
				}
				floor[n+1] {
					seticon(new qicon(new qpixmap(C_CLOSE)))
					setIconSize(new qSize(100,100))
				}
				if n = 0
					showFloor.settext("GF")
				else
					showFloor.settext(string(n))
				ok
				if n = sourceFloor - 1
					nFloor = n + 1
					floor[n+1] {
						seticon(new qicon(new qpixmap(C_OPEN)))
						setIconSize(new qSize(100,100))
					}
				ok
			next
			see nl
		ok
		n = 0
		if sourceFloor < targetFloor 
			for n = targetFloor to sourceFloor + 1 step -1
				app.processEvents()
				sleep(0.5)
				floor[n] {
					seticon(new qicon(new qpixmap(C_EMPTY)))
					setIconSize(new qSize(100,100))
				}
				floor[n-1] {
					seticon(new qicon(new qpixmap(C_CLOSE)))
					setIconSize(new qSize(100,100))
				}
				if n = 2
					showFloor.settext("GF")
				else
					showFloor.settext(string(n-2))
				ok
				if n = sourceFloor + 1
					nFloor = n - 1
					floor[n-1] {
						seticon(new qicon(new qpixmap(C_OPEN)))
						setIconSize(new qSize(100,100))
					}
				ok
			next
			see nl
		ok
		randOld = sourceFloor
	ok

func pMoveDown
	if randWait > randEvelator
		return
	ok
	for n = 1 to floorCount
		floorCall[n] { setenabled(True) }
	next
	if randWait < randEvelator
		for n = randEvelator to randWait + 1 step -1
			app.processEvents()
			sleep(0.5)
			floor[n] { 
				seticon(new qicon(new qpixmap(C_EMPTY)))
				setIconSize(new qSize(100,100)) 
			}
			floor[n-1] { 
				seticon(new qicon(new qpixmap(C_CLOSE)))
				setIconSize(new qSize(100,100)) 
			}
			if n = 0
				showFloor.settext("GF")
			else
				showFloor.settext(string(n-2))
			ok
			if n = randWait + 1
				nFloor = n - 1
				floor[n-1] {
					seticon(new qicon(new qpixmap(C_OPEN)))
					setIconSize(new qSize(100,100))
				}
			ok
		next
	ok 
	app.processEvents()
	sleep(1)
	flag++       

func pMoveUp
	if randWait < randEvelator
		return
	ok    
	for n = 1 to floorCount
		floorCall[n] { setenabled(True) }
	next
	if randWait > randEvelator
		for n = randEvelator to randWait - 1
			app.processEvents()
			sleep(0.5)
			floor[n] { 
				seticon(new qicon(new qpixmap(C_EMPTY)))
				setIconSize(new qSize(100,100)) 
			}
			floor[n+1] { 
				seticon(new qicon(new qpixmap(C_CLOSE)))
				setIconSize(new qSize(100,100)) 
			}
			if n = 1
				showFloor.settext("GF")
			else
				showFloor.settext(string(n))
			ok
			if n = randWait - 1
				nFloor = n + 1
				floor[n+1] {
					seticon(new qicon(new qpixmap(C_OPEN)))
					setIconSize(new qSize(100,100)) 
				}
			ok
		next
	ok   
	app.processEvents()
	sleep(1)
	flag++

func pClose
	floor[nFloor] {
		seticon(new qicon(new qpixmap(C_CLOSE)))
		setIconSize(new qSize(100,100)) 
	} 

func pExit
	win.close()
	app.quit()
