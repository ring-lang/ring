load "mysqllib.ring"

See "Read file" + nl
cFile = read("ringlogo.jpg")
con = mysql_init()
See "Connect to database..." + nl
mysql_connect(con, "localhost", "root", "root","mahdb")
see "drop table" + nl
mysql_query(con, "DROP TABLE IF EXISTS photo")
see "create table" + nl
mysql_query(con, "CREATE TABLE photo(Id INT PRIMARY KEY AUTO_INCREMENT, Data TEXT)")
stmt = "INSERT INTO photo(id, data) VALUES(1, '" + str2hex(cFile) + "')"
See "Insert data..." + nl
mysql_query(con,stmt)
See "Close database..." + nl
mysql_close(con)
