load "mysqllib.ring"

con = mysql_init()

if mysql_connect( con , "localhost" , "root" , "" , 'mydbfromring' ) = 0
   see "Can't connect" + NL
   see "Error: " + mysql_error(con) + NL
   mysql_close(con)
   bye
ok

stmt = "
CREATE TABLE IF NOT EXISTS employee
(
   empno int primary key,
   empname varchar(100) not null,
   salary  int
)
"
mysql_query( con , "SET CHARACTER SET utf8" )

mysql_query( con , stmt )

mysql_query( con , "insert into employee values(4,'عمرو',1500)" )
mysql_query( con , "insert into employee values(5,'عادل',1500)" )


mysql_close(con)
