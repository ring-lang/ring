Load "guilib.ring"

New qapp 
{
    $ObjectName   = "oFirstWindow"    ### $ObjectName use inside Class FirstWindow as ($ObjectName+".pBox1A()")
    oFirstWindow  = new FirstWindow   ### Class called FirstWindow
    
        See nl +nl +"===== ObjectName First: ===== " +nl +nl
        See $ObjectName
        See nl +nl +"===== oFirstWindow: ======== " +nl +nl
        See oFirstWindow
        See nl +nl +"===================" +nl +nl
    
    $ObjectName   = "oSecondWindow"   ### $ObjectName use inside Class SecondWindow as($ObjectName+".pBox2X()")
    oSecondWindow = new SecondWindow  ### Class called SecondWindow
    
        See nl +nl +"===== ObjectName Second: ====== " +nl +nl
        See $ObjectName
        See nl +nl +"===== oSecondWindow: ========= " +nl +nl
        See oSecondWindow
        See nl +nl +"===================" +nl +nl
    
    exec()
}


class FirstWindow

    win1 = new qMainWindow()
    {
        #symbolz = "Inside Win-1 symbolz" ###  No Conflict with Win-2 symbols. OBJECT: symbolz: Inside Win-1 symbolz
        
        ###------------------------------------------------------
        setGeometry(200,200,800,500)
        setwindowtitle("qMainWindow -- Win 1 Table 1 ABCD")
        
            Table1 = new qTableWidget(win1) 
            {
                #symbolz = "Inside Table-1 symbolz"  ###  No Conflict with Win-2 symbols --- OBJECT: symbolz: Inside Table-1 symbolz
                
                setrowcount(6)
                setcolumncount(8)
                
                setGeometry(20,20,700,400)
                setselectionbehavior(QAbstractItemView_SelectRows)
                setSelectionMode(QAbstractItemView_SelectItems)             
    
                SetColumnWidth(0,60)    # 
                SetColumnWidth(1,100)   # 
                SetColumnWidth(2,75)    # 

                mycols = new qstringlist() 
                {
                    append("SYMBOL") 
                    append("NAME")
                    append("GROUP")
                }       
                
                setHorizontalHeaderLabels(mycols)
                setAlternatingRowColors(true)               
                setStyleSheet("QHeaderView::section { background-color: yellow }")
                horizontalHeader().setStyleSheet("color: blue")
                verticalHeader().setStyleSheet("color: red")                
                
                cBox1List =[" ", "A", "B", "C", "D"]
                
                cBox1A = new qCombobox(Table1) { for i in cBox1List addItem(i,0) next setcurrentIndexChangedEvent($ObjectName+".pBox1A()") }   ### $ObjectName global
                cBox1B = new qCombobox(Table1) { for i in cBox1List addItem(i,0) next setcurrentIndexChangedEvent($ObjectName+".pBox1B()") }
                cBox1C = new qCombobox(Table1) { for i in cBox1List addItem(i,0) next setcurrentIndexChangedEvent($ObjectName+".pBox1C()") }
              
                setCellWidget(0, 0, cBox1A)
                setCellWidget(0, 1, cBox1B)
                setCellWidget(0, 2, cBox1C)
                
                ###---------------------------
                ### Add some Table Widget Items
                
                setItem(1,0, new qTableWidgetItem("ATT") )
                setItem(2,1, new qTableWidgetItem("BAC") )  
                setItem(3,2, new qTableWidgetItem("CVX") )  
                

                ###---------------------
                ### TABLE 2 Widget
                
                #$ObjectName   = $ObjectName + ".oSecondWindow"   # oFirstWindow.oSecondWindow
                #oSecondWindow = new DisplayWidgetTable
            }                       

            ###-------------------------------------------      
        show()       
    }

###-----------------------

    ###------------------------------------
    ### TABLE 1 Methods
    
    func pBox1A
        See "func pBox-1A-1: " + cBox1A.currentText() +" Index: "+  cBox1A.currentIndex() +nl
    return
            
    func pBox1B
        See "func pBox-1B-1: " + cBox1B.currentText() +" Index: "+  cBox1B.currentIndex() +nl
    return
            
    func pBox1C
        See "func pBox-1C-1: " + cBox1C.currentText() +" Index: "+  cBox1C.currentIndex() +nl
    return
  
    ###----------------------------------------



###-----------------------------------------------
### Widget TABLE 2

