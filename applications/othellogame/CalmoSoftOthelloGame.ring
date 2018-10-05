# Project : Othello Game
# Date    : 2018/09/27
# Author : Gal Zsolt (~ CalmoSoft ~), Bert Mariani
# Email   : <calmosoft@gmail.com>

load "stdlib.ring"
load "guilib.ring"

size = 8
move = 1
score = 0
flag = 0

summoveblack = 0
summovewhite = 0

C_SPACING = 2 ### was 5

C_EMPTYBUTTONSTYLE  = 'border-radius:5px;background-color:gray'
C_BUTTONBLACKSTYLE  = 'border-radius:5px;color:black; background-color: black'
C_BUTTONWHITESTYLE  = 'border-radius:5px;color:black; background-color: white'
C_BUTTONORANGESTYLE = 'border-radius:5px;color:black; background-color: orange'

C_ButtonBlueStyle     = 'border-radius:5px;color:black; background-color: Cyan'
C_ButtonYellowStyle   = 'border-radius:5px;color:black; background-color: Yellow'

button = newlist(size+1,size)
btnblack = newlist(size,size)
btnwhite = newlist(size,size)
LayoutButtonRow = list(size+4)

cols = list(size+1)
rows = list(size)
colcells = [" ","A","B","C","D","E","F","G","H"]

TransScript = list(1)
MoveNumber  = 1

###=====================================================

