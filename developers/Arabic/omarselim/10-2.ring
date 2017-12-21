load "odbclib.ring"

odbc=odbc_init()
? odbc_drivers(odbc)

? "connect to db" +nl

?odbc_connect(odbc ,"dbq=test.mdb;driver={microsoft access driver(*.mdb)}")

? "select data" +nl


? odbc_execute(odbc , "select * from person ")

nMAX =ODBC_COlcount(ODBC)

? "COLMN COUNT "+ NMAX


WHILE ODBC_FETch(ODBC)

	? "RAW DATA:" +NL
	FOR X=1 TO NMAX 

	? ODBC_GETdata(ODBC,X)+"-"
NEXT 


END


SEE "CLOSE DATABASE" +NL
ODBC_DISconnect(ODBC)
ODBC_CLOse(ODBC)
