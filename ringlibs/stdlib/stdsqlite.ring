# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	sqlite_class_test()
ok

func sqlite_class_test

	osqlite = new sqlite
	See "Test the sqlite Class Methods" + nl
	osqlite {
		open("test.db")
		sql = "CREATE TABLE COMPANY("  +
       			"ID INT PRIMARY KEY     NOT NULL," +
		         "NAME           TEXT    NOT NULL," +
		         "AGE            INT     NOT NULL," +
		         "ADDRESS        CHAR(50)," +
		         "SALARY         REAL );"

		execute(sql)

		sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  +
		         "VALUES (1, 'Mahmoud', 29, 'Jeddah', 20000.00 ); " +
		         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  +
		         "VALUES (2, 'Ahmed', 27, 'Jeddah', 15000.00 ); "     +
		         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" +
		         "VALUES (3, 'Mohammed', 31, 'Egypt', 20000.00 );" +
		         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" +
		         "VALUES (4, 'Ibrahim', 24, 'Egypt ', 65000.00 );"

		execute(sql)

		aResult =  execute("select * from COMPANY")
		for x in aResult
			for t in x
				see t[2] + nl
			next
		next
		see copy("*",50)  + nl
		for x in aResult
			see x["name"] + nl
		next
		close()
	}

Class sqlite

	osqlite = init()

	Func init
		return sqlite_init()

	Func close
		return sqlite_close(osqlite)

	Func open cDatabase
		return sqlite_open(osqlite,cDatabase)

	Func errormessage
		return sqlite_errmsg(osqlite)

	Func execute cSQL
		return sqlite_execute(osqlite,cSQL)