app = new qApp {
         STYLEFusion()
         win = new qWidget() {
                  setWindowTitle('Othello Game')
		  setStyleSheet('background-color:green')
				  
                  move(490,100)
                  resize(600,600)
                  winheight = win.height()
                  fontsize = 8 + (winheight/70)
				  
                  playscoreblack = new QLabel(win) {
                                          setFont(new qFont("Verdana",fontsize,100,0))
                                          setstylesheet(C_ButtonBlueStyle)
                                          setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                          settext("Black Score: 2")
                                          show()
                                          }

                  playscorewhite = new QLabel(win) {
                                           setFont(new qFont("Verdana",fontsize,100,0))
                                           setstylesheet(C_ButtonYellowStyle)
                                           setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                           settext("White Score: 2")
                                           show()
                                           }

                  nextmove = new QLabel(win) {
                                    setFont(new qFont("Verdana",fontsize,100,0))
                                    setstylesheet(C_BUTTONORANGESTYLE)
                                    setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                    settext("Next Move: Black ")
                                    show()
                                    } 

                  newgame  = new QPushButton(win) {
                                     setFont(new qFont("Verdana",fontsize,100,0))
                                     setstylesheet("background-color:violet")
                                     settext("New Game")
                                     setclickevent("pstart()")
                                     show()
                                     }

                  for n = 1 to size+1
                       cols[n] = new QLabel(win) {
                                    setFont(new qFont("Verdana",fontsize,100,0))
                                    setstylesheet(C_BUTTONBLUESTYLE)
                                    setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                    settext(colcells[n])
                                    }
                  next
                  for n = 1 to size
                       rows[n] = new QLabel(win) {
                                     setFont(new qFont("Verdana",fontsize,100,0))
                                     setstylesheet(C_BUTTONBLUESTYLE)
                                     setalignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                     settext(string(n))
                                     }
                  next
	
                  LayoutButtonMain = new QVBoxLayout()
                  LayoutButtonMain.setSpacing(C_SPACING)
                  LayoutButtonMain.setContentsmargins(0,0,0,0)
				  
                  LayoutButtonColCells = new QHBoxLayout()
                  LayoutButtonColCells.setSpacing(C_SPACING)
                  LayoutButtonColCells.setContentsmargins(0,0,0,0)
				  

		###=================================================
		### Title Top Row - LETTERS  @ A B C D E F G H
		
		TitleLet = list(9)	### Array of qLabel Object
		
		Number = 64  			### @ A B .. H

		for Col = 1 to 9
			Letter = hex2str( hex(Number))
			TitleLet[Col] = new qLabel(win) { setFont(new qFont("Verdana",fontsize,100,0))
                                            setAlignment(Qt_AlignHCenter | Qt_AlignVCenter) 
                                            setStyleSheet("background-color:darkgray") 
                                            setText(Letter) } 
			Number++				
		next
				
			###------------------------------------------------------------------------------
			### QVBoxLayout lays out BUTTON Widgets in a vertical column, from top to bottom.
			### Horizontal ROWS - 1 2 3 4 5 6 7 8
		
	
			LayoutTitleRow = new QHBoxLayout() { setSpacing(C_Spacing)
                                                 setContentsMargins(0,0,0,0) }

				for Col = 1 to 9				
					LayoutTitleRow.AddWidget(TitleLet[Col])			
				next
							
			LayoutButtonMain.AddLayout(LayoutTitleRow)	### Layout - Add  TITLE-ROW on TOP
			

		###----------------------------------------------
		### BUTTON ROWS

		TitleNum = list(9)	### Array of qLabel Object

		for Col = 1 to 8
			Letter = ""+ Col
			TitleNum[Col] = new qLabel(win) { setFont(new qFont("Verdana",fontsize,100,0)) 
                                               setAlignment(Qt_AlignHCenter | Qt_AlignVCenter) 
                                               setStyleSheet("background-color:darkgray")
                                               setText(Letter) } 
			Number++			
			
		next
	  

			###-----------------------------------------------------------------------
			### QHBoxLayout lays out widgets in a horizontal row, from left to right
				
			for Row = 1 to size
				LayoutButtonRow[Row] = new QHBoxLayout()	### Horizontal
				{
					setSpacing(C_Spacing)
					setContentsmargins(0,0,0,0)
				} 

			   LayoutButtonRow[Row].AddWidget(TitleNum[Row])
			   
			   for Col = 1 to size
					Button[Row][Col] = new QPushButton(win)	### Create Buttons
					{
						setStyleSheet(C_EmptyButtonStyle)			
						setClickEvent("pplay(" + string(Row) + "," + string(Col) + ")")
						setSizePolicy(1,1)
					}
					
					LayoutButtonRow[Row].AddWidget(Button[Row][Col])	### Widget - Add HORZ BOTTON
			   next
			   
			   LayoutButtonMain.AddLayout(LayoutButtonRow[Row])		### Layout - Add ROW of BUTTONS
			next

			###=======================================================
			### Horizontal Row Bottom
				LayoutDataRow = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }
				  
					LayoutDataRow.AddWidget(playscoreblack) 
					LayoutDataRow.AddWidget(playscorewhite) 
					LayoutDataRow.AddWidget(nextmove) 
  

				LayoutButtonMain.AddLayout(LayoutDataRow)
				LayoutButtonMain.AddWidget(newgame)

            setLayout(LayoutButtonMain)
            pstart()
            show()
   }
   exec()
 }

###---------------------------------------
func pstart()
       move = 1
       score = 0 
       flag = 0
       MoveNumber  = 1
       TransScript = list(1)
       for col = 1 to size
            for row = 1 to size
                 btnblack[col][row] = 0
                 btnwhite[col][row] = 0
                 button[col][row].setenabled(true)
                 button[col][row] { setstylesheet(C_EMPTYBUTTONSTYLE) }
            next
       next
       nextmove.settext("Next Move: Black ")
       playscoreblack.settext("Black Score: 2")
       playscorewhite.settext("White Score: 2")

       button[4][4].setenabled(false)
       button[5][5].setenabled(false)
       button[4][5].setenabled(false)
       button[5][4].setenabled(false)

       button[4][4] { setstylesheet(C_BUTTONBLACKSTYLE) }
       button[5][5] { setstylesheet(C_BUTTONBLACKSTYLE) }
       button[4][5] { setstylesheet(C_BUTTONWHITESTYLE) }
       button[5][4] { setstylesheet(C_BUTTONWHITESTYLE) }

       btnblack[4][4] = 1
       btnblack[5][5] = 1
       btnwhite[4][5] = 1
       btnwhite[5][4] = 1

