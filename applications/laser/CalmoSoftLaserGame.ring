# Project : CalmoSoft Laser Game
# Date    : 19/01/2020
# Author  : Gal Zsolt (~ CalmoSoft ~), Bert Mariani
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

start = 1
size = 10
nrCell = 50
cellStatus = newlist(size,size)
emptyCell = "empty.jpg"
leftCell = "left.jpg"
rightCell = "right.jpg"
startCell = "start.jpg"
lineVer = "linever.jpg"
lineHor = "linehor.jpg"
linePlus = "plus.jpg"

cellDowntoLeft = "DowntoLeft.jpg"
cellDowntoRight = "DowntoRight.jpg"
cellLefttoDown = "LefttoDown.jpg"
cellLefttoUp = "LefttoUp.jpg"
cellRighttoDown = "RighttoDown.jpg"
cellRighttoUp = "RighttoUp.jpg"
cellUptoLeft = "UptoLeft.jpg"
cellUptoRight = "UptoRight.jpg"

dirCmB = null
nRow = 0
nCol = 1
bool = 1
bool1 = 0

Button = newlist(size,size)

app = new qApp 
{
      win = new qWidget() {
	    setWindowTitle('CalmoSoft Laser Game')
	    move(550,150)
	    reSize(600,650)

	    btnFire = new QPushButton(win)	
		      { setgeometry(60,620,40,20)
                        settext("Fire")
                        setclickevent("fire()")
                        show()		
                      }

	    btnNewGame = new QPushButton(win)	
		         { setgeometry(120,620,70,20)
                           settext("New Game")
                           setclickevent("newGame()")
                           show()		
                         }

	    btnSaveCells = new QPushButton(win)	
		           { setgeometry(210,620,70,20)
                             settext("Save Cells")
                             setclickevent("saveCells()")
                             show()		
                           }


	    btnLoadCells = new QPushButton(win)	
		           { setgeometry(300,620,70,20)
                             settext("Load Cells")
                             setclickevent("loadCells()")
                             show()		
                           }



            for Row = 1 to size
         	for Col = 1 to size
		    Button[Row][Col] = new QPushButton(win)	
				       { setgeometry((Col-1)*60,(Row-1)*60,60,60)
                                         seticon(new qicon(new qpixmap(emptyCell)))
                                         setclickevent("pselect(" + string(Row) + "," + string(Col) + ")")		
                                       }
                    cellStatus[Row][Col] = 0					
		next
            next
            show()
            pBegin()
   }
   exec()
}
//=================================

func fire()
     nRow = size
     nCol = 1
     start = 0
     //See nl+nl+"fire " ShowCellStatus()
     while bool = 1
           bool1 = 0
           moveStart()
           bool = bool1
     end

//=================================

func moveStart()

     if (cellStatus[nRow][nCol] = "up") and (cellStatus[nRow-1][nCol] = 0) 
         while not(cellStatus[nRow-1][nCol] = 1 or cellStatus[nRow-1][nCol] = 2) and nRow > 1
                app.processevents()
                sleep(0.3)
                button[nRow-1][nCol] { seticon(new qicon(new qpixmap(lineVer)))
                                       setIconSize(new qSize(50,50))
                                     }
                cellStatus[nRow-1][nCol] = "up"
                nRow = nRow - 1
                if nRow = 1
                   bool1 = 0
                   exit
                ok
                bool1 = 1
         end
         if nRow > 1
            nRow = nRow - 1
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 1
                  changeUptoRight()
               ok
            ok
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 2
                  changeRighttoDown()
               ok 
            ok
         ok     
     ok

     if cellStatus[size-1][1] = 2
        button[size-1][1] { seticon(new qicon(new qpixmap(cellUptoLeft)))
                            setIconSize(new qSize(50,50))
                          }
        cellStatus[size-1][1] = "left"
     ok

     if cellStatus[size-1][1] = 1
        button[size-1][1] { seticon(new qicon(new qpixmap(cellUptoRight)))
                            setIconSize(new qSize(50,50))
                          }
        cellStatus[size-1][1] = "right"
        nRow = size - 1
        moveRight()
     ok

//================================= !!!

func changeLefttoDown()
     app.processevents()
     sleep(0.3)
     button[nRow][nCol] { seticon(new qicon(new qpixmap(cellLefttoDown)))
                          setIconSize(new qSize(50,50))
                        }
     moveDown()

//=================================


func changeDowntoRight()
     app.processevents()
     sleep(0.3)
     button[nRow][nCol] { seticon(new qicon(new qpixmap(cellDowntoRight)))
                          setIconSize(new qSize(50,50))
                        }
     moveRight()

//=================================

