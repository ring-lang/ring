load "mysqllib.ring"

con = mysql_init()

if mysql_connect( con , "localhost" , "root" , "" ) = 0
   see "Can't connect" + NL
   see "Error: " + mysql_error(con) + NL
   mysql_close(con)
   bye
ok

stmt = "
CREATE DATABASE IF NOT EXISTS mydbfromring 
DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_general_ci
"

see mysql_query( con , stmt )

mysql_close(con)
