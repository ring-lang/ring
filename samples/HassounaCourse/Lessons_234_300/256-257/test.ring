load "mysql_hassouna.ring"
db_name = "mydbfromring"
mysql_connect_now()

//mysql_run( "insert into emp values(1,'" + mysql_file('ahmed.png') + "')" )
r = mysql_get("select * from emp")
write( "ahmed.png" , r[2][2] )

mysql_close_now()
