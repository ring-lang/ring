Load "guilib.ring"

New qApp 
{

        win1 = new qMainWindow() 
        {
                   setGeometry(100,100,1100,370)
                   setwindowtitle("Using QTableWidget")

                   Table1 = new qTableWidget(win1) 
                   {
                                setrowcount(10) setcolumncount(5)
                                setGeometry(0,0,800,400)
                                setselectionbehavior(QAbstractItemView_SelectRows)
                                setSelectionMode(QAbstractItemView_SelectItems) 

                                for x = 1 to 10
                                     for y = 1 to 5
                                          item1 = new qtablewidgetitem("R"+X+"-C"+Y)
                                          setitem(x-1,y-1,item1)                                                                  
                                     next
                                next

                                SetColumnWidth(0,200)
                                SetColumnWidth(1,50)
                                SetColumnWidth(2,50)
                                SetColumnWidth(3,100)
                                SetColumnWidth(4,100)

                                mycols = new qstringlist() 
                               {
                                               append("SYMBOL") 
                                               append("NAME")
                                               append("GROUP")
                                               append("CHANGE")
                                               append("RATIO")
                               }
                               setHorizontalHeaderLabels(mycols)
                               //setAlternatingRowColors(true)
                        
                               setStyleSheet("QHeaderView::section { background-color: yellow }")
                               setStyleSheet("QTableWidget::item {background-color: orange}")
                       
                               horizontalHeader().setStyleSheet("color: blue")
                               verticalHeader().setStyleSheet("color: red")                         
                 }

                 setcentralwidget(table1)
                 show()
        }
        exec()
}
