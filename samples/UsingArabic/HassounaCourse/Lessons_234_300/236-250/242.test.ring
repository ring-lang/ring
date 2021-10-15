load "mysqllib.ring"

con = mysql_init()

if mysql_connect( con , "localhost" , "root" , "" ) = 0
   see "Can't connect" + NL
   see "Error: " + mysql_error(con) + NL
   mysql_close(con)
   bye
ok

mysql_query( con , "use mydbfromring" )
mysql_query( con , "SET CHARACTER SET utf8" )

if mysql_query( con , "insert into employee values(8,'عمرو',1500)" )
  see mysql_error(con) + NL
ok

if mysql_query( con , "create table employee (c1 int, c2 int)" )
  see mysql_error(con) + NL
ok


mysql_close(con)
