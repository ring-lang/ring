# Project : CalmoSoft Magic Balls Game
# Date    : 28/02/2020
# Author  : Gal Zsolt (~ CalmoSoft ~), Bert Mariani
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"
load "solveArrayPathDest.ring"

size = 10
nrCell = 3        // number of new cells
colorNr = 6       // number of basic colors

Rows = 1
Cols = 1
srcX = 1
srcY = 1

cellVisit = newlist(size,size)

balls = ["images/blue.jpg", "images/green.jpg", "images/orange.jpg",
	 "images/red.jpg", "images/violet.jpg","images/yellow.jpg",
         "images/blueonblack.jpg", "images/greenonblack.jpg",
	 "images/orangeonblack.jpg", "images/redonblack.jpg", "images/violetonblack.jpg",
	 "images/yellowonblack.jpg", "images/empty.jpg"]

C_EMPTY = "images/empty.jpg"
whiteBallWH = new Qpixmap("blue.jpg")

hv = 0         // source ball
btn = 0        // target empty cell
bt = 0
bWidth  = whiteBallWH.width()    
bHeight = whiteBallWH.height()   

Button = list(size*size)    // list for balls
cellType = list(size*size)  // Type (color) of ball
aList = list(size*size)
bool = 0
bool01 = 0
bool02 = 0
bool03 = 0
bool04 = 0
score = 0
plusScore = 0
scoreText = "Score: "

//=================================

app = new qApp 
{       
      processevents()
      win = new qWidget() {
	    setWindowTitle('CalmoSoft Magic Balls Game')
	    move(550,150)
	    reSize(600,650)

	    btnNewGame = new QPushButton(win)	
		         { setgeometry(120,620,70,20)
                           settext("New Game")
                           setclickevent("newGame()")
                           show()		
                         }

	    btnScore = new QPushButton(win)	
		       { setgeometry(240,620,70,20)
                         settext("Score: 0")
                         show()		
                       }


            for btn = 1 to size*size
                Button[btn] = new QPushButton(win) { setIcon(new qIcon(new Qpixmap(C_EMPTY)))
                                  setIconSize(new qSize(bWidth,bHeight))
                                  col = btn%size
                                  if col = 0
                                     col = size 
                                  ok
                                  row = ceil(btn/size)
                                  setgeometry((col-1)*60,(row-1)*60,60,60)
                                  setclickevent("UserLeftClick(" + string(btn) + ")") }
            next

            show()
   }
   pbegin()
   exec()   
}

//=================================

func gameOver()
     eList = []     
     for i = 1 to size*size
         if cellType[i] = C_EMPTY   
            Add(eList,i)
         ok
     next 
     nrOver = len(eList)
     if nrOver < 7
        msgBox("Game Over!")
        newGame()
     ok

//=================================

func UserLeftClick(btn)                    // for click on a button

     bool = 0
     ind = find(balls, cellType[btn])      //find color
     if (ind > 0) and (cellType[btn] != C_EMPTY)
	hv = btn                           // store index of source ball to hv
        if ind < colorNr + 1               // if color is basic
           cellType[hv] = balls[ind+colorNr]
        ok		
        return
     else
        if (hv != 0)
              if cellType[hv] = C_EMPTY
                 start = 0
              else
                 start = 1
              ok
              y = hv%size
              if y = 0
                 y = size 
              ok
              x = ceil(hv/size)
              t = btn%size
              if t = 0
                 t = size 
              ok
              s = ceil(btn/size)		
              for m = 1 to size*size
		  row = ceil( m / size)
		  col = m % size
		  if col = 0  col = size  ok
		  if cellType[m] = C_EMPTY
	       	     cellVisit[row][col] = 0
		  else
		     cellVisit[row][col] = 1
		  ok
	      next
              pathRes = pathSrcDest(cellVisit,x,y,s,t)
              if pathRes = 1 
	         Button[btn] { seticon(new qicon(new qpixmap(cellType[hv])))
                               setIconSize(new qSize(65,65)) } 
                 Button[hv] { seticon(new qicon(new qpixmap(C_EMPTY)))
                              setIconSize(new qSize(65,65)) }
                 app.processevents()
                 sleep(0.1)
                 cellVisit[s][t] = 1
                 cellVisit[x][y] = 0
                 cellType[btn] = cellType[hv]
                 cellType[hv] = C_EMPTY
                 deleteCells()      // When you line up 5 balls of the same color horizontally,
                                    // vertically or diagonally, the line disappears
                 bool = (bool01 = 1 or bool02 = 1 or bool03 = 1 or bool04 = 1)
                 if bool = 1
                    msgBox("You win!")
                    newCells(5)
                    return
                 ok
                 if (start = 1)
                    newCells(3)      // place new three balls on table
                 ok
              else
                 msgBox("Invalid move!")
              ok
        ok
      ok

