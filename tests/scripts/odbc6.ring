See "ODBC test 6" + nl
pODBC = odbc_init()
See "Connect to database" + nl
#See odbc_connect(pODBC,"DSN=myvfpdata") + nl
odbc_connect(pODBC,"Driver={Microsoft Visual FoxPro Driver};SourceType=DBC;SourceDB=C:\PWCT19\ssbuild\PWCTDATA\CH1\Data\mydata.dbc;") + NL
See "Select data" + nl
see odbc_execute(pODBC,"select * from t38") + nl
nMax = odbc_colcount(pODBC)
See "Columns Count : " + nMax + nl
while odbc_fetch(pODBC)
	See "Row data:" + nl
	for x = 1 to nMax
		see odbc_getdata(pODBC,x) + " - "
	next
end
See "Close database..." + nl
odbc_disconnect(pODBC)
odbc_close(pODBC)
