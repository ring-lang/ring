# Project : CalmoSoft Elevator Game
# Date    : 25/03/2020-09:06:34
# Author  : Gal Zsolt & Cathlyn Cosca
# Email   : calmosoft@gmail.com

load "stdlib.ring"
load "guilib.ring"

floorCount = 6
randEvelator = 1
randWait = 1
randOld = 0
nFloor = 0
count = 0
floor = list(floorCount)
floorbtn = list(floorCount)
floorCall = list(floorCount)
C_UP = "images/up.jpg"
C_DOWN = "images/down.jpg"
C_WAIT = "images/wait.jpg"
C_EMPTY = "images/empty.jpg"
C_OPEN = "images/elevatoropen.jpg"
C_CLOSE = "images/elevatorclose.jpg"
C_CLOSEEVELATOR = "images/closeevelator.jpg"
C_RECTANGLE = "images/rectangle.jpg"
floorbtn[1] = "images/floor1.jpg"
floorbtn[2] = "images/floor2.jpg"
floorbtn[3] = "images/floor3.jpg"
floorbtn[4] = "images/floor4.jpg"
floorbtn[5] = "images/floor5.jpg"
floorbtn[6] = "images/floor6.jpg"
oFont = new qfont("Verdana",16,0,0)

app = new qApp 
{       
	stylefusionblack()
      processevents()
      win = new qWidget() {
	    setWindowTitle('CalmoSoft Evelator Game')
	    move(550,150)
	    reSize(600,800)
            app.processEvents()

            for n = 1 to floorCount 
	        floor[n] = new QPushButton(win)	
	                   { setgeometry(150,550-(n-1)*100,100,100) }
            next

            showFloor = new QPushButton(win)	
	                { setgeometry(150,15,100,25)
                          setfont(oFont)
                        }

	    rectangle = new QPushButton(win)	
	           { setgeometry(280,35,100,200)
  	             seticon(new qicon(new qpixmap(C_RECTANGLE)))
                     setIconSize(new qSize(66,66))
                   }

	    down = new QPushButton(win)	
	           { setgeometry(300,150,66,66)
                     setfont(oFont)
	             seticon(new qicon(new qpixmap(C_DOWN)))
                     setIconSize(new qSize(66,66))
                     setclickevent("pMoveDown()")
                   }

	    up = new QPushButton(win)	
	         { setgeometry(300,50,66,66) 
                   setfont(oFont)
	           seticon(new qicon(new qpixmap(C_UP)))
                   setIconSize(new qSize(66,66))
                   setclickevent("pMoveUp()")
                 }

	    newGame = new QPushButton(win)	
	              { setgeometry(150,700,250,50)
                        setfont(oFont)
                        settext("New Game")
                        setclickevent("pNewGame()")
                      }

	    rectangleFloor = new QPushButton(win)	
	                     { setgeometry(280,330,190,320)
  	                       seticon(new qicon(new qpixmap(C_RECTANGLE)))
                               setIconSize(new qSize(66,66))
                             }

	    floorCall[1] = new QPushButton(win)	
	                   { setgeometry(300,490,66,66)
	                     seticon(new qicon(new qpixmap(floorbtn[1])))
                             setIconSize(new qSize(100,100))
                             setclickevent("pMove(" + "1" + ")")
                           }

	    floorCall[2] = new QPushButton(win)	
	                   { setgeometry(386,490,66,66)
	                     seticon(new qicon(new qpixmap(floorbtn[2])))
                             setIconSize(new qSize(100,100))
                             setclickevent("pMove(" + "2" + ")")
                           }

	    floorCall[3] = new QPushButton(win)	
	                   { setgeometry(300,414,66,66)
	                     seticon(new qicon(new qpixmap(floorbtn[3])))
                             setIconSize(new qSize(100,100))
                             setclickevent("pMove(" + "3" + ")")
                             show()	
                           }

	    floorCall[4] = new QPushButton(win)	
	                   { setgeometry(386,414,66,66)
	                     seticon(new qicon(new qpixmap(floorbtn[4])))
                             setIconSize(new qSize(100,100))
                             setclickevent("pMove(" + "4" + ")")
                             show()	
                           }

	    floorCall[5] = new QPushButton(win)	
	                   { setgeometry(300,338,66,66)
	                     seticon(new qicon(new qpixmap(floorbtn[5])))
                             setIconSize(new qSize(100,100))
                             setclickevent("pMove(" + "5" + ")")
                           }

	    floorCall[6] = new QPushButton(win)	
	                   { setgeometry(386,338,66,66)
	                     seticon(new qicon(new qpixmap(floorbtn[6])))
                             setIconSize(new qSize(100,100))
                             setclickevent("pMove(" + "6" + ")")
                           }
	    close = new QPushButton(win)	
	            { setgeometry(340,580,66,66)
	              seticon(new qicon(new qpixmap(C_CLOSEEVELATOR)))
                      setIconSize(new qSize(100,100))
                      setclickevent("pClose()")
                    }        
            show()
      }
      pBegin()
      exec()   
}

