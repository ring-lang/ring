# Project : Lights Out Game
# Date    : 2018/10/31
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

load "stdlibcore.ring"
load "lightguilib.ring"

size = 5
nlight = 10
score = 0
C_Spacing = 1

C_ButtonBlueStyle   = 'border-radius:6px;color:black; background-color: blue'
C_ButtonLightBlueStyle   = 'border-radius:6px;color:black; background-color: lightblue'
C_ButtonOrangeStyle = 'border-radius:6px;color:black; background-color: orange'

Button = newlist(size,size)
btnLight = newlist(size,size)
LayoutButtonRow = list(size)

app = new qApp 
{
	win = new qWidget() {
		setWinIcon(self,"light.png")
		setWindowTitle('Lights Out')
		move(500,100)
		reSize(600,600)
		winheight = win.height()
		fontSize = 8 + (winheight / 100)

		GameScore = new QLabel(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
							setstylesheet(C_ButtonOrangestyle)
							settext("GameScore:")
						}


		ExitLabel = new QPushButton(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
							setstylesheet(C_ButtonOrangestyle)
                                                        setClickEvent("pExit()")
							settext("Exit")
						}

		NewGame = new QPushButton(win) 
						{
							setFont(new qFont("Verdana",fontSize,100,0))
							setstylesheet(C_ButtonOrangestyle)
                                                        setClickEvent("pBegin()")
							settext("New Game")
						} 

 		LayoutButtonMain = new QVBoxLayout()			
		LayoutButtonMain.setSpacing(C_Spacing)
		LayoutButtonMain.setContentsmargins(0,0,0,0)

			for Row = 1 to size
				LayoutButtonRow[Row] = new QHBoxLayout()	
				{
					setSpacing(C_Spacing)
					setContentsmargins(0,0,0,0)
				} 
         		   for Col = 1 to size
					Button[Row][Col] = new QPushButton(win)	
					{
						setStyleSheet(C_ButtonBlueStyle)
                                                setclickevent("pselect(" + string(Row) + "," + string(Col) + ")")		
						setSizePolicy(1,1)                                                
					}
					
					LayoutButtonRow[Row].AddWidget(Button[Row][Col])	
			   next
			   
			   LayoutButtonMain.AddLayout(LayoutButtonRow[Row])			
			next

				LayoutDataRow = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }

				LayoutDataRow.AddWidget(GameScore) 		
				LayoutDataRow.AddWidget(NewGame) 			  
				LayoutDataRow.AddWidget(ExitLabel) 
  
				LayoutButtonMain.AddLayout(LayoutDataRow)

            setLayout(LayoutButtonMain)

            pBegin()			
            show()
   }
   exec()
}

func pselect(Col,Row)
       if btnLight[Col][Row] = "on"
          Button[Col][Row].setstylesheet(C_ButtonBlueStyle)
          btnLight[Col][Row] = "out"
          score = score + 1
          GameScore.settext("Game Score: " + string(score))
          plight(Col,Row)
          gameover()
       ok

func plight(Col,Row)
       if Row > 1
          if btnLight[Col][Row-1] = "on"
             btnLight[Col][Row-1] = "out"
             Button[Col][Row-1].setstylesheet(C_ButtonBlueStyle)
          else
             btnLight[Col][Row-1] = "on"
             Button[Col][Row-1].setstylesheet(C_ButtonLightBlueStyle)
          ok
       ok
       if Row < size
          if btnLight[Col][Row+1] = "on"
             btnLight[Col][Row+1] = "out"
             Button[Col][Row+1].setstylesheet(C_ButtonBlueStyle)
          else
             btnLight[Col][Row+1] = "on"
             Button[Col][Row+1].setstylesheet(C_ButtonLightBlueStyle)
          ok
       ok
       if Col > 1
          if btnLight[Col-1][Row] = "on"
             btnLight[Col-1][Row] = "out"
             Button[Col-1][Row].setstylesheet(C_ButtonBlueStyle)
          else
             btnLight[Col-1][Row] = "on"
             Button[Col-1][Row].setstylesheet(C_ButtonLightBlueStyle)
          ok
       ok
       if Col < size
          if btnLight[Col+1][Row] = "on"
             btnLight[Col+1][Row] = "out"
             Button[Col+1][Row].setstylesheet(C_ButtonBlueStyle)
          else
             btnLight[Col+1][Row] = "on"
             Button[Col+1][Row].setstylesheet(C_ButtonLightBlueStyle)
          ok
       ok

func pBegin()
       score = 0
       for n = 1 to size   
            for m = 1 to size
                 Button[n][m].setstylesheet(C_ButtonBlueStyle)
                 btnLight[n][m] = "out"
            next
       next
       for n = 1 to nlight   
            x = random(size-1) + 1
            y = random(size-1) + 1
            Button[x][y].setstylesheet(C_ButtonLightBlueStyle)
            btnLight[x][y] = "on"
       next
       GameScore.settext("Game Score:")

func gameover()
       total = 0
       for n = 1 to size   
            for m = 1 to size
                 if btnLight[n][m] = "out"
                    total = total + 1
                 ok
            next
       next
       if total = size*size
          msgbox("Game over")
       ok
       
Func msgBox(cText) 
	mb = new qMessageBox(win) 
		{
	        setWindowTitle('Lights Out')
	        setText(cText )
		setstylesheet(C_ButtonWhitestyle)
                setstandardButtons(QMessageBox_Discard | QMessageBox_OK) 
                result = exec()
                if result = QMessageBox_OK
                   pbegin()
                ok			
        }
        return

func pExit()
	win.close()
	app.quit()	
