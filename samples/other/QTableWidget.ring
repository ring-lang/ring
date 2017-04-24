Load "guilib.ring"


New qApp
             {
              win1 = new qMainWindow()
             {
              setGeometry(100,100,1100,370)    
              setwindowtitle("Using QTableWidget")
              Table1 = new qTableWidget(win1)
              {
              setrowcount(10) setcolumncount(10)
              setGeometry(0,0,800,400)
              setSelectionMode(QAbstractItemView_SelectItems)  
              setitemChangedEvent("pPress()")

              for x = 1 to 10
                   for y = 1 to 10
                        item1 = new qtablewidgetitem("R"+X+"C"+Y)
                        setitem(x-1,y-1, item1)
                   next
              next

              cmb = new QComboBox(Table1)
              {
                         alist = ["one","two","three","four","five"]
                         for x in aList
                              additem(x, 0)
                         next 
              }

              cmb.setEnabled(false) 

              btn1 = new QPushButton(win1){
                         settext("First cell")
                         setClickEvent("pFirst()")
              } 

              btn2 = new QPushButton(win1){
                         settext("Last cell")
                         setClickEvent("pLast()")
              }

              btn3 = new QPushButton(win1){
                         settext("Go to Cell")
                         setClickEvent("pEdit()")
              }

              btn4 = new QPushButton(win1){
                         settext("Set row height")
                         setClickEvent("setHeight()")
              }

              btn5 = new QPushButton(win1){
                         settext("Set column width")
                         setClickEvent("setWidth()")
              }

              lineedit1 = new qlineedit(win1) {
                               settext("Go to Row")
                               setalignment(Qt_AlignHCenter)
                               setreturnPressedEvent("pPress()")
              } 

              lineedit2 = new qlineedit(win1) {
                               settext("Go to Column")
                               setalignment(Qt_AlignHCenter)
              } 

              lineedit3 = new qlineedit(win1) {
                               settext("Set row")
                               setalignment(Qt_AlignHCenter)
              } 

              lineedit4 = new qlineedit(win1) {
                               settext("Row height")
                               setalignment(Qt_AlignHCenter)
              } 

              lineedit5 = new qlineedit(win1) {
                               settext("Set column")
                               setalignment(Qt_AlignHCenter)
              } 

              lineedit6 = new qlineedit(win1) {
                               settext("Row width")
                               setalignment(Qt_AlignHCenter)
              } 

              setCellWidget(3, 5, cmb)
              setCellWidget(3, 6, btn1)
              setCellWidget(3, 7, btn2)
              setCellWidget(4, 5, lineedit1)
              setCellWidget(4, 6, lineedit2)
              setCellWidget(4, 7, btn3)
              setCellWidget(5, 5, lineedit3)
              setCellWidget(5, 6, lineedit4)
              setCellWidget(6, 5, lineedit5)
              setCellWidget(6, 6, lineedit6)
              setCellWidget(5, 7, btn4)
              setCellWidget(6, 7, btn5)

              }

              setcentralwidget(table1)
              myfilter = new qallevents(win1)
              myfilter.setKeyPressEvent("pKeyPress()")            
              installeventfilter(myfilter)
              show()
   }
   exec()
}

func pKeyPress 
       nKeyCode = myfilter.getkeycode()
       if nKeyCode = 16777220
         Table1 { 
                    if currentrow() = rowcount()-1 and currentcolumn() = columncount()-1
                       setcurrentcell(0, 0) 
                    else
                       if currentrow() = rowcount()-1
                          setcurrentcell(0, currentcolumn()+1)
                       else
                         setcurrentcell( currentrow()+1 , currentcolumn())
                    ok ok    
                    }
         ok

func pFirst
       Table1.setfocus(true)
       Table1.setcurrentcell(0, 0)

func pLast
       Table1.setfocus(true)
       Table1.setcurrentcell(Table1.rowcount()-1, Table1.columncount()-1)

func pEdit
       lineedit1{row = text()}
       lineedit2{column = text()}
       Table1.setfocus(true)
       Table1.setcurrentcell(row-1, column-1)

func pPress 
       Table1 {
                  if currentrow() = rowcount()-1 and currentcolumn() = columncount()-1
                     setcurrentcell(0, 0)
                  but currentrow() = rowcount()-1 
                     setcurrentcell( 0 , currentcolumn() + 1)
                  else
                     setcurrentcell( currentrow()+1 , currentcolumn()) ok
                  }

func setHeight
       Table1 {
                  lineedit3 {setRow = number(text())}
                  lineedit4 {setHeight = number(text())}
                  setRowHeight(setRow, setHeight)
                  }    

func setWidth
       Table1 {
                  lineedit5 {setColumn = number(text())}
                  lineedit6 {setWidth = number(text())}
                  setColumnWidth(setColumn, setWidth)
                  }       