func changeRighttoUp()

     app.processevents()
     sleep(0.3)
     button[nRow][nCol] { seticon(new qicon(new qpixmap(cellRighttoUp)))
                          setIconSize(new qSize(50,50))
                        }
     if cellStatus[nRow-1][nCol] = 2
        button[nRow-1][nCol] { seticon(new qicon(new qpixmap(cellUptoLeft)))
                               setIconSize(new qSize(50,50))
                             }
        nRow = nRow - 1
        moveLeft()
     else
        moveUp()
     ok

//=================================

func changeDowntoLeft()
     app.processevents()
     sleep(0.3)
     button[nRow][nCol] { seticon(new qicon(new qpixmap(cellDowntoLeft)))
                          setIconSize(new qSize(50,50))
                        }
     moveLeft()

//=================================

func changeRighttoDown()
     app.processevents()
     sleep(0.3)
     button[nRow][nCol] { seticon(new qicon(new qpixmap(cellRighttoDown)))
                          setIconSize(new qSize(50,50))
                        }
     moveDown()

//=================================

func changeUptoRight()
     app.processevents()
     sleep(0.3)
     button[nRow][nCol] { seticon(new qicon(new qpixmap(cellUptoRight)))
                          setIconSize(new qSize(50,50))
                        }
     if nCol < size   
        moveRight()
     ok

//=================================

func changeUptoLeft()
     app.processevents()
     sleep(0.3)
     button[nRow][nCol] { seticon(new qicon(new qpixmap(cellUptoLeft)))
                          setIconSize(new qSize(50,50))
                        }
     moveLeft()

//=================================

func changeLefttoUp()
     app.processevents()
     sleep(0.3)
     button[nRow][nCol] { seticon(new qicon(new qpixmap(cellLefttoUp)))
                          setIconSize(new qSize(50,50))
                        }
     moveUp()  

//=================================

func moveRight()
         while not(cellStatus[nRow][nCol+1] = 1 or cellStatus[nRow][nCol+1] = 2)
                app.processevents()
                sleep(0.3)
                button[nRow][nCol+1] { seticon(new qicon(new qpixmap(lineHor)))
                                       setIconSize(new qSize(50,50))
                                     }
                cellStatus[nRow][nCol+1] = "right"
                nCol = nCol + 1
                if nCol = size 
                   bool1 = 0  
                   exit
                ok
         end
         nCol = nCol + 1
         if nCol < size + 1
            // ShowCellStatus()
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 1
                  changeRighttoUp()
               ok
            ok
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 2
                  changeRighttoDown()
               ok
            ok
         ok

//=================================

func moveLeft()
         while not(cellStatus[nRow][nCol-1] = 1 or cellStatus[nRow][nCol-1] = 2)
                app.processevents()
                sleep(0.3)
                button[nRow][nCol-1] { seticon(new qicon(new qpixmap(lineHor)))
                                       setIconSize(new qSize(50,50))
                                     }
                cellStatus[nRow][nCol-1] = "left"
                nCol = nCol - 1
                if nCol = 1 
                   bool1 = 0   
                   exit
                ok
         end
         nCol = nCol - 1
         if nCol > 0 
            // ShowCellStatus()
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 1
                  changeLefttoDown()  
               ok
            ok
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 2
                  changeLefttoUp()
               ok
            ok
         ok

//=================================

func moveDown()
         while not(cellStatus[nRow+1][nCol] = 1 or cellStatus[nRow+1][nCol] = 2)
                app.processevents()
                sleep(0.3)
                button[nRow+1][nCol] { seticon(new qicon(new qpixmap(lineVer)))
                                       setIconSize(new qSize(50,50))
                                     }
                cellStatus[nRow+1][nCol] = "down"
                nRow = nRow + 1
                if nRow = size
                   bool1 = 0  
                   exit
                ok
         end
         nRow = nRow + 1
         if nRow < size + 1
            // ShowCellStatus()
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 1
                  changeDowntoLeft()
               ok
            ok
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 2
                   changeDowntoRight()             
               ok
            ok
         ok

//=================================

func moveUp()
         while not(cellStatus[nRow-1][nCol] = 1 or cellStatus[nRow-1][nCol] = 2)
                app.processevents()
                sleep(0.3)
                button[nRow-1][nCol] { seticon(new qicon(new qpixmap(lineVer)))
                                       setIconSize(new qSize(50,50))
                                     }
                cellStatus[nRow-1][nCol] = "up"
                nRow = nRow - 1
                if nRow = 1
                   bool1 = 0  
                   exit
                ok
         end
         //nRow = nRow + 1
         //if nRow < size + 1
         nRow = nRow - 1
         if nRow > 0
            // ShowCellStatus()
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 1
                  changeUptoRight()
               ok
            ok
            if nRow > 0 and nRow < size + 1 and nCol > 0 and nCol < size + 1
               if cellStatus[nRow][nCol] = 2
                  changeUptoLeft()
               ok
            ok
         ok

