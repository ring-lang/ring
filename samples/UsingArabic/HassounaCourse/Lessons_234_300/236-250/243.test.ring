load "mysqllib.ring"

con = mysql_init()

if mysql_connect( con , "localhost" , "root" , "" , 'mydbfromring' ) = 0
   see "Can't connect" + NL
   see "Error: " + mysql_error(con) + NL
   mysql_close(con)
   bye
ok

mysql_query( con , "SET CHARACTER SET utf8" )

if mysql_query( con , "select * from employee" ) see mysql_error(con) ok

#r = mysql_result( con )
#r = mysql_columns( con )
r = mysql_result2( con )

see type(r) + NL
see r

mysql_close(con)
