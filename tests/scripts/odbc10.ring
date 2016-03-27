func main
	for x = 1 to 1000
		test()
	next


func test
	See "ODBC test 1" + nl
	oODBC = odbc_init()
	See "Drivers " + nl
	see odbc_drivers(oODBC)
	odbc_close(oODBC)