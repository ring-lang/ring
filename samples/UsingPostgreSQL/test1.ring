load "postgresqllib.ring"

conninfo = "user=postgres password=sa dbname = postgres"

exit_nicely = func conn {
	PQfinish(conn)
	shutdown(1)
}

conn = PQconnectdb(conninfo)

if (PQstatus(conn) != CONNECTION_OK)
	fputs(stderr, "Connection to database failed: "+PQerrorMessage(conn))
        call exit_nicely(conn)
ok

res = PQexec(conn, "select * from pg_database")
if PQresultStatus(res) != PGRES_TUPLES_OK
	fputs(stderr, "Select failed: " + PQerrorMessage(conn))
	PQclear(res)
	exit_nicely(conn)
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