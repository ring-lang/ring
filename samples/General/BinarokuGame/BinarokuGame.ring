//---------------------------------------------------------------------------

# Project : Binaroku Game
# Date    : 21/11/2020-23:02:37
# Update  : 24/11/2020-04:12:48
# Author  : Gal Zsolt (CalmoSoft)
# Email   : calmosoft@gmail.com

//---------------------------------------------------------------------------

load "stdlib.ring"
load "guilib.ring"

//---------------------------------------------------------------------------

size      = 8				
				
limit     = 50
C_SPACING = 1
checkRC   = 0
Button              = list(size,size)
LayoutButtonRow     = list(size)
C_ButtonOrangeStyle = 'border-radius:1x;color:black; background-color: orange'
errorMsg = "Bad step." + nl + "Please try another one"

//---------------------------------------------------------------------------

MyApp = New qApp {

        StyleFusion()

        win = new qWidget() {

              setwindowtitle("Binaroku Game")
              move(555,145)
              resize(200,200)

	     desktop = new QDesktopWidget()
	     workHeight = win.height()
		  fontSize = 8 + (workHeight / 30)

 	     LayoutButtonMain = new QVBoxLayout() {
		                    setSpacing(C_SPACING)
		                    setContentsmargins(50,50,50,50) 
	     }

	     LayoutButtonStart = new QHBoxLayout() {
			                   setSpacing(C_SPACING)
			                   setContentsmargins(0,0,0,0)
	     }

	     btnStart = new QPushButton(win) {
			          setFont(new qFont("Calibri",fontsize,2100,0))
			          setMinimumWidth(desktop.Width() * 0.05)
			          setMinimumHeight(desktop.Height() * 0.05)
                   settext("New Game")
                   setstylesheet(C_ButtonOrangeStyle)
                   setclickevent("pStart()")
        }

	     btnExit = new QPushButton(win) {
			         setFont(new qFont("Calibri",fontsize,2100,0))
			         setMinimumWidth(desktop.Width() * 0.05)
			         setMinimumHeight(desktop.Height() * 0.05)
                  settext("Exit")
                  setstylesheet(C_ButtonOrangeStyle)
                  setclickevent("pExit()")
        }

        LayoutButtonStart.AddWidget(btnStart)
        LayoutButtonStart.AddWidget(btnExit)

        LayoutButtonMain.AddLayout(LayoutButtonStart)

        for Row = 1 to size
		      LayoutButtonRow[Row] = new QHBoxLayout() {
				setSpacing(C_SPACING)
				setContentsmargins(0,0,0,0)
		      }

            for Col = 1 to size		      
                Button[Row][Col] = new QPushButton(win) {
			                          setFont(new qFont("Calibri",fontsize,2100,0))
			                          setMinimumWidth(desktop.Width() * 0.05)
			                          setMinimumHeight(desktop.Height() * 0.05)
                                   setclickevent("pClick(" + string(Row) + "," + string(Col) + ")")
                                   }

                LayoutButtonRow[Row].AddWidget(Button[Row][Col])
		      next
          
		      LayoutButtonMain.AddLayout(LayoutButtonRow[Row])

		  next

		  setLayout(LayoutButtonMain)

        show()

        }

        pStart()

        exec()
}

//---------------------------------------------------------------------------

func pStart()
     for Row = 1 to size
         for Col = 1 to size
             Button[Row][Col].settext("-")
         next
     next
     randomBoard()

//---------------------------------------------------------------------------

func pClick(Row,Col)

     txt = Button[Row][Col].text()

     switch txt
            on "-"
               cClick = "0"
            on "0"
               cClick = "1"
            on "1"
               cClick = "0"
     off

     Button[Row][Col].settext(cClick)

     nearCells()

     result = goodCells(Row,Col)

     if txt = "-" and cClick = "0" and result = 1
        see "ok1" + nl
        Button[Row][Col].settext("1")
     ok
     
     nearCells() 

     result = goodCells(Row,Col)

     if txt = "-" and cClick = "0" and result = 1
        see "ok2" + nl
        Button[Row][Col].settext("1")
     ok

     gameOver()

