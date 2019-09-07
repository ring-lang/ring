# Project : Phone Database Application
# Date    : 05/07/2019-12:00:00
# Update  : 07/09/2019-13:24:10
# Author  : Gal Zsolt & Bert Mariani
# Company : CalmoSoft 
# Email   : quiwox@gmail.com

load "guilib.ring"
load "sqlitelib.ring"
load "countryList.ring"

nId = 1
ID = null
CID = null

arow = 0
indn = 0
nr = 0
num = 0
snum = 0

emptyrow = 0
cInd = 0
cIndType = 0

gRow = 0
crow = 0
nrow = 0

cbo = null
oSQLite = null
Table = null

listSearch = []
linesearch = null
cSearchInd = 0
cSearch = ""

labelsearch1 = ""
labelsearch2 = ""
labelsearch3 = ""
labelsearch4 = ""
labelsearch5 = ""
labelsearch6 = ""
labelsearch7 = ""

New qApp { 
         win1 = new qWidget() {
                resize(1280,550)
                setWindowTitle("Phone Database")

                btnstart = new qpushbutton(win1) {
                           setgeometry(450,500,80,40)
                           settext("ClearSearch")
                           setclickevent("pRestart()")
                           show()
                           }

                btnsave = new qpushbutton(win1) {
                          setgeometry(560,500,50,40)
                          settext("Save")
                          setclickevent("pSaveToSqlTable()")
                          show()
                          }

                btnexit = new qpushbutton(win1) {
                          setgeometry(620,500,50,40)
                          settext("Exit")
                          setclickevent("pExit()")
                          show()
                          }

                btndelete = new qpushbutton(win1) {
                            setgeometry(700,500,50,40)
                            settext("Delete")
                            setclickevent("pDelete()")
                            show()
                            }

                btninsert = new qpushbutton(win1) {
                            setgeometry(760,500,50,40)
                            settext("Insert")
                            setclickevent("pInsert()")
                            show()
                            }

                  show() 
         }         
		 
		                 
		 pInit()
		 pSqlOpenFirstTime()
         pReadSqlTable()
		 
         exec()
         }

//==========================================================

Func  pSqlOpenFirstTime()
     oSQLite = sqlite_init()
     sqlite_open(oSQLite,"mytest.db")
return	 

//-------------------------

func pReadSqlTable()

     row     = -1
     
	 sql = "select * from COMPANY"     
     aResult =  sqlite_execute(oSQLite,sql)
     
     for x in aResult
         row = row + 1
         col = -1
          for t in x
             col = col + 1
             item1 = new qtablewidgetitem(t[2])
             Table.setitem(row,col,item1)
         next
     next

//-------------------------------------------------------
// SAVE Button

func pSaveToSqlTable()

     sql = "DELETE FROM COMPANY"
     sqlite_execute(oSQLite,sql)
	 
     crow = Table.rowcount()
     for row = 0 to (crow-1)
         CID      = row
         CNAME    = Table.item(row,1).text()
         CCOUNTRY = Table.item(row,2).text()
         CADDRESS = Table.item(row,3).text()
         CPHONE   = Table.item(row,4).text()
         CJOB     = Table.item(row,5).text()
         CNOTES   = Table.item(row,6).text()
         
		 sql = "INSERT INTO COMPANY (ID,NAME,COUNTRY,ADDRESS,PHONE,JOB,NOTES)
                         VALUES (" + CID +",'"+ CNAME +"','"+ CCOUNTRY +"','"+ CADDRESS +"','"+ CPHONE +"','"+ CJOB +"','"+ CNOTES +"');
						 COMMIT;
               "
         sqlite_execute(oSQLite,sql)
     next

     pReadSqlTable() 
	 
//-------------------------------------------------------