func pNewGame()
     pBegin()
     pWait()

func pBegin()
     count = 0
     for n = 1 to floorCount
	 floor[n] { seticon(new qicon(new qpixmap(C_EMPTY)))
                      setIconSize(new qSize(100,100)) }	
     next
     randEvelator = random(floorCount-1) + 1
     floor[randEvelator] { seticon(new qicon(new qpixmap(C_CLOSE)))
                        setIconSize(new qSize(100,100)) }
     for n = 1 to floorCount
	 floorCall[n] { setenabled(False) }
     next
     up { setenabled(True) }
     down { setenabled(True) }
     showFloor.settext(string(randEvelator))
     pWait()

func pWait()
     floor[randWait] { seticon(new qicon(new qpixmap(C_EMPTY)))
                       setIconSize(new qSize(100,100)) }
     while true 
           randWait = random(floorCount-1) + 1
           if randWait != randEvelator
              floor[randWait] { seticon(new qicon(new qpixmap(C_WAIT)))
                                setIconSize(new qSize(100,100)) }
              exit
           ok
     end
 
func pMove(nr)
     up { setenabled(false) }
     down { setenabled(false) }
     count = count + 1
     if count = 1
        delFloor = randWait
     else
        delFloor = randOld
     ok
     if nr > delFloor
        for n = delFloor to nr - 1
            app.processEvents()
            sleep(0.5)
            floor[n] { seticon(new qicon(new qpixmap(C_EMPTY)))
                       setIconSize(new qSize(100,100)) }
            floor[n+1] { seticon(new qicon(new qpixmap(C_CLOSE)))
                       setIconSize(new qSize(100,100)) }
            if n = nr - 1
               nFloor = n + 1
               floor[n+1] { seticon(new qicon(new qpixmap(C_OPEN)))
                            setIconSize(new qSize(100,100)) }
            ok
            showFloor.settext(string(n+1))
        next
     ok
     if nr < delFloor
        for n = delFloor to nr + 1 step -1
            app.processEvents()
            sleep(0.5)
            floor[n] { seticon(new qicon(new qpixmap(C_EMPTY)))
                       setIconSize(new qSize(100,100)) }
            floor[n-1] { seticon(new qicon(new qpixmap(C_CLOSE)))
                         setIconSize(new qSize(100,100)) }
            if n = nr + 1
               nFloor = n - 1
               floor[n-1] { seticon(new qicon(new qpixmap(C_OPEN)))
                            setIconSize(new qSize(100,100)) }
            ok
            showFloor.settext(string(n-1))
        next
     ok
     randOld = nr

func pMoveDown()
     for n = 1 to floorCount
	 floorCall[n] { setenabled(True) }
     next
     if randWait < randEvelator
        for n = randEvelator to randWait + 1 step -1
            app.processEvents()
            sleep(0.5)
            floor[n] { seticon(new qicon(new qpixmap(C_EMPTY)))
                       setIconSize(new qSize(100,100)) }
            floor[n-1] { seticon(new qicon(new qpixmap(C_CLOSE)))
                         setIconSize(new qSize(100,100)) }
            if n = randWait + 1
                   nFloor = n - 1
                   floor[n-1] { seticon(new qicon(new qpixmap(C_OPEN)))
                                setIconSize(new qSize(100,100)) }
            ok
            showFloor.settext(string(randWait + 1))
        next
     ok        

func pMoveUp()
     for n = 1 to floorCount
	 floorCall[n] { setenabled(True) }
     next
     if randWait > randEvelator
        for n = randEvelator to randWait - 1
            app.processEvents()
            sleep(0.5)
            floor[n] { seticon(new qicon(new qpixmap(C_EMPTY)))
                       setIconSize(new qSize(100,100)) }
            floor[n+1] { seticon(new qicon(new qpixmap(C_CLOSE)))
                         setIconSize(new qSize(100,100)) }
            if n = randWait - 1
                   nFloor = n + 1
                   floor[n+1] { seticon(new qicon(new qpixmap(C_OPEN)))
                                setIconSize(new qSize(100,100)) }
            ok
            showFloor.settext(string(n+1))
        next
     ok   

func pClose()
     floor[nFloor] { seticon(new qicon(new qpixmap(C_CLOSE)))
                     setIconSize(new qSize(100,100)) } 
