load "postgresqllib.ring"

conninfo = "user=postgres password=sa"

exit_nicely = func conn {
	PQfinish(conn)
	shutdown(1)
}

conn = PQconnectdb(conninfo)
if (PQstatus(conn) != CONNECTION_OK)
	fputs(stderr, "Connection to database failed: "+PQerrorMessage(conn))
        call exit_nicely(conn)
ok

res = PQexec(conn, "DROP DATABASE IF EXISTS mahdb;")
if PQresultStatus(res) != PGRES_TUPLES_OK
	fputs(stderr, "Remove failed: " + PQerrorMessage(conn))
ok
PQclear(res)

res = PQexec(conn, "CREATE DATABASE mahdb;")
if PQresultStatus(res) != PGRES_TUPLES_OK
	fputs(stderr, "Create database failed: " + PQerrorMessage(conn))
ok
PQclear(res)

res = PQexec(conn, "
CREATE TABLE COMPANY (
         ID INT PRIMARY KEY     NOT NULL,
         NAME           TEXT    NOT NULL,
         AGE            INT     NOT NULL,
         ADDRESS        CHAR(50),
         SALARY         REAL );
")
if PQresultStatus(res) != PGRES_TUPLES_OK
	fputs(stderr, "Create Table failed: " + PQerrorMessage(conn))
ok
PQclear(res)

res = PQexec(conn, "
        INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)
        VALUES  (1, 'Mahmoud' , 31, 'Jeddah', 10.00 ),
                (2, 'Ahmed'   , 27, 'Jeddah', 20.00 ),
                (3, 'Mohammed', 33, 'Egypt' , 30.00 ),
                (4, 'Ibrahim' , 24, 'Egypt ', 40.00 );
")
if PQresultStatus(res) != PGRES_TUPLES_OK
	fputs(stderr, "Insert Table failed: " + PQerrorMessage(conn))
ok
PQclear(res)

res = PQexec(conn, "
       select * from COMPANY
")
if PQresultStatus(res) != PGRES_TUPLES_OK
	fputs(stderr, "Select failed: " + PQerrorMessage(conn))
	PQclear(res)
	call exit_nicely(conn)
ok


nFields = PQnfields(res)
for i = 1 to nFields
        ? PQfname(res, i-1) 
next

? copy("*",60)

for i = 1 to PQntuples(res)
	for j=1 to nFields
		see PQgetvalue(res, i-1, j-1) + " "
	next
	see nl
next

PQclear(res)

PQfinish(conn)