func pInsert()
     Table.setitemChangedEvent("")
     nrow = Table.CurrentRow()
     arow = nrow
     Table.insertrow(nrow)

     temp = " "
     item = new qTableWidgetItem(temp)     Table.setitem(nrow,0,item)
     item = new qTableWidgetItem(temp)     Table.setitem(nrow,1,item)
     item = new qTableWidgetItem(temp)     Table.setitem(nrow,2,item)
     item = new qTableWidgetItem(temp)     Table.setitem(nrow,3,item)
     item = new qTableWidgetItem(temp)     Table.setitem(nrow,4,item)
     item = new qTableWidgetItem(temp)     Table.setitem(nrow,5,item)
     item = new qTableWidgetItem(temp)     Table.setitem(nrow,6,item)

//-------------------------------------------------------

func pClick()  
		Table {
	        if (currentcolumn()=2) 
		    cbo.show()
	            setCellWidget(currentrow(),2, cbo)
	        ok
	 	}

func pBox1
        Table { if currentColumn()=2
		item1 = new qtablewidgetitem(cbo.currentText())
                setitem(currentrow(), currentColumn(), item1) cbo.hide() 
				elseif currentcolumn() = 1
 					item(currentrow(),2).settextalignment(Qt_AlignHCenter|Qt_AlignVCenter)
				ok
        }

//-------------------------
func pExit()
     sqlite_close(oSQLite)
     win1.close()


//-------------------------------------------------------

func pSearch()

     Table.sortitems(0,0)
     listSearch = []

     nr = Table.rowcount()-1
     for k = 1 to nr + 1
         myitem = Table.item(k-1,0)
         temp = myitem.text()
         if len(temp) = 1
            temp = "0" + temp
            item = new qTableWidgetItem(temp)           
            Table.setitem(k-1,0,item)
         ok
     next

     Table.sortitems(0,0)

     if cIndType = 0
        nr = Table.rowcount()-1
        for k = 1 to nr + 1
            myitem = Table.item(k-1,cInd)
            temp = myitem.text()
            if temp = ""
               temp2 = "ZZZ"
               item = new qTableWidgetItem(temp2)           
               Table.setitem(k-1,cInd,item)
            ok
        next 
        Table.sortitems(cInd,cIndType)    ### FieldNbr and Ascend/Descend
        nr = Table.rowcount()-1
        for k = 1 to nr + 1
            myitem = Table.item(k-1,cInd)
            temp = myitem.text()
            if temp = "ZZZ"
               temp2 = ""
               item = new qTableWidgetItem(temp2)           
               Table.setitem(k-1,cInd,item)
            ok
        next
     ok

     nr = Table.rowcount()-1
     for k = 1 to nr + 1
         myitem = Table.item(k-1,0)
         temp = myitem.text()
         if left(temp,1) = "0"
            temp = right(temp,1)
            item = new qTableWidgetItem(temp)
            Table.setitem(k-1,0,item)
         ok
     next

     nr = Table.rowcount()-1
     for k = 1 to nr + 1
            temp = Table.item(k-1,cSearchInd).text()
            templist = Table.item(k-1,0).text()
            if substr(lower(temp), lower(cSearch)) > 0
               add(listSearch,templist)
               Table.setCurrentCell(k-1,cSearchInd)
               Table.showrow(k-1)
            else
               Table.hiderow(k-1)
            ok 
     end

     if cIndType = 1
        Table.sortitems(cInd,cIndType)
     ok

     nr = len(listSearch)
     num = nr
return   

func pSearchInd()
     cSearchInd = cbosearch.currentindex()

//------------------------------------------------------- 	 

func pSortInd()
     cInd = cboind.currentindex()

func pSortType()
     cIndType = cbotype.currentindex()