//---------------------------------------------------------------------------

func goodCells(Row,Col)

     xflag = 1

     for xRow = 1 to size
         bRowOne  = 0
         bRowZero = 0
         for yCol = 1 to size
             txt = Button[xRow][yCol].text()
             if txt = "0"
                bRowZero = bRowZero + 1
                if bRowZero > 4
                   if xRow = Row and yCol = Col
                      xflag = 0
                   ok
                   bRowZero = bRowZero - 1
                   Button[xRow][yCol].settext("-")
                ok
             ok
             if txt = "1"
                bRowOne = bRowOne + 1
                if bRowOne > 4
                   if xRow = Row and yCol = Col
                      xflag = 0
                   ok
                   bRowOne = bRowOne - 1
                   Button[xRow][yCol].settext("-")
                ok
             ok
         next
     next

     for yCol = 1 to size
         bColOne  = 0
         bColZero = 0
         for xRow = 1 to size
             txt = Button[xRow][yCol].text()
             if txt = "0"
                bColZero = bColZero + 1
                if bColZero > 4
                   if xRow = Row and yCol = Col
                      xflag = 0
                   ok
                   bColZero = bColZero - 1
                   Button[xRow][yCol].settext("-")
                ok
             ok
             if txt = "1"
                bColOne = bColOne + 1
                if bColOne > 4
                   if xRow = Row and yCol = Col
                      xflag = 0
                   ok
                   bColOne = bColOne - 1
                   Button[xRow][yCol].settext("-")
                ok
             ok
         next
     next

     if xflag = 1
        return 0
     else
        return 1
     ok

//---------------------------------------------------------------------------  

func randomBoard()

     for Row = 1 to size
         for Col = 1 to size
             Button[Row][Col].settext("-")
         next
     next

     for n = 1 to limit
         rnd = random(1)
         rRow = random(size-1)+1
         rCol = random(size-1)+1

         resBegin = goodCells(rRow,rCol)
         if resBegin = 1
            loop
         else
            Button[rRow][rCol].settext(string(rnd))
         ok
     next

//---------------------------------------------------------------------------

Func msgBox(cText) 

	  mb = new qMessageBox(win) 
	      {
	      setWindowTitle('Binaroku Game')
	      setText(cText )
         setstandardButtons(QMessageBox_Discard | QMessageBox_OK) 
         result = exec()
         }
         return

//---------------------------------------------------------------------------

Func pExit
     MyApp.quit()

//---------------------------------------------------------------------------

func gameOver()

     for x = 1 to size
         okZero = 0
         okOne = 0
         for y = 1 to size
             if Button[x][y].text() = "0"
                okZero = okZero + 1
             ok
             if Button[x][y].text() = "1"
                okOne = okOne + 1
             ok
         next
         if okZero != 4 or okOne != 4
            return
         ok
     next

     for y = 1 to size
         okZero = 0
         okOne = 0
         for x = 1 to size
             if Button[x][y].text() = "0"
                okZero = okZero + 1
             ok
             if Button[x][y].text() = "1"
                okOne = okOne + 1
             ok
         next
         if okZero != 4 or okOne != 4
            return
         ok
     next

     msgBox("Good Solution. You Win.")

//---------------------------------------------------------------------------

func nearCells()

     for x = 1 to size
         for y = 1 to size - 2
             bool1 =  ( Button[x][y].text() = Button[x][y+1].text() )
             bool2 =  ( Button[x][y+1].text() = Button[x][y+2].text() )
             bool = bool1 and bool2
             if bool = 1
                Button[x][y].settext("-")
             ok
         next
     next

     for y = 1 to size
         for x = 1 to size - 2
             bool1 =  ( Button[x][y].text() = Button[x+1][y].text() )
             bool2 =  ( Button[x+1][y].text() = Button[x+2][y].text() )
             bool = bool1 and bool2
             if bool = 1
                Button[x][y].settext("-")
             ok
         next
     next

//---------------------------------------------------------------------------