//=================================

func newGame()
     start = 1
     pbegin()

//=================================

func pselect(Row,Col)
     DirCmB = new qcombobox(win) {
    	      move((Col-1)*60,(Row-1)*60)
              resize(60,20)
              setstylesheet("color:black;background-color:;")
              oFont = new qfont("",0,0,0)
              oFont.fromstring("Arial")
              setfont(oFont)
              oFont.delete()
              aList = ["Left", "Right", "Up", "Down", "Rot Left", "Rot Right"]
              for x in aList additem(x,0) next
              setcurrentIndex(0)
              setactivatedEvent("changeStatus(" + string(Row) + "," + string(Col) + ")")
              seteditTextChangedEvent("")
              sethighlightedEvent("")
              show() }

func changeStatus(Row, Col)

     if DirCmB.currentindex() = 0
        bool1 = (cellStatus[Row][Col-1] = "left")
        bool2 = (cellStatus[Row][Col-1] = "right")
        bool3 = (cellStatus[Row][Col-1] = "up")
        bool4 = (cellStatus[Row][Col-1] = "down")
        bool = not(bool1 or bool2 or bool3 or bool4)
        if (Col > 1) and (cellStatus[Row][Col-1] = 0) and bool
           button[Row][Col] { seticon(new qicon(new qpixmap(emptyCell))) }
           if cellStatus[Row][Col] = 1
              button[Row][Col-1] { seticon(new qicon(new qpixmap(leftCell))) }
              cellStatus[Row][Col-1] = 1
           ok
           if cellStatus[Row][Col] = 2
              button[Row][Col-1] { seticon(new qicon(new qpixmap(rightCell))) }
              cellStatus[Row][Col-1] = 2
           ok
           cellStatus[Row][Col] = 0
        ok        
     ok

     if DirCmB.currentindex() = 1
        bool1 = (cellStatus[Row][Col+1] = "left")
        bool2 = (cellStatus[Row][Col+1] = "right")
        bool3 = (cellStatus[Row][Col+1] = "up")
        bool4 = (cellStatus[Row][Col+1] = "down")
        bool = not(bool1 or bool2 or bool3 or bool4)
        if (Col < size) and (cellStatus[Row][Col+1] = 0) and bool
           button[Row][Col] { seticon(new qicon(new qpixmap(emptyCell))) }
           if cellStatus[Row][Col] = 1
              button[Row][Col+1] { seticon(new qicon(new qpixmap(leftCell))) }
              cellStatus[Row][Col+1] = 1
           ok
           if cellStatus[Row][Col] = 2
              button[Row][Col+1] { seticon(new qicon(new qpixmap(rightCell))) }
              cellStatus[Row][Col+1] = 2
           ok
           cellStatus[Row][Col] = 0
        ok        
     ok

     if DirCmB.currentindex() = 2
        bool1 = (cellStatus[Row-1][Col] = "left")
        bool2 = (cellStatus[Row-1][Col] = "right")
        bool3 = (cellStatus[Row-1][Col] = "up")
        bool4 = (cellStatus[Row-1][Col] = "down")
        bool = not(bool1 or bool2 or bool3 or bool4)
        if (Row > 1) and (cellStatus[Row-1][Col] = 0) and bool
           button[Row][Col] { seticon(new qicon(new qpixmap(emptyCell))) }
           if cellStatus[Row][Col] = 1
              button[Row-1][Col] { seticon(new qicon(new qpixmap(leftCell))) }
              cellStatus[Row-1][Col] = 1
           ok
           if cellStatus[Row][Col] = 2
              button[Row-1][Col] { seticon(new qicon(new qpixmap(rightCell))) }
              cellStatus[Row-1][Col] = 2
           ok
           cellStatus[Row][Col] = 0
        ok        
     ok

     if DirCmB.currentindex() = 3
        bool1 = (cellStatus[Row+1][Col] = "left")
        bool2 = (cellStatus[Row+1][Col] = "right")
        bool3 = (cellStatus[Row+1][Col] = "up")
        bool4 = (cellStatus[Row+1][Col] = "down")
        bool = not(bool1 or bool2 or bool3 or bool4)
        if (Row < size) and (cellStatus[Row+1][Col] = 0)
           button[Row][Col] { seticon(new qicon(new qpixmap(emptyCell))) }
           if cellStatus[Row][Col] = 1
              button[Row+1][Col] { seticon(new qicon(new qpixmap(leftCell))) }
              cellStatus[Row+1][Col] = 1
           ok
           if cellStatus[Row][Col] = 2
              button[Row+1][Col] { seticon(new qicon(new qpixmap(rightCell))) }
              cellStatus[Row+1][Col] = 2
           ok
           cellStatus[Row][Col] = 0
        ok        
     ok


     if DirCmB.currentindex() = 4
        if cellStatus[Row][Col] = 2
           button[Row][Col] { seticon(new qicon(new qpixmap(leftCell))) }
           cellStatus[Row][Col] = 1
        ok        
     ok

     if DirCmB.currentindex() = 5
        if cellStatus[Row][Col] = 1
           button[Row][Col] { seticon(new qicon(new qpixmap(rightCell))) }
           cellStatus[Row][Col] = 2
        ok        
     ok

     DirCmB.delete() 

     //See nl+nl+"changeStatus "+ ShowCellStatus()

