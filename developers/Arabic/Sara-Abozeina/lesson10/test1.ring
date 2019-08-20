/*
**	Application:SQLite
**	Author	   :Sara Abozeina
**	Date       :2017.12.31
*/

load "sqlitelib.ring"

oSQLite = sqlite_init()
sqlite_open(oSQLite,"test3.db")
###===(1)create DB===###
sql = "CREATE TABLE persons("  +
         "ID INT PRIMARY  KEY     NOT NULL," +
         "Names           TEXT    NOT NULL);" 

sqlite_execute(oSQLite,sql)



###===(2)fill it with data DB===###
sql="insert into persons (ID,Names)"+
	"Values(1,'A');" +
"insert into persons  (ID,Names)"+
	"Values(2,'B');" +
"insert into persons  (ID,Names)"+
	"Values(3,'C');" 

sqlite_execute(oSQLite,sql)

###===(3)Extract data===###
alist=sqlite_execute(oSQLite,"select * from persons")

#list of two dimensions 
for x in alist	 
	for t in x
		?t[2] ?"^^^"   #data in list
		?t[1]          #titles in list				
	next
next

#one 
for x in alist	
	?x["ID"]               #list of id
	?x["Names"]            #list of names 
next
sqlite_close(oSQLite)