func summove()
       summoveblack = 0
       summovewhite = 0

       for col = 1 to size
            for row = 1 to size
                 if btnblack[col][row] = 1
                    summoveblack = summoveblack + 1
                 ok
                 if btnwhite[col][row] = 1
                    summovewhite = summovewhite + 1
                 ok 
            next
       next

       playscoreblack.settext("Black Score: " + string(summoveblack))
       playscorewhite.settext("White Score: " + string(summovewhite))

###---------------------------------------------

func pplay(n,m)
       flag = 0
       Letter = char(64 + m)
       if move = 1
	  MovePlayed = ""+ MoveNumber +"-"+ "B" +"-"+ n +"-"+ Letter
	  nextmove.settext("Next Move: White ")    
       else
	  MovePlayed = ""+ MoveNumber +"-"+ "W" +"-"+ n +"-"+ Letter 
	  nextmove.settext("Next Move: Black ") 
       ok 
       TranScript = Add(TransScript, MovePlayed)
       MoveNumber++
       see "TransScript: "+nl  see TransScript  see nl+nl

       if move = 1
          move = 0
          button[n][m].setenabled(false)
          button[n][m] { setstylesheet(C_BUTTONBLACKSTYLE) }
          btnblack[n][m] = 1
          pcheck(n,m,"black")
          summove()
          return
       ok
       if move = 0
          move = 1
          button[n][m].setenabled(false)
          button[n][m] { setstylesheet(C_BUTTONWHITESTYLE) }
          btnwhite[n][m] = 1
          pcheck(n,m,"white")
          summove()
          return
       ok

func pcheckright(n,m,bw)
       if bw = "black"
       pos = 0
       for x = n+1 to size
            if btnwhite[x][m] = 1
               loop
            ok
            if btnblack[x][m] = 1
               pos = x
               exit
            ok
       next
       if pos > n+1 and btnblack[pos][m] = 1 
          flag = 1
          for nc = n+1 to pos - 1
               see "nc = " + nc + " m = " + m + nl
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[nc][m] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[nc][m] = 0
               btnblack[nc][m] = 1
          next
       ok
       ok
       if bw = "white"
       pos = 0
       for x = n+1 to size-1
            if btnblack[x][m] = 1
               loop
            else
               pos = x
               exit
            ok
       next
       if pos > n+1 and btnwhite[pos][m] = 1 
          flag = 1
          for nc = n+1 to pos - 1
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[nc][m] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[nc][m] = 0
               btnwhite[nc][m] = 1
          next
       ok
       ok

func pcheckleft(n,m,bw)
       if bw = "black"
       pos = 0
       for x = n-1 to 1 step -1
            if btnwhite[x][m] = 1
               loop
            else
               pos = x
               exit
            ok
       next
       if pos < n-1 and btnblack[pos][m] = 1 
          flag = 1
          for nc = n-1 to pos step -1
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[nc][m] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[nc][m] = 0
               btnblack[nc][m] = 1
          next
       ok
       ok
       if bw = "white"
       pos = 0
       for x = n-1 to 1 step -1
            if btnblack[x][m] = 1
               loop
            else
               pos = x
               exit
            ok
       next
       if pos < n-1 and btnwhite[pos][m] = 1 
          flag = 1
          for nc = n-1 to pos step -1
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[nc][m] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[nc][m] = 0
               btnwhite[nc][m] = 1
          next
       ok
       ok

func pcheckdown(n,m,bw)
       if bw = "black"
       pos = 0
       for y = m+1 to size-1
            if btnwhite[n][y] = 1
               loop
            else
               pos = y
               exit
            ok
       next
       if pos > m+1 and btnblack[n][pos] = 1 
          flag = 1
          for nr = m+1 to pos - 1
               button[nr][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n][nr] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n][nr] = 0
               btnblack[n][nr] = 1
          next
       ok
       ok
       if bw = "white"
       pos = 0
       for y = m+1 to size-1
            if btnblack[n][y] = 1
               loop
            else
               pos = y
               exit
            ok
       next
       if pos > m+1 and btnwhite[n][pos] = 1 
          flag = 1
          for nr = m+1 to pos - 1
               button[n][nr].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n][nr] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n][nr] = 0
               btnwhite[n][nr] = 1
          next
       ok
       ok

