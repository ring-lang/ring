/*
**	Application Name : ODBC;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-22;		
*/
load "odbclib.ring"

oOdbc = odbc_init()

? odbc_drivers(oOdbc)