func pSort()

     nr = Table.rowcount()-1
     for k = 1 to nr + 1
         myitem = Table.item(k-1,0)
         temp = myitem.text()
         if len(temp) = 1
            temp = "0" + temp
            item = new qTableWidgetItem(temp)           
            Table.setitem(k-1,0,item)
         ok
     next

     Table.sortitems(0,0)

     if cIndType = 0
        nr = Table.rowcount()-1
        for k = 1 to nr + 1
            myitem = Table.item(k-1,cInd)
            temp = myitem.text()
            if temp = ""
               temp2 = "ZZZ"
               item = new qTableWidgetItem(temp2)           
               Table.setitem(k-1,cInd,item)
            ok
        next 
        Table.sortitems(cInd,cIndType)    ### FieldNbr and Ascend/Descend
        nr = Table.rowcount()-1
        for k = 1 to nr + 1
            myitem = Table.item(k-1,cInd)
            temp = myitem.text()
            if temp = "ZZZ"
               temp2 = ""
               item = new qTableWidgetItem(temp2)           
               Table.setitem(k-1,cInd,item)
            ok
        next
     ok

     if cIndType = 1
        Table.sortitems(cInd,cIndType)
     ok

     nr = Table.rowcount()-1
     for k = 1 to nr + 1
         myitem = Table.item(k-1,0)
         temp = myitem.text()
         if left(temp,1) = "0"
            temp = right(temp,1)
            item = new qTableWidgetItem(temp)
            Table.setitem(k-1,0,item)
         ok
     next

//------------------------------------------------------- 

func sort1()
     cInd = 0
     psort()
     if cIndType = 0
        cIndType = 1
     else
        cIndType = 0
     ok

func sort2()
     cInd = 1
     psort()
     if cIndType = 0
        cIndType = 1
     else
        cIndType = 0
     ok

func sort3()
     cInd = 2
     psort()
     if cIndType = 0
        cIndType = 1
     else
        cIndType = 0
     ok

func sort4()
     cInd = 3
     psort()
     if cIndType = 0
        cIndType = 1
     else
        cIndType = 0
     ok

func sort5()
     cInd = 4
     psort()
     if cIndType = 0
        cIndType = 1
     else
        cIndType = 0
     ok

func sort6()
     cInd = 5
     psort()
     if cIndType = 0
        cIndType = 1
     else
        cIndType = 0
     ok

func sort7()
     cInd = 6
     psort()
     if cIndType = 0
        cIndType = 1
     else
        cIndType = 0
     ok

func pSearch1()
     cSearchInd = 0
     cSearch = labelsearch1.text()
     psearch()

func pSearch2()
     cSearchInd = 1
     cSearch = labelsearch2.text()
     psearch()

func pSearch3()
     cSearchInd = 2
     cSearch = labelsearch3.text()
     psearch()

func pSearch4()
     cSearchInd = 3
     cSearch = labelsearch4.text()
     psearch()

func pSearch5()
     cSearchInd = 4
     cSearch = labelsearch5.text()
     psearch()

func pSearch6()
     cSearchInd = 5
     cSearch = labelsearch6.text()
     psearch()

func pSearch7()
     cSearchInd = 6
     cSearch = labelsearch7.text()
     psearch()

//--------------------------------
// What does this do ?

func pRestart()
     labelsearch2.settext("")
     labelsearch3.settext("")
     labelsearch4.settext("")
     labelsearch5.settext("")
     labelsearch6.settext("")
     labelsearch7.settext("")

//--------------------------------------------

