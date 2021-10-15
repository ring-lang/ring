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

mysql_query( con , "insert into employee values(8,'عمرو',1500)" )
mysql_query( con , "insert into employee values(9,'عادل',1500)" )


mysql_close(con)