//=================================

func newCells(nrCell)
     aList = []   
     for i = 1 to size*size
         if cellType[i] = C_EMPTY   
            Add(aList,i)
         ok
     next 
     cnt = 0
     while cnt < nrCell
           cellStyle = random(5) + 1
           pickSquare = random(len(aList)-1)+1
           ind1 = find(aList,pickSquare)
           if ind1 > 0
              del(aList,ind1)
              ind2 = find(aList,pickSquare)
              if ind2 < 1
                 add(aList,ind1)
                 aList = sort(aList)
                 pickValue  = aList[pickSquare]
                 button[pickValue] { seticon(new qicon(new qpixmap(balls[cellStyle])))
                                     setIconSize(new qSize(65,65)) }
                 cellType[pickValue] = balls[cellStyle] 
                 cnt = cnt + 1
                 gameOver()
              ok             
           ok
     end
     if nrCell = 5
        score = score + nrCell + plusScore
        btnScore.settext(scoreText + string(score)) 
     ok

//=================================

func newGame()
     pBegin()

//=================================

func pBegin()

     score = 0
     plusScore = 0
     btnScore.settext(scoreText + string(score)) 

     for btn = 1 to size*size
	 Button[btn] { seticon(new qicon(new qpixmap(C_EMPTY)))
                       setIconSize(new qSize(65,65))
                     }
         cellType[btn] = C_EMPTY
         col = btn%size
         if col = 0
            col = size 
         ok
         row = ceil(btn/size)
         cellVisit[row][col] = 0
     next

     newCells(3)

//=================================

