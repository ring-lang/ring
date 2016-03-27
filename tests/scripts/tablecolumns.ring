con = mysql_init()
see "Connect to database" + nl
mysql_connect(con, "localhost", "root", "root","mahdb")
see "Execute Query" + nl
mysql_query(con, "SELECT * FROM Employee")
see "Result" + nl
result =  mysql_columns(con)
see result
for x = 1 to len(result)
	if isstring(result[x])
		see result[x] + nl
	ok
next

mysql_query(con, "SELECT * FROM salary limit 0,1")
see "result" + nl
aResult = mysql_result2(con)[1]
see aResult

see "Close database" + nl
mysql_close(con)