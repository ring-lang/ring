load "mysqllib.ring"

con = mysql_init()

if mysql_connect( con , "localhost" , "root" , "" ) = 0
   see "Can't connect" + NL
   see "Error: " + mysql_error(con) + NL
   mysql_close(con)
   bye
ok

see "Connected..." + NL


