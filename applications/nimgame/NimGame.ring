# Project : CalmoSoft Nim Game
# Date    : 16/04/2020-13:27:07
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlibcore.ring"
load "lightguilib.ring"

limit = 4
limit1 = 1
limit2 = 3
limit3 = 5
limit4 = 7

match1 = limit1
match2 = limit2
match3 = limit3
match4 = limit4

move1 = 0
move2 = 0
move3 = 0
move4 = 0

Button1 = list(limit1)
Button2 = list(limit2)
Button3 = list(limit3)
Button4 = list(limit4)

pcMove = 0

width = 60
height = 60

yourScore = 0
pcScore = 0

C_FONTSIZE = 15
C_NIM = "images/nim.jpg"
C_COMPUTER = "images/computer.jpg"
C_PROGRAMMER = "images/programmer.jpg"

app = new qApp 
{
      win = new qWidget() {
            app.StyleFusionBlack()
	    setWindowTitle('CalmoSoft Nim Game')
	    setWinIcon(self,"images/nim.jpg")
	    setWindowFlags(Qt_SplashScreen | Qt_CustomizeWindowHint) 
	    reSize(620,460)

            for Col = 1 to limit1
		Button1[Col] = new QPushButton(win) {
                          y = 230+(Col-1)*height
                          setgeometry(y+10,70,width,height)
                          setSizePolicy(1,1)
                          seticon(new qicon(new qpixmap(C_NIM)))                        
                          setIconSize(new qSize(60,60))
                          }				       
	    next

            for Col = 1 to limit2
		Button2[Col] = new QPushButton(win) {
                          y = 170+(Col-1)*height
                          setgeometry(y+10,150,width,height)
                          setSizePolicy(1,1)
                          seticon(new qicon(new qpixmap(C_NIM)))                        
                          setIconSize(new qSize(60,60))
                          }				       
	    next

            for Col = 1 to limit3
		Button3[Col] = new QPushButton(win) {
                          y = 110+(Col-1)*height
                          setgeometry(y+10,230,width,height)
                          setSizePolicy(1,1)
                          seticon(new qicon(new qpixmap(C_NIM)))                        
                          setIconSize(new qSize(60,60))
                          }				       
	    next

            for Col = 1 to limit4
		Button4[Col] = new QPushButton(win) {
                          y = 50+(Col-1)*height
                          setgeometry(y+10,310,width,height)
                          setSizePolicy(1,1)
                          seticon(new qicon(new qpixmap(C_NIM)))                        
                          setIconSize(new qSize(60,60))
                          }				       
	    next

	    Row1 = new QPushButton(win) {
                   setgeometry(500,70,width,height)
                   setStyleSheet("color:Black;background-color:Orange")
                   setSizePolicy(1,1)
                   setclickevent("deleteRow1()")
                   settext("Row1") }


	    Row2 = new QPushButton(win) {
                   setgeometry(500,150,width,height)
                   setStyleSheet("color:Black;background-color:Orange")
                   setSizePolicy(1,1)
                   setclickevent("deleteRow2()")
                   settext("Row2") }


	    Row3 = new QPushButton(win) {
                   setgeometry(500,230,width,height)
                   setStyleSheet("color:Black;background-color:Orange")
                   setSizePolicy(1,1)
                   setclickevent("deleteRow3()")
                   settext("Row3") }


	    Row4 = new QPushButton(win) {
                   setgeometry(500,310,width,height)
                   setStyleSheet("color:Black;background-color:Orange")
                   setSizePolicy(1,1)
                   setclickevent("deleteRow4()")
                   settext("Row4") }

	    labelYourScore = new QLabel(win) { setgeometry(60,20,150,30)
		             setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                             settext("Your score: 0") }

	    labelComputerScore = new QLabel(win) { setgeometry(350,20,150,30)
		                setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                                settext("PC score: 0") }

	    btnNewGame = new QPushButton(win) { setgeometry(60,400,80,30)
			     setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                             settext("New")
                             setclickevent("newGame()") }

	    btnExit = new QPushButton(win) { setgeometry(400,400,80,30)
			  setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                          settext("Exit")
                          setclickevent("pQuit()") }

	    btnPcMove = new QPushButton(win) { setgeometry(200,400,140,30)
		        setFont(new qFont("Verdana",C_FONTSIZE,50,0))
                        settext("PC move")
                        setclickevent("pcMove()") }

            show()
   }
   exec()
}

func deleteRow1()
     if move2 = 1 or move3 = 1 or move4 = 1
        move1 = 0
        return 
     else
        move1 = 1
     ok
     if (match1 > 0) and (move1 = 1)
        if pcMove = 1
        Button1[match1] { seticon(new qicon(new qpixmap(C_COMPUTER)))                        
                          setIconSize(new qSize(55,55))
                          setenabled(false) }
        match1 = match1 - 1
        move1 = 0
        ok

        if pcMove = 0 
        Button1[match1] { seticon(new qicon(new qpixmap(C_PROGRAMMER)))                        
                          setIconSize(new qSize(55,55))
                          setenabled(false) }
        match1 = match1 - 1
        ok
        gameOver()
     ok

