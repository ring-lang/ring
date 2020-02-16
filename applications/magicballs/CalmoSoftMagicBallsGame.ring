# Project : CalmoSoft Magic Balls Game
# Date    : 15/02/2020
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 10
nrCell = 3        // number of new cells
colorNr = 6       // number of basic colors

Rows = 1
Cols = 1
srcXY = 1
dstXY = 1

aSquare = list(size*size)

balls = ["images/blue.jpg", "images/green.jpg", "images/orange.jpg",
	 "images/red.jpg", "images/violet.jpg","images/yellow.jpg",
         "images/blueonblack.jpg", "images/greenonblack.jpg",
	 "images/orangeonblack.jpg", "images/redonblack.jpg", "images/violetonblack.jpg",
	 "images/yellowonblack.jpg", "images/empty.jpg"]

C_EMPTY = "images/empty.jpg"

whiteBallWH = new Qpixmap("images/blue.jpg")

hv = 0         // source ball
btn = 0        // target empty cell
bWidth  = whiteBallWH.width()    
bHeight = whiteBallWH.height()   

Button = list(size*size)    // list for balls
cellType = list(size*size)  // Type (color) of ball

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

func UserLeftClick(btn)                    // for click on a button
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
              pDelVisit()
              pathTF = pathSrcDest(aSquare,hv,btn)
              if pathTF = 1

	      Button[btn] { seticon(new qicon(new qpixmap(cellType[hv])))
                            setIconSize(new qSize(65,65)) } 
              Button[hv] { seticon(new qicon(new qpixmap(C_EMPTY)))
                           setIconSize(new qSize(65,65)) }
              app.processevents()
              sleep(0.5)
              aSquare[btn] = 1
              aSquare[hv] = 0
              cellType[btn] = cellType[hv]
              cellType[hv] = C_EMPTY
              if start = 1 
                 newCells()      // place new three balls on table
              ok
              deleteCells()      // When you line up 5 balls of the same color horizontally,
                                 //v ertically or diagonally, the line disappears
              else
                 msgBox("Invalid move!")
              ok
        ok
     ok

//=================================

func newCells()
     for n = 1 to nrCell
         rnd = random(size*size-1) + 1
         cellStyle = random(5) + 1
         app.processevents()
         sleep(0.5)
         if cellType[rnd] = C_EMPTY
            button[rnd] { seticon(new qicon(new qpixmap(balls[cellStyle])))
                          setIconSize(new qSize(65,65)) }
            cellType[rnd] = balls[cellStyle]
            aSquare[rnd] = 1
         ok 
     next

//=================================

func newGame()
     pBegin()

//=================================

func pBegin()
     for btn = 1 to size*size
	 Button[btn] { seticon(new qicon(new qpixmap(C_EMPTY)))
                       setIconSize(new qSize(65,65))
                     }
         cellType[btn] = C_EMPTY
         aSquare[btn] = 0
     next

     for n = 1 to nrCell
         btn = random(size*size-1) + 1
         cellStyle = random(5) + 1
         button[btn] { seticon(new qicon(new qpixmap(balls[cellStyle])))
                       setIconSize(new qSize(65,65)) }
         cellType[btn] = balls[cellStyle]
         aSquare[btn] = 1
     next

//=================================

func deleteCells()
     bool = 0
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
             bool = bool1 and bool2 and bool3 and bool4 and bool5
             if bool = 1 
                for p = 0 to 4
                    Button[btn+p] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                    setIconSize(new qSize(65,65))
                                  }
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
             bool = bool1 and bool2 and bool3 and bool4 and bool5
             if bool = 1
                for p = 0 to 4
                    Button[btn+size*p] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                         setIconSize(new qSize(65,65))
                                       }
                next
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
             bool = bool1 and bool2 and bool3 and bool4 and bool5
             if bool = 1
                for p = 0 to 4
                    Button[btn+p*9] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                      setIconSize(new qSize(65,65))
                                    }
                next
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
             bool = bool1 and bool2 and bool3 and bool4 and bool5
             if bool = 1
                for p = 0 to 4
                    Button[btn+p*11] { seticon(new qicon(new qpixmap(C_EMPTY)))
                                       setIconSize(new qSize(65,65))
                                     }
                next
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

