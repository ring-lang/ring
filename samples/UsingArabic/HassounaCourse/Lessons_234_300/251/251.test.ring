load "mysql_hassouna.ring"
db_name = "mydbfromring"

mysql_connect_now()

see mysql_auto_number("employee","empno")

#mysql_run("insert into employee values(6,'Yaser',1500,'Giza')")
#mysql_run("insert into employee values(7,'ياسر',1500,'Giza')")


r = mysql_get("select * from employee")
for row=1 to len(r)
   for col=1 to len(r[row])
      see r[row][col] + TAB
   next
   see NL
next


mysql_close_now()
