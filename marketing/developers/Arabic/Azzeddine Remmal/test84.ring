#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 14.01.2018                  
####################################


load "sqlitelib.ring"

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
         VALUES (1, 'Azzeddine', 40, 'Algiria', 20000.00 ), 
		(2, 'Ahmed', 27, 'Jeddah', 15000.00 ),
         	(3, 'Mohammed', 31, 'Egypt', 20000.00 ),
         	(4, 'Ibrahim', 24, 'Egypt ', 65000.00 );
"

sqlite_execute(oSQLite,sql)

aResult =  sqlite_execute(oSQLite,"select * from COMPANY")
#	-------------[ [ [column,value],...etc ], ... etc ]

		for x in aResult
		        for t in x
		                ? t[2] 
		        next
		next
see copy("*",50)  + nl
for x in aResult
        ? x[:name] 
next
sqlite_close(oSQLite)

