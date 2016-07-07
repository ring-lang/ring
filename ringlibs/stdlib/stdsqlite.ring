# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	sqlite_class_test()
ok

func sqlite_class_test
	
	osqlite = new sqlite
	See "Test the sqlite Class Methods" + nl
	osqlite { 
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

