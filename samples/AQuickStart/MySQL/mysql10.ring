load "mysqllib.ring"

func main

	con = mysql_init()

	? "Connect" 
	if mysql_connect(con, "localhost", "root", "root","mahdb") = 0
	system_error(con) 
	ok

	? "Select max(id)"
	mysql_query(con, "select max(id) from Employee2")
	see "Max. ID = " ? mysql_result(con)

	? "Select rows"
	mysql_query(con, "select * from Employee2")
	? mysql_result(con)
	mysql_close(con)

func system_error con

	? mysql_error(con)
        mysql_close(con)
        bye