//=================================

func pBegin()

     bool = 1
     bool1 = 0
     start = 1

     for Row = 1 to size
         for Col = 1 to size
	     Button[Row][Col] { seticon(new qicon(new qpixmap(emptyCell)))
                                setIconSize(new qSize(50,50))
                              }
             cellStatus[Row][Col] = 0
					
	 next
     next

     for n = 1 to nrCell
         rowRnd = random(size-1) + 1
         colRnd = random(size-1) + 1
            cellStyle = random(2) + 1
            switch cellStyle {
                   case 1
                        button[rowRnd][colRnd] { seticon(new qicon(new qpixmap(leftCell)))
                                                 setIconSize(new qSize(50,50))
                                               }
                        cellStatus[rowRnd][colRnd] = 1
                   case 2
                        button[rowRnd][colRnd] { seticon(new qicon(new qpixmap(rightCell)))
                                                 setIconSize(new qSize(50,50))
                                               }
                        cellStatus[rowRnd][colRnd] = 2
            }
     next

     button[1][size] { seticon(new qicon(new qpixmap(startCell))) }
     button[size][1] { seticon(new qicon(new qpixmap(lineVer))) }
     cellStatus[size][1] = "up"

     //See nl+nl+"pBegin " ShowCellStatus()

//=================================

func pExit()
     win.close()
     app.quit()

//=================================

func saveCells()

     if start = 1
        See nl+nl+"saveCells "    ShowCellStatus()   See nl+nl  
        fp = fopen("CellStatus.txt","w")
        for n = 1 to size
            for m = 1 to size
		See "saveCells: n-m: "+ n +"-"+ m +" = "+ cellStatus[n][m] +nl
		if n = size and m = 1
                   aString = string(n) + "," + string(m) + "," + cellStatus[n][m] + windowsnl()
                else
                   aString = string(n) + "," + string(m) + "," + string(cellStatus[n][m]) + windowsnl()
                ok
                fwrite(fp,aString)
            next
        next
     ok

//=================================

func loadCells()

     fp = fopen("CellStatus.txt","r")
     aString = ""
     bString = ""
     while isstring(aString)
           aString = fgetc(fp)
           if aString = char(10)
              aList = split(bString,",")
              nn = aList[1]
              mm = aList[2]
              stat = aList[3]
              cellStatus[number(nn)][number(mm)] = number(stat)
              aList = []
              bString = ""
           else
              bString = bString + aString
           ok
     end
     fclose(fp)


     bool = 1
     bool1 = 0
     for Row = 1 to size
         for Col = 1 to size
             switch cellStatus[Row][Col] {
                    case 0 
	                 Button[Row][Col] { seticon(new qicon(new qpixmap(emptyCell)))
                                            setIconSize(new qSize(50,50))
                                          }

                    case 1 
	                 Button[Row][Col] { seticon(new qicon(new qpixmap(leftCell)))
                                            setIconSize(new qSize(50,50))
                                          }

                    case 2 
	                 Button[Row][Col] { seticon(new qicon(new qpixmap(rightCell)))
                                            setIconSize(new qSize(50,50)) }
                                          }
	 next
     next
     button[1][size] { seticon(new qicon(new qpixmap(startCell))) }
     button[size][1] { seticon(new qicon(new qpixmap(lineVer))) }
     cellStatus[size][1] = "up"

     //See nl+nl+"loadCells " ShowCellStatus()

//===============================
// Use 1st letter of Cell Status

Func ShowCellStatus()

     See nl+nl+"ShowCellStatus"+ nl
     See "    _1_2_3_4_5_6_7_8_9_0__ "+ nl
   
     See "  1|"
     for Row = 1 to size
       for Col = 1 to size
           value = ""+ cellStatus[Row][Col]     
           if value[1] = "0" value[1] = " "  ok
           
                See " "+ Upper(value[1]) +""
       next       
       
       NextRow = Row+1
       if NextRow = 11
               return
            ok
       if NextRow = 10
               NextRow = 0 
            ok
            See nl +"  "+ NextRow +"|"
       
     next
      
return

//--------------------------------