func pcheckup(n,m,bw)
       if bw = "black"
       pos = 0
       for x = m-1 to 1 step -1
            if btnwhite[n][x] = 1
               loop
            else
               pos = x
               exit
            ok
       next
       if pos < m-1 and btnblack[n][pos] = 1 
          flag = 1
          for nc = m-1 to pos step -1
               button[nc][m].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n][nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n][nc] = 0
               btnblack[n][nc] = 1
          next
       ok
       ok
       if bw = "white"
       pos = 0
       for x = m-1 to 1 step -1
            if btnblack[n][x] = 1
               loop
            else
               pos = x
               exit
            ok
       next
       if pos < m-1 and btnwhite[n][pos] = 1 
          flag = 1
          for nc = m-1 to pos step -1
               button[n][nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n][nc] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n][nc] = 0
               btnwhite[n][nc] = 1
          next
       ok
       ok

func pcheckdiagdownright(n,m,bw)
       if bw = "black"
       pos1 = 0
       pos2 = 0
       for x = 1 to size
            if (n+x) < size and (m+x) < size
               if btnwhite[n+x][m+x] = 1
                  loop
               else
                  pos1 = n+x
                  pos2 = m+x
                  exit
               ok
            else
               exit
            ok
       next
       if pos1 > n and btnblack[pos1][pos2] = 1 
          flag = 1
          for nc = 1 to x
               button[n+nc][m+nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n+nc][m+nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n+nc][m+nc] = 0
               btnblack[n+nc][m+nc] = 1
          next
       ok
       ok
       if bw = "white"
       pos1 = 0
       pos2 = 0
       for x = 1 to size
            if (n+x) < (size+1) and (m+x) < (size+1)
               if btnblack[n+x][m+x] = 1
                  loop
               else
                  pos1 = n+x
                  pos2 = m+x
                  exit
               ok
            else
               exit
            ok
       next
       if pos1 > n and btnwhite[pos1][pos2] = 1 
          flag = 1
          for nc = 1 to x
               button[n+nc][m+nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n+nc][m+nc] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n+nc][m+nc] = 0
               btnwhite[n+nc][m+nc] = 1
          next
       ok
       ok

func pcheckdiagdownleft(n,m,bw)
       if bw = "black"
       pos1 = 0
       pos2 = 0
       for x = 1 to size
            if (n-x) < size and (m+x) < size and (n-x) > 0
               if btnwhite[n-x][m+x] = 1
                  loop
               else
                  pos1 = n-x
                  pos2 = m+x
                  exit
               ok
            else
               exit
            ok
       next
       if pos1 > 0 and pos2 > 0
          if pos1 < n-1 and btnblack[pos1][pos2] = 1 
             flag = 1
             for nc = 1 to x
                  button[n-nc][m+nc].setenabled(false)
                  app.processevents()
                  sleep(0.5)
                  button[n-nc][m+nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
                  btnwhite[n-nc][m+nc] = 0
                  btnblack[n-nc][m+nc] = 1
             next
          ok
       ok
       ok
       if bw = "white"
       pos1 = 0
       pos2 = 0
       for x = 1 to size
            if (n-x) < size and (m+x) < size and (n-x) > 0
               if btnblack[n-x][m+x] = 1
                  loop
               else
                  pos1 = n-x
                  pos2 = m+x
                  exit
               ok
            else
               exit
            ok
       next
       if pos1 > 0 and pos2 > 0
          if pos1 < n-1 and btnwhite[pos1][pos2] = 1 
             flag = 1
             for nc = 1 to x
                  button[n-nc][m+nc].setenabled(false)
                  app.processevents()
                  sleep(0.5)
                  button[n-nc][m+nc] { setstylesheet(C_BUTTONWHITESTYLE) }
                  btnblack[n-nc][m+nc] = 0
                  btnwhite[n-nc][m+nc] = 1
             next
          ok
       ok
       ok

func pcheckdiagupright(n,m,bw)
       if bw = "black"
       pos1 = 0
       pos2 = 0
       for x = 1 to size
            if (n+x) > 1 and (m-x) > 1 and (n+x) < size and (m-x) < size
               if btnwhite[n+x][m-x] = 1
                  loop
               else
                  pos1 = n+x
                  pos2 = m-x
                  exit
               ok
            else
               exit
            ok
       next
       if pos1 > n+1 and btnblack[pos1][pos2] = 1 
          flag = 1
          for nc = 1 to x
               button[n+nc][m-nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n+nc][m-nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n+nc][m-nc] = 0
               btnblack[n+nc][m-nc] = 1
          next
       ok
       ok
       if bw = "white"
       pos1 = 0
       pos2 = 0
       for x = 1 to size
            if (n-x) > 0 and (m-x) > 0
               if btnblack[n-x][m-x] = 1
                  loop
               else
                  pos1 = n-x
                  pos2 = m-x
                  exit
               ok
            else
               exit
            ok
       next
       if pos1 > 0 and btnwhite[pos1][pos2] = 1 
          flag = 1
          for nc = 1 to x
               button[n-nc][m-nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n-nc][m-nc] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n-nc][m-nc] = 0
               btnwhite[n-nc][m-nc] = 1
          next
       ok
       ok

