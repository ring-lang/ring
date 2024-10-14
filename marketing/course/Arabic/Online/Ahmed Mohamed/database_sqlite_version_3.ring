/*
	Application	: Database (SQLite) Version 3
	Author		: Ahmed Mohamed
	Date		: 2019/10/25
*/

# Database

# ODBC (Connect - Database - ODBC Driver)
# MySQL
# SQLite
# GUI Framework (Qt) - Database Classes
#================================================
# RingSQLite

load "sqlitelib.ring"

oSQLite = sqlite_init()

sqlite_open(oSQLite,"mytest.db")

sqlite_execute(oSQLite, "
         CREATE TABLE COMPANY (
         ID INT PRIMARY KEY     NOT NULL,
         NAME           TEXT    NOT NULL,
         AGE            INT     NOT NULL,
         ADDRESS        CHAR(50),
         SALARY         REAL );
")

sqlite_execute(oSQLite, "
        INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)
        VALUES  (1, 'Mahmoud' , 29, 'Jeddah', 20000.00 ),
                (2, 'Ahmed'   , 27, 'Jeddah', 15000.00 ),
                (3, 'Mohammed', 31, 'Egypt' , 20000.00 ),
                (4, 'Ibrahim' , 24, 'Egypt ', 65000.00 );
")

aResult =  sqlite_execute(oSQLite,"select * from COMPANY")

# [ [ [column, value], .... etc ] ]

for x in aResult
        for t in x
                ? t[2] + nl
        next
next
? copy("*",50)
for x in aResult
        ? x[:name]
next
sqlite_close(oSQLite)
