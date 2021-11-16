/*    Application: database
 *    Author     : heba atef
 *    Date       : 1.1.2018
 */
# odbc ( connect - database - odbc driver )

# my sql 

# sql lite 

#========================================
# ring sql lite 
 
load "sqlitelib.ring"

# sqlite_init() 
# sqlite_open(object, "file.db")
# sqllite_excute(object, "sql statement")
#sqlite_close()
#========================================

oSQLite = sqlite_init()

sqlite_open(oSQLite, "mytest.db")

sql ="
 CREATE TABLE COMPANY(
    ID     INT PRIMARY KEY     NOT NULL,
 NAME       TEXT    NOT NULL,
        
 AGE          INT     NOT NULL,
    ADDRESS        CHAR(50), 
     SALARY         REAL );
"

sqlite_execute(oSQLite,sql)

sql = "
INSERT INTO COMPANY (ID,NAME, AGE, ADDRESS, SALARY) 
         VALUES (1, 'Mahmoud', 29, 'Jeddah', 20000.00 ); 
         INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) 
         VALUES (2, 'Ahmed', 27, 'Jeddah', 15000.00 ); 
         INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)
         VALUES (3, 'Mohammed', 31, 'Egypt', 20000.00 );
         INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)
         VALUES (4, 'Ibrahim', 24, 'Egypt ', 65000.00 );
"
sqlite_execute(oSQLite,sql)

aResult =  sqlite_execute(oSQLite, "select * from COMPANY")
for x in aResult
        for t in x
              ? t[2] 
        next
next
? copy("*", 50)  
for x in aResult
        ? x["name"] 
next
sqlite_close(oSQLite)

