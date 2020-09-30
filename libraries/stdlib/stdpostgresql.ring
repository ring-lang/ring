# The Ring Standard Library
# Common Functions and classes for applications
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	load "postgresqllib.ring"
	postgresql_class_test()
ok

func postgresql_class_test

	oPostgreSQL = new PostgreSQL("user=postgres password=sa dbname = mahdb")
	See "Test the PostgreSQL Class Methods" + nl
	oPostgreSQL {

		sql = "CREATE TABLE COMPANY_TEST("  +
       			"ID INT PRIMARY KEY     NOT NULL," +
		         "NAME           TEXT    NOT NULL," +
		         "AGE            INT     NOT NULL," +
		         "ADDRESS        CHAR(50)," +
		         "SALARY         REAL );"

		execute(sql)

		sql = "INSERT INTO COMPANY_TEST (ID,NAME,AGE,ADDRESS,SALARY) "  +
		         "VALUES (1, 'Mahmoud', 29, 'Jeddah', 20000.00 ); " +
		         "INSERT INTO COMPANY_TEST (ID,NAME,AGE,ADDRESS,SALARY) "  +
		         "VALUES (2, 'Ahmed', 27, 'Jeddah', 15000.00 ); "     +
		         "INSERT INTO COMPANY_TEST (ID,NAME,AGE,ADDRESS,SALARY)" +
		         "VALUES (3, 'Mohammed', 31, 'Egypt', 20000.00 );" +
		         "INSERT INTO COMPANY_TEST (ID,NAME,AGE,ADDRESS,SALARY)" +
		         "VALUES (4, 'Ibrahim', 24, 'Egypt ', 65000.00 );"

		execute(sql)

		?  execute("select * from COMPANY_TEST")

		? copy("*",50)  

		close()
	}

Class PostgreSQL

	con

	Func init cConString
		con = PQconnectdb(cConString)
		if (PQstatus(con) != CONNECTION_OK)
			raise("Error (PostgreSQL Class) : Can't connect to the database server!")
			PQfinish(con)
		ok
		return con

	Func close
		return PQfinish(con)

	Func execute cSQL
		res = PQexec(con,cSQL)
		aMyQueryResult = []
		aResultRow = []
		nFields = PQnfields(res)
		for i = 1 to nFields
		        aResultRow + PQfname(res, i-1) 
		next
		aMyQueryResult + aResultRow		
		for i = 1 to PQntuples(res)
			aResultRow = []
			for j=1 to nFields
				aResultRow + PQgetvalue(res, i-1, j-1) 
			next
			aMyQueryResult + aResultRow
		next		
		PQclear(res)
		return aMyQueryResult