func pInit()

           Table = new qtablewidget(win1) {
                  move(150,40)
                  resize(945,440)
                  setstylesheet("color:;background-color:;")

                  oFont = new qfont("",0,0,0)
                  oFont.fromstring("Arial")
                  setfont(oFont)
                  oFont.delete()
                  setcellClickedEvent("pClick()")
                  setcolumncount(7)
                  setrowcount(50)
				  
		  // countryList.ring
		  cbo  = new qCombobox(Table) 
			 { for r in country 
			       addItem(r,0) 
			   next 
			   setactivatedEvent("pBox1()") 
			   hide() 
			  }
                  
		  setCellWidget(Table.rowCount(), 2-1, cbo)
		  for x = 1 to Table.rowcount()
                      for y = 1 to Table.columncount()
                       	  item1 = new qtablewidgetitem("")
                          Table.setitem(x-1,y-1, item1)
                      next
               	  next

                  setColumnwidth(0,150)
                  setColumnwidth(1,150)
                  setColumnwidth(2,150)
                  setColumnwidth(3,150)
                  setColumnwidth(4,150)
                  setColumnwidth(5,150)
                  setColumnwidth(6,150)

                  setHorizontalHeaderItem(0, new QTableWidgetItem("ID"))
                  setHorizontalHeaderItem(1, new QTableWidgetItem("Name"))
                  setHorizontalHeaderItem(2, new QTableWidgetItem("Country"))
                  setHorizontalHeaderItem(3, new QTableWidgetItem("Address"))
                  setHorizontalHeaderItem(4, new QTableWidgetItem("Phone"))
                  setHorizontalHeaderItem(5, new QTableWidgetItem("Job"))
                  setHorizontalHeaderItem(6, new QTableWidgetItem("Notes"))
                  Table.hidecolumn(0)
 
                  labelsearch2 = new qlineedit(win1) {
                                 setgeometry(170,15,150,25)
                                 settext("")
                                 setTextChangedEvent("pSearch2()")
                                 settooltip("Enter text to search")
                                 show()
                                 }

                  labelsearch3 = new qlineedit(win1) {
                                 setgeometry(320,15,150,25)
                                 settext("")
                                 setTextChangedEvent("pSearch3()")
                                 settooltip("Enter text to search")
                                 show()
                                 }

                  labelsearch4 = new qlineedit(win1) {
                                 setgeometry(470,15,150,25)
                                 settext("")
                                 setTextChangedEvent("pSearch4()")
                                 settooltip("Enter text to search")
                                 show()
                                 }

                  labelsearch5 = new qlineedit(win1) {
                                 setgeometry(620,15,150,25)
                                 settext("")
                                 setTextChangedEvent("pSearch5()")
                                 settooltip("Enter text to search")
                                 show()
                                 }

                  labelsearch6 = new qlineedit(win1) {
                                 setgeometry(770,15,150,25)
                                 settext("")
                                 setTextChangedEvent("pSearch6()")
                                 settooltip("Enter text to search")
                                 show()
                                 }

                  labelsearch7 = new qlineedit(win1) {
                                 setgeometry(920,15,150,25)
                                 settext("")
                                 setTextChangedEvent("pSearch7()")
                                 settooltip("Enter text to search")
                                 show()
                                 }
                 
                   header2 = new qpushbutton(win1) {
                            setgeometry(170,40,150,25)
                            settext("Name")
                            setclickevent("sort2()")
                            settooltip("Click to sort the column")
                            show()
                            }

                  header3 = new qpushbutton(win1) {
                            setgeometry(320,40,150,25)
                            settext("Country")
                            setclickevent("sort3()")
                            settooltip("Click to sort the column")
                            show()
                            }

                  header4 = new qpushbutton(win1) {
                            setgeometry(470,40,150,25)
                            settext("Address")
                            setclickevent("sort4()")
                            settooltip("Click to sort the column")
                            show()
                            }
                  header5 = new qpushbutton(win1) {
                            setgeometry(620,40,150,25)
                            settext("Phone")
                            setclickevent("sort5()")
                            settooltip("Click to sort the column")
                            show()
                            }

                  header6 = new qpushbutton(win1) {
                            setgeometry(770,40,150,25)
                            settext("Job")
                            setclickevent("sort6()")
                            settooltip("Click to sort the column")
                            show()
                            }
                  header7 = new qpushbutton(win1) {
                            setgeometry(920,40,150,25)
                            settext("Notes")
                            setclickevent("sort7()")
                            settooltip("Click to sort the column")
                            show()
                            }
                  show()
                  }
				  
//---------------------------------

func pDelete()
//startCalcClock = clock()
     nrow = Table.CurrentRow()
     temp = Table.item(nrow,0).text() 
     Table.removerow(nrow)
     sql = "delete from COMPANY where ID = " + temp   
     sqlite_execute(oSQLite,sql)
     pReadSqlTable()
//? "TimeCalc = " + ((clock()-startCalcClock)/clockspersecond()) + " seconds  v32"		 