Class SecondWindow

    win2 = new qwidget() 
    {       
        symbolz = "Inside Win-2 symbolz"  ### shows OBJECT: symbolz: GOOGL  --- R6C0 = NULL instead of GOOGL --- Column 0 ALL = NULL
    
        setGeometry(30,40,700,400)
        setwindowtitle("Display qwidget - Win2 Table2 XYZW")
        
            Table2 = new qTableWidget(win2) 
            {
                #symbolz = "Inside Table-2 symbolz" ### shows OBJECT: symbolz: GOOGL R6C0 = NULL instead of GOOGL --- Column 0 ALL = NULL
                
                setrowcount(8)
                setcolumncount(6)
                
                setGeometry(20,20,800,600)
                setselectionbehavior(QAbstractItemView_SelectRows)
                setSelectionMode(QAbstractItemView_SelectItems)         
                
                SetColumnWidth(0,60)    # 
                SetColumnWidth(1,100)   # 
                SetColumnWidth(2,75)    #

                mycols = new qstringlist() 
                {
                    append("ABLE") 
                    append("BAKER")
                    append("CHARLIE")
                }
                    
                setHorizontalHeaderLabels(mycols)
                setAlternatingRowColors(true)
                    
                setStyleSheet("QHeaderView::section { background-color: aqua }")
                   
                horizontalHeader().setStyleSheet("color: blue")
                verticalHeader().setStyleSheet("color: red")  
                               
                cBox1List =[" ", "X", "Y", "Z", "W"]
                
                cBox1A = new qCombobox(Table2) { for i in cBox1List addItem(i,0) next setcurrentIndexChangedEvent($ObjectName+".pBox1A()") }   ### $ObjectName global
                cBox1B = new qCombobox(Table2) { for i in cBox1List addItem(i,0) next setcurrentIndexChangedEvent($ObjectName+".pBox1B()") }
                cBox1C = new qCombobox(Table2) { for i in cBox1List addItem(i,0) next setcurrentIndexChangedEvent($ObjectName+".pBox1C()") }
        
                setCellWidget(0, 0, cBox1A)
                setCellWidget(0, 1, cBox1B)
                setCellWidget(0, 2, cBox1C)   
                
                ###---------------------------
                ### Fill in Widget Table
                companyList = []
                
                aList = 
                [
                  [ "SPY",   "SP500",    "Index", 0, 109.24, 107.21 ],
                  [ "SDYL",  "SPDivs",   "ETF",   1, 152.33, 119.85 ],
                  [ "FB",    "Facebook", "Tech",  2, 143.34, 114.02 ],
                  [ "AMZN",  "Amazon",   "Cloud", 3, 154.80, 117.39 ],
                  [ "NVDA",  "Nvidia",   "Chips", 4, 287.49, 141.35 ],
                  [ "GOOGL", "Google",   "Cloud", 5, 126.70, 107.83 ]
                ]

                for record in aList
                            companyList +  new Company ([
		 		:Symbolz   =   record[1],		 
                        	:Namez     =   record[2],
                            	:Groupz    =   record[3],
                           	:Positionz =   record[4],
                          	:Changez   =   record[5], 
                           	:Ratioz    =   record[6] 
                          ])                       
                next      
	see "print list" + nl
	see companylist

                ###------------------------------
                ### Put data in Widget Cells
                
                for x = 1 to len(companyList)               
                    
                    item1 = new qtablewidgetitem(companyList[x].Symbolz)
                    item2 = new qtablewidgetitem(companyList[x].Namez)
                    item3 = new qtablewidgetitem(companyList[x].Groupz)
                    item4 = new qtablewidgetitem("" + companyList[x].Positionz)
                    item5 = new qtablewidgetitem("" + companyList[x].Changez)
                    item6 = new qtablewidgetitem("" + companyList[x].Ratioz)
                    
                    setitem(x, 0, item1) 
                    setitem(x, 1, item2) 
                    setitem(x, 2, item3) 
                    setitem(x, 3, item4) 
                    setitem(x, 4, item5) 
                    setitem(x, 5, item6) 
    
                next
                
                setItem(1,3, new qTableWidgetItem("Item13") )
                setItem(3,1, new qTableWidgetItem("Item31") )               
          
            }
            
            ###-----------------------     
        show()
    }
 
###-----------------------

    ###------------------------------------
    ### TABLE 2 Methods
    
    func pBox1A
        See "func pBox-1A-2: " + cBox1A.currentText() +" Index: "+  cBox1A.currentIndex() +nl
    return
            
    func pBox1B
        See "func pBox-1B-2: " + cBox1B.currentText() +" Index: "+  cBox1B.currentIndex() +nl
    return
    
    func pBox1C
        See "func pBox-1C-2: " + cBox1C.currentText() +" Index: "+  cBox1C.currentIndex() +nl
        
        Table2.item(5,3).setText("Changed03")
        See "  Item-R4-C1: " + Table2.item(4,1).text() +nl
        See "  Item-R5-C2: " + Table2.item(5,2).text() +nl
    return
    

 
Class Company 
	Symbolz Namez Groupz Positionz Changez Ratioz
	func init aPara
		Symbolz  = aPara[:Symbolz]
		Namez 	 = aPara[:Namez]
		Groupz	 = aPara[:Groupz]
		Positionz= aPara[:Positionz]
		Changez  = aPara[:Changez]
		Ratioz 	 = aPara[:Ratioz]
	
######################################
