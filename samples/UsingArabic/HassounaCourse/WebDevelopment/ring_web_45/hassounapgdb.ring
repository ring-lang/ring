load "postgresqllib.ring"

username = "postgres"
password = " "
database = " "
port     = "5432"
conn     = NULL 

def open()
	conninfo  = " user="     + username
	conninfo += " password=" + password
	conninfo += " dbname="   + database
	conninfo += " port="     + port
	conn = PQconnectdb(conninfo)

def close()
	PQfinish(conn)

def run(sql_statement)
	open()
	res = PQexec( conn , sql_statement )
	err = ""
	if PQresultStatus(res) != PGRES_TUPLES_OK
		err = PQerrorMessage(conn)
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
	res = PQexec( conn , select_statement )
	err = ""
	table   = []
	if PQresultStatus(res) != PGRES_TUPLES_OK
		err = PQerrorMessage(conn)
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