func pcheckdiagupleft(n,m,bw)
       if bw = "black"
       pos1 = 0
       pos2 = 0
       for x = 1 to size
            if (n-x) > 0 and (m-x) > 0
               if btnwhite[n-x][m-x] = 1
                  loop
               else
                  pos1 = n-x
                  pos2 = m-x
                  exit
               ok
            else
               exit
            ok
       next
       if pos1 > 0 and btnblack[pos1][pos2] = 1 
          flag = 1
          for nc = 1 to x
               button[n-nc][m-nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n-nc][m-nc] { setstylesheet(C_BUTTONBLACKSTYLE) }
               btnwhite[n-nc][m-nc] = 0
               btnblack[n-nc][m-nc] = 1
          next
       ok
       ok
       if bw = "white"
       pos1 = 0
       pos2 = 0
       for x = 1 to size
            if (n-x) > 0 and (m-x) > 0
               if btnblack[n-x][m-x] = 1
                  loop
               else
                  pos1 = n-x
                  pos2 = m-x
                  exit
               ok
            else
               exit
            ok
       next
       if pos1 > 0 and btnwhite[pos1][pos2] = 1 
          flag = 1
          for nc = 1 to x
               button[n-nc][m-nc].setenabled(false)
               app.processevents()
               sleep(0.5)
               button[n-nc][m-nc] { setstylesheet(C_BUTTONWHITESTYLE) }
               btnblack[n-nc][m-nc] = 0
               btnwhite[n-nc][m-nc] = 1
          next
       ok
       ok

func pcheck(n,m,bw)
       pcheckright(n,m,bw)
       pcheckok(n,m)
       pcheckleft(n,m,bw)
       pcheckok(n,m)
       pcheckok(n,m)
       pcheckdown(n,m,bw)
       pcheckok(n,m)
       pcheckup(n,m,bw)
       pcheckok(n,m)
       pcheckdiagdownright(n,m,bw)
       pcheckok(n,m)
       pcheckdiagdownleft(n,m,bw)
       pcheckok(n,m)
       pcheckdiagupright(n,m,bw)
       pcheckok(n,m)
       pcheckdiagupleft(n,m,bw)
       pcheckok(n,m)

func pcheckok(n,m)
       if flag = 1
          button[n][m].setenabled(false)
          return
       ok

func msgBox(cText) 
	mb = new qMessageBox(win) {
	        setWindowTitle('Othello Game')
	        setText(cText)
                setstandardbuttons(QMessageBox_OK) 
                result = exec()
        }
        return
