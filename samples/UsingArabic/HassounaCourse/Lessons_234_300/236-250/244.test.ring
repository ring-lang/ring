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

r = mysql_result2( con )

for row=1 to len(r)
   for cell=1 to len(r[row])
      see r[row][cell] + TAB
   next
   see NL
next


mysql_close(con)
