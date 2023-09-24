load "mysqllib.ring"

con = mysql_init()
See "Connect to database..." + nl
mysql_connect(con, "localhost", "root", "root","mahdb")
See "Read data from database..." + nl
mysql_query(con,"SELECT data FROM photo WHERE id=1")
See "Write new file" + nl
result = mysql_result(con)
write("great.jpg",hex2str(result[1][1]))
See "Close database..." + nl
mysql_close(con)
