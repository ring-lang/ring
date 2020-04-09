/*
	name	:	Darsh Adam
	Lesson	:	Ring Lessons.ring
	Date 	:	24/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================

load "odbclib.ring"


? "ODBC test 4" 
pODBC = odbc_init()
? "Connect to database" 
odbc_connect(pODBC,"DBQ=test.mdb;Driver={Microsoft Access Driver (*.mdb)}") 
? "Select data" 
odbc_execute(pODBC,"select * from mytable") 
nMax = odbc_colcount(pODBC)
? "Columns Count : " + nMax 
while odbc_fetch(pODBC)
        ? "" 
        for x = 1 to nMax
                ? odbc_getdata(pODBC,x) 
		if x != nmax see " - " ok
        next
end
? ""
? "Close database..." 
odbc_disconnect(pODBC)
odbc_close(pODBC)
