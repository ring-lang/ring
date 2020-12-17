load "postgresqllib.ring"

pg_username = "postgres"
pg_password = " "
pg_database = " "
pg_port     = "5432"
pg_conn     = NULL 

def open()
	conninfo  = " user="     + pg_username
	conninfo += " password=" + pg_password
	conninfo += " dbname="   + pg_database
	conninfo += " port="     + pg_port
	pg_conn = PQconnectdb(conninfo)

def close()
	PQfinish(pg_conn)

def run(sql_statement)
	open()
	res = PQexec( pg_conn , sql_statement )
	err = ""
	if PQresultStatus(res) != PGRES_TUPLES_OK
		err = PQerrorMessage(pg_conn)
	ok
	PQclear(res)
	close()
	if err=""
		return True
	else
		return False
	ok

def get_data(select_statement)
	open()
	res = PQexec( pg_conn , select_statement )
	err = ""
	table   = []
	if PQresultStatus(res) != PGRES_TUPLES_OK
		err = PQerrorMessage(pg_conn)
	else
		nRows   = PQntuples(res)
		nFields = PQnfields(res)
		for i=1 to nRows
			row = []
			for j=1 to nFields
				row[PQfname(res, j-1)] = PQgetvalue(res, i-1, j-1)
			next
			add( table , row )
		next
	ok
	PQclear(res)
	close()
	if err=""
		return table
	else
		return err
	ok

def auto_num( table , column )
	tbl = get_data( "select max(" + column + ")+1 as num from " + table )
	if type(tbl)=type([]) and len(tbl)>0
		if tbl[1][:num] != NULL
			return tbl[1][:num]
		else
			return "1"
		ok
	else
		return "0"
	ok