func gameOver()
     for btn = 1 to size*size
             if cellType[btn] != C_EMPTY
                gover = 1
             else
                gover = 0
                exit 
             ok
     next
     if gover = 1
        msgBox("Game Over!")
     ok

//=================================

func pDelVisit()

     for btn = 1 to size*size
         if aSquare[btn] = 'v'
            aSquare[btn] = 0
         ok
     next
//=================================

//---------------------------------------------------
// CALL  pathSrcDest(array, srcX, srcY, dstX, dstY)
// Return: True / False
//
// Path 6-5 to 2-10 ng , 6-5 to 1-4 ok , 6-5 to 10-6 ng ,  6-5 to 10-1 ok

Func pathSrcDest(aSquare,xy,st)

    //-------------------------------------
    // Find size of 2D Array => Rows x Cols
    Rows = len(aSquare)       // Size: 10     Rows
    Cols = len(aSquare)    // Size[1]: 10  Row-1 Cols

    srcXY = xy  //srcY = y
    dstXY = st  //dstY = t 

    VisitSquare(srcXY)
    //DisplaySquare()          // SHOW  aSquare with "v" visited results

    pathTF = CheckResult()
  
return pathTF

  
//===============================

Func DisplaySquare()
    ind = 0
    See nl
    for i = 1 to size
        for j = 1 to size
            ind = ind + 1
            See " " + aSquare[ind]
        next
        See nl
    next
return

//===============================
// Visit N,S,E,W  
// Value: 1 = Occupied, 0 = Empty 'V' = Visited  
//  NorthLine -10  =>     <  1
//  SouthLine +10  =>     > 81   
//  EastSide   +1  Mod =>    1
//  WestSide   -1  Mod =>    0

Func VisitSquare(xy)

// NORTH
   if ((xy-10) % Rows != 0) and (xy > size)
       if aSquare[xy-10] = 1  || aSquare[xy-10] = 'v'     
          
       else 
         aSquare[xy-10] = 'v'
         VisitSquare(xy-10)
       ok
   ok
         
//SOUTH
   if (xy+10) % Rows != 1 and xy < (size-1)*size
       if aSquare[xy+10] = 1  || aSquare[xy+10] = 'v'  
            
       else 
         aSquare[xy+10] = 'v'
         VisitSquare(xy+10)
       ok
   ok
                
// EAST 
   if (xy-1) > 0   
      if aSquare[xy-1] = 1   || aSquare[xy-1] = 'v'       
              
       else 
         aSquare[xy-1] = 'v'              
         VisitSquare(xy-1)
       ok  
   ok
         
   //WEST
   if (xy+1) <= Cols 
       if aSquare[xy+1] = 1   || aSquare[xy+1] = 'v'     
           
       else 
         aSquare[xy+1] = 'v'             
         VisitSquare(xy+1)
       ok                
   ok 

   //See "Exit - VisitSquare: xy "+x+"-"+y +nl   // Show Recursive calls
                                
return  

//==========================================

Func CheckResult()
   
    if aSquare[dstXY] = 'v'
        //See "CheckResult: Path Open.: "+ srcX +"-"+ srcY  +" To: "+ dstX +"-"+ dstY +" Value: "+ aSquare[dstX][dstY] +" TRUE" +nl
        return TRUE
    else
        //See "CheckResult: Path Block: "+ srcX +"-"+ srcY  +" To: "+ dstX +"-"+ dstY +" Value: "+ aSquare[dstX][dstY] +" FALSE" +nl
        return FALSE
    ok

return 

//===========================================