func deleteCells()
     bool01 = 0
     bool02 = 0
     bool03 = 0
     bool04 = 0
     start = 1
     plusScore = 0
     for btn = 1 to size*size-4                          // detect 5 balls horitontally
             cellType1 = cellType[btn]
             inds = find(balls,cellType[btn])
             if inds < colorNr + 1
                cellType2 = balls[inds+colorNr]
             else
                cellType2 = balls[inds-colorNr]
             ok
             bool1 = (cellType[btn] != C_EMPTY)
             bool2 = (cellType[btn+1] = cellType1) or (cellType[btn+1] = cellType2)    
             bool3 = (cellType[btn+2] = cellType1) or (cellType[btn+2] = cellType2)
             bool4 = (cellType[btn+3] = cellType1) or (cellType[btn+3] = cellType2)
             bool5 = (cellType[btn+4] = cellType1) or (cellType[btn+4] = cellType2)
             bool01 = bool1 and bool2 and bool3 and bool4 and bool5
             if bool01 = 1 
                for p = 0 to 4
                    Button[btn+p] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                    setIconSize(new qSize(65,65))
                                  }
                    cellType[btn+p] = C_EMPTY
                    col = btn%size
                    if col = 0
                       col = size 
                    ok
                    row = ceil(btn/size)
                next
                for bt = btn+5 to size*size
                    if (cellType[bt] = cellType1) or (cellType[bt] = cellType2)
                       Button[bt] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                    setIconSize(new qSize(65,65))
                                  }
                       cellType[bt] = C_EMPTY
                       col = bt%size
                       if col = 0
                          col = size 
                       ok
                       row = ceil(bt/size)
                       plusScore = plusScore + 1
                     else
                       exit
                     ok
                next
                exit
             ok
     next

     for btn = 1 to size*size-40                         // detect 5 balls vertically
             cellType1 = cellType[btn]
             inds = find(balls,cellType[btn])
             if inds < colorNr + 1
                cellType2 = balls[inds+colorNr]
             else
                cellType2 = balls[inds-colorNr]
             ok
             bool1 = (cellType[btn] != C_EMPTY)
             bool2 = (cellType[btn+size] = cellType1) or (cellType[btn+size] = cellType2)
             bool3 = (cellType[btn+size*2] = cellType1) or (cellType[btn+size*2] = cellType2) 
             bool4 = (cellType[btn+size*3] = cellType1) or (cellType[btn+size*3] = cellType2)
             bool5 = (cellType[btn+size*4] = cellType1) or (cellType[btn+size*4] = cellType2)
             bool02 = bool1 and bool2 and bool3 and bool4 and bool5
             if bool02 = 1
                for p = 0 to 4
                    Button[btn+size*p] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                         setIconSize(new qSize(65,65))
                                       }
                    cellType[btn+size*p] = C_EMPTY
                    col = btn%size
                    if col = 0
                       col = size 
                    ok
                    row = ceil(btn/size)
                next
                for bt = btn+size*5 to size*size step 10
                    if (cellType[bt] = cellType1) or (cellType[bt] = cellType2)
                       Button[bt] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                    setIconSize(new qSize(65,65))
                                  }
                       cellType[bt] = C_EMPTY
                       col = bt%size
                       if col = 0
                          col = size 
                       ok
                       row = ceil(bt/size)
                       plusScore = plusScore + 1
                     else
                       exit
                     ok
                next
                exit
              ok
     next

     for btn = 1 to size*size-36                         // detect 5 balls diagonally (to top l eftcorner)
             cellType1 = cellType[btn]
             inds = find(balls,cellType[btn])
             if inds < colorNr + 1
                cellType2 = balls[inds+colorNr]
             else
                cellType2 = balls[inds-colorNr]
             ok
             bool1 = (cellType[btn] != C_EMPTY)
             bool2 = (cellType[btn+9] = cellType1) or (cellType[btn+9] = cellType2)
             bool3 = (cellType[btn+18] = cellType1) or (cellType[btn+18] = cellType2)
             bool4 = (cellType[btn+27] = cellType1) or (cellType[btn+27] = cellType2)
             bool5 = (cellType[btn+36] = cellType1) or (cellType[btn+36] = cellType2)
             bool03 = bool1 and bool2 and bool3 and bool4 and bool5
             if bool03 = 1
                for p = 0 to 4
                    Button[btn+p*9] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                      setIconSize(new qSize(65,65))
                                    }
                    cellType[btn+p*9] = C_EMPTY
                    col = btn%size
                    if col = 0
                       col = size 
                    ok
                    row = ceil(btn/size)
                next
                for bt = btn+(size-1)*5 to size*size step 9
                    if (cellType[bt] = cellType1) or (cellType[bt] = cellType2)
                       Button[bt] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                    setIconSize(new qSize(65,65))
                                  }
                       cellType[bt] = C_EMPTY
                       col = bt%size
                       if col = 0
                          col = size 
                       ok
                       row = ceil(bt/size)
                       plusScore = plusScore + 1
                     else
                       exit
                     ok
                next
                exit
             ok
     next

     for btn = 1 to size*size-44                         // detect 5 balls diagonally (to top right corner)
             cellType1 = cellType[btn]
             inds = find(balls,cellType[btn])
             if inds < colorNr + 1
                cellType2 = balls[inds+colorNr]
             else
                cellType2 = balls[inds-colorNr]
             ok
             bool1 = (cellType[btn] != C_EMPTY)
             bool2 = (cellType[btn+11] = cellType1) or (cellType[btn+11] = cellType2)
             bool3 = (cellType[btn+22] = cellType1) or (cellType[btn+22] = cellType2) 
             bool4 = (cellType[btn+33] = cellType1) or (cellType[btn+33] = cellType2)
             bool5 = (cellType[btn+44] = cellType1) or (cellType[btn+44] = cellType2)
             bool04 = bool1 and bool2 and bool3 and bool4 and bool5
             if bool04 = 1
                for p = 0 to 4
                    Button[btn+p*11] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                       setIconSize(new qSize(65,65))
                                     }
                    cellType[btn+p*11] = C_EMPTY
                    col = btn%size
                    if col = 0
                       col = size 
                    ok
                    row = ceil(btn/size)
                next
                for bt = btn+(size+1)*5 to size*size step 11
                    if (cellType[bt] = cellType1) or (cellType[bt] = cellType2)
                       Button[bt] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                    setIconSize(new qSize(65,65))
                                  }
                       cellType[bt] = C_EMPTY
                       col = bt%size
                       if col = 0
                          col = size 
                       ok
                       row = ceil(bt/size)
                       plusScore = plusScore + 1
                     else
                       exit
                     ok
                next
                exit
             ok
     next

//=================================

func pExit()
     win.close()
     app.quit()

//=================================

func msgBox(cText)
     mb = new qMessageBox(win) 
	  { setWindowTitle('Magic Balls Game')
            setstandardButtons(QMessageBox_Discard | QMessageBox_OK) 
            settext(cText)
            result = exec()
            if result = QMessageBox_OK
               return
            ok			
          }
          return

//=================================