func deleteRow2()
     if move1 = 1 or move3 = 1 or move4 = 1
        move2 = 0
        return 
     else
        move2 = 1
     ok
     if match2 > 0 and move2 = 1
        if pcMove = 1
        Button2[match2] { seticon(new qicon(new qpixmap(C_COMPUTER)))                        
                          setIconSize(new qSize(55,55))
                          setenabled(false) }
        match2 = match2 - 1
        move2 = 0
        ok

        if pcMove = 0
        Button2[match2] { seticon(new qicon(new qpixmap(C_PROGRAMMER)))                        
                          setIconSize(new qSize(55,55))
                          setenabled(false) }
        match2 = match2 - 1
        ok
        gameOver()
     ok

func deleteRow3()
     if move1 = 1 or move2 = 1 or move4 = 1
        move3 = 0
        return 
     else
        move3 = 1
     ok
     if match3 > 0 and move3 = 1
        if pcMove = 1
        Button3[match3] { seticon(new qicon(new qpixmap(C_COMPUTER)))                        
                          setIconSize(new qSize(55,55))
                          setenabled(false) }
        match3 = match3 - 1
        move3 = 0
        ok

        if pcMove = 0
        Button3[match3] { seticon(new qicon(new qpixmap(C_PROGRAMMER)))                        
                          setIconSize(new qSize(55,55))
                          setenabled(false) }
        match3 = match3 - 1
        ok
        gameOver()
     ok

func deleteRow4()
     if move1 = 1 or move2 = 1 or move3 = 1
        move4 = 0
        return 
     else
        move4 = 1
     ok
     if match4 > 0 and move4 = 1       
        if pcMove = 1
        Button4[match4] { seticon(new qicon(new qpixmap(C_COMPUTER)))                        
                          setIconSize(new qSize(55,55))
                          setenabled(false) }
        match4 = match4 - 1
        move4 = 0
        ok

        if pcMove = 0 
        Button4[match4] { seticon(new qicon(new qpixmap(C_PROGRAMMER)))                        
                          setIconSize(new qSize(55,55))
                          setenabled(false) }
        match4 = match4 - 1
        ok
        gameOver()
     ok

func pcMove()

     move1 = 0
     move2 = 0
     move3 = 0
     move4 = 0
     pcMove = 1
     for n = 1 to limit
         if match1 > 0
            rnd = random(max(match1-1,1))+1
            for m = 1 to rnd
                deleteRow1()
            next
            exit
         ok

         if match2 > 0
            rnd = random(max(match2-1,1))+1
            for m = 1 to rnd
                deleteRow2()
            next
            exit
         ok

         if match3 > 0
             rnd = random(max(match3-1,1))+1
             for m = 1 to rnd
                 deleteRow3()
             next
             exit 
          ok

          if match4 > 0
             rnd = random(max(match4-1,1))+1
             for m = 1 to rnd
                 deleteRow4()
             next
             exit 
          ok
     next
     pcMove = 0

func gameOver()
     if (match1 = 0) and (match2 = 0) and (match3 = 0) and (match4 = 0)
        if pcMove = 0
           pcScore = pcScore + 1
           labelComputerScore.settext("PC score: " + string(pcScore))
           msgBox("Game Over! You Lost!")
        else
           yourScore = yourScore + 1
           labelYourScore.settext("Your score: " + string(yourScore))
           msgBox("Game Over! You Win!")
        ok
     ok

func newGame()

     match1 = limit1
     match2 = limit2
     match3 = limit3
     match4 = limit4

     move1 = 0
     move2 = 0
     move3 = 0
     move4 = 0

     pcMove = 0

     for Col = 1 to limit1
	 Button1[Col] = new QPushButton(win) {
                        y = 230+(Col-1)*height
                        setgeometry(y+10,70,width,height)
                        setSizePolicy(1,1)
                        seticon(new qicon(new qpixmap(C_NIM)))                        
                        setIconSize(new qSize(60,60))
                        show()
                        }				       
	next

        for Col = 1 to limit2
	    Button2[Col] = new QPushButton(win) {
                           y = 170+(Col-1)*height
                           setgeometry(y+10,150,width,height)
                           setSizePolicy(1,1)
                           seticon(new qicon(new qpixmap(C_NIM)))                        
                           setIconSize(new qSize(60,60))
                           show()
                           }				       
	next

        for Col = 1 to limit3
	    Button3[Col] = new QPushButton(win) {
                           y = 110+(Col-1)*height
                           setgeometry(y+10,230,width,height)
                           setSizePolicy(1,1)
                           seticon(new qicon(new qpixmap(C_NIM)))                        
                           setIconSize(new qSize(60,60))
                           show()
                           }				       
	next

        for Col = 1 to limit4
	    Button4[Col] = new QPushButton(win) {
                           y = 50+(Col-1)*height
                           setgeometry(y+10,310,width,height)
                           setSizePolicy(1,1)
                           seticon(new qicon(new qpixmap(C_NIM)))                        
                           setIconSize(new qSize(60,60))
                           show()
                           }				       
	next

func msgBox(cText)	  
     mb = new qMessageBox(win) {
	  setWindowTitle('CalmoSoft Nim Game')
	  setText(cText)
          setstandardbuttons(QMessageBox_OK) 
          result = exec() 
     }

func pQuit()
     win.close()
     app.Quit()
