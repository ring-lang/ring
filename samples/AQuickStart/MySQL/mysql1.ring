load "mysqllib.ring"
See "MySQL Test - Create Database" + nl
con = mysql_init()

See "Connect" + nl
if mysql_connect(con,"localhost","root","root") = 0
        see "Can't connect" + nl
        see "Error : " + mysql_error(con) + nl
        mysql_close(con)
        bye
ok

See "Create Database..." + nl
mysql_query(con,"CREATE DATABASE mahdb")

See "Close Connection" + nl
mysql_close(con)
