/*-----------------------------------
# Project : DNA subsequences
# Date    : 2021/03/23
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
-----------------------------------*/

//-----------------------------------------

load "stdlibcore.ring"
load "guilib.ring"

base = ["A","C","G","T"]
dnaList = []
dnaSeq = []
Button = list(10,20)
ColLine = list(21)
start = 0 
C_Spacing = 2 

C_ButtonDnaStyle  = 'background-color: Red; border-radius: 8px;' 
C_ButtonStyle  = '' 
LayoutButtonRow = list(10)

//-----------------------------------------

app = new qApp 
{
      win = new qWidget() {
            setWindowTitle('DNA subsequences')
	    setWinIcon(self,AppFile("white.jpg"))
            setStyleSheet('background-color:White')
            setgeometry(560,180,300,300)
            //reSize(400,400)
            winheight = 10 
            fontSize = 8 # + (winheight / 100)

            LayoutButtonMain = new QVBoxLayout()            
            LayoutButtonMain.setSpacing(C_Spacing)
            LayoutButtonMain.setContentsmargins(0,0,0,0)

            LabelInd = new qLabel(win) { settext("    DNA subsequences start positions:")
                                         setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
                                         setStyleSheet("background-color:yellow") }

            ButtonInd = new QPushButton(win) { setStyleSheet("background-color:yellow") }

            LabelFind = new qLabel(win) { settext("    DNA subsequence to find:")
                                          setStyleSheet("background-color:yellow") }

            ButtonFind = new QPushButton(win)

            DnaSearch = new QPushButton(win) { setclickevent("pstart()")
                                               setStyleSheet("background-color:yellow")
                                               settext("Find")
                                             }
    
            for Col = 1 to 21
                ColLine[Col] = new qLabel(win) {
                                setmaximumheight(20)
                                setAlignment(Qt_AlignHCenter | Qt_AlignVCenter) 
                                setStyleSheet("background-color:darkgray")
                                setText(string(Col-1))
                                } 
            next

            LayoutInd = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }
            LayoutInd.AddWidget(LabelInd) 
            LayoutInd.AddWidget(ButtonInd) 
            LayoutButtonMain.AddLayout(LayoutInd) 
                
            LayoutTitleRow = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }

                for Col = 1 to 21                
                    LayoutTitleRow.AddWidget(ColLine[Col])         
                next
                            
            LayoutButtonMain.AddLayout(LayoutTitleRow)  
            
            RowLine = list(10)  

            for Row = 1 to 10
                Letter = "" + Row*20
                if Row*20 < 100
                   Letter = "  " + Row*20
                ok
                RowLine[Row] = new qLabel(win) { setFont(new qFont("Verdana",fontSize,40,0))
                                                 setAlignment(Qt_AlignHCenter | Qt_AlignVCenter) 
                                                 setStyleSheet("background-color:darkgray")
                                                 setText(Letter)
                                               } 
            next

            for Row = 1 to 10
                LayoutButtonRow[Row] = new QHBoxLayout()    
                {
                    setSpacing(C_Spacing)
                    setContentsmargins(0,0,0,0)
                } 

               LayoutButtonRow[Row].AddWidget(RowLine[Row])
               
               for Col = 1 to 20
                    Button[Row][Col] = new QPushButton(win) {
                                       setmaximumwidth(20) 
                                       }
                    LayoutButtonRow[Row].AddWidget(Button[Row][Col])    
               next
               
               LayoutButtonMain.AddLayout(LayoutButtonRow[Row])         
            next

            LayoutDataRow = new QHBoxLayout() { setSpacing(C_Spacing) setContentsMargins(0,0,0,0) }

            LayoutDataRow.AddWidget(LabelFind)
            LayoutDataRow.AddWidget(ButtonFind)               
            LayoutDataRow.AddWidget(DnaSearch)
            LayoutButtonMain.AddLayout(LayoutDataRow) 
                  
            setLayout(LayoutButtonMain)
            
            pStart()
            show()
   }
   exec()
 }

//-----------------------------------------

func pStart()
     start = start + 1

     dnaList = []
     for row = 1 to 10
         for col = 1 to 20
             Button[row][col].settext("")
         next
     next
     for nr = 1 to 200
         rnd = random(3)+1
         baseStr = base[rnd]
         row = ceil(nr/20)
         col = nr%20
         if col = 0
            col = 20
         ok
         Button[row][col].settext(baseStr)
         add(dnaList,baseStr)
     next

     startDna()

//-----------------------------------------

func startDna()

     strDna = list2str(dnaList)
     strDna = substr(strDna,nl,"")

     while true
           strBase = ""
           for n = 1 to 4
               rnd = random(3)+1
               strBase = strBase + base[rnd]
           next
           ind = substr(strDna,strBase)
           if ind > 0
              exit
           ok
     end

     showDna(dnaList)

//-----------------------------------------

func showDna(dnaList)

     if start > 1
     see nl
     for n = 1 to len(dnaSeq)
         for m = 0 to 3
             ind = dnaSeq[n] + m
             row = ceil(ind/20)
             col = ind%20
             if col = 0
                col = 20
             ok
             Button[row][col].setstylesheet(C_ButtonStyle)
         next
     next
     ok


     dnaSeq = []
     strDna = list2str(dnaList)
     strDna = substr(strDna,nl,"")

     while true
           strBase = ""
           for n = 1 to 4
               rnd = random(3)+1
               strBase = strBase + base[rnd]
           next
           ind = substr(strDna,strBase)
           if ind > 0
              exit
           ok
     end

     ButtonFind.setStyleSheet("background-color:yellow")
     ButtonFind.settext(strBase)

     for n = 1 to 196
         flag = 1
         for m = 0 to 3
             if dnaList[n+m] != strBase[m+1]
                flag = 0
                exit
             ok
         next
         if flag = 1
            add(dnaSeq,n)
         ok
     next
     
     temp = ""
     ButtonInd.settext("")
     for nr = 1 to len(dnaList)
         ind = find(dnaSeq,nr)
         if ind > 0
            temp = temp + string(dnaSeq[ind]) + " "
            ButtonInd.settext(temp)
            for n = nr to nr + 3
                row = ceil(n/20)
                col = n%20
                if col = 0
                   col = 20
                ok
                Button[row][col].setStyleSheet(C_ButtonDnaStyle)
                Button[row][col].settext(dnaList[n])
            next
         ok
      next           

//-----------------------------------------
