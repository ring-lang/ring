/*
**	Application	: Ring lessons - DataBase(SQLite) .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 14 .
*/

# DataBase

# ODBC ( Connect - DataBase - ODBC Driver )
# MySQL
# SQLite
# GUI Framework (QT) - DataBase Classes
# ==============================
load "sqlitelib.ring"

# 		sqlite_init()	----> C Object
#		sqlite_open(object,"file.db")
#		sqlite_execute(object , SQL Statement)
#		sqlite_close(object) 

oSQLite = sqlite_init()

sqlite_open(oSQLite,"mytest.db")

sqlite_execute(oSQLite,"
	CREATE TABLE COMPANY(
        	ID INT PRIMARY KEY     NOT NULL,
        	NAME           TEXT    NOT NULL,
        	AGE            INT     NOT NULL,
        	ADDRESS        CHAR(50),
        	SALARY         REAL );
	")

sqlite_execute(oSQLite,"
	INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)
	VALUES	(1, 'Mahmoud', 29, 'Jeddah', 100000.00 ),
        		(2, 'Ahmed', 27, 'Jeddah', 15000.00 ),
        		(3, 'Osama', 38, 'Syria', 20000.00 ),
        		(4, 'Ibrahim', 24, 'Egypt ', 65000.00 );
")

aResult =  sqlite_execute(oSQLite,"select * from COMPANY")
for x in aResult
        for t in x
                ? t[2]
        next
next
? copy("*",50)
for x in aResult
        ? x[:name]
next
sqlite_close(oSQLite)








