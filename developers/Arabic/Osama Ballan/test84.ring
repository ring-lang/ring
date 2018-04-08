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

sql = "
	CREATE TABLE COMPANY(
         ID INT PRIMARY KEY     NOT NULL,
         NAME           TEXT    NOT NULL,
         AGE            INT     NOT NULL,
         ADDRESS        CHAR(50),
         SALARY         REAL );
	"

sqlite_execute(oSQLite,sql)

sql = "
	INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)
	VALUES	(1, 'Mahmoud', 29, 'Jeddah', 100000.00 ),
        		(2, 'Ahmed', 27, 'Jeddah', 15000.00 ),
        		(3, 'Osama', 38, 'Syria', 80000.00 ),
        		(4, 'Ibrahim', 24, 'Egypt ', 65000.00 );
	"

sqlite_execute(oSQLite,sql)
aResult =  sqlite_execute(oSQLite,"select * from COMPANY")
/* aResult =[[[ID,1],[NAME,Mahmoud],[AGE,29],[ADDRESS,Jeddah],[SALARY,100000]],
		    [[ID,2],[NAME,Ahmed],[AGE,27],[ADDRESS,Jeddah],[SALARY,15000]],
		    [[ID,3],[NAME,Osama],[AGE,38],[ADDRESS,Syria],[SALARY,80000]],
		    [[ID,4],[NAME,Ibrahim],[AGE,24],[ADDRESS,Egypt],[SALARY,65000]]]
for x in aResult
        for t in x
                ? t[2]
        next
next
*/
for x = 1 to 4
	for t =1 to 5
                ? aResult[x][t][2]
        next
next

? copy("*",50)
for x in aResult
        ? x[:name]
next
sqlite_close(oSQLite)